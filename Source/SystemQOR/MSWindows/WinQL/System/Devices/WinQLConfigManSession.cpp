//WinQLConfigManSession.cpp

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
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/System/Devices/WinQLConfigManSession.h"
#include "WinQL/System/Devices/WinQLDeviceNode.h"
#include "WinQAPI/SetupAPI.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CConfigurationManagementSession );

	//--------------------------------------------------------------------------------
	CConfigurationManagementSession::CConfigurationManagementSession( CTStringRef strMachine ) : m_Library( CSetupAPI::Instance() ), m_Handle( this, 0 ), m_strMachine( *strMachine )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::CConfigurationManagementSession" );

		void* hMachine = 0;
		unsigned long ulResult = m_Library.CM_Connect_Machine( strMachine->GetNullableBuffer(), reinterpret_cast< ::PHMACHINE >( &hMachine ) );
		if( ulResult == 0 )
		{
			m_Handle = hMachine;
		}
		strMachine->ReleaseBuffer();
		m_pRootDevice = 0;
		LocateDeviceNode( CWString::TheEmptyString().Ref(), 0, &m_pRootDevice );
	}

	//--------------------------------------------------------------------------------
	CConfigurationManagementSession::~CConfigurationManagementSession()
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::~CConfigurationManagementSession" );
		delete m_pRootDevice;
		m_Library.CM_Disconnect_Machine( reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) );
	}

	//--------------------------------------------------------------------------------
	CTStringRef CConfigurationManagementSession::Machine()
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::Machine" );
		return m_strMachine.Ref();
	}

	//--------------------------------------------------------------------------------
	CDeviceNode& CConfigurationManagementSession::RootDevice( void )
	{
		return *m_pRootDevice;
	}

	//--------------------------------------------------------------------------------
	unsigned long CConfigurationManagementSession::LocateDeviceNode( CWStringRef strDeviceID, unsigned long ulFlags, CDeviceNode** ppDeviceNode )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::LocateDeviceNode" );

		unsigned long ulResult = 0;
		unsigned long ulDeviceInstance = 0;
		ulResult = m_Library.CM_Locate_DevNode_Ex( reinterpret_cast< ::PDEVINST >( &ulDeviceInstance ), reinterpret_cast< ::DEVINSTID_W >( strDeviceID->GetNullableBuffer() ), ulFlags, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) );
		if( ppDeviceNode && !*ppDeviceNode )
		{
			*ppDeviceNode = new CDeviceNode( ulDeviceInstance, *this );
		}

		return ulResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CConfigurationManagementSession::GetFirstDevNodeChild( unsigned long ulParentDevInst )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::GetFirstDevNodeChild" );

		unsigned long ulResult = 0;
		unsigned long ulDeviceInstance = 0;
		ulResult = m_Library.CM_Get_Child_Ex( reinterpret_cast< ::PDEVINST >( &ulDeviceInstance ), static_cast< ::DEVINST >( ulParentDevInst ), 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) );

		return ulDeviceInstance;
	}

	//--------------------------------------------------------------------------------
	unsigned long CConfigurationManagementSession::GetDevNodeSibling( unsigned long ulDevNode )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::GetDevNodeSibling" );

		unsigned long ulResult = 0;
		unsigned long ulDeviceInstance = 0;
		ulResult = m_Library.CM_Get_Sibling_Ex( reinterpret_cast< ::PDEVINST >( &ulDeviceInstance ), static_cast< ::DEVINST >( ulDevNode ), 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) );

		return ulDeviceInstance;
	}

	//--------------------------------------------------------------------------------
	CTString CConfigurationManagementSession::GetDeviceInstanceID( unsigned long ulDevNode )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::GetDeviceInstanceID" );

		CTString strDeviceID;
		unsigned long ulBufferCharCount = 0;
		unsigned long ulResult = m_Library.CM_Get_Device_ID_Size_Ex( &ulBufferCharCount, ulDevNode, 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) );

		if( ulBufferCharCount != 0 )
		{
			ulBufferCharCount++;
			ulResult = m_Library.CM_Get_Device_ID_Ex( ulDevNode, strDeviceID.GetBufferSetLength( static_cast< unsigned short >( ulBufferCharCount ) ), ulBufferCharCount, 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) );
			strDeviceID.ValidateBuffer( static_cast< unsigned short >( ulBufferCharCount ) );
		}
		return strDeviceID;
	}

	//--------------------------------------------------------------------------------
	CTString CConfigurationManagementSession::GetDevNodeDescription( unsigned long ulDevNode )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::GetDevNodeDescription" );

		CTString strDescription;
		unsigned long ulLength = 0;
		byte* pBuffer = reinterpret_cast< byte* >( strDescription.GetBufferSetLength( MaxPath + MaxDeviceIDLen + 1 ) );
		if( m_Library.CM_Get_DevNode_Registry_Property_Ex( ulDevNode, CM_DRP_FRIENDLYNAME, 0, pBuffer, &ulLength, 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) ) == 0 ||
			m_Library.CM_Get_DevNode_Registry_Property_Ex( ulDevNode, CM_DRP_DEVICEDESC, 0, pBuffer, &ulLength, 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) ) == 0 
			)
		{
			strDescription.ValidateBuffer( static_cast< unsigned short >( ulLength ) );
		}

		return strDescription;
	}

	//--------------------------------------------------------------------------------
	CTString CConfigurationManagementSession::GetDevNodeEnumerator( unsigned long ulDevNode )
	{
		_WINQ_FCONTEXT( "CConfigurationManagementSession::GetDevNodeEnumerator" );

		CTString strEnumeratorName;
		unsigned long ulLength = MaxDeviceIDLen;
		byte* pBuffer = reinterpret_cast< byte* >( strEnumeratorName.GetBufferSetLength( MaxDeviceIDLen + 1 ) );
		if( m_Library.CM_Get_DevNode_Registry_Property_Ex( ulDevNode, CM_DRP_ENUMERATOR_NAME, 0, pBuffer, &ulLength, 0, reinterpret_cast< ::HMACHINE >( m_Handle.Use() ) ) == 0 )
		{
			strEnumeratorName.ValidateBuffer( static_cast< unsigned short >( ulLength ) );
		}
		return strEnumeratorName;
	}

}//nsWin32
