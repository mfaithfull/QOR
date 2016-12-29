//WinQLFileConnector.cpp

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

#include "WinQL/Application/IO/File/WinQLFileConnector.h"
#include "WinQL/Application/Threading/WinQLEvent.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CFileConnector );

	//--------------------------------------------------------------------------------
	CFileConnector::CFileConnector( nsBluefoot::CBFConnectionPool* pPool ) : nsBluefoot::CBFPlug( pPool )
	{
		_WINQ_FCONTEXT( "CFileConnector::CFileConnector" );
		m_pSecurity = 0;
		m_ulAccess = nsWin32::Generic_Read | nsWin32::Generic_Write;
		m_ulShareMode = 0;
		m_ulFlags = File_Attribute_Normal;
		m_pFile = 0;		
		m_ulCreationDisposition = Open_Always;
		m_pTemplate = 0;
	}

	//--------------------------------------------------------------------------------
	CFileConnector::~CFileConnector()
	{
		_WINQ_FCONTEXT( "CFileConnector::~CFileConnector" );
		if( m_bConnected )
		{
			Disconnect();
		}
	}

	//--------------------------------------------------------------------------------
	bool CFileConnector::Connect()
	{
		_WINQ_FCONTEXT( "CFileConnector::Connect" );

		m_pFile = new CFile( m_strFileName, m_ulAccess, m_ulShareMode, m_pSecurity, m_ulCreationDisposition, m_ulFlags, m_pTemplate );
		m_bConnected = ( m_pFile != 0 && m_pFile->IsOpen() ) ? true : false;

		if( !AsyncConnection() )
		{
			m_bConnected ? OnConnected() : OnConnectionError();
		}
		return m_bConnected;
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::Disconnect()
	{
		_WINQ_FCONTEXT( "CFileConnector::Disconnect" );
		m_bConnected = false;
		delete m_pFile;		
		if( !AsyncConnection() )
		{
			OnDisconnected();
		}
	}

	//--------------------------------------------------------------------------------
	bool CFileConnector::HandlePendingConnectionResult( bool bConnected )
	{
		_WINQ_FCONTEXT( "CFileConnector::HandlePendingConnectionResult" );

		bool bPendingIO = false;

		// Overlapped ConnectNamedPipe should return zero. 
		if( bConnected ) 
		{
			//printf("ConnectNamedPipe failed with %d.\n", GetLastError()); 
			return false;
		}

		switch( m_ErrorHelper.GetLastError() ) 
		{ 
		// The overlapped connection in progress. 
		case ErrorIOPending: 
			bPendingIO = true; 
			break; 
   
		// If an error occurs during the connect operation... 
		default: 
			{
				//printf("ConnectNamedPipe failed with %d.\n", GetLastError());
				return false;
			}
		} 

		return bPendingIO;		
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::OnConnected( void )
	{
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::OnConnectionError( void )
	{
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::OnDisconnected( void )
	{
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::OnDisconnectionError( void )
	{
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::SetFileName( CTString& strFileName )
	{
		_WINQ_FCONTEXT( "CFileConnector::SetFileName" );
		m_strFileName = strFileName;
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::SetDesiredAccess( unsigned long ulDesiredAccess )
	{
		_WINQ_FCONTEXT( "CFileConnector::SetDesiredAccess" );
		m_ulAccess = ulDesiredAccess;
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::SetShareMode( unsigned long ulShareMode )
	{
		_WINQ_FCONTEXT( "CFileConnector::SetShareMode" );
		m_ulShareMode = ulShareMode;
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::SetFlags( unsigned long ulFlags )
	{
		_WINQ_FCONTEXT( "CFileConnector::SetFlags" );
		m_ulFlags = ulFlags;
	}

	//--------------------------------------------------------------------------------
	void CFileConnector::SetSecurity( SECURITY_ATTRIBUTES* pSecurity )
	{
		_WINQ_FCONTEXT( "CFileConnector::SetSecurity" );
		m_pSecurity = pSecurity;
	}

	//--------------------------------------------------------------------------------
	CTString CFileConnector::GetFileName( void )
	{
		_WINQ_FCONTEXT( "CFileConnector::GetFileName" );
		return m_strFileName;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFileConnector::GetAccessMode( void )
	{
		_WINQ_FCONTEXT( "CFileConnector::GetAccessMode" );
		return m_ulAccess;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFileConnector::GetShareMode( void )
	{
		_WINQ_FCONTEXT( "CFileConnector::GetShareMode" );
		return m_ulShareMode;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFileConnector::GetFlags( void )
	{
		_WINQ_FCONTEXT( "CFileConnector::GetFlags" );
		return m_ulFlags;
	}

	//--------------------------------------------------------------------------------
	SECURITY_ATTRIBUTES* CFileConnector::GetSecurity( void )
	{
		_WINQ_FCONTEXT( "CFileConnector::GetSecurity" );
		return m_pSecurity;
	}

	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< CFile > CFileConnector::File( void )
	{
		return nsCodeQOR::CTLRef< CFile >( m_pFile );
	}

}//nsWin32

