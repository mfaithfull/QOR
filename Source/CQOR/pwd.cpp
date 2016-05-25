//pwd.cpp

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

#include "CQOR/CQORPolicy.h"
#include <pwd.h>
#include <errno.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMHEADER(pwd.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Cpwd _pwd;
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) passwd* getpwnam( const char* szName )
{
    __QCS_FCONTEXT( "getpwnam" );
	passwd* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _pwd.getpwnam( szName );
    }__QCS_ENDPROTECT
	return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) passwd* getpwuid( uid_t id )
{
    __QCS_FCONTEXT( "getpwuid" );
	passwd* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _pwd.getpwuid( id );
    }__QCS_ENDPROTECT
	return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int getpwnam_r( const char* name, passwd* pwd, char* buffer, size_t buffersize, passwd** result )
{
    __QCS_FCONTEXT( "getpwnam_r" );
	int iResult = 0;
    __QCS_PROTECT
    {
        iResult = _pwd.getpwnam_r( name, pwd, buffer, buffersize, result );
    }__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int getpwuid_r( uid_t uid, passwd* pwd, char* buffer, size_t buffersize, passwd** result )
{
    __QCS_FCONTEXT( "getpwuid_r" );
	int iResult = 0;
    __QCS_PROTECT
    {
        iResult = _pwd.getpwuid_r( uid, pwd, buffer, buffersize, result );
    }__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void endpwent( void )
{
    __QCS_FCONTEXT( "endpwent" );
    __QCS_PROTECT
    {
        _pwd.endpwent();
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) passwd* getpwent( void )
{
    __QCS_FCONTEXT( "getpwent" );
	passwd* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _pwd.getpwent();
    }__QCS_ENDPROTECT
	return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void setpwent( void )
{
	__QCS_FCONTEXT( "setpwent" );
	__QCS_PROTECT
	{
		_pwd.setpwent();
	}__QCS_ENDPROTECT
}

__QCMP_ENDLINKAGE_C


