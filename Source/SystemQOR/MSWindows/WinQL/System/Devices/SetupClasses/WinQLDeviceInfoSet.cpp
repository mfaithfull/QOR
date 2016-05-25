//WinQLDeviceInfoSet.cpp

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

#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/Application/Threading/WinQLThread.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQl/System/Devices/SetupClasses/WinQLDeviceInfoSet.h"
#include "WinQL/Definitions/Constants.h"
#include "WinQL/GUI/Window.h"
#include "WinQL/Application/Resources/WinQLResourceManager.h"
#include "WinQAPI/SetupAPI.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CDeviceInfoSet );

	//--------------------------------------------------------------------------------
	CDeviceInfoSet::CDeviceInfoSet( nsCodeQOR::mxGUID* pGuid, COSWindow* pWindow, const mxTCHAR* szMachineName ) : m_Handle( 0 )
	, m_Library( CSetupAPI::Instance() )
	, m_pGUID( pGuid )
	, m_pWindow( pWindow )
	, m_szMachine( szMachineName )
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::CDeviceInfoSet" );

		m_Handle = m_Library.SetupDiCreateDeviceInfoListEx( 
			reinterpret_cast< const ::GUID* >( pGuid ), 
			reinterpret_cast< ::HWND >( pWindow ? pWindow->Handle()->Use() : 0 ), szMachineName, 0 );
		m_Handle.Attach( this );
		Init();
	}

	//--------------------------------------------------------------------------------
	CDeviceInfoSet::CDeviceInfoSet( CTString& strEnumID ) : m_Handle( 0 )
	,	m_Library( CSetupAPI::Instance() )
	, m_pGUID( 0 )
	, m_pWindow( 0 )
	, m_szMachine( 0 )
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::CDeviceInfoSet" );
		m_Handle = m_Library.SetupDiGetClassDevs( 0, strEnumID, 0, DIGCF_ALLCLASSES | DIGCF_PRESENT );
		m_Handle.Attach( this );
		Init();
	}

	//--------------------------------------------------------------------------------
	CDeviceInfoSet::CDeviceInfoSet( nsCodeQOR::mxGUID& InterfaceGUID, unsigned long ulFlags ) : m_Handle( 0 )
	,	m_Library( CSetupAPI::Instance() )
	,	m_pGUID( & InterfaceGUID )
	,	m_pWindow( 0 )
	,	m_szMachine( 0 )
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::CDeviceInfoSet" );
		m_Handle = m_Library.SetupDiGetClassDevs( reinterpret_cast< const ::GUID* >( &InterfaceGUID ), 0, 0, ulFlags/*( DIGCF_PRESENT | DIGCF_DEVICEINTERFACE )*/ );
		m_Handle.Attach( this );
		Init();
	}

	//--------------------------------------------------------------------------------
	CDeviceInfoSet::~CDeviceInfoSet()
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::~CDeviceInfoSet" );
		m_Library.SetupDiDestroyDeviceInfoList( m_Handle.Use() );
		Uninit();
	}

	//--------------------------------------------------------------------------------
	CHandle& CDeviceInfoSet::Handle( void )
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::Handle" );
		return m_Handle;
	}

	//--------------------------------------------------------------------------------
	void CDeviceInfoSet::Uninit()
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::Uninit" );

		if( !m_Handle.IsNull() )
		{
			_Thread().ResourceManager().DeviceInfoSetHandleMap().Remove( nsCodeQOR::CTLRef< CHandle >( &m_Handle ) );
		}
	}

	//--------------------------------------------------------------------------------
	void CDeviceInfoSet::Init()
	{
		_WINQ_FCONTEXT( "CDeviceInfoSet::Init" );

		if( !( m_Handle.IsNull() ) )
		{
			_Thread().ResourceManager().DeviceInfoSetHandleMap().Add( nsCodeQOR::CTLRef< CHandle >( &m_Handle ), this );
		}
	}

}//nsWin32
