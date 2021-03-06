//WinQLIOSink.h

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

#ifndef WINQL_IO_SINK_H_3
#define WINQL_IO_SINK_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/DataStructures/TLRef.h"
#include "WinQL/WinQL.h"
#include "BluefootQOR/BfSink.h"
#include "BluefootQOR/BfPlug.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	//A generic data sink, possibly but not necessarily representing a device.
	//Derived classes handle output to specific devices
	class __QOR_INTERFACE( __WINQL ) CIOSink : public nsBluefoot::CSink
	{
	public:

		typedef nsCodeQOR::CTLRef< CIOSink > refSinkType;

		//--------------------------------------------------------------------------------
		CIOSink( nsBluefoot::CPlug* pConnector = 0 ) : nsBluefoot::CSink()
		,	m_pIOSinkConnector( pConnector )
		{
		}

		//--------------------------------------------------------------------------------
		virtual ~CIOSink()
		{
			m_pIOSinkConnector = 0;
		}

		//--------------------------------------------------------------------------------
		refSinkType SinkRef( void )
		{
			refSinkType ref( this, false );
			return ref;
		}

		//--------------------------------------------------------------------------------
		nsBluefoot::CPlug* GetSinkConnector( void )
		{
			return m_pIOSinkConnector;
		}

		//--------------------------------------------------------------------------------
		void SetSinkConnector( nsBluefoot::CPlug* pIOConnector )
		{
			m_pIOSinkConnector = pIOConnector;
		}

		//--------------------------------------------------------------------------------
		virtual void OnWriteSuccess( void )
		{
		}

		virtual bool Write( unsigned long& ulNumberOfBytesWritten, unsigned long ulNumberOfBytesToWrite ) = 0;
		virtual bool Flush( void ) = 0;

	protected:

		nsBluefoot::CPlug* m_pIOSinkConnector;
	};

}//nsWin32

#endif//WINQL_IO_CONNECTION_H_3
