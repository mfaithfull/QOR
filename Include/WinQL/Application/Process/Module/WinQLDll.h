//WinQLDll.h

// Copyright Querysoft Limited 2013
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

//Win32 Code Services Dynamic Link Libraries

#ifndef WINQL_CODESERV_DLL_H_2
#define WINQL_CODESERV_DLL_H_2

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "../Source/SystemQOR/MSWindows/WinQAPI/include/ErrorDomain.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/Library.h"
#include "WinQL/WinQL.h"
#include "WinQL/Definitions/Handles.h"
#include "WinQL/Application/Process/Module/WinQLModule.h"
#include "WinQL/Application/Process/WinQLAtExit.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	#define DLL_PROCESS_ATTACH   1    
	#define DLL_THREAD_ATTACH    2    
	#define DLL_THREAD_DETACH    3    
	#define DLL_PROCESS_DETACH   0  

	typedef Cmp_int_ptr ( __QCMP_STDCALLCONVENTION *FARPROC )( void );

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CDll : public CWinModule, public nsWinQAPI::CLibrary
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CDll );

		typedef int( *DefProc )( void );//Default procedure pointer type

		CDll( const TCHAR* lpFileName );
		CDll( const TCHAR* lpFileName, void* hFile, unsigned long dwFlags );
		CDll( void* hModule, bool bDontFree = false );
		virtual ~CDll();
		bool DisableThreadLibraryCalls( void );
		void Free( void );
		void FreeAndExitThread( unsigned long dwExitCode );
		unsigned long GetFileName( TCHAR* lpFilename, unsigned long nSize );
		nsWin32::FARPROC GetProcAddress( const char* lpProcName );
		static bool GetEx( unsigned long dwFlags, const TCHAR* lpModuleName, CDll* /*phModule*/ );
		static unsigned long GetDirectory( unsigned long nBufferLength, TCHAR* lpBuffer );
		static bool SetDllDirectoryT( const TCHAR* lpPathName );

		//--------------------------------------------------------------------------------
		CAtExit& AtExitList()
		{
			return m_AtExitList; 
		}

	protected:

		CAtExit				m_AtExitList;			
		CDll( CHandle& hModule );

	private:
			
		bool m_bExitThread;
		unsigned long m_dwExitCode;
		bool m_bDontFree;

		CDll( const CDll& );
		CDll& operator = ( const CDll& );
	};

}//nsWin32

#endif//WINQL_CODESERV_DLL_H_2
