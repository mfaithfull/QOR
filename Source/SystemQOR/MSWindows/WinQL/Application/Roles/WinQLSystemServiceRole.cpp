//WinQLSystemServiceRole.cpp

// Copyright Querysoft Limited 2016
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

//WinQL Application Role for System Service

#include "WinQL/WinQL.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Traits/MemoryTraits.h"
#include "SystemQOR/System.h"
#include "WinQL/System/WinQLSystem.h"
#include "WinQL/System/ProcessManager/WinQLServiceControlManager.h"
#include "WinQL/Application/Roles/WinQLSystemServiceRole.h"
#include "WinQL/Application/Process/WinQLProcess.h"
#include "WinQL/Application/WinQLApplication.h"
#include "WinQL/System/EventLogging/WinQLEventLog.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	CSystemServiceRole::CSystemServiceRole() : nsQOR::CRoleImplBase()
	{
	}

	//--------------------------------------------------------------------------------
	CSystemServiceRole::~CSystemServiceRole()
	{
	}

	//--------------------------------------------------------------------------------
	CSystemServiceRole::CSystemServiceRole( const CSystemServiceRole& src ) : nsQOR::CRoleImplBase( src )
	{
	}

	//--------------------------------------------------------------------------------
	CSystemServiceRole& CSystemServiceRole::operator = ( const CSystemServiceRole& src )
	{
		if( &src != this )
		{
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Setup( CWin32Application& Application )
	{
		m_Threading.Setup( Application );
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Shutdown( CWin32Application& Application )
	{
		m_Threading.Shutdown( Application );
	}

	//--------------------------------------------------------------------------------
	bool CSystemServiceRole::Run( void )
	{
		SERVICE_TABLE_ENTRY serviceTable[ ] =
		{
			{ m_strName.GetBuffer(), ServiceMain },
			{ 0, 0 }
		};

		return TheSystem().As< nsWin32::CSystem >()->Services( QOR_PP_SHARED_OBJECT_ACCESS )().StartCtrlDispatcher( serviceTable );
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Stop( void )
	{
		unsigned long dwOriginalState = m_Status.dwCurrentState;
		try
		{
			SetServiceStatus( eStopPending );				// Tell SCM that the service is stopping. 			
			OnStop();										// Perform service-specific stop operations. 			
			SetServiceStatus( eStopped );					// Tell SCM that the service is stopped. 
		}
		catch( unsigned long ulError )
		{
			WriteErrorLogEntry( _TXT( "Service Stop" ).c_str(), ulError );		// Log the error. 			 
			SetServiceStatus( dwOriginalState );						// Set the orginal service status.
		}
		catch( ... )
		{
			WriteEventLogEntry( _TXT( "Service failed to stop." ).c_str(), EventLog_Error_Type );		// Log the error. 
			SetServiceStatus( dwOriginalState );												// Set the orginal service status. 
		}
	}
	
	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Install( CTString& strDisplayName, unsigned long ulStartType, CTString& strDependencies, CTString& strAccount, CTString& strPassword )
	{
		CTString strPath = ( dynamic_cast< CProcess* >( CProcess::ThisProcess() ) )->GetFileName();

		// Open the local default service control manager database 
		CServiceControlSession::ref_type ServiceControlSession = TheSystem().As< nsWin32::CSystem >()->Services( QOR_PP_SHARED_OBJECT_ACCESS )().OpenSession(
			CTString::TheEmptyString(), CTString::TheEmptyString(), SCManagerConnect | SCManagerCreate );

		// Install the service into SCM by calling CreateService 
		CServiceController::ref_type ServiceController = ServiceControlSession->Create(
			m_strName, strDisplayName, Service_Query_Status, Service_Own_Process, ulStartType, eServiceErrorNormal, strPath, CTString::TheEmptyString(), 0, strDependencies, strAccount, strPassword );
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Uninstall( void )
	{
		//Open the local default service control manager database 
		CServiceControlSession::ref_type ServiceControlSession = TheSystem().As< nsWin32::CSystem >()->Services( QOR_PP_SHARED_OBJECT_ACCESS )().OpenSession( CTString::TheEmptyString(), CTString::TheEmptyString(), SCManagerConnect );

		SERVICE_STATUS ssSvcStatus = { };

		//Open the service with delete, stop, and query status permissions 
		CServiceController::refType ServiceController = ServiceControlSession->Open( m_strName, Service_Stop | Service_Query_Status | Delete );

		// Try to stop the service 
		if( ServiceController->Control( eServiceControlStop, &ssSvcStatus ) )
		{
			//wprintf( L"Stopping %s.", m_strName ); 

			GetCurrentWin32Thread()->Sleep( 1000 );

			while( ServiceController->QueryStatus( &ssSvcStatus ) )
			{
				if( ssSvcStatus.dwCurrentState == eStopPending )
				{
					//wprintf(L"."); 
					GetCurrentWin32Thread()->Sleep( 1000 );
				}
				else break;
			}

			/*
			if( ssSvcStatus.dwCurrentState == eStopped )
			{
			wprintf( L"\n%s is stopped.\n", m_strName );
			}
			else
			{
			wprintf( L"\n%s failed to stop.\n", m_strName );
			}
			*/
		}
		// Now remove the service by calling DeleteService. 
		if( !ServiceController->Delete() )
		{
			//wprintf( L"DeleteService failed w/err 0x%08lx\n", ThisProcess()->ErrorSystem().GetLastError() );         
		}
		else
		{
			//wprintf( L"%s is removed.\n", m_strName ); 
		}
	}
//protected:

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::OnStart( unsigned long ulArgc, TCHAR** szArgv )
	{
		//
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::OnStop( void )
	{
		//
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::OnPause( void )
	{
		//
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::OnContinue( void )
	{
		//
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::OnShutdown( void )
	{
		//
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::SetServiceStatus( unsigned long ulCurrentState, unsigned long ulWin32ExitCode, unsigned long ulWaitHint )
	{
		static unsigned long ulCheckPoint = 1;

		// Fill in the SERVICE_STATUS structure of the service. 

		m_Status.dwCurrentState = ulCurrentState;
		m_Status.dwWin32ExitCode = ulWin32ExitCode;
		m_Status.dwWaitHint = ulWaitHint;

		m_Status.dwCheckPoint = ( ( ulCurrentState == eRunning ) || ( ulCurrentState == eStopped ) ) ? 0 : ulCheckPoint++;

		// Report the status of the service to the SCM.
		TheSystem().As< nsWin32::CSystem >()->Services( QOR_PP_SHARED_OBJECT_ACCESS )().SetStatus( m_StatusHandle, &m_Status );
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::WriteEventLogEntry( const TCHAR* szMessage, unsigned short usType )
	{
		const TCHAR* lpszStrings[ 2 ] = { 0, 0 };

		CEventLogServer EventLog( 0, m_strName.GetBuffer() );

		m_strName.ReleaseBuffer();

		lpszStrings[ 0 ] = m_strName.GetBuffer();
		lpszStrings[ 1 ] = szMessage;

		EventLog.Report( usType, 0, 0, 0, 2, 0, &lpszStrings[ 0 ], 0 );

		m_strName.ReleaseBuffer();
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::WriteErrorLogEntry( const TCHAR* szFunction, unsigned long ulError )
	{
		CTString strMessage;
		strMessage.FormatV( _TXT( "%s failed w/err 0x%08lx" ), szFunction, ulError );
		WriteEventLogEntry( szFunction, EventLog_Error_Type );
	}

//private:

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::ServiceMain( unsigned long ulArgc, TCHAR** lpszArgv )
	{
		ref_type TheService = CWin32Application::TheWin32Application()->GetRole().As< CSystemServiceRole >();

		TheService->m_StatusHandle = TheSystem().As< nsWin32::CSystem >()->Services( QOR_PP_SHARED_OBJECT_ACCESS )().RegisterCtrlHandler( TheService->m_strName, ServiceCtrlHandler );

		if( TheService->m_StatusHandle == 0 )
		{
			//TODO: Raise error
		}
		else
		{
			TheService->Start( ulArgc, lpszArgv );
		}
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::ServiceCtrlHandler( unsigned long ulCtrl )
	{
		ref_type TheService = CWin32Application::TheWin32Application()->GetRole().As< CSystemServiceRole >();

		switch( ulCtrl )
		{
		case eServiceControlStop:
			TheService->Stop();
			break;
		case eServiceControlPause:
			TheService->Pause();
			break;
		case eServiceControlContinue:
			TheService->Continue();
			break;
		case eServiceControlShutdown:
			TheService->Shutdown();
			break;
		case eServiceControlInterrogate:
			break;
		default:
			break;
		}
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Start( unsigned long ulArgc, TCHAR** pszArgv )
	{
		try
		{
			SetServiceStatus( eStartPending );			// Tell SCM that the service is starting. 
			OnStart( ulArgc, pszArgv );					// Perform service-specific initialization. 
			SetServiceStatus( eRunning );				// Tell SCM that the service is started. 
		}
		catch( unsigned long ulError )
		{
			WriteErrorLogEntry( _TXT( "Service Start" ).c_str(), ulError );		// Log the error. 			
			SetServiceStatus( eStopped, ulError );						// Set the service status to be stopped. 
		}
		catch( ... )
		{
			WriteEventLogEntry( _TXT( "Service failed to start." ).c_str(), EventLog_Error_Type );		// Log the error. 			
			SetServiceStatus( eStopped );														// Set the service status to be stopped. 
		}
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Pause( void )
	{
		try
		{
			SetServiceStatus( ePausePending );		// Tell SCM that the service is pausing. 			
			OnPause();								// Perform service-specific pause operations. 			
			SetServiceStatus( ePaused );			// Tell SCM that the service is paused. 
		}
		catch( unsigned long ulError )
		{
			WriteErrorLogEntry( _TXT( "Service Pause" ), ulError );		// Log the error. 
			SetServiceStatus( eRunning );								// Tell SCM that the service is still running. 
		}
		catch( ... )
		{
			WriteEventLogEntry( _TXT( "Service failed to pause." ), EventLog_Error_Type );		// Log the error. 			
			SetServiceStatus( eRunning );														// Tell SCM that the service is still running. 
		}
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Continue( void )
	{
		try
		{
			SetServiceStatus( eContinuePending );			// Tell SCM that the service is resuming. 			
			OnContinue();									// Perform service-specific continue operations. 			
			SetServiceStatus( eRunning );					// Tell SCM that the service is running. 
		}
		catch( unsigned long ulError )
		{
			WriteErrorLogEntry( _TXT( "Service Continue" ), ulError );	// Log the error.  			
			SetServiceStatus( ePaused );								// Tell SCM that the service is still paused. 
		}
		catch( ... )
		{
			WriteEventLogEntry( _TXT( "Service failed to resume." ), EventLog_Error_Type );			// Log the error. 			
			SetServiceStatus( ePaused );															// Tell SCM that the service is still paused.  
		}
	}

	//--------------------------------------------------------------------------------
	void CSystemServiceRole::Shutdown( void )
	{
		try
		{
			OnShutdown();					// Perform service-specific shutdown operations. 			
			SetServiceStatus( eStopped );	// Tell SCM that the service is stopped. 
		}
		catch( unsigned long ulError )
		{
			// Log the error. 
			WriteErrorLogEntry( _TXT( "Service Shutdown" ), ulError );
		}
		catch( ... )
		{
			// Log the error. 
			WriteEventLogEntry( _TXT( "Service failed to shut down." ), EventLog_Error_Type );
		}
	}


}//nsWin32
