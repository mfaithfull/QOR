//Services.cpp

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

#include "WinQAPI/AdvAPI32.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//Service functions
	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::CloseServiceHandle( SC_HANDLE hSCObject )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CloseServiceHandle" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( CloseServiceHandle );
		bResult = Call< BOOL, SC_HANDLE >( pFunc, hSCObject );
#else
		QOR_PP_UNREF( hSCObject );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "CloseServiceHandle" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::ChangeServiceConfig2A( SC_HANDLE hService, DWORD dwInfoLevel, LPVOID lpInfo )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::ChangeServiceConfig2A" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( ChangeServiceConfig2A );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPVOID >( pFunc, hService, dwInfoLevel, lpInfo );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( dwInfoLevel );
		QOR_PP_UNREF( lpInfo );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "ChangeServiceConfig2A" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::ChangeServiceConfig2W( SC_HANDLE hService, DWORD dwInfoLevel, LPVOID lpInfo )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::ChangeServiceConfig2W" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( ChangeServiceConfig2W );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPVOID >( pFunc, hService, dwInfoLevel, lpInfo );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( dwInfoLevel );
		QOR_PP_UNREF( lpInfo );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "ChangeServiceConfig2W" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::ChangeServiceConfigA( SC_HANDLE hService, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCSTR lpBinaryPathName, LPCSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCSTR lpDependencies, LPCSTR lpServiceStartName, LPCSTR lpPassword, LPCSTR lpDisplayName )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::ChangeServiceConfigA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( ChangeServiceConfigA );
		bResult = Call< BOOL, SC_HANDLE, DWORD, DWORD, DWORD, LPCSTR, LPCSTR, LPDWORD, LPCSTR, LPCSTR, LPCSTR, LPCSTR >( pFunc, hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName );
#else
		__QCMP_UNREF4( hService, dwServiceType, dwStartType, dwErrorControl );
		__QCMP_UNREF4( lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies );
		QOR_PP_UNREF( lpServiceStartName );
		QOR_PP_UNREF( lpPassword );
		QOR_PP_UNREF( lpDisplayName );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "ChangeServiceConfigA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::ChangeServiceConfigW( SC_HANDLE hService, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCWSTR lpBinaryPathName, LPCWSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCWSTR lpDependencies, LPCWSTR lpServiceStartName, LPCWSTR lpPassword, LPCWSTR lpDisplayName )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::ChangeServiceConfigW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( ChangeServiceConfigW );
		bResult = Call< BOOL, SC_HANDLE, DWORD, DWORD, DWORD, LPCWSTR, LPCWSTR, LPDWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR >( pFunc, hService, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword, lpDisplayName );
#else
		__QCMP_UNREF4( hService, dwServiceType, dwStartType, dwErrorControl );
		__QCMP_UNREF4( lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies );
		QOR_PP_UNREF( lpServiceStartName );
		QOR_PP_UNREF( lpPassword );
		QOR_PP_UNREF( lpDisplayName );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "ChangeServiceConfigW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::ControlService( SC_HANDLE hService, DWORD dwControl, LPSERVICE_STATUS lpServiceStatus )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::ControlService" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( ControlService );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPSERVICE_STATUS >( pFunc, hService, dwControl, lpServiceStatus );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( dwControl );
		QOR_PP_UNREF( lpServiceStatus );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "ControlService" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	SC_HANDLE CAdvAPI32::CreateServiceA( SC_HANDLE hSCManager, LPCSTR lpServiceName, LPCSTR lpDisplayName, DWORD dwDesiredAccess, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCSTR lpBinaryPathName, LPCSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCSTR lpDependencies, LPCSTR lpServiceStartName, LPCSTR lpPassword )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CreateServiceA" );
		CCheckReturn< SC_HANDLE, CCheckNonZero< SC_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( CreateServiceA );
		Result = Call< SC_HANDLE, SC_HANDLE, LPCSTR, LPCSTR, DWORD, DWORD, DWORD, DWORD, LPCSTR, LPCSTR, LPDWORD, LPCSTR, LPCSTR, LPCSTR >( pFunc, hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword );
