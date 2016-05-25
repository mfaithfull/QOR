//WinQLDeviceInterfaceClass.cpp

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
#include "WinQL/Definitions/Constants.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterfaceClass.h"
#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterface.h"
#include "WinQL/System/Devices/Battery/WinQLBattery.h"
#include "WinQL/System/Devices/Keyboard/WinQLKeyboardDevice.h"
#include "WinQL/System/Devices/Mouse/WinQLMouse.h"
#include "WinQL/GUI/Window.h"
#include "WinQL/System/WinQLSystem.h"
#include "WinQAPI/Kernel32.h"
#include "WinQAPI/SetupAPI.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CDeviceInterfaceClass );

	//--------------------------------------------------------------------------------
	CDeviceInterfaceClass::CDeviceInterfaceClass( nsCodeQOR::__mxGUID GUID, const CTString& strInterfaceName, CTStringRef refstrMachine ) : m_GUID( GUID )
	,	m_Library( CSetupAPI::Instance() )
	,	m_strName( strInterfaceName )
	,	m_strMachine( refstrMachine.IsNull() ? CTString::TheEmptyString() : *refstrMachine )	
	,	m_bEnumerated( false )
	{
		_WINQ_FCONTEXT( "CDeviceInterfaceClass::CDeviceInterfaceClass" );
	}

	//--------------------------------------------------------------------------------
	CDeviceInterfaceClass::CDeviceInterfaceClass( const CDeviceInterfaceClass& src ) :	m_Library( CSetupAPI::Instance() )
	{
		_WINQ_FCONTEXT( "CDeviceInterfaceClass::CDeviceInterfaceClass" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CDeviceInterfaceClass& CDeviceInterfaceClass::operator = ( const CDeviceInterfaceClass& src )
	{
		_WINQ_FCONTEXT( "CDeviceInterfaceClass::operator =" );

		if( &src != this )
		{
			m_GUID = src.m_GUID;
			m_VecInterfaceInstances = src.m_VecInterfaceInstances;
			m_bEnumerated = src.m_bEnumerated;
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	CDeviceInterfaceClass::~CDeviceInterfaceClass()
	{
		_WINQ_FCONTEXT( "CDeviceInterfaceClass::~CDeviceInterfaceClass" );
	}

	//--------------------------------------------------------------------------------
	unsigned long CDeviceInterfaceClass::RegisterInterface( CDeviceInterface::refType DeviceInterface )
	{
		m_VecInterfaceInstances.push_back( DeviceInterface );
		return m_VecInterfaceInstances.size();
	}

	//--------------------------------------------------------------------------------
	std::vector< CDeviceInterface::refType >& CDeviceInterfaceClass::Interfaces( void )
	{
		if( !m_bEnumerated )
		{
			Enumerate();
		}
		return m_VecInterfaceInstances;
	}

	//--------------------------------------------------------------------------------
	CTString CDeviceInterfaceClass::Name()
	{
		return m_strName;
	}

	//--------------------------------------------------------------------------------
	nsCodeQOR::__mxGUID& CDeviceInterfaceClass::GUID()
	{
		return m_GUID;
	}

	//--------------------------------------------------------------------------------
	//Create an object for the type of interface the class represents
	CDeviceInterface* CDeviceInterfaceClass::CreateObject()
	{
		CDeviceInterface* pDeviceInterface = 0;
		nsCodeQOR::CClassInstanceFactory* pFactory = ThisModule().ExternalClassReg().GetFactory( &m_GUID );
		
		if( pFactory )
		{
			pDeviceInterface = reinterpret_cast< CDeviceInterface* >( pFactory->Instance() );
		}

		return pDeviceInterface;
	}

	//--------------------------------------------------------------------------------
	bool CDeviceInterfaceClass::IsImplemented()
	{
		nsCodeQOR::CClassInstanceFactory* pFactory = ThisModule().ExternalClassReg().GetFactory( &m_GUID );
		return pFactory ? true : false;
	}

	//--------------------------------------------------------------------------------
	void CDeviceInterfaceClass::Enumerate( void )
	{
		m_Handle = m_Library.SetupDiGetClassDevsEx( reinterpret_cast< const ::GUID* >( &m_GUID ), 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE, 0, m_strMachine.GetNullableBuffer() );
		m_strMachine.ReleaseBuffer();

		if( !m_Handle.IsNull() )
		{
			m_Handle.Attach( this );

			SP_DevInfo_Data DevInfo;
			SP_Device_Interface_Data DevInterfaceData;
			SP_Device_Interface_Detail_Data DevInterfaceDetailData;
			bool bEnumerated = false;
			unsigned long ulIndex = 0;
			do
			{	
				unsigned long ulError = 0;
				DevInterfaceData.cbSize = sizeof( ::SP_DEVICE_INTERFACE_DATA );
				if( m_Library.SetupDiEnumDeviceInterfaces( 
					reinterpret_cast< ::HDEVINFO >( m_Handle.Use() ), 0, 
					reinterpret_cast< const ::GUID* >( &m_GUID ), ulIndex, 
					reinterpret_cast< ::PSP_DEVICE_INTERFACE_DATA >( &DevInterfaceData ) ) )
				{
					unsigned long ulDeviceInterfaceDetailRequiredSize = 0;
					DevInterfaceDetailData.cbSize = sizeof( ::SP_DEVICE_INTERFACE_DETAIL_DATA );
					DevInfo.cbSize = sizeof( ::SP_DEVINFO_DATA );

					m_Library.SetupDiGetDeviceInterfaceDetail( reinterpret_cast< ::HDEVINFO >( m_Handle.Use() ),
						reinterpret_cast< ::PSP_DEVICE_INTERFACE_DATA >( &DevInterfaceData ),
						0, 0, &ulDeviceInterfaceDetailRequiredSize, 
						reinterpret_cast< ::PSP_DEVINFO_DATA >( &DevInfo ) );

					if( ulDeviceInterfaceDetailRequiredSize > 0 )
					{
						m_Library.SetupDiGetDeviceInterfaceDetail( reinterpret_cast< ::HDEVINFO >( m_Handle.Use() ),
							reinterpret_cast< ::PSP_DEVICE_INTERFACE_DATA >( &DevInterfaceData ),
							reinterpret_cast< ::PSP_DEVICE_INTERFACE_DETAIL_DATA >( &DevInterfaceDetailData ),
							ulDeviceInterfaceDetailRequiredSize, &ulDeviceInterfaceDetailRequiredSize, 
							reinterpret_cast< ::PSP_DEVINFO_DATA >( &DevInfo ) );
					}
					else
					{
						ulError = ::GetLastError();
					}
					
					CTString strDeviceInstance;
					unsigned long ulInstanceSize = 0;
					m_Library.SetupDiGetDeviceInstanceId( reinterpret_cast< ::HDEVINFO >( m_Handle.Use() ), reinterpret_cast< ::PSP_DEVINFO_DATA >( &DevInfo ), 0, 0, &ulInstanceSize );
					if( ulInstanceSize > 0 )
					{							
						m_Library.SetupDiGetDeviceInstanceId( m_Handle.Use(), reinterpret_cast< ::PSP_DEVINFO_DATA >( &DevInfo ), 
							strDeviceInstance.GetBufferSetLength( static_cast< unsigned short >( ulInstanceSize + 1 ) ), ulInstanceSize, &ulInstanceSize );
						strDeviceInstance.ValidateBuffer( static_cast< unsigned short >( ulInstanceSize ) );

					}
					else
					{
						ulError = ::GetLastError();
					}

					CTString strDeviceID;
					if( m_Library.CM_Get_Device_ID_Ex( static_cast< ::DEVINST >( DevInfo.DevInst ), strDeviceID.GetBufferSetLength( MaxDeviceIDLen + 1), MaxDeviceIDLen, 0, 0 ) != CR_SUCCESS )
					{
						ulError = ::GetLastError();
					}
					else
					{
						strDeviceID.ValidateBuffer();

						nsCodeQOR::CTLRef< CDeviceInstance > RefDevInst( CSystem::Instance().Devices(QOR_PP_SHARED_OBJECT_ACCESS).DeviceFromID( strDeviceInstance ) );

						if( RefDevInst.IsNull() )
						{
							//Device instance not enumerated. This is normal for well known Interface Class IDs on startup
							RefDevInst.Attach( new CDeviceInstance( strDeviceID, DevInfo ), true );
						}
						
						//Create the CDeviceInterface derivative
						CDeviceInterface::refType DeviceInterface( CreateObject(), true );

						if( !DeviceInterface.IsNull() )
						{
							DeviceInterface->SetActive( DevInterfaceData.Flags & SPINT_ACTIVE );
							DeviceInterface->SetDefault( DevInterfaceData.Flags & SPINT_DEFAULT ? true : false );
							DeviceInterface->SetRemoved( DevInterfaceData.Flags & SPINT_REMOVED ? true : false );
							DeviceInterface->SetPath( DevInterfaceDetailData.DevicePath );
							DeviceInterface->SetClass( this, ulIndex );
							DeviceInterface->SetInstance( RefDevInst );		//Add the device to the Interface

							m_VecInterfaceInstances.push_back( DeviceInterface );		//Add it to the Interface class
						
							if( !RefDevInst.IsNull() )							//Add it to the DeviceInstance
							{
								RefDevInst->Interfaces().push_back( DeviceInterface->Ref() );
							}
							else
							{
								//Error: Instance removed?
							}
						}
						else
						{
							//Failed to create device interface object
						}
					}

				}
				else
				{
					ulError = ::GetLastError();
					if( ulError == ERROR_NO_MORE_ITEMS )
					{
						bEnumerated = true;
					}
				}
				ulIndex++;
			}while( !bEnumerated );
		}

		m_bEnumerated = true;
	}
}//nsWin32
