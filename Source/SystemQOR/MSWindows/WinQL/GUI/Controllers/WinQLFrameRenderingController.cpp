//WinQLFrameRenderingController.cpp

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
#include "WinQL/GUI/Controllers/FrameMenuController.h"
#include "WinQL/GUI/Controllers/FrameNCController.h"
#include "WinQL/GUI/Controllers/FrameScrollController.h"
#include "WinQL/GUI/Controllers/FrameRenderingController.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CFrameRenderingController );

	//--------------------------------------------------------------------------------
	CFrameRenderingController::CFrameRenderingController( nsMammut::CModel* pModelItem, nsAppocrita::CController* pParent ) : CRenderingController( pModelItem, pParent )
	{				
		_WINQ_FCONTEXT( "CFrameRenderingController::CFrameRenderingController" );
	}

	//--------------------------------------------------------------------------------
	CFrameRenderingController::~CFrameRenderingController()
	{
		_WINQ_FCONTEXT( "CFrameRenderingController::~CFrameRenderingController" );
	}

	//--------------------------------------------------------------------------------
	void CFrameRenderingController::OnSize( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam )
	{
		CRenderingController::OnSize( Window, wParam, lParam );

		int nType = static_cast< int > ( wParam );
		if ( nType != COSWindow::SizeMinimized )
		{
			COSWindow::refType Child = Window.Get( COSWindow::gwChild );
			while( !Child.IsNull() )
			{
                CRectangle rcChild = Window.GetClientRect();
				Child->SetPos( 0, rcChild.Left(), rcChild.Top(), LoWord( lParam ), HiWord( lParam ), 0 );
				Child = Child->Get( COSWindow::gwHWndNext );
			}
		}

	}

	//--------------------------------------------------------------------------------
	long CFrameRenderingController::OnEraseBackground( COSWindow& Window, CDeviceContext& refDC )
	{
		long lResult = 0;
		return lResult;
	}
		
	//--------------------------------------------------------------------------------
	//Notify Owned windows of the new position
    /*
	void CFrameRenderingController::LayoutOwned()
	{
		//Get Owner model
            
		COwnerView* pOwnerModel;
		if( DataPtr()->QueryInterface( COwnerView::IID_IOwnerView, (void**)&pOwnerModel ) == S_OK && pOwnerModel != 0 )
		{
			unsigned int uiOwnedCount = pOwnerModel->Count();

			if( uiOwnedCount > 0 )
			{
				unsigned int uiWindow = 0;
				for( ; uiWindow < uiOwnedCount; uiWindow++ )
				{
					COSWindow* pOwnedWindow = pOwnerModel->OwnedWindow( uiWindow );
					if( pOwnedWindow != 0 )
					{
						CController* pController = &pOwnedWindow->m_Controller();
						if( pController != 0 )
						{
							CRenderedWindowController* pRenderedWindowController = dynamic_cast< CRenderedWindowController* >( pController );
							if( pRenderedWindowController != 0 )
							{
								CRenderedWindowView* pRenderedWindowModel = pRenderedWindowController->DataPtr();
								if( pRenderedWindowModel != 0 )
								{
									CLayoutModel* pOwnedLayout = 0;
									if( pRenderedWindowModel->QueryInterface( CLayoutModel::IID_ILayoutModel, (void**)&pOwnedLayout ) == S_OK && pOwnedLayout != 0 )
									{
										if( pOwnedLayout->Layer() > 0 )
										{
											pRenderedWindowController->Rendering().OnOwnerLayoutNotify();
										}
										else if( pOwnedLayout->Layer() == 0 )
										{
											pRenderedWindowController->Rendering().OnParentLayout();
										}
										else if( pOwnedLayout->Layer() < 0 )
										{
											pRenderedWindowController->Rendering().OnParentBackgroundLayout();
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
    */

	//--------------------------------------------------------------------------------
	//Layout each child window that takes part in the layer 0 (main) layout
    /*
	void CFrameRenderingController::LayoutChildren()
	{
		//Call OnParentLayout for each Layer0 child
		//Get Parent model
		CParentView* pParentModel;
		if( DataPtr()->QueryInterface( CParentView::IID_IParentView, (void**)&pParentModel ) == S_OK && pParentModel != 0 )
		{
			unsigned int uiChildCount = pParentModel->Count();

			if( uiChildCount > 0 )
			{
				unsigned int uiWindow = 0;
				for( ; uiWindow < uiChildCount; uiWindow++ )
				{
					COSWindow* pChildWindow = pParentModel->ChildWindow( uiWindow );
					if( pChildWindow != 0 )
					{
						CController* pController = &pChildWindow->m_Controller();
						if( pController != 0 )
						{									
							CRenderedWindowController* pRenderedWindowController = dynamic_cast< CRenderedWindowController* >( pController );
							if( pRenderedWindowController != 0 )
							{
								pRenderedWindowController->Rendering().OnParentLayout();
							}
						}
					}
				}
			}
		}
	}
*/

}//nsWin32
