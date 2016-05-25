//WinQLProgressBar.cpp

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
#include "WinQL/GUI/Windows/ProgressBar.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CProgressBarClass );

	//--------------------------------------------------------------------------------
	CProgressBarClass::CProgressBarClass() : m_ComCtrl32( CCommonCtrl::CCPROGRESS_CLASS )
	{ 
		_WINQ_FCONTEXT( "CProgressBarClass::CProgressBarClass" );
	}

	//--------------------------------------------------------------------------------
	CProgressBarClass::~CProgressBarClass()
	{ 
		_WINQ_FCONTEXT( "CProgressBarClass::~CProgressBarClass" );
	}

	//--------------------------------------------------------------------------------
	bool CProgressBarClass::Preregistered()
	{ 
		_WINQ_FCONTEXT( "CProgressBarClass::Preregistered" );
		return true; 
	}

	//--------------------------------------------------------------------------------
	const TCHAR* CProgressBarClass::Name()
	{ 
		_WINQ_FCONTEXT( "CProgressBarClass::Name" );
		return _TXT( "msctls_progress32" ); 
	}




	__QOR_IMPLEMENT_OCLASS_LUID( CProgressBarFactory );

	//--------------------------------------------------------------------------------
	CProgressBarFactory::CProgressBarFactory() : CWindowFactory()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::CProgressBarFactory" );
	}

	//--------------------------------------------------------------------------------
	CProgressBar* CProgressBarFactory::Create()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::Instance" );
		return new CProgressBar;//PreCreateWindow< CProgressBar, CProgressBarClass >();
	}

	//--------------------------------------------------------------------------------
	CProgressBarFactory::~CProgressBarFactory()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::~CProgressBarFactory" );
	}
			
	//--------------------------------------------------------------------------------
	bool CProgressBarFactory::GetSmooth()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::GetSmooth" );
		return GetStyleBits( PBS_SMOOTH );
	}

	//--------------------------------------------------------------------------------
	void CProgressBarFactory::SetSmooth( bool bFlag )
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::SetSmooth" );
		SetStyleBits( PBS_SMOOTH, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CProgressBarFactory::GetVertical()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::GetVertical" );
		return GetStyleBits( PBS_VERTICAL );
	}

	//--------------------------------------------------------------------------------
	void CProgressBarFactory::SetVertical( bool bFlag )
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::SetVertical" );
		SetStyleBits( PBS_VERTICAL, bFlag );
	}

	//--------------------------------------------------------------------------------
	bool CProgressBarFactory::GetMarquee()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::GetMarquee" );
#if		( _WIN32_WINNT >= 0x0501 )
		return GetStyleBits( PBS_MARQUEE );
#else
		return false;
#endif//( _WIN32_WINNT >= 0x0501 )
	}

	//--------------------------------------------------------------------------------
	void CProgressBarFactory::SetMarquee( bool bFlag )
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::SetMarquee" );
#if		( _WIN32_WINNT >= 0x0501 )
		SetStyleBits( PBS_MARQUEE, bFlag );
#endif//( _WIN32_WINNT >= 0x0501 )
	}

	//--------------------------------------------------------------------------------
	bool CProgressBarFactory::GetSmoothReverse()
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::GetSmoothReverse" );
#if		( _WIN32_WINNT >= 0x0600 )
		return GetStyleBits( PBS_SMOOTHREVERSE );
#else
		return false;
