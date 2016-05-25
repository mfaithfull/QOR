//WinQLInteractiveWindowController.cpp

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
#include "WinQL/GUI/Controllers/InteractiveWindowController.h"
#include "WinQL/GUI/Window.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CInteractiveWindowController );

	//--------------------------------------------------------------------------------
	CInteractiveWindowController::CInteractiveWindowController( nsMammut::CModel* pModelItem, nsAppocrita::CCompoundController* pParent ) : CRenderedWindowController( pModelItem, pParent )
	{
		_WINQ_FCONTEXT( "CInteractiveWindowController::CInteractiveWindowController" );
	}

	//--------------------------------------------------------------------------------
	CInteractiveWindowController::~CInteractiveWindowController()
	{
		_WINQ_FCONTEXT( "CInteractiveWindowController::~CInteractiveWindowController" );
	}

	//--------------------------------------------------------------------------------
	bool CInteractiveWindowController::SetModel( nsMammut::CModel* pModelItem )
	{	
		_WINQ_FCONTEXT( "CInteractiveWindowController::SetModel" );

		Focus().SetModel( pModelItem );
		NCPointer().SetModel( pModelItem );
		Pointer().SetModel( pModelItem );
		KeyboardInput().SetModel( pModelItem );
		DragAndDrop().SetModel( pModelItem );
		IME().SetModel( pModelItem );
		Help().SetModel( pModelItem );
		Scroll().SetModel( pModelItem );
		Menu().SetModel( pModelItem );
		ClipboardOwner().SetModel( pModelItem );
		Parent().SetModel( pModelItem );
		CRenderedWindowController::SetModel( pModelItem );	
		return true;
	}

	//--------------------------------------------------------------------------------
	bool CInteractiveWindowController::ProcessMessage( COSWindow& Window, Cmp_long_ptr& lResult, unsigned int uMsg, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CInteractiveWindowController::ProcessMessage" );

		bool bProcessed = ProcessHook( Window, lResult, uMsg, wParam, lParam );

		//Pass the message through filters until it's processed
		bProcessed = 
			CRenderedWindowController::ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			NCPointer().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			Pointer().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			Parent().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			Focus().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			KeyboardInput().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			IME().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			Menu().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			Scroll().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			Help().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			DragAndDrop().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			ClipboardOwner().ProcessMessage( Window, lResult, uMsg, wParam, lParam ) ||
			CInteractiveWindowController::HandleMessage( Window, lResult, uMsg, wParam, lParam );

		return bProcessed;
	}

	//--------------------------------------------------------------------------------
	bool CInteractiveWindowController::HandleMessage( COSWindow& Window, Cmp_long_ptr& lResult, unsigned int uMsg, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		_WINQ_FCONTEXT( "CInteractiveWindowController::HandleMessage" );
		bool bHandled = false;
		return bHandled;
	}

}//nsWin32
