//LIN_semaphore.h

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

//Linux overrides for semaphore

#ifndef SYSTEMQOR_LIN_SEMAPHORE_H_3
#define SYSTEMQOR_LIN_SEMAPHORE_H_3

#include "SystemQOR/Linux/types/semaphore_types.h"
#include "SystemQOR/Posix/Basesemaphore.h"

//--------------------------------------------------------------------------------
namespace nsLinux
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Csemaphore : public nsBaseCRT::Csemaphore
	{
	public:

		Csemaphore(){}
		~Csemaphore(){}

		virtual int    sem_close(sem_t *);
		virtual int    sem_destroy(sem_t *);
		virtual int    sem_getvalue(sem_t *__restrict, int *__restrict);
		virtual int    sem_init(sem_t *, int, unsigned);
		virtual sem_t *sem_open(const char *, int, ...);
		virtual int    sem_post(sem_t *);
		virtual int    sem_timedwait(sem_t *__restrict, const timespec *__restrict);
		virtual int    sem_trywait(sem_t *);
		virtual int    sem_unlink(const char *);
		virtual int    sem_wait(sem_t *);

	private:

		Csemaphore( const Csemaphore& );
		Csemaphore& operator = ( const Csemaphore& );

	};

}//nsLinux

#endif//SYSTEMQOR_LIN_SEMAPHORE_H_3
