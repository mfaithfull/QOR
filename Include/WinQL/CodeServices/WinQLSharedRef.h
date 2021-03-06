//WinQLSharedRef.h

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

//A reference type for process wide objects that must cross threads

#ifndef WINQL_CS_SHAREDREF_H_3
#define WINQL_CS_SHAREDREF_H_3

#include "CompilerQOR.h"
#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "CodeQOR/DataStructures/TLRef.h"

//Macro that effectively adds two public functions to a class, Lock and Unlock, and one member equivalent to a Critical Section
#define QOR_PP_WINQL_SHARED															\
	public:																			\
		CWinQLPolicy::TThreadSyncSinglePrimitive _SyncSinglePrimitive;				\
		CSharedObjectLockFunctor _Lock;												\
		CSharedObjectUnlockFunctor _Unlock;											\
	private:

#define QOR_PP_SHARED_OBJECT_ACCESS )(

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class CSharedObjectLockFunctor
	{
	public:

		//--------------------------------------------------------------------------------
		template< class T > void operator()( T* pt )
		{
			pt->_SyncSinglePrimitive.Acquire();
		}
	};

	//--------------------------------------------------------------------------------
	class CSharedObjectUnlockFunctor
	{
	public:
		
		//--------------------------------------------------------------------------------
		template< class T > void operator()( T* pt )
		{
			pt->_SyncSinglePrimitive.Release();
		}
	};

	//--------------------------------------------------------------------------------
	template< class T > class CTObjectLock
	{
	public:

		//--------------------------------------------------------------------------------
		CTObjectLock( T* p_t ) : m_pt( p_t )
		{
			if( m_pt )
			{
				m_pt->_Lock( m_pt );
			}
		}

		//--------------------------------------------------------------------------------
		~CTObjectLock()
		{
			Release();
		}

		//--------------------------------------------------------------------------------
		void Release( void )
		{
			if( m_pt )
			{
				m_pt->_Unlock( m_pt );
			}
		}

	private:

		T* m_pt;

		CTObjectLock();//not implemented
		CTObjectLock( const CTObjectLock& );//not implemented
		CTObjectLock& operator = ( const CTObjectLock& );//not implemented
	};

	//--------------------------------------------------------------------------------
	//A reference type which Locks the object refered for the lifetime of the reference
	//Use these to access global objects safely.
	template< class T > class CSharedRef
	{

	public:

		//--------------------------------------------------------------------------------
		CSharedRef( const T* pt ) : m_p( const_cast< T* >( pt ) ), m_Lock( m_p )
		{

		}
		
		//--------------------------------------------------------------------------------
		CSharedRef(const CSharedRef< T >& src) : m_Lock(Src.m_p)
		{
			m_p = Src.m_p;
		}

		//--------------------------------------------------------------------------------
		CSharedRef( const nsCodeQOR::CTLRef< T >& Src ) : m_Lock( Src.m_p )
		{
			m_p = Src.m_p;
		}

		//--------------------------------------------------------------------------------
		//Two shared references are only equal if they refer to the same object
		bool operator == ( const CSharedRef< T >& Cmp ) const
		{
			return ( m_p == Cmp.m_p );
		}

		//--------------------------------------------------------------------------------
		T* operator -> (void) const
		{
			return m_p;
		}

		//--------------------------------------------------------------------------------
		T& operator()(void) const
		{
			if( m_p == 0 )
			{
				//TODO: Raise a null reference exception here
			}
			return *m_p;
		}

		//--------------------------------------------------------------------------------
		~CSharedRef()
        {
        }
	
		//--------------------------------------------------------------------------------
		template< class TDerived >
		TDerived* As( void )
		{
			return dynamic_cast< TDerived* >( m_p );
		}

		//--------------------------------------------------------------------------------
		bool IsNull( void )
		{
			return m_p == 0;
		}

		//--------------------------------------------------------------------------------
		bool IsOwner( void )
		{
			return false;
		}

		//--------------------------------------------------------------------------------
		void Dispose( void )
		{
			if( m_p )
			{
				m_Lock.Release();
				m_p = 0;
			}
		}

	protected:

		T* m_p;
		CTObjectLock< T > m_Lock;
	};

    //--------------------------------------------------------------------------------
    //A configurable member pointer wrapper template
    //Gives a class 'construct on first use' members that can be configured at runtime
    //to use derived class instances owned elsewhere. Enables runtime member replacement
    //with a more specialized type.
    //All allocation and destruction is deferred from this class.
    template< class Tbase >
    class CSharedMember
    {
    public:

		typedef typename Tbase::refType baseRef;

        //--------------------------------------------------------------------------------
        CSharedMember() : m_pMember( 0 ), m_bOwnsPtr( true )
        {
        }

        //--------------------------------------------------------------------------------
        virtual ~CSharedMember()
        {
            Free();
        }

        //--------------------------------------------------------------------------------
        template< class T > typename T::refType operator()()
#if		__QCMP_SUPPORTS( __QCMP_FEATURE_TEMPLATE_TEMPLATE_TEMPLATES ) 
			;
#else
		{
			//CWinQLPolicy::TThreadSyncSingleLock Lock( m_Section );
            if( m_pMember == 0 )
            {
                m_pMember = Allocate();
            }

            T::refType Ref( ( dynamic_cast< T* >( m_pMember ) ) );
			return Ref;
        }
#endif

        baseRef operator()();

		//--------------------------------------------------------------------------------
		Tbase* Base( void ) const
		{
			return m_pMember;
		}

        //--------------------------------------------------------------------------------
        bool Configure( Tbase* pConf, bool bConferOwnership = false )
        {
            bool bResult = false;
			//CWinQLPolicy::TThreadSyncSingleLock Lock( m_Section );
            if( m_pMember == 0 && pConf != 0 )
            {
                m_pMember = pConf;
                bResult = true;
                m_bOwnsPtr = bConferOwnership;
            }
            else if( m_pMember != 0 && pConf == 0 && m_bOwnsPtr == false )
            {
                m_pMember = 0;
                bResult = true;
            }
            return bResult;
        }

        //--------------------------------------------------------------------------------
        bool Configure( baseRef Conf )
        {
            bool bResult = false;
			//CWinQLPolicy::TThreadSyncSingleLock Lock( m_Section );
			if( m_pMember == 0 && !Conf.IsNull() )
            {
				m_bOwnsPtr = Conf.IsOwner();
				m_pMember = Conf.As< Tbase >();
                bResult = true;                
            }
			else if( m_pMember != 0 && Conf.IsNull() && m_bOwnsPtr == false )
            {
                m_pMember = 0;
                bResult = true;
            }
            return bResult;
        }

		//--------------------------------------------------------------------------------
		bool IsNull()
		{
			return m_pMember == 0 ? true : false;
		}

    protected:

        //--------------------------------------------------------------------------------
        virtual Tbase* Allocate()
        {
            m_bOwnsPtr = true;
            Tbase* pNew = nsCodeQOR::mem_traits< Tbase >::CTAllocator::Allocate();
            return pNew;
        }

        //--------------------------------------------------------------------------------
        virtual void Free()
        {
            if( m_bOwnsPtr )
            {
                nsCodeQOR::mem_traits< Tbase >::CTAllocator::Free( m_pMember );
            }
            m_pMember = 0;
        }

        Tbase* m_pMember;
        bool m_bOwnsPtr;
		
	};

