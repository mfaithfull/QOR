//WinQLHandle.h

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

//Win32 Handle object wrapper

#ifndef WINQL_CS_HANDLE_H_3
#define WINQL_CS_HANDLE_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/ClassReg/ClassRegEntry.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CHandle
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CHandle );

		CHandle();
		CHandle( void* h );
		virtual ~CHandle();
		CHandle( const CHandle& );
		CHandle& operator = ( const CHandle& );
		CHandle CHandle::Clone( void* hSourceProcessHandle, void* hTargetProcessHandle, unsigned long dwDesiredAccess, bool bInheritHandle, unsigned long dwOptions );
		virtual bool Attach( void* pObj );
		virtual void* Detach( void );
		virtual void* Object( void ) const;
		bool Duplicate( void* hSourceProcessHandle, void* hTargetProcessHandle, void** lpTargetHandle, unsigned long dwDesiredAccess, bool bInheritHandle, unsigned long dwOptions );
		bool GetInformation( unsigned long* lpdwFlags );
		bool SetInformation( unsigned long dwMask, unsigned long dwFlags );
		virtual void Close( void );
		bool IsNull( void ) const;
		bool IsInvalid( void );
		void Drop( void );
		virtual void* Use( void ) const;

		void* ptr( void ) const
		{
			return m_h;
		}

		void** pptr( void )
		{
			return &m_h;
		}

		CHandle& Handle( void ) const
		{
			return const_cast< CHandle& >( *this );
		}

		bool operator == ( CHandle& Cmp )
		{
			return ( m_pObject == Cmp.m_pObject || m_h == Cmp.m_h ) ? true : false;
		}

		bool operator < ( const CHandle& Cmp )
		{
			return m_h < Cmp.m_h;
		}

	protected:

		void* m_h;
		void* m_pObject;

	};

}//nsWin32

#endif//WINQL_CS_HANDLE_H_3