#else
		__QCMP_UNREF4( hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess );
		__QCMP_UNREF4( dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName );
		__QCMP_UNREF4( lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName );
		QOR_PP_UNREF( lpPassword );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "CreateServiceA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SC_HANDLE CAdvAPI32::CreateServiceW( SC_HANDLE hSCManager, LPCWSTR lpServiceName, LPCWSTR lpDisplayName, DWORD dwDesiredAccess, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCWSTR lpBinaryPathName, LPCWSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCWSTR lpDependencies, LPCWSTR lpServiceStartName, LPCWSTR lpPassword )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CreateServiceW" );
		CCheckReturn< SC_HANDLE, CCheckNonZero< SC_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( CreateServiceW );
		Result = Call< SC_HANDLE, SC_HANDLE, LPCWSTR, LPCWSTR, DWORD, DWORD, DWORD, DWORD, LPCWSTR, LPCWSTR, LPDWORD, LPCWSTR, LPCWSTR, LPCWSTR >( pFunc, hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess, dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName, lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName, lpPassword );
#else
		__QCMP_UNREF4( hSCManager, lpServiceName, lpDisplayName, dwDesiredAccess );
		__QCMP_UNREF4( dwServiceType, dwStartType, dwErrorControl, lpBinaryPathName );
		__QCMP_UNREF4( lpLoadOrderGroup, lpdwTagId, lpDependencies, lpServiceStartName );
		QOR_PP_UNREF( lpPassword );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "CreateServiceW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::DeleteService( SC_HANDLE hService )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::DeleteService" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( DeleteService );
		bResult = Call< BOOL, SC_HANDLE >( pFunc, hService );
