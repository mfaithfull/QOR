//MSW_mutex.cpp

// Copyright Querysoft Limited 2013
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

/*
   Copyright (c) 2011 mingw-w64 project

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#include "SystemQOR.h"

#if		(QOR_SYS_OS == QOR_SYS_MSW)

#include "WinQL/Application/Threading/WinQLThread.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include "SystemQOR/MSWindows/types/pthread_types.h"
#include "SystemQOR/MSWindows/MSW_pthread.h"
#include "../SystemQOR/MSWindows/Winpthreads/details/spinlock.h"
#include "../SystemQOR/MSWindows/Winpthreads/details/ref.h"
#include "../SystemQOR/MSWindows/Winpthreads/details/mutex.h"
#include "../SystemQOR/MSWindows/Winpthreads/details/misc.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	extern int do_sema_b_wait_intern ( void* sema, int nointerrupt, unsigned long timeout );
	static __QCMP_NOINLINE int mutex_static_init(pthread_mutex_t *m);
	static __QCMP_NOINLINE int _mutex_trylock(pthread_mutex_t *m);

	static spin_t mutex_global = {0,LIFE_SPINLOCK,1};
	static spin_t mutex_global_static = {0,LIFE_SPINLOCK,1};

	//--------------------------------------------------------------------------------
	static __QCMP_NOINLINE int mutex_unref(pthread_mutex_t *m, int r)
	{
		mutex_t *m_ = (mutex_t *)*m;
		_spin_lite_lock(&mutex_global);
	#ifdef WINPTHREAD_DBG
		assert((m_->valid == LIFE_MUTEX) && (m_->busy > 0));
	#endif
		m_->busy --;
		if( m_->busy < 0 )
		{
			m_->busy = 0;
		}
		_spin_lite_unlock(&mutex_global);
		return r;
	}

	//--------------------------------------------------------------------------------
	/* Set the mutex to busy in a thread-safe way */
	/* A busy mutex can't be destroyed */
	static __QCMP_NOINLINE int mutex_ref(pthread_mutex_t *m)
	{
		int r = 0;

		_spin_lite_lock(&mutex_global);
		if (!m || !*m)
		{
		  _spin_lite_unlock(&mutex_global);
		  return EINVAL;
		}
		if (STATIC_INITIALIZER(*m))
		{
		  _spin_lite_unlock(&mutex_global);
		  r = mutex_static_init(m);
		  _spin_lite_lock(&mutex_global);
		  if (r != 0 && r != EBUSY)
		  {
		_spin_lite_unlock(&mutex_global);
		return r;
		  }
		}
		r = 0;
		if (!m || !*m || ((mutex_t *)*m)->valid != LIFE_MUTEX) r = EINVAL;
		else {
			((mutex_t *)*m)->busy ++;
		}

		_spin_lite_unlock(&mutex_global);

		return r;
	}

	//--------------------------------------------------------------------------------
	/* An unlock can simply fail with EPERM instead of auto-init (can't be owned) */
	static __QCMP_NOINLINE int mutex_ref_unlock(pthread_mutex_t *m)
	{
		int r = 0;
		mutex_t *m_ = (mutex_t *)*m;

		_spin_lite_lock(&mutex_global);

		if (!m || !*m || ((mutex_t *)*m)->valid != LIFE_MUTEX) r = EINVAL;
		else if (STATIC_INITIALIZER(*m) || !COND_LOCKED(m_)) {
		  r= EPERM;
		}
		else {
			((mutex_t *)*m)->busy ++;
		}

		_spin_lite_unlock(&mutex_global);

		return r;
	}

	//--------------------------------------------------------------------------------
	/* doesn't lock the mutex but set it to invalid in a thread-safe way */
	/* A busy mutex can't be destroyed -> EBUSY */
	static __QCMP_NOINLINE int mutex_ref_destroy(pthread_mutex_t *m, pthread_mutex_t *mDestroy )
	{
		int r = 0;

		*mDestroy = NULL;
		/* also considered as busy, any concurrent access prevents destruction: */
		if (_spin_lite_trylock(&mutex_global))
		  return EBUSY;
    
		if (!m || !*m)
			r = EINVAL;
		else {
			mutex_t *m_ = (mutex_t *)*m;
			if (STATIC_INITIALIZER(*m)) *m = NULL;
			else if (m_->valid != LIFE_MUTEX) r = EINVAL;
			else if ( (m_->busy > 0 ) || COND_LOCKED(m_)) r = EBUSY;
			else {
				*mDestroy = *m;
				*m = NULL;
			}
		}

		_spin_lite_unlock(&mutex_global);
		return r;
	}

	//--------------------------------------------------------------------------------
	static __QCMP_NOINLINE int mutex_ref_init(pthread_mutex_t *m )
	{
		int r = 0;

		_spin_lite_lock(&mutex_global);
    
		if (!m)  r = EINVAL;
 
		_spin_lite_unlock(&mutex_global);
		return r;
	}

	#ifndef NDEBUG
	static int print_state = 1;

	//--------------------------------------------------------------------------------
	void mutex_print_set(int state)
	{
		print_state = state;
	}

	//--------------------------------------------------------------------------------
	void mutex_print(pthread_mutex_t *m, char *txt)
	{
		if (!print_state) return;
		mutex_t *m_ = (mutex_t *)*m;
		if (m_ == NULL) {
			printf("M%p %d %s\n",*m,(int)nsWin32::GetCurrentWin32Thread()->GetCurrentId(), txt);
		} else {
			printf("M%p %d V=%0X B=%d t=%d o=%d C=%d R=%d H=%p %s\n",
				*m, 
				(int)nsWin32::GetCurrentWin32Thread()->GetCurrentId(), 
				(int)m_->valid, 
				(int)m_->busy,
				m_->type,
				(int)GET_OWNER(m_),(int)(m_->count),(int)GET_RCNT(m_),GET_HANDLE(m_),txt);
		}
	}
	#endif

	//--------------------------------------------------------------------------------
	static __QCMP_NOINLINE int mutex_static_init(pthread_mutex_t *m)
	{
		static pthread_mutexattr_t mxattr_recursive = PTHREAD_MUTEX_RECURSIVE;
		static pthread_mutexattr_t mxattr_errorcheck = PTHREAD_MUTEX_ERRORCHECK;

		int r;

		_spin_lite_lock(&mutex_global_static);
		if (!STATIC_INITIALIZER(*m)) {
			/* Assume someone crept in between: */
			r = 0;
		}
		else
		{
		  if (*m == PTHREAD_MUTEX_INITIALIZER)
		r = pthread_mutex_init (m, NULL);
		  else if (*m == PTHREAD_RECURSIVE_MUTEX_INITIALIZER)
		r = pthread_mutex_init (m, &mxattr_recursive);
		  else if (*m == PTHREAD_ERRORCHECK_MUTEX_INITIALIZER)
		r = pthread_mutex_init (m, &mxattr_errorcheck);
		  else if (*m == NULL)
		r = EINVAL;
		  else
		r = pthread_mutex_init(m, NULL);
		}
		_spin_lite_unlock(&mutex_global_static);
		return r;
	}

	static int pthread_mutex_lock_intern(pthread_mutex_t *m, unsigned long timeout);

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_lock (pthread_mutex_t *m)
	{
	  return pthread_mutex_lock_intern(m, nsWin32::Infinite);
	}

	//--------------------------------------------------------------------------------
	static int pthread_mutex_lock_intern (pthread_mutex_t *m, unsigned long timeout)
	{
		mutex_t* _m;
		int r;
		r = mutex_ref( m );
		if( r ) 
		{
			return r;
		}

		_m = (mutex_t*)*m;
		if( _m->type != PTHREAD_MUTEX_NORMAL )
		{
			if( COND_LOCKED( _m ) )
			{
				if( COND_OWNER( _m ) )
				{
					if( _m->type == PTHREAD_MUTEX_RECURSIVE )
					{
						nsWin32::CInterlockedHelper::Increment( &_m->count );
						return mutex_unref( m, 0 );
					}
					return mutex_unref( m, EDEADLK );
				}
			}
		}

		r = _m->h->Wait( timeout );//do_sema_b_wait_intern ( const_cast< void* >( _m->h->Handle() ), 1, timeout );

		if (r == 0)
		{
			_m->count = 1;
			SET_OWNER(_m);
		}
		return mutex_unref( m, r );
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_timedlock(pthread_mutex_t *m, const timespec *ts)
	{
		unsigned long long t, ct;
		int r;
		mutex_t *_m;

		if (!ts) return pthread_mutex_lock(m);
		r = mutex_ref(m);
		if (r) return r;

		/* Try to lock it without waiting */
		r=_mutex_trylock(m);
		if (r != EBUSY) return mutex_unref(m,r);
    
		_m = (mutex_t *)*m;
		if (_m->type != PTHREAD_MUTEX_NORMAL && COND_LOCKED(_m) && COND_OWNER(_m))
		  return mutex_unref(m,EDEADLK);
		ct = time_in_ms();
		t = time_in_ms_from_timespec(ts);
	   mutex_unref(m,r);
	   r = pthread_mutex_lock_intern(m, (ct > t ? 0 : (t - ct)));
	   return  r;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_unlock(pthread_mutex_t *m)
	{
		mutex_t *_m;
		int r = mutex_ref_unlock(m);
		if(r) return r;

		_m = (mutex_t *)*m;
		if (_m->type == PTHREAD_MUTEX_NORMAL)
		{
			if (!COND_LOCKED(_m))
		  return mutex_unref(m,EPERM);
		}
		else if (!COND_LOCKED(_m) || !COND_OWNER(_m))
			return mutex_unref(m,EPERM);
		if (_m->type == PTHREAD_MUTEX_RECURSIVE)
		{
		  if( m_InterlockedHelper.Decrement(&_m->count) )
		  {
			return mutex_unref(m,0);
		  }
		}
		UNSET_OWNER(_m);
		if (_m->h != NULL && ! _m->h->Release( 1, NULL ) ) 
		{
    		SET_OWNER(_m);
			/* restore our own bookkeeping */
			return mutex_unref(m,EPERM);
		}
		return mutex_unref(m,0);
	}

	//--------------------------------------------------------------------------------
	static __QCMP_NOINLINE int _mutex_trylock(pthread_mutex_t *m)
	{
		int r = 0;
		mutex_t *_m = (mutex_t *)*m;
		if (_m->type != PTHREAD_MUTEX_NORMAL)
		{
		  if (COND_LOCKED(_m))
		  {
		if (_m->type == PTHREAD_MUTEX_RECURSIVE && COND_OWNER(_m))
		{
			nsWin32::CInterlockedHelper InterlockedHelper;
		  InterlockedHelper.Increment(&_m->count);
		  return 0;
		}
		return EBUSY;
		  }
		} else if (COND_LOCKED(_m))
		  return EBUSY;
		r = do_sema_b_wait_intern (_m->h, 1, 0);
		if (r == ETIMEDOUT) r = EBUSY;
		else if (!r)
		{
		  _m->count = 1;
		  SET_OWNER(_m);
		}
		return r;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_trylock(pthread_mutex_t *m)
	{
		int r = mutex_ref(m);
		if(r) return r;

		return mutex_unref(m,_mutex_trylock(m));
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *a)
	{
		mutex_t *_m;

		int r = mutex_ref_init(m);
		if(r) return r;

		if (!(_m = (mutex_t*)(pthread_mutex_t)calloc(1,sizeof(*_m))))
		  return ENOMEM; 

		_m->type = PTHREAD_MUTEX_DEFAULT;
		_m->count = 0;

		if (a)
		 {
			int share = PTHREAD_PROCESS_PRIVATE;
			r = pthread_mutexattr_gettype (a, &_m->type);
			if (!r)
			  r = pthread_mutexattr_getpshared(a, &share);
			if (!r && share == PTHREAD_PROCESS_SHARED)
			  {
			r = ENOSYS;
		  }
		 }
		if (!r)
		{
			_m->h = new nsWin32::CSemaphore( (nsWin32::LPSECURITY_ATTRIBUTES)(NULL), 1, 0x7fffffff, NULL, 0, nsWin32::Standard_Rights_All | nsWin32::Semaphore_Modify_State );
		} 
		if (r)
		{
			_m->valid = DEAD_MUTEX;
			free(_m);
			*m = NULL;
			return r;
		}
		_m->valid = LIFE_MUTEX;
		*m = (pthread_mutex_t)_m;

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_destroy(pthread_mutex_t *m)
	{
		mutex_t *_m;
		pthread_mutex_t mDestroy;
		int r = mutex_ref_destroy(m,&mDestroy);
		if(r) return r;
		if(!mDestroy) return 0; // destroyed a (still) static initialized mutex

		// now the mutex is invalid, and no one can touch it
		_m = (mutex_t *)mDestroy;

		delete _m->h;
		_m->valid = DEAD_MUTEX;
		_m->type  = 0;
		_m->count = 0;
		_m->busy = 0;
		_m->h = 0;
		free(mDestroy);
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_init(pthread_mutexattr_t *a)
	{
		*a = PTHREAD_MUTEX_NORMAL | (PTHREAD_PROCESS_PRIVATE << 3);
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_destroy(pthread_mutexattr_t *a)
	{
		if (!a)
		  return EINVAL;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_gettype(const pthread_mutexattr_t *a, int *type)
	{
		if (!a || !type)
		  return EINVAL;
		*type = *a & 3;

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_settype(pthread_mutexattr_t *a, int type)
	{
		if (!a || (type != PTHREAD_MUTEX_NORMAL && type != PTHREAD_MUTEX_RECURSIVE && type != PTHREAD_MUTEX_ERRORCHECK))
		  return EINVAL;
		*a &= ~3;
		*a |= type;

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getpshared(const pthread_mutexattr_t *a, int *type)
	{
		if (!a || !type)
		  return EINVAL;
		*type = (*a & 4 ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE);

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_setpshared(pthread_mutexattr_t * a, int type)
	{
		int r = 0;
		if (!a || (type != PTHREAD_PROCESS_SHARED
		&& type != PTHREAD_PROCESS_PRIVATE))
		  return EINVAL;
		if (type == PTHREAD_PROCESS_SHARED)
		{
		  type = PTHREAD_PROCESS_PRIVATE;
		  r = ENOSYS;
		}
		type = (type == PTHREAD_PROCESS_SHARED ? 4 : 0);

		*a &= ~4;
		*a |= type;

		return r;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getprotocol(const pthread_mutexattr_t *a, int *type)
	{
		*type = *a & (8 + 16);

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_setprotocol(pthread_mutexattr_t *a, int type)
	{
		if ((type & (8 + 16)) != 8 + 16) return EINVAL;

		*a &= ~(8 + 16);
		*a |= type;

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getprioceiling(const pthread_mutexattr_t *a, int * prio)
	{
		*prio = *a / PTHREAD_PRIO_MULT;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_setprioceiling(pthread_mutexattr_t *a, int prio)
	{
		*a &= (PTHREAD_PRIO_MULT - 1);
		*a += prio * PTHREAD_PRIO_MULT;

		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_setprioceiling( pthread_mutex_t* pp_pthreadmutex, int iPrioCeiling, int* pOldCieling )
	{
		return ENOTSUP;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getrobust( const pthread_mutexattr_t* pp_pthreadmutexattr, int* piPRobust )
	{
		return ENOTSUP;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_getprioceiling( const pthread_mutex_t* pp_pthreadmutex, int* pPrioCeiling )
	{
		return ENOTSUP;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_consistent( pthread_mutex_t* pp_pthreadmutex )
	{
		return ENOTSUP;
	}


}//nsWin32

#endif//(QOR_SYS_OS == QOR_SYS_MSW)
