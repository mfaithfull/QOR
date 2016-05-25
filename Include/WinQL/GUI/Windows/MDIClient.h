//MDICLient.h

// Copyright Querysoft Limited 2013, 2015
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

//MDI Client

#ifndef WINQL_GUI_WND_MDICLIENT_H_3
#define WINQL_GUI_WND_MDICLIENT_H_3

#include "WinQL/GUI/Views/WindowView.h"
#include "WinQL/GUI/Windows/WinCtrlWindow.h"
#include "WinQL/GUI/WindowFactory.h"
#include "WinQL/GUI/Menu.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CMDIClientClass : public CWindowClass
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CMDIClientClass );

		CMDIClientClass();
		~CMDIClientClass();
		virtual bool Preregistered();
		const TCHAR* Name();

	private:

		CMDIClientClass( const CMDIClientClass& );
		CMDIClientClass& operator = ( const CMDIClientClass& );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CMDIClient : public CWinCtrlWindow
	{
	public:
		
		__QCMP_STATIC_CONSTANT( int, MDISAllChildStyles	= 0x0001 );

		__QOR_DECLARE_OCLASS_ID( CMDIClient );

		CMDIClient();
		virtual ~CMDIClient();
		virtual void Create( const TCHAR* lpWindowName, InstanceHandle hInstance, CWindowHandle::refType hWndParent, CMenuHandle::refType hMenu, unsigned long dwStyle = COSWindow::eWSOverlappedWindow, unsigned long dwExStyle = COSWindow::eWSExAppWindow, int x = CW_UseDefault, int y = CW_UseDefault, int nWidth = CW_UseDefault, int nHeight = CW_UseDefault );
		long MDIActivate( CWindowHandle::refType hChild );
		bool MDICascade( Cmp_uint_ptr Option );
		CWindowHandle::refType MDICreate( nsWin32::MDICREATESTRUCT& CreateStruct );
		void MDIDestroy( CWindowHandle::refType hChild );
		CWindowHandle::refType MDIGetActive( int* pbMaximized = 0 );
		void MDIArrageIcons();
		void MDIMaximize( CWindowHandle::refType hChild );
		void MDINext( CWindowHandle::refType hChild, bool bAfter );
		CMenuHandle::refType MDIRefreshMenu();
		void MDIRestore( CWindowHandle::refType hChild );
		CMenuHandle::refType MDISetMenu( CMenuHandle::refType hFrameMenu, CMenuHandle::refType hSysMenu );
		bool MDITile( Cmp_uint_ptr Option );
		void SetCreateStruct( CLIENTCREATESTRUCT* pCreateStruct );

	protected:

		CLIENTCREATESTRUCT* m_pCreateStruct;

	private:

		CMDIClient( const CMDIClient& );
		CMDIClient& operator = ( const CMDIClient& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CMDIClientFactory : public CWindowFactory
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CMDIClientFactory );

		CMDIClientFactory();
		~CMDIClientFactory();
		virtual CMDIClient* Create( void );

	private:

		CMDIClientFactory( const CMDIClientFactory& );
		CMDIClientFactory& operator = ( const CMDIClientFactory& );
	};

}//nsWin32

#endif//WINQL_GUI_WND_MDICLIENT_H_3
