//SanQLProcess.cpp

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

//Implements the CProcess class representing the executing SanOS process

#include <limits.h>
#include "CodeQOR/Instancing/sTOB.h"
//#include "CodeQOR/ErrorSystem/Error.h"
//#include "../SystemQOR/MSWindows/WinQAPI/include/ErrorDomain.h"
//#include "../SystemQOR/MSWindows/WinQAPI/include/DynamicLibrary.h"
//#include "WinQL/CodeServices/ErrorSystem/Error.h"
#include "SanQL/CodeServices/Process.h"
#include "SanQL/CodeServices/Thread.h"
//#include "WinQAPI/Kernel32.h"
//#include "WinQAPI/User32.h"
//#include "WinQAPI/PSAPI.h"

//------------------------------------------------------------------------------
namespace nsSanOS
{
	//using namespace nsWinQAPI;

	nsCodeQOR::sTOB< CProcess > theSanOSProcess;

	__QOR_IMPLEMENT_OCLASS_GUID( CProcess, 0x9c8a6e9, 0x7b0b, 0x428f, 0xae, 0x88, 0x99, 0xa9, 0xc8, 0x58, 0x14, 0x3e )	// {09C8A6E9-7B0B-428F-AE88-99A9C858143E}

	//--------------------------------------------------------------------------------
	CProcessModuleInitializer::CProcessModuleInitializer()
	{			
		theSanOSProcess->GetId();
	}

	//--------------------------------------------------------------------------------
	CProcessModuleInitializer::~CProcessModuleInitializer()
	{
		
	}

	//--------------------------------------------------------------------------------
	CProcess* CProcess::ThisProcess()
	{
		//_WINQ_SFCONTEXT( "CProcess::ThisProcess" );
		return dynamic_cast< CProcess* >( nsCodeQOR::CProcessBase::ThisProcess() );
	}

	// {B581519C-9BA8-442B-AF56-56D25E9ACAB2}
	//__QOR_IMPLEMENT_OCLASS_GUID( CProcessHelper, 0xb581519c, 0x9ba8, 0x442b, 0xaf, 0x56, 0x56, 0xd2, 0x5e, 0x9a, 0xca, 0xb2 )

	/*
	//--------------------------------------------------------------------------------
	CProcessHelper::CProcessHelper() : m_PSAPI( CPSAPI::Instance() )
	{
		_WINQ_FCONTEXT( "CProcessHelper::CProcessHelper" );
	}

	//--------------------------------------------------------------------------------
	CProcessHelper::CProcessHelper( const CProcessHelper& ) : m_PSAPI( CPSAPI::Instance() )
	{
	}

	//--------------------------------------------------------------------------------
	CProcessHelper& CProcessHelper::operator=( const CProcessHelper& )
	{
		return *this;
	}

	//--------------------------------------------------------------------------------
	CProcessHelper::~CProcessHelper()
	{
		_WINQ_FCONTEXT( "CProcessHelper::~CProcessHelper" );
	}

	//------------------------------------------------------------------------------
	TCHAR* CProcessHelper::GetCommandLineT()
	{
		_WINQ_FCONTEXT( "CProcessHelper::GetCommandLine" );
		LPTSTR pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::GetCommandLine();
		}__QOR_ENDPROTECT
		return pResult;
	}

	//------------------------------------------------------------------------------
	void CProcessHelper::GetStartupInfoT( nsWin32::LPSTARTUPINFO lpStartupInfo )
	{
		_WINQ_FCONTEXT( "CProcessHelper::GetStartupInfo" );
		CKernel32::GetStartupInfo( reinterpret_cast< ::LPSTARTUPINFO >( lpStartupInfo ) );
	}

	//--------------------------------------------------------------------------------
	unsigned long CProcessHelper::LoadModule( const char* lpModuleName, void* lpParameterBlock )
	{
		_WINQ_FCONTEXT( "CProcessHelper::LoadModule" );
		unsigned long ulResult = 0;
		__QOR_PROTECT
		{
			ulResult = nsWinQAPI::CKernel32::Instance().LoadModule( lpModuleName, lpParameterBlock );
		}__QOR_ENDPROTECT
		return ulResult;
	}

	//--------------------------------------------------------------------------------
	bool CProcessHelper::EnumProcessModulesEx( ModuleHandle hProcess, ModuleHandle* lphModule, unsigned long cb, unsigned long* lpcbNeeded, unsigned long dwFilterFlag )
	{
		_WINQ_FCONTEXT( "CProcessHelper::EnumProcessModulesEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_PSAPI.EnumProcessModulesEx( hProcess, reinterpret_cast< HMODULE* >( lphModule ), cb, lpcbNeeded, dwFilterFlag ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}
	*/
	//--------------------------------------------------------------------------------
	nsCodeQOR::CThreadContextBase* CProcess::ThreadContext( void )
	{
		//Can't have function context here because this is required by function context initialisation
		return 0;//t_pCurrentWin32Thread;
	}
	
	//--------------------------------------------------------------------------------
	CProcess::CProcess() //: CWinModule( CProcess::GetCurrentHandle().Use() )
	{
		//_WINQ_FCONTEXT( "CProcess::CProcess" );
		//m_hProcess = m_Handle.ptr();
		//m_hInstance = ( InstanceHandle )&__ImageBase;
		//m_Name = 0;
	}

