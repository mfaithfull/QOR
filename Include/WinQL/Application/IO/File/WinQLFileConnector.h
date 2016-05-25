//WinQLFileConnector.h

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

#ifndef WINQL_IO_FILECONNECTOR_H_3
#define WINQL_IO_FILECONNECTOR_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "BluefootQOR/BfPlug.h"
#include "BluefootQOR/BfConnection.h"
#include "BluefootQOR/BfBuffer.h"
#include "WinQL/System/FileSystem/WinQLFile.h"
#include "WinQL/Application/IO/WinQLOverlappedHandler.h"
#include "WinQL/Application/ErrorSystem/WinQLErrorHandling.h"
#include "WinQL/Application/IO/File/WinQLFileSource.h"
#include "WinQL/Application/IO/File/WinQLFileSink.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CFileConnector : public nsBluefoot::CBFPlug
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CFileConnector );

		CFileConnector( nsBluefoot::CBFConnectionPool* pPool = 0 );
		virtual ~CFileConnector();

		//Plug interface
		virtual bool Connect( void );
		virtual void Disconnect( void );		
		virtual bool HandlePendingConnectionResult( bool bConnected );			//Handling device specific pending connection states for async connections

		virtual void OnConnected( void );
		virtual void OnConnectionError( void );
		virtual void OnDisconnected( void );		
		virtual void OnDisconnectionError( void );

		void SetFileName( CTString& strFileName );
		void SetDesiredAccess( unsigned long ulDesiredAccess );
		void SetShareMode( unsigned long ulShareMode );
		void SetFlags( unsigned long ulFlags );
		void SetSecurity( SECURITY_ATTRIBUTES* pSecurity );
		CTString GetFileName( void );
		unsigned long GetAccessMode( void );
		unsigned long GetShareMode( void );
		unsigned long GetFlags( void );
		SECURITY_ATTRIBUTES* GetSecurity( void );

		nsCodeQOR::CTLRef< CFile > File( void );

	protected:

		CFile* m_pFile;
		SECURITY_ATTRIBUTES* m_pSecurity;
		CTString m_strFileName;
		unsigned long m_ulAccess;
		unsigned long m_ulShareMode;
		unsigned long m_ulCreationDisposition;
		unsigned long m_ulFlags;
		void* m_pTemplate;
		CErrorHelper m_ErrorHelper;
	};

	//--------------------------------------------------------------------------------
	class CReadOnlyFileConnector : public nsBluefoot::CTBFReadOnlyConnection< CFileConnector, CFileSource >
	{
	public:

		//--------------------------------------------------------------------------------
		CReadOnlyFileConnector( CTString& strSourceFileName, unsigned long ulBufferSize = 0 ) : nsBluefoot::CTBFReadOnlyConnection< CFileConnector, CFileSource >(), m_pBuffer( 0 )
		{
			SetFileName( strSourceFileName );
			SetDesiredAccess( Generic_Read );
			SetShareMode( File_Share_Read );

			if( ulBufferSize > 0 )
			{
				m_pBuffer = new nsBluefoot::CByteStreamBuffer( ulBufferSize );
				GetSource()->SetBuffer( m_pBuffer );
			}
		}

		//--------------------------------------------------------------------------------
		CReadOnlyFileConnector( mxTCHAR* szFileName, unsigned long ulBufferSize = 0  ) : nsBluefoot::CTBFReadOnlyConnection< CFileConnector, CFileSource >()
		{
			CTString strSourceFileName( szFileName );
			SetFileName( strSourceFileName );
			SetDesiredAccess( Generic_Read );
			SetShareMode( File_Share_Read );

			if( ulBufferSize > 0 )
			{
				m_pBuffer = new nsBluefoot::CByteStreamBuffer( ulBufferSize );
				GetSource()->SetBuffer( m_pBuffer );
			}
		}

		//--------------------------------------------------------------------------------
		virtual ~CReadOnlyFileConnector()
		{
			delete m_pBuffer;
		}

	protected:

		nsBluefoot::CByteStreamBuffer* m_pBuffer;
	};

	//--------------------------------------------------------------------------------
	class CWriteOnlyFileConnector : public nsBluefoot::CTBFWriteOnlyConnection< CFileConnector, CFileSink >
	{
	public:

		//--------------------------------------------------------------------------------
		CWriteOnlyFileConnector( CTString& strSourceFileName ) : nsBluefoot::CTBFWriteOnlyConnection< CFileConnector, CFileSink >()
		{
			SetFileName( strSourceFileName );
			SetDesiredAccess( Generic_Write );
		}

		//--------------------------------------------------------------------------------
		CWriteOnlyFileConnector( mxTCHAR* szFileName ) : nsBluefoot::CTBFWriteOnlyConnection< CFileConnector, CFileSink >()
		{
			CTString strSourceFileName( szFileName );
			SetFileName( strSourceFileName );
			SetDesiredAccess( Generic_Write );
		}

		//--------------------------------------------------------------------------------
		virtual ~CWriteOnlyFileConnector()
		{
		}
	};

}//nsWin32

#endif//WINQL_IO_FILECONNECTOR_H_3
