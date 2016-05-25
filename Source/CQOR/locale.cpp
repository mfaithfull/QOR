//locale.cpp

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

//Generic locale implementation

#include "CQOR/CQORPolicy.h"
#include <locale.h>
#include <errno.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMHEADER(locale.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Clocale _locale;
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) locale_t duplocale( locale_t l )
{
    __QCS_FCONTEXT( "duplocale" );
	locale_t Result;
    __QCS_PROTECT
    {
        Result = _locale.duplocale( l );
    }__QCS_ENDPROTECT
	return Result;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void freelocale( locale_t l )
{
    __QCS_FCONTEXT( "freelocale" );
    __QCS_PROTECT
    {
        _locale.freelocale( l );
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) lconv* localeconv( void )
{
    __QCS_FCONTEXT( "localeconv" );
    lconv* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _locale.localeconv();
    }__QCS_ENDPROTECT
    return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) locale_t newlocale( int iCategoryMask, const char* szLocale, locale_t lBase )
{
    __QCS_FCONTEXT( "newlocale" );
    locale_t Result;
    __QCS_PROTECT
    {
        Result = _locale.newlocale( iCategoryMask, szLocale, lBase );
    }__QCS_ENDPROTECT
    return Result;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) char* setlocale( int category, const char* locale )
{
    __QCS_FCONTEXT( "setlocale" );
    char* pResult = 0;
    __QCS_PROTECT
    {
        pResult = _locale.setlocale( category, locale );
    }__QCS_ENDPROTECT
    return pResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) locale_t uselocale( locale_t l )
{
    __QCS_FCONTEXT( "uselocale" );
    locale_t Result = 0;
    __QCS_PROTECT
    {
        Result = _locale.uselocale( l );
    }__QCS_ENDPROTECT
    return Result;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) ::lconv* localeconv_l( ::locale_t loc )
{
    __QCS_FCONTEXT( "localeconv_l" );
    lconv* pResult = 0;
    __QCS_PROTECT
    {
		pResult = _locale.localeconv_l( loc );
	}__QCS_ENDPROTECT
	return pResult;
}

__QCMP_ENDLINKAGE_C
