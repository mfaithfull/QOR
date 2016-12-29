//Basesemaphore.cpp

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

#include "SystemQOR/Posix/Basesemaphore.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID( Csemaphore );

	//--------------------------------------------------------------------------------
	Csemaphore::Csemaphore()
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::Csemaphore" );
	}

	//--------------------------------------------------------------------------------
	Csemaphore::~Csemaphore()
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::~Csemaphore" );
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_close( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_close" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_destroy( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_destroy" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_getvalue( sem_t* pSem, int* piValue )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_getvalue" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_init( sem_t* pSem, int iPShared, unsigned uValue )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_init" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	sem_t* Csemaphore::sem_open( const char* szName, int iOFlags, ... )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_open" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_post( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_post" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_timedwait( sem_t* pSem, const timespec* pAbs_Timeout )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_timedwait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_trywait( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_trywait" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_unlink( const char* szName )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_unlink" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_wait( sem_t* pSem )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_wait" );
		errno = ENOSYS;
		return 0;
	}
	
	//extensions

	//--------------------------------------------------------------------------------
	int Csemaphore::sem_post_multiple( sem_t* sem, int count )
	{
		__QCS_MEMBER_FCONTEXT( "Csemaphore::sem_post_multiple" );
		errno = ENOSYS;
		return 0;
	}
	
}//nsBaseCRT