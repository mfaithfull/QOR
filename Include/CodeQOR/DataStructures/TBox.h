//TBox.h

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

//Managed object smart pointer

#ifndef CODEQOR_DATASTRUCTS_TBOX_H_2
#define CODEQOR_DATASTRUCTS_TBOX_H_2

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Traits/MemoryTraits.h"
#include "CodeQOR/MemoryManagement/SmallObjectHeap.h"
#include "CodeQOR/MemoryManagement/ManagedAllocator.h"

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//--------------------------------------------------------------------------------
	//A double dereference smart pointer to aid in creating 'managed' or 'boxed' objects
	//These should live on the stack
	template< typename T >
	class TBox
	{
	public:

		//--------------------------------------------------------------------------------
		TBox( unsigned int uiCount ) : m_uiReferenceCount( 0 )
		, m_uiCount( uiCount )
		, m_pObjectAllocation( 0 )
		{
			m_pObjectAllocation = UnsafeNew< T >( uiCount );
		}

		//--------------------------------------------------------------------------------
		Cmp_uint_ptr AddRef( void )
		{
			m_uiReferenceCount++;
			return m_uiReferenceCount;
		}

		//--------------------------------------------------------------------------------
		Cmp_uint_ptr Release( void )
		{
			if( m_uiReferenceCount > 0 )
			{
				m_uiReferenceCount--;
			}
			Cmp_uint_ptr uiResult = m_uiReferenceCount;
			if( uiResult == 0 )
			{
				SmallObjectHeap.FreeUnboxed< T >( m_pObjectAllocation, sizeof( T ) * Count() );
				SmallObjectHeap.FreeBox( this );
				return 0;
			}
			return uiResult;
		}

		//--------------------------------------------------------------------------------
		T* operator -> ( void )
		{
			return m_pObjectAllocation;
		}

		//--------------------------------------------------------------------------------
		T& operator []( unsigned int uiIndex )
		{
			if( uiIndex < Count() )
			{
				return operator->()[ uiIndex ];
			}
			return *( operator->() );
		}

		//--------------------------------------------------------------------------------
		Cmp_uint_ptr Count( void )
		{
			return m_uiCount;
		}

		//--------------------------------------------------------------------------------
		~TBox()
		{			
		}

	private:
		
		TBox( const TBox< T >& src );						//Not implemented
		TBox< T >& operator = ( const TBox< T >& src );		//Not implemented

		Cmp_uint_ptr m_uiReferenceCount;
		Cmp_uint_ptr m_uiCount;
		T* m_pObjectAllocation;

	};

}//nsCodeQOR

#endif//CODEQOR_DATASTRUCTS_TBOX_H_2
