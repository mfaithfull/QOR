//time.cpp

// Copyright Querysoft Limited 2015
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

//Generic time implementation
//An exported standard C interface which forwards calls to the matching C++ implementaion for the platform

#include <sys/time.h>
#include <errno.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMSYSHEADER(time.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Csystime _time;
}//anonymous

typedef nsPlatform::timeval timeval;

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int getitimer( int which, ::itimerval* value )
{
	__QCS_FCONTEXT( "getitimer" );
	int iResult = 0;
	__QCS_PROTECT
	{
		iResult = _time.getitimer( which, value );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int gettimeofday( ::timeval* __QCMP_RESTRICT tp, void* __QCMP_RESTRICT tzp )
{
	__QCS_FCONTEXT( "getimeofday" );
	int iResult = 0;
	__QCS_PROTECT
	{
		iResult = _time.gettimeofday( tp, tzp );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int setitimer( int which, const ::itimerval* __QCMP_RESTRICT value, ::itimerval* __QCMP_RESTRICT ovalue )
{
	__QCS_FCONTEXT( "setitimer" );
	int iResult = 0;
	__QCS_PROTECT
	{
		iResult = _time.setitimer( which, value, ovalue );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int utimes( const char* path, const ::timeval times[ 2 ] )
{
	__QCS_FCONTEXT( "utimes" );
	int iResult = 0;
	__QCS_PROTECT
	{
		iResult = _time.utimes( path, times );
	}__QCS_ENDPROTECT
	return iResult;
}

__QCMP_ENDLINKAGE_C
