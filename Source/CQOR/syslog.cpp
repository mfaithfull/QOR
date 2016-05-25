//syslog.cpp

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
#include <syslog.h>
#include <errno.h>
#include <stdarg.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMHEADER(syslog.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Csyslog _syslog;
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void closelog()
{
    __QCS_FCONTEXT( "closelog" );
    __QCS_PROTECT
    {
        _syslog.closelog();
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void openlog( const char* ident, int logopt, int facility )
{
    __QCS_FCONTEXT( "openlog" );
    __QCS_PROTECT
    {
        _syslog.openlog( ident, logopt, facility );
    }__QCS_ENDPROTECT
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) int setlogmask( int iMaskPri )
{
    __QCS_FCONTEXT( "setlogmask" );
	int iResult = -1;
    __QCS_PROTECT
    {
        iResult = _syslog.setlogmask( iMaskPri );
    }__QCS_ENDPROTECT
    return iResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) void syslog( int iPriority, const char* szMessage, ... )
{
    __QCS_FCONTEXT( "syslog" );

    __QCS_PROTECT
    {
		va_list args;
		va_start( args, szMessage );
        _syslog.syslog( iPriority, szMessage, args );
		va_end( args );
    }__QCS_ENDPROTECT
    return;
}

__QCMP_ENDLINKAGE_C

