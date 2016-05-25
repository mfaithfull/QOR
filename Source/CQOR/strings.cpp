//strings.cpp

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
#include <strings.h>
#include <errno.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMHEADER(strings.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Cstrings _strings;
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int ffs( int i )
{
    __QCS_FCONTEXT( "ffs" );
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _strings.ffs( i );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int strcasecmp( const char* s1, const char* s2 )
{
    __QCS_FCONTEXT( "strcasecmp" );
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _strings.strcasecmp( s1, s2 );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int strcasecmp_l( const char* s1, const char* s2, locale_t l )
{    
	__QCS_FCONTEXT( "strcasecmp_l" );
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _strings.strcasecmp_l( s1, s2, l );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int strncasecmp( const char* s1, const char* s2, size_t n )
{
    __QCS_FCONTEXT( "strncasecmp" );
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _strings.strncasecmp( s1, s2, n );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int strncasecmp_l( const char* s1, const char* s2, size_t n, locale_t l )
{
    __QCS_FCONTEXT( "strncasecmp_l" );
    int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _strings.strncasecmp_l( s1, s2, n, l );
    }__QCS_ENDPROTECT
    return iResult;
}

__QCMP_ENDLINKAGE_C


