//DataObjectClient.h

// Copyright Querysoft Limited 2013, 2015
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

#ifndef WINQL_COM_DATAOBJECTCLIENT_H_3
#define WINQL_COM_DATAOBJECTCLIENT_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Security.h"
#include "WinQL/Definitions/Interfaces.h"
#include "WinQL/COM/ServerObjectBase.h"
#include "WinQL/COM/ClientBase.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	//Client Side DataObject
	class __QOR_INTERFACE( __WINQL_COM ) CDataObjectClient : public CComPtr< IDataObject >
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CDataObjectClient );

		CDataObjectClient();
		virtual ~CDataObjectClient();

		long OleCreateFromData( const GUID& riid, unsigned long renderopt, FormatEtc* pFormatEtc, IOleClientSite* pClientSite, IStorage* pStg, void** ppvObj );
		long OleCreateFromDataEx( const GUID& riid, unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf, FormatEtc* rgFormatEtc, IAdviseSink* lpAdviseSink, unsigned long* rgdwConnection, IOleClientSite* pClientSite, IStorage* pStg, void** ppvObj );
		long OleCreateLinkFromData( const GUID& riid, unsigned long renderopt, FormatEtc* pFormatEtc, IOleClientSite* pClientSite, IStorage* pStg, void** ppvObj );
		long OleCreateLinkFromDataEx( const GUID& riid, unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf, FormatEtc* rgFormatEtc, IAdviseSink* lpAdviseSink, unsigned long* rgdwConnection, IOleClientSite* pClientSite, IStorage* pStg, void** ppvObj );
		long OleCreateStaticFromData( const GUID& iid, unsigned long renderopt, FormatEtc* pFormatEtc, IOleClientSite* pClientSite, IStorage* pStg, void** ppvObj );
		long OleIsCurrentClipboard( void );
		long OleQueryCreateFromData( void );
		long OleQueryLinkFromData( void );
		long OleSetClipboard( void );
		long OleFlushClipboard( void );

	private:

		CDataObjectClient( const CDataObjectClient& );
		CDataObjectClient& operator = ( const CDataObjectClient& );

	};

}//nsWin32

#endif//WINQL_COM_DATAOBJECTCLIENT_H_3

