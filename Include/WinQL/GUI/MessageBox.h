//MessageBox.h

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

/*Portions derived from: 
XMessageBox - A reverse-engineered MessageBox()
By Hans Dietrich | 29 Nov 2008 
www.codeproject.com
under: Code Project Open License
*/

#ifndef WINQL_GUI_MESSAGEBOX_H_3
#define WINQL_GUI_MESSAGEBOX_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Handles.h"
#include "WinQL/Application/Graphics/WinQLRectangle.h"
#include "WinQL/GUI/GUI.h"
#include "WinQL/GUI/CommonCtrl.h"
#include "WinQL/GUI/Window.h"
#include "WinQL/CodeServices/Handles/WinQLHandleMap.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CUser32;
	//class __QOR_INTERFACE( __WINQAPI ) CUXTheme;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	typedef struct tagHELPINFO			// Structure pointed to by lParam of WM_HELP
	{
		unsigned int cbSize;            // Size in bytes of this struct 
		int iContextType;				// Either HELPINFO_WINDOW or HELPINFO_MENUITEM
		int iCtrlId;					// Control Id or a Menu item Id.
		CWindowHandle::refType hItemHandle;       // hWnd of control or hMenu.    
		Cmp_ulong_ptr dwContextId;      // Context Id associated with this item
		nsWin32::POINT MousePos;        // Mouse Position in screen co-ordinates
	}  HELPINFO, *LPHELPINFO;

	//--------------------------------------------------------------------------------
	typedef void ( __QCMP_STDCALLCONVENTION *MSGBOXCALLBACK )( LPHELPINFO lpHelpInfo );

	//--------------------------------------------------------------------------------
	typedef struct tagMSGBOXPARAMS
	{
		unsigned int cbSize;
		void* hwndOwner;
		InstanceHandle hInstance;
		const TCHAR* lpszText;
		const TCHAR* lpszCaption;
		unsigned long dwStyle;
		const TCHAR* lpszIcon;
		Cmp_ulong_ptr dwContextHelpId;
		nsWin32::MSGBOXCALLBACK lpfnMsgBoxCallback;
		unsigned long dwLanguageId;
	} MSGBOXPARAMS, *PMSGBOXPARAMS, *LPMSGBOXPARAMS;


	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CMessageBox
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CMessageBox );

		__QCMP_STATIC_CONSTANT( unsigned int, MBOK						= 0x00000000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBOKCancel				= 0x00000001 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBAbortRetryIgnore		= 0x00000002 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBYesNoCancel				= 0x00000003 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBYesNo					= 0x00000004 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBRetryCancel				= 0x00000005 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBCancelTryAgainContinue	= 0x00000006 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBHelp					= 0x00004000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconExclamation			= 0x00000030 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconWarning				= 0x00000030 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconInformation			= 0x00000040 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconAsterisk			= 0x00000040 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconQuestion			= 0x00000020 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconStop				= 0x00000010 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconError				= 0x00000010 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBIconHand				= 0x00000010 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBDefButton1				= 0x00000000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBDefButton2				= 0x00000100 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBDefButton3				= 0x00000200 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBDefButton4				= 0x00000300 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBApplModal				= 0x00000000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBSystemModal				= 0x00001000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBTaskModal				= 0x00002000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBDefaultDesktopOnly		= 0x00020000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBRight					= 0x00080000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBRTLReading				= 0x00100000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBSetForeground			= 0x00010000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBTopmost					= 0x00040000 );
		__QCMP_STATIC_CONSTANT( unsigned int, MBServiceNotification		= 0x00200000 );

		CMessageBox( COSWindow::refType Wnd, const TCHAR* lpText, const TCHAR* lpCaption, unsigned int uType, unsigned short wLanguageId = 0, unsigned long dwMilliseconds = 0 );
		CMessageBox( const nsWin32::LPMSGBOXPARAMS lpMsgBoxParams );
		virtual ~CMessageBox( void );
		int Result( void );

	protected:

		int m_iResult;

	private:			

		nsWinQAPI::CUser32& m_User32Library;

		__QCS_DECLARE_NONCOPYABLE( CMessageBox );
	};

}//nsWin32

#endif//WINQL_GUI_MESSAGEBOX_H_3