#if		__QCMP_SUPPORTS( __QCMP_FEATURE_TEMPLATE_TEMPLATE_TEMPLATES )

    //--------------------------------------------------------------------------------
	template< typename Tbase > template< typename T > typename T::refType CSharedMember< Tbase >::__QCMP_TEMPLATE_OPERATOR_SPECIFIER operator()()
    {
		if( m_pMember == 0 )
		{
			m_pMember = Allocate();
        }

        return typename T::refType( dynamic_cast< T* >( m_pMember ) );
    }

#endif//__QCMP_SUPPORTS( __QCMP_FEATURE_TEMPLATE_TEMPLATE_TEMPLATES )

	//--------------------------------------------------------------------------------
	template< typename Tbase > typename Tbase::refType CSharedMember< Tbase >::__QCMP_TEMPLATE_OPERATOR_SPECIFIER operator()()
	{		
		if ( m_pMember == 0 )
		{
			m_pMember = Allocate();
		}

		return typename Tbase::refType( m_pMember );
	}

	//--------------------------------------------------------------------------------
	template< class T >
	class CSharedMemberAdaptor : private T
	{
	public:

		typedef CSharedRef< T > refType;

		//--------------------------------------------------------------------------------
		CSharedMemberAdaptor() : T()
		{
		}

		//--------------------------------------------------------------------------------
		~CSharedMemberAdaptor()
		{
		}

		//--------------------------------------------------------------------------------
		refType Ref( void )
		{
			return refType( this );
		}

	};

}//nsWin32

#endif//WINQL_CS_SHAREDREF_H_3

