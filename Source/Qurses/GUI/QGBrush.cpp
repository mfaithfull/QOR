//QGBrush.cpp

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

#include "Qurses/GUI/QGBrush.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "Qurses/GUI/QGWindow.h"
#include "Qurses/curses.h"

//--------------------------------------------------------------------------------
namespace nsQurses
{
	__QOR_IMPLEMENT_OCLASS_LUID( CQGBrush );

	//--------------------------------------------------------------------------------
	CQGBrush::CQGBrush()
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::CQGBrush" );
	}

	//--------------------------------------------------------------------------------
	CQGBrush::~CQGBrush()
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::~CQGBrush" );
	}

	//--------------------------------------------------------------------------------
	CQGWindow* CQGBrush::Select( CQGWindow& Target )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::Select" );
		CQGWindow* pPrevTarget = m_pTarget;
		m_pTarget = &Target;
		chtype ch = static_cast< chtype >( m_usSpec );
		ch = ch << 16;
		m_pTarget->SetAttributes( ch );
		return pPrevTarget;
	}

	//--------------------------------------------------------------------------------
	CQGWindow* CQGBrush::Deselect( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::Deselect" );
		CQGWindow* pPrevTarget = m_pTarget;
		m_pTarget = 0;
		return pPrevTarget;
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetStandout( bool bStandout )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetStandout" );
		SetReverse( bStandout );
		SetBold( bStandout );
	}

	//--------------------------------------------------------------------------------
	bool CQGBrush::GetStandout( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetStandout" );
		return GetReverse() && GetBold();
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetReverse( bool )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetReverse" );
		m_usSpec |= eReverse;
	}

	//--------------------------------------------------------------------------------
	bool CQGBrush::GetReverse( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetReverse" );
		return m_usSpec & eReverse ? true : false;
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetBold( bool )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetBold" );
		m_usSpec |= eBold;
	}

	//--------------------------------------------------------------------------------
	bool CQGBrush::GetBold( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetBold" );
		return m_usSpec & eBold ? true : false;
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetDim( bool )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetDim" );
		m_usSpec = 0;
	}

	//--------------------------------------------------------------------------------
	bool CQGBrush::GetDim( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetDim" );
		return m_usSpec == 0;
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetBlink( bool )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetBlink" );
		m_usSpec |= eBlink;
	}

	//--------------------------------------------------------------------------------
	bool CQGBrush::GetBlink( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetBlink" );
		return m_usSpec & eBlink ? true : false;
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetUnderline( bool )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetUnderline" );
		m_usSpec |= eUnderline;
	}

	//--------------------------------------------------------------------------------
	bool CQGBrush::GetUnderline( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetUnderline" );
		return m_usSpec & eUnderline ? true : false;
	}

	//--------------------------------------------------------------------------------
	void CQGBrush::SetPaletteColour( unsigned char ucEntry )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::SetPaletteColour" );
		unsigned short usEntry = static_cast< unsigned short >( ucEntry );
		m_usSpec |= usEntry << 8;
	}

	//--------------------------------------------------------------------------------
	unsigned char CQGBrush::GetPaletteColour( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGBrush::GetPaletteColour" );
		unsigned char ucEntry = static_cast< unsigned char >( ( m_usSpec >> 8 ) | 0x00FF );
		return ucEntry;
	}

}//nsQurses
