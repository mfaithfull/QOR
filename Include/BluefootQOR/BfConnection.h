//BfConnection.h

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

#ifndef BLUEFOOT_CONNECTION_H_3
#define BLUEFOOT_CONNECTION_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "BfSource.h"
#include "BfSink.h"
#include "BfPlug.h"

//--------------------------------------------------------------------------------
namespace nsBluefoot
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CConnectionPool;

	//--------------------------------------------------------------------------------
	template< class TPlug, class TSource, class TSink >
	class CConnection : public TPlug
	{
	public:

		typedef TPlug plugType;
		typedef TSource sourceType;
		typedef TSink sinkType;

		//--------------------------------------------------------------------------------
		CConnection( CConnectionPool* pPool = 0 ) : TPlug( pPool )
		,	m_Source( this )
		,	m_Sink( this )
		{
		}

		//--------------------------------------------------------------------------------
		virtual ~CConnection()
		{
		}

		//Connection interface
		//--------------------------------------------------------------------------------
		virtual CSource* GetSource( void )
		{
			return &m_Source;
		}

		//--------------------------------------------------------------------------------
		virtual CSink* GetSink( void )
		{
			return &m_Sink;
		}

		//--------------------------------------------------------------------------------
		virtual bool CanRead( void ) const
		{
			return false;
		}

		//--------------------------------------------------------------------------------
		virtual bool CanWrite( void ) const
		{
			return false;
		}

		//--------------------------------------------------------------------------------
		virtual const bool AsyncConnection( void ) const
		{
			return false;
		}

	protected:

		TSource m_Source;
		TSink m_Sink;
	};


	//--------------------------------------------------------------------------------
	//Adds read capability to a Connection by attaching a Source
	template< class TPlug, class TSource >
	class CReadOnlyConnection : public CConnection< TPlug, TSource, CNULLSink >
	{
	public:

		//--------------------------------------------------------------------------------
		CReadOnlyConnection( CConnectionPool* pPool = 0 ) : CConnection< TPlug, TSource, CNULLSink >( pPool )
		{			
		}

		//--------------------------------------------------------------------------------
		virtual ~CReadOnlyConnection()
		{
		}

		//--------------------------------------------------------------------------------
		virtual bool CanRead( void ) const
		{
			return true;
		}
	};

	//--------------------------------------------------------------------------------
	template< class TPlug, class TSink >
	class CWriteOnlyConnection : public CConnection< TPlug, CNULLSource, TSink >
	{
	public:

		//--------------------------------------------------------------------------------
		CWriteOnlyConnection( CConnectionPool* pPool = 0 ) : CConnection< TPlug, CNULLSource, TSink >( pPool )
		{			
		}

		//--------------------------------------------------------------------------------
		virtual ~CWriteOnlyConnection()
		{
		}

		//--------------------------------------------------------------------------------
		virtual bool CanWrite( void ) const
		{
			return true;
		}
	};

	//--------------------------------------------------------------------------------
	//A Read|Write connection adds Source and Sink to a base CPlug
	template< class TPlug, class TSource, class TSink >
	class CReadWriteConnection : public CConnection< TPlug, TSource, TSink >
	{
	public:

		//--------------------------------------------------------------------------------
		CReadWriteConnection( CConnectionPool* pPool = 0 ) : CConnection< TPlug, TSource, TSink >( pPool )
		{
		}

		//--------------------------------------------------------------------------------
		virtual ~CReadWriteConnection()
		{
		}

		//--------------------------------------------------------------------------------
		virtual bool CanRead( void ) const
		{
			return true;
		}

		//--------------------------------------------------------------------------------
		virtual bool CanWrite( void ) const
		{
			return true;
		}
	};

	//--------------------------------------------------------------------------------
	//CRTP wrapper which turns a TConnection into an Asynchronous Connection which 
	//will be called back when Read or Writes complete
	template< class TConnection, class TAsyncHandler >
	class CAsyncConnection : public TConnection, public TAsyncHandler
	{
		friend TAsyncHandler;

	public:

		//--------------------------------------------------------------------------------
		CAsyncConnection( CConnectionPool* pPool = 0 ) : TConnection( pPool )
		{		
			SetSyncObject( &m_Overlapped );															//Use the internal SyncObject by default. This may get changed by Server/Connection Manager		
		}

		//--------------------------------------------------------------------------------
		virtual ~CAsyncConnection()
		{			
		}

		//--------------------------------------------------------------------------------
		virtual void OnConnected( void )
		{
			//__QCS_MEMBER_FCONTEXT( "CAsyncConnection::OnConnected" );
			TConnection::SetSyncObject( &m_Overlapped );											//Once connected always use the internal SyncObject for IO
			TConnection::OnConnected();
		}

		//--------------------------------------------------------------------------------
		virtual const bool AsyncConnection( void ) const
		{
			return true;
		}

	protected:

		//--------------------------------------------------------------------------------
		virtual void OnWriteCompleted( unsigned long ulError, unsigned long ulUnitsWritten )
		{	
			CSink* pSink = GetSink();
			if (pSink)
			{
				if( ulError == 0 )
				{
					pSink->OnWriteSuccess(ulUnitsWritten);
				}
				else
				{
					pSink->OnWriteError(ulUnitsWritten, ulError)
				}
			}
		}
			
		//--------------------------------------------------------------------------------
		virtual void OnReadCompleted( unsigned long ulError, unsigned long ulCountUnitsRead)
		{
			CSource* pSource = GetSource();

			if (pSource)
			{
				if (ulError == 0)
				{
					pSource->OnReadSuccess(ulCountUnitsRead);
				}
				else
				{
					pSource->OnReadError(ulError, ulCountUnitsRead)
				}
			}
		}
	};

}//nsBluefoot

#endif//BLUEFOOT_CONNECTION_H_3
