//WinQLKeyboardInputController.cpp

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
#include "WinQL/GUI/Controllers/Parts/KeyboardInputController.h"
#include "WinQL/GUI/Window.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CKeyboardInputController );

	//--------------------------------------------------------------------------------
	CKeyboardInputController::CKeyboardInputController( nsMammut::CModel* pModelItem, nsAppocrita::CController* pParent ) : CBaseWindowPartController( pModelItem, pParent )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::CKeyboardInputController" );
	}

	//--------------------------------------------------------------------------------
	CKeyboardInputController::~CKeyboardInputController()
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::~CKeyboardInputController" );
	}

	//--------------------------------------------------------------------------------
	bool CKeyboardInputController::ProcessMessage( COSWindow& Window, Cmp_long_ptr& lResult, unsigned int uMsg, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::ProcessMessage" );

		bool bProcessed = ProcessHook( Window, lResult, uMsg, wParam, lParam );

		switch ( uMsg )
		{
		case COSWindow::wmInputLangChangeRequest:
			{
				OnInputLangChangeRequest( Window, wParam, lParam );
				bProcessed = true;
			}
			break;
		case COSWindow::wmInputLangChange:
			{
				OnInputLangChange( Window, wParam, lParam );
				lResult = 1;
				bProcessed = true;
			}
		case COSWindow::wmKeyDown:
			{
				OnKeyDown( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmKeyUp:
			{
				OnKeyUp( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmChar:
			{
				OnChar( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmDeadChar:
			{
				OnDeadChar( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmSysKeyDown:
			{
				OnSysKeyDown( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmSysKeyUp:
			{
				OnSysKeyUp( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmSysChar:
			{
				OnSysChar( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
		case COSWindow::wmSysDeadChar:
			{
				OnSysDeadChar( Window, wParam, lParam );
				lResult = 0;
				bProcessed = true;
			}
			break;
		case COSWindow::wmCommand:
			{
				unsigned short wCode = HiWord( wParam );
					
				if( wCode == 1 )
				{
					unsigned short wAccelID = LoWord( wParam );						
					OnCommand( Window, wAccelID );
					lResult = 0;
					bProcessed = true;
				}
			}
			break;
		//case WM_KEYLAST:
		}

		return bProcessed;
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnInputLangChangeRequest( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnInputLangChangeRequest" );
		Window.DefProc( COSWindow::wmInputLangChangeRequest, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnInputLangChange( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnInputLangChange" );
		Window.DefProc( COSWindow::wmInputLangChange, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnKeyDown( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnKeyDown" );
		Window.DefProc( COSWindow::wmKeyDown, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnKeyUp( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnKeyUp" );
		Window.DefProc( COSWindow::wmKeyUp, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnChar( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnChar" );
		Window.DefProc( COSWindow::wmChar, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnDeadChar( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnDeadChar" );
		Window.DefProc( COSWindow::wmDeadChar, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnSysKeyDown( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnSysKeyDown" );
		Window.DefProc( COSWindow::wmSysKeyDown, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnSysKeyUp( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnSysKeyUp" );
		Window.DefProc( COSWindow::wmSysKeyUp, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnSysChar( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnSysChar" );
		Window.DefProc( COSWindow::wmSysChar, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnSysDeadChar( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnSysDeadChar" );
		Window.DefProc( COSWindow::wmSysDeadChar, wParam, lParam );
	}

	//--------------------------------------------------------------------------------
	void CKeyboardInputController::OnCommand( COSWindow& Window, unsigned short wAccelID )
	{
		_WINQ_FCONTEXT( "CKeyboardInputController::OnCommand" );
	}

}//nsWin32

