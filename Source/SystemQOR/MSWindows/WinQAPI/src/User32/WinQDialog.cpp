//WinQDialog.cpp

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

//Dialog functions

#include "WinQAPI/User32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	HWND CUser32::CreateDialogIndirectParam( HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, ::DLGPROC lpDialogFunc, LPARAM lParamInit )
	{
		_WINQ_FCONTEXT( "CUser32::CreateDialogIndirectParam" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( CreateDialogIndirectParam );
		Result = Call< HWND, HINSTANCE, LPCDLGTEMPLATE, HWND, ::DLGPROC, LPARAM >( pFunc, hInstance, lpTemplate, hWndParent, lpDialogFunc, lParamInit );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::CreateDialogParamA( HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, ::DLGPROC lpDialogFunc, LPARAM dwInitParam )
	{
		_WINQ_FCONTEXT( "CUser32::CreateDialogParamA" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPIAW( CreateDialogParamA );
		Result = Call< HWND, HINSTANCE, LPCSTR, HWND, ::DLGPROC, LPARAM >( pFunc, hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::CreateDialogParamW( HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, ::DLGPROC lpDialogFunc, LPARAM dwInitParam )
	{
		_WINQ_FCONTEXT( "CUser32::CreateDialogParamW" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPIAW( CreateDialogParamW );
		Result = Call< HWND, HINSTANCE, LPCWSTR, HWND, ::DLGPROC, LPARAM >( pFunc, hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam );
		return Result;
	}

	//--------------------------------------------------------------------------------
	LRESULT CUser32::DefDlgProc( HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam )
	{
		_WINQ_FCONTEXT( "CUser32::DefDlgProc" );
		_WINQ_USESAPIAW( DefDlgProc );
		return Call< LRESULT, HWND, UINT, WPARAM, LPARAM >( pFunc, hDlg, Msg, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	INT_PTR CUser32::DialogBoxIndirectParam( HINSTANCE hInstance, LPCDLGTEMPLATE hDialogTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam )
	{
		_WINQ_FCONTEXT( "CUser32::DialogBoxIndirectParam" );
		INT_PTR Result = 0;
		_WINQ_USESAPI( DialogBoxIndirectParam );
		Result = Call< INT_PTR, HINSTANCE, LPCDLGTEMPLATE, HWND, DLGPROC, LPARAM >( pFunc, hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam );
		if( Result <= 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "DialogBoxIndirectParam" ), 0 ));
			}
		}
		return Result;
	}

	//--------------------------------------------------------------------------------
	INT_PTR CUser32::DialogBoxParam( HINSTANCE hInstance, LPCTSTR lpTemplateName, HWND hWndParent, ::DLGPROC lpDialogFunc, LPARAM dwInitParam )
	{
		_WINQ_FCONTEXT( "CUser32::DialogBoxParam" );
		INT_PTR Result = 0;
		_WINQ_USESAPI( DialogBoxParam );
		Result = Call< INT_PTR, HINSTANCE, LPCTSTR, HWND, ::DLGPROC, LPARAM >( pFunc, hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam );
		if( Result <= 0 )
		{
			DWORD dwError = CKernel32::GetLastError();
			if( dwError != ERROR_SUCCESS )
			{
				__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "DialogBoxParam" ), 0 ));
			}
		}
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::EndDialog( HWND hDlg, INT_PTR nResult )
	{
		_WINQ_FCONTEXT( "CUser32::EndDialog" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( EndDialog );
		bResult = Call< BOOL, HWND, INT_PTR >( pFunc, hDlg, nResult );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	LONG CUser32::GetDialogBaseUnits(void)
	{
		_WINQ_FCONTEXT( "CUser32::GetDialogBaseUnits" );
		_WINQ_USESAPI( GetDialogBaseUnits );
		return Call< LONG >( pFunc );
	}

	//--------------------------------------------------------------------------------
	int CUser32::GetDlgCtrlID( HWND hwndCtl )
	{
		_WINQ_FCONTEXT( "CUser32::GetDlgCtrlID" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult;
		_WINQ_USESAPI( GetDlgCtrlID );
		iResult = Call< int, HWND >( pFunc, hwndCtl );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetDlgItem( HWND hDlg, int nIDDlgItem )
	{
		_WINQ_FCONTEXT( "CUser32::GetDlgItem" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( GetDlgItem );
		Result = Call< HWND, HWND, int >( pFunc, hDlg, nIDDlgItem );
		return Result;
	}

	//--------------------------------------------------------------------------------
	UINT CUser32::GetDlgItemInt( HWND hDlg, int nIDDlgItem, BOOL* lpTranslated, BOOL bSigned )
	{
		_WINQ_FCONTEXT( "CUser32::GetDlgItemInt" );
		UINT uiResult = 0;
		_WINQ_USESAPI( GetDlgItemInt );
		uiResult = Call< UINT, HWND, int, BOOL*, BOOL >( pFunc, hDlg, nIDDlgItem, lpTranslated, bSigned );
		if( lpTranslated != 0 && *lpTranslated == 0 )
		{
			__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "GetDlgItemInt" ), 0 ));
		}
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	UINT CUser32::GetDlgItemText( HWND hDlg, int nIDDlgItem, LPTSTR lpString, int nMaxCount )
	{
		_WINQ_FCONTEXT( "CUser32::GetDlgItemText" );
		CCheckReturn< UINT, CCheckNonZero< UINT > >::TType uiResult;
		_WINQ_USESAPI( GetDlgItemText );
		uiResult = Call< UINT, HWND, int, LPTSTR, int >( pFunc, hDlg, nIDDlgItem, lpString, nMaxCount );
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetNextDlgGroupItem( HWND hDlg, HWND hCtl, BOOL bPrevious )
	{
		_WINQ_FCONTEXT( "CUser32::GetNextDlgGroupItem" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( GetNextDlgGroupItem );
		Result = Call< HWND, HWND, HWND, BOOL >( pFunc, hDlg, hCtl, bPrevious );
		return Result;
	}

	//--------------------------------------------------------------------------------
	HWND CUser32::GetNextDlgTabItem( HWND hDlg, HWND hCtl, BOOL bPrevious )
	{
		_WINQ_FCONTEXT( "CUser32::GetNextDlgTabItem" );
		CCheckReturn< HWND, CCheckNonZero< HWND > >::TType Result;
		_WINQ_USESAPI( GetNextDlgTabItem );
		Result = Call< HWND, HWND, HWND, BOOL >( pFunc, hDlg, hCtl, bPrevious );
		return Result;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsDialogMessage( HWND hDlg, LPMSG lpMsg )
	{
		_WINQ_FCONTEXT( "CUser32::IsDialogMessage" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPIAW( IsDialogMessage );
		bResult = Call< BOOL, HWND, LPMSG >( pFunc, hDlg, lpMsg );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::MapDialogRect( HWND hDlg, LPRECT lpRect )
	{
		_WINQ_FCONTEXT( "CUser32::MapDialogRect" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( MapDialogRect );
		bResult = Call< BOOL, HWND, LPRECT >( pFunc, hDlg, lpRect );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::MessageBox( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType )
	{
		_WINQ_FCONTEXT( "CUser32::MessageBox" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult;
		_WINQ_USESAPIAW( MessageBox );
		iResult = Call< int, HWND, LPCTSTR, LPCTSTR, UINT >( pFunc, hWnd, lpText, lpCaption, uType );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::MessageBoxEx( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, WORD wLanguageId )
	{
		_WINQ_FCONTEXT( "CUser32::MessageBoxEx" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult = 0;
		_WINQ_USESAPIAW( MessageBoxEx );
		iResult = Call< int, HWND, LPCTSTR, LPCTSTR, UINT, WORD >( pFunc, hWnd, lpText, lpCaption, uType, wLanguageId );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::MessageBoxIndirect( const ::LPMSGBOXPARAMS lpMsgBoxParams )
	{
		_WINQ_FCONTEXT( "CUser32::MessageBoxIndirect" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult = 0;
		_WINQ_USESAPIAW( MessageBoxIndirect );
		iResult = Call< int, const ::LPMSGBOXPARAMS >( pFunc, lpMsgBoxParams );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	//NOTE: Thanks to CPian Maurizio Pisano
	int CUser32::MessageBoxTimeout( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, WORD wLanguageId, DWORD dwMilliseconds )
	{
		_WINQ_FCONTEXT( "CUser32::MessageBoxTimeout" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult;
		_WINQ_USESAPIAW( MessageBoxTimeout );
		iResult = Call< int, HWND, LPCTSTR, LPCTSTR, UINT, WORD, DWORD >( pFunc, hWnd, lpText, lpCaption, uType, wLanguageId, dwMilliseconds );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	LRESULT CUser32::SendDlgItemMessage( HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam )
	{
		_WINQ_FCONTEXT( "CUser32::SendDlgItemMessage" );
		_WINQ_USESAPIAW( SendDlgItemMessage );
		return Call< LRESULT, HWND, int, UINT, WPARAM, LPARAM >( pFunc, hDlg, nIDDlgItem, Msg, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetDlgItemInt( HWND hDlg, int nIDDlgItem, UINT uValue, BOOL bSigned )
	{
		_WINQ_FCONTEXT( "CUser32::SetDlgItemInt" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( SetDlgItemInt );
		bResult = Call< BOOL, HWND, int, UINT, BOOL >( pFunc, hDlg, nIDDlgItem, uValue, bSigned );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::SetDlgItemText( HWND hDlg, int nIDDlgItem, LPCTSTR lpString )
	{
		_WINQ_FCONTEXT( "CUser32::SetDlgItemText" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPIAW( SetDlgItemText );
		bResult = Call< BOOL, HWND, int, LPCTSTR >( pFunc, hDlg, nIDDlgItem, lpString );
		return bResult;
	}

}//nsWinQAPI

