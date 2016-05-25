//ListBox.h

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

//WinQL List Box

#ifndef WINQL_GUI_WND_LISTBOX_H_3
#define WINQL_GUI_WND_LISTBOX_H_3

#include "WinQL/GUI/Views/WindowView.h"
#include "WinQL/GUI/Windows/WinCtrlWindow.h"
#include "WinQL/GUI/WindowFactory.h"
#include "WinQL/Application/Graphics/WinQLRectangle.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CListBoxClass : public CWindowClass
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CListBoxClass );

		CListBoxClass();
		virtual ~CListBoxClass();
		virtual bool Preregistered();
		const TCHAR* Name();

	private:

		CListBoxClass( const CListBoxClass& );
		CListBoxClass& operator = ( const CListBoxClass& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CListBox : public CWinCtrlWindow
	{
	public:

		//Notifications
		__QCMP_STATIC_CONSTANT( int, LBN_ERRSPACE        = (-2) );
		__QCMP_STATIC_CONSTANT( int, LBN_SELCHANGE       = 1	   );
		__QCMP_STATIC_CONSTANT( int, LBN_DBLCLK          = 2	   );
		__QCMP_STATIC_CONSTANT( int, LBN_SELCANCEL       = 3	   );
		__QCMP_STATIC_CONSTANT( int, LBN_SETFOCUS        = 4	   );
		__QCMP_STATIC_CONSTANT( int, LBN_KILLFOCUS       = 5	   );

		// Listbox messages

		__QCMP_STATIC_CONSTANT( unsigned int, LB_ADDSTRING            = 0x0180 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_INSERTSTRING         = 0x0181 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_DELETESTRING         = 0x0182 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SELITEMRANGEEX       = 0x0183 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_RESETCONTENT         = 0x0184 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETSEL               = 0x0185 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETCURSEL            = 0x0186 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETSEL               = 0x0187 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETCURSEL            = 0x0188 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETTEXT              = 0x0189 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETTEXTLEN           = 0x018A );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETCOUNT             = 0x018B );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SELECTSTRING         = 0x018C );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_DIR                  = 0x018D );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETTOPINDEX          = 0x018E );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_FINDSTRING           = 0x018F );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETSELCOUNT          = 0x0190 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETSELITEMS          = 0x0191 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETTABSTOPS          = 0x0192 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETHORIZONTALEXTENT  = 0x0193 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETHORIZONTALEXTENT  = 0x0194 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETCOLUMNWIDTH       = 0x0195 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_ADDFILE              = 0x0196 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETTOPINDEX          = 0x0197 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETITEMRECT          = 0x0198 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETITEMDATA          = 0x0199 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETITEMDATA          = 0x019A );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SELITEMRANGE         = 0x019B );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETANCHORINDEX       = 0x019C );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETANCHORINDEX       = 0x019D );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETCARETINDEX        = 0x019E );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETCARETINDEX        = 0x019F );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETITEMHEIGHT        = 0x01A0 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETITEMHEIGHT        = 0x01A1 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_FINDSTRINGEXACT      = 0x01A2 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETLOCALE            = 0x01A5 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETLOCALE            = 0x01A6 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_SETCOUNT             = 0x01A7 );

#if(WINVER >= 0x0400)
		__QCMP_STATIC_CONSTANT( unsigned int, LB_INITSTORAGE          = 0x01A8 );
		__QCMP_STATIC_CONSTANT( unsigned int, LB_ITEMFROMPOINT        = 0x01A9 );
#endif /* WINVER >= 0x0400 */

#if(_WIN32_WCE >= 0x0400)
		__QCMP_STATIC_CONSTANT( unsigned int, LB_MULTIPLEADDSTRING    = 0x01B1 );
#endif

#if(_WIN32_WINNT >= 0x0501)
		__QCMP_STATIC_CONSTANT( unsigned int, LB_GETLISTBOXINFO       = 0x01B2 );
#endif /* _WIN32_WINNT >= 0x0501 */

#if(_WIN32_WINNT >= 0x0501)
		__QCMP_STATIC_CONSTANT( unsigned int, LB_MSGMAX               = 0x01B3 );
#elif(_WIN32_WCE >= 0x0400)
		__QCMP_STATIC_CONSTANT( unsigned int, LB_MSGMAX               = 0x01B1 );
#elif(WINVER >= 0x0400)
		__QCMP_STATIC_CONSTANT( unsigned int, LB_MSGMAX               = 0x01B0 );
#else
		__QCMP_STATIC_CONSTANT( unsigned int, LB_MSGMAX               = 0x01A8 );
