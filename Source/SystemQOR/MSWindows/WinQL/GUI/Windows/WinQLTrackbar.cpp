//WinQLTrackbar.cpp

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
#include "WinQL/GUI/Windows/Trackbar.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CTrackbarClass );

	//--------------------------------------------------------------------------------
	CTrackbarClass::CTrackbarClass() : CCommonCtrlClass( CCommonCtrl::CCBAR_CLASSES, _TXT( "msctls_trackbar32" ) )
	{
		_WINQ_FCONTEXT( "CTrackbarClass::CTrackbarClass" );
	}

	//--------------------------------------------------------------------------------
	CTrackbarClass::~CTrackbarClass()
	{
		_WINQ_FCONTEXT( "CTrackbarClass::~CTrackbarClass" );
	}





	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CTrackbarFactory );

	//--------------------------------------------------------------------------------
	CTrackbarFactory::CTrackbarFactory() : CCommonCtrlFactory< CTrackbar >()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::CTrackbarFactory" );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetAutoTicks()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetAutoTicks" );
		return GetStyleBits( TBS_AUTOTICKS );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetAutoTicks( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetAutoTicks" );
		SetStyleBits( TBS_AUTOTICKS, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetVertical()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetVertical" );
		return GetStyleBits( TBS_VERT );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetVertical( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetVertical" );
		SetStyleBits( TBS_VERT, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetHorizontal()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetHorizontal" );
		return !GetStyleBits( TBS_VERT );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetHorizontal( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetHorizontal" );
		SetStyleBits( TBS_VERT, !bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetTop()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetTop" );
		return GetStyleBits( TBS_TOP );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetTop( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetTop" );
		SetStyleBits( TBS_TOP, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetBottom()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetBottom" );
		return !GetStyleBits( TBS_TOP );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetBottom( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetBottom" );
		SetStyleBits( TBS_TOP, !bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetLeft()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetLeft" );
		return GetStyleBits( TBS_LEFT );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetLeft( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetLeft" );
		SetStyleBits( TBS_LEFT, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetRight()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetRight" );
		return !GetStyleBits( TBS_LEFT );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetRight( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetRight" );
		SetStyleBits( TBS_LEFT, !bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetBoth()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetBoth" );
		return GetStyleBits( TBS_BOTH );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetBoth( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetBoth" );
		SetStyleBits( TBS_BOTH, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetNoTicks()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GeTNoTicks" );
		return GetStyleBits( TBS_NOTICKS );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetNoTicks( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetNoTicks" );
		SetStyleBits( TBS_NOTICKS, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetEnableSelRange()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetEnableSelRange" );
		return GetStyleBits( TBS_ENABLESELRANGE );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetEnableSelRange( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetEnableSelRange" );
		SetStyleBits( TBS_ENABLESELRANGE, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetFixedLength()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetFixedLength" );
		return GetStyleBits( TBS_FIXEDLENGTH );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetFixedLength( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetFixedLength" );
		SetStyleBits( TBS_FIXEDLENGTH, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetNoThumb()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetNoThumb" );
		return GetStyleBits( TBS_NOTHUMB );
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetNoThumb( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetNoThumb" );
		SetStyleBits( TBS_NOTHUMB, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetToolTips()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetToolTips" );
		bool bResult = false;
#if		( _WIN32_IE >= 0x0300 )
		bResult = GetStyleBits( TBS_TOOLTIPS );
#endif//( _WIN32_IE >= 0x0300 )
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetToolTips( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetToolTips" );
#if		( _WIN32_IE >= 0x0300 )
		SetStyleBits( TBS_TOOLTIPS, bFlag );
#else
		__QCMP_UNREF( bFlag );
#endif//( _WIN32_IE >= 0x0300 )
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetReversed()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetReversed" );
		bool bResult = false;
#if		( _WIN32_IE >= 0x0500 )
		bResult = GetStyleBits( TBS_REVERSED );
#endif//( _WIN32_IE >= 0x0500 )
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetReversed( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetReversed" );
#if		( _WIN32_IE >= 0x0500 )
		SetStyleBits( TBS_REVERSED, bFlag );
#else
		__QCMP_UNREF( bFlag );
#endif//( _WIN32_IE >= 0x0500 )
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetDownIsLeft()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetDownIsLeft" );
		bool bResult = false;
#if		( _WIN32_IE >= 0x0501 )
		bResult = GetStyleBits( TBS_DOWNISLEFT );
#endif//( _WIN32_IE >= 0x0501 )
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetDownIsLeft( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetDownIsLeft" );
#if		( _WIN32_IE >= 0x0501 )
		SetStyleBits( TBS_DOWNISLEFT, bFlag );
#else
		__QCMP_UNREF( bFlag );
#endif//( _WIN32_IE >= 0x0501 )
	}


	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetNotifyBeforeMove()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetNotifyBeforeMove" );
		bool bResult = false;
#if		( _WIN32_IE >= 0x0600 )
		bResult = GetStyleBits( TBS_NOTIFYBEFOREMOVE );
#endif//( _WIN32_IE >= 0x0600 )
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetNotifyBeforeMove( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetNotifyBeforeMove" );
#if		( _WIN32_IE >= 0x0600 )
		SetStyleBits( TBS_NOTIFYBEFOREMOVE, bFlag );
#else
		__QCMP_UNREF( bFlag );
#endif//( _WIN32_IE >= 0x0600 )
	}

	//--------------------------------------------------------------------------------
	bool CTrackbarFactory::GetTransparentBackground()
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::GetTransparentBackground" );
		bool bResult = false;
#if		( NTDDI_VERSION >= NTDDI_VISTA )
		bResult = GetStyleBits( TBS_TRANSPARENTBKGND );
#endif//( NTDDI_VERSION >= NTDDI_VISTA )
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbarFactory::SetTransparentBackground( bool bFlag )
	{
		_WINQ_FCONTEXT( "CTrackbarFactory::SetTransparentBackground" );
#if		( NTDDI_VERSION >= NTDDI_VISTA )
		SetStyleBits( TBS_TRANSPARENTBKGND, bFlag );
#else
		__QCMP_UNREF( bFlag );
#endif//( NTDDI_VERSION >= NTDDI_VISTA )
	}

		
		
		
	
	__QOR_IMPLEMENT_OCLASS_LUID( CTrackbar );

	//--------------------------------------------------------------------------------
	CTrackbar::CTrackbar() : CWinCtrlWindow()
	{	
		_WINQ_FCONTEXT( "CTrackbar::CTrackbar" );
	}

	//--------------------------------------------------------------------------------
	CTrackbar::~CTrackbar()
	{
		_WINQ_FCONTEXT( "CTrackbar::~CTrackbar" );
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::OnNotify( NotificationMessageHeader* pHdr )
	{
		_WINQ_FCONTEXT( "CTrackbar::OnNotify" );

		long lResult = 0;

		if( pHdr != 0 )
		{
			switch ( pHdr->m_uiCode )
			{
			case NM_CUSTOMDRAW:
				{
					lResult = OnCustomDraw( reinterpret_cast< NMCustomDraw* >( pHdr ) );
				}
				break;
#if		( _WIN32_IE >= 0x0400 )
			case NM_RELEASEDCAPTURE:
				{
					OnReleasedCapture( pHdr );
				}
				break;
#endif//( _WIN32_IE >= 0x0400 )
#if		( _WIN32_WINNT >= 0x0600 )
			case TRBN_THUMBPOSCHANGING:
				{
					OnThumbPosChanging( reinterpret_cast< NMTRBTHUMBPOSCHANGING* >( pHdr ) );
				}
				break;
#endif//( _WIN32_WINNT >= 0x0600 )
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
	long CTrackbar::OnCustomDraw( NMCustomDraw* pHdr )
	{
		_WINQ_FCONTEXT( "CTrackbar::OnCustomDraw" );
		QOR_PP_UNREF( pHdr );
		long lResult = CDRF_DODEFAULT;
		return lResult;
	}

	//--------------------------------------------------------------------------------		
	void CTrackbar::OnReleasedCapture( NotificationMessageHeader* pHdr )
	{
		_WINQ_FCONTEXT( "CTrackbar::OnReleaseCapture" );
		QOR_PP_UNREF( pHdr );
	}

	//--------------------------------------------------------------------------------		
	void CTrackbar::OnThumbPosChanging( NMTRBTHUMBPOSCHANGING* pHdr )
	{
		_WINQ_FCONTEXT( "CTrackbar::OnThumbPosChanging" );
		QOR_PP_UNREF( pHdr );
	}

	//--------------------------------------------------------------------------------		
	long CTrackbar::OnUnknownNotification( NotificationMessageHeader* pHdr )
	{
		_WINQ_FCONTEXT( "CTrackbar::OnUnknownNotification" );
		QOR_PP_UNREF( pHdr );
		long lResult = 0;
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::ClearSel( bool bRedraw )
	{				
		_WINQ_FCONTEXT( "CTrackbar::ClearSel" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_CLEARSEL,
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), 0 );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::ClearTicks( bool bRedraw )
	{				
		_WINQ_FCONTEXT( "CTrackbar::ClearTicks" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_CLEARTICS,
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), 0 );
	}

	//--------------------------------------------------------------------------------
	COSWindow::refType CTrackbar::GetBuddy( bool bLocation )
	{	
		_WINQ_FCONTEXT( "CTrackbar::GetBuddy" );
		return COSWindow::FromHandle( CWindowHandle::refType( new CWindowHandle( 0, (void* )( m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETBUDDY, static_cast< Cmp_uint_ptr >( bLocation ? 1 : 0 ), 0 ) ) ), true ) );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::GetChannelRect( CRectangle& rcChannel )
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetChannelRect" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETCHANNELRECT,
			0, reinterpret_cast< Cmp_long_ptr >( &rcChannel ) );
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetLineSize()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetLineSize" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETLINESIZE, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetNumTicks()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetNumTicks" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETNUMTICS, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetPageSize()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetPageSize" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETPAGESIZE, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetPos()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetPos" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETPOS, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long* CTrackbar::GetPosTicks()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetPosTicks" );
		unsigned long* pdwResult = reinterpret_cast< unsigned long* >(
			m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETPTICS, 0, 0 ) );
		return pdwResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetRangeMax()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetRangeMax" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETRANGEMAX, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetRangeMin()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetRangeMin" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETRANGEMIN, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetSelEnd()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetSelEnd" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETSELEND, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetSelStart()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetSelStart" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETSELSTART, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetThumbLength()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetThumbLength" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETTHUMBLENGTH, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetThumbRect( CRectangle& rcThumb )
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetThumbRect" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETTHUMBRECT, 0, 
			reinterpret_cast< Cmp_long_ptr >( &rcThumb ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetTick( unsigned short wTick )
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetTick" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETTIC, 
			static_cast< Cmp_uint_ptr >( wTick ), 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::GetTickPos( unsigned short wTick )
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetTickPos" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETTICPOS, 
			static_cast< Cmp_uint_ptr >( wTick ), 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	COSWindow::refType CTrackbar::GetToolTips()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetToolTips" );
		return COSWindow::FromHandle( CWindowHandle::refType( new CWindowHandle( 0, (void*)( m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETTOOLTIPS, 0, 0 ) ) ) ) );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbar::GetUnicodeFormat()
	{				
		_WINQ_FCONTEXT( "CTrackbar::GetUnicodeFormat" );
		bool bResult = false;
#if		( _WIN32_IE >= 0x0400 )
		bResult = ( m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_GETUNICODEFORMAT, 0, 0 ) ? true : false );
#endif//( _WIN32_IE >= 0x0400 )
		return bResult;
	}

	//--------------------------------------------------------------------------------
	COSWindow::refType CTrackbar::SetBuddy( bool bLocation, COSWindow::refType Buddy )
	{			
		_WINQ_FCONTEXT( "CTrackbar::SetBuddy" );
		return COSWindow::FromHandle( CWindowHandle::refType( new CWindowHandle( 0, (void*)( m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETBUDDY,  static_cast< Cmp_uint_ptr >( bLocation ? 1 : 0 ), reinterpret_cast< Cmp_long_ptr >( Buddy->Handle()->Use() ) ) ) ), true ) );
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::SetLineSize( long lLineSize )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetLineSize" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETLINESIZE, 
			0, static_cast< Cmp_long_ptr >( lLineSize ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::SetPageSize( long lPageSize )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetPageSize" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETPAGESIZE, 
			0, static_cast< Cmp_long_ptr >( lPageSize ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetPos( bool bRedraw, long lPos )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetPos" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETPOS, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), static_cast< Cmp_long_ptr >( lPos ) );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetRange( bool bRedraw, unsigned short wMin, unsigned short wMax )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetRange" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETRANGE, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), MakeLong( wMin, wMax ) );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetRangeMax( bool bRedraw, long lMax )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetRangeMax" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETRANGEMAX, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), lMax );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetRangeMin( bool bRedraw, long lMin )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetRangeMin" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETRANGEMIN, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), lMin );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetSel( bool bRedraw, unsigned short wMin, unsigned short wMax )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetSel" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETSEL, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), MakeLong( wMin, wMax ) );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetSelEnd( bool bRedraw, long lEnd )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetSelEnd" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETSELEND, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), lEnd );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetSelStart( bool bRedraw, long lStart )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetSelStart" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETSELSTART, 
			static_cast< Cmp_uint_ptr >( bRedraw ? 1 : 0 ), lStart );
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetThumbLength( unsigned int uiLength )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetThumbLength" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETTHUMBLENGTH, 
			static_cast< Cmp_uint_ptr >( uiLength ), 0 );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbar::SetTic( long lPosition )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetTic" );
		bool bResult = ( m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETTIC, 0, lPosition ) ? true : false );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetTicFrequency( unsigned short wFreq )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetTicFrequency" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETTICFREQ, 
			static_cast< Cmp_uint_ptr >( wFreq ), 0 );
	}

	//--------------------------------------------------------------------------------
	long CTrackbar::SetTipSide( int iLocation )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetTipSide" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETTIPSIDE, 
			static_cast< Cmp_uint_ptr >( iLocation ), 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	void CTrackbar::SetToolTips( COSWindow::refType ToolTips )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetToolTips" );
		m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETTOOLTIPS, 
			reinterpret_cast< Cmp_uint_ptr >( ToolTips->Handle()->Use() ), 0 );
	}

	//--------------------------------------------------------------------------------
	bool CTrackbar::SetUnicodeFormat( bool bUnicode )
	{				
		_WINQ_FCONTEXT( "CTrackbar::SetUnicodeFormat" );
		bool bResult = false;
#if		( _WIN32_IE >= 0x0400 )
		bResult = ( m_Win32MsgHandler.Send( Ref(), (unsigned int) TBM_SETUNICODEFORMAT, 
			static_cast< Cmp_uint_ptr >( bUnicode ? 1 : 0 ), 0 ) ? true : false );
#endif//( _WIN32_IE >= 0x0400 )
		return bResult;
	}

}//nsWin32

