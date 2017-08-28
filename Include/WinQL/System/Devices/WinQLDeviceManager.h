//WinQLDeviceManager.h

// Copyright Querysoft Limited 2013, 2017
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

//Win32 Device Manager

#ifndef WINQL_DEVICEMANAGER_H_3
#define WINQL_DEVICEMANAGER_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/DataStructures/TRef.h"
#include "WinQL/Definitions/Data.h"
#include "WinQL/Definitions/IO.h"
#include "WinQL/CodeServices/WinQLPolicy.h"
#include <map>
#include "WinQL/System/Devices/WinQLDevice.h"
#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterfaceClass.h"
#include "WinQL/System/Devices/Enumerator/WinQLRootDeviceEnumerator.h"
#include "WinQL/System/Devices/SetupClasses/WinQLDeviceSetupClass.h"
#include "WinQL/System/Devices/Drivers/WinQLDeviceDriver.h"
#include "WinQL/System/Devices/WinQLConfigManSession.h"
#include "WinQL/System/Devices/WinQLDeviceNode.h"
#include "WinQL/CodeServices/Text/WinString.h"
//#include "WinQL/CodeServices/WinQLSharedRef.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQAPI ) CPSAPI;
}//nsWinQAPI

//--------------------------------------------------------------------------------
namespace nsWin32
{
	class __QOR_INTERFACE( __WINQL ) CUSBHub;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CDeviceManager
	{
	public:

		__QOR_DECLARE_REF_TYPE(CDeviceManager);
		__QOR_DECLARE_OCLASS_ID( CDeviceManager );

		typedef bool( CDeviceManager::*fpDevNodeCallback )( CDeviceNode* pNode );

		//1394 and 16883 devices
		static nsCodeQOR::mxGUID BUS1394_CLASS_GUID;
		static nsCodeQOR::mxGUID GUID_61883_CLASS;

		//Battery and ACPI devices
		static nsCodeQOR::mxGUID GUID_DEVICE_APPLICATIONLAUNCH_BUTTON;
		static nsCodeQOR::mxGUID GUID_DEVICE_BATTERY;
		static nsCodeQOR::mxGUID GUID_DEVICE_LID;
		static nsCodeQOR::mxGUID GUID_DEVICE_MEMORY;
		static nsCodeQOR::mxGUID GUID_DEVICE_MESSAGE_INDICATOR;
		static nsCodeQOR::mxGUID GUID_DEVICE_PROCESSOR;
		static nsCodeQOR::mxGUID GUID_DEVICE_SYS_BUTTON;
		static nsCodeQOR::mxGUID GUID_DEVICE_THERMAL_ZONE;

		//Bluetooth
		static nsCodeQOR::mxGUID GUID_BTHPORT_DEVICE_INTERFACE;

		//Interactive Input
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_HID;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_KEYBOARD;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_MOUSE;

		//Display and Image
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_BRIGHTNESS;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_DISPLAY_ADAPTER;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_I2C;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_IMAGE;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_MONITOR;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_OPM;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_VIDEO_OUTPUT_ARRIVAL;
		static nsCodeQOR::mxGUID GUID_DISPLAY_DEVICE_ARRIVAL;

		//Modem
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_MODEM;

		//Network
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_NET;

		//Serial and Parallel Port
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_COMPORT;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_PARALLEL;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_PARCLASS;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR;

		//Storage
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_CDCHANGER;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_CDROM;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_DISK;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_FLOPPY;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_MEDIUMCHANGER;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_PARTITION;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_STORAGEPORT;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_TAPE;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_VOLUME;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_WRITEONCEDISK;

		//USB
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_USB_DEVICE;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_USB_HOST_CONTROLLER;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_USB_HUB;

		//Windows Portable Devices
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_WPD;
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_WPD_PRIVATE;

		//Windows Slideshow
		static nsCodeQOR::mxGUID GUID_DEVINTERFACE_SLIDESHOW;


		CDeviceManager( CTStringRef refstrMachine = CTString::TheEmptyString().Ref() );
		~CDeviceManager();

		nsCodeQOR::CSTMember< CRootDeviceEnumerator > m_EnumeratorEnumerator;
		
		CDeviceNode::ref_type RootDevice( void );

		std::map< const CTString, CDeviceEnumerator::ref_type >& Enumerators( void );
		std::map< const CTString, CDeviceInstance::ref_type >& Instances( void );
		std::map< nsCodeQOR::mxGUID, CDeviceSetupClass::ref_type >& SetupClasses( void );
		std::map< nsCodeQOR::mxGUID, CDeviceInterfaceClass::ref_type >& InterfaceClasses( void );
		std::map< const CTString, CDeviceDriver::ref_type >& Drivers( void );
		
		void RegisterEnumerator( const CTString strDeivceEnumeratorName, CDeviceEnumerator::ref_type pDeviceEnumerator );
		void RegisterInstance( const CTString strDeviceInstance, CDeviceInstance::ref_type pDeviceInstance );
		void RegisterInterfaceClass( const CTString strInterfaceName, nsCodeQOR::mxGUID& GUID );
		void RegisterUSBHub( const CTString& strHubName, CUSBHub* pUSBHub ); 
	
		CUSBHub* USBHubFromName( const CTString& strHubName );
		CDeviceInstance::ref_type DeviceFromID( CTString& strDeviceID );
		CDeviceInstance::ref_type DeviceFromName( const mxTCHAR* szDeviceName );
		CDeviceEnumerator::ref_type EnumeratorFromName( CTStringRef strEnumerator );
		CDeviceInterfaceClass::ref_type InterfaceClassFromGUID( nsCodeQOR::mxGUID& GUID );

	protected:

		std::map< const CTString, CDeviceEnumerator::ref_type > m_DeviceEnumeratorCollection;
		std::map< const CTString, CDeviceInstance::ref_type > m_DeviceInstanceCollection;
		std::map< nsCodeQOR::mxGUID, CDeviceInterfaceClass::ref_type > m_DeviceInterfaceClassCollection;
		std::map< nsCodeQOR::mxGUID, CDeviceSetupClass::ref_type > m_DeviceSetupClassCollection;
		std::map< const CTString, CDeviceDriver::ref_type > m_DeviceDriverCollection;
		std::map< const CTString, CUSBHub* > m_USBHubByNameMap;

		CConfigurationManagementSession m_ConfigManagementSession;

	private:

		void RegisterKnownInterfaceClasses( void );

		void EnumerateInstances( void );
		void EnumerateSetupClasses( void );
		void EnumerateInterfaceClasses( void );
		void EnumerateDrivers( void );
		
		void WalkInstances( CDeviceNode::ref_type rootNode, fpDevNodeCallback pNodeCallback = 0 );
		bool InstanceFromNodeCallback( CDeviceNode* pDevNode );

		CTString DeviceIDFromName( const mxTCHAR* szDeviceName );		

		CTString m_strMachine;

		nsWinQAPI::CSetupAPI& m_Library;
		nsWinQAPI::CPSAPI* m_pPSAPILibrary;

		bool m_bEnumeratorsEnumerated;
		bool m_bInstancesEnumerated;
		bool m_bSetupClassesEnumerated;
		bool m_bInterfaceClassesEnumerated;
		bool m_bDriversEnumerated;

		CDeviceManager( const CDeviceManager& src );
		CDeviceManager& CDeviceManager::operator = ( const CDeviceManager& src );

	};

}//nsWin32

#endif//WINQL_DEVICEMANAGER_H_3
