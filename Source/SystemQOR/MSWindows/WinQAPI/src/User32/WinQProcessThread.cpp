//WinQProcessThread.cpp

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

//Process and Thread functions

#include "WinQAPI/User32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	BOOL CUser32::AttachThreadInput( DWORD idAttach, DWORD idAttachTo, BOOL fAttach )
	{
		_WINQ_FCONTEXT( "CUser32::AttachThreadInput" );
		BOOL bResult = FALSE;
		_WINQ_USESAPI( AttachThreadInput );
		bResult = Call< BOOL, DWORD, DWORD, BOOL>( pFunc, idAttach, idAttachTo, fAttach );
		if( bResult == 0 )
		{
#	if( _WIN32_WINNT >= 0x0600 )
			__WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _T( "UnhookWindowsHookEx" ), 0 ));
#	else
			__WINQAPI_CONT_ERROR(( API_FAILED, _T( "UnhookWindowsHookEx" ), E_FAIL, 0 ));;
#	endif
			
		}
		return bResult;
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::GetGuiResources( HANDLE hProcess, DWORD uiFlags )
	{
		_WINQ_FCONTEXT( "CUser32::GetGuiResources" );
		CCheckReturn< DWORD, CCheckNonZero< DWORD > >::TType dwResult;
		_WINQ_USESAPI( GetGuiResources );
		dwResult = Call< DWORD, HANDLE, DWORD >( pFunc, hProcess, uiFlags );
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsWow64Message(void)
	{
		_WINQ_FCONTEXT( "CUser32::IsWow64Message" );
		_WINQ_USESAPI( IsWow64Message );	
		return Call< BOOL >( pFunc );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::UserHandleGrantAccess( HANDLE hUserHandle, HANDLE hJob, BOOL bGrant )
	{
		_WINQ_FCONTEXT( "CUser32::UserHandleGrantAccess" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( UserHandleGrantAccess );	
		bResult = Call< BOOL, HANDLE, HANDLE, BOOL >( pFunc, hUserHandle, hJob, bGrant );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::WaitForInputIdle( HANDLE hProcess, DWORD dwMilliseconds )
	{
		_WINQ_FCONTEXT( "CUser32::WaitForInputIdle" );
		CCheckReturn< DWORD, CTCheckFailureValue< DWORD, WAIT_FAILED > >::TType dwResult;
		_WINQ_USESAPI( WaitForInputIdle );
		dwResult = Call< DWORD, HANDLE, DWORD > ( pFunc, hProcess, dwMilliseconds );
		return dwResult;
	}

}//nsWinQAPI
