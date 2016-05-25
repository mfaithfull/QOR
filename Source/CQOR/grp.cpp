//grp.cpp

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

//Generic grp implementation
//An exported standard C interface which forwards calls to the matching C++ implementaion for the platform

#include "CQOR/CQORPolicy.h"
#include <grp.h>
#include QOR_SYS_PLATFORMHEADER(grp.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Cgrp _grp;
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void endgrent( void )
{
    __QCS_FCONTEXT( "endgrent" );
    __QCS_PROTECT
    {
		_grp.endgrent();
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) group* getgrent( void )
{
	__QCS_FCONTEXT( "getgrent" );
	group* pResult = 0;
	__QCS_PROTECT
	{
		pResult = _grp.getgrent();
	}__QCS_ENDPROTECT
	return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) group* getgrgid( gid_t id )
{
	__QCS_FCONTEXT( "getgrgid" );
	group* pResult = 0;
	__QCS_PROTECT
	{
		pResult = _grp.getgrgid( id );
	}__QCS_ENDPROTECT
	return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int getgrgid_r( gid_t gid, group* grp, char* buffer, size_t buffsize, group** result )
{
	__QCS_FCONTEXT( "getgrgid_r" );
	int iResult = 0;
	__QCS_PROTECT
	{
		iResult = _grp.getgrgid_r( gid, grp, buffer, buffsize, result );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) group* getgrnam( const char* szGrp )
{
	__QCS_FCONTEXT( "getgrnam" );
	group* pGroup = 0;
	__QCS_PROTECT
	{
		pGroup = _grp.getgrnam( szGrp );
	}__QCS_ENDPROTECT
	return pGroup;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int getgrnam_r( const char* name, group* grp, char* buffer, size_t buffsize, group** result )
{
	__QCS_FCONTEXT( "getgrnam_r" );
	int iResult = 0;
	__QCS_PROTECT
	{
		iResult = _grp.getgrnam_r( name, grp, buffer, buffsize, result );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void setgrent( void )
{
	__QCS_FCONTEXT( "setgrent" );
	__QCS_PROTECT
	{
		_grp.setgrent();
	}__QCS_ENDPROTECT
}

__QCMP_ENDLINKAGE_C


