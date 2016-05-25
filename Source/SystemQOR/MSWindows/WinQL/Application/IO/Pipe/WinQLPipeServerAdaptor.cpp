//WinQLPipeServerAdaptor.cpp

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

#include "WinQL/Application/IO/Pipe/WinQLPipeServerAdaptor.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	__QOR_IMPLEMENT_OCLASS_LUID( CPipeServerAdaptor );

	//--------------------------------------------------------------------------------
	CPipeServerAdaptor::CPipeServerAdaptor( nsBluefoot::CBFConnectionPool* pPool ) : CPipeConnector( pPool )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::CPipeServerAdaptor" );
		
		m_ulOutgoingSystemBufferSize	= DefaultBufferSize;
		m_ulIncomingSystemBufferSize	= DefaultBufferSize;
		m_ulInstanceLimit				= DefaultInstanceLimit;
		m_ulReadMode					= DefaultReadMode;
		m_ulMessageMode					= DefaultMessageMode;
	}
	
	//--------------------------------------------------------------------------------
	CPipeServerAdaptor::~CPipeServerAdaptor()
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::~CPipeServerAdaptor" );
	}

	//--------------------------------------------------------------------------------
	bool CPipeServerAdaptor::Connect()
	{
		_WINQ_FCONTEXT( "CPipeServerConnection::Connect" );

		OVERLAPPED* pOverlapped  = reinterpret_cast< OVERLAPPED* >( GetSyncObject() );	//For connection use the OVERLAPPED set by the server

		if( !m_Pipe.IsOpen() )
		{
			m_Pipe.Create( m_strPipeName.GetBuffer(),										// pipe name 
				CPipe::Duplex |																	// read/write access 
					( ( AsyncConnection() || pOverlapped ) ? File_Flag_Overlapped : 0 ),
				m_ulMessageMode |															// message-type pipe 
					m_ulReadMode |															// message read mode 
					CPipe::Wait,															// blocking mode must always be set
				m_ulInstanceLimit,															// un|limited instances 
				m_ulOutgoingSystemBufferSize,
				m_ulIncomingSystemBufferSize,
				m_ulConnectionTimeout,														// client time-out 
				m_pSecurity );		
		}
		return m_Pipe.ConnectClient( pOverlapped );
	}

	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::OnConnected()
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::OnConnected" );
		m_bConnected = true;
		if( Protocol() )
		{
			Protocol()->OnConnected();
		}
	}

	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::Disconnect() 
	{ 
		_WINQ_FCONTEXT( "CPipeServerAdaptor::Disconnect" );
		m_bConnected = false;
		bool bDisconnected = m_Pipe.DisconnectClient();		// Disconnect the pipe instance. 

		if( bDisconnected )
		{
			m_Pipe.Close();									// Close the handle to the pipe instance. 
		}

		if( !AsyncConnection() && Protocol() )
		{
			bDisconnected ? Protocol()->OnDisconnected() : Protocol()->OnDisconnectionError();
		}		
	}


	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::SetInstanceLimit( unsigned char ucLimit )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::SetInstanceLimit" );
		m_ulInstanceLimit = ucLimit;
	}

	//--------------------------------------------------------------------------------
	unsigned char CPipeServerAdaptor::GetInstanceLimit( void )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::GetInstanceLimit" );
		return static_cast< unsigned char >( m_ulInstanceLimit );
	}

	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::SetReadMode( unsigned long ulReadMode )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::SetReadMode" );
		m_ulReadMode = ulReadMode;
	}

	//--------------------------------------------------------------------------------
	unsigned long CPipeServerAdaptor::GetReadMode( void )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::GetReadMode" );
		return m_ulReadMode;
	}

	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::SetMessageMode( unsigned long ulMessageMode )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::SetMessageMode" );
		m_ulMessageMode = ulMessageMode;
	}

	//--------------------------------------------------------------------------------
	unsigned long CPipeServerAdaptor::GetMessageMode( void )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::GetMessageMode" );
		return m_ulMessageMode;
	}

	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::SetOutgoingSystemBufferSize( unsigned long ulBufferSize )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::SetOutgoingSystemBufferSize" );
		m_ulOutgoingSystemBufferSize = ulBufferSize;
	}

	//--------------------------------------------------------------------------------
	unsigned long CPipeServerAdaptor::GetOutgoingSystemBufferSize( void )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::GetOutgoingSystemBufferSize" );
		return m_ulOutgoingSystemBufferSize;
	}

	//--------------------------------------------------------------------------------
	void CPipeServerAdaptor::SetIncomingSystemBufferSize( unsigned long ulBufferSize )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::SetIncomingSystemBufferSize" );
		m_ulIncomingSystemBufferSize = ulBufferSize;
	}

	//--------------------------------------------------------------------------------
	unsigned long CPipeServerAdaptor::GetIncomingSystemBufferSize( void )
	{
		_WINQ_FCONTEXT( "CPipeServerAdaptor::GetIncomingSystemBufferSize" );
		return m_ulIncomingSystemBufferSize;
	}

}//nsWin32


