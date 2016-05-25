//NCPointerController.h

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

//GUI Controller for Non Client Pointer interaction

#ifndef WINQL_GUI_CONTROLLER_NCPOINTER_H_3
#define WINQL_GUI_CONTROLLER_NCPOINTER_H_3

#include "WinQL/GUI/Views/InteractiveWindowView.h"
#include "WinQL/GUI/Controllers/Parts/BaseWindowPartController.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CNCPointerController : public CBaseWindowPartController
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CNCPointerController );

		CNCPointerController( nsMammut::CModel* pModelItem = 0, nsAppocrita::CController* pParent = 0 );
		virtual ~CNCPointerController();

		virtual bool ProcessMessage( COSWindow& Window, Cmp_long_ptr& lResult, unsigned int uMsg, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
			
		virtual void OnNCMouseMove( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCLButtonDown( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCLButtonUp( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCLButtonDblClk( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCRButtonDown( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCRButtonUp( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCRButtonDblClk( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCMButtonDown( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCMButtonUp( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
		virtual void OnNCMButtonDblClk( COSWindow& Window, Cmp_uint_ptr wParam, Cmp_long_ptr lParam );
	};

}//nsWin32

#endif//WINQL_GUI_CONTROLLER_NCPOINTER_H_3
