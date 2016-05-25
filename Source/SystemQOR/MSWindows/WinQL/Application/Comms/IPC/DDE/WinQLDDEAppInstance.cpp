//WinQLDDEAppInstance.cpp

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
#include "WinQL/Application/Comms/IPC/DDE/WinQLDDE.h"
#include "WinQAPI/User32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CDDEAppInstance );

	//--------------------------------------------------------------------------------
	CDDEAppInstance::CDDEAppInstance( unsigned long afCmd, int* pbResult ) : m_User32Library( CUser32::Instance() )
	{
		_WINQ_FCONTEXT( "CDDEAppInstance::CDDEAppInstance" );
		__QOR_PROTECT
		{
			m_pbResult = pbResult;
			m_uiInitResult = m_User32Library.DdeInitialize( &m_idInst, (PFNCALLBACK)&CallBack, afCmd , 0 );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CDDEAppInstance::~CDDEAppInstance()
	{
		_WINQ_FCONTEXT( "CDDEAppInstance::~CDDEAppInstance" );
		__QOR_PROTECT
		{
			BOOL bResult = m_User32Library.DdeUninitialize( m_idInst );
			if( m_pbResult != NULL )
			{
				*m_pbResult = bResult;
			}
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	unsigned long CDDEAppInstance::ID()
	{
		_WINQ_FCONTEXT( "CDDEAppInstance::ID" );
		return m_idInst;
	}

	//--------------------------------------------------------------------------------
	void* CDDEAppInstance::CallBack( unsigned int /*wType*/, unsigned int/*wFmt*/, void* /*hConv*/, void* /*hsz1*/, void* /*hsz2*/, void* /*hData*/, Cmp_ulong_ptr /*dwData1*/, Cmp_ulong_ptr/*dwData2*/ )
	{
		//TODO:
		void* result = 0;
		return result;
	}

	//--------------------------------------------------------------------------------
	unsigned int CDDEAppInstance::GetLastError()
	{
		_WINQ_FCONTEXT( "CDDEAppInstance::GetLastError" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_User32Library.DdeGetLastError( m_idInst );
		}__QOR_ENDPROTECT
		return uiResult;
	}



}//nsWin32
