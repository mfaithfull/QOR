//DynamicLibrary.cpp

// Copyright Querysoft Limited 2015
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

#include "WinQAPI/Kernel32.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/DynamicLibrary.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/Error.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/FunctionContext.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	__QOR_IMPLEMENT_OCLASS_GUID( CDll, 0x27afa9a0, 0x898e, 0x4441, 0xbb, 0x5b, 0x4a, 0x3b, 0x59, 0x93, 0x67, 0x3c );	// {27AFA9A0-898E-4441-BB5B-4A3B5993673C}

	//------------------------------------------------------------------------------
	CDll::CDll( const CDll& src )
	{
		m_bExitThread = src.m_bExitThread;
		m_dwExitCode = src.m_dwExitCode;
		m_hModule = src.m_hModule;
		m_bDontFree = src.m_bDontFree;
		(const_cast< CDll& >( src ) ).m_bDontFree = true;
		(const_cast< CDll& >( src ) ).m_bExitThread = false;
	}

	//------------------------------------------------------------------------------
	CDll::CDll( const TCHAR* lpFileName )
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		m_bExitThread = false;
		m_dwExitCode = 0;
		m_hModule = CKernel32::LoadLibrary( lpFileName );
		m_bDontFree = false;
	}

	//------------------------------------------------------------------------------
	CDll::CDll( const TCHAR* lpFileName, void* hFile, unsigned long dwFlags )
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		m_bExitThread = false;
		m_dwExitCode = 0;
		m_hModule = CKernel32::LoadLibraryEx( lpFileName, hFile, dwFlags );
		m_bDontFree = false;
	}

	//------------------------------------------------------------------------------
	CDll::~CDll()
	{
		_WINQ_FCONTEXT( "CDll::~CDll" );

		if( !m_bDontFree )
		{
			if( m_bExitThread )
			{
				CKernel32::FreeLibraryAndExitThread( m_hModule, m_dwExitCode );
			}
			else
			{
				CKernel32::FreeLibrary( m_hModule );
			}
		}
	}

	//------------------------------------------------------------------------------
	bool CDll::DisableThreadLibraryCalls()
	{
		_WINQ_FCONTEXT( "CDll::DisableThreadLibraryCalls" );
		bool bResult = false;
		bResult = CKernel32::DisableThreadLibraryCalls( m_hModule ) ? true : false;
		return bResult;
	}

	//------------------------------------------------------------------------------
	void CDll::Free()
	{
		_WINQ_FCONTEXT( "CDll::Free" );
		delete this;
	}

	//------------------------------------------------------------------------------
	void CDll::FreeAndExitThread( unsigned long dwExitCode )
	{
		_WINQ_FCONTEXT( "CDll::FreeAndExitThread" );
		m_dwExitCode = dwExitCode;
		m_bExitThread = true;
		delete this;
	}

	//------------------------------------------------------------------------------
	unsigned long CDll::GetFileName( TCHAR* lpFilename, unsigned long nSize )
	{
		_WINQ_FCONTEXT( "CDll::GetFileName" );
		DWORD dwResult = 0;
		dwResult = CKernel32::GetModuleFileName( m_hModule, lpFilename, nSize );
		return dwResult;
	}

	//------------------------------------------------------------------------------
	nsWinQAPI::FARPROC CDll::GetProcAddress( const char* lpProcName )
	{
		_WINQ_FCONTEXT( "CDll::GetProcAddress" );
		FARPROC pResult = 0;
		pResult = (FARPROC)( CKernel32::GetProcAddress( m_hModule, lpProcName ) );
		return pResult;
	}


	//------------------------------------------------------------------------------
	bool CDll::GetEx( unsigned long dwFlags, const TCHAR* lpModuleName, CDll* /*phModule*/ )
	{
		_WINQ_SFCONTEXT( "CDll::GetEx" );
		bool bResult = false;
		HMODULE hModule;
		bResult = CKernel32::GetModuleHandleEx( dwFlags, lpModuleName, &hModule ) ? true : false;
		///TODO: Look up the internal static map to get the CDll object from the handle
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CDll::GetDirectory( unsigned long nBufferLength, TCHAR* lpBuffer )
	{
		_WINQ_SFCONTEXT( "CDll::GetDirectory" );
		DWORD dwResult = 0;
		dwResult = CKernel32::GetDllDirectory( nBufferLength, lpBuffer );
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CDll::SetDllDirectoryT( const TCHAR* lpPathName )
	{
		_WINQ_SFCONTEXT( "CDll::SetDllDirectory" );
		bool bResult = false;
		bResult = CKernel32::SetDllDirectory( lpPathName ) ? true : false;
		return bResult;
	}

	//------------------------------------------------------------------------------
	HMODULE CDll::Handle( void )
	{
		_WINQ_FCONTEXT( "CDll::Handle" );
		return m_hModule;
	}

	//------------------------------------------------------------------------------
	CDll::CDll( HMODULE hModule, bool bDontFree )
	{
		_WINQ_FCONTEXT( "CDll::CDll" );
		m_hModule = hModule;
		m_bExitThread = false;
		m_dwExitCode = 0;
		m_bDontFree = bDontFree;
	}

}//nsWinQAPI

