//MenuModel.h

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

//Model for Windows Menu

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef WINQL_GUI_VISMODELS_MENU_H_3
#define WINQL_GUI_VISMODELS_MENU_H_3

#include "MammutQOR/Model.h"
#include "MammutQOR/Model/MProperty.h"
#include "MammutQOR/Model/MPropertySet.h"
#include "MammutQOR/Models/VectorModel.h"
#include "CodeQOR/ClassReg/ClassRegEntry.h"
#include "WinQL/Application/Process/Module/WinQLModule.h"
#include "WinQL/GUI/Menu.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CMenuItemModel : public nsMammut::CPropertySet
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CMenuItemModel );

		CMenuItemModel( nsMammut::CModel* pContainer = 0 );
		CMenuItemModel( const CMenuItemModel& src );
		CMenuItemModel( nsMammut::CPropertySet& src );
		CMenuItemModel& operator = ( const CMenuItemModel& src );
		CMenuItemModel& operator = ( const nsMammut::CPropertySet& src );
		virtual ~CMenuItemModel();

		nsMammut::CProperty< unsigned long > m_Mask;
		nsMammut::CProperty< unsigned int > m_Type;		// used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
		nsMammut::CProperty< unsigned int > m_State;        // used if MIIM_STATE
		nsMammut::CProperty< unsigned int > m_wID;           // used if MIIM_ID
		nsMammut::CProperty< CMenu::refType > m_SubMenu;		// used if MIIM_SUBMENU
		nsMammut::CProperty< CBitmap::refType > m_BMPChecked;   // used if MIIM_CHECKMARKS
		nsMammut::CProperty< CBitmap::refType > m_BMPUnchecked; // used if MIIM_CHECKMARKS
		nsMammut::CProperty< Cmp_ulong_ptr > m_ItemData;   // used if MIIM_DATA
		nsMammut::CProperty< TCHAR* > m_TypeData;			// used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
		nsMammut::CProperty< unsigned int > m_cch;           // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
		nsMammut::CProperty< CBitmap::refType > m_BMPItem;      // used if MIIM_BITMAP

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CMenuModel : public nsMammut::CModel
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CMenuModel );

		CMenuModel( nsMammut::CModel* pContainer = 0 );
		CMenuModel( const CMenuModel& src );	
		CMenuModel( nsMammut::CModel& src );
		CMenuModel& operator = ( const CMenuModel& src );
		CMenuModel& operator = ( nsMammut::CModel& src );
        virtual ~CMenuModel();
                    		
		nsMammut::CPropertySet m_MenuInfo;

			nsMammut::CProperty< unsigned long > m_Mask;
			nsMammut::CProperty< unsigned long > m_Style;
			nsMammut::CProperty< unsigned int > m_YMax;
			nsMammut::CProperty< CBrush::refType > m_BackgroundBrush;
			nsMammut::CProperty< unsigned long > m_ContextHelpID;
			nsMammut::CProperty< Cmp_ulong_ptr > m_MenuData;
			nsMammut::CProperty< const TCHAR* > m_Name;
			nsMammut::CProperty< CWinModule* > m_Module;

		nsMammut::CVectorModel< CMenuItemModel > m_MenuItems;
	};

}//nsWin32

#endif//WINQL_GUI_VISMODELS_MENU_H_3