#else
		QOR_PP_UNREF( hService );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "DeleteService" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::EnumDependentServicesA( SC_HANDLE hService, DWORD dwServiceState, LPENUM_SERVICE_STATUS lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::EnumDependentServicesA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( EnumDependentServicesA );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPENUM_SERVICE_STATUS, DWORD, LPDWORD, LPDWORD >( pFunc, hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned );
#else
		__QCMP_UNREF4( hService, dwServiceState, lpServices, cbBufSize );
		QOR_PP_UNREF( pcbBytesNeeded );
		QOR_PP_UNREF( lpServicesReturned );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "EnumDependentServicesA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::EnumDependentServicesW( SC_HANDLE hService, DWORD dwServiceState, LPENUM_SERVICE_STATUS lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::EnumDependentServicesW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( EnumDependentServicesW );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPENUM_SERVICE_STATUS, DWORD, LPDWORD, LPDWORD >( pFunc, hService, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned );
#else
		__QCMP_UNREF4( hService, dwServiceState, lpServices, cbBufSize );
		QOR_PP_UNREF( pcbBytesNeeded );
		QOR_PP_UNREF( lpServicesReturned );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "EnumDependentServicesW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::EnumServicesStatusA( SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUS lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::EnumServicesStatusA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( EnumServicesStatusA );
		bResult = Call< BOOL, SC_HANDLE, DWORD, DWORD, LPENUM_SERVICE_STATUS, DWORD, LPDWORD, LPDWORD, LPDWORD >( pFunc, hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle );
#else
		__QCMP_UNREF4( hSCManager, dwServiceType, dwServiceState, lpServices );
		__QCMP_UNREF4( cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "EnumServicesStatusA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::EnumServicesStatusW( SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUS lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::EnumServicesStatusW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( EnumServicesStatusW );
		bResult = Call< BOOL, SC_HANDLE, DWORD, DWORD, LPENUM_SERVICE_STATUS, DWORD, LPDWORD, LPDWORD, LPDWORD >( pFunc, hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle );
#else
		__QCMP_UNREF4( hSCManager, dwServiceType, dwServiceState, lpServices );
		__QCMP_UNREF4( cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "EnumServicesStatusW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::EnumServicesStatusExA( SC_HANDLE hSCManager, SC_ENUM_TYPE InfoLevel, DWORD dwServiceType, DWORD dwServiceState, LPBYTE lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle, LPCSTR pszGroupName )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::EnumServicesStatusExA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( EnumServicesStatusExA );
		bResult = Call< BOOL, SC_HANDLE, SC_ENUM_TYPE, DWORD, DWORD, LPBYTE, DWORD, LPDWORD, LPDWORD, LPDWORD, LPCSTR >( pFunc, hSCManager, InfoLevel, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle, pszGroupName );
#else
		__QCMP_UNREF4( hSCManager, InfoLevel, dwServiceType, dwServiceState );
		__QCMP_UNREF4( lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned );
		QOR_PP_UNREF( lpResumeHandle );
		QOR_PP_UNREF( pszGroupName );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "EnumServicesStatusExA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::EnumServicesStatusExW( SC_HANDLE hSCManager, SC_ENUM_TYPE InfoLevel, DWORD dwServiceType, DWORD dwServiceState, LPBYTE lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle, LPCWSTR pszGroupName )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::EnumServicesStatusExW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( EnumServicesStatusExW );
		bResult = Call< BOOL, SC_HANDLE, SC_ENUM_TYPE, DWORD, DWORD, LPBYTE, DWORD, LPDWORD, LPDWORD, LPDWORD, LPCWSTR >( pFunc, hSCManager, InfoLevel, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle, pszGroupName );
#else
		__QCMP_UNREF4( hSCManager, InfoLevel, dwServiceType, dwServiceState );
		__QCMP_UNREF4( lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned );
		QOR_PP_UNREF( lpResumeHandle );
		QOR_PP_UNREF( pszGroupName );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "EnumServicesStatusExW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::GetServiceDisplayNameA( SC_HANDLE hSCManager, LPCSTR lpServiceName, LPSTR lpDisplayName, LPDWORD lpcchBuffer )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::GetServiceDisplayNameA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( GetServiceDisplayNameA );
		bResult = Call< BOOL, SC_HANDLE, LPCSTR, LPSTR, LPDWORD >( pFunc, hSCManager, lpServiceName, lpDisplayName, lpcchBuffer );
#else
		__QCMP_UNREF4( hSCManager, lpServiceName, lpDisplayName, lpcchBuffer );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "GetServiceDisplayNameA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::GetServiceDisplayNameW( SC_HANDLE hSCManager, LPCWSTR lpServiceName, LPWSTR lpDisplayName, LPDWORD lpcchBuffer )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::GetServiceDisplayNameW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( GetServiceDisplayNameW );
		bResult = Call< BOOL, SC_HANDLE, LPCWSTR, LPWSTR, LPDWORD >( pFunc, hSCManager, lpServiceName, lpDisplayName, lpcchBuffer );
#else
		__QCMP_UNREF4( hSCManager, lpServiceName, lpDisplayName, lpcchBuffer );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "GetServiceDisplayNameW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::GetServiceKeyNameA( SC_HANDLE hSCManager, LPCSTR lpDisplayName, LPSTR lpServiceName, LPDWORD lpcchBuffer )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::GetServiceKeyNameA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( GetServiceKeyNameA );
		bResult = Call< BOOL, SC_HANDLE, LPCSTR, LPSTR, LPDWORD >( pFunc, hSCManager, lpDisplayName, lpServiceName, lpcchBuffer );
#else
		__QCMP_UNREF4( hSCManager, lpDisplayName, lpServiceName, lpcchBuffer );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "GetServiceKeyNameA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::GetServiceKeyNameW( SC_HANDLE hSCManager, LPCWSTR lpDisplayName, LPWSTR lpServiceName, LPDWORD lpcchBuffer )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::GetServiceKeyNameW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( GetServiceKeyNameW );
		bResult = Call< BOOL, SC_HANDLE, LPCWSTR, LPWSTR, LPDWORD >( pFunc, hSCManager, lpDisplayName, lpServiceName, lpcchBuffer );
#else
		__QCMP_UNREF4( hSCManager, lpDisplayName, lpServiceName, lpcchBuffer );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "GetServiceKeyNameW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	SC_LOCK CAdvAPI32::LockServiceDatabase( SC_HANDLE hSCManager )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::LockServiceDatabase" );
		CCheckReturn< SC_LOCK, CCheckNonZero< SC_LOCK > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( LockServiceDatabase );
		Result = Call< SC_LOCK, SC_HANDLE >( pFunc, hSCManager );
#else
		QOR_PP_UNREF( hSCManager );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "LockServiceDatabase" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	DWORD CAdvAPI32::NotifyServiceStatusChange( SC_HANDLE hService, DWORD dwNotifyMask, PSERVICE_NOTIFY pNotifyBuffer )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::NotifyServiceStatusChange" );
		CCheckReturn< DWORD, CTSuccessCheck< DWORD > >::TType dwResult;
#if		( _WIN32_WINNT >= 0x0600 )
		_WINQ_USESAPI( NotifyServiceStatusChange );
		dwResult = Call< DWORD, SC_HANDLE, DWORD, PSERVICE_NOTIFY >( pFunc, hService, dwNotifyMask, pNotifyBuffer );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( dwNotifyMask );
		QOR_PP_UNREF( pNotifyBuffer );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "NotifyServiceStatusChange" ), _T( "Windows Vista" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0600 )
		return dwResult;
	}

	//------------------------------------------------------------------------------
	SC_HANDLE CAdvAPI32::OpenSCManagerA( LPCSTR lpMachineName, LPCSTR lpDatabaseName, DWORD dwDesiredAccess )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::OpenSCManagerA" );
		CCheckReturn< SC_HANDLE, CCheckNonZero< SC_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( OpenSCManagerA );
		Result = Call< SC_HANDLE, LPCSTR, LPCSTR, DWORD >( pFunc, lpMachineName, lpDatabaseName, dwDesiredAccess );
