//WinQLSocketServerAdaptor.cpp

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

#include "WinQL/Application/IO/Socket/WinQLSocketServerAdaptor.h"
#include "WinQL/Application/ErrorSystem/WinQLFunctionContext.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	__QOR_IMPLEMENT_OCLASS_LUID( CSocketServerAdaptor );

	//--------------------------------------------------------------------------------
	CSocketServerAdaptor::CSocketServerAdaptor( nsBluefoot::CConnectionPool* pPool ) : CSocketConnector( pPool ), m_iBacklog( 5 )
	{
		_WINQ_FCONTEXT( "CSocketServerAdaptor::CSocketServerAdaptor" );
		memset( m_Address.data.sa_data, 0, 60 );
	}
	
	//--------------------------------------------------------------------------------
	CSocketServerAdaptor::~CSocketServerAdaptor()
	{
		_WINQ_FCONTEXT( "CSocketServerAdaptor::~CSocketServerAdaptor" );
	}

	//--------------------------------------------------------------------------------
	void CSocketServerAdaptor::SetBacklog( int iBacklog )
	{
		_WINQ_FCONTEXT( "CSocketServerAdaptor::SetBacklog" );
		m_iBacklog = iBacklog;
	}

	//--------------------------------------------------------------------------------
	int CSocketServerAdaptor::GetBacklog( void )
	{
		_WINQ_FCONTEXT( "CSocketServerAdaptor::GetBacklog" );
		return m_iBacklog;
	}

	//--------------------------------------------------------------------------------
	void CSocketServerAdaptor::Create()
	{
		m_Socket.Create( m_AddressFamily, m_Type, m_iProtocol, m_pProtocolInfo, m_uiGroup, m_ulFlags  );
	}

	//--------------------------------------------------------------------------------
	void CSocketServerAdaptor::Bind()
	{
		m_pAcceptBuffer = new byte[ ( ( 16 + 16 ) * 2 ) ];
		memset( m_pAcceptBuffer, 0, ( 16 + 16 ) * 2 );		
		m_Address.sa_family = static_cast< unsigned short >( m_AddressFamily );
		m_Socket.Bind( m_Address );
	}

	//--------------------------------------------------------------------------------
	void CSocketServerAdaptor::SetAcceptConnection( nsBluefoot::CPlug::refPlugType AcceptConnection )
	{
		m_AcceptConnection = AcceptConnection->Ref();
	}

#define IOC_OUT         0x40000000      /* copy out parameters */
#define IOC_IN          0x80000000      /* copy in parameters */
#define IOC_INOUT       (IOC_IN|IOC_OUT)
#define IOC_WS2                       0x08000000
#define _WSAIORW(x,y)                 (IOC_INOUT|(x)|(y))
#define SIO_GET_EXTENSION_FUNCTION_POINTER  _WSAIORW(IOC_WS2,6)

	//--------------------------------------------------------------------------------
	bool CSocketServerAdaptor::Connect()
	{
		_WINQ_FCONTEXT( "CSocketServerAdaptor::Connect" );

		OVERLAPPED* pOverlapped  = reinterpret_cast< OVERLAPPED* >( GetSyncObject() );	//For connection use the OVERLAPPED set by the server

		m_Socket.Listen( m_iBacklog );

		fp_AcceptEx lpfnAcceptEx = 0;
		unsigned long ulBytes = 0;
		
		// Load the AcceptEx function into memory using WSAIoctl.
		// The WSAIoctl function is an extension of the ioctlsocket()
		// function that can use overlapped I/O. The function's 3rd
		// through 6th parameters are input and output buffers where
		// we pass the pointer to our AcceptEx function. This is used
		// so that we can call the AcceptEx function directly, rather
		// than refer to the Mswsock.lib library.
		m_Socket.IOCtl( SIO_GET_EXTENSION_FUNCTION_POINTER, 
			const_cast< void* >( reinterpret_cast< const void* >( &CSocket::WSAID_AcceptEx ) ),
			sizeof (nsCodeQOR::__mxGUID), reinterpret_cast< void* >( &lpfnAcceptEx ), sizeof (lpfnAcceptEx), &ulBytes, NULL, NULL );
		ulBytes = 0;
		bool bResult = lpfnAcceptEx( m_Socket.ID(), m_AcceptConnection.As< CSocketConnector >()->Socket().ID(), m_pAcceptBuffer,
                 0,
                 16 + 16, 16 + 16, 
                 &ulBytes, pOverlapped ) ? true : false;

		if( !bResult )
		{
			int iError = m_Socket.GetLastError();
			if(  iError == ErrorIOPending )
			{
				bResult = true;
			}
		}
		return bResult;
		
	}

	//--------------------------------------------------------------------------------
	void CSocketServerAdaptor::Disconnect() 
	{ 
		_WINQ_FCONTEXT( "CSocketServerAdaptor::Disconnect" );
		m_bConnected = false;
		bool bDisconnected = m_Socket.Shutdown( 1 ) ? true : false;		// Disconnect the pipe instance. 

		CSocketConnector::Disconnect();
		/*
		if( !AsyncConnection() && Protocol() )
		{
			bDisconnected ? Protocol().As< nsBluefoot::CProtocol >()->OnDisconnected() : Protocol().As< nsBluefoot::CProtocol >()->OnDisconnectionError();
		}
		*/
	}


}//nsWin32


