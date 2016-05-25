//TMemberPtr.h

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

//A configurable member pointer template with factory instancing

#ifndef CODEQOR_INST_TMEMBERPTR_H_3
#define CODEQOR_INST_TMEMBERPTR_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Traits/MemoryTraits.h"
#include "CodeQOR/MemoryManagement/DefaultAllocator.h"
#include "CodeQOR/DataStructures/TLRef.h"

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
    //--------------------------------------------------------------------------------
    template< class Tbase >
    class CTMemberPtr
    {
    public:

        //--------------------------------------------------------------------------------
        CTMemberPtr() : m_pMember( 0 ), m_pFactoryClassID( Tbase::ClassID() ), m_bOwnsPtr( false )
        {
        }

        //--------------------------------------------------------------------------------
        virtual ~CTMemberPtr()
        {
            Free();
        }

        //--------------------------------------------------------------------------------
        template< typename T > T& operator()()
#if		__QCMP_SUPPORTS( __QCMP_FEATURE_TEMPLATE_TEMPLATE_TEMPLATES ) 
			;
#else
		{
            if( m_pMember == 0 )
            {
                m_pMember = Allocate();
            }

            return (*( dynamic_cast< T* >( m_pMember ) ) );
        }
#endif

        Tbase& operator()();

        //--------------------------------------------------------------------------------
        void Configure( mxGUID* pFactoryClassID )
        {
			m_pFactoryClassID = pFactoryClassID;
        }

		//--------------------------------------------------------------------------------
		bool IsNull()
		{
			return m_pMember == 0 ? true : false;
		}

		//------------------------------------------------------------------------------
		Tbase* operator ->()
		{
			return &( operator() < Tbase > ( ) );
		}

    protected:

        //--------------------------------------------------------------------------------
        virtual Tbase* Allocate()
        {
			Tbase* pNew = 0;
            m_bOwnsPtr = true;

			CClassInstanceFactory* pFactory = ThisModule().ClassReg().GetFactory( m_pFactoryClassID );	

			if( pFactory != 0 )
			{
				pNew = reinterpret_cast< Tbase* >( pFactory->Instance() );
			}
			else
			{
				pNew = 0;
			}

            return pNew;
        }

        //--------------------------------------------------------------------------------
        virtual void Free()
        {
            if( m_bOwnsPtr )
            {
				CClassInstanceFactory* pFactory = ThisModule().ClassReg().GetFactory( m_pFactoryClassID );	
				if( pFactory != 0 && m_pMember != 0 )
				{
					pFactory->Release( m_pMember );
				}
            }
            m_pMember = 0;
        }

        Tbase* m_pMember;
		mxGUID* m_pFactoryClassID;
        bool m_bOwnsPtr;
	};

#if		__QCMP_SUPPORTS( __QCMP_FEATURE_TEMPLATE_TEMPLATE_TEMPLATES )

    //--------------------------------------------------------------------------------
	template<typename Tbase> template < typename T > T& CTMemberPtr<Tbase >::__QCMP_TEMPLATE_OPERATOR_SPECIFIER operator()()
    {
        if( m_pMember == 0 )
        {
            m_pMember = Allocate();
        }

        return (*( dynamic_cast< T* >( m_pMember ) ) );
    }
#endif//__QCMP_SUPPORTS( __QCMP_FEATURE_TEMPLATE_TEMPLATE_TEMPLATES )

	//--------------------------------------------------------------------------------
	template<typename Tbase> Tbase& CTMemberPtr<Tbase >::__QCMP_TEMPLATE_OPERATOR_SPECIFIER operator()()
	{
		if( m_pMember == 0 )
		{
			m_pMember = Allocate();
		}

		return (*m_pMember);
	}

}//nsCodeQOR

#endif//CODEQOR_INST_TMEMBERPTR_H_3
