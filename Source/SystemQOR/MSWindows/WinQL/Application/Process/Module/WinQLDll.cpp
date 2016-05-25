//WinQLDll.cpp

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

//Implements the CDll class representing a Windows dynamic library at runtime

#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/Application/Process/Module/WinQLDll.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CDll );

	//------------------------------------------------------------------------------
	CDll::CDll( void* hModule, bool bDontFree ) : CWinModule( hModule ), nsWinQAPI::CLibrary()
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		__QOR_PROTECT
		{
			m_bDontFree = bDontFree;
			m_bExitThread = false;
			m_dwExitCode = 0;
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	CDll::CDll( const TCHAR* lpFileName ) : CWinModule( CKernel32::LoadLibrary( lpFileName ) ), nsWinQAPI::CLibrary()
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		m_bDontFree = false;
		m_bExitThread = false;
		m_dwExitCode = 0;
	}

	//------------------------------------------------------------------------------
	CDll::CDll( const TCHAR* lpFileName, void* hFile, unsigned long dwFlags ) : CWinModule( CKernel32::LoadLibraryEx( lpFileName, hFile, dwFlags ) ), nsWinQAPI::CLibrary()
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		m_bDontFree = false;
		m_bExitThread = false;
		m_dwExitCode = 0;
	}

	//------------------------------------------------------------------------------
	CDll::~CDll()
	{
		_WINQ_FCONTEXT( "CDll::~CDll" );
		__QOR_PROTECT
		{
			if(!m_bDontFree)
			{
				m_AtExitList.Invoke();

				if( m_bExitThread )
				{
					CKernel32::FreeLibraryAndExitThread( (HMODULE)m_Handle.Use(), m_dwExitCode );
				}
				else
				{
					CKernel32::FreeLibrary( (HMODULE)m_Handle.Use() );
				}
			}
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	bool CDll::DisableThreadLibraryCalls()
	{
		_WINQ_FCONTEXT( "CDll::DisableThreadLibraryCalls" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::DisableThreadLibraryCalls( (HMODULE)m_Handle.Use() ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	void CDll::Free()
	{
		_WINQ_FCONTEXT( "CDll::Free" );
		__QOR_PROTECT
		{
			delete this;
		}__QOR_ENDPROTECT			
	}

	//------------------------------------------------------------------------------
	void CDll::FreeAndExitThread( unsigned long dwExitCode )
	{
		_WINQ_FCONTEXT( "CDll::FreeAndExitThread" );
		__QOR_PROTECT
		{
			m_dwExitCode = dwExitCode;
			m_bExitThread = true;
			delete this;
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	unsigned long CDll::GetFileName( TCHAR* lpFilename, unsigned long nSize )
	{
		_WINQ_FCONTEXT( "CDll::GetFileName" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetModuleFileName( (HMODULE)m_Handle.Use(), lpFilename, nSize );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	//static CDll& Get( LPCTSTR lpModuleName )
	//{
	//	HANDLE hModule = CKernel32::GetModuleHandle( lpModuleName );
	//	//TODO: Look up the internal static map to get the CDll object from the handle
	//}

	//------------------------------------------------------------------------------
	nsWin32::FARPROC CDll::GetProcAddress( const char* lpProcName )
	{
		_WINQ_FCONTEXT( "CDll::GetProcAddress" );
		FARPROC pResult = 0;
		__QOR_PROTECT
		{
			pResult = (FARPROC)( CKernel32::GetProcAddress( (HMODULE)m_Handle.Use(), lpProcName ) );
		}__QOR_ENDPROTECT
		return pResult;
	}


	//------------------------------------------------------------------------------
	bool CDll::GetEx( unsigned long dwFlags, const TCHAR* lpModuleName, CDll* /*phModule*/ )
	{
		_WINQ_SFCONTEXT( "CDll::GetEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			HMODULE hModule;
			bResult = CKernel32::GetModuleHandleEx( dwFlags, lpModuleName, &hModule ) ? true : false;
			///TODO: Look up the internal static map to get the CDll object from the handle
		}__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CDll::GetDirectory( unsigned long nBufferLength, TCHAR* lpBuffer )
	{
		_WINQ_SFCONTEXT( "CDll::GetDirectory" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetDllDirectory( nBufferLength, lpBuffer );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CDll::SetDllDirectoryT( const TCHAR* lpPathName )
	{
		_WINQ_SFCONTEXT( "CDll::SetDllDirectory" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::SetDllDirectory( lpPathName ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//protected:


	//------------------------------------------------------------------------------
	CDll::CDll( CHandle& hModule ) : CWinModule( hModule ), nsWinQAPI::CLibrary()
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		m_bExitThread = false;
		m_dwExitCode = 0;
	}

}//nsWin32