#endif

		__QOR_DECLARE_OCLASS_ID( CListBox );

		CListBox();
		virtual ~CListBox();
		virtual void OnCommand( unsigned short wCtrlID, unsigned short wCode );

		virtual void OnErrSpace();
		virtual void OnSelChange();
		virtual void OnDblClick();
		virtual void OnSelCancel();
		virtual void OnSetFocus();
		virtual void OnKillFocus();

		long AddFile( const TCHAR* strFile );
		long AddString( const TCHAR* strItem );
		long DeleteString( unsigned short wIndex );
		long Dir( Cmp_uint_ptr Flags, const TCHAR* strPath );
		long FindString( unsigned short wIndex, const TCHAR* strItem );
		long FindStringExact( unsigned short wIndex, const TCHAR* strItem );
		long GetAnchorIndex();
		long GetCaretIndex();
		long GetCount();
		long GetCurSel();
		long GetHorizontalExtent();
		long SetHorizontalExtent( Cmp_uint_ptr Extent );
		long GetItemData( unsigned short wIndex );
		long GetItemHeight( unsigned short wIndex );
		long GetItemRect( unsigned short wIndex, CRectangle& rcItem );
		long GetInfo();
		long GetLocale();
		long GetSel( unsigned short wIndex );
		long GetSelCount();
		long GetSelItems( int* pItemsBuffer, Cmp_uint_ptr BufferCount );
		long GetText( unsigned short wIndex, TCHAR* strBuffer );
		long GetTextLength( unsigned short wIndex );
		long GetTopIndex();
		long InitStorage( unsigned short wItems, long lBytes );
		long InsertString( unsigned short wIndex, const TCHAR* strItem );
		long ItemFromPoint( unsigned short wXPos, unsigned short wYPos );
		long ResetContent();
		long SelectString( unsigned short wIndex, const TCHAR* strSearch );
		long SelectItemRange( bool bSelect, unsigned short wSelBegin, unsigned short wSelEnd );
		long SelectItemRangeEx( unsigned short wSelBegin, unsigned short wSelEnd );
		long SetAnchorIndex( unsigned short wIndex );
		long SetCaretIndex( unsigned short wIndex, bool bMinimumScrollVisible );
		void SetColumnWidth( Cmp_uint_ptr Width );
		long SetCount( unsigned short wItems );
		long SetCurSel( unsigned short wIndex );
		long SetItemData( unsigned short wIndex, Cmp_long_ptr lItemData );
		long SetItemHeight( unsigned short wIndex, Cmp_long_ptr lItemHeight );
		long SetLocale( Cmp_uint_ptr LocaleID );
		long SetSel( bool bSel, Cmp_long_ptr lSelItem );
		bool SetTabstops( Cmp_uint_ptr Count, int* pTabstops );
		long SetTopIndex( unsigned short wIndex );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CListBoxFactory : public CWindowFactory
	{
	public:

		//Listbox Styles

		__QCMP_STATIC_CONSTANT( long, LBS_NOTIFY             = 0x0001L );
		__QCMP_STATIC_CONSTANT( long, LBS_SORT               = 0x0002L );
		__QCMP_STATIC_CONSTANT( long, LBS_NOREDRAW           = 0x0004L );
		__QCMP_STATIC_CONSTANT( long, LBS_MULTIPLESEL        = 0x0008L );
		__QCMP_STATIC_CONSTANT( long, LBS_OWNERDRAWFIXED     = 0x0010L );
		__QCMP_STATIC_CONSTANT( long, LBS_OWNERDRAWVARIABLE  = 0x0020L );
		__QCMP_STATIC_CONSTANT( long, LBS_HASSTRINGS         = 0x0040L );
		__QCMP_STATIC_CONSTANT( long, LBS_USETABSTOPS        = 0x0080L );
		__QCMP_STATIC_CONSTANT( long, LBS_NOINTEGRALHEIGHT   = 0x0100L );
		__QCMP_STATIC_CONSTANT( long, LBS_MULTICOLUMN        = 0x0200L );
		__QCMP_STATIC_CONSTANT( long, LBS_WANTKEYBOARDINPUT  = 0x0400L );
		__QCMP_STATIC_CONSTANT( long, LBS_EXTENDEDSEL        = 0x0800L );
		__QCMP_STATIC_CONSTANT( long, LBS_DISABLENOSCROLL    = 0x1000L );
		__QCMP_STATIC_CONSTANT( long, LBS_NODATA             = 0x2000L );
		__QCMP_STATIC_CONSTANT( long, LBS_NOSEL              = 0x4000L );
		__QCMP_STATIC_CONSTANT( long, LBS_COMBOBOX           = 0x8000L );
		__QCMP_STATIC_CONSTANT( long, LBS_STANDARD           = (LBS_NOTIFY | LBS_SORT | COSWindow::eWSVScroll | COSWindow::eWSBorder ) );

		__QOR_DECLARE_OCLASS_ID( CListBoxFactory );

		CListBoxFactory();
		virtual ~CListBoxFactory();
		virtual CListBox* Create( void );
		bool GetDisableNoScroll();
		void SetDisableNoScroll( bool bFlag );
		bool GetNotify();
		void SetNotify( bool bFlag );
		bool GetSort();
		void SetSort( bool bFlag );
		bool GetNoRedraw();
		void SetNoRedraw( bool bFlag );
		bool GetMultiSelect();
		void SetMultiSelect( bool bFlag );
		bool GetOwnerDrawFixed();
		void SetOwnerDrawFixed( bool bFlag );
		bool GetOwnerDrawVariable();
		void SetOwnerDrawVariable( bool bFlag );
		bool GetHasStrings();
		void SetHasStrings( bool bFlag );
		bool GetUseTabstops();
		void SetUseTabstops( bool bFlag );
		bool GetNoIntegralHeight();
		void SetNoIntegralHeight( bool bFlag );
		bool GetMultiColumn();
		void SetMultiColumn( bool bFlag );
		bool GetWantKeyboardInput();
		void SetWantKeyboardInput( bool bFlag );
		bool GetExtendedSelection();
		void SetExtendedSelection( bool bFlag );
		bool GetNoData();
		void SetNoData( bool bFlag );
		bool GetNoSelection();
		void SetNoSelection( bool bFlag );
		bool GetStandard();
		void SetStandard( bool bFlag );

	};

}//nsWin32

#endif//WINQL_GUI_WND_LISTBOX_H_3
