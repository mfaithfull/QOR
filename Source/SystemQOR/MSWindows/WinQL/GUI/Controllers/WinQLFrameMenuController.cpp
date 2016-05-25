//WinQLFrameMenuController.cpp

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
#include "WinQL/GUI/Controllers/FrameNCController.h"
#include "WinQL/GUI/Controllers/FrameScrollController.h"
#include "WinQL/GUI/Controllers/FrameRenderingController.h"
#include "WinQL/GUI/Controllers/FrameMenuController.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CFrameMenuController );

	//--------------------------------------------------------------------------------
	CFrameMenuController::CFrameMenuController( nsMammut::CModel* pModelItem, nsAppocrita::CController* pParent ) : CMenuController( pModelItem, pParent )
	{
		_WINQ_FCONTEXT( "CFrameMenuController::CFrameMenuController" );
	}

	//--------------------------------------------------------------------------------
	CFrameMenuController::~CFrameMenuController()
	{
		_WINQ_FCONTEXT( "CFrameMenuController::~CFrameMenuController" );
	}

	//--------------------------------------------------------------------------------
	void CFrameMenuController::OnInitMenu( COSWindow& Window, CMenu::refType Menu )
	{
		_WINQ_FCONTEXT( "CFrameMenuController::OnInitMenu" );
	}

	//--------------------------------------------------------------------------------
	void CFrameMenuController::OnInitMenuPopup( COSWindow& Window, CMenu::refType Menu, unsigned short wPos, bool bWindowMenu )
	{
		_WINQ_FCONTEXT( "CFrameMenuController::OnInitMenuPopup" );
	}

	//--------------------------------------------------------------------------------
	void CFrameMenuController::OnMenuSelect( COSWindow& Window, CMenu::refType Menu, unsigned short wIndex, unsigned short wFlags )
	{
		_WINQ_FCONTEXT( "CFrameMenuController::OnMenuSelect" );
	}

}//nsWin32
