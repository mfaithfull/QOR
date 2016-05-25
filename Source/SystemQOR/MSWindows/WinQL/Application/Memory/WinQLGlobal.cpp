//WinQLGlobal.cpp

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
#include "WinQL/Application/Memory/WinQLGlobal.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CGlobalHelper );

	//------------------------------------------------------------------------------
	CGlobalHelper::CGlobalHelper()
	{
		_WINQ_FCONTEXT( "CGlobalHelper::CGlobalHelper" );
	}

	//------------------------------------------------------------------------------
	CGlobalHelper::~CGlobalHelper()
	{
		_WINQ_FCONTEXT( "CGlobalHelper::~CGlobalHelper" );
	}

	//------------------------------------------------------------------------------
	void* CGlobalHelper::Alloc( unsigned int uFlags, Cmp_ulong_ptr uBytes ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Alloc" );
		HGLOBAL h = 0;
		__QOR_PROTECT
		{
			h = CKernel32::GlobalAlloc( uFlags, uBytes );
		}__QOR_ENDPROTECT
		return h;
	}

	//------------------------------------------------------------------------------
	unsigned int CGlobalHelper::Flags( void* hMem ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Flags" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = CKernel32::GlobalFlags( hMem );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//------------------------------------------------------------------------------
	void* CGlobalHelper::Free( void* hMem ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Free" );
		HGLOBAL h = 0;
		__QOR_PROTECT
		{
			h = CKernel32::GlobalFree( hMem );
		}__QOR_ENDPROTECT
		return h;
	}

	//------------------------------------------------------------------------------
	void* CGlobalHelper::Handle( const void* pMem ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Handle" );
		HGLOBAL h = 0;
		__QOR_PROTECT
		{
			h = CKernel32::GlobalHandle( pMem );
		}__QOR_ENDPROTECT
		return h;
	}

	//------------------------------------------------------------------------------
	void* CGlobalHelper::Lock( void* hMem ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Lock" );
		LPVOID pResult = 0;
		__QOR_PROTECT
		{
			pResult = CKernel32::GlobalLock( hMem );
		}__QOR_ENDPROTECT
		return pResult;
	}

	//------------------------------------------------------------------------------
	void* CGlobalHelper::ReAlloc( void* hMem, Cmp_ulong_ptr uBytes, unsigned int uFlags) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::ReAlloc" );
		HGLOBAL h = 0;
		__QOR_PROTECT
		{
			h = CKernel32::GlobalReAlloc( hMem, uBytes, uFlags );
		}__QOR_ENDPROTECT
		return h;
	}

	//------------------------------------------------------------------------------
	Cmp_ulong_ptr CGlobalHelper::Size( void* hMem ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Size" );
		SIZE_T Result = 0;
		__QOR_PROTECT
		{
			Result = CKernel32::GlobalSize( hMem );
		}__QOR_ENDPROTECT
		return Result;
	}

	//------------------------------------------------------------------------------
	bool CGlobalHelper::Unlock( void* hMem ) const
	{
		_WINQ_FCONTEXT( "CGlobalHelper::Unlock" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::GlobalUnlock( hMem ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

}//nsWin32

