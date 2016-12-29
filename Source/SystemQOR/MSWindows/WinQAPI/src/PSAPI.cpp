//PSAPI.cpp

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

#include "WinQAPI/WinQAPI.h"
#include "SystemQOR.h"
#include "WinQAPI/Kernel32.h"
#include "WinQAPI/PSAPI.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	//Removes as many pages as possible from the working set of the specified process.
	BOOL CPSAPI::EmptyWorkingSet( HANDLE hProcess )
	{
		_WINQ_FCONTEXT( "CPSAPI::EmptyWorkingSet" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( EmptyWorkingSet );
		bResult = Call< BOOL, HANDLE >( pFunc, hProcess );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	//Retrieves the load address for each device driver in the system.
	BOOL CPSAPI::EnumDeviceDrivers( LPVOID* lpImageBase, DWORD cb, LPDWORD lpcbNeeded )
	{
		_WINQ_FCONTEXT( "CPSAPI::EnumDeviceDrivers" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( EnumDeviceDrivers );
		bResult = Call< BOOL, LPVOID*, DWORD, LPDWORD >( pFunc, lpImageBase, cb, lpcbNeeded );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	//Calls the callback routine for each installed pagefile in the system.
	BOOL CPSAPI::EnumPageFiles( PENUM_PAGE_FILE_CALLBACK pCallbackRoutine, LPVOID lpContext )
	{
		_WINQ_FCONTEXT( "CPSAPI::EnumPageFiles" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( EnumPageFiles );
		bResult = Call< BOOL, PENUM_PAGE_FILE_CALLBACK, LPVOID >( pFunc, pCallbackRoutine, lpContext );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CPSAPI::EnumProcesses( DWORD* pProcessIds, DWORD cb, DWORD *pBytesReturned )
	{
		_WINQ_FCONTEXT( "CPSAPI::EnumProcesses" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;
		_WINQ_USESAPI( EnumProcesses );
		bResult = Call< BOOL, DWORD*, DWORD, DWORD* >( pFunc, pProcessIds, cb, pBytesReturned );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CPSAPI::EnumProcessModules( HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded )
	{
		_WINQ_FCONTEXT( "CPSAPI::EnumProcessModules" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;

		_WINQ_USESAPI( EnumProcessModules );
		bResult = Call< BOOL, HANDLE, HMODULE*, DWORD, LPDWORD >( pFunc, hProcess, lphModule, cb, lpcbNeeded );
		
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CPSAPI::EnumProcessModulesEx( HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded, DWORD dwFilterFlag )
	{
		_WINQ_FCONTEXT( "CPSAPI::EnumProcessModulesEx" );
		CCheckReturn< BOOL, CBoolCheck<> >::TType bResult;

		_WINQ_USESAPI( EnumProcessModulesEx );
		bResult = Call< BOOL, HANDLE, HMODULE*, DWORD, LPDWORD, DWORD >( pFunc, hProcess, lphModule, cb, lpcbNeeded, dwFilterFlag );

		return bResult;
	}

	//--------------------------------------------------------------------------------
	DWORD CPSAPI::GetDeviceDriverBaseName( LPVOID ImageBase, LPTSTR lpBaseName, DWORD nSize )
	{
		_WINQ_FCONTEXT( "CPSAPI::GetDeviceDriverBaseName" );
		CCheckReturn< DWORD, CCheckNonZero< DWORD > >::TType Result;
		_WINQ_USESAPIAW( GetDeviceDriverBaseName );
		Result = Call< DWORD, LPVOID, LPTSTR, DWORD >( pFunc, ImageBase, lpBaseName, nSize );
		return Result;
	}

	//--------------------------------------------------------------------------------
	DWORD CPSAPI::GetDeviceDriverFileName( LPVOID ImageBase, LPTSTR lpFilename, DWORD nSize )
	{
		_WINQ_FCONTEXT( "CPSAPI::GetDeviceDriverFileName" );
		CCheckReturn< DWORD, CCheckNonZero< DWORD > >::TType Result;
		_WINQ_USESAPIAW( GetDeviceDriverFileName );
		Result = Call< DWORD, LPVOID, LPTSTR, DWORD >( pFunc, ImageBase, lpFilename, nSize );
		return Result;
	}

}//nsWinQAPI
