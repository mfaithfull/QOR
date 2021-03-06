//kAppRecRestart.cpp

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

#include "WinQAPI/Kernel32.h"
#include "ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	VOID CKernel32::ApplicationRecoveryFinished( BOOL bSuccess )
	{
		_WINQ_SFCONTEXT( "CKernel32::ApplicationRecoveryFinished" );
		::ApplicationRecoveryFinished( bSuccess );
	}

	//--------------------------------------------------------------------------------
	HRESULT CKernel32::ApplicationRecoveryInProgress( PBOOL pbCanceled )
	{
		_WINQ_SFCONTEXT( "CKernel32::ApplicationRecoveryInProgress" );
		HRESULT hr = ::ApplicationRecoveryInProgress( pbCanceled );
		if( hr != S_OK )
		{
			__QOR_CODESTRING( APIName, "ApplicationRecoveryInProgress" );
			switch ( hr )
			{
			case E_FAIL:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "You can call this function only after Windows Error Reporting has called your recovery callback function." ), 0 ));
				break;
			case E_INVALIDARG:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "The parameter 'pbCancelled' cannot be NULL." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
		return hr;
	}


	//--------------------------------------------------------------------------------
	HRESULT CKernel32::GetApplicationRecoveryCallback( HANDLE hProcess, APPLICATION_RECOVERY_CALLBACK* pRecoveryCallback, PVOID* ppvParameter, PDWORD dwPingInterval, PDWORD dwFlags )
	{
		_WINQ_SFCONTEXT( "CKernel32::GetApplicationRecoveryCallback" );
		HRESULT hr = ::GetApplicationRecoveryCallback( hProcess, pRecoveryCallback, ppvParameter, dwPingInterval, dwFlags );
		if( hr != S_OK )
		{
			__QOR_CODESTRING( APIName, "GetApplicationRecoveryCallback" );
			switch ( hr )
			{
			case S_FALSE:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "The application did not register for recovery." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
		return hr;
	}

	//--------------------------------------------------------------------------------
	HRESULT CKernel32::GetApplicationRestartSettings( HANDLE hProcess, PWSTR pwzCommandline, PDWORD pcchSize, PDWORD pdwFlags )
	{
		_WINQ_SFCONTEXT( "CKernel32::GetApplicationRestartSettings" );
		HRESULT hr = ::GetApplicationRestartSettings( hProcess, pwzCommandline, pcchSize, pdwFlags );
		if( hr != S_OK )
		{
			__QOR_CODESTRING( APIName, "GetApplicationRestartSettings" );
			switch ( hr )
			{
				
			case ( ( ERROR_NOT_FOUND & 0x0000FFFF ) | ( FACILITY_WIN32 << 16 ) | 0x80000000 ):
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "The application did not register for restart." ), 0 ));
				break;
			case ( ( ERROR_INSUFFICIENT_BUFFER & 0x0000FFFF ) | ( FACILITY_WIN32 << 16 ) | 0x80000000 ):
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "The pwzCommandLine buffer is too small. The function returns the required buffer size in pcchSize. Use the required size to reallocate the buffer." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
		return hr;
	}

	//--------------------------------------------------------------------------------
	HRESULT CKernel32::RegisterApplicationRecoveryCallback( APPLICATION_RECOVERY_CALLBACK pRecoveryCallback, PVOID pvParameter, DWORD dwPingInterval, DWORD dwFlags )
	{
		_WINQ_SFCONTEXT( "CKernel32::RegisterApplicationRecoveryCallback" );
		HRESULT hr = E_NOTIMPL;
		__QOR_CODESTRING( APIName, "RegisterApplicationRecoveryCallback" );
#	if ( _WIN32_WINNT >= 0x0600 )
		hr = ::RegisterApplicationRecoveryCallback( pRecoveryCallback, pvParameter, dwPingInterval, dwFlags );
		if( hr != S_OK )
		{
			switch ( hr )
			{
			case E_FAIL:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "Internal error; the registration failed." ), 0 ));
				break;
			case E_INVALIDARG:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "The ping interval cannot be more than five minutes." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
#	else
		__QCMP_UNREF( dwFlags );
		__QCMP_UNREF( dwPingInterval );
		__QCMP_UNREF( pvParameter );
		__QCMP_UNREF( pRecoveryCallback );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, APIName.c_str(), _T( "Windows Vista" ), 0 ));
#	endif
		return hr;
	}

	//--------------------------------------------------------------------------------
	HRESULT CKernel32::RegisterApplicationRestart( PCWSTR pwzCommandline, DWORD dwFlags )
	{
		_WINQ_SFCONTEXT( "CKernel32::RegisterApplicationRestart" );
		HRESULT hr = E_NOTIMPL;
		__QOR_CODESTRING( APIName, "RegisterApplicationRestart" );
#	if ( _WIN32_WINNT >= 0x0600 )
		hr = ::RegisterApplicationRestart( pwzCommandline, dwFlags );
		if( hr != S_OK )
		{
			switch ( hr )
			{
			case E_FAIL:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "Internal error." ), 0 ));
				break;
			case E_INVALIDARG:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "The specified command line is too long." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
#	else
		__QCMP_UNREF( dwFlags );
		__QCMP_UNREF( pwzCommandline );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, APIName.c_str(), _T( "Windows Vista" ), 0 ));
#	endif
		return hr;
	}		

	//--------------------------------------------------------------------------------
	HRESULT CKernel32::UnregisterApplicationRecoveryCallback(void)
	{
		_WINQ_SFCONTEXT( "CKernel32::UnregisterApplicationRecoveryCallback" );
		HRESULT hr = E_NOTIMPL;
		__QOR_CODESTRING( APIName, "UnregisterApplicationRecoveryCallback" );
#	if ( _WIN32_WINNT >= 0x0600 )
		hr = ::UnregisterApplicationRecoveryCallback();
		if( hr != S_OK )
		{
			switch ( hr )
			{
			case E_FAIL:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "Internal error." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
#	else
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, APIName.c_str(), _T( "Windows Vista" ), 0 ));
#	endif
		return hr;
	}

	//--------------------------------------------------------------------------------
	HRESULT CKernel32::UnregisterApplicationRestart(void)
	{
		_WINQ_SFCONTEXT( "CKernel32::UnregisterApplicationRestart" );
		HRESULT hr = E_NOTIMPL;
		__QOR_CODESTRING( APIName, "UnregisterApplicationRestart" );
#	if ( _WIN32_WINNT >= 0x0600 )
		hr = ::UnregisterApplicationRestart();
		if( hr != S_OK )
		{
			switch ( hr )
			{
			case E_FAIL:
				__WINQAPI_CONT_ERROR(( APP_RECOVERY_API_ERROR, APIName.c_str(), _T( "Internal error." ), 0 ));
				break;
			default:
				__WINQAPI_CONT_ERROR(( API_FAILED, APIName.c_str(), hr, 0 ));
				break;
			}
		}
#	else
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, APIName.c_str(), _T( "Windows Vista" ), 0 ));
#	endif
		return hr;
	}

}//nsWinQAPI

