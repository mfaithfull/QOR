//WinQLDisplay.cpp

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

#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "CompilerQOR.h"
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: stored in member for later use" )
#include "WinQL/Application/Graphics/WinQLDisplay.h"
__QCMP_WARNING_POP
#include "WinQL/System/Info/WinQLInfo.h"
#include "WinQAPI/User32.h"

#undef AddMonitor		//Kill the leaked AddMonitor(A/W) definition from Windows headers
#undef EnumMonitors

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CDisplayHelper );

	//--------------------------------------------------------------------------------
	CDisplayHelper::CDisplayHelper() : m_User32Library( CUser32::Instance() )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::CDisplayHelper" );
	}

	//--------------------------------------------------------------------------------
	CDisplayHelper::~CDisplayHelper()
	{
		_WINQ_FCONTEXT( "CDisplayHelper::~CDisplayHelper" );
	}

	//--------------------------------------------------------------------------------
	long CDisplayHelper::ChangeSettings( nsWin32::LPDEVMODE lpDevMode, unsigned long dwflags )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::ChangeSettings" );
		LONG lResult = 0;
		__QOR_PROTECT
		{
			lResult = m_User32Library.ChangeDisplaySettings( reinterpret_cast< ::LPDEVMODE >( lpDevMode ), dwflags );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CDisplayHelper::ChangeSettings( const TCHAR* lpszDeviceName, nsWin32::LPDEVMODE lpDevMode, COSWindow::refType Window, unsigned long dwflags, void* lParam )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::ChangeSettings" );
		LONG lResult = 0;
		__QOR_PROTECT
		{
			lResult = m_User32Library.ChangeDisplaySettingsEx( lpszDeviceName, reinterpret_cast< ::LPDEVMODE >( lpDevMode ), reinterpret_cast< ::HWND >( Window->Handle()->Use() ), dwflags, lParam );
		}__QOR_ENDPROTECT
		return lResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::EnumDevices( const TCHAR* lpDevice, unsigned long iDevNum, nsWin32::PDISPLAY_DEVICE lpDisplayDevice, unsigned long dwFlags )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::EnumDevices" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.EnumDisplayDevices( lpDevice, iDevNum, reinterpret_cast< ::PDISPLAY_DEVICE >( lpDisplayDevice ), dwFlags ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::EnumSettings( const TCHAR* lpszDeviceName, unsigned long iModeNum, nsWin32::LPDEVMODE lpDevMode, unsigned long dwFlags )
	{				
		_WINQ_FCONTEXT( "CDisplayHelper::EnumSettings" );
		bool bResult = false;
		__QOR_PROTECT
		{
			if( dwFlags == 0 )
			{
				bResult = m_User32Library.EnumDisplaySettings( lpszDeviceName, iModeNum, reinterpret_cast< ::LPDEVMODE >( lpDevMode ) ) ? true : false;
			}
			else
			{
				bResult = m_User32Library.EnumDisplaySettingsEx( lpszDeviceName, iModeNum, reinterpret_cast< ::LPDEVMODE >( lpDevMode ), dwFlags ) ? true : false;
			}
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::EnumDisplayMonitors( CDeviceContext::refType dc, const nsWin32::RECT* lprcClip, nsWin32::MONITORENUMPROC lpfnEnum, Cmp_long_ptr dwData )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::EnumDisplayMonitors" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.EnumDisplayMonitors( dc.IsNull() ? 0 : reinterpret_cast< ::HDC >( dc->Handle()->Use() ), reinterpret_cast< const ::RECT* >( lprcClip ), reinterpret_cast< ::MONITORENUMPROC >( lpfnEnum ), dwData ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::SetProcessDPIAware()
	{
		_WINQ_FCONTEXT( "CDisplayHelper::SetProcessDPIAware" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.SetProcessDPIAware() ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::GetProcessDefaultLayout( unsigned long* pdwDefaultLayout )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::GetProcessDefaultLayout" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.GetProcessDefaultLayout( pdwDefaultLayout ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::SetProcessDefaultLayout( unsigned long dwDefaultLayout )
	{
		_WINQ_FCONTEXT( "CDisplayHelper::SetProcessDefaultLayout" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.SetProcessDefaultLayout( dwDefaultLayout ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplayHelper::IsProcessDPIAware()
	{
		_WINQ_FCONTEXT( "CDisplayHelper::IsProcessDPIAware" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.IsProcessDPIAware() ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}



	//--Monitor-----------------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CMonitorHelper );

#include "CompilerQOR.h"
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: stored in member for later use" )

	//--------------------------------------------------------------------------------
	CMonitorHelper::CMonitorHelper( const CMonitorHelper& Monitor ) : m_User32Library( CUser32::Instance() )
	,	m_Handle( this, 0 )
	{
		_WINQ_FCONTEXT( "CMonitorHelper::CMonitorHelper" );
		m_Handle = Monitor.m_Handle.AsHandle().ptr();
	}

	//--------------------------------------------------------------------------------
	CMonitorHelper::CMonitorHelper( CMonitorHandle::refType hMonitor ) : m_User32Library( CUser32::Instance() )
	,	m_Handle( this, 0 )
	{
		_WINQ_FCONTEXT( "CMonitorHelper::CMonitorHelper" );
		m_Handle = hMonitor->AsHandle().ptr();
	}

	//--------------------------------------------------------------------------------
	CMonitorHelper::CMonitorHelper( nsWin32::POINT pt, unsigned long dwFlags ) : m_User32Library( CUser32::Instance() )
	,	m_Handle( this, 0 )
	{
		_WINQ_FCONTEXT( "CMonitorHelper::CMonitorHelper" );
		__QOR_PROTECT
		{
			m_Handle = ( m_User32Library.MonitorFromPoint( *(reinterpret_cast< ::POINT* >( &pt ) ), dwFlags ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CMonitorHelper::CMonitorHelper( const nsWin32::RECT* lprc, unsigned long dwFlags ) : m_User32Library( CUser32::Instance() )
	,	m_Handle( this, 0 )
	{
		_WINQ_FCONTEXT( "CMonitorHelper::CMonitorHelper" );
		__QOR_PROTECT
		{
			m_Handle = ( m_User32Library.MonitorFromRect( reinterpret_cast< ::LPCRECT >( lprc ), dwFlags ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CMonitorHelper::CMonitorHelper( COSWindow::refType Window, unsigned long dwFlags ) : m_User32Library( CUser32::Instance() )
	,	m_Handle( this, 0 )
	{
		_WINQ_FCONTEXT( "CMonitorHelper::CMonitorHelper" );
		__QOR_PROTECT
		{
			m_Handle = ( m_User32Library.MonitorFromWindow( reinterpret_cast< ::HWND >( Window->Handle()->Use() ), dwFlags ) );
		}__QOR_ENDPROTECT
	}

__QCMP_WARNING_POP

	//--------------------------------------------------------------------------------
	CMonitorHelper::~CMonitorHelper()
	{
		_WINQ_FCONTEXT( "CMonitorHelper::~CMonitorHelper" );
	}

	//--------------------------------------------------------------------------------
	bool CMonitorHelper::GetInfo( nsWin32::LPMONITORINFO lpmi )
	{
		_WINQ_FCONTEXT( "CMonitorHelper::GetInfo" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_User32Library.GetMonitorInfo( reinterpret_cast< ::HMONITOR >( m_Handle.Use() ), reinterpret_cast< ::LPMONITORINFO >( lpmi ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}


	//--------------------------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CDisplay );

	//--------------------------------------------------------------------------------
	CDisplay::CDisplay() : m_bDevicesEnumerated( false ), m_bMonitorsEnumerated( false )
	{
		_WINQ_FCONTEXT( "CDisplay::CDisplay" );
	}

	//--------------------------------------------------------------------------------
	CDisplay::~CDisplay()
	{
		_WINQ_FCONTEXT( "CDisplay::~CDisplay" );
	}

	//--------------------------------------------------------------------------------
	CDisplay::CDevice CDisplay::DefaultDevice()
	{
		if( !m_bDevicesEnumerated )
		{
			EnumDevices();
		}
		return m_Devices[ 0 ];
	}

	//--------------------------------------------------------------------------------
	CDisplay::CDevice CDisplay::Device( unsigned int uiDevice )
	{
		if( !m_bDevicesEnumerated )
		{
			EnumDevices();
		}
		return m_Devices[ uiDevice ];		
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor& CDisplay::Monitor( unsigned int uiMonitor )
	{
		if( !m_bMonitorsEnumerated )
		{
			EnumAllMonitors();
		}
		return (*m_apMonitors[ uiMonitor ]);
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor CDisplay::MonitorFromPoint( nsWin32::POINT pt, unsigned long dwFlags )
	{
		CMonitor aMonitor( pt, dwFlags );
		return aMonitor;
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor CDisplay::MonitorFromRect( const CRectangle* lprc, unsigned long dwFlags )
	{
		CMonitor aMonitor( lprc, dwFlags );
		return aMonitor;
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor CDisplay::MonitorFromWindow( COSWindow::refType Window, unsigned long dwFlags )
	{
		CMonitor aMonitor( Window, dwFlags );
		return aMonitor;
	}

	//--------------------------------------------------------------------------------
	long CDisplay::ChangeSettingsForDefaultDevice( nsWin32::LPDEVMODE lpDevMode, unsigned long dwflags )
	{
		long lResult = 0;
		lResult = m_Win32DisplayHelper.ChangeSettings( lpDevMode, dwflags );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplay::EnumMonitors( CDeviceContext::refType dc, const CRectangle* lprcClip, nsWin32::MONITORENUMPROC lpfnEnum, Cmp_long_ptr dwData )
	{
		bool bResult = false;
		bResult = m_Win32DisplayHelper.EnumDisplayMonitors( dc, lprcClip, lpfnEnum, dwData );
		return bResult;
	}			

	//--------------------------------------------------------------------------------
	bool CDisplay::EnumAllMonitors()
	{
		_WINQ_FCONTEXT( "CDisplay::EnumAllMonitors" );
		bool bResult = false;
		bResult = m_Win32DisplayHelper.EnumDisplayMonitors( 0, 0, reinterpret_cast< nsWin32::MONITORENUMPROC >( &CDisplay::EnumMonitorProc ), reinterpret_cast<Cmp_long_ptr>( this ) );
		m_bMonitorsEnumerated = true;
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool __QCMP_STDCALLCONVENTION CDisplay::EnumMonitorProc( void* hMonitor, void* phdcMonitor, LPRECT lprcMonitor, Cmp_long_ptr dwData )
	{
		_WINQ_SFCONTEXT( "CDisplay::EnumMonitorProc" );
		bool bResult = false;
		CDisplay* pThis = reinterpret_cast< CDisplay* >( dwData );
		CDeviceContext::refType refDC = CDeviceContext::FromHandle( CDCHandle( 0, phdcMonitor ).Ref() );
		bResult = pThis->AddMonitor( hMonitor, refDC, lprcMonitor );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplay::AddMonitor( void* hMonitor, CDeviceContext::refType dcMonitor, LPRECT lprcMonitor )
	{
		_WINQ_FCONTEXT( "CDisplay::AddMonitor" );
		bool bResult = false;
		CMonitor* pMonitor = new CMonitor( CMonitorHandle( 0, hMonitor ).Ref() );
		m_apMonitors.Append( pMonitor );
		bResult = true;
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CDisplay::EnumDevices()
	{
		_WINQ_FCONTEXT( "CDisplay::EnumDevices" );

		CSystemInfo Info;
		unsigned long dwMajorVersion = Info.GetMajorVersion();
		bool bResult = false;

#		if( WINVER >= 0x0500 )
		if( dwMajorVersion > 4 )
		{
			unsigned long iDevNum = 0;
				
			do
			{
				CDevice DisplayDevice;
				bResult = m_Win32DisplayHelper.EnumDevices( 0, iDevNum, &DisplayDevice, CDisplayHelper::_EDD_GET_DEVICE_INTERFACE_NAME );
				if( bResult == true )
				{
					DisplayDevice.m_bInitialised = true;
					m_Devices.Append( DisplayDevice );
				}
				iDevNum++;
			}while( bResult == true );
			m_bDevicesEnumerated = true;
		}
		else
		{
#		else
			CDevice DisplayDevice;
			m_Devices.Append( DisplayDevice );
#		endif
#		if( WINVER >= 0x0500 )
		}
#		endif

		return bResult;
	}





	__QOR_IMPLEMENT_OCLASS_LUID( CDisplay::CDevice )

	//--------------------------------------------------------------------------------
	CDisplay::CDevice::CDevice() : m_bInitialised( false )
	{				
		_WINQ_FCONTEXT( "CDisplay::CDevice::CDevice" );
		cb = sizeof( nsWin32::DISPLAY_DEVICE );
		StateFlags = 0;
	}

	//--------------------------------------------------------------------------------
	CDisplay::CDevice::CDevice( const CDisplay::CDevice& src )
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::CDevice" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CDisplay::CDevice::~CDevice()
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::~CDevice" );
	}

	//--------------------------------------------------------------------------------
	CDisplay::CDevice& CDisplay::CDevice::operator=( const CDevice& Src )
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::operator =" );
		cb = Src.cb;
		memcpy( DeviceName, Src.DeviceName, 32 * sizeof( TCHAR ) );
		memcpy( DeviceString, Src.DeviceString, 128 * sizeof( TCHAR ) );
		StateFlags = Src.StateFlags;
		memcpy( DeviceID, Src.DeviceID, 128 * sizeof( TCHAR ) );
		memcpy( DeviceKey, Src.DeviceKey, 128 * sizeof( TCHAR ) );
		return *this;
	}

	//--------------------------------------------------------------------------------
	bool CDisplay::CDevice::EnumSettings( unsigned long iModeNum, nsWin32::LPDEVMODE lpDevMode, unsigned long dwFlags )
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::EnumSettings" );
		bool bResult = false;
		if( m_bInitialised )
		{
			bResult = m_Win32DisplayHelper.EnumSettings( DeviceName, iModeNum, lpDevMode, dwFlags );
		}
		else
		{
			bResult = m_Win32DisplayHelper.EnumSettings( 0, iModeNum, lpDevMode, 0 );
		}
		return bResult;
	}

	//--------------------------------------------------------------------------------
	long CDisplay::CDevice::ChangeSettings( nsWin32::LPDEVMODE lpDevMode, COSWindow::refType Window, unsigned long dwflags, void* lParam )
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::ChangeSettings" );
		long lResult = 0;
		lResult = m_Win32DisplayHelper.ChangeSettings( DeviceName, lpDevMode, Window, dwflags, lParam );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	CTString CDisplay::CDevice::GetDeviceID()
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::GetDeviceID" );
		CTString strDeviceID( DeviceID, 128 );
		return strDeviceID;
	}

	//--------------------------------------------------------------------------------
	CTString CDisplay::CDevice::GetDeviceString()
	{
		_WINQ_FCONTEXT( "CDisplay::CDevice::GetDeviceString" );
		CTString strDeviceString( DeviceString, 128 );
		return strDeviceString;
	}



	__QOR_IMPLEMENT_OCLASS_LUID( CDisplay::CMonitor )

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor::CMonitor( const CDisplay::CMonitor& Monitor ) : m_Win32Monitor( Monitor.m_Win32Monitor )
	{
		_WINQ_FCONTEXT( "CDisplay::CMonitor::CMonitor" );
		*( dynamic_cast< nsWin32::MONITORINFO* >( this ) ) = Monitor;
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor::CMonitor( CMonitorHandle::refType hMonitor ) : m_Win32Monitor( hMonitor )
	{
		_WINQ_FCONTEXT( "CDisplay::CMonitor::CMonitor" );
		cbSize = sizeof( nsWin32::MONITORINFO );
		m_Win32Monitor.GetInfo( this );
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor::CMonitor( nsWin32::POINT pt, unsigned long dwFlags ) : m_Win32Monitor( pt, dwFlags )
	{
		_WINQ_FCONTEXT( "CDisplay::CMonitor::CMonitor" );
		cbSize = sizeof( nsWin32::MONITORINFO );
		m_Win32Monitor.GetInfo( this );
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor::CMonitor( const CRectangle* lprc, unsigned long dwFlags ) : m_Win32Monitor( lprc, dwFlags )
	{
		_WINQ_FCONTEXT( "CDisplay::CMonitor::CMonitor" );
		cbSize = sizeof( nsWin32::MONITORINFO );
		m_Win32Monitor.GetInfo( this );
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor::CMonitor( COSWindow::refType Window, unsigned long dwFlags ) : m_Win32Monitor( Window, dwFlags )
	{
		_WINQ_FCONTEXT( "CDisplay::CMonitor::CMonitor" );
		cbSize = sizeof( nsWin32::MONITORINFO );
		m_Win32Monitor.GetInfo( this );
	}

	//--------------------------------------------------------------------------------
	bool CDisplay::CMonitor::IsPrimary()
	{
		return ( dwFlags & MONITORINFOF_PRIMARY ) ? true : false;
	}

	//--------------------------------------------------------------------------------
	CDisplay::CMonitor::~CMonitor()
	{
		_WINQ_FCONTEXT( "CDisplay::CMonitor::~CMonitor" );
	}


}//nsWin32
