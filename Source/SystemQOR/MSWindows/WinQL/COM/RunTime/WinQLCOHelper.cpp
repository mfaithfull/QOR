//WinQLCOHelper.cpp

// Copyright Querysoft Limited 2013, 2015, 2017
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
#include "WinQL/System/Registry/WinQLRegistry.h"
#include "WinQL/COM/Runtime/WinQLCOHelper.h"
#include "WinQL/Definitions/Interfaces.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQAPI/OLE32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CCOHelper );

	//--------------------------------------------------------------------------------
	CCOHelper::CCOHelper() : m_Library( COLE32::Instance() )
	{
		_WINQ_FCONTEXT( "CCOHelper::CCOHelper" );
	}

	//--------------------------------------------------------------------------------
	CCOHelper::~CCOHelper()
	{
		_WINQ_FCONTEXT( "CCOHelper::~CCOHelper" );
	}

	//--------------------------------------------------------------------------------
	CCOHelper& CCOHelper::operator = ( const CCOHelper& )
	{
		_WINQ_FCONTEXT( "CCOHelper::operator = " );
		//Nothing to assign but the MSVC compiler can't generate this so we have to write it
		return *this;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::CLSIDFromProgID( const wchar_t* lpszProgID, GUID* lpclsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::CLSIDFromProgID" );
		return m_Library.CLSIDFromProgID( lpszProgID, reinterpret_cast< LPCLSID >( lpclsid ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::CLSIDFromProgIDEx( const wchar_t* lpszProgID, GUID* lpclsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::CLSIDFromProgIDEx" );
		return m_Library.CLSIDFromProgIDEx( lpszProgID, reinterpret_cast< LPCLSID >( lpclsid ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::CLSIDFromString( const wchar_t* lpsz, GUID* pclsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::CLSIDFromString" );
		return m_Library.CLSIDFromString( lpsz, reinterpret_cast< LPCLSID >( pclsid ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::CopyProxy( void* pProxy, void** ppCopy )
	{
		_WINQ_FCONTEXT( "CCOHelper::CopyProxy" );
		return m_Library.CoCopyProxy( reinterpret_cast< ::IUnknown* >( pProxy ), reinterpret_cast< ::IUnknown** >( ppCopy ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::CreateFreeThreadedMarshaler( void* punkOuter, void** ppunkMarshal )
	{
		_WINQ_FCONTEXT( "CCOHelper::CreateFreeThreadedMarshaler" );
		return m_Library.CoCreateFreeThreadedMarshaler( reinterpret_cast< ::LPUNKNOWN >( punkOuter ), reinterpret_cast< ::LPUNKNOWN* >( ppunkMarshal ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::CreateGUID( GUID* pguid )
	{
		_WINQ_FCONTEXT( "CCOHelper::CreateGUID" );
		return m_Library.CoCreateGuid( reinterpret_cast< ::GUID* >( pguid ) );
	}

	//--------------------------------------------------------------------------------
	bool CCOHelper::DosDatTimeToFileTime( unsigned short usDosDate, unsigned short usDosTime, FILETIME* pFileTime )
	{
		_WINQ_FCONTEXT( "CCOHelper::DosDatTimeToFileTime" );
		return m_Library.CoDosDateTimeToFileTime( usDosDate, usDosTime, reinterpret_cast< ::FILETIME* >( pFileTime ) ) ? true : false;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::FileTimeNow( FILETIME* pFileTime )
	{
		_WINQ_FCONTEXT( "CCOHelper::FileTimeNow" );
		return m_Library.CoFileTimeNow( reinterpret_cast< ::FILETIME* >( pFileTime	) );
	}

	//--------------------------------------------------------------------------------
	bool CCOHelper::FileTimeToDosDateTime( FILETIME* pFileTime, unsigned short* pDosDate, unsigned short* pDosTime )
	{
		_WINQ_FCONTEXT( "CCOHelper::FileTimeToDosDateTime" );
		return m_Library.CoFileTimeToDosDateTime( reinterpret_cast< ::FILETIME* >( pFileTime ), pDosDate, pDosTime ) ? true : false;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::GetPSClsid( const GUID& riid, GUID* pClsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::GetPSClsid" );
		return m_Library.CoGetPSClsid( reinterpret_cast< REFIID >( riid ), reinterpret_cast< CLSID* >( pClsid ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::GetTreatAsClass( const GUID& clsidOld, GUID* pClsidNew )
	{
		_WINQ_FCONTEXT( "CCOHelper::GetTreatAsClass" );
		return m_Library.CoGetTreatAsClass( reinterpret_cast< REFCLSID >( clsidOld ), reinterpret_cast< LPCLSID >( pClsidNew ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::InstallServer( uClsSpec* pClassSpec, QueryContext* pQuery )
	{
		_WINQ_FCONTEXT( "CCOHelper::InstallServer" );
		pClassSpec->tyspec = TYSPEC_CLSID;
		return m_Library.CoInstall( 0, 0, reinterpret_cast< uCLSSPEC* >( pClassSpec ), reinterpret_cast< QUERYCONTEXT* >( pQuery ), 0 );
	}

	//--------------------------------------------------------------------------------
	bool CCOHelper::IsHandlerConnected( void* pUnk )
	{
		_WINQ_FCONTEXT( "CCOHelper::IsHandlerConnected" );
		bool bResult = m_Library.CoIsHandlerConnected( reinterpret_cast< LPUNKNOWN >( pUnk ) ) ? true : false;
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CCOHelper::IsOle1Class( const GUID& rclsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::IsOle1Class" );
		bool bResult = m_Library.CoIsOle1Class( reinterpret_cast< REFCLSID >( rclsid ) ) ? true : false;
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void* CCOHelper::TaskMemAlloc( Cmp_ulong_ptr cb )
	{
		_WINQ_FCONTEXT( "CCOHelper::TaskMemAlloc" );
		void* pResult = m_Library.CoTaskMemAlloc( cb );
		//TODO: Always check return value
		return pResult;
	}

	//--------------------------------------------------------------------------------
	void CCOHelper::TaskMemFree( void* pv )
	{
		_WINQ_FCONTEXT( "CCOHelper::TaskMemFree" );
		m_Library.CoTaskMemFree( pv );
	}

	//--------------------------------------------------------------------------------
	void* CCOHelper::TaskMemRealloc( void* pv, Cmp_ulong_ptr cb )
	{
		_WINQ_FCONTEXT( "CCOHelper::TaskMemRealloc" );
		return m_Library.CoTaskMemRealloc( pv, cb );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::WaitForMultipleHandles( unsigned long ulFlags, unsigned long ulTimeout, unsigned long cHandles, void** pHandles, unsigned long* pulIndex )
	{
		_WINQ_FCONTEXT( "CCOHelper::WaitForMultipleHandles" );
		return m_Library.CoWaitForMultipleHandles( ulFlags, ulTimeout, cHandles, pHandles, pulIndex );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::FmtIdToPropStgName( const GUID* pfmtid, wchar_t* wszName )
	{
		_WINQ_FCONTEXT( "CCOHelper::FmtIdToPropStgName" );
		return m_Library.FmtIdToPropStgName( reinterpret_cast< const FMTID* >( pfmtid ), wszName );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::FreePropVariantArray( unsigned long cVariants, PropVariant* pVars )
	{
		_WINQ_FCONTEXT( "CCOHelper::FreePropVariantArray" );
		return m_Library.FreePropVariantArray( cVariants, reinterpret_cast< ::PROPVARIANT* >( pVars ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::GetClassFile( wchar_t* szFilename, GUID* pclsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::GetClassFile" );
		return m_Library.GetClassFile( szFilename, reinterpret_cast< CLSID* >( pclsid ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::IIDFromString( const wchar_t* lpsz, GUID* piid )
	{
		_WINQ_FCONTEXT( "CCOHelper::IIDFromString" );
		return m_Library.IIDFromString( lpsz, reinterpret_cast< LPIID >( piid ) );
	}

	//--------------------------------------------------------------------------------
	int CCOHelper::IsAccelerator( void* pAccel, int cAccelEntries, MSG* pMsg, unsigned short* pwCmd )
	{
		_WINQ_FCONTEXT( "CCOHelper::IsAccelerator" );
		return m_Library.IsAccelerator( reinterpret_cast< HACCEL >( pAccel ), cAccelEntries, reinterpret_cast< ::LPMSG >( pMsg ), pwCmd );
	}

	//--------------------------------------------------------------------------------
	int CCOHelper::IsEqualGUID( const GUID& rguid1, const GUID& rguid2 )
	{
		_WINQ_FCONTEXT( "CCOHelper::IsEqualGUID" );
		return m_Library.IsEqualGUID( reinterpret_cast< const ::GUID& >( rguid1 ), reinterpret_cast< const ::GUID& >( rguid2 ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::MonikerCommonPrefixWith( IMoniker* pmkThis, IMoniker* pmkOther, IMoniker** ppmkCommon )
	{
		_WINQ_FCONTEXT( "CCOHelper::MonikerCommonPrefixWith" );
		return m_Library.MonikerCommonPrefixWith( reinterpret_cast< LPMONIKER >( pmkThis ), reinterpret_cast< LPMONIKER >( pmkOther ), reinterpret_cast< LPMONIKER* >( ppmkCommon ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::MonikerRelativePathTo( IMoniker* pmkSrc, IMoniker* pmkDest, IMoniker** ppmkRelPath )
	{
		_WINQ_FCONTEXT( "CCOHelper::MonikerRelativePathTo" );
		return m_Library.MonikerRelativePathTo( reinterpret_cast< LPMONIKER >( pmkSrc ), reinterpret_cast< LPMONIKER >( pmkDest ), reinterpret_cast< LPMONIKER* >( ppmkRelPath ), 1 );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleConvertIStorageToOLESTREAM( IStorage* pStg, OLEStream* pOLEStream )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleConvertIStorageToOLESTREAM" );
		return m_Library.OleConvertIStorageToOLESTREAM( reinterpret_cast< ::IStorage* >( pStg ), reinterpret_cast< ::LPOLESTREAM >( pOLEStream ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleConvertIStorageToOLESTREAMEx( IStorage* pStg, CLIPFORMAT cfFormat, long lWidth, long lHeight, unsigned long ulSize, StgMedium* pmedium, OLEStream* polestm )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleConvertIStorageToOLESTREAMEx" );
		return m_Library.OleConvertIStorageToOLESTREAMEx( reinterpret_cast< ::IStorage* >( pStg ), cfFormat, lWidth, lHeight, ulSize, reinterpret_cast< ::STGMEDIUM* >( pmedium ), reinterpret_cast< LPOLESTREAM >( polestm ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleConvertOLESTREAMToIStorage( OLEStream* polestream, IStorage* pstg, const DVTargetDevice* ptd )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleConvertOLESTREAMToIStorage" );
		return m_Library.OleConvertOLESTREAMToIStorage( reinterpret_cast< LPOLESTREAM >( polestream ), reinterpret_cast< ::IStorage* >( pstg ), reinterpret_cast< const DVTARGETDEVICE* >( ptd ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleConvertOLESTREAMToIStorageEx( OLEStream* polestm, IStorage* pstg, CLIPFORMAT* pcfFormat, long* plWidth, long* plHeight, unsigned long* pulSize, StgMedium* pmedium )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleConvertOLESTREAMToIStorageEx" );
		return m_Library.OleConvertOLESTREAMToIStorageEx( reinterpret_cast< LPOLESTREAM >( polestm ), reinterpret_cast< ::IStorage* >( pstg ), reinterpret_cast< ::CLIPFORMAT* >( pcfFormat ), plWidth, plHeight, pulSize, reinterpret_cast< ::STGMEDIUM* >( pmedium ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::StgCreateStorageEx( const wchar_t* pwcsName, unsigned long grfMode, unsigned long stgfmt, unsigned long grfAttrs, STGOPTIONS* pStgOptions, SECURITY_DESCRIPTOR** pSecurityDescriptor, const GUID& riid, void** ppObjectOpen )
	{
		_WINQ_FCONTEXT( "CCOHelper::StgCreateStorageEx" );
		return m_Library.StgCreateStorageEx( pwcsName, grfMode, stgfmt, grfAttrs, reinterpret_cast< ::STGOPTIONS* >( pStgOptions ), reinterpret_cast< ::PSECURITY_DESCRIPTOR* >( pSecurityDescriptor ), reinterpret_cast< const IID& >( riid ), ppObjectOpen );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::StgIsStorageFile( const wchar_t* pwcsName )
	{
		_WINQ_FCONTEXT( "CCOHelper::StgIsStorageFile" );
		return m_Library.StgIsStorageFile( pwcsName );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::StgOpenStorageEx( const wchar_t* pwcsName, unsigned long grfMode, unsigned long stgfmt, unsigned long grfAttrs, STGOPTIONS* pStgOptions, void* reserved2, const GUID& riid, void** ppObjectOpen )
	{
		_WINQ_FCONTEXT( "CCOHelper::StgOpenStorageEx" );
		return m_Library.StgOpenStorageEx( pwcsName, grfMode, stgfmt, grfAttrs, reinterpret_cast< ::STGOPTIONS* >( pStgOptions ), reserved2, reinterpret_cast< const IID& >( riid ), ppObjectOpen );
	}

	//--------------------------------------------------------------------------------
	unsigned long CCOHelper::StgPropertyLengthAsVariant( const SERIALIZEDPROPERTYVALUE* pProp, unsigned long cbProp, unsigned short CodePage )
	{
		_WINQ_FCONTEXT( "CCOHelper::StgPropertyLengthAsVariant" );
		return m_Library.StgPropertyLengthAsVariant( reinterpret_cast< const ::SERIALIZEDPROPERTYVALUE* >( pProp ), cbProp, CodePage, 0 );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::StgSetTimes( wchar_t const* lpszName, FILETIME const* pctime, FILETIME const* patime, FILETIME const* pmtime )
	{
		_WINQ_FCONTEXT( "CCOHelper::StgSetTimes" );
		return m_Library.StgSetTimes( lpszName, reinterpret_cast< const ::FILETIME* >( pctime ), reinterpret_cast< const ::FILETIME* >( patime ), reinterpret_cast< const ::FILETIME* >( pmtime ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::StringFromCLSID( const GUID& rclsid, wchar_t** ppsz )
	{
		_WINQ_FCONTEXT( "CCOHelper::StringFromCLSID" );
		return m_Library.StringFromCLSID( reinterpret_cast< const IID& >( rclsid ), ppsz );
	}

	//--------------------------------------------------------------------------------
	int CCOHelper::StringFromGUID2( const GUID& rguid, wchar_t* lpsz, int cchMax )
	{
		_WINQ_FCONTEXT( "CCOHelper::StringFromGUID2" );
		return m_Library.StringFromGUID2( reinterpret_cast< const ::GUID& >( rguid ), lpsz, cchMax );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::StringFromIID( const GUID& rclsid, wchar_t** ppsz )
	{
		_WINQ_FCONTEXT( "CCOHelper::StringFromIID" );
		return m_Library.StringFromIID( reinterpret_cast< const IID& >( rclsid ), ppsz );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::ProgIDFromCLSID( const GUID& clsid, wchar_t** ppszProgID )
	{
		_WINQ_FCONTEXT( "CCOHelper::ProgIDFromCLSID" );
		return m_Library.ProgIDFromCLSID( reinterpret_cast< const IID& >( clsid ), ppszProgID );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleGetAutoConvert( const GUID& clsidOld, GUID* pClsidNew )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleGetAutoConvert" );
		return m_Library.OleGetAutoConvert( reinterpret_cast< const IID& >( clsidOld ), reinterpret_cast< ::LPCLSID >( pClsidNew ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleSetAutoConvert( const GUID& clsidOld, const GUID& clsidNew )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleSetAutoConvert" );
		return m_Library.OleSetAutoConvert( reinterpret_cast< const IID& >( clsidOld ), reinterpret_cast< const IID& >( clsidNew ) );
	}

	//--------------------------------------------------------------------------------
	void* CCOHelper::OleMetafilePictFromIconAndLabel( CIcon::refType Icon, wchar_t* lpszLabel, wchar_t* lpszSourceFile, unsigned int iIconIndex )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleMetafilePictFromIconAndLabel" );
		return m_Library.OleMetafilePictFromIconAndLabel( reinterpret_cast< ::HICON >( Icon->Handle()->Use() ), lpszLabel, lpszSourceFile, iIconIndex );
	}

	//--------------------------------------------------------------------------------
	void* CCOHelper::OleGetIconOfFile( wchar_t* lpszPath, bool bUseFileAsLabel )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleGetIconOfFile" );
		return m_Library.OleGetIconOfFile( lpszPath, bUseFileAsLabel ? 1 : 0 );
	}

	//--------------------------------------------------------------------------------
	void* CCOHelper::OleGetIconOfClass( const GUID& rclsid, wchar_t* lpszLabel, bool bUseTypeAsLabel )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleGetIconOfClass" );
		return m_Library.OleGetIconOfClass( reinterpret_cast< const IID& >( rclsid ), lpszLabel, bUseTypeAsLabel ? 1 : 0 );
	}

	//--------------------------------------------------------------------------------
	void* CCOHelper::OleDuplicateData( void* hSrc, CLIPFORMAT cfFormat, unsigned int uiFlags )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleDuplicateData" );
		return m_Library.OleDuplicateData( hSrc, cfFormat, uiFlags );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleDraw( IUnknown* pUnknown, unsigned long dwAspect, CDeviceContext::refType dcDraw, const RECT* lprcBounds )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleDraw" );
		return m_Library.OleDraw( reinterpret_cast< ::LPUNKNOWN >( pUnknown ), dwAspect, reinterpret_cast< ::HDC >( dcDraw->Handle()->Use() ), reinterpret_cast< ::LPCRECT >( lprcBounds ) );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::OleCreateStaticFromData( IDataObject* pSrcDataObj, const GUID& iid, unsigned long renderopt, FormatEtc* pFormatEtc, IOleClientSite* pClientSite, IStorage* pStg, void** ppvObj )
	{
		_WINQ_FCONTEXT( "CCOHelper::OleCreateStaticFromData" );
		return m_Library.OleCreateStaticFromData( reinterpret_cast< ::LPDATAOBJECT >( pSrcDataObj ), reinterpret_cast< REFIID >( iid ), renderopt, reinterpret_cast< LPFORMATETC >( pFormatEtc ), reinterpret_cast< LPOLECLIENTSITE >( pClientSite ), reinterpret_cast< ::LPSTORAGE >( pStg ), ppvObj );
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::RegisterServer( CDll& Module, const GUID& clsid, const TCHAR* szFriendlyName )
	{
		_WINQ_FCONTEXT( "CCOHelper::RegisterServer" );

		long hr = E_Fail;
		CTString strModule;
		unsigned long ulResult = Module.GetFileName( strModule.GetBufferSetLength( Max_Path ), Max_Path * sizeof( TCHAR ) );
		strModule.ValidateBuffer( static_cast< unsigned short >( ulResult ) );

		CTString strFriendlyName( szFriendlyName );
		

		if( ulResult != 0 )
		{
			wchar_t* wszCLSID = 0;
			hr = StringFromCLSID( clsid, &wszCLSID );

			if( hr == 0 )
			{
				CTString strOurKey( CWString( wszCLSID ).toTString() );
				TaskMemFree( wszCLSID );

				CRegKey ClassesRoot( HKey_Classes_Root );
				CRegKey CLSIDKey( ClassesRoot, _TXT( "CLSID" ), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS );
				CLSIDKey.SetValue( strOurKey, REG_SZ, strFriendlyName.GetBuffer(), strFriendlyName.Len() * sizeof( TCHAR ) );
				CRegKey OurKey( CLSIDKey, strOurKey );
				OurKey.SetValue( _TXT("InprocServer32"), REG_SZ, strModule.GetBuffer(), strModule.Len() * sizeof( TCHAR ) );
				strModule.ReleaseBuffer();
				CRegKey InProcKey( OurKey, _TXT( "InprocServer32" ) );
				InProcKey.SetValueEx( _TXT("ThreadingModel"), REG_SZ, reinterpret_cast< const byte* >( _TXT("Apartment").c_str() ), 9 * sizeof( TCHAR ) );
			}
		}

		return hr;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::UnregisterServer( const GUID& clsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::UnregisterServer" );

		wchar_t* wszCLSID = 0;
		long hr = StringFromCLSID( clsid, &wszCLSID );

		if( hr == 0 )
		{
			CTString strCLSID( CWString( wszCLSID ).toTString() );
			TaskMemFree( wszCLSID );
			CRegKey ClassesRoot( HKey_Classes_Root );
			CRegKey CLSIDKey( ClassesRoot, _TXT( "CLSID" ), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS );

			hr = CLSIDKey.DeleteTree( strCLSID );
		}

		return hr;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::RegisterSnapin( const GUID& clsid, const TCHAR* szNameString, const GUID& clsidAbout, const TCHAR* szProvider, const bool bSupportExtensions )
	{
		_WINQ_FCONTEXT( "CCOHelper::RegisterSnapin" );
		wchar_t* wszCLSID = 0;
		CTString strCLSID;
		wchar_t* wszAboutCLSID = 0;
		CTString strAboutCLSID;
		long hr = StringFromCLSID( clsid, &wszCLSID );

		if( hr == 0 )
		{
			strCLSID = CWString( wszCLSID ).toTString();
			TaskMemFree( wszCLSID );
		}

		hr = StringFromCLSID( clsidAbout, &wszAboutCLSID );

		if( hr == 0 )
		{
			strAboutCLSID = CWString( wszAboutCLSID ).toTString();
			TaskMemFree( wszAboutCLSID );
		}

		SetSnapinKeyAndValue( strCLSID, 0, _TXT("NameString"), szNameString );
		SetSnapinKeyAndValue( strCLSID, 0, _TXT("Provider"), szProvider );
		SetSnapinKeyAndValue( strCLSID, _TXT("Standalone"), 0, 0 );

		if( clsidAbout != NULL_GUID )
		{
			SetSnapinKeyAndValue( strCLSID, 0, _TXT("About"), strAboutCLSID );
		}

		SetSnapinKeyAndValue( strCLSID, _TXT("NodeTypes"), 0, 0 );

		return hr;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::UnregisterSnapin( const GUID& clsid )
	{
		_WINQ_FCONTEXT( "CCOHelper::UnregisterSnapin" );
		wchar_t* wszCLSID = 0;
		long hr = StringFromCLSID( clsid, &wszCLSID );

		if( hr == 0 )
		{
			CTString strCLSID( CWString( wszCLSID ).toTString() );
			TaskMemFree( wszCLSID );
			CRegKey SnapInsKey( CRegKey( HKey_Local_Machine ), _TXT("SOFTWARE\\Microsoft\\MMC\\SnapIns"), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS );
			SnapInsKey.DeleteTree( strCLSID );
		}

		return hr;
	}

	//--------------------------------------------------------------------------------
	bool CCOHelper::SetSnapinKeyAndValue( const TCHAR* szKey, const TCHAR* szSubkey, const TCHAR* szName, const TCHAR* szValue )
	{
		_WINQ_FCONTEXT( "CCOHelper::SetSnapinKeyAndValue" );
		// Create and open key and subkey.
		CRegKey SnapInsKey( CRegKey( HKey_Local_Machine ), _TXT("SOFTWARE\\Microsoft\\MMC\\SnapIns"), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS );
		CRegKey OurSnapinKey( SnapInsKey, szKey );

		if( szSubkey != 0 )
		{
			CRegKey OurSnapinSubkey( OurSnapinKey, szSubkey );
		}

		if( szValue != 0 )
		{
			CTString strValue( szValue );

			OurSnapinKey.SetValueEx( szName, REG_SZ, reinterpret_cast< const byte* >( szValue ), strValue.IsEmpty() ? 0 : (strValue.Len()+1) * sizeof( TCHAR ) );
		}
		return true;
	}

	//--------------------------------------------------------------------------------
	long CCOHelper::GetMalloc( unsigned long ulMemContext, void** ppMalloc )
	{
		_WINQ_FCONTEXT( "CCOHelper::GetMalloc" );
		return m_Library.CoGetMalloc( ulMemContext, reinterpret_cast< LPMALLOC* >( ppMalloc ) );
	}

}//nsWin32