#endif//( _WIN32_WINNT >= 0x06001 )
	}

	//--------------------------------------------------------------------------------
	void CProgressBarFactory::SetSmoothReverse( bool bFlag )
	{
		_WINQ_FCONTEXT( "CProgressBarFactory::SetSmoothReverse" );
#if		( _WIN32_WINNT >= 0x0600 )
		SetStyleBits( PBS_SMOOTHREVERSE, bFlag );
#endif//( _WIN32_WINNT >= 0x0600 )
	}



	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CProgressBar );

	//--------------------------------------------------------------------------------
	CProgressBar::CProgressBar() : CWinCtrlWindow()
	{	
		_WINQ_FCONTEXT( "CProgressBar::CProgressBar" );
	}

	//--------------------------------------------------------------------------------
	CProgressBar::~CProgressBar()
	{
		_WINQ_FCONTEXT( "CProgressBar::~CProgressBar" );
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::DeltaPosition( int nIncrement )
	{
		_WINQ_FCONTEXT( "CProgressBar::DeltaPosition" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_DELTAPOS, 
			static_cast< Cmp_uint_ptr >( nIncrement ), 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::GetBarColour()
	{
		_WINQ_FCONTEXT( "CProgressBar::GetBarColour" );
		long lResult = CLR_DEFAULT;
#if		( _WIN32_WINNT >= 0x0600 )
		lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_GETBARCOLOR, 0, 0 );
#endif//( _WIN32_WINNT >= 0x0600 )
		return lResult;
	}
			
	//--------------------------------------------------------------------------------
	long CProgressBar::GetBkColour()
	{
		_WINQ_FCONTEXT( "CProgressBar::GetBkColour" );
		long lResult = CLR_DEFAULT;
#if		( _WIN32_WINNT >= 0x0600 )
		lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_GETBKCOLOR, 0, 0 );
#endif//( _WIN32_WINNT >= 0x0600 )
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::GetPos()
	{
		_WINQ_FCONTEXT( "CProgressBar::GetPos" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_GETPOS, 0, 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::GetRange( bool bLowLimit, PBRANGE* pPBRange )
	{
		_WINQ_FCONTEXT( "CProgressBar::GetRange" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_GETRANGE,
			static_cast< Cmp_uint_ptr >( bLowLimit ? 1 : 0 ), 
			reinterpret_cast< Cmp_long_ptr >( pPBRange ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::GetState()
	{
		_WINQ_FCONTEXT( "CProgressBar::GetState" );
		long lResult = 0;
#if		( _WIN32_WINNT >= 0x0600 )
		lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_GETSTATE, 0, 0 );
#endif//( _WIN32_WINNT >= 0x0600 )
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::GetStep()
	{
		_WINQ_FCONTEXT( "CProgressBar::GetStep" );
		long lResult = 10;
#if		( _WIN32_WINNT >= 0x0600 )
		lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_GETSTEP, 0, 0 );
#endif//( _WIN32_WINNT >= 0x0600 )
		return lResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CProgressBar::SetBarColour( unsigned long clrBarColour )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetBarColour" );
		unsigned long Result = 0;
#if		( _WIN32_IE >= 0x0400 )
		Result = static_cast< unsigned long >(
			m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETBARCOLOR, 0, 
			static_cast< Cmp_long_ptr >( clrBarColour ) ) );
#endif//( _WIN32_IE >= 0x0400 )
		return Result;
	}

	//--------------------------------------------------------------------------------
	unsigned long CProgressBar::SetBkColour( unsigned long clrBkColour )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetBkColour" );
		unsigned long Result = 0;
#if		( _WIN32_IE >= 0x0400 )
		Result = static_cast< unsigned long >(
			m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETBKCOLOR, 0, 
			static_cast< Cmp_long_ptr >( clrBkColour ) ) );
#endif//( _WIN32_IE >= 0x0400 )
		return Result;
	}

	//--------------------------------------------------------------------------------
	void CProgressBar::SetMarquee( unsigned int uiMilliseconds, bool bOn )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetMarquee" );
#if		( _WIN32_WINNT >= 0x0501 )
		m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETMARQUEE,
			static_cast< Cmp_uint_ptr >( bOn ? 1 : 0 ), 
			static_cast< Cmp_long_ptr >( uiMilliseconds ) );
#else
		__QCMP_UNREF( bOn );
		__QCMP_UNREF( uiMilliseconds );
#endif//( _WIN32_WINNT >= 0x0501 )
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::SetPos( int iPos )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetPos" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETPOS, static_cast< Cmp_uint_ptr >( iPos ), 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::SetRange( unsigned short wMin, unsigned short wMax )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetRange" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETRANGE, 0, MakeLParam( wMin, wMax ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::SetRange32( int iMin, int iMax )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetRange32" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETRANGE32,
			static_cast< Cmp_uint_ptr >( iMin ), static_cast< Cmp_uint_ptr >( iMax ) );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::SetState( int iState )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetState" );
		long lResult = 0;
#if		( _WIN32_WINNT >= 0x0600 )
		lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETSTATE, static_cast< Cmp_uint_ptr >( iState ), 0 );
#endif//#if		( _WIN32_WINNT >= 0x0600 )
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::SetStep( int nStepInc )
	{
		_WINQ_FCONTEXT( "CProgressBar::SetStep" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_SETSTEP, static_cast< Cmp_uint_ptr >( nStepInc ), 0 );
		return lResult;
	}

	//--------------------------------------------------------------------------------
	long CProgressBar::StepIt()
	{
		_WINQ_FCONTEXT( "CProgressBar::StepIt" );
		long lResult = m_Win32MsgHandler.Send( Ref(), (unsigned int) PBM_STEPIT, 0, 0 );
		return lResult;
	}


}//nsWin32
