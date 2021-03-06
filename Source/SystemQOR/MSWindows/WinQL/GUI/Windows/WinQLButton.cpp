//WinQLButton.cpp

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
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: stored in member for later use" )
#include "WinQL/GUI/Windows/Button.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CButtonClass );

	//--------------------------------------------------------------------------------
	CButtonClass::CButtonClass()
	{
		_WINQ_FCONTEXT( "CButtonClass::CButtonClass" );
	}

	//--------------------------------------------------------------------------------
	CButtonClass::~CButtonClass()
	{
		_WINQ_FCONTEXT( "CButtonClass::~CButtonClass" );
	}

	//--------------------------------------------------------------------------------
	bool CButtonClass::Preregistered()
	{ 
		_WINQ_FCONTEXT( "CButtonClass::Preregistered" );
		return true; 
	}

	//--------------------------------------------------------------------------------
	const TCHAR* CButtonClass::Name()
	{ 
		_WINQ_FCONTEXT( "CButtonClass::Name" );
		return _TXT( "BUTTON" ); 
	}


	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CButtonFactory );

	//--------------------------------------------------------------------------------
	CButtonFactory::CButtonFactory() : CWindowFactory()
	{
		_WINQ_FCONTEXT( "CButtonFactory::CButtonFactory" );
	}

	//--------------------------------------------------------------------------------
	CButton* CButtonFactory::Create()
	{
		_WINQ_FCONTEXT( "CButtonFactory::Instance" );
		return new CButton;//PreCreateWindow< CButton, CButtonClass >();
	}

	//--------------------------------------------------------------------------------
	CButtonFactory::~CButtonFactory()
	{				
		_WINQ_FCONTEXT( "CButtonFactory::~CButtonFactory" );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetDefault()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetDefault" );
		return GetStyleBits( BS_DEFPUSHBUTTON );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetDefault( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetDefault" );
		SetStyleBits( BS_DEFPUSHBUTTON, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetCheckBox()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetCheckBox" );
		return GetStyleBits( BS_CHECKBOX );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetCheckBox( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetCheckBox" );
		SetStyleBits( BS_CHECKBOX, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetAutoCheckBox()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetAutoCheckBox" );
		return GetStyleBits( BS_AUTOCHECKBOX );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetAutoCheckBox( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetAutoCheckBox" );
		SetStyleBits( BS_AUTOCHECKBOX, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetRadioButton()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetRadioButton" );
		return GetStyleBits( BS_RADIOBUTTON );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetRadioButton( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetRadioButton" );
		SetStyleBits( BS_RADIOBUTTON, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::Get3State()
	{
		_WINQ_FCONTEXT( "CButtonFactory::Get3State" );
		return GetStyleBits( BS_3STATE );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::Set3State( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::Set3State" );
		SetStyleBits( BS_3STATE, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetAuto3State()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetAuto3State" );
		return GetStyleBits( BS_AUTO3STATE );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetAuto3State( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetAuto3State" );
		SetStyleBits( BS_AUTO3STATE, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetGroupBox()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetGroupBox" );
		return GetStyleBits( BS_GROUPBOX );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetGroupBox( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetGroupBox" );
		SetStyleBits( BS_GROUPBOX, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetUserButton()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetUserButtony" );
		return GetStyleBits( BS_USERBUTTON );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetUserButton( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetUserButton" );
		SetStyleBits( BS_USERBUTTON, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetAutoRadioButton()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetAutoRadioButton" );
		return GetStyleBits( BS_AUTORADIOBUTTON );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetAutoRadioButton( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetAutoRadioButton" );
		SetStyleBits( BS_AUTORADIOBUTTON, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetPushBox()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetPushBox" );
		return GetStyleBits( BS_PUSHBOX );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetPushBox( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetPushBox" );
		SetStyleBits( BS_PUSHBOX, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetOwnerDraw()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetOwnerDraw" );
		return GetStyleBits( BS_OWNERDRAW );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetOwnerDraw( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetOwnerDraw" );
		SetStyleBits( BS_OWNERDRAW, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetTypeMask()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetTypeMask" );
		return GetStyleBits( BS_TYPEMASK );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetTypeMask( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetTypeMask" );
		SetStyleBits( BS_TYPEMASK, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetLeftText()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetLeftText" );
		return GetStyleBits( BS_LEFTTEXT );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetLeftText( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetLeftText" );
		SetStyleBits( BS_LEFTTEXT, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetIcon()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetIcon" );
		return GetStyleBits( BS_ICON );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetIcon( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetIcon" );
		SetStyleBits( BS_ICON, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetBitmap()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetBitmap" );
		return GetStyleBits( BS_BITMAP );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetBitmap( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetBitmap" );
		SetStyleBits( BS_BITMAP, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetLeft()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetLeft" );
		return GetStyleBits( BS_LEFT );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetLeft( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetLeft" );
		SetStyleBits( BS_LEFT, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetRight()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetRight" );
		return GetStyleBits( BS_RIGHT );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetRight( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetRight" );
		SetStyleBits( BS_RIGHT, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetCenter()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetCenter" );
		return GetStyleBits( BS_CENTER );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetCenter( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetCenter" );
		SetStyleBits( BS_CENTER, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetTop()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetTop" );
		return GetStyleBits( BS_TOP );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetTop( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetTop" );
		SetStyleBits( BS_TOP, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetBottom()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetBottom" );
		return GetStyleBits( BS_BOTTOM );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetBottom( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetBottom" );
		SetStyleBits( BS_BOTTOM, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetVCenter()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetBCenter" );
		return GetStyleBits( BS_VCENTER );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetVCenter( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetVCenter" );
		SetStyleBits( BS_VCENTER, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetPushlike()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetPushLike" );
		return GetStyleBits( BS_PUSHLIKE );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetPushlike( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetPushLike" );
		SetStyleBits( BS_PUSHLIKE, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetMultiline()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetMultiline" );
		return GetStyleBits( BS_MULTILINE );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetMultiline( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetMultiline" );
		SetStyleBits( BS_MULTILINE, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetNotify()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetNotify" );
		return GetStyleBits( BS_NOTIFY );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetNotify( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetNotify" );
		SetStyleBits( BS_NOTIFY, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CButtonFactory::GetFlat()
	{
		_WINQ_FCONTEXT( "CButtonFactory::GetFlat" );
		return GetStyleBits( BS_FLAT );
	}

	//--------------------------------------------------------------------------------
	void CButtonFactory::SetFlat( bool bFlag )
	{
		_WINQ_FCONTEXT( "CButtonFactory::SetFlat" );
		SetStyleBits( BS_FLAT, bFlag );
	}



	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CButton );

	//--------------------------------------------------------------------------------
	CButton::CButton() : CWinCtrlWindow()
	{				
		_WINQ_FCONTEXT( "CButton::CButton" );
	}

	//--------------------------------------------------------------------------------
	CButton::~CButton()
	{
		_WINQ_FCONTEXT( "CButton::~CButton" );
	}
			

	//--------------------------------------------------------------------------------
	void CButton::OnBCNDropDown( NMBCDROPDOWN* pNMDropDown )
	{
		_WINQ_FCONTEXT( "CButton::OnBCNDropDown" );
	}

	//--------------------------------------------------------------------------------
	void CButton::OnHotItemChange( NMBCHOTITEM* pNMHotItem )
	{
		_WINQ_FCONTEXT( "CButton::OnHotItemChange" );
	}

	//--------------------------------------------------------------------------------
	void CButton::OnCommand( unsigned short wCtrlID, unsigned short wCode )
	{
		_WINQ_FCONTEXT( "CButton::OnCommand" );
		switch ( wCode )
		{
		case BN_CLICKED:
			{
				OnClicked();
			}
			break;
		case BN_PAINT:
			{
				OnPaint();
			}
			break;
		case BN_HILITE://BN_PUSHED
			{
				OnPushed();
			}
			break;
		case BN_UNHILITE://BN_UNPUSHED
			{
				OnUnpushed();
			}
			break;
		case BN_DISABLE:
			{
				OnDisable();
			}
			break;
		case BN_DOUBLECLICKED://BN_DBLCLK
			{
				OnDblClicked();
			}
			break;
		case BN_SETFOCUS:
			{
				OnSetFocus();
			}
			break;
		case BN_KILLFOCUS:
			{
				OnKillFocus();
			}
			break;
		}
	}

	//--------------------------------------------------------------------------------
	long CButton::OnNotify( NotificationMessageHeader* pHdr )
	{
		_WINQ_FCONTEXT( "CButton::OnNotify" );
		long lResult = 0;
		if( pHdr != 0 )
		{
			switch ( pHdr->m_uiCode )
			{
#if		( _WIN32_WINNT >= 0x0600 )
			case BCN_DROPDOWN:
				{
					NMBCDROPDOWN* pNMDropDown = reinterpret_cast< NMBCDROPDOWN* >( pHdr );
					OnBCNDropDown( pNMDropDown );
				}
				break;
#endif//( _WIN32_WINNT >= 0x0600 )
#if		( _WIN32_WINNT >= 0x0501 )
			case BCN_HOTITEMCHANGE:
				{
						NMBCHOTITEM* pNMHotItem = reinterpret_cast< NMBCHOTITEM* >( pHdr );
						OnHotItemChange( pNMHotItem );
				}
				break;				
#endif//( _WIN32_WINNT >= 0x0501 )
			case NM_CUSTOMDRAW:
				{
						NMCustomDraw* pCustomDraw = reinterpret_cast< NMCustomDraw* >( pHdr );
						lResult = OnCustomDraw( pCustomDraw );
				}
				break;
			}
		}
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CButton::OnCustomDraw( NMCustomDraw* pCustomDraw )
	{
		_WINQ_FCONTEXT( "CButton::OnCustomDraw" );
		long lResult = 0;
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CButton::Click()
	{
		_WINQ_FCONTEXT( "CButton::Click" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_CLICK, 0, 0 ); 
	}

	//--------------------------------------------------------------------------------
	long CButton::GetCheck()
	{
		_WINQ_FCONTEXT( "CButton::GetCheck" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_GETCHECK, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CButton::SetCheck( Cmp_uint_ptr Check )
	{
		_WINQ_FCONTEXT( "CButton::SetCheck" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_SETCHECK, Check, 0 ); 
	}

	//--------------------------------------------------------------------------------
	long CButton::GetState()
	{
		_WINQ_FCONTEXT( "CButton::GetState" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_GETSTATE, 0, 0 );  
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CButton::SetState( Cmp_uint_ptr State )
	{
		_WINQ_FCONTEXT( "CButton::SetState" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_SETSTATE, State, 0 );
	}

	//--------------------------------------------------------------------------------
	void CButton::SetStyle( Cmp_uint_ptr Style, int bRedraw )
	{
		_WINQ_FCONTEXT( "CButton::SetStyle" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_SETSTYLE, Style, static_cast< Cmp_long_ptr >( bRedraw ) );
	}

	//--------------------------------------------------------------------------------
	CIconHandle::refType CButton::GetIcon()
	{
		_WINQ_FCONTEXT( "CButton::GetIcon" );
		void* pInnerHandle = (void*)( m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_GETIMAGE, IMAGE_ICON, 0 ) );
		CIconHandle::refType Result( new CIconHandle( 0, pInnerHandle ), true ); 
		Result->AsHandle().Attach( CIcon::FromHandle( Result ) );
		return Result;
	}

	//--------------------------------------------------------------------------------
	CBitmapHandle::refType CButton::GetBitmap()
	{
		_WINQ_FCONTEXT( "CButton::GetBitmap" );
		void* pInnerHandle = (void*)(m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_GETIMAGE, IMAGE_BITMAP, 0 ) );
		CBitmapHandle::refType Result( new CBitmapHandle( 0, pInnerHandle ), true );
		Result->AsHandle().Attach( CBitmap::FromHandle( Result ) );
		return Result;
	}

	//--------------------------------------------------------------------------------
	CIconHandle::refType CButton::SetIcon( CIconHandle::refType hIcon )
	{
		_WINQ_FCONTEXT( "CButton::SetIcon" );
		void* pInnerHandle = (void*)( m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_SETIMAGE, IMAGE_ICON, reinterpret_cast< Cmp_long_ptr >( hIcon->Use() ) ) );
		CIconHandle::refType Result( new CIconHandle( 0, pInnerHandle ), true );
		Result->AsHandle().Attach( CIcon::FromHandle( Result ) );
		return Result;
	}

	//--------------------------------------------------------------------------------
	CBitmapHandle::refType CButton::SetBitmap( CBitmapHandle::refType hBitmap )
	{
		_WINQ_FCONTEXT( "CButton::SetBitmap" );
		void* pInnerHandle = (void*)( m_Win32MsgHandler.Send( Ref(), (unsigned int) BM_SETIMAGE, IMAGE_BITMAP, reinterpret_cast< Cmp_long_ptr >( hBitmap->Use() ) ) );
		CBitmapHandle::refType Result( new CBitmapHandle( 0, pInnerHandle ), true );
		Result->AsHandle().Attach( CBitmap::FromHandle( Result ) );
		return Result;
	}

}//nsWin32

