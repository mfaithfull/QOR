//WinQLPointerChecks.h

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

#ifndef WINQL_CS_ERR_POINTERCHECKS_H_2
#define WINQL_CS_ERR_POINTERCHECKS_H_2

#include "CodeQOR/Parameters/PChecks/PointerChecks.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsParamCheck
	{
		//--------------------------------------------------------------------------------
		//Check for null pointer errors
		class CNullPointerCheck
		{
		public: 
			static void Check( const void* p );
		};

		//------------------------------------------------------------------------------
		class CWriteablePointerCheck
		{
		public:
			static void Check( const void* p, int iSize );
		};

		/*
		//------------------------------------------------------------------------------
		class CReadablePointerCheck
		{
		public:
			static void Check( const void* p, int iSize );
		};
		*/

		//------------------------------------------------------------------------------
		class CNullOrReadablePointerCheck
		{
		public:
			static void Check( const void* p, int iSize );
		};

		//------------------------------------------------------------------------------
		class CNullOrWriteablePointerCheck
		{
		public:
			static void Check( const void* p, int iSize );
		};

		//------------------------------------------------------------------------------
		class CRWPointerCheck
		{
		public:
			static void Check( const void* p, int iSize );
		};

		//------------------------------------------------------------------------------
		class CCodePointerCheck
		{
		public:
			static void Check( void* p );
		};

		//------------------------------------------------------------------------------
		class CNullOrCodePointerCheck
		{
		public:
			static void Check( void* p );
		};

		//------------------------------------------------------------------------------
		//Template classes to add extra compile time information to the standard Check call
		template< int iWriteableSize >
		class CTWritablePointerCheck
		{
		public:	
			static void Check( const void* p )
			{
				/*nsParamChecking::*/CWriteablePointerCheck::Check( p, iWriteableSize );
			}	
		};

		//------------------------------------------------------------------------------
		template< int iReadableSize >
		class CTReadablePointerCheck
		{
		public:	
			static void Check( const void* p )
			{
				CReadablePointerCheck::Check( p, iReadableSize );
			}	
		};

		//------------------------------------------------------------------------------
		template< int iReadableSize >
		class CTNullOrReadablePointerCheck
		{
		public:
			static void Check( const void* p )
			{
				CNullOrReadablePointerCheck::Check( p, iReadableSize );
			}
		};

		//------------------------------------------------------------------------------
		template< int iWriteableSize >
		class CTNullOrWriteablePointerCheck
		{
		public:
			static void Check( const void* p )
			{
				CNullOrWriteablePointerCheck::Check( p, iWriteableSize );
			}
		};

		//------------------------------------------------------------------------------
		template< int iRWSize >
		class CTRWPointerCheck
		{
		public:
			static void Check( const void* p )
			{
				::nsParamChecking::CRWPointerCheck::Check( p, iRWSize );
			}
		};

		//------------------------------------------------------------------------------
		template< typename TFPType >
		class CTCodePointerCheck
		{
		public:
			static void Check( TFPType p )
			{
				CCodePointerCheck::Check( *((void**)(&p)) );
			}
		};

		//------------------------------------------------------------------------------
		template< typename TFPType >
		class CTNullOrCodePointer
		{
		public:
			static void Check( TFPType p )
			{
				CNullOrCodePointerCheck::Check( *((void**)(&p)) );
			}
		};		

		//------------------------------------------------------------------------------
		template< typename T, int iCount >
		class CTArrayCheck
		{
		public:
			static void Check( T pElem )
			{
				::nsParamChecking::CRWPointerCheck::Check( const_cast< const void* >( reinterpret_cast< void* >( pElem ) ), iCount * sizeof( T ) );
			}
		};

	}//nsParamCheck

}//nsWin32

#endif//WINQL_CS_ERR_POINTERCHECKS_H_2
