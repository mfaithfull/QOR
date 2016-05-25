//WinQLUSBHostController.h

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

//Win32 USB Host Controller Device

#ifndef WINQL_DEVICE_USBHOSTCONTROLLER_H_3
#define WINQL_DEVICE_USBHOSTCONTROLLER_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterface.h"
#include "WinQL/System/Devices/WinQLIODevice.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	class __QOR_INTERFACE( __WINQL ) CUSBHub;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CUSBHostController : public CDeviceInterface
	{
	public:

		//--------------------------------------------------------------------------------
		typedef enum _USB_CONTROLLER_FLAVOR 
		{

			USB_HcGeneric   = 0,

			OHCI_Generic    = 100,
			OHCI_Hydra,
			OHCI_NEC,

			UHCI_Generic    = 200,
			UHCI_Piix4      = 201,
			UHCI_Piix3      = 202,
			UHCI_Ich2       = 203,
			UHCI_Reserved204   = 204,
			UHCI_Ich1       = 205,
			UHCI_Ich3m      = 206,
			UHCI_Ich4       = 207,
			UHCI_Ich5       = 208,
			UHCI_Ich6       = 209,

			UHCI_Intel      = 249,

			UHCI_VIA          = 250,
			UHCI_VIA_x01      = 251,
			UHCI_VIA_x02      = 252,
			UHCI_VIA_x03      = 253,
			UHCI_VIA_x04      = 254,

			UHCI_VIA_x0E_FIFO = 264,

			EHCI_Generic    = 1000,
			EHCI_NEC        = 2000,
			EHCI_Lucent     = 3000,
			EHCI_NVIDIA_Tegra2 = 4000,
			EHCI_NVIDIA_Tegra3 = 4001,
			EHCI_Intel_Medfield = 5001

		} USB_CONTROLLER_FLAVOR;

		//--------------------------------------------------------------------------------
		typedef enum _USBDEVICEINFOTYPE
		{
			HostControllerInfo,
			RootHubInfo,
			ExternalHubInfo,
			DeviceInfo
		} USBDEVICEINFOTYPE, *PUSBDEVICEINFOTYPE;

		//--------------------------------------------------------------------------------
		typedef enum _USB_USER_ERROR_CODE 
		{
			UsbUserSuccess = 0,
			UsbUserNotSupported,
			UsbUserInvalidRequestCode,
			UsbUserFeatureDisabled,
			UsbUserInvalidHeaderParameter,
			UsbUserInvalidParameter,
			UsbUserMiniportError,
			UsbUserBufferTooSmall,
			UsbUserErrorNotMapped,
			UsbUserDeviceNotStarted,
			UsbUserNoDeviceConnected

		} USB_USER_ERROR_CODE;

		//--------------------------------------------------------------------------------
		typedef struct _USBUSER_REQUEST_HEADER 
		{					
			unsigned long UsbUserRequest;				//API Requested
			USB_USER_ERROR_CODE UsbUserStatusCode;		//status code returned by port driver
			unsigned long RequestBufferLength;			//size of client input/output buffer we always use the same buffer for input and output
			unsigned long ActualBufferLength;			//size of buffer required to get all of the data

		} USBUSER_REQUEST_HEADER, *PUSBUSER_REQUEST_HEADER;

		//--------------------------------------------------------------------------------
		typedef struct _USB_CONTROLLER_INFO_0 
		{

			unsigned long PciVendorId;
			unsigned long PciDeviceId;
			unsigned long PciRevision;
			unsigned long NumberOfRootPorts;
			USB_CONTROLLER_FLAVOR ControllerFlavor;
			unsigned long HcFeatureFlags;

		} USB_CONTROLLER_INFO_0 , *PUSB_CONTROLLER_INFO_0;

		//--------------------------------------------------------------------------------
		typedef struct _USBUSER_CONTROLLER_INFO_0 
		{

			USBUSER_REQUEST_HEADER Header;
			USB_CONTROLLER_INFO_0 Info0;

		} USBUSER_CONTROLLER_INFO_0, *PUSBUSER_CONTROLLER_INFO_0;

		//--------------------------------------------------------------------------------
		typedef enum _WDMUSB_POWER_STATE 
		{

			WdmUsbPowerNotMapped = 0,

			WdmUsbPowerSystemUnspecified = 100,
			WdmUsbPowerSystemWorking,
			WdmUsbPowerSystemSleeping1,
			WdmUsbPowerSystemSleeping2,
			WdmUsbPowerSystemSleeping3,
			WdmUsbPowerSystemHibernate,
			WdmUsbPowerSystemShutdown,

			WdmUsbPowerDeviceUnspecified = 200,
			WdmUsbPowerDeviceD0,
			WdmUsbPowerDeviceD1,
			WdmUsbPowerDeviceD2,
			WdmUsbPowerDeviceD3

		} WDMUSB_POWER_STATE;

		//--------------------------------------------------------------------------------
		typedef struct _USB_POWER_INFO 
		{
			// input 
			WDMUSB_POWER_STATE SystemState;
			// output
			WDMUSB_POWER_STATE HcDevicePowerState;
			WDMUSB_POWER_STATE HcDeviceWake;
			WDMUSB_POWER_STATE HcSystemWake;

			WDMUSB_POWER_STATE RhDevicePowerState;
			WDMUSB_POWER_STATE RhDeviceWake;
			WDMUSB_POWER_STATE RhSystemWake;

			WDMUSB_POWER_STATE LastSystemSleepState;

			byte CanWakeup;
			byte IsPowered;

		} USB_POWER_INFO, *PUSB_POWER_INFO;

		//--------------------------------------------------------------------------------
		typedef struct _USBHOSTCONTROLLERINFO
		{
			USBDEVICEINFOTYPE                   DeviceInfoType;
			LIST_ENTRY                          ListEntry;
			wchar_t*							DriverKey;
			unsigned long                       VendorID;
			unsigned long                       DeviceID;
			unsigned long                       SubSysID;
			unsigned long                       Revision;
			USB_POWER_INFO                      USBPowerInfo[6];
			int                                 BusDeviceFunctionValid;
			unsigned long                       BusNumber;
			unsigned short                      BusDevice;
			unsigned short                      BusFunction;
			USB_CONTROLLER_INFO_0               ControllerInfo;
		} USBHOSTCONTROLLERINFO, *PUSBHOSTCONTROLLERINFO;

		//--------------------------------------------------------------------------------
		typedef struct _USB_HCD_DRIVERKEY_NAME 
		{
			unsigned long ActualLength;			
			wchar_t DriverKeyName[ 1 ]; // NULL terminated unicode driverkeyname for hcd
		} USB_HCD_DRIVERKEY_NAME, *PUSB_HCD_DRIVERKEY_NAME;

		//--------------------------------------------------------------------------------
		typedef struct _USB_ROOT_HUB_NAME 
		{
			unsigned long ActualLength;			
			wchar_t RootHubName[1];// NULL terminated unicode symbolic name for the root hub
		} USB_ROOT_HUB_NAME, *PUSB_ROOT_HUB_NAME;

		typedef nsCodeQOR::CTLRef< CUSBHostController > refType;


		//define USB USER request Codes

		//The following APIS are enabled always
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_CONTROLLER_INFO_0           = 0x00000001	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_CONTROLLER_DRIVER_KEY       = 0x00000002	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_PASS_THRU                       = 0x00000003	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_POWER_STATE_MAP             = 0x00000004	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_BANDWIDTH_INFORMATION       = 0x00000005	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_BUS_STATISTICS_0            = 0x00000006	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_ROOTHUB_SYMBOLIC_NAME       = 0x00000007	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_USB_DRIVER_VERSION          = 0x00000008	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_USB2_HW_VERSION             = 0x00000009	);
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_USB_REFRESH_HCT_REG             = 0x0000000a	);

		//The following APIs are only enabled when the devlopr key is set in the registry.

		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_SEND_ONE_PACKET              = 0x10000001 );

		//The following APIs are only enabled when the root hub is disabled.

		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_RAW_RESET_PORT               = 0x20000001 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_OPEN_RAW_DEVICE              = 0x20000002 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_CLOSE_RAW_DEVICE             = 0x20000003 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_SEND_RAW_COMMAND             = 0x20000004 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_SET_ROOTPORT_FEATURE            = 0x20000005 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_CLEAR_ROOTPORT_FEATURE          = 0x20000006 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_GET_ROOTPORT_STATUS             = 0x20000007 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_INVALID_REQUEST                 = 0xFFFFFFF0 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_MASK_DEVONLY_API             = 0x10000000 );
		__QCMP_STATIC_CONSTANT(	unsigned long, USBUSER_OP_MASK_HCTEST_API              = 0x20000000 ); 

		//Function codes for user mode IOCTLs

		//The following codes are valid only if passed as in the icControlCode parameter for IRP_MJ_DEVICE_CONTROL hence, they are callable by user mode applications
		__QCMP_STATIC_CONSTANT(	int, HCD_DIAGNOSTIC_MODE_ON              = 256 );
		__QCMP_STATIC_CONSTANT(	int, HCD_DIAGNOSTIC_MODE_OFF             = 257 );
		__QCMP_STATIC_CONSTANT(	int, HCD_GET_ROOT_HUB_NAME               = 258 );
		__QCMP_STATIC_CONSTANT(	int, HCD_GET_DRIVERKEY_NAME              = 265 );
		__QCMP_STATIC_CONSTANT(	int, HCD_USER_REQUEST                    = 270 );
		__QCMP_STATIC_CONSTANT(	int, HCD_TRACE_READ_REQUEST              = 275 );

		__QOR_DECLARE_OCLASS_ID( CUSBHostController );

		static nsCodeQOR::CTExternalRegEntry< CUSBHostController > RegEntry;

		__QCMP_STATIC_CONSTANT( unsigned long, File_Device_USB = 0x00000022 );

		CUSBHostController();
		virtual ~CUSBHostController();

		CUSBHub* GetRootHub( void );
		CWString GetHCDDriverKeyName( void );
		CWString GetRootHubName( void );

	private:
		
		void EnumerateRootHub( void );		
		void GetHostControllerInfo( PUSBHOSTCONTROLLERINFO hcInfo );
		
		CUSBHostController( const CUSBHostController& src );
		CUSBHostController& operator = ( const CUSBHostController& src );
		
	};

}//nsWin32

#endif//WINQL_DEVICE_USBHOSTCONTROLLER_H_3

