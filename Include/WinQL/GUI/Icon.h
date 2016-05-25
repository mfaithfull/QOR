//Icon.h

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

#ifndef WINQL_GUI_ICON_H_3
#define WINQL_GUI_ICON_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/codingmacros.h"
#include "CodeQOR/DataStructures/TLRef.h"
#include "WinQL/CodeServices/Handles/WinQLHandleMap.h"
#include "WinQL/Definitions/Handles.h"
#include "WinQL/Definitions/Constants.h"
#include "WinQL/Application/User/WinQLUserObject.h"
#include "WinQL/CodeServices/Handles/WinQLRAIISessionHandle.h"
#include "WinQL/Application/Process/Module/WinQLModule.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CUser32;
}//nsWinQAPI

//--------------------------------------------------------------------------------
namespace nsWin32
{
	class __QOR_INTERFACE( __WINQL ) CDeviceContext;
	class __QOR_INTERFACE( __WINQL ) CBrush;

	//--------------------------------------------------------------------------------
	typedef struct _ICONINFO 
	{
		int fIcon;
		unsigned long xHotspot;
		unsigned long yHotspot;
		void* hbmMask;
		void* hbmColor;
	} ICONINFO;

	typedef ICONINFO *PICONINFO;

	//--------------------------------------------------------------------------------
	struct ICONINFOEX
	{
		unsigned long cbSize;
		int fIcon;
		unsigned long xHotspot;
		unsigned long yHotspot;
		CBitmapHandle::refType hbmMask;
		CBitmapHandle::refType hbmColor;
		unsigned short wResID;
		TCHAR szModName[ Max_Path ];
		TCHAR szResName[ Max_Path ];
	};

	class __QOR_INTERFACE( __WINQL_GUI ) CIcon;

	typedef nsWin32::CTHandleMap< CIconHandle::refType, CIcon > CIconHandleMap;

	extern __QCMP_DECLARE_PERTHREAD CIconHandleMap* p_tIconHandleMap;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CIcon
	{
		friend class nsCodeQOR::CDefaultInstancer< nsCodeQOR::CDefaultSource, CIcon >;
		friend class nsCodeQOR::CDefaultAllocator< nsCodeQOR::CDefaultInstancer< nsCodeQOR::CDefaultSource, CIcon >, CIcon >;
		friend class nsCodeQOR::CTClassRegEntry< nsWin32::CIcon >;
	public:

		typedef nsCodeQOR::CTLRef< CIcon > refType;

		__QOR_DECLARE_OCLASS_ID( CIcon );
			
		CIcon( CWinModule& Module, int nWidth, int nHeight, unsigned char cPlanes, unsigned char cBitsPixel, const unsigned char* lpbANDbits, const unsigned char* lpbXORbits );
		CIcon( unsigned char* presbits, unsigned long dwResSize, bool fIcon, unsigned long dwVer );
		CIcon( unsigned char* pbIconBits, unsigned long cbIconBits, bool fIcon, unsigned long dwVersion, int cxDesired, int cyDesired, unsigned int uFlags );
		CIcon( nsWin32::ICONINFO& iconinfo );
		CIcon( CWinModule& Module, const TCHAR* lpIconName );
		CIcon( const CIcon& src );
		
		static refType Load( CWinModule& Module, const TCHAR* pIconName );
		static refType CreateIndirect( nsWin32::ICONINFO& iconinfo );
		static refType CreateFromResourceEx( unsigned char* pbIconBits, unsigned long cbIconBits, bool fIcon, unsigned long dwVersion, int cxDesired, int cyDesired, unsigned int uFlags );
		static refType CreateFromResource( unsigned char* presbits, unsigned long dwResSize, bool fIcon, unsigned long dwVer );
		static refType Create( CWinModule& Module, int nWidth, int nHeight, unsigned char cPlanes, unsigned char cBitsPixel, const unsigned char* lpbANDbits, const unsigned char* lpbXORbits );
		virtual ~CIcon();
		bool Draw( CDeviceContext& dc, int X, int Y );
		bool Draw( CDeviceContext& dc, int xLeft, int yTop, int cxWidth, int cyWidth, unsigned int istepIfAniCur, CBrush& FlickerFreeDrawBrush, unsigned int diFlags );
		bool GetInfo( nsWin32::ICONINFO& iconinfo );
		bool GetInfo( nsWin32::ICONINFOEX& iconinfoex );
		CUserObject Security();		
		int Status( void );
		refType Ref( void );

		CIconHandle::refType Handle( void );
		static refType FromHandle( CIconHandle::refType hIcon );

	protected:

		CIconHandle m_Handle;
		int m_iStatus;

		void Init( void );
		void Uninit( void );

		CIcon( CIconHandle::refType hIcon );

	private:			

		nsWinQAPI::CUser32& m_User32Library;

		CIcon();
		__QCS_DECLARE_NONASSIGNABLE( CIcon );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CIconResourceHelper
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CIconResourceHelper );

		CIconResourceHelper();
		~CIconResourceHelper();
		int LookupIdFromDirectory( unsigned char* presbits, bool fIcon );
		int LookupIdFromDirectory( unsigned char* presbits, bool fIcon, int cxDesired, int cyDesired, unsigned int Flags );
		unsigned int Extract( const TCHAR* lpszFile, int nIconIndex, int cxIcon, int cyIcon, unsigned int nIcons, unsigned int flags, nsCodeQOR::CTArray< CIcon::refType > Icons, nsCodeQOR::CTArray< unsigned int > ResourceIds );

	private:

		nsWinQAPI::CUser32& m_User32Library;

		__QCS_DECLARE_NONCOPYABLE( CIconResourceHelper );
	};

}//nsWin32

#endif//WINQL_GUI_ICON_H_3
