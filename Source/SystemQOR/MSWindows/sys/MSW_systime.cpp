//MSW_systime.cpp

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

#include "SystemQOR.h"

#if		(QOR_SYS_OS == QOR_SYS_MSW)

#include "SystemQOR/MSWindows/sys/MSW_time.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( Csystime );

	//--------------------------------------------------------------------------------
	Csystime::Csystime()
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::Csystime" );
	}

	//--------------------------------------------------------------------------------
	Csystime::~Csystime()
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::~Csystime" );
	}

	//--------------------------------------------------------------------------------
    int Csystime::getitimer( int, itimerval* )
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::getitimer" );
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Csystime::gettimeofday( timeval* __QCMP_RESTRICT, void* __QCMP_RESTRICT )
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::gettimeofday" );
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Csystime::select( int, fd_set* __QCMP_RESTRICT, fd_set* __QCMP_RESTRICT, fd_set* __QCMP_RESTRICT, timeval* __QCMP_RESTRICT )
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::select" );
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Csystime::setitimer( int, const itimerval* __QCMP_RESTRICT, itimerval* __QCMP_RESTRICT )
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::setitimer" );
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Csystime::utimes( const char*, const timeval[ 2 ] )
	{
		__QCS_MEMBER_FCONTEXT( "Csystime::utimes" );
		return 0;
	}

}//nsWin32

#endif	//(QOR_SYS_OS == QOR_SYS_MSW)
