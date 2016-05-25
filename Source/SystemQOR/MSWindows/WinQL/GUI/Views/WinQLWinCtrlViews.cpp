//WinQLWinCtrlViews.cpp

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

//Implementation of Windows Control Views

#include "SystemQOR.h"
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: saved in member for later use" );
#include "WinQL/GUI/Views/WinCtrlViews.h"
#include "WinQL/GUI/Windows/MDIFrameWindow.h"
#include "WinQL/GUI/Controllers/MDIFrameWindowController.h"
#include "WinQL/GUI/Windows/MDIClient.h"
#include "WinQL/GUI/Views/MDIFrameView.h"
#include "WinQL/GUI/Windows/Button.h"
#include "WinQL/GUI/Windows/FrameWindow.h"
__QCMP_WARNING_POP

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	bool CHeaderView::Animate()
	{		
		/*
        WindowHandle hWndParent = ParentHandle( pParentView );

		m_WindowFactory.SetWindowClass( &m_WindowClass );
		m_pWindow = dynamic_cast< COSWindow* >( m_WindowFactory.Instance() );			
		m_WindowFactory.SetStyle( COSWindow::eWSChild | COSWindow::eWSBorder );				
		m_WindowFactory.Create( _TXT( "CCtrl Header" ), hWndParent );

        CWindowView* pView = dynamic_cast< CWindowView* >( pParentView );
		if( pView != 0 )
		{
			nsWin32::nsGraphics::CRectangle rcParent = pView->WindowPtr()->GetClientRect();
			CHeader::HDLAYOUT hdl;
			WINDOWPOS wp;
			hdl.prc = &rcParent; 
			hdl.pwpos = &wp; 

			(reinterpret_cast< CHeader* >(m_pWindow))->Layout( hdl );
			nsCodeQOR::CTLRef<COSWindow> InsertAfterRef = COSWindow::FromHandle( wp.hwndInsertAfter );
			nsWin32::nsGUI::COSWindow* pWndInsertAfter = &InsertAfterRef->OSWindow();
			m_pWindow->SetPos( pWndInsertAfter, wp.x, wp.y, wp.cx, wp.cy, wp.flags | COSWindow::swpShowWindow );
		}
		*/
		return true;

	}

    //--------------------------------------------------------------------------------
	bool CButtonView::Animate()
	{	
		/*
        WindowHandle hWndParent = ParentHandle( pParent );

		m_WindowFactory.SetWindowClass( &m_WindowClass );
		m_pWindow = dynamic_cast< COSWindow* >( m_WindowFactory.Instance() );

        //TODO: Get from Layout
		m_WindowFactory.WindowRect.Set( 5,5,120,30 );

        //TODO: Get from Style
		m_WindowFactory.SetStyle( COSWindow::eWSChild | COSWindow::eWSOverlapped | COSWindow::eWSVisible );				
		m_WindowFactory.SetCenter( true );
		m_WindowFactory.SetNotify( true );
		m_WindowFactory.SetPushlike( true );
		m_WindowFactory.SetVCenter( true );

        //TODO: Get name from Model
		m_WindowFactory.Create( _TXT( "MSW Button" ), hWndParent );
		*/
		return true;
	}			

    //--------------------------------------------------------------------------------
    bool CMDIClientView::AddChildFrame( CInteractiveWindowView* pModel )
    {
	    bool bResult = false;
        CMDIChildFrameView* pChildFrame = new CMDIChildFrameView(); 
	    pChildFrame->FrameClient.Configure( pModel );
	    int iResult = m_ListChildFrames.Append( pChildFrame );
	    bResult = ( iResult != -1 ) ? true : false;
	    return bResult;
    }

	//--------------------------------------------------------------------------------
	bool CMDIClientView::Animate()
	{
		/*
		WindowHandle hWndParent = ParentHandle( pParentView );

		if( pParentView != 0 )
		{
			CMDIFrameView* pMDIParent = dynamic_cast< CMDIFrameView* >( pParentView );
			if( pMDIParent != 0 )
			{
				CMenuModel& MenuModel = pMDIParent->m_Menu();
				CMenu* pMenu = MenuModel.Menu();
				if( pMenu != 0 )
				{
                    //Special MDI Client menu hookup
					int iItemCount = pMenu->GetItemCount();
					MenuHandle hWindowMenu = pMenu->GetSubMenu( iItemCount - 1 );
					m_ClientCreateStruct.hWindowMenu = hWindowMenu;
					m_ClientCreateStruct.idFirstChild = 0xFF00;
				}
			}
		}

		m_WindowFactory.SetWindowClass( &m_WindowClass );
		m_WindowFactory.SetParameter( &m_ClientCreateStruct );
        m_WindowFactory.SetView( this );
		m_pWindow = dynamic_cast< COSWindow* >( m_WindowFactory.Instance() );
        m_pWindow->m_Controller.Configure( m_pController );

        CWindowView* pBaseView = dynamic_cast< CWindowView* >( pParentView );

        nsWin32::nsGraphics::CRectangle rcChild;
        if( pBaseView )
        {
            rcChild = pBaseView->WindowPtr()->GetClientRect();
        }

		m_WindowFactory.WindowRect.Set( 0,0,rcChild.Width(),rcChild.Height() );
		m_WindowFactory.SetStyle( nsWin32::nsGUI::COSWindow::eWSVisible | COSWindow::eWSChild | COSWindow::eWSClipChildren | nsWin32::nsGUI::COSWindow::eWSClipSiblings | CMDIClient::MDISAllChildStyles );
		m_WindowFactory.SetStyleEx( COSWindow::eWSExClientEdge );
		m_WindowFactory.Create( _TXT(""), hWndParent );
		m_pWindow->BringToTop();

	    CParentView* pParentingView = 0;
            
	    if( pBaseView != 0 )
	    {
            pBaseView->QueryInterface( CParentView::IID_IParentView, (void**)&pParentingView );
	    }

	    if( pParentingView != 0 )
	    {
		    pParentingView->RegisterChildWindow( m_pWindow );
	    }	
        	
	    for( int iItemIndex = 1; iItemIndex <= m_ListChildFrames.GetCount(); iItemIndex++ )
	    {
		    m_ListChildFrames.GetItem( iItemIndex )->Animate( this );
	    }
        */

		return true;
	}	

	//--------------------------------------------------------------------------------
	bool CStatusBarView::Animate()
	{	
		/*
		WindowHandle hWndParent = ParentHandle( pParentView );

		CWindowView* pBaseView = dynamic_cast< CWindowView* >( pParentView );

		CParentView* pParentingView = 0;
		if( pBaseView )
		{
            pBaseView->QueryInterface( CParentView::IID_IParentView, (void**)&pParentingView );
		}


		m_WindowFactory.SetWindowClass( &m_WindowClass );
		m_pWindow = dynamic_cast< COSWindow* >( m_WindowFactory.Instance() );
		//StatusBarController().Rendering.Configure( &RenderingController() );
		//m_pWindow->m_Controller.Configure( &StatusBarController() );
		if( pParentingView != 0 )
		{
			pParentingView->RegisterChildWindow( m_pWindow );
		}
		m_WindowFactory.SetStyle( COSWindow::eWSChild | COSWindow::eWSVisible | COSWindow::eWSClipSiblings );				

		m_pWindow->Controller().SetModel( GetModel() );
		m_WindowFactory.Create( _TXT( "CCtrl Status Bar" ), hWndParent );

		CStatusBar* pStatusBar = reinterpret_cast< CStatusBar* >( m_pWindow );

		m_bToolTips = m_WindowFactory.GetToolTips();
		//Set basic parameters
		pStatusBar->SetUnicodeFormat( m_bUnicodeFormat );
		pStatusBar->SetBkColour( m_BackgroundColour );
		//Set simple mode data
		pStatusBar->SetSimple( true );
		pStatusBar->SetText( CStatusPart::SP_SIMPLEID, m_SimpleModePart.GetType(), m_SimpleModePart.GetText() );
		nsWin32::nsGUI::CIcon* pIcon = m_SimpleModePart.GetIcon();
		if( pIcon != 0 )
		{
			pStatusBar->SetIcon( -1, pIcon->Handle() );
		}
		//Set mode
		pStatusBar->SetSimple( m_bSimpleMode );

		//Set full part data if necessary
		if( m_apParts.Size() > 0 )
		{
			int nParts = m_apParts.Size();
			if( nParts > 256 )
			{
				nParts = 256;
			}

			int* paRightCoord = new int[ nParts ];

			int iPart = 0;
			int iWidth = 0;
			for( iPart = 0; iPart < nParts; iPart++ )
			{
				iWidth += m_apParts[iPart]->GetSize();
				paRightCoord[ iPart ] = iWidth;
			}

			pStatusBar->SetParts( nParts, paRightCoord );

			delete [] paRightCoord;

			for( iPart = 0; iPart < nParts; iPart++ )
			{
				pStatusBar->SetIcon( iPart, m_apParts[ iPart ]->GetIcon()->Handle() );
				pStatusBar->SetText( iPart, m_apParts[ iPart ]->GetType(), m_apParts[ iPart ]->GetText() );
				if( m_bToolTips )
				{
					pStatusBar->SetTipText( iPart, m_apParts[ iPart ]->GetTipText() );
				}
			}
		}
		*/
		return true;
	}

	//--------------------------------------------------------------------------------
	bool CFrameWindowView::Animate()
	{
		bool bResult = false;
		/*
		m_WindowClass().Preinitialise();
		m_WindowFactory().SetWindowClass( &( m_WindowClass() ) );

		m_WindowFactory().SetParameter( this );
        m_WindowFactory().SetView( this );
		m_pWindow = dynamic_cast< COSWindow* >( m_WindowFactory().Instance() );
		m_pWindow->m_Controller.Configure( m_pController );

		m_WindowFactory().SetStyle( nsWin32::nsGUI::COSWindow::eWSOverlappedWindow );
		m_WindowFactory().WindowRect.Set( 32, 32, 300, 200 );

		m_WindowFactory().Create( _TXT( "WRT Test Application #1" ), 0 );			

        m_pWindow->Show( COSWindow::swShow );
		*/
		bResult = true;

		return bResult;
	}

}//nsWin32
