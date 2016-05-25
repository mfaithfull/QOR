//WindowClass.h

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

#ifndef WINQL_GUI_WNDCLASS_H_3
#define WINQL_GUI_WNDCLASS_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/Definitions/Handles.h"
#include "CodeQOR/Text/CodeString.h"
#include "CodeQOR/ClassReg/ClassRegEntry.h"
#include "WinQL/GUI/Icon.h"
#include "WinQL/GUI/Cursor.h"
#include "WinQL/CodeServices/Handles/WinQLRAIISessionHandle.h"
#include "WinQL/Application/Graphics/WinQLBrush.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CUser32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{	

	//--------------------------------------------------------------------------------
	typedef Cmp_long_ptr ( __QCMP_STDCALLCONVENTION* WNDPROC )( void*, unsigned int, Cmp_uint_ptr, Cmp_long_ptr );

	//--------------------------------------------------------------------------------
	typedef struct tagWNDCLASSEX
	{
		unsigned int m_uicbSize;
		unsigned int m_uiStyle;
		nsWin32::WNDPROC m_pfnWndProc;
		int m_cbClsExtra;
		int m_cbWndExtra;
		void* m_hInstance;
		void* m_pIcon;
		void* m_pCursor;
		void* m_pbrBackground;
		const TCHAR* m_lpszMenuName;
		const TCHAR* m_lpszClassName;
		void* m_pIconSm;
	} WNDCLASSEX, *PWNDCLASSEX, *NPWNDCLASSEX, *LPWNDCLASSEX;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CWindowClassData : public nsWin32::WNDCLASSEX
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CWindowClassData );

		__QCMP_STATIC_CONSTANT( unsigned long, VREDRAW          = 0x0001 );
		__QCMP_STATIC_CONSTANT( unsigned long, HREDRAW          = 0x0002 );
		__QCMP_STATIC_CONSTANT( unsigned long, DBLCLKS          = 0x0008 );
		__QCMP_STATIC_CONSTANT( unsigned long, OWNDC            = 0x0020 );
		__QCMP_STATIC_CONSTANT( unsigned long, CLASSDC          = 0x0040 );
		__QCMP_STATIC_CONSTANT( unsigned long, PARENTDC         = 0x0080 );
		__QCMP_STATIC_CONSTANT( unsigned long, NOCLOSE          = 0x0200 );
		__QCMP_STATIC_CONSTANT( unsigned long, SAVEBITS         = 0x0800 );
		__QCMP_STATIC_CONSTANT( unsigned long, BYTEALIGNCLIENT  = 0x1000 );
		__QCMP_STATIC_CONSTANT( unsigned long, BYTEALIGNWINDOW  = 0x2000 );
		__QCMP_STATIC_CONSTANT( unsigned long, GLOBALCLASS      = 0x4000 );
		__QCMP_STATIC_CONSTANT( unsigned long, IME              = 0x00010000 );
		__QCMP_STATIC_CONSTANT( unsigned long, DROPSHADOW       = 0x00020000 );

		CWindowClassData();
		CWindowClassData( InstanceHandle hinst, const TCHAR* lpszClass );
		virtual ~CWindowClassData();

	private:			

		nsWinQAPI::CUser32& m_User32Library;
		__QCS_DECLARE_NONCOPYABLE( CWindowClassData );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CWindowClassRegistration
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CWindowClassRegistration );
			
		CWindowClassRegistration( CWindowClassData& WC );
		virtual ~CWindowClassRegistration();

	protected:

		CWindowClassData& m_Class;
		unsigned short m_Atom;

	private:

		nsWinQAPI::CUser32& m_User32Library;
		__QCS_DECLARE_NONCOPYABLE( CWindowClassRegistration );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CWindowClass : public CWindowClassData
	{
	public:

		typedef nsCodeQOR::CTLRef< CWindowClass > refType;

		__QOR_DECLARE_OCLASS_ID( CWindowClass );

		CWindowClass();
		virtual ~CWindowClass();
		virtual void Preinitialise();
		virtual void Initialise();
		virtual bool Preregistered();		//Override this for built in Windows classes that are preregistred
		virtual bool Registered( bool bRegister = false );
		bool Register();
		virtual const TCHAR* Name();

		bool GetByteAlignClient();
		void SetByteAlignClient( bool bFlag );
		bool GetByteAlignWindow();
		void SetByteAlignWindow( bool bFlag );
		bool GetUseClassDC();
		void SetUseClassDC( bool bFlag );
		bool GetDoubleClicks();
		void SetDoubleClicks( bool bFlag );
		bool GetDropShadow();
		void SetDropShadow( bool bFlag );
		bool GetGlobalClass();
		void SetGlobalClass( bool bFlag );
		bool GetHRedrawTrigger();
		void SetHRedrawTrigger( bool bFlag );
		bool GetVRedrawTrigger();
		void SetVRedrawTrigger( bool bFlag );
		bool GetNoClose();
		void SetNoClose( bool bFlag );
		bool GetOwnDC();
		void SetOwnDC( bool bFlag );
		bool GetUsesParentDC();
		void SetUsesParentDC( bool bFlag );
		bool GetSaveBits();
		void SetSaveBits( bool bFlag );
		bool GetStyleBits( unsigned int uiStyle );
		void SetStyleBits( unsigned int uiStyle, bool bFlag );
		unsigned int GetStyle();
		void SetStyle( unsigned int uiStyle );
		nsWin32::WNDPROC GetWndProc();
		int GetClassExtra();
		int GetWindowExtra();
		CWinModule* GetInstance();
		CIcon::refType GetIcon();
		CCursor::refType GetCursor();
		CBrush::refType GetBackgroundBrush();
		const TCHAR* GetMenuName();
		const TCHAR* GetClassNameT();
		CIcon::refType GetSmallIcon();
			
	private:

		CWindowClassRegistration* m_pReg;			

		CWindowClass( const CWindowClass& );
		CWindowClass& operator = ( const CWindowClass& );
	};

    //--------------------------------------------------------------------------------
    template< const TCHAR** szName >
    class CTStandardWindowClass : public CWindowClass
    {

    public:

        //--------------------------------------------------------------------------------
	    CTStandardWindowClass()
        {
            Preinitialise();
        }

		//--------------------------------------------------------------------------------
	    virtual ~CTStandardWindowClass()
		{
		}

	    //--------------------------------------------------------------------------------
	    const TCHAR* Name()
	    {
		    return *szName;
	    }

	    //--------------------------------------------------------------------------------
	    bool Registered( bool bRegister = false )
	    {
		    static bool sbRegistered = false;
		    if( bRegister == true )
		    {
			    sbRegistered = true;
		    }
		    return sbRegistered;
	    }

    };

}//nsWin32

#endif//WINQL_GUI_WNDCLASS_H_3
