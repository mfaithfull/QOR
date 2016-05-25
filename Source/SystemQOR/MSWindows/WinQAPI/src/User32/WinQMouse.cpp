//WinQMouse.cpp

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

//Mouse functions

#include "WinQAPI/User32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	BOOL CUser32::DragDetect( HWND hwnd, ::POINT pt )
	{
		_WINQ_FCONTEXT( "CUser32::DragDetect" );
		_WINQ_USESAPI( DragDetect );
		return Call< BOOL, HWND, ::POINT >( pFunc, hwnd, pt );
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetCapture( void )
	{
		_WINQ_FCONTEXT( "CUser32::GetCapture" );
		_WINQ_USESAPI( GetCapture );
		return Call< HWND >( pFunc );
	}

	//--------------------------------------------------------------------------------
	UINT CUser32::GetDoubleClickTime( void )
	{
		_WINQ_FCONTEXT( "CUser32::GetDoubleClickTime" );
		_WINQ_USESAPI( GetDoubleClickTime );
		return Call< UINT >( pFunc );
	}

	//--------------------------------------------------------------------------------
	int CUser32::GetMouseMovePointsEx( UINT cbSize, LPMOUSEMOVEPOINT lppt, LPMOUSEMOVEPOINT lpptBuf, int nBufPoints, DWORD resolution )
	{
		_WINQ_FCONTEXT( "CUser32::GetMouseMovePointsEx" );
		CCheckReturn< int, CTCheckFailureValue< int, -1 > >::TType iResult;
		_WINQ_USESAPI( GetMouseMovePointsEx );
		iResult = Call< int, UINT, LPMOUSEMOVEPOINT, LPMOUSEMOVEPOINT, int, DWORD >( pFunc, cbSize, lppt, lpptBuf, nBufPoints, resolution );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	VOID CUser32::mouse_event( DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo )
	{
		_WINQ_FCONTEXT( "CUser32::mouse_event" );
		_WINQ_USESAPI( mouse_event );
		voidCall< DWORD, DWORD, DWORD, DWORD, ULONG_PTR >( pFunc, dwFlags, dx, dy, dwData, dwExtraInfo );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::ReleaseCapture(void)
	{
		_WINQ_FCONTEXT( "CUser32::ReleaseCapture" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( ReleaseCapture );
		bResult = Call< BOOL >( pFunc );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::SetCapture( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::SetCapture" );
		_WINQ_USESAPI( SetCapture );
		return Call< HWND, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetDoubleClickTime( UINT uInterval )
	{
		_WINQ_FCONTEXT( "CUser32::SetDoubleClickTime" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetDoubleClickTime );
		bResult = Call< BOOL, UINT >( pFunc, uInterval );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SwapMouseButton( BOOL fSwap )
	{
		_WINQ_FCONTEXT( "CUser32::SwapMouseButton" );
		_WINQ_USESAPI( SwapMouseButton );
		return Call< BOOL, BOOL >( pFunc, fSwap );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::TrackMouseEvent( LPTRACKMOUSEEVENT lpEventTrack )
	{
		_WINQ_FCONTEXT( "CUser32::TrackMouseEvent" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( TrackMouseEvent );
		bResult = Call< BOOL, LPTRACKMOUSEEVENT >( pFunc, lpEventTrack );
		return bResult;
	}

}//nsWinQAPI

