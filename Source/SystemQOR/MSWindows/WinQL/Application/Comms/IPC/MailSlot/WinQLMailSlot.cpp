//WinQLMailSlot.cpp

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
#include "WinQL/Application/Comms/IPC/MailSlot/WinQLMailSlot.h"
#include <assert.h>
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CMailSlot );

	//------------------------------------------------------------------------------
	CMailSlot::CMailSlot( const TCHAR* lpName, unsigned long nMaxMessageSize, unsigned long lReadTimeout, nsWin32::LPSECURITY_ATTRIBUTES lpSecurityAttributes )
	{
		_WINQ_FCONTEXT( "CMailSlot::CMailSlot" );
		__QOR_PROTECT
		{
			m_Handle = CKernel32::CreateMailslot( lpName, nMaxMessageSize, lReadTimeout, reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpSecurityAttributes ) );
			m_Handle.Attach( this );
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	CMailSlot::~CMailSlot()
	{
		_WINQ_FCONTEXT( "CMailSlot::~CMailSlot" );
		__QOR_PROTECT
		{
			m_Handle.Close();
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	bool CMailSlot::GetInfo( unsigned long* lpMaxMessageSize, unsigned long* lpNextSize, unsigned long* lpMessageCount, unsigned long* lpReadTimeout )
	{
		_WINQ_FCONTEXT( "CMailSlot::GetInfo" );
		bool bResult = false;
		__QOR_PROTECT
		{
			assert( !m_Handle.IsNull() && !m_Handle.IsInvalid() );
			bResult = CKernel32::GetMailslotInfo( m_Handle.Use(), lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CMailSlot::SetInfo( unsigned long lReadTimeout )
	{
		_WINQ_FCONTEXT( "CMailSlot::SetInfo" );
		bool bResult = false;
		__QOR_PROTECT
		{
			assert( !m_Handle.IsNull() && !m_Handle.IsInvalid() );
			bResult = CKernel32::SetMailslotInfo( m_Handle.Use(), lReadTimeout ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CMailSlot::Read( void* pBuffer, unsigned long NumberOfBytesToRead, unsigned long& NumberOfBytesRead, OVERLAPPED* pOverlapped )
	{
		_WINQ_FCONTEXT( "CMailSlot::Read" );
		bool bResult = false;
		__QOR_PROTECT
		{
			assert( !m_Handle.IsNull() && !m_Handle.IsInvalid() );
			bResult = CKernel32::ReadFile( m_Handle.Use(), pBuffer, NumberOfBytesToRead, &NumberOfBytesRead, reinterpret_cast< ::LPOVERLAPPED >( pOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CMailSlot::Read( void* pBuffer, unsigned long NumberOfBytesToRead, OVERLAPPED* pOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE pCompletionRoutine )
	{
		_WINQ_FCONTEXT( "CMailSlot::Read" );
		bool bResult = false;
		__QOR_PROTECT
		{
			assert( !m_Handle.IsNull() && !m_Handle.IsInvalid() );
			bResult = CKernel32::ReadFileEx( m_Handle.Use(), pBuffer, NumberOfBytesToRead, reinterpret_cast< ::LPOVERLAPPED >( pOverlapped ), reinterpret_cast< ::LPOVERLAPPED_COMPLETION_ROUTINE >( pCompletionRoutine ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CMailSlot::Write( const void* pBuffer, unsigned long NumberOfBytesToWrite, unsigned long& NumberOfBytesWritten, OVERLAPPED* pOverlapped )
	{
		_WINQ_FCONTEXT( "CMailSlot::Write" );
		bool bResult = false;
		__QOR_PROTECT
		{
			assert( !m_Handle.IsNull() && !m_Handle.IsInvalid() );
			bResult = CKernel32::WriteFile( m_Handle.Use(), pBuffer, NumberOfBytesToWrite, &NumberOfBytesWritten, reinterpret_cast< ::LPOVERLAPPED >( pOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CMailSlot::Write( const void* pBuffer, unsigned long NumberOfBytesToWrite, OVERLAPPED* pOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE pCompletionRoutine )
	{
		_WINQ_FCONTEXT( "CMailSlot::Write" );
		bool bResult = false;
		__QOR_PROTECT
		{
			assert( !m_Handle.IsNull() && !m_Handle.IsInvalid() );
			bResult = CKernel32::WriteFileEx( m_Handle.Use(), pBuffer, NumberOfBytesToWrite, reinterpret_cast< ::LPOVERLAPPED >( pOverlapped ), reinterpret_cast< ::LPOVERLAPPED_COMPLETION_ROUTINE >( pCompletionRoutine ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}


}//nsWin32
