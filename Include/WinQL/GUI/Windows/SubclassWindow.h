//SubclassWindow.h

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

//A class for overriding an existing window type by message interception

#ifdef	__QCMP_OPTIMIZEINCLUDE
		__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef WINQL_WND_SUBCLASS_H_3
#define WINQL_WND_SUBCLASS_H_3

#include "WinQL/GUI/Views/WindowView.h"
#include "WinQL/GUI/Window.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CSubclassWindow : public COSWindow
	{
		
	public:

		__QOR_DECLARE_OCLASS_ID( CSubclassWindow );

		CSubclassWindow();
		CSubclassWindow( CWindowClass* pClass, void* pParam = 0 );
		virtual ~CSubclassWindow();
		bool Hook();
		bool Unhook();

		static Cmp_long_ptr __QCMP_STDCALLCONVENTION SubclassProc( CWindowHandle::refType hWnd, unsigned int uMsg, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );

		Cmp_long_ptr MsgProc( CWindowHandle::refType hWnd, unsigned int uMsg, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );

	protected:

		WNDPROC m_pOldWndProc; //original window proc

	private:

		CSubclassWindow( const CSubclassWindow& );
		CSubclassWindow& operator = ( const CSubclassWindow& );
	};

}//nsWin32

#endif//WINQL_WND_SUBCLASS_H_3

