//ComboBoxEx.h

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

//Common Control Combo Box

#ifndef WINQL_GUI_WND_CCTRL_COMBOBOXEX_H_3
#define WINQL_GUI_WND_CCTRL_COMBOBOXEX_H_3

#include "WinQL/GUI/Windows/CommonCtrlFactory.h"
#include "WinQL/GUI/Windows/ComboBox.h"
#include "WinQL/GUI/CommonCtrl.h"
#include "WinQL/GUI/ImageList.h"
#include "WinQL/GUI/Windows/Edit.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CComboBoxExClass : public CComboBoxClass
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CComboBoxExClass );

		CComboBoxExClass();
		~CComboBoxExClass();
		const TCHAR* Name();

	private:

		CCommonCtrl m_ComCtrl32;

		CComboBoxExClass( const CComboBoxExClass& );
		CComboBoxExClass& operator = ( const CComboBoxExClass& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CComboBoxEx : public CComboBox
	{
	public:

		//--------------------------------------------------------------------------------
		typedef struct tagNMMOUSE : public NotificationMessageHeader
		{
			//NMHDR   hdr;
			Cmp_ulong_ptr dwItemSpec;
			Cmp_ulong_ptr dwItemData;
			POINT   pt;
			Cmp_long_ptr  dwHitInfo; // any specifics about where on the item or control the mouse is
		} NMMOUSE, *LPNMMOUSE;

		//--------------------------------------------------------------------------------
		struct COMBOBOXEXITEM
		{
			unsigned int mask;
			Cmp_int_ptr iItem;
			TCHAR* pszText;
			int cchTextMax;
			int iImage;
			int iSelectedImage;
			int iOverlay;
			int iIndent;
			Cmp_long_ptr lParam;
		};

		__QCMP_STATIC_CONSTANT( int, CBEMAXSTRLEN			= 260 );

		//--------------------------------------------------------------------------------
		typedef struct NMCBEDRAGBEGIN : public NotificationMessageHeader
		{
			//NMHDR hdr;
			int   iItemid;
			TCHAR szText[ CBEMAXSTRLEN ];
		} *LPNMCBEDRAGBEGIN, *PNMCBEDRAGBEGIN;

		//--------------------------------------------------------------------------------
		typedef struct : public NotificationMessageHeader
		{
			//NMHDR hdr;
			int fChanged;
			int iNewSelection;
			TCHAR szText[ CBEMAXSTRLEN ];
			int iWhy;
		} NMCBEENDEDIT, *LPNMCBEENDEDIT, *PNMCBEENDEDIT;

		//--------------------------------------------------------------------------------
		typedef struct : public NotificationMessageHeader
		{
			//NMHDR hdr;
			COMBOBOXEXITEM ceItem;
		} NMCOMBOBOXEX, *PNMCOMBOBOXEX;

		__QCMP_STATIC_CONSTANT( int, CBEN_FIRST              = (0U-800U) );       // combo box ex
		__QCMP_STATIC_CONSTANT( int, CBEN_LAST               = (0U-830U) );

		//Notifications

#if (_WIN32_IE >= 0x0400)
		__QCMP_STATIC_CONSTANT( int, CBEN_GETDISPINFOA        = (CBEN_FIRST - 0) );
#endif
		__QCMP_STATIC_CONSTANT( int, CBEN_INSERTITEM          = (CBEN_FIRST - 1) );
		__QCMP_STATIC_CONSTANT( int, CBEN_DELETEITEM          = (CBEN_FIRST - 2) );
		__QCMP_STATIC_CONSTANT( int, CBEN_BEGINEDIT           = (CBEN_FIRST - 4) );
		__QCMP_STATIC_CONSTANT( int, CBEN_ENDEDITA            = (CBEN_FIRST - 5) );
		__QCMP_STATIC_CONSTANT( int, CBEN_ENDEDITW            = (CBEN_FIRST - 6) );

#if		(_WIN32_IE >= 0x0400)
		__QCMP_STATIC_CONSTANT( int, CBEN_GETDISPINFOW        = (CBEN_FIRST - 7) );
		__QCMP_STATIC_CONSTANT( int, CBEN_DRAGBEGINA          = (CBEN_FIRST - 8) );
		__QCMP_STATIC_CONSTANT( int, CBEN_DRAGBEGINW          = (CBEN_FIRST - 9) );
#endif//(_WIN32_IE >= 0x0400)

#ifdef UNICODE
#	define CBEN_DRAGBEGIN CBEN_DRAGBEGINW
#	define CBEN_ENDEDIT CBEN_ENDEDITW
#	define CBEN_GETDISPINFO CBEN_GETDISPINFOW
#else
#	define CBEN_DRAGBEGIN CBEN_DRAGBEGINA
#	define CBEN_ENDEDIT CBEN_ENDEDITA
#	define CBEN_GETDISPINFO CBEN_GETDISPINFOA
#endif
			
		//Messages

		__QCMP_STATIC_CONSTANT( int, CBEM_INSERTITEMA        = ( COSWindow::wmUser + 1) );
		__QCMP_STATIC_CONSTANT( int, CBEM_SETIMAGELIST       = ( COSWindow::wmUser + 2) );
		__QCMP_STATIC_CONSTANT( int, CBEM_GETIMAGELIST       = ( COSWindow::wmUser + 3) );
		__QCMP_STATIC_CONSTANT( int, CBEM_GETITEMA           = ( COSWindow::wmUser + 4) );
		__QCMP_STATIC_CONSTANT( int, CBEM_SETITEMA           = ( COSWindow::wmUser + 5) );
		__QCMP_STATIC_CONSTANT( int, CBEM_DELETEITEM         = CB_DELETESTRING );
		__QCMP_STATIC_CONSTANT( int, CBEM_GETCOMBOCONTROL    = ( COSWindow::wmUser + 6) );
		__QCMP_STATIC_CONSTANT( int, CBEM_GETEDITCONTROL     = ( COSWindow::wmUser + 7) );
#if (_WIN32_IE >= 0x0400)
		__QCMP_STATIC_CONSTANT( int, CBEM_SETEXSTYLE         = ( COSWindow::wmUser + 8) );  // use  SETEXTENDEDSTYLE instead
		__QCMP_STATIC_CONSTANT( int, CBEM_SETEXTENDEDSTYLE   = ( COSWindow::wmUser + 14) );   // lparam == new style, wParam (optional) == mask
		__QCMP_STATIC_CONSTANT( int, CBEM_GETEXSTYLE         = ( COSWindow::wmUser + 9) ); // use GETEXTENDEDSTYLE instead
		__QCMP_STATIC_CONSTANT( int, CBEM_GETEXTENDEDSTYLE   = ( COSWindow::wmUser + 9) );
#else
		__QCMP_STATIC_CONSTANT( int, CBEM_SETEXSTYLE         = ( COSWindow::wmUser + 8) );
		__QCMP_STATIC_CONSTANT( int, CBEM_GETEXSTYLE         = ( COSWindow::wmUser + 9) );
#endif
		__QCMP_STATIC_CONSTANT( int, CBEM_HASEDITCHANGED     = ( COSWindow::wmUser + 10) );
		__QCMP_STATIC_CONSTANT( int, CBEM_INSERTITEMW        = ( COSWindow::wmUser + 11) );
		__QCMP_STATIC_CONSTANT( int, CBEM_SETITEMW           = ( COSWindow::wmUser + 12) );
		__QCMP_STATIC_CONSTANT( int, CBEM_GETITEMW           = ( COSWindow::wmUser + 13) );

#define CBEM_SETUNICODEFORMAT   CCM_SETUNICODEFORMAT
#define CBEM_GETUNICODEFORMAT   CCM_GETUNICODEFORMAT
#define CBEM_SETWINDOWTHEME     CCM_SETWINDOWTHEME

#ifdef UNICODE
#	define CBEM_INSERTITEM         CBEM_INSERTITEMW
#	define CBEM_SETITEM            CBEM_SETITEMW
#	define CBEM_GETITEM            CBEM_GETITEMW
#else
#	define CBEM_INSERTITEM         CBEM_INSERTITEMA
#	define CBEM_SETITEM            CBEM_SETITEMA
#	define CBEM_GETITEM            CBEM_GETITEMA
#endif

		__QOR_DECLARE_OCLASS_ID( CComboBoxEx );

		CComboBoxEx();
		virtual ~CComboBoxEx();

		long OnNotify( NotificationMessageHeader* pHdr );

		virtual void OnBeginEdit( NotificationMessageHeader* pHdr );
		virtual void OnDeleteItem( NMCOMBOBOXEX* pHdr );
#if		( _WIN32_IE >= 0x0400 )
		virtual void OnBeginDrag( NMCBEDRAGBEGIN* pHdr );
#endif//( _WIN32_IE >= 0x0400 )
		virtual long OnEndEdit( NMCBEENDEDIT* pHdr );
		virtual void OnGetDispInfo( NMCOMBOBOXEX* pHdr );
		virtual void OnInsertItem( NMCOMBOBOXEX* pHdr );
#if		( _WIN32_IE >= 0x0400 )
		virtual long OnNotifySetCursor( NMMOUSE* pHdr );
#endif//( _WIN32_IE >= 0x0400 )

		long DeleteItem( Cmp_uint_ptr Index );
		CComboBox::refType GetComboControl();
		CEdit::refType GetEditControl();
		long GetExtendedStyle();
		CImageList::refType GetImageList();
		bool GetItem( COMBOBOXEXITEM& Item );
		bool GetUnicodeFormat();
		bool HasEditChanged();
		long InsertItem( COMBOBOXEXITEM& Item );

		//--------------------------------------------------------------------------------
		/*
		void KillFocus()
		{
			m_Win32MsgHandler.Send( Handle(), (unsigned int) CBEM_KILLCOMBOFOCUS, 0, 0 );
		}

		//--------------------------------------------------------------------------------
		void SetFocus()
		{
			m_Win32MsgHandler.Send( Handle(), (unsigned int) CBEM_SETCOMBOFOCUS, 0, 0 );
		}
		*/
		//--------------------------------------------------------------------------------
		long SetExtendedStyle( unsigned long dwMask, unsigned long dwExStyle );
		long SetImageList( CImageListHandle::refType hIml );
		bool SetItem( COMBOBOXEXITEM& Item );
		bool SetUnicodeFormat( bool bUnicode );
		void SetWindowTheme( wchar_t* wstrStyle );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CComboBoxExFactory : public CWindowFactory
	{
	public:

		__QCMP_STATIC_CONSTANT( unsigned long, CBES_EX_NOEDITIMAGE          = 0x00000001 );
		__QCMP_STATIC_CONSTANT( unsigned long, CBES_EX_NOEDITIMAGEINDENT    = 0x00000002 );
		__QCMP_STATIC_CONSTANT( unsigned long, CBES_EX_PATHWORDBREAKPROC    = 0x00000004 );
		__QCMP_STATIC_CONSTANT( unsigned long, CBES_EX_NOSIZELIMIT          = 0x00000008 );
		__QCMP_STATIC_CONSTANT( unsigned long, CBES_EX_CASESENSITIVE        = 0x00000010 );
#if		(_WIN32_WINNT >= 0x0600)
		__QCMP_STATIC_CONSTANT( unsigned long, CBES_EX_TEXTENDELLIPSIS      = 0x00000020 );
#endif//(_WIN32_WINNT >= 0x0600)

		__QOR_DECLARE_OCLASS_ID( CComboBoxExFactory );

		CComboBoxExFactory();

		virtual ~CComboBoxExFactory();
		virtual CComboBoxEx* Create();
		bool GetNoEditImage();
		void SetNoEditImage( bool bFlag );
		bool GetNoEditImageIndent();
		void SetNoEditImageIndent( bool bFlag );
		bool GetPathWordBreakProc();
		void SetPathWordBreakProc( bool bFlag );
		bool GetNoSizeLimit();
		void SetNoSizeLimit( bool bFlag );
		bool GetCaseSensitive();
		void SetCaseSensitive( bool bFlag );
		bool GetTextEndEllipsis();
		void SetTextEndEllipsis( bool bFlag );

	private:

		CComboBoxExFactory( const CComboBoxExFactory& );
		CComboBoxExFactory& operator = ( const CComboBoxExFactory& );

	};

}//nsWin32

#endif//WINQL_GUI_WND_CCTRL_COMBOBOXEX_H_3
