//QGChildWindow.h

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

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "Qurses/QursesPolicy.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"
#include "Qurses/GUI/QGWindow.h"

#ifndef QURSES_GUI_CHILDWINDOW_H_3
#define	QURSES_GUI_CHILDWINDOW_H_3

//--------------------------------------------------------------------------------
namespace nsQurses
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( QURSES_QOR ) CQGChildWindow : public CQGWindow, public CQGLayoutItem
	{

	public:		

		__QOR_DECLARE_OCLASS_ID( CQGChildWindow );

		CQGChildWindow( CQGWindow* pParent, int iLines, int iCols, int iXPos, int iYPos );
		virtual ~CQGChildWindow();

		virtual int MoveTo( int XPos, int YPos );
		
		virtual unsigned int GetMaxWidth( void );
		virtual unsigned int GetMinWidth( void );
		virtual unsigned int GetPreferedWidth( void );
		virtual unsigned int GetMaxHeight( void );
		virtual unsigned int GetMinHeight( void );
		virtual unsigned int GetPreferedHeight( void );
		
		virtual unsigned int GetWidth( void );
		virtual unsigned int GetHeight( void );

		virtual void SetMaxWidth( unsigned int );
		virtual void SetMinWidth( unsigned int );
		virtual void SetMaxHeight( unsigned int );
		virtual void SetMinHeight( unsigned int );
		virtual bool SetWidth( unsigned int );
		virtual bool SetHeight( unsigned int );
		
		virtual void SetMargins( unsigned int uiLeft, unsigned int uiTop, unsigned int uiRight, unsigned int uiBottom );
		virtual void GetMargins( unsigned int& uiLeft, unsigned int& uiTop, unsigned int& uiRight, unsigned int& uiBottom );

		virtual unsigned int GetXPos( void );
		virtual unsigned int GetYPos( void );
		virtual void SetXPos( unsigned int );
		virtual void SetYPos( unsigned int );

		virtual bool Layout( void );
		virtual void Paint( void );

	protected:

		CQGWindow* m_pParent;
	};

}//nsQurses

#endif//QURSES_GUI_WINDOW_H_3

