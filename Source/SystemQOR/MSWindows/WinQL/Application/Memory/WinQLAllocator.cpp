//WinQLAllocator.cpp

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
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/Application/Memory/WinQLAllocator.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CWin32Allocator );

	//------------------------------------------------------------------------------
	CWin32Allocator::CWin32Allocator()
	{
		_WINQ_FCONTEXT( "CWin32Allocator::CWin32Allocator" );
		__QOR_PROTECT
		{
			m_hProcessHeap = CKernel32::GetProcessHeap();
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	CWin32Allocator::~CWin32Allocator()
	{
		_WINQ_FCONTEXT( "CWin32Allocator::~CWin32Allocator" );
	}

	//------------------------------------------------------------------------------
	void* CWin32Allocator::Allocate( unsigned long ulCount, unsigned long ulFlags )
	{		
		_WINQ_FCONTEXT( "CWin32Allocator::Allocate" );
		void* pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::HeapAlloc( m_hProcessHeap, ulFlags, ulCount );		
		}__QOR_ENDPROTECT
		return pResult;
	}

	//------------------------------------------------------------------------------
	void CWin32Allocator::Free( void* p )
	{
		_WINQ_FCONTEXT( "CWin32Allocator::Free" );
		__QOR_PROTECT
		{
			CKernel32::HeapFree( m_hProcessHeap, 0, p );
		}__QOR_ENDPROTECT
	}

}//nsWin32