	//------------------------------------------------------------------------------
	unsigned long CProcess::GetId( void )
	{
		return 0;//SanOS is Uniprocess
	}

	/*
	//------------------------------------------------------------------------------
	CProcess::CProcess( void* hProcess ) : CWinModule( hProcess )
	{
		_WINQ_FCONTEXT( "CProcess::CProcess" );
		m_hProcess = hProcess;
		m_hInstance = ( InstanceHandle )&__ImageBase;
		m_Name = 0;
		//t_pCurrentWin32Thread = 0;
	}

	//------------------------------------------------------------------------------
	CProcess::CProcess( unsigned long dwDesiredAccess, bool bInheritHandle, unsigned long dwProcessId ) //: m_Initializer( 0 )
	{			
		_WINQ_FCONTEXT( "CProcess::CProcess" );
		__QOR_PROTECT
		{
			m_hProcess = CKernel32::OpenProcess( dwDesiredAccess, bInheritHandle ? TRUE : FALSE, dwProcessId );
			m_Name = 0;

		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	CProcess::CProcess( const TCHAR* lpApplicationName, TCHAR* lpCommandLine, nsWin32::LPSECURITY_ATTRIBUTES lpProcessAttributes, nsWin32::LPSECURITY_ATTRIBUTES lpThreadAttributes, bool bInheritHandles, unsigned long dwCreationFlags, void* lpEnvironment, const TCHAR* lpCurrentDirectory, nsWin32::LPSTARTUPINFO lpStartupInfo, nsWin32::ProcessInformation* lpProcessInformation ) //: m_Initializer( 0 )
	{
		_WINQ_FCONTEXT( "CProcess::CProcess" );
		__QOR_PROTECT
		{
			CKernel32::CreateProcess( lpApplicationName, lpCommandLine, reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpProcessAttributes ), reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpThreadAttributes ), bInheritHandles ? TRUE : FALSE, dwCreationFlags, lpEnvironment, lpCurrentDirectory, reinterpret_cast< ::LPSTARTUPINFO >( lpStartupInfo ), reinterpret_cast< ::LPPROCESS_INFORMATION >( lpProcessInformation ) );
			if( lpProcessInformation != 0 )
			{
				m_hProcess = lpProcessInformation->hProcess;
				m_Name = const_cast< TCHAR* >( lpApplicationName );
			}
			else
			{
				//TODO: Raise an error
			}
		}__QOR_ENDPROTECT
	}
	*/
	//------------------------------------------------------------------------------
	CProcess::~CProcess()
	{
		//_WINQ_FCONTEXT( "CProcess::~CProcess" );
	}

	//------------------------------------------------------------------------------
	void CProcess::Exit( unsigned int uExitCode )
	{
		/*
		_WINQ_SFCONTEXT( "CProcess::Exit" );
		__QOR_PROTECT
		{
			CKernel32::ExitProcess( uExitCode );
		}__QOR_ENDPROTECT
		*/
	}

	//------------------------------------------------------------------------------
	CProcess* CProcess::GetCurrent()
	{
		//_WINQ_SFCONTEXT( "CProcess::GetCurrent" );
		/*
		CHandle hProcess = CKernel32::GetCurrentProcess();
		CWinModule* pModule = CWinModule::FromHandle( hProcess );
		return dynamic_cast< CProcess* >( pModule );
		*/
		return 0;
	}
	/*
	//------------------------------------------------------------------------------
	unsigned long CProcess::GetCurrentId()
	{
		_WINQ_SFCONTEXT( "CProcess::GetCurrentId" );
		return CKernel32::GetCurrentProcessId();
	}

	//------------------------------------------------------------------------------
	CHandle CProcess::GetCurrentHandle()
	{
		CHandle hProcess = CKernel32::GetCurrentProcess();
		return hProcess;
	}

	//------------------------------------------------------------------------------
	bool CProcess::GetExitCode( unsigned long* lpExitCode )
	{
		_WINQ_FCONTEXT( "CProcess::GetExitCode" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::GetExitCodeProcess( m_hProcess, lpExitCode ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	void* CProcess::Handle() const
	{
		_WINQ_FCONTEXT( "CProcess::Handle" );
		return m_hProcess;
	}

	//------------------------------------------------------------------------------
	void* CProcess::Instance() const
	{
		_WINQ_FCONTEXT( "CProcess::Instance" );
		return m_hInstance;
	}

	//--------------------------------------------------------------------------------
	mxTCHAR* CProcess::Name( void )
	{
		if( m_Name != 0 )
		{
			return m_Name;
		}
		else
		{
			return _CTXT( "unnamed" );
		}
	}
	*/
	//--------------------------------------------------------------------------------
	int CProcess::ProcessCommandLine( int& argc, char**& argv )
	{
		return 0;

	}

	//--------------------------------------------------------------------------------
	void CProcess::ParseCommandLine( char** argv,  char* args, int* piArgumentCount, int* piCharacterCount )
	{
	}

	//--------------------------------------------------------------------------------
	bool CProcess::ParseArgument( char** argv, char* args, int* piArgumentCount, int* piCharacterCount, char* p, bool& bInQuote, bool& bCopyChar, unsigned int& numslash )
	{
		return true;
	}

	//--------------------------------------------------------------------------------
	bool CProcess::ParseOneArgument( char* args, int* piCharacterCount, bool& bInQuote, bool& bCopyChar, unsigned int& numslash, char* p )
	{
		return true;
	}
}//nsWin32

