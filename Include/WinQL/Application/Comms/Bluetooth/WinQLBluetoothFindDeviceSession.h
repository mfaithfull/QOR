//WinQLBluetoothFindDeviceSession.h

// Copyright Querysoft Limited 2013, 2016
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

//Win32 Session over Bluetooth Find Device

#ifndef WINQL_COMMS_BLUETOOTHFINDDEVICESESSION_H_3
#define WINQL_COMMS_BLUETOOTHFINDDEVICESESSION_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQL/GUI/Window.h"
#include "WinQL/Application/Comms/Bluetooth/WinQLBluetoothRemoteDevice.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CBthProps;
}//nsWinQAPI

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CFindBluetoothDeviceSession
	{
	public:

		typedef nsCodeQOR::CTLRef< CFindBluetoothDeviceSession > refType;

		//--------------------------------------------------------------------------------
		struct SearchParams
		{
			unsigned long   dwSize;        //  IN  sizeof this structure

			int    fReturnAuthenticated;   //  IN  return authenticated devices
			int    fReturnRemembered;      //  IN  return remembered devices
			int    fReturnUnknown;         //  IN  return unknown devices
			int    fReturnConnected;       //  IN  return connected devices

			int    fIssueInquiry;          //  IN  issue a new inquiry
			unsigned char   cTimeoutMultiplier;     //  IN  timeout for the inquiry

			void*  hRadio;                 //  IN  handle to radio to enumerate - NULL == all radios will be searched
		};

		__QOR_DECLARE_OCLASS_ID( CFindBluetoothDeviceSession );
		
		CFindBluetoothDeviceSession( CFindBluetoothDeviceSession::SearchParams& SearchParams, CBluetoothRemoteDevice::ref_type Device );
		virtual ~CFindBluetoothDeviceSession();

		bool Next( CBluetoothRemoteDevice::ref_type Device );

	private:

		nsWinQAPI::CBthProps& m_Library;

		CHandle m_Handle;

		SearchParams m_SearchParams;

		CFindBluetoothDeviceSession();
		CFindBluetoothDeviceSession( const CFindBluetoothDeviceSession& );
		CFindBluetoothDeviceSession& operator = ( const CFindBluetoothDeviceSession& );
	};

}//nsWin32

#endif//WINQL_COMMS_BLUETOOTHFINDDEVICESESSION_H_3
