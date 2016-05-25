//WinQLWaitableTimer.h

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

#ifndef WINQL_APP_WAITABLETIMER_H_3
#define WINQL_APP_WAITABLETIMER_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Security.h"
#include "WinQL/Definitions/Data.h"
#include "WinQL/CodeServices/Handles/WinQLSyncHandle.h"

//------------------------------------------------------------------------------
namespace nsWin32
{
	//------------------------------------------------------------------------------
	typedef void ( __QCMP_STDCALLCONVENTION *PTIMERAPCROUTINE )( void* lpArgToCompletionRoutine, unsigned long dwTimerLowValue, unsigned long dwTimerHighValue );

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CWaitableTimer
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CWaitableTimer );

		CWaitableTimer( bool bManualReset = true );
		CWaitableTimer( const CWaitableTimer& );
		CWaitableTimer& operator = ( const CWaitableTimer& );
		virtual ~CWaitableTimer();
		CWaitableTimer( nsWin32::LPSECURITY_ATTRIBUTES lpTimerAttributes, bool bManualReset, const TCHAR* lpTimerName, bool& bAlreadyExists );
		CWaitableTimer( nsWin32::LPSECURITY_ATTRIBUTES lpTimerAttributes, const TCHAR* lpTimerName, unsigned long dwFlags, unsigned long dwDesiredAccess, bool& bAlreadyExists );
		CWaitableTimer( unsigned long dwDesiredAccess, bool bInheritHandle, const TCHAR* lpTimerName );			
		bool Set( const nsWin32::LARGE_INTEGER* pDueTime, long lPeriod, nsWin32::PTIMERAPCROUTINE pfnCompletionRoutine, void* lpArgToCompletionRoutine, bool fResume );
		bool Cancel( void );
		unsigned long Wait( bool bAlertable = false );
		nsCodeQOR::CTLRef< CSyncHandle > Handle( void );

	private:

		CSyncHandle m_Handle;
	};

}//nsWin32

#endif//WINQL_APP_WAITABLETIMER_H_3
