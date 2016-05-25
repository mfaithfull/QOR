//WTSAPI32.h

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

#ifndef WINQAPI_MODULES_WTSAPI32_H_3
#define WINQAPI_MODULES_WTSAPI32_H_3

#include "../SystemQOR/MSWindows/WinQAPI/include/DynamicLibrary.h"
#include "WinQAPI/Kernel32.h"
#include <WtsApi32.h>

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQAPI ) CWTSAPI32 : public CDll
	{
	public:

		//--------------------------------------------------------------------------------
		CWTSAPI32() : CDll( TEXT("WTSAPI32.dll") )
		{						
		}

		//--------------------------------------------------------------------------------
		static CWTSAPI32* Instance( void )
		{
			return new CWTSAPI32;
		}

		//--------------------------------------------------------------------------------
		~CWTSAPI32()
		{						
		}

		//IsInteractiveUserSession
		//QueryActiveSession
		//QueryUserToken
		//RegisterUsertokenForNoWinlogon
		void WTSCloseServer( HANDLE hServer );
		BOOL WTSConnectSession( ULONG LogonId, ULONG TargetLogonId, PTSTR pPassword, BOOL bWait );
		BOOL WTSCreateListener( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, PWTSLISTENERCONFIG pBuffer, DWORD dwFlag );		
		BOOL WTSDisconnectSession( HANDLE hServer, DWORD SessionId, BOOL bWait );
		BOOL WTSEnableChildSessions( BOOL bEnable );
		BOOL WTSEnumerateListeners( HANDLE hServer, PVOID pReserved, DWORD Reserved, PWTSLISTENERNAME pListeners, DWORD* pCount );		
		BOOL WTSEnumerateProcesses( HANDLE hServer, DWORD Reserved, DWORD Version, PWTS_PROCESS_INFO* ppProcessInfo, DWORD* pCount );
		BOOL WTSEnumerateProcessesEx( HANDLE hServer, DWORD* pLevel, DWORD SessionID, LPTSTR* ppProcessInfo, DWORD* pCount );		
		BOOL WTSEnumerateServers( LPTSTR pDomainName, DWORD Reserved, DWORD Version, PWTS_SERVER_INFO* ppServerInfo, DWORD* pCount );
		BOOL WTSEnumerateSessions( HANDLE hServer, DWORD Reserved, DWORD Version, PWTS_SESSION_INFO* ppSessionInfo, DWORD* pCount );
		BOOL WTSEnumerateSessionsEx( HANDLE hServer, DWORD* pLevel, DWORD Filter, PWTS_SESSION_INFO_1* ppSessionInfo, DWORD* pCount );
		void WTSFreeMemory( PVOID pMemory );
		BOOL WTSFreeMemoryEx( WTS_TYPE_CLASS WtsTypeClass, PVOID pMemory, ULONG NumberOfEntries );
		BOOL WTSGetChildSessionId( ULONG* pSessionId );
		BOOL WTSGetListenerSecurity( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded );
		BOOL WTSIsChildSessionsEnabled( BOOL* pbEnabled );
		BOOL WTSLogoffSession( HANDLE hServer, DWORD SessionId, BOOL bWait );
		HANDLE WTSOpenServer( LPTSTR pServerName );
		HANDLE WTSOpenServerEx( LPTSTR pServerName );		
		BOOL WTSQueryListenerConfig( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, PWTSLISTENERCONFIG pBuffer );
		BOOL WTSQuerySessionInformation( HANDLE hServer, DWORD SessionId, WTS_INFO_CLASS WTSInfoClass, LPTSTR* ppBuffer, DWORD* pBytesReturned );		
		BOOL WTSQueryUserConfig( LPTSTR pServerName, LPTSTR pUserName, WTS_CONFIG_CLASS WTSConfigClass, LPTSTR* ppBuffer, DWORD* pBytesReturned );
		BOOL WTSQueryUserToken( ULONG SessionId, PHANDLE phToken );
		BOOL WTSRegisterSessionNotification( HWND hWnd, DWORD dwFlags );
		BOOL WTSRegisterSessionNotificationEx( HANDLE hServer, HWND hWnd, DWORD dwFlags );
		BOOL WTSSendMessage( HANDLE hServer, DWORD SessionId, LPTSTR pTitle, DWORD TitleLength, LPTSTR pMessage, DWORD MessageLength, DWORD Style, DWORD Timeout, DWORD* pResponse, BOOL bWait );
		BOOL WTSSetListenerSecurity( HANDLE hServer, PVOID pReserved, DWORD Reserved, LPTSTR pListenerName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor );
		
		//WTSSetRenderHint
		//WTSSetSessionInformationA
		//WTSSetSessionInformationW
		BOOL WTSSetUserConfig( LPTSTR pServerName, LPTSTR pUserName, WTS_CONFIG_CLASS WTSConfigClass, LPTSTR pBuffer, DWORD DataLength );		
		BOOL WTSShutdownSystem( HANDLE hServer, DWORD ShutdownFlag );

		BOOL WTSStartRemoteControlSession( LPTSTR pTargetServerName, ULONG TargetLogonId, BYTE HotkeyVk, USHORT HotkeyModifiers );
		BOOL WTSStopRemoteControlSession( ULONG LogonId );
		BOOL WTSTerminateProcess( HANDLE hServer, DWORD ProcessId, DWORD ExitCode );
		BOOL WTSUnRegisterSessionNotification( HWND hWnd );
		BOOL WTSUnRegisterSessionNotificationEx( HANDLE hServer, HWND hWnd );
		BOOL WTSVirtualChannelClose( HANDLE hChannelHandle );
		HANDLE WTSVirtualChannelOpen( HANDLE hServer, DWORD SessionId, LPSTR pVirtualName );
		HANDLE WTSVirtualChannelOpenEx( DWORD SessionId, LPSTR pVirtualName, DWORD flags );
		BOOL WTSVirtualChannelPurgeInput( HANDLE hChannelHandle );
		BOOL WTSVirtualChannelPurgeOutput( HANDLE hChannelHandle );
		BOOL WTSVirtualChannelQuery( HANDLE hChannelHandle, WTS_VIRTUAL_CLASS WtsVirtualClass, PVOID* ppBuffer, DWORD* pBytesReturned );
		BOOL WTSVirtualChannelRead( HANDLE hChannelHandle, ULONG TimeOut, PCHAR Buffer, ULONG BufferSize, PULONG pBytesRead );
		BOOL WTSVirtualChannelWrite( HANDLE hChannelHandle, PCHAR Buffer, ULONG Length, PULONG pBytesWritten );
		BOOL WTSWaitSystemEvent( HANDLE hServer, DWORD EventMask, DWORD* pEventFlags );

	};

}//nsWinQAPI

#endif//WINQAPI_MODULES_WTSAPI32_H_3
