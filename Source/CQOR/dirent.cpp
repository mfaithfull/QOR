//dirent.cpp

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

//Generic dirent implementation
//An exported standard C interface which forwards calls to the matching C++ implementaion for the platform

#include "CQOR/CQORPolicy.h"
#include <dirent.h>
#include <errno.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMHEADER(dirent.h)				//Include the platform specific dirent.h
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace 
{
	nsPlatform::Cdirent _dirent;					//Local instance of the platform dirent implementation
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int alphasort( const dirent** d1, const dirent** d2)
{
	__QCS_FCONTEXT( "alphasort" );
	
	int iResult = -1;
	__QCS_PROTECT
	{
		iResult = _dirent.alphasort( d1, d2 );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int closedir( DIR* dirp )
{
    __QCS_FCONTEXT( "closedir" );
    
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _dirent.closedir( dirp );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int dirfd( DIR* pDIR )
{
	__QCS_FCONTEXT( "dirfd" );
	
	int iResult = -1;
	__QCS_PROTECT
	{
		iResult = _dirent.dirfd( pDIR );
	}__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) DIR* fdopendir( int nFD )
{
	__QCS_FCONTEXT( "fdopendir" );
	
	DIR* pResult = 0;
	__QCS_PROTECT
	{
		pResult = _dirent.fdopendir( nFD );
	}__QCS_ENDPROTECT
	return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) DIR* opendir( const char* dirname )
{
    __QCS_FCONTEXT( "opendir" );
    
    DIR* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _dirent.opendir( dirname );
    }__QCS_ENDPROTECT
    return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) dirent* readdir( DIR* dirp )
{
    __QCS_FCONTEXT( "readdir" );
    
    dirent* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _dirent.readdir( dirp );
    }__QCS_ENDPROTECT
    return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int readdir_r( DIR* __QCMP_RESTRICT dirp, dirent* __QCMP_RESTRICT entry, dirent** __QCMP_RESTRICT result )
{
    __QCS_FCONTEXT( "readdir_r" );
    
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _dirent.readdir_r( dirp, entry, result );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void rewinddir( DIR* dirp )
{
    __QCS_FCONTEXT( "rewinddir" );
    
    __QCS_PROTECT
    {
        _dirent.rewinddir( dirp );
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int scandir( const char* szDir, dirent*** namelist, int (*sel)( const dirent* ), int (*compar)( const dirent**, const dirent** ) )
{
    __QCS_FCONTEXT( "seekdir" );
    
	int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _dirent.scandir( szDir, namelist, sel, compar );
    }__QCS_ENDPROTECT
	return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void seekdir( DIR* dirp, long loc )
{
    __QCS_FCONTEXT( "seekdir" );
    
    __QCS_PROTECT
    {
        _dirent.seekdir( dirp, loc );
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long telldir( DIR* dirp )
{
    __QCS_FCONTEXT( "telldir" );
    
    long lResult = 0;
    __QCS_PROTECT
    {
        lResult = _dirent.telldir( dirp );
    }__QCS_ENDPROTECT
    return lResult;
}

__QCMP_ENDLINKAGE_C