#else
		QOR_PP_UNREF( lpMachineName );
		QOR_PP_UNREF( lpDatabaseName );
		QOR_PP_UNREF( dwDesiredAccess );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "OpenSCManagerA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SC_HANDLE CAdvAPI32::OpenSCManagerW( LPCWSTR lpMachineName, LPCWSTR lpDatabaseName, DWORD dwDesiredAccess )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::OpenSCManagerW" );
		CCheckReturn< SC_HANDLE, CCheckNonZero< SC_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( OpenSCManagerW );
		Result = Call< SC_HANDLE, LPCWSTR, LPCWSTR, DWORD >( pFunc, lpMachineName, lpDatabaseName, dwDesiredAccess );
#else
		QOR_PP_UNREF( lpMachineName );
		QOR_PP_UNREF( lpDatabaseName );
		QOR_PP_UNREF( dwDesiredAccess );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "OpenSCManagerW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SC_HANDLE CAdvAPI32::OpenServiceA( SC_HANDLE hSCManager, LPCSTR lpServiceName, DWORD dwDesiredAccess )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::OpenServiceA" );
		CCheckReturn< SC_HANDLE, CCheckNonZero< SC_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( OpenServiceA );
		Result = Call< SC_HANDLE, SC_HANDLE, LPCSTR, DWORD >( pFunc, hSCManager, lpServiceName, dwDesiredAccess );
#else
		QOR_PP_UNREF( hSCManager );
		QOR_PP_UNREF( lpServiceName );
		QOR_PP_UNREF( dwDesiredAccess );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "OpenServiceA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SC_HANDLE CAdvAPI32::OpenServiceW( SC_HANDLE hSCManager, LPCWSTR lpServiceName, DWORD dwDesiredAccess )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::OpenServiceW" );
		CCheckReturn< SC_HANDLE, CCheckNonZero< SC_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( OpenServiceW );
		Result = Call< SC_HANDLE, SC_HANDLE, LPCWSTR, DWORD >( pFunc, hSCManager, lpServiceName, dwDesiredAccess );
#else
		QOR_PP_UNREF( hSCManager );
		QOR_PP_UNREF( lpServiceName );
		QOR_PP_UNREF( dwDesiredAccess );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "OpenServiceW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceConfig2A( SC_HANDLE hService, DWORD dwInfoLevel, LPBYTE lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceConfig2A" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceConfig2A );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPBYTE, DWORD, LPDWORD >( pFunc, hService, dwInfoLevel, lpBuffer, cbBufSize, pcbBytesNeeded );
#else
		__QCMP_UNREF4( hService, dwInfoLevel, lpBuffer, cbBufSize );
		QOR_PP_UNREF( pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceConfig2A" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceConfig2W( SC_HANDLE hService, DWORD dwInfoLevel, LPBYTE lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceConfig2W" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceConfig2W );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPBYTE, DWORD, LPDWORD >( pFunc, hService, dwInfoLevel, lpBuffer, cbBufSize, pcbBytesNeeded );
