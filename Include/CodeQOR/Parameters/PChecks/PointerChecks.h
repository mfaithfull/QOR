//PointerChecks.h

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

//Validation checks for pointer parameters

#ifndef CODEQOR_PCHECKING_POINTERS_H_1
#define CODEQOR_PCHECKING_POINTERS_H_1

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Parameters/ParamChecking.h"
#include "CodeQOR.h"

//--------------------------------------------------------------------------------
namespace nsParamChecking
{
	//--------------------------------------------------------------------------------
	//Check for null pointer errors
	class __QOR_INTERFACE( __CODEQOR ) CNullPointerCheck
	{
	public: 

		static void Check( const void* p );
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CWriteablePointerCheck
	{
	public:
		static void Check( const void* p, int iSize );
	};

	//------------------------------------------------------------------------------
	//Template classes to add extra compile time information to the standard Check call
	template< int iWriteableSize >
	class CTWritablePointerCheck
	{
	public:	

		//------------------------------------------------------------------------------
		static void Check(const void* p )
		{
			CWriteablePointerCheck::Check( p, iWriteableSize );
		}	
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CReadablePointerCheck
	{
	public:

		static void Check( const void* p, int iReadableSize );
	};

	//------------------------------------------------------------------------------
	template< int iReadableSize >
	class CTReadablePointerCheck
	{
	public:	

		//------------------------------------------------------------------------------
		static void Check( const void* p )
		{
			CReadablePointerCheck::Check( p, iReadableSize );
		}	
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CNullOrReadablePointerCheck
	{
	public:

		static void Check( const void* p, int iReadableSize );
	};

	//------------------------------------------------------------------------------
	template< int iReadableSize >
	class CTNullOrReadablePointerCheck
	{
	public:

		//------------------------------------------------------------------------------
		static void Check( const void* p )
		{
			CNullOrReadablePointerCheck::Check( p, iReadableSize );
		}
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CRWPointerCheck
	{
	public:

		static void Check( const void* p, int iRWSize );

	};

	//------------------------------------------------------------------------------
	template< int iRWSize >
	class CTRWPointerCheck
	{
	public:

		//------------------------------------------------------------------------------
		static void Check( const void* p )
		{
			CRWPointerCheck::Check( p, iRWSize );
		}
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CCodePointerCheck
	{
	public:

		static void Check( void* p );
	};

}//nsParamChecking

#endif//CODEQOR_PCHECKING_POINTERS_H_1
