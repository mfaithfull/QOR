//WinQWindow.cpp

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

//Window functions

#include "WinQAPI/User32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	BOOL CUser32::AdjustWindowRect( ::LPRECT lpRect, DWORD dwStyle, BOOL bMenu )
	{
		_WINQ_FCONTEXT( "CUser32::AdjustWindowRect" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( AdjustWindowRect );
		bResult = Call< BOOL, ::LPRECT, DWORD, BOOL >( pFunc, lpRect, dwStyle, bMenu );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::AdjustWindowRectEx( ::LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle )
	{
		_WINQ_FCONTEXT( "CUser32::AdjustWindowRectEx" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( AdjustWindowRectEx );
		bResult = Call< BOOL, ::LPRECT, DWORD, BOOL, DWORD >( pFunc, lpRect, dwStyle, bMenu, dwExStyle );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::AllowSetForegroundWindow( DWORD dwProcessId )
	{
		_WINQ_FCONTEXT( "CUser32::AllowSetForegroundWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( AllowSetForegroundWindow );
		bResult = Call< BOOL, DWORD >( pFunc, dwProcessId );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::AnimateWindow( HWND hwnd, DWORD dwTime, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::AnimateWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( AnimateWindow );
		bResult = Call< BOOL, HWND, DWORD, DWORD >( pFunc, hwnd, dwTime, dwFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::AnyPopup(void)
	{
		_WINQ_FCONTEXT( "CUser32::AnyPopup" );
		_WINQ_USESAPI( AnyPopup );
		return Call< BOOL >( pFunc );
	}

	//--------------------------------------------------------------------------------
	UINT CUser32::ArrangeIconicWindows( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::ArrangeIconicWindows" );
		CCheckReturn< UINT, CCheckNonZero< UINT > >::TType uiResult;
		_WINQ_USESAPI( ArrangeIconicWindows );
		uiResult = Call< UINT, HWND >( pFunc, hWnd );
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	HDWP CUser32::BeginDeferWindowPos( int nNumWindows )
	{
		_WINQ_FCONTEXT( "CUser32::BeginDeferWindowPos" );
		CCheckReturn< HDWP, CCheckNonZero< HDWP > >::TType Result;
		_WINQ_USESAPI( BeginDeferWindowPos );
		Result = Call< HDWP, int >( pFunc, nNumWindows );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::BringWindowToTop( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::BringWindowToTop" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( BringWindowToTop );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	WORD CUser32::CascadeChildWindows( HWND hWndParent, WORD wFlags )
	{
		_WINQ_FCONTEXT( "CUser32::CascadeChildWindows" );
		CCheckReturn< WORD, CCheckNonZero< WORD > >::TType wResult;
		_WINQ_USESAPI( CascadeChildWindows );
		wResult = Call< WORD, HWND, WORD >( pFunc, hWndParent, wFlags );
		return wResult;
	}

	//--------------------------------------------------------------------------------
	WORD CUser32::CascadeWindows( HWND hwndParent, UINT wHow, const ::RECT* lpRect, UINT cKids, const HWND* lpKids )
	{
		_WINQ_FCONTEXT( "CUser32::CascadeWindows" );
		CCheckReturn< WORD, CCheckNonZero< WORD > >::TType wResult;
		_WINQ_USESAPI( CascadeWindows );
		wResult = Call< WORD, HWND, UINT, const ::RECT*, UINT, const HWND* >( pFunc, hwndParent, wHow, lpRect, cKids, lpKids );
		return wResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::ChangeWindowMessageFilter( UINT message, DWORD dwFlag )
	{
		_WINQ_FCONTEXT( "CUser32::ChangeWindowMessageFilter" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( ChangeWindowMessageFilter );
		bResult = Call< BOOL, UINT, DWORD >( pFunc, message, dwFlag );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::ChildWindowFromPoint( HWND hWndParent, ::POINT Point )
	{
		_WINQ_FCONTEXT( "CUser32::ChildWindowFromPoint" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( ChildWindowFromPoint );
		Result = Call< HWND, HWND, ::POINT >( pFunc, hWndParent, Point );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::ChildWindowFromPointEx( HWND hwndParent, ::POINT pt, UINT uFlags )
	{
		_WINQ_FCONTEXT( "CUser32::ChildWindowFromPointEx" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( ChildWindowFromPointEx );
		Result = Call< HWND, HWND, ::POINT, UINT >( pFunc, hwndParent, pt, uFlags );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::CloseWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::CloseWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( CloseWindow );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::mxCreateWindow( LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam )
	{
		_WINQ_FCONTEXT( "CUser32::mxCreateWindow" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPIAW( CreateWindow );
		Result = Call< HWND, LPCTSTR, LPCTSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID >(
			pFunc, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::CreateWindowEx( DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam )
	{
		_WINQ_FCONTEXT( "CUser32::CreateWindowEx" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( CreateWindowEx );
		Result = Call< HWND, DWORD, LPCTSTR, LPCTSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID >( 
			pFunc, dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HDWP CUser32::DeferWindowPos( HDWP hWinPosInfo, HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags )
	{
		_WINQ_FCONTEXT( "CUser32::DeferWindowPos" );
		CCheckReturn< HDWP, CCheckNonZero< HDWP > >::TType Result;
		_WINQ_USESAPI( DeferWindowPos );
		Result = Call< HDWP, HDWP, HWND, HWND, int, int, int, int, UINT >( pFunc, hWinPosInfo, hWnd, hWndInsertAfter, x, y, cx, cy, uFlags );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::DeregisterShellHookWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::DeregisterShellHookWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( DeregisterShellHookWindow );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::DestroyWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::DestroyWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( DestroyWindow );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::EndDeferWindowPos( HDWP hWinPosInfo )
	{
		_WINQ_FCONTEXT( "CUser32::EndDeferWindowPos" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EndDeferWindowPos );
		bResult = Call< BOOL, HDWP >( pFunc, hWinPosInfo );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::EndTask( HWND hWnd, BOOL fShutDown, BOOL fForce )
	{
		_WINQ_FCONTEXT( "CUser32::EndTask" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EndTask );
		bResult = Call< BOOL, HWND >( pFunc, hWnd, fShutDown, fForce );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::EnumChildWindows( HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam )
	{
		_WINQ_FCONTEXT( "CUser32::EnumChildWindows" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EnumChildWindows );
		bResult = Call< BOOL, HWND, WNDENUMPROC, LPARAM >( pFunc, hWndParent, lpEnumFunc, lParam );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::EnumThreadWindows( DWORD dwThreadId, WNDENUMPROC lpfn, LPARAM lParam )
	{
		_WINQ_FCONTEXT( "CUser32::EnumThreadWindows" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EnumThreadWindows );
		bResult = Call< BOOL, DWORD, WNDENUMPROC, LPARAM >( pFunc, dwThreadId, lpfn, lParam );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::EnumWindows( WNDENUMPROC lpEnumFunc, LPARAM lParam )
	{
		_WINQ_FCONTEXT( "CUser32::EnumWindows" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EnumWindows );
		bResult = Call< BOOL, WNDENUMPROC, LPARAM >( pFunc, lpEnumFunc, lParam );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::FindWindow( LPCTSTR lpClassName, LPCTSTR lpWindowName )
	{
		_WINQ_FCONTEXT( "CUser32::FindWindow" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( FindWindow );
		Result = Call< HWND, LPCTSTR, LPCTSTR >( pFunc, lpClassName, lpWindowName );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::FindWindowEx( HWND hwndParent, HWND hwndChildAfter, LPCTSTR lpszClass, LPCTSTR lpszWindow )
	{
		_WINQ_FCONTEXT( "CUser32::FindWindowEx" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( FindWindowEx );
		Result = Call< HWND, HWND, HWND, LPCTSTR, LPCTSTR >( pFunc, hwndParent, hwndChildAfter, lpszClass, lpszWindow );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetAltTabInfo( HWND hwnd, int iItem, ::PALTTABINFO pati, LPTSTR pszItemText, UINT cchItemText )
	{
		_WINQ_FCONTEXT( "CUser32::GetAltTabInfo" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetAltTabInfo );
		bResult = Call< BOOL, HWND, int, ::PALTTABINFO, LPTSTR, UINT >( pFunc, hwnd, iItem, pati, pszItemText, cchItemText );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetAncestor( HWND hwnd, UINT gaFlags )
	{
		_WINQ_FCONTEXT( "CUser32::GetAncestor" );
		_WINQ_USESAPI( GetAncestor );
		return Call< HWND, HWND, UINT >( pFunc, hwnd, gaFlags );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetClientRect( HWND hWnd, ::LPRECT lpRect )
	{
		_WINQ_FCONTEXT( "CUser32::GetClientRect" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetClientRect );
		bResult = Call< BOOL, HWND, ::LPRECT >( pFunc, hWnd, lpRect );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetDesktopWindow(void)
	{
		_WINQ_FCONTEXT( "CUser32::GetDesktopWindow" );
		_WINQ_USESAPI( GetDesktopWindow );
		return Call< HWND >( pFunc );
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetForegroundWindow(void)
	{
		_WINQ_FCONTEXT( "CUser32::GetForegroundWindow" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( GetForegroundWindow );
		Result = Call< HWND >( pFunc );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetGUIThreadInfo( DWORD idThread, ::LPGUITHREADINFO lpgui )
	{
		_WINQ_FCONTEXT( "CUser32::GetGUIThreadInfo" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetGUIThreadInfo );
		bResult = Call< BOOL, DWORD, ::LPGUITHREADINFO >( pFunc, idThread, lpgui );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetLastActivePopup( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::GetLastActivePopup" );
		_WINQ_USESAPI( GetLastActivePopup );
		return Call< HWND, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetLayeredWindowAttributes( HWND hwnd, COLORREF* pcrKey, BYTE* pbAlpha, DWORD* pdwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::GetLayeredWindowAttributes" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetLayeredWindowAttributes );
		bResult = Call< BOOL, HWND, COLORREF*, BYTE*, DWORD* >( pFunc, hwnd, pcrKey, pbAlpha, pdwFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetParent( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::GetParent" );
		HWND Result = 0;
		_WINQ_USESAPI( GetParent );
		Result = Call< HWND, HWND >( pFunc, hWnd );
		if( Result == 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "GetParent" ), 0 ));
			}
		}
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetProcessDefaultLayout( DWORD* pdwDefaultLayout )
	{
		_WINQ_FCONTEXT( "CUser32::GetProcessDefaultLayout" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetProcesDefaultLayout );
		bResult = Call< BOOL, DWORD* >( pFunc, pdwDefaultLayout );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetShellWindow(void)
	{
		_WINQ_FCONTEXT( "CUser32::GetShellWindow" );
		_WINQ_USESAPI( GetShellWindow );
		return Call< HWND >( pFunc );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetTitleBarInfo( HWND hwnd, ::PTITLEBARINFO pti )
	{
		_WINQ_FCONTEXT( "CUser32::GetTitleBarInfo" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetTitleBarInfo );
		bResult = Call< BOOL, HWND, ::PTITLEBARINFO >( pFunc, hwnd, pti );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetTopWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::GetTopWindow" );
		HWND Result = 0;
		_WINQ_USESAPI( GetTopWindow );
		Result = Call< HWND, HWND >( pFunc, hWnd );
		if( Result == 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "GetTopWindow" ), 0 ));
			}
		}
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetWindow( HWND hWnd, UINT uCmd )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindow" );
		_WINQ_USESAPI( GetWindow );
		return Call< HWND, HWND, UINT >( pFunc, hWnd, uCmd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetWindowInfo( HWND hwnd, ::PWINDOWINFO pwi )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowInfo" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetWindowInfo );
		bResult = Call< BOOL, HWND, ::PWINDOWINFO >( pFunc, hwnd, pwi );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	UINT CUser32::GetWindowModuleFileName( HWND hwnd, LPTSTR lpszFileName, UINT cchFileNameMax )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowModuleFileName" );
		_WINQ_USESAPIAW( GetWindowModuleFileName );
		return Call< UINT, HWND, LPTSTR, UINT >( pFunc, hwnd, lpszFileName, cchFileNameMax );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetWindowPlacement( HWND hWnd, ::WINDOWPLACEMENT* lpwndpl )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowPlacement" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetWindowPlacement );
		bResult = Call< BOOL, HWND, ::WINDOWPLACEMENT* >( pFunc, hWnd, lpwndpl );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::GetWindowRect( HWND hWnd, ::LPRECT lpRect )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowRect" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( GetWindowRect );
		bResult = Call< BOOL, HWND, ::LPRECT >( pFunc, hWnd, lpRect );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::GetWindowText( HWND hWnd, LPTSTR lpString, int nMaxCount )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowText" );
		int iResult = 0;
		_WINQ_USESAPI( GetWindowText );
		iResult = Call< int, HWND, LPTSTR, int >( pFunc, hWnd, lpString, nMaxCount );
		if( iResult == 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "GetWindowText" ), 0 ));
			}
		}
		return iResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::GetWindowTextLength( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowTextLength" );
		int iResult = 0;
		_WINQ_USESAPI( GetWindowTextLength );
		iResult = Call< int, HWND >( pFunc, hWnd );
		if( iResult == 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "GetWindowTextLength" ), 0 ));
			}
		}
		return iResult;
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::GetWindowThreadProcessId( HWND hWnd, LPDWORD lpdwProcessId )
	{
		_WINQ_FCONTEXT( "CUser32::GetWindowThreadProcessId" );
		_WINQ_USESAPI( GetWindowThreadProcessId );
		return Call< DWORD, HWND, LPDWORD >( pFunc, hWnd, lpdwProcessId );
	}

	//--------------------------------------------------------------------------------
	int CUser32::InternalGetWindowText( HWND hWnd, LPWSTR lpString, int nMaxCount )
	{
		_WINQ_FCONTEXT( "CUser32::InternalGetWindowText" );
		int iResult = 0;
		_WINQ_USESAPI( InternalGetWindowText );
		iResult = Call< int, HWND, LPWSTR, int >( pFunc, hWnd, lpString, nMaxCount );
		if( iResult == 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "InternalGetWindowText" ), 0 ));
			}
		}
		return iResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsChild( HWND hWndParent, HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsChild" );
		_WINQ_USESAPI( IsChild );
		return Call< BOOL, HWND, HWND >( pFunc, hWndParent, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsGUIThread( BOOL bConvert )
	{
		_WINQ_FCONTEXT( "CUser32::IsGUIThread" );
		CCheckReturn< BOOL, CTCheckFailureValue< BOOL, ERROR_NOT_ENOUGH_MEMORY > >::TType bResult;
		_WINQ_USESAPI( IsGUIThread );
		bResult = Call< BOOL, BOOL >( pFunc, bConvert );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsHungAppWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsHungAppWindow" );
		_WINQ_USESAPI( IsHungAppWindow );
		return Call< BOOL, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsIconic( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsIconic" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( IsIconic );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsProcessDPIAware(void)
	{
		_WINQ_FCONTEXT( "CUser32::IsProcessDPIAware" );
		_WINQ_USESAPI( IsProcessDPIAware );
		return Call< BOOL >( pFunc );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsWindow" );
		_WINQ_USESAPI( IsWindow );
		return Call< BOOL, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsWindowUnicode( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsWindowUnicode" );
		_WINQ_USESAPI( IsWindowUnicode );
		return Call< BOOL, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsWindowVisible( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsWindowVisible" );
		_WINQ_USESAPI( IsWindowVisible );
		return Call< BOOL, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsZoomed( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::IsZoomed" );
		_WINQ_USESAPI( IsZoomed );
		return Call< BOOL, HWND >( pFunc, hWnd );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::LockSetForegroundWindow( UINT uLockCode )
	{
		_WINQ_FCONTEXT( "CUser32::LockSetForegroundWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( LockSetForegroundWindow );
		bResult = Call< BOOL, UINT >( pFunc, uLockCode );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CUser32::LogicalToPhysicalPoint( HWND hWnd, ::LPPOINT lpPoint )
	{
		_WINQ_FCONTEXT( "CUser32::LogicalToPhysicalPoint" );
		_WINQ_USESAPI( LogicalToPhysicalPoint );
		voidCall< HWND, ::LPPOINT >( pFunc, hWnd, lpPoint );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::MoveWindow( HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint )
	{
		_WINQ_FCONTEXT( "CUser32::MoveWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( MoveWindow );
		bResult = Call< BOOL, HWND, int, int, int, int, BOOL >( pFunc, hWnd, X, Y, nWidth, nHeight, bRepaint );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::OpenIcon( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::OpenIcon" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( OpenIcon );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CUser32::PhysicalToLogicalPoint( HWND hWnd, ::LPPOINT lpPoint )
	{
		_WINQ_FCONTEXT( "CUser32::PhysicalToLogicalPoint" );	
		_WINQ_USESAPI( PhysicalToLogicalPoint );
		voidCall< HWND, ::LPPOINT >( pFunc, hWnd, lpPoint );
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::RealChildWindowFromPoint( HWND hwndParent, ::POINT ptParentClientCoords )
	{
		_WINQ_FCONTEXT( "CUser32::RealChildWindowFromPoint" );
		_WINQ_USESAPI( RealChildWindowFromPoint );
		return Call< HWND, HWND, ::POINT >( pFunc, hwndParent, ptParentClientCoords );
	}

	//--------------------------------------------------------------------------------
	UINT CUser32::RealGetWindowClass( HWND hwnd, LPTSTR pszType, UINT cchType )
	{
		_WINQ_FCONTEXT( "CUser32::RealGetWindowClass" );
		CCheckReturn< UINT, CCheckNonZero< UINT > >::TType uiResult;
		_WINQ_USESAPI( RealGetWindowClass );
		uiResult = Call< UINT, HWND, LPTSTR, UINT >( pFunc, hwnd, pszType, cchType );
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::RegisterShellHookWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::RegisterShellHookWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( RegisterShellHookWindow );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetForegroundWindow( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CUser32::SetForegroundWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetForegroundWindow );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetLayeredWindowAttributes( HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::SetLayeredWindowAttributes" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetLayeredWindowAttributes );
		bResult = Call< BOOL, HWND, COLORREF, BYTE, DWORD >( pFunc, hwnd, crKey, bAlpha, dwFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::SetParent( HWND hWndChild, HWND hWndNewParent )
	{
		_WINQ_FCONTEXT( "CUser32::SetParent" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( SetParent );
		Result = Call< HWND, HWND, HWND >( pFunc, hWndChild, hWndNewParent );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetProcessDefaultLayout( DWORD dwDefaultLayout )
	{
		_WINQ_FCONTEXT( "CUser32::SetProcessDefaultLayout" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetProcessDefaultLayout );
		bResult = Call< BOOL, DWORD >( pFunc, dwDefaultLayout );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetProcessDPIAware(void)
	{
		_WINQ_FCONTEXT( "CUser32::SetProcessDPIAware" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetProcessDPIAware );
		bResult = Call< BOOL >( pFunc );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetWindowPlacement( HWND hWnd, ::WINDOWPLACEMENT* lpwndpl )
	{
		_WINQ_FCONTEXT( "CUser32::SetWindowPlacement" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetWindowPlacement );
		bResult = Call< BOOL, HWND, ::WINDOWPLACEMENT* >( pFunc, hWnd, lpwndpl );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetWindowPos( HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags )
	{
		_WINQ_FCONTEXT( "CUser32::SetWindowPos" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetWindowPos );
		bResult = Call< BOOL, HWND, HWND, int, int, int ,int, UINT >( pFunc, hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetWindowText( HWND hWnd, LPCTSTR lpString )
	{
		_WINQ_FCONTEXT( "CUser32::SetWindowText" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetWindowText );
		bResult = Call< BOOL, HWND, LPCTSTR >( pFunc, hWnd, lpString );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::ShowOwnedPopups( HWND hWnd, BOOL fShow )
	{
		_WINQ_FCONTEXT( "CUser32::ShowOwnedPopups" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( ShowOwnedPopups );
		bResult = Call< BOOL, HWND, BOOL >( pFunc, hWnd, fShow );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::ShowWindow( HWND hWnd, int nCmdShow )
	{
		_WINQ_FCONTEXT( "CUser32::ShowWindow" );
		_WINQ_USESAPI( ShowWindow );
		return Call< BOOL, HWND, int >( pFunc, hWnd, nCmdShow );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::ShowWindowAsync( HWND hWnd, int nCmdShow )
	{
		_WINQ_FCONTEXT( "CUser32::ShowWindowAsync" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( ShowWindowAsync );
		bResult = Call< BOOL, HWND, int >( pFunc, hWnd, nCmdShow );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SoundSentry(void)
	{
		_WINQ_FCONTEXT( "CUser32::SoundSentry" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SoundSentry );
		bResult = Call< BOOL >( pFunc );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CUser32::SwitchToThisWindow( HWND hWnd, BOOL fAltTab )
	{
		_WINQ_FCONTEXT( "CUser32::SwitchToThisWindow" );
		_WINQ_USESAPI( SwitchToThisWindow );
		voidCall< HWND, BOOL >( pFunc, hWnd, fAltTab );
	}

	//--------------------------------------------------------------------------------
	WORD CUser32::TileWindows( HWND hwndParent, UINT wHow, ::RECT* lpRect, UINT cKids, const HWND* lpKids )
	{
		_WINQ_FCONTEXT( "CUser32::TileWindows" );
		CCheckReturn< WORD, CCheckNonZero< WORD > >::TType wResult;
		_WINQ_USESAPI( TileWindows );
		wResult = Call< WORD, HWND, UINT, ::RECT*, UINT, const HWND* >( pFunc, hwndParent, wHow, lpRect, cKids, lpKids );
		return wResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::UpdateLayeredWindow( HWND hwnd, HDC hdcDst, ::POINT* pptDst, ::SIZE* psize, HDC hdcSrc, ::POINT* pptSrc, COLORREF crKey, ::BLENDFUNCTION* pblend, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::UpdateLayeredWindow" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( UpdateLayeredWindow );
		bResult = Call< BOOL, HWND, HDC, ::POINT*, ::SIZE*, HDC, ::POINT*, COLORREF, ::BLENDFUNCTION*, DWORD >( pFunc, hwnd, hdcDst, pptDst, psize, hdcSrc, pptSrc, crKey, pblend, dwFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::UpdateLayeredWindowIndirect( HWND hwnd, const ::UPDATELAYEREDWINDOWINFO* pULWInfo )
	{
		_WINQ_FCONTEXT( "CUser32::UpdateLayeredWindowIndirect" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( UpdateLayeredWindowIndirect );
		bResult = Call< BOOL, HWND, const ::UPDATELAYEREDWINDOWINFO* >( pFunc, hwnd, pULWInfo );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::WindowFromPhysicalPoint( ::POINT Point )
	{
		_WINQ_FCONTEXT( "CUser32::WindowFromPhysicalPoint" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( WindowFromPysicalPoint );
		Result = Call< HWND, ::POINT >( pFunc, Point );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::WindowFromPoint( ::POINT Point )
	{
		_WINQ_FCONTEXT( "CUser32::WindowFromPoint" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( WindowFromPoint );
		Result = Call< HWND, ::POINT >( pFunc, Point );
		return Result;
	}

}//nsWinQAPI

