//SingletonInstancer.h

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

//Singleton pattern template

#ifndef CODEQOR_SINGLETON_INSTANCER_H_2
#define CODEQOR_SINGLETON_INSTANCER_H_2

#include "CodeQOR/instancing/sTOB.h"

//------------------------------------------------------------------------------
//Declare a class to be a singleton
//This prevents _Class from being created except by derived
//classes or CTSingleton< _Class >
#define __QOR_DECLARE_SINGLETON( _Class, _Policy )								\
																				\
friend class nsCodeQOR::CTSingletonInstancer< _Class, _Policy >;				\
friend class typename mem_traits< _Class >::CTAllocator;						\
protected:																		\
	_Class();																	\
	virtual ~_Class();

//------------------------------------------------------------------------------
//Macro to singleton enable a class implementation
//Include __QOR_IMPLEMENT_SINGLETON(class-name) in your class implementation
#define __QOR_IMPLEMENT_SINGLETON( _Class, _Policy  )															\
																												\
template<> _Class* nsCodeQOR::CTSingletonInstancer< _Class, _Policy >::m_pInstance = 0;							\
template<> long nsCodeQOR::CTSingletonInstancer< _Class, _Policy >::m_lInstanceCount = 0;						\
template<> _Policy::TThreadSyncSinglePrimitive nsCodeQOR::CTSingletonInstancer< _Class, _Policy >::m_Section;	\
template<> mem_traits< _Class >::CSource nsCodeQOR::CTSingletonInstancer< _Class, _Policy >::m_Source;

//Add __QOR_DECLARE_SINGLETON( source, class-name ); to your class declaration
//declaring no other constructors or destructor. 

//Add __QOR_IMPLEMENT_SINGLETON( source, class-name) to your class implementation
//and your class will only be able to be accessed as a singleton

//Use nsCodeQOR::CTSingletonInstancer< source_type, class-name >::Instance() to get an pointer to a singleton

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//------------------------------------------------------------------------------
	//Template for singleton instancing
	template< class T, class TPolicy >
	class CTSingletonInstancer
	{

	public:

		typedef typename TPolicy::TThreadSyncSinglePrimitive sectionType;
		typedef typename mem_traits< T >::CSource CTSource;

		//------------------------------------------------------------------------------
		CTSingletonInstancer()
		{
		}

		//------------------------------------------------------------------------------
		CTSingletonInstancer( const CTSingletonInstancer& src )
		{
			*this = src;
		}

		//------------------------------------------------------------------------------
		CTSingletonInstancer& operator = ( const CTSingletonInstancer& src )
		{
			if( &src != this )
			{
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		virtual ~CTSingletonInstancer()
		{
		}

		//------------------------------------------------------------------------------
		//Get a pointer to the one instance
		T* Instance()
		{
			TPolicy::TThreadSyncSingleLock Lock( m_Section );
			if( m_pInstance == 0 )					//If we don't have one then
			{				
				byte* pMemory = m_Source.Source( sizeof( T ) );
				m_pInstance = new( pMemory )( T );	//Create the one instance
				m_lInstanceCount = 1;				//count the single reference
			}
			else
			{
				m_lInstanceCount++;
			}

			return m_pInstance;
		}

		//------------------------------------------------------------------------------
		//Release a pointer to the one instance
		void Release( T* /*ignored*/ )	
		{
			TPolicy::TThreadSyncSingleLock Lock( m_Section );
			m_lInstanceCount--;							//decrement the reference count
			if( m_lInstanceCount <= 0 )
			{											//If no more references are held
				m_pInstance->~T();						//The one instance is deleted
				m_Source.Free( reinterpret_cast< byte* >( m_pInstance ), sizeof( T ) );

				m_pInstance = 0;						//reset pointer so re-creation can occur
				m_lInstanceCount = 0;					//Reference count is reset to 0		
			}
		}

		//--------------------------------------------------------------------------------
		CTSource& Source( void )
		{
			return m_Source;
		}

	private:

		static sectionType m_Section;;
		static T* m_pInstance;
		static long m_lInstanceCount;
		static CTSource m_Source;

	};

}//nsCodeQOR

#endif//CODEQOR_SINGLETON_INSTANCER_H_2
