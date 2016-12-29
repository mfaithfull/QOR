//WinQLRAIISessionHandle.cpp

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
#include "WinQL/CodeServices/Handles/WinQLRAIISessionHandle.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CRAIISessionHandle );

	//--------------------------------------------------------------------------------
	CRAIISessionHandle::CRAIISessionHandle( void* pObj, void* h ) : CHandle( h )
	{
		_WINQ_FCONTEXT( "CRAIISessionHandle::CRAIISessionHandle" );
		CHandle::Attach( pObj );
	}

	//--------------------------------------------------------------------------------
	CRAIISessionHandle& CRAIISessionHandle::operator = ( void* h )
	{
		_WINQ_FCONTEXT( "CRAIISessionHandle::operator =" );
		CHandle::m_h = h;
		return *this;
	}

	//--------------------------------------------------------------------------------
	CRAIISessionHandle::~CRAIISessionHandle()
	{
		_WINQ_FCONTEXT( "CRAIISessionHandle::~CRAIISessionHandle" );
		Drop();
	}

	//--------------------------------------------------------------------------------
	bool CRAIISessionHandle::operator == ( const CRAIISessionHandle& Cmp )
	{
		return ( CHandle::m_pObject == Cmp.AsHandle().Object() || CHandle::m_h == Cmp.ptr() );
	}

	//--------------------------------------------------------------------------------
	bool CRAIISessionHandle::IsNull( void ) const
	{
		_WINQ_FCONTEXT( "CRAIISessionHandle::IsNull" );
		return CHandle::IsNull();
	}

	//--------------------------------------------------------------------------------
	void* CRAIISessionHandle::Use( void ) const
	{
		_WINQ_FCONTEXT( "CRAIISessionHandle::Use" );
		return CHandle::ptr();
	}

	//--------------------------------------------------------------------------------
	CHandle& CRAIISessionHandle::AsHandle( void ) const
	{
		_WINQ_FCONTEXT( "CRAIISessionHandle::AsHandle" );
		return CHandle::Handle();
	}

	//--------------------------------------------------------------------------------
	CRAIISessionHandle::refType CRAIISessionHandle::Ref( void )
	{
		CRAIISessionHandle::refType Ref( this, false );
		return Ref;
	}

}//nsWin32