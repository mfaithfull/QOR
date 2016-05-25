//WinQLSystemHelper.cpp

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

#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/System/WinQLSystemHelper.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CSystemHelper );

	//--------------------------------------------------------------------------------
	CSystemHelper::CSystemHelper()
	{
		_WINQ_FCONTEXT( "CSystemHelper::CSystemHelper" );
	}

	//--------------------------------------------------------------------------------
	CSystemHelper::CSystemHelper( const CSystemHelper& src )
	{
		_WINQ_FCONTEXT( "CsystemHelper::CSystemHelper" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CSystemHelper& CSystemHelper::operator = ( const CSystemHelper& src )
	{
		_WINQ_FCONTEXT( "CsystemHelper::operator =" );
		if( &src != this )
		{
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	CSystemHelper::~CSystemHelper()
	{
		_WINQ_FCONTEXT( "CSystemHelper::~CSystemHelper" );
	}

	//--------------------------------------------------------------------------------
	unsigned long CSystemHelper::AddLocalAlternateComputerName( const TCHAR* lpDnsFQHostname, unsigned long ulFlags )
	{
		_WINQ_FCONTEXT( "CSystemHelper::AddLocalAlternateComputerName" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::AddLocalAlternateComputerName( lpDnsFQHostname, ulFlags );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	nsWin32::FARPROC CSystemHelper::DelayLoadFailureHook( const char* pszDllName, const char* pszProcName )
	{
		_WINQ_FCONTEXT( "CSystemHelper::DelayLoadFailureHook" );
		FARPROC pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::DelayLoadFailureHook( pszDllName, pszProcName );
		}__QOR_ENDPROTECT
		return pResult;
	}

	//--------------------------------------------------------------------------------
	void* CSystemHelper::DecodePointer( void* Ptr )
	{
		_WINQ_FCONTEXT( "CSystemHelper::DecodePointer" );
		PVOID pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::DecodePointer( Ptr );
		}__QOR_ENDPROTECT
		return pResult;
	}

	//--------------------------------------------------------------------------------
	void* CSystemHelper::DecodeSystemPointer( void* Ptr )
	{
		_WINQ_FCONTEXT( "CSystemHelper::DecodeSystemPointer" );
		PVOID pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::DecodeSystemPointer( Ptr );
		}__QOR_ENDPROTECT
		return pResult;
	}

	//--------------------------------------------------------------------------------
	void* CSystemHelper::EncodePointer( void* Ptr )
	{
		_WINQ_FCONTEXT( "CSystemHelper::EncodePointer" );
		PVOID pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::EncodePointer( Ptr );
		}__QOR_ENDPROTECT
		return pResult;
	}

	//--------------------------------------------------------------------------------
	void* CSystemHelper::EncodeSystemPointer( void* Ptr )
	{
		_WINQ_FCONTEXT( "CSystemHelper::EncodeSystemPointer" );
		PVOID pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::EncodeSystemPointer( Ptr );
		}__QOR_ENDPROTECT
		return pResult;
	}

}//nsWin32
