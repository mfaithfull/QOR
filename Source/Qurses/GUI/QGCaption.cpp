//QGCaption.cpp

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

#include "Qurses/GUI/QGCaption.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "Qurses/GUI/QGHorizontal.h"
#include "Qurses/curses.h"

//--------------------------------------------------------------------------------
namespace nsQurses
{
	__QOR_IMPLEMENT_OCLASS_LUID( CQGCaption );

	//--------------------------------------------------------------------------------
	CQGCaption::CQGCaption( CQGWindow* pParent ) : CQGChildWindow( pParent, 1, pParent->GetWidth(), pParent->Left(), pParent->Top() )
	{
		__QCS_MEMBER_FCONTEXT( "CQGCaption::CQGCaption" );

		CQGHorizontal::refType CaptionLayout = CQGHorizontal::refType( new nsQurses::CQGHorizontal, true );
		CaptionLayout->SetXPos( 0 );
		CaptionLayout->SetYPos( 0 );
		CaptionLayout->SetWidth( pParent->GetWidth() - 2 );
		CaptionLayout->SetHeight( 1 );
		m_TitleLabel.SetText( pParent->GetWindowTitle() );
		m_TitleLabel.SetTextAlignment( CQGLabel::eCenter );
		CaptionLayout->AddItem( &m_TitleLabel );
		SetLayout( CaptionLayout );
	}

	//--------------------------------------------------------------------------------
	CQGCaption::~CQGCaption()
	{
		__QCS_MEMBER_FCONTEXT( "CQGCaption::~CQGCaption" );
	}

}//nsQurses
