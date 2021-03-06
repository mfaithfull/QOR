//TLRef.h

// Copyright Querysoft Limited 2015, 2016
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

//Smart pointer

#ifndef CODEQOR_DATASTRUCTS_TLREF_H_1
#define CODEQOR_DATASTRUCTS_TLREF_H_1

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Traits/MemoryTraits.h"
#include "CodeQOR/MemoryManagement/DefaultAllocator.h"

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//--------------------------------------------------------------------------------
	//A simple smart pointer with optional object ownership
	//If an object is a temporary then we're responsible for deleting it, we own it
	//No reference counting here, one object, one owner at a time, assignment transfers ownership so be careful
	//This is a light weight smart pointer not a safe pointer
	template< class T > class CTLRef
	{
	public:

		//--------------------------------------------------------------------------------
		CTLRef() : m_p( 0 ), m_bTemp( false )
		{
		}

		//--------------------------------------------------------------------------------
		CTLRef( const T* pt, bool bTemp = false ) : m_p( const_cast< T* >( pt ) ), m_bTemp( bTemp )
		{
		}
		
		//--------------------------------------------------------------------------------
		CTLRef( const CTLRef< T >& Src )
		{
			m_p = Src.m_p;			//We take on ownership from the source object
			m_bTemp = Src.m_bTemp;
			Src.m_bTemp = false;	//It therefore no longer treats the target object as a temp
		}

		//--------------------------------------------------------------------------------
		CTLRef( CTLRef< T >&& Src)
		{
			m_p = Src.m_p;			//We take on ownership from the source object
			m_bTemp = Src.m_bTemp;
			Src.m_p = nullptr;
			Src.m_bTemp = false;
		}

		//--------------------------------------------------------------------------------
		CTLRef& operator = ( const CTLRef< T >& Src )
		{
			m_p = Src.m_p;
			m_bTemp = Src.m_bTemp;
			Src.m_bTemp = false;
			return *this;
		}

		//--------------------------------------------------------------------------------
		CTLRef& operator = (CTLRef< T >&& Src)
		{
			m_p = Src.m_p;
			m_bTemp = Src.m_bTemp;
			Src.m_bTemp = false;
			Src.m_p = nullptr;
			return *this;
		}

		//--------------------------------------------------------------------------------
		template< class TDerived > operator CTLRef< TDerived >() const
		{
			TDerived* pDerived = dynamic_cast< TDerived* >( m_p );
			if( m_p != 0 && pDerived != 0 )
			{
				//TODO: Raise NULL reference exception
			}
			return CTLRef< TDerived >( pDerived, false );
		}

		//--------------------------------------------------------------------------------
		//Two references are equal if they refer to the same object, temporary or not,
		//or if the things they point to are equal
		bool operator == ( const CTLRef< T >& Cmp ) const
		{
			return ( m_p == Cmp.m_p ) || ( *Cmp.m_p == ( *m_p ) );
		}

		//--------------------------------------------------------------------------------
		operator T* ( void ) const
		{
			return m_p;
		}

		//--------------------------------------------------------------------------------
		T& operator() (void) const
		{
			if( m_p == nullptr )
			{
				//TODO Raise NULL reference exception
			}
			return *m_p;
		}

		//--------------------------------------------------------------------------------
		T* operator -> () const
		{
			if( m_p == 0 )
			{
				//TODO: Raise a null reference exception here
			}
			return m_p;
		}

		//--------------------------------------------------------------------------------
		~CTLRef()
        {
			Dispose();
        }

		//--------------------------------------------------------------------------------
		void Dispose( void )
		{
			if( m_p && m_bTemp )
			{
				mem_traits< T >::CTAllocator::Free( m_p );
			}
			m_p = 0;
		}

		//--------------------------------------------------------------------------------
		void Attach( T* p, bool bTemp = true )
		{
			Dispose();

			if( m_p == 0 )
			{
				m_p = p;
				m_bTemp = bTemp;
			}
		}

        //--------------------------------------------------------------------------------
        T* Detach()
        {
            T* p = m_p;
            if( m_bTemp )
            {
                m_p = 0;
            }
            return p;
        }
	
		//--------------------------------------------------------------------------------
		template< class TDerived >
		TDerived* As( void ) const
		{
			return dynamic_cast< TDerived* >( m_p );
		}

		//--------------------------------------------------------------------------------
		template< class TDerived >
		CTLRef< TDerived > AsRef(void)
		{
			return CTLRef< TDerived >((dynamic_cast<TDerived*>(m_p)));
		}

		//--------------------------------------------------------------------------------
		bool IsNull( void ) const
		{
			return m_p == 0;
		}

		//--------------------------------------------------------------------------------
		bool IsOwner( void ) const
		{
			return m_bTemp;
		}

	protected:

		T* m_p;
		mutable bool m_bTemp;
	};

}//nsCodeQOR

//--------------------------------------------------------------------------------
template< typename T >
nsCodeQOR::CTLRef<T> new_ref()
{
	return nsCodeQOR::CTLRef<T>(new (nsCodeQOR::mem_traits< T >::CTAllocator::RawAllocate())T(), true);
}

//--------------------------------------------------------------------------------
template< typename T, typename..._p >
nsCodeQOR::CTLRef<T> new_ref(_p&&... p1)
{
	return nsCodeQOR::CTLRef<T>(new (nsCodeQOR::mem_traits< T >::CTAllocator::RawAllocate())T(std::forward<_p>(p1)...), true);
}

#endif//CODEQOR_DATASTRUCTS_TLREF_H_1
