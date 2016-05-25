//WinQMultiMonitor.cpp

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

//Multiple Monitor functions

#include "WinQAPI/User32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	BOOL CUser32::EnumDisplayMonitors( HDC hdc, LPCRECT lprcClip, ::MONITORENUMPROC lpfnEnum, LPARAM dwData )
	{
		_WINQ_FCONTEXT( "CUser32::EnumDisplayMonitors" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EnumDisplayMonitors );
		bResult = Call< BOOL, HDC, LPCRECT, ::MONITORENUMPROC, LPARAM >( pFunc, hdc, lprcClip, lpfnEnum, dwData );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetMonitorInfo( HMONITOR hMonitor, ::LPMONITORINFO lpmi )
	{
		_WINQ_FCONTEXT( "CUser32::GetMonitorInfo" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPIAW( GetMonitorInfo );
		bResult = Call< BOOL, HMONITOR, ::LPMONITORINFO >( pFunc, hMonitor, lpmi );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HMONITOR CUser32::MonitorFromPoint( ::POINT pt, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::MonitorFromPoint" );
		_WINQ_USESAPI( MonitorFromPoint );
		return Call< HMONITOR, ::POINT, DWORD >( pFunc, pt, dwFlags );
	}

	//--------------------------------------------------------------------------------
	HMONITOR CUser32::MonitorFromRect( LPCRECT lprc, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::MonitorFromRect" );
		_WINQ_USESAPI( MonitorFromRect );
		return Call< HMONITOR, LPCRECT, DWORD >( pFunc, lprc, dwFlags );
	}

	//--------------------------------------------------------------------------------
	HMONITOR CUser32::MonitorFromWindow( HWND hwnd, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::MonitorFromWindow" );
		_WINQ_USESAPI( MonitorFromWindow );
		return Call< HMONITOR, HWND, DWORD >( pFunc, hwnd, dwFlags );
	}

}//nsWinQAPI
