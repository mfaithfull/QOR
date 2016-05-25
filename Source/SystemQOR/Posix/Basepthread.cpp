//Basepthread.cpp

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

#include "SystemQOR/Posix/Basepthread.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID( Cpthread );
	
	//--------------------------------------------------------------------------------
	Cpthread::Cpthread()
	{
	}

	//--------------------------------------------------------------------------------
	Cpthread::~Cpthread()
	{
	}

	//--------------------------------------------------------------------------------
	int Cpthread::atfork( void (*)(void), void (*)(void), void(*)(void) )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::atfork" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_destroy( pthread_attr_t* p_pthread_attr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getdetachstate( const pthread_attr_t* p_pthread_attr, int* pDetachState )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getdetachstate" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getguardsize( const pthread_attr_t* p_pthread_attr, size_t* guardsize )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getguardsize" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getinheritsched( const pthread_attr_t* p_pthread_attr, int* inheritsched )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getinheritsched" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getschedparam( const pthread_attr_t* p_pthread_attr, sched_param* param )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getschedparam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getschedpolicy( const pthread_attr_t* p_pthread_attr, int* policy )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getschedpolicy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getscope( const pthread_attr_t* p_pthread_attr, int* contentionscope )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getscope" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getstack( const pthread_attr_t* p_pthread_attr, void** stackaddr, size_t* stacksize )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getstack" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getstackaddr( const pthread_attr_t* p_pthread_attr, void** stackaddr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getstackaddr" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_getstacksize( const pthread_attr_t* p_pthread_attr, size_t* stacksize )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_getstacksize" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_init( pthread_attr_t* p_pthread_attr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setdetachstate( pthread_attr_t* p_pthread_attr, int iDetachState )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setdetachstate" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setguardsize( pthread_attr_t* p_pthread_attr, size_t guardsize )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setguardsize" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setinheritsched( pthread_attr_t* p_pthread_attr, int inheritsched )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setinheritsched" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setschedparam( pthread_attr_t* p_pthread_attr, const sched_param* param )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setschedparam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setschedpolicy( pthread_attr_t* p_pthread_attr, int iPolicy )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setschedpolicy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setscope( pthread_attr_t* p_pthread_attr, int iContentionScope )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setscope" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setstack( pthread_attr_t* p_pthread_attr, void* stackaddr, size_t stacksize )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setstack" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setstackaddr( pthread_attr_t* p_pthread_attr, void* pStackAddr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setstackaddr" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::attr_setstacksize( pthread_attr_t* p_pthread_attr, size_t StackSize )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::attr_setstacksize" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrier_destroy( pthread_barrier_t* p_pthread_barrier )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrier_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrier_init( pthread_barrier_t* pp_barrier, const pthread_barrierattr_t* pp_barrier_attr, unsigned uiCount )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrier_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrier_wait( pthread_barrier_t* pp_barrier )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrier_wait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrierattr_destroy( pthread_barrierattr_t* pp_barrierattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrierattr_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrierattr_getpshared( const pthread_barrierattr_t* pp_barrierattr, int* p_pshared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrierattr_getpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrierattr_init( pthread_barrierattr_t* pp_barrierattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrierattr_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::barrierattr_setpshared( pthread_barrierattr_t* pp_barrierattr, int iPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::barrierattr_setpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cancel( pthread_t hpthread )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cancel" );
		errno = ENOSYS;
		return 0;
	}
	/*
	//--------------------------------------------------------------------------------
	int Cpthread::cleanup_push( void ( *routine )(void *), void* arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cleanup_push" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cleanup_pop( int iExecute )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cleanup_pop" );
		errno = ENOSYS;
		return 0;
	}
	*/
	//--------------------------------------------------------------------------------
	int Cpthread::create( pthread_t* phThread, const pthread_attr_t* pp_threadattr, void *(*start_routine)(void *), void* arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::create" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::detach( pthread_t hThread )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::detach" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::equal( pthread_t hThread1, pthread_t hThread2 )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::equal" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cpthread::exit( void* value_ptr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::exit" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::getconcurrency( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::getconcurrency" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::getcpuclockid( pthread_t hThread, clockid_t* pClockId )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::getcpuclockid" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::getschedparam( pthread_t hThread, int* pPolicy, sched_param* pParam )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::getschedparam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	void* Cpthread::getspecific( pthread_key_t p_pthreadkey )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::getspecific" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::join( pthread_t hThread, void** ppValue )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::join" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	pthread_t Cpthread::self( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::self" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::setcancelstate( int iState, int* piOldState )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::setcancelstate" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::setcanceltype( int iType, int* piOldType )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::setcanceltype" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::setconcurrency( int iConcurrency )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::setconcurrency" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::setschedparam( pthread_t hThread, int iPolicy, const sched_param* pParam )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::setschedparam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::setschedprio( pthread_t hThread, int iPriority )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::setschedprio" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::setspecific( pthread_key_t key, const void* pValue )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::setspecific" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cpthread::testcancel( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::testcancel" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::key_create( pthread_key_t* pp_pthreadkey, void (*destructor)(void *) )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::key_create" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::key_delete( pthread_key_t p_pthreadkey )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::key_delete" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cond_broadcast( pthread_cond_t* pp_pthread_cond )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cond_broadcast" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cond_destroy( pthread_cond_t* pp_pthread_cond )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cond_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cond_init( pthread_cond_t* pp_pthread_cond, const pthread_condattr_t* pp_pthread_condattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cond_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cond_signal( pthread_cond_t* pp_pthread_cond )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cond_signal" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cond_timedwait( pthread_cond_t* pp_pthread_cond, pthread_mutex_t* pp_pthread_mutex, const timespec* ptimespec )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cond_timedwait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::cond_wait( pthread_cond_t* pp_pthread_cond, pthread_mutex_t* pp_pthread_mutex )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::cond_wait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::condattr_destroy( pthread_condattr_t* pp_pthread_condattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::condattr_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::condattr_getclock( const pthread_condattr_t* pp_pthread_condattr, clockid_t* pClockId )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::condattr_getclock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::condattr_getpshared( const pthread_condattr_t* pp_pthread_condattr, int* piPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::condattr_getpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::condattr_init( pthread_condattr_t* pp_pthread_condattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::condattr_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::condattr_setclock( pthread_condattr_t* pp_pthread_condattr, clockid_t ClockId )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::condattr_setclock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::condattr_setpshared( pthread_condattr_t* pp_pthread_condattr, int iPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::condattr_setpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_consistent( pthread_mutex_t* pp_pthreadmutex )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_consistent" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_destroy( pthread_mutex_t* pp_pthreadmutex )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_getprioceiling( const pthread_mutex_t* pp_pthreadmutex, int* pPrioCeiling )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_getprioceiling" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_init( pthread_mutex_t* pp_pthreadmutex, const pthread_mutexattr_t* pp_pthreadmutexattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_lock( pthread_mutex_t* pp_pthreadmutex )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_lock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_setprioceiling( pthread_mutex_t* pp_pthreadmutex, int iPrioCeiling, int* pOldCieling )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_setprioceiling" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_timedlock( pthread_mutex_t* pp_pthreadmutex, const timespec* ptimespec )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_timedlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_trylock( pthread_mutex_t* pp_pthreadmutex )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_trylock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutex_unlock( pthread_mutex_t* pp_pthreadmutex )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutex_unlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_destroy( pthread_mutexattr_t* pp_pthreadmutexattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getprioceiling( const pthread_mutexattr_t* pp_pthreadmutexattr, int* piPrioCeiling )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_getprioceiling" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getprotocol( const pthread_mutexattr_t* pp_pthreadmutexattr, int* piProtocol )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_getprotocol" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getpshared( const pthread_mutexattr_t* pp_pthreadmutexattr, int* piPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_getpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_getrobust( const pthread_mutexattr_t* pp_pthreadmutexattr, int* piPRobust )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_getrobust" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_gettype( const pthread_mutexattr_t* pp_pthreadmutexattr, int* piType )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_gettype" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_init( pthread_mutexattr_t* pp_pthreadmutexattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_setprioceiling( pthread_mutexattr_t* pp_pthreadmutexattr, int iPrioCeiling )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_setprioceiling" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_setprotocol( pthread_mutexattr_t* pp_pthreadmutexattr, int iProtocol )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_setprotocol" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_setpshared( pthread_mutexattr_t* pp_pthreadmutexattr, int iPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_setpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::mutexattr_settype( pthread_mutexattr_t* pp_pthreadmutexattr, int iType )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::mutexattr_settype" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::once( pthread_once_t* pp_pthreadonce, void (*init_routine)( void ) )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::once" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_destroy( pthread_rwlock_t* pp_pthreadrwlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_init( pthread_rwlock_t* pp_pthreadrwlock, const pthread_rwlockattr_t* pp_pthreadrwlockattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_rdlock( pthread_rwlock_t* pp_pthreadrwlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_rdlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_timedrdlock( pthread_rwlock_t* pp_pthreadrwlock, const timespec* ptimespec )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_timedrdlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_timedwrlock( pthread_rwlock_t* pp_pthreadrwlock, const timespec* ptimespec )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_timedwrlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_tryrdlock( pthread_rwlock_t* pp_pthreadrwlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_tryrdlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_trywrlock( pthread_rwlock_t* pp_pthreadrwlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_trywrlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_unlock( pthread_rwlock_t* pp_pthreadrwlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_unlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlock_wrlock( pthread_rwlock_t* pp_pthreadrwlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlock_wrlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlockattr_destroy( pthread_rwlockattr_t* pp_pthreadrwlockattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlockattr_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlockattr_getpshared( const pthread_rwlockattr_t* pp_pthreadrwlockattr, int* piPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlockattr_getpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlockattr_init( pthread_rwlockattr_t* pp_pthreadrwlockattr )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlockattr_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::rwlockattr_setpshared( pthread_rwlockattr_t* pp_pthreadrwlockattr, int iPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::rwlockattr_setpshared" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::spin_destroy( pthread_spinlock_t* pp_pthreadspinlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::spin_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::spin_init( pthread_spinlock_t* pp_pthreadspinlock, int iPShared )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::spin_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::spin_lock( pthread_spinlock_t* pp_pthreadspinlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::spin_lock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::spin_trylock( pthread_spinlock_t* pp_pthreadspinlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::spin_trylock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::spin_unlock( pthread_spinlock_t* pp_pthreadspinlock )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::spin_unlock" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_post_multiple( sem_t* sem, int count )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_post_multiple" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_wait( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_wait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_unlink( const char* szName )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_unlink" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_trywait( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_trywait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_timedwait( sem_t* pSem, const timespec* pAbs_Timeout )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_timedwait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_post( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_post" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	sem_t* Cpthread::sem_open( const char* szName, int iOFlags )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_open" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_init( sem_t* pSem, int iPShared, unsigned uValue )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_getvalue( sem_t* pSem, int* piValue )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_getvalue" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_destroy( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpthread::sem_close( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Cpthread::sem_close" );
		errno = ENOSYS;
		return 0;
	}

}//nsBaseCRT
