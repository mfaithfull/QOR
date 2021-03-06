//WinQLBluetoothClient.cpp

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

#include "WinQL/Application/Comms/Bluetooth/WinQLBluetoothClient.h"
#include "WinQL/Application/WinQLApplication.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CBluetoothClient );

	nsCodeQOR::mxGUID CBluetoothClient::OBEXObjectPushServiceClass_UUID		 = { 0x00001105, 0x0000, 0x1000, { 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB } };


	//--------------------------------------------------------------------------------
	CBluetoothClient::CBluetoothClient( nsCodeQOR::mxGUID& ServiceUUID ) : m_ServiceUUID( ServiceUUID )
	{
		nsQOR::IRole::ref_type Role = CWin32Application::TheWin32Application()->GetRole();
		CCommsNode* pCommsNode = Role->GetSubSystem( CCommsNode::ClassID() ).As< CCommsNode >();
		if( pCommsNode )
		{
			pCommsNode->BluetoothHost().RegisterServiceClient( ServiceUUID, this );
		}
	}

	//--------------------------------------------------------------------------------
	CBluetoothClient::~CBluetoothClient()
	{
		nsQOR::IRole::ref_type Role = CWin32Application::TheWin32Application()->GetRole();
		CCommsNode* pCommsNode = Role->GetSubSystem( CCommsNode::ClassID() ).As< CCommsNode >();

		if( pCommsNode != 0 )
		{
			pCommsNode->BluetoothHost().UnregisterServiceClient( m_ServiceUUID, this );
		}
	}

	//--------------------------------------------------------------------------------
	void CBluetoothClient::AttachDevice( CBluetoothRemoteDevice::ref_type Device )
	{
	}

}//nsWin32
