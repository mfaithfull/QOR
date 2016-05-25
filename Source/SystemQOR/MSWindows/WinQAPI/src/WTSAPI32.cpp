//WTSAPI32.cpp

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

#include "WinQAPI/WinQAPI.h"
#include "SystemQOR.h"
#include "WinQAPI/Kernel32.h"
#include "WinQAPI/WTSAPI32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	void CWTSAPI32::WTSCloseServer( HANDLE hServer )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSCloseServer" );
		_WINQ_USESAPI( WTSCloseServer );
		voidCall< HANDLE >( pFunc, hServer );
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSConnectSession( ULONG LogonId, ULONG TargetLogonId, PTSTR pPassword, BOOL bWait )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSConnectSession" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSConnectSession );
		bResult = Call< BOOL, ULONG, ULONG, PTSTR, BOOL >( pFunc, LogonId, TargetLogonId, pPassword, bWait );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSCreateListener( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, PWTSLISTENERCONFIG pBuffer, DWORD dwFlag )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSCreateList" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSCreateListener );
		bResult = Call< BOOL, HANDLE, PVOID, DWORD, LPTSTR, PWTSLISTENERCONFIG, DWORD >( pFunc, hServer, pReserved, Reserved, pListenerName, pBuffer, dwFlag );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSDisconnectSession( HANDLE hServer, DWORD SessionId, BOOL bWait )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSDisconnectSession" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSDisconnectSession );
		bResult = Call< BOOL, HANDLE, DWORD, BOOL >( pFunc, hServer, SessionId, bWait );
		return bResult;
		
	}
	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnableChildSessions( BOOL bEnable )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnableChildSessions" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnableChildSessions );
		bResult = Call< BOOL, BOOL >( pFunc, bEnable );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnumerateListeners( HANDLE hServer, PVOID pReserved, DWORD Reserved, PWTSLISTENERNAME pListeners, DWORD* pCount )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnumerateListeners" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnumerateListeners );
		bResult = Call< BOOL, HANDLE, PVOID, DWORD, PWTSLISTENERNAME, DWORD* >( pFunc, hServer, pReserved, Reserved, pListeners, pCount );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnumerateProcesses( HANDLE hServer, DWORD Reserved, DWORD Version, PWTS_PROCESS_INFO* ppProcessInfo, DWORD* pCount )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnumerateProcesses" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnumerateProcesses );
		bResult = Call< BOOL, HANDLE, DWORD, DWORD, PWTS_PROCESS_INFO*, DWORD* >( pFunc, hServer, Reserved, Version, ppProcessInfo, pCount );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnumerateProcessesEx( HANDLE hServer, DWORD* pLevel, DWORD SessionID, LPTSTR* ppProcessInfo, DWORD* pCount )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnumerateProcessesEx" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnumerateProcessesEx );
		bResult = Call< BOOL, HANDLE, DWORD*, DWORD, LPTSTR*, DWORD* >( pFunc, hServer, pLevel, SessionID, ppProcessInfo, pCount );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnumerateServers( LPTSTR pDomainName, DWORD Reserved, DWORD Version, PWTS_SERVER_INFO* ppServerInfo, DWORD* pCount )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnumerateServers" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnumerateServers );
		bResult = Call< BOOL, LPTSTR, DWORD, DWORD, PWTS_SERVER_INFO*, DWORD* >( pFunc, pDomainName, Reserved, Version, ppServerInfo, pCount );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnumerateSessions( HANDLE hServer, DWORD Reserved, DWORD Version, PWTS_SESSION_INFO* ppSessionInfo, DWORD* pCount )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnumerateSessions" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnumerateSessions );
		bResult = Call< BOOL, HANDLE, DWORD, DWORD, PWTS_SESSION_INFO*, DWORD* >( pFunc, hServer, Reserved, Version, ppSessionInfo, pCount );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSEnumerateSessionsEx( HANDLE hServer, DWORD* pLevel, DWORD Filter, PWTS_SESSION_INFO_1* ppSessionInfo, DWORD* pCount )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSEnumerateSessionsEx" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSEnumerateSessionsEx );
		bResult = Call< BOOL, HANDLE, DWORD*, DWORD, PWTS_SESSION_INFO_1*, DWORD* >( pFunc, hServer, pLevel, Filter, ppSessionInfo, pCount );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	void CWTSAPI32::WTSFreeMemory( PVOID pMemory )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSFreeMemory" );
		_WINQ_USESAPI( WTSFreeMemory );
		voidCall< PVOID >( pFunc, pMemory );		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSFreeMemoryEx( WTS_TYPE_CLASS WtsTypeClass, PVOID pMemory, ULONG NumberOfEntries )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSFreeMemoryEx" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSFreeMemoryEx );
		bResult = Call< BOOL, WTS_TYPE_CLASS, PVOID, ULONG >( pFunc, WtsTypeClass, pMemory, NumberOfEntries );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSGetChildSessionId( ULONG* pSessionId )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSGetChildSessionId" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSGetChildSessionId );
		bResult = Call< BOOL, ULONG* >( pFunc, pSessionId );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSGetListenerSecurity( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSGetListenerSecurity" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSGetListenerSecurity );
		bResult = Call< BOOL, HANDLE, PVOID, DWORD, LPTSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, DWORD, LPDWORD >( pFunc, hServer, pReserved, Reserved, pListenerName, SecurityInformation, pSecurityDescriptor, nLength, lpnLengthNeeded );
		return bResult;
	}
	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSIsChildSessionsEnabled( BOOL* pbEnabled )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSIsChildSessionsEnabled" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSIsChildSessionsEnabled );
		bResult = Call< BOOL, BOOL* >( pFunc, pbEnabled );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSLogoffSession( HANDLE hServer, DWORD SessionId, BOOL bWait )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSLogoffSession" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSLogoffSession );
		bResult = Call< BOOL, HANDLE, DWORD, BOOL >( pFunc, hServer, SessionId, bWait );	
		return bResult;
	}

	//--------------------------------------------------------------------------------
	HANDLE CWTSAPI32::WTSOpenServer( LPTSTR pServerName )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSOpenServer" );
		HANDLE hResult = 0;
		_WINQ_USESAPI( WTSOpenServer );
		hResult = Call< HANDLE, LPTSTR >( pFunc, pServerName );
		return hResult;
	}

	//--------------------------------------------------------------------------------
	HANDLE CWTSAPI32::WTSOpenServerEx( LPTSTR pServerName )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSOpenServerEx" );
		HANDLE hResult = 0;
		_WINQ_USESAPI( WTSOpenServerEx );
		hResult = Call< HANDLE, LPTSTR >( pFunc, pServerName );
		return hResult;		
	}

	//--------------------------------------------------------------------------------		
	BOOL CWTSAPI32::WTSQueryListenerConfig( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, PWTSLISTENERCONFIG pBuffer )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSQueryListenerConfig" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSQueryListenerConfig );
		bResult = Call< BOOL, HANDLE, PVOID, DWORD, LPTSTR, PWTSLISTENERCONFIG >( pFunc, hServer, pReserved, Reserved, pListenerName, pBuffer );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSQuerySessionInformation( HANDLE hServer, DWORD SessionId, WTS_INFO_CLASS WTSInfoClass, LPTSTR* ppBuffer, DWORD* pBytesReturned )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSQuerySessionInformation" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSQuerySessionInformation );
		bResult = Call< BOOL, HANDLE, DWORD, WTS_INFO_CLASS, LPTSTR*, DWORD* >( pFunc, hServer, SessionId, WTSInfoClass, ppBuffer, pBytesReturned );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSQueryUserConfig( LPTSTR pServerName, LPTSTR pUserName, WTS_CONFIG_CLASS WTSConfigClass, LPTSTR* ppBuffer, DWORD* pBytesReturned )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSQueryUserConfig" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSQueryUserConfig );
		bResult = Call< BOOL, LPTSTR, LPTSTR, WTS_CONFIG_CLASS, LPTSTR*, DWORD* >( pFunc, pServerName, pUserName, WTSConfigClass, ppBuffer, pBytesReturned );
		return bResult;
	}
	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSQueryUserToken( ULONG SessionId, PHANDLE phToken )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSQueryUserToken" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSQueryUserToken );
		bResult = Call< BOOL, ULONG, PHANDLE >( pFunc, SessionId, phToken );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSRegisterSessionNotification( HWND hWnd, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSRegisterSessionNotification" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSRegisterSessionNotification );
		bResult = Call< BOOL, HWND, DWORD >( pFunc, hWnd, dwFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSRegisterSessionNotificationEx( HANDLE hServer, HWND hWnd, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSRegisterSessionNotificationEx" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSRegisterSessionNotificationEx );
		bResult = Call< BOOL, HANDLE, HWND, DWORD >( pFunc, hServer, hWnd, dwFlags );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSSendMessage( HANDLE hServer, DWORD SessionId, LPTSTR pTitle, DWORD TitleLength, LPTSTR pMessage, DWORD MessageLength, DWORD Style, DWORD Timeout, DWORD* pResponse, BOOL bWait )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSSendMessage" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSSendMessage );
		bResult = Call< BOOL, HANDLE, DWORD, LPTSTR, DWORD, LPTSTR, DWORD, DWORD, DWORD, DWORD*, BOOL >( pFunc, hServer, SessionId, pTitle, TitleLength, pMessage, MessageLength, Style, Timeout, pResponse, bWait );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSSetListenerSecurity( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSSetListenerSecurity" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSSetListenerSecurity );
		bResult = Call< BOOL, HANDLE, PVOID, DWORD, LPTSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR >( pFunc, hServer, pReserved, Reserved, pListenerName, SecurityInformation, pSecurityDescriptor );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSSetUserConfig( LPTSTR pServerName, LPTSTR pUserName, WTS_CONFIG_CLASS WTSConfigClass, LPTSTR pBuffer, DWORD DataLength )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSSetUserConfig" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSSetUserConfig );
		bResult = Call< BOOL, LPTSTR, LPTSTR, WTS_CONFIG_CLASS, LPTSTR, DWORD >( pFunc, pServerName, pUserName, WTSConfigClass, pBuffer, DataLength );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSShutdownSystem( HANDLE hServer, DWORD ShutdownFlag )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSShutdownSystem" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSShutdownSystem );
		bResult = Call< BOOL, HANDLE, DWORD >( pFunc, hServer, ShutdownFlag );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSStartRemoteControlSession( LPTSTR pTargetServerName, ULONG TargetLogonId, BYTE HotkeyVk, USHORT HotkeyModifiers )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSStartRemoteControlSession" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSStartRemoteControlSession );
		bResult = Call< BOOL, LPTSTR, ULONG, BYTE, USHORT >( pFunc, pTargetServerName, TargetLogonId, HotkeyVk, HotkeyModifiers );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSStopRemoteControlSession( ULONG LogonId )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSStopRemoteControlSession" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSStopRemoteControlSession );
		bResult = Call< BOOL, ULONG >( pFunc, LogonId );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSTerminateProcess( HANDLE hServer, DWORD ProcessId, DWORD ExitCode )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSTerminateProcess" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSTerminateProcess );
		bResult = Call< BOOL, HANDLE, DWORD, DWORD >( pFunc, hServer, ProcessId, ExitCode );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSUnRegisterSessionNotification( HWND hWnd )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSUnRegisterSessionNotification" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSUnRegisterSessionNotification );
		bResult = Call< BOOL, HWND >( pFunc, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSUnRegisterSessionNotificationEx( HANDLE hServer, HWND hWnd )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSUnRegisterSessionNotificationEx" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSUnRegisterSessionNotificationEx );
		bResult = Call< BOOL, HANDLE, HWND >( pFunc, hServer, hWnd );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSVirtualChannelClose( HANDLE hChannelHandle )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelClose" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSVirtualChannelClose );
		bResult = Call< BOOL, HANDLE >( pFunc, hChannelHandle );
		return bResult;
	}
	//--------------------------------------------------------------------------------
	HANDLE CWTSAPI32::WTSVirtualChannelOpen( HANDLE hServer, DWORD SessionId, LPSTR pVirtualName )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelOpen" );
		HANDLE hResult = 0;
		_WINQ_USESAPI( WTSVirtualChannelOpen );
		hResult = Call< HANDLE, HANDLE, DWORD, LPSTR >( pFunc, hServer, SessionId, pVirtualName );
		return hResult;		
	}

	//--------------------------------------------------------------------------------
	HANDLE CWTSAPI32::WTSVirtualChannelOpenEx( DWORD SessionId, LPSTR pVirtualName, DWORD flags )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelOpenEx" );
		HANDLE hResult = 0;
		_WINQ_USESAPI( WTSVirtualChannelOpenEx );
		hResult = Call< HANDLE, DWORD, LPSTR, DWORD >( pFunc, SessionId, pVirtualName, flags );
		return hResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSVirtualChannelPurgeInput( HANDLE hChannelHandle )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelPurgeInput" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSVirtualChannelPurgeInput );
		bResult = Call< BOOL, HANDLE >( pFunc, hChannelHandle );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSVirtualChannelPurgeOutput( HANDLE hChannelHandle )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelPurgeOutput" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSVirtualChannelPurgeOutput );
		bResult = Call< BOOL, HANDLE >( pFunc, hChannelHandle );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSVirtualChannelQuery( HANDLE hChannelHandle, WTS_VIRTUAL_CLASS WtsVirtualClass, PVOID* ppBuffer, DWORD* pBytesReturned )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelQuery" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSVirtualChannelQuery );
		bResult = Call< BOOL, HANDLE, WTS_VIRTUAL_CLASS, PVOID*, DWORD* >( pFunc, hChannelHandle, WtsVirtualClass, ppBuffer, pBytesReturned );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSVirtualChannelRead( HANDLE hChannelHandle, ULONG TimeOut, PCHAR Buffer, ULONG BufferSize, PULONG pBytesRead )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelRead" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSVirtualChannelRead );
		bResult = Call< BOOL, HANDLE, ULONG, PCHAR, ULONG, PULONG >( pFunc, hChannelHandle, TimeOut, Buffer, BufferSize, pBytesRead );
		return bResult;		
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSVirtualChannelWrite( HANDLE hChannelHandle, PCHAR Buffer, ULONG Length, PULONG pBytesWritten )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSVirtualChannelWrite" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSVirtualChannelWrite );
		bResult = Call< BOOL, HANDLE, PCHAR, ULONG, PULONG >( pFunc, hChannelHandle, Buffer, Length, pBytesWritten );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CWTSAPI32::WTSWaitSystemEvent( HANDLE hServer, DWORD EventMask, DWORD* pEventFlags )
	{
		_WINQ_FCONTEXT( "CWTSAPI32::WTSWaitSystemEvent" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( WTSWaitSystemEvent );
		bResult = Call< BOOL, HANDLE, DWORD, DWORD* >( pFunc, hServer, EventMask, pEventFlags );
		return bResult;
	}

}//nsWinQAPI

