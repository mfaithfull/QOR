//QGPanel.cpp

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

#include "Qurses/GUI/QGPanel.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "Qurses/curses.h"
#include "Qurses/panel.h"

//--------------------------------------------------------------------------------
namespace nsQurses
{
	__QOR_IMPLEMENT_OCLASS_LUID( CQGPanel );

	//--------------------------------------------------------------------------------
	CQGPanel::CQGPanel( int iLines, int iCols, int iXPos, int iYPos ) : CQGWindow( 0, iLines, iCols, iXPos, iYPos )
	{
		__QCS_MEMBER_FCONTEXT( "CQGPanel::CQGPanel" );

		m_pPanelStruct = new_panel( m_pWindowStruct );
	}

	//--------------------------------------------------------------------------------
	CQGPanel::~CQGPanel()
	{
		__QCS_MEMBER_FCONTEXT( "CQGPanel::~CQGPanel" );

		del_panel( m_pPanelStruct );
	}

	//--------------------------------------------------------------------------------
	int CQGPanel::SendToBack()
	{
		return bottom_panel( m_pPanelStruct );
	}

	//--------------------------------------------------------------------------------
	int CQGPanel::Hide()
	{
		return hide_panel( m_pPanelStruct );
	}

	//--------------------------------------------------------------------------------
	int CQGPanel::MoveTo( int XPos, int YPos )
	{
		int iResult = move_panel( m_pPanelStruct, YPos, XPos );
		update_panels();
		return iResult;
	}

	//--------------------------------------------------------------------------------
	int CQGPanel::Hidden()
	{
		return panel_hidden( m_pPanelStruct );
	}

	//--------------------------------------------------------------------------------
	const void* CQGPanel::UserPointer()
	{
		return panel_userptr( m_pPanelStruct );
	}

	//--------------------------------------------------------------------------------
	int CQGPanel::SetUserPointer( const void* uptr )
	{
		return set_panel_userptr( m_pPanelStruct, uptr );
	}

	//--------------------------------------------------------------------------------
	int CQGPanel::Show()
	{
		return show_panel( m_pPanelStruct );
	}

}//nsQurses