#else
		__QCMP_UNREF4( hService, dwInfoLevel, lpBuffer, cbBufSize );
		QOR_PP_UNREF( pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceConfig2W" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceConfigA( SC_HANDLE hService, LPQUERY_SERVICE_CONFIG lpServiceConfig, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceConfigA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceConfigA );
		bResult = Call< BOOL, SC_HANDLE, LPQUERY_SERVICE_CONFIG, DWORD, LPDWORD >( pFunc, hService, lpServiceConfig, cbBufSize, pcbBytesNeeded );
#else
		__QCMP_UNREF4( hService, lpServiceConfig, cbBufSize, pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceConfigA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceConfigW( SC_HANDLE hService, LPQUERY_SERVICE_CONFIG lpServiceConfig, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceConfigW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceConfigW );
		bResult = Call< BOOL, SC_HANDLE, LPQUERY_SERVICE_CONFIG, DWORD, LPDWORD >( pFunc, hService, lpServiceConfig, cbBufSize, pcbBytesNeeded );
#else
		__QCMP_UNREF4( hService, lpServiceConfig, cbBufSize, pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceConfigW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceLockStatusA( SC_HANDLE hSCManager, LPQUERY_SERVICE_LOCK_STATUS lpLockStatus, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceLockStatusA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceLockStatusA );
		bResult = Call< BOOL, SC_HANDLE, LPQUERY_SERVICE_LOCK_STATUS, DWORD, LPDWORD >( pFunc, hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded );
#else
		__QCMP_UNREF4( hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceLockStatusA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceLockStatusW( SC_HANDLE hSCManager, LPQUERY_SERVICE_LOCK_STATUS lpLockStatus, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceLockStatusW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceLockStatusW );
		bResult = Call< BOOL, SC_HANDLE, LPQUERY_SERVICE_LOCK_STATUS, DWORD, LPDWORD >( pFunc, hSCManager, lpLockStatus, cbBufSize, pcbBytesNeeded );
#else
		QOR_PP_UNREF( hSCManager );
		QOR_PP_UNREF( lpLockStatus );
		QOR_PP_UNREF( cbBufSize );
		QOR_PP_UNREF( pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceLockStatusW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceStatus( SC_HANDLE hService, LPSERVICE_STATUS lpServiceStatus )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceStatus" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceStatus );
		bResult = Call< BOOL, SC_HANDLE, LPSERVICE_STATUS >( pFunc, hService, lpServiceStatus );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( lpServiceStatus );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceStatus" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::QueryServiceStatusEx( SC_HANDLE hService, SC_STATUS_TYPE InfoLevel, LPBYTE lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::QueryServiceStatusEx" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( QueryServiceStatusEx );
		bResult = Call< BOOL, SC_HANDLE, SC_STATUS_TYPE, LPBYTE, DWORD, LPDWORD >( pFunc, hService, InfoLevel, lpBuffer, cbBufSize, pcbBytesNeeded );
#else
		__QCMP_UNREF4( hService, InfoLevel, lpBuffer, cbBufSize );
		QOR_PP_UNREF( pcbBytesNeeded );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "QueryServiceStatusEx" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	SERVICE_STATUS_HANDLE CAdvAPI32::RegisterServiceCtrlHandlerA( LPCSTR lpServiceName, LPHANDLER_FUNCTION lpHandlerProc )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::RegisterServiceCtrlHandlerA" );
		CCheckReturn< SERVICE_STATUS_HANDLE, CCheckNonZero< SERVICE_STATUS_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( RegisterServiceCtrlHandlerA );
		Result = Call< SERVICE_STATUS_HANDLE, LPCSTR, LPHANDLER_FUNCTION >( pFunc, lpServiceName, lpHandlerProc );
#else
		QOR_PP_UNREF( lpServiceName );
		QOR_PP_UNREF( lpHandlerProc );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "RegisterServiceCtrlHandlerA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SERVICE_STATUS_HANDLE CAdvAPI32::RegisterServiceCtrlHandlerW( LPCWSTR lpServiceName, LPHANDLER_FUNCTION lpHandlerProc )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::RegisterServiceCtrlHandlerW" );
		CCheckReturn< SERVICE_STATUS_HANDLE, CCheckNonZero< SERVICE_STATUS_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( RegisterServiceCtrlHandlerW );
		Result = Call< SERVICE_STATUS_HANDLE, LPCWSTR, LPHANDLER_FUNCTION >( pFunc, lpServiceName, lpHandlerProc );
#else
		QOR_PP_UNREF( lpServiceName );
		QOR_PP_UNREF( lpHandlerProc );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "RegisterServiceCtrlHandlerW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SERVICE_STATUS_HANDLE CAdvAPI32::RegisterServiceCtrlHandlerExA( LPCSTR lpServiceName, LPHANDLER_FUNCTION_EX lpHandlerProc, LPVOID lpContext )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::RegisterServiceCtrlHandlerExA" );
		CCheckReturn< SERVICE_STATUS_HANDLE, CCheckNonZero< SERVICE_STATUS_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( RegisterServiceCtrlHandlerExA );
		Result = Call< SERVICE_STATUS_HANDLE, LPCSTR, LPHANDLER_FUNCTION_EX, LPVOID >( pFunc, lpServiceName, lpHandlerProc, lpContext );
#else
		QOR_PP_UNREF( lpServiceName );
		QOR_PP_UNREF( lpHandlerProc );
		QOR_PP_UNREF( lpContext );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "RegisterServiceCtrlHandlerExA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	SERVICE_STATUS_HANDLE CAdvAPI32::RegisterServiceCtrlHandlerExW( LPCWSTR lpServiceName, LPHANDLER_FUNCTION_EX lpHandlerProc, LPVOID lpContext )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::RegisterServiceCtrlHandlerExW" );
		CCheckReturn< SERVICE_STATUS_HANDLE, CCheckNonZero< SERVICE_STATUS_HANDLE > >::TType Result;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( RegisterServiceCtrlHandlerExW );
		Result = Call< SERVICE_STATUS_HANDLE, LPCWSTR, LPHANDLER_FUNCTION_EX, LPVOID >( pFunc, lpServiceName, lpHandlerProc, lpContext );
#else
		QOR_PP_UNREF( lpServiceName );
		QOR_PP_UNREF( lpHandlerProc );
		QOR_PP_UNREF( lpContext );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "RegisterServiceCtrlHandlerExW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return Result;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::SetServiceBits( SERVICE_STATUS_HANDLE hServiceStatus, DWORD dwServiceBits, BOOL bSetBitsOn, BOOL bUpdateImmediately )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::SetServiceBits" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( SetServiceBits );
		bResult = Call< BOOL, SERVICE_STATUS_HANDLE, DWORD, BOOL, BOOL >( pFunc, hServiceStatus, dwServiceBits, bSetBitsOn, bUpdateImmediately );
#else
		__QCMP_UNREF4( hServiceStatus, dwServiceBits, bSetBitsOn, bUpdateImmediately );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "SetServiceBits" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::SetServiceStatus( SERVICE_STATUS_HANDLE hServiceStatus, LPSERVICE_STATUS lpServiceStatus )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::SetServiceStatus" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( SetServiceStatus );
		bResult = Call< BOOL, SERVICE_STATUS_HANDLE, LPSERVICE_STATUS >( pFunc, hServiceStatus, lpServiceStatus );
#else
		QOR_PP_UNREF( hServiceStatus );
		QOR_PP_UNREF( lpServiceStatus );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "SetServiceStatus" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::StartServiceA( SC_HANDLE hService, DWORD dwNumServiceArgs, LPCSTR* lpServiceArgVectors )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::StartServiceA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( StartServiceA );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPCSTR* >( pFunc, hService, dwNumServiceArgs, lpServiceArgVectors );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( dwNumServiceArgs );
		QOR_PP_UNREF( lpServiceArgVectors );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "StartServiceA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::StartServiceW( SC_HANDLE hService, DWORD dwNumServiceArgs, LPCWSTR* lpServiceArgVectors )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::StartServiceW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( StartServiceW );
		bResult = Call< BOOL, SC_HANDLE, DWORD, LPCWSTR* >( pFunc, hService, dwNumServiceArgs, lpServiceArgVectors );
#else
		QOR_PP_UNREF( hService );
		QOR_PP_UNREF( dwNumServiceArgs );
		QOR_PP_UNREF( lpServiceArgVectors );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "StartServiceW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )

		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::StartServiceCtrlDispatcherA( const SERVICE_TABLE_ENTRY *lpServiceTable )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::StartServiceCtrlDispatcherA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( StartServiceCtrlDispatcherA );
		bResult = Call< BOOL, const SERVICE_TABLE_ENTRY* >( pFunc, lpServiceTable );
#else
		QOR_PP_UNREF( lpServiceTable );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "StartServiceCtrlDispatcherA" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::StartServiceCtrlDispatcherW( const SERVICE_TABLE_ENTRY *lpServiceTable )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::StartServiceCtrlDispatcherW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( StartServiceCtrlDispatcherW );
		bResult = Call< BOOL, const SERVICE_TABLE_ENTRY* >( pFunc, lpServiceTable );
#else
		QOR_PP_UNREF( lpServiceTable );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "StartServiceCtrlDispatcherW" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	BOOL CAdvAPI32::UnlockServiceDatabase( SC_LOCK ScLock )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::UnlockServiceDatabase" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0500 )
		_WINQ_USESAPI( UnlockServiceDatabase );
		bResult = Call< BOOL, SC_LOCK >( pFunc, ScLock );
#else
		QOR_PP_UNREF( ScLock );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T( "UnlockServiceDatabase" ), _T( "Windows 2000 Professional" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0500 )
		return bResult;
	}

}//nsWinQAPI
