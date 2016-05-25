//COSessionEx.h

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

#ifndef WINQL_COM_COSESSIONEX_H_3
#define WINQL_COM_COSESSIONEX_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Security.h"
#include "WinQL/COM/COSession.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_COM ) CCOSessionEx : public CCOSession
	{
	public:

		//--------------------------------------------------------------------------------
		enum COINIT 
		{
			COINIT_APARTMENTTHREADED   = 0x2,
			COINIT_MULTITHREADED       = 0x0,
			COINIT_DISABLE_OLE1DDE     = 0x4,
			COINIT_SPEED_OVER_MEMORY   = 0x8 
		};

		//--------------------------------------------------------------------------------
		enum AptTypeQualifier
		{
			APTTYPEQUALIFIER_NONE	= 0,
			APTTYPEQUALIFIER_IMPLICIT_MTA	= 1,
			APTTYPEQUALIFIER_NA_ON_MTA	= 2,
			APTTYPEQUALIFIER_NA_ON_STA	= 3,
			APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA	= 4,
			APTTYPEQUALIFIER_NA_ON_MAINSTA	= 5
		};

		//--------------------------------------------------------------------------------
		enum AptType
		{
			APTTYPE_CURRENT	= -1,
			APTTYPE_STA	= 0,
			APTTYPE_MTA	= 1,
			APTTYPE_NA	= 2,
			APTTYPE_MAINSTA	= 3
		};

		CCOSessionEx( unsigned long ulCoInit );
		virtual ~CCOSessionEx();
		long AllowSetForegroundWindow( void* pUnk );
		long CancelCall( unsigned long ulTimeout );
		void FreeAllLibraries( void );
		void FreeUnusedLibraries();
		void FreeUnusedLibrariesEx( unsigned long ulUnloadDelay );
		long GetApartmentType( AptType* pAptType, AptTypeQualifier* pAptQualifier );
		long GetCallContext( const GUID& riid, void** ppInterface );
		long GetCallerTID( unsigned long* pTID );
		long GetCurrentLogicalThreadId( GUID* pGuid );
		unsigned long GetCurrentUniqueThreadId();
		long GetMalloc( unsigned long ulMemContext, void** ppMalloc );

	protected:

		CCOSessionEx( dont_initialize* pIgnore );

	private:

		bool m_bUninitEx;

		CCOSessionEx();
		CCOSessionEx( const CCOSessionEx& );
		CCOSessionEx& operator = ( const CCOSessionEx& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_COM ) COLESessionEx : public CCOSessionEx
	{
	public:

		COLESessionEx();
		~COLESessionEx();

	private:

		bool m_bOLEUninitEx;

		COLESessionEx( const COLESessionEx& );
		COLESessionEx& operator = ( const COLESessionEx& );
	};

}//nsWin32

#endif//WINQL_COM_COSESSIONEX_H_3

