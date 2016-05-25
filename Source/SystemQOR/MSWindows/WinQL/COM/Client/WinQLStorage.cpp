//WinQLStorage.cpp

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

#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/COM/Storage.h"
#include "WinQAPI/OLE32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	__QOR_IMPLEMENT_OCLASS_LUID( CPropertySetStorageClient );

	//--------------------------------------------------------------------------------
	CPropertySetStorageClient::CPropertySetStorageClient( IStorage* pStorage )
	{
		_WINQ_FCONTEXT( "CPropertySetStorageClient::CPropertySetStorageClient" );
		m_lStatus = m_Library.StgCreatePropSetStg( reinterpret_cast< ::IStorage* >( pStorage ), 0, reinterpret_cast< ::IPropertySetStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	CPropertySetStorageClient::~CPropertySetStorageClient()
	{
		_WINQ_FCONTEXT( "CPropertySetStorageClient::~CPropertySetStorageClient" );
	}

	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CPropertyStorageClient );

	//--------------------------------------------------------------------------------
	CPropertyStorageClient::CPropertyStorageClient( IUnknown* pUnk, const GUID& fmtid, const GUID* pclsid, unsigned long grfFlags, unsigned long dwReserved )
	{
		_WINQ_FCONTEXT( "CPropertySetStorageClient::CPropertySetStorageClient" );
		m_lStatus = m_Library.StgCreatePropStg( reinterpret_cast< ::IUnknown* >( pUnk ), reinterpret_cast< const IID& >( fmtid ), reinterpret_cast< const CLSID* >( pclsid ), grfFlags, dwReserved, reinterpret_cast< ::IPropertyStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	CPropertyStorageClient::CPropertyStorageClient( IUnknown* pUnk, const GUID& fmtid, unsigned long grfFlags, unsigned long dwReserved )
	{
		_WINQ_FCONTEXT( "CPropertySetStorageClient::CPropertySetStorageClient" );
		m_lStatus = m_Library.StgOpenPropStg( reinterpret_cast< ::IUnknown* >( pUnk ), reinterpret_cast< const IID& >( fmtid ), grfFlags, dwReserved, reinterpret_cast< ::IPropertyStorage** >( &m_p ) );
	}


	__QOR_IMPLEMENT_OCLASS_LUID( CStorageClient );

	//--------------------------------------------------------------------------------
	CStorageClient::CStorageClient()
	{
		_WINQ_FCONTEXT( "CStorageClient::CStorageClient" );
	}

	//--------------------------------------------------------------------------------
	//Obselete for Win2K and later
	//opens an existing root asynchronous storage object on a byte-array wrapper object provided by the caller. 
	CStorageClient::CStorageClient( IFillLockBytes* ppflb, unsigned long grfmode, unsigned long asyncFlags )
	{
		_WINQ_FCONTEXT( "CStorageClient::CStorageClient" );
		m_lStatus = m_Library.StgOpenAsyncDocfileOnIFillLockBytes( reinterpret_cast< ::IFillLockBytes* >( ppflb ), grfmode, asyncFlags, reinterpret_cast< ::IStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	//Opens an existing root storage object in the file system
	CStorageClient::CStorageClient( const wchar_t* pwcsName, IStorage* pstgPriority, unsigned long grfMode, wchar_t** snbExclude, unsigned long reserved )
	{
		_WINQ_FCONTEXT( "CStorageClient::CStorageClient" );
		m_lStatus = m_Library.StgOpenStorage( pwcsName, reinterpret_cast< ::IStorage* >( pstgPriority ), grfMode, snbExclude, reserved, reinterpret_cast< ::IStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	///Open a stream on locked bytes memory based storage
	CStorageClient::CStorageClient( ILockBytes* plkbyt,	IStorage* pStgPriority, unsigned long grfMode, wchar_t** snbExclude, unsigned long reserved )
	{
		_WINQ_FCONTEXT( "CStorageClient::CStorageClient" );
		m_lStatus = m_Library.StgOpenStorageOnILockBytes( reinterpret_cast< ::ILockBytes* >( plkbyt ), reinterpret_cast< ::IStorage* >( pStgPriority ), grfMode, snbExclude, reserved, reinterpret_cast< ::IStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	//creates and opens a new compound file storage object on top of a byte-array object 
	CStorageClient::CStorageClient( ILockBytes* plkbyt, unsigned long grfMode )
	{
		_WINQ_FCONTEXT( "CStorageClient::CStorageClient" );
		m_lStatus = m_Library.StgCreateDocfileOnILockBytes( reinterpret_cast< ::ILockBytes* >( plkbyt ), grfMode, 0, reinterpret_cast< ::IStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	//creates a new compound file storage object using the COM-provided compound file implementation for the IStorage interface.
	CStorageClient::CStorageClient( const wchar_t* pwcsName, unsigned long grfMode )
	{
		_WINQ_FCONTEXT( "CStorageClient::CStorageClient" );
		m_lStatus = m_Library.StgCreateDocfile( pwcsName, grfMode, 0, reinterpret_cast< ::IStorage** >( &m_p ) );
	}

	//--------------------------------------------------------------------------------
	CStorageClient::~CStorageClient()
	{
		_WINQ_FCONTEXT( "CStorageClient::~CStorageClient" );
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleCreateFromFile( const GUID& rclsid, const wchar_t* lpszFileName, const GUID& riid, unsigned long renderopt, FormatEtc* lpFormatEtc, IOleClientSite* pClientSite, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleCreateFromFile" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleCreateFromFile( reinterpret_cast< REFCLSID >( rclsid ), lpszFileName, reinterpret_cast< REFIID >( riid ), renderopt, reinterpret_cast< ::LPFORMATETC >( lpFormatEtc ), reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( m_p ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleCreateFromFileEx( const GUID& rclsid, const wchar_t* lpszFileName, const GUID& riid, unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf, FormatEtc* rgFormatEtc, IAdviseSink* lpAdviseSink, unsigned long* rgdwConnection, IOleClientSite* pClientSite, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleCreateFromFileEx" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleCreateFromFileEx( reinterpret_cast< REFCLSID >( rclsid ), lpszFileName, reinterpret_cast< REFIID >( riid ), dwFlags, renderopt, cFormats, rgAdvf, reinterpret_cast< ::LPFORMATETC >( rgFormatEtc ), reinterpret_cast< ::IAdviseSink* >( lpAdviseSink ), rgdwConnection, reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( m_p ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleCreateLink( IMoniker* pmkLinkSrc, const GUID& riid, unsigned long renderopt, FormatEtc* lpFormatEtc, IOleClientSite* pClientSite, void** ppvObj	)
	{
		_WINQ_FCONTEXT( "CStorageClient::OleCreateLink" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleCreateLink( reinterpret_cast< ::LPMONIKER >( pmkLinkSrc ), reinterpret_cast< REFIID >( riid ), renderopt, reinterpret_cast< ::LPFORMATETC >( lpFormatEtc ), reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( m_p ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleCreateLinkEx( IMoniker* pmkLinkSrc, const GUID& riid, unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf, FormatEtc* rgFormatEtc, IAdviseSink* lpAdviseSink, unsigned long* rgdwConnection, IOleClientSite* pClientSite, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleCreateLinkEx" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleCreateLinkEx( reinterpret_cast< ::LPMONIKER >( pmkLinkSrc ), reinterpret_cast< REFIID >( riid ), dwFlags, renderopt, cFormats, rgAdvf, reinterpret_cast< ::LPFORMATETC >( rgFormatEtc ), reinterpret_cast< ::IAdviseSink* >( lpAdviseSink ), rgdwConnection, reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( m_p ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleCreateLinkToFile( const wchar_t* lpszFileName, const GUID& riid, unsigned long renderopt, FormatEtc* lpFormatEtc, IOleClientSite* pClientSite, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleCreateLinkToFile" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleCreateLinkToFile( lpszFileName, reinterpret_cast< REFIID >( riid ), renderopt, reinterpret_cast< ::LPFORMATETC >( lpFormatEtc ), reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( m_p ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleCreateLinkToFileEx( const wchar_t* lpszFileName, const GUID& riid, unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf, FormatEtc* rgFormatEtc, IAdviseSink* lpAdviseSink, unsigned long* rgdwConnection, IOleClientSite* pClientSite, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleCreateLinkToFileEx" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleCreateLinkToFileEx( lpszFileName, reinterpret_cast< REFIID >( riid ), dwFlags, renderopt, cFormats, rgAdvf, reinterpret_cast< ::LPFORMATETC >( rgFormatEtc ), reinterpret_cast< ::IAdviseSink* >( lpAdviseSink ), rgdwConnection, reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( m_p ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleDoAutoConvert( GUID* pClsidNew )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleDoAutoConvert" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleDoAutoConvert( reinterpret_cast< ::LPSTORAGE >( m_p ), reinterpret_cast< ::LPCLSID >( pClsidNew ) );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::OleLoad( const GUID& riid, IOleClientSite* pClientSite, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CStorageClient::OleLoad" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleLoad( reinterpret_cast< ::LPSTORAGE >( m_p ), reinterpret_cast< REFIID >( riid ), reinterpret_cast< ::LPOLECLIENTSITE >( pClientSite ), ppvObj );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::SaveFromIPersistStorage( IPersistStorage* pPS, bool bSameAsLoad )
	{
		_WINQ_FCONTEXT( "CStorageClient::SaveFromIPersistStorage" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.OleSave( reinterpret_cast< ::LPPERSISTSTORAGE >( pPS ), reinterpret_cast< ::LPSTORAGE >( m_p ), bSameAsLoad ? 1 : 0 );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::GetConvertStg()
	{
		_WINQ_FCONTEXT( "CStorageClient::GetConvertStg" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.GetConvertStg( reinterpret_cast< ::IStorage* >( m_p ) );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::SetConvertStg( bool bConvert )
	{
		_WINQ_FCONTEXT( "CStorageClient::SetConvertStg" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.SetConvertStg( reinterpret_cast< ::IStorage* >( m_p ), bConvert ? 1 : 0 );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::ReadClassStg( GUID* pclsid )
	{
		_WINQ_FCONTEXT( "CStorageClient::ReadClassStg" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.ReadClassStg( reinterpret_cast< ::IStorage* >( m_p ), reinterpret_cast< CLSID* >( pclsid ) );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::WriteClassStg( const GUID& rclsid )
	{
		_WINQ_FCONTEXT( "CStorageClient::WriteClassStg" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.WriteClassStg( reinterpret_cast< ::IStorage* >( m_p ), reinterpret_cast< const IID& >( rclsid ) );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::ReadFmtUserTypeStg( CLIPFORMAT* pcf, wchar_t** ppszUserType )
	{
		_WINQ_FCONTEXT( "CStorageClient::ReadFmtUserTypeStg" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.ReadFmtUserTypeStg( reinterpret_cast< ::IStorage* >( m_p ), pcf, ppszUserType );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CStorageClient::WriteFmtUserTypeStg( CLIPFORMAT cf, wchar_t** pszUserType )
	{
		_WINQ_FCONTEXT( "CStorageClient::WriteFmtUserTypeStg" );
		long lResult = -1;
		__QOR_PROTECT
		{
			lResult = m_Library.WriteFmtUserTypeStg( reinterpret_cast< ::IStorage* >( m_p ), cf, pszUserType );
		}__QOR_ENDPROTECT
		return lResult;
	}

}//nsWin32

