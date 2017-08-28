//WinQLRegistryHelper.h

// Copyright Querysoft Limited 2015, 2017
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

#ifndef WINQL_SYSTEM_REGISTRY_HELPER_H_3
#define WINQL_SYSTEM_REGISTRY_HELPER_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/codingmacros.h"
#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/Definitions/Handles.h"
#include "WinQL/Definitions/Security.h"
#include "WinQL/Definitions/IO.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CAdvAPI32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	//Registry helper class
	class __QOR_INTERFACE( __WINQL ) CRegistryHelper
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CRegistryHelper );
			
		CRegistryHelper();
		~CRegistryHelper();

		long DisablePredefinedCache( void );
		long DisablePredefinedCacheAll( void );

		unsigned int GetPrivateProfileIntT( const TCHAR* lpAppName, const TCHAR* lpKeyName, int nDefault, const TCHAR* lpFileName );
		unsigned long GetPrivateProfileSectionT( const TCHAR* lpAppName, TCHAR* lpReturnedString, unsigned long nSize, const TCHAR* lpFileName );
		unsigned long GetPrivateProfileSectionNamesT( TCHAR* lpszReturnBuffer, unsigned long nSize, const TCHAR*lpFileName );
		unsigned long GetPrivateProfileStringT( const TCHAR* lpAppName, const TCHAR* lpKeyName, const TCHAR* lpDefault, TCHAR* lpReturnedString, unsigned long nSize, const TCHAR* lpFileName );
		bool GetPrivateProfileStructT( const TCHAR* lpszSection, const TCHAR* lpszKey, void* lpStruct, unsigned int uSizeStruct, const TCHAR* szFile );
		unsigned int GetProfileIntT( const TCHAR* lpAppName, const TCHAR* lpKeyName, int nDefault );
		unsigned long GetProfileSectionT( const TCHAR* lpAppName, TCHAR* lpReturnedString, unsigned long nSize );
		unsigned long GetProfileStringT( const TCHAR* lpAppName, const TCHAR* lpKeyName, const TCHAR* lpDefault, TCHAR* lpReturnedString, unsigned long nSize );
		bool WritePrivateProfileSectionT( const TCHAR* lpAppName, const TCHAR* lpString, const TCHAR* lpFileName );
		bool WritePrivateProfileStringT( const TCHAR* lpAppName, const TCHAR* lpKeyName, const TCHAR* lpString, const TCHAR* lpFileName );
		bool WritePrivateProfileStructT( const TCHAR* lpszSection, const TCHAR* lpszKey, void* lpStruct, unsigned int uSizeStruct, const TCHAR* szFile );
		bool WriteProfileSectionT( const TCHAR* lpAppName, const TCHAR* lpString );
		bool WriteProfileStringT( const TCHAR* lpAppName, const TCHAR* lpKeyName, const TCHAR* lpString );

	private:

		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;
		CRegistryHelper( const CRegistryHelper& );
		CRegistryHelper& operator = ( const CRegistryHelper& );
	};

}//nsWin32

#endif//WINQL_SYSTEM_REGISTRY_HELPER_H_3
