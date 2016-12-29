//WinQLIPAddress.cpp

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

#include "CompilerQOR.h"
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usafe: stored in member for later use" );
#include "WinQL/GUI/Windows/IPAddress.h"
__QCMP_WARNING_POP

#if		( _WIN32_IE >= 0x0400 )

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CIPAddressClass );

	//--------------------------------------------------------------------------------
	CIPAddressClass::CIPAddressClass() : m_ComCtrl32( CCommonCtrl::CCINTERNET_CLASSES )
	{
		_WINQ_FCONTEXT( "CIPAddressClass::CIPAddressClass" );
	}

	//--------------------------------------------------------------------------------
	CIPAddressClass::~CIPAddressClass()
	{ 
		_WINQ_FCONTEXT( "CIPAddressClass::~CIPAddressClass" );
	}

	//--------------------------------------------------------------------------------
	bool CIPAddressClass::Preregistered()
	{ 
		_WINQ_FCONTEXT( "CIPAddressClass::Name" );
		return true; 
	}

	//--------------------------------------------------------------------------------
	const TCHAR* CIPAddressClass::Name()
	{ 
		_WINQ_FCONTEXT( "CIPAddressClass::Name" );
		return _TXT( "SysIPAddress32" ); 
	}






	__QOR_IMPLEMENT_OCLASS_LUID( CIPAddressFactory );

	//--------------------------------------------------------------------------------
	CIPAddressFactory::CIPAddressFactory() : CWindowFactory()
	{
		_WINQ_FCONTEXT( "CIPAddressFactory::CIPAddressFactory" );
	}

	//--------------------------------------------------------------------------------
	CIPAddressFactory::~CIPAddressFactory()
	{	
		_WINQ_FCONTEXT( "CIPAddressFactory::~CIPAddressFactory" );
	}

	//--------------------------------------------------------------------------------
	CIPAddress* CIPAddressFactory::Create()
	{
		_WINQ_FCONTEXT( "CIPAddressFactory::Instance" );
		return new CIPAddress;//PreCreateWindow< CIPAddress, CIPAddressClass >();
	}





	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CIPAddress );

	//--------------------------------------------------------------------------------
	CIPAddress::CIPAddress() : CWinCtrlWindow()
	{	
		_WINQ_FCONTEXT( "CIPAddress::CIPAddress" );
	}

	//--------------------------------------------------------------------------------
	CIPAddress::~CIPAddress()
	{
		_WINQ_FCONTEXT( "CIPAddress::~CIPAddress" );
	}

	//--------------------------------------------------------------------------------		
	void CIPAddress::OnCommand( unsigned short wCtrlID, unsigned short wCode )
	{
		_WINQ_FCONTEXT( "CIPAddress::OnCommand" );

		switch ( wCode )
		{
		case EN_CHANGE:
			{
				OnChange();
			}
			break;
		case EN_SETFOCUS:
			{
				OnSetFocus();
			}
			break;
		case EN_KILLFOCUS:
			{
				OnKillFocus();
			}
			break;
		default:
			{
				OnUnknownCommand( wCode );
			}
			break;
		}
	}

	//--------------------------------------------------------------------------------
	long CIPAddress::OnNotify( NotificationMessageHeader* pHdr )
	{
		_WINQ_FCONTEXT( "CIPAddress::OnNotify" );

		long lResult = 0;

		if( pHdr != 0 )
		{
			switch ( pHdr->m_uiCode )
			{
			case IPN_FIELDCHANGED:
				{
					OnFieldChanged( reinterpret_cast< NMIPADDRESS* >( pHdr ) );
				}
				break;
			default:
				{
					lResult = OnUnknownNotification( pHdr );
				}
				break;
			}
		}
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::OnChange()
	{
		_WINQ_FCONTEXT( "CIPAddress::OnChange" );
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::OnSetFocus()
	{
		_WINQ_FCONTEXT( "CIPAddress::OnSetFocus" );
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::OnKillFocus()
	{
		_WINQ_FCONTEXT( "CIPAddress::OnKillFocus" );
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::OnUnknownCommand( unsigned short wCode )
	{
		_WINQ_FCONTEXT( "CIPAddress::OnUnknownCommand" );
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::OnFieldChanged( NMIPADDRESS* pHdr )
	{
		_WINQ_FCONTEXT( "CIPAddress::OnFieldChanged" );
	}

	//--------------------------------------------------------------------------------
	long CIPAddress::OnUnknownNotification( NotificationMessageHeader* pHdr )
	{
		_WINQ_FCONTEXT( "CIPAddress::OnUnknownNotification" );
		long lResult = 0;
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::ClearAddress()
	{
		_WINQ_FCONTEXT( "CIPAddress::ClearAddress" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) IPM_CLEARADDRESS, 0, 0 );
	}

	//--------------------------------------------------------------------------------
	long CIPAddress::GetAddress( unsigned long& dwAddress )
	{
		_WINQ_FCONTEXT( "CIPAddress::GetAddress" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) IPM_GETADDRESS, 0, reinterpret_cast< Cmp_long_ptr >( &dwAddress ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	bool CIPAddress::IsBlank()
	{
		_WINQ_FCONTEXT( "CIPAddress::IsBlank" );
		bool bResult = ( m_Win32MsgHandler.Send( Ref(), (unsigned int) IPM_ISBLANK, 0, 0 ) ? true : false );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::SetAddress( unsigned long dwAddress )
	{
		_WINQ_FCONTEXT( "CIPAddress::SetAddress" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) IPM_SETADDRESS, 0, static_cast< Cmp_long_ptr >( dwAddress ) );
	}

	//--------------------------------------------------------------------------------
	void CIPAddress::SetFieldFocus( int nField )
	{
		_WINQ_FCONTEXT( "CIPAddress::SetFieldFocus" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) IPM_SETFOCUS, static_cast< Cmp_uint_ptr >( nField ), 0 );
	}

	//--------------------------------------------------------------------------------
	bool CIPAddress::SetRange( int nField, unsigned short wRange )
	{
		_WINQ_FCONTEXT( "CIPAddress::SetRange" );
		bool bResult = ( m_Win32MsgHandler.Send( Ref(), (unsigned int) IPM_SETRANGE, static_cast< Cmp_uint_ptr >( nField ), static_cast< Cmp_long_ptr >( wRange ) ) ? true : false );
		return bResult;
	}

}//nsWin32

#endif//( _WIN32_IE >= 0x0400 )