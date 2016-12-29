//WinQLPointerChecks.cpp

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

#include "WinQL/Application/ErrorSystem/WinQLPointerChecks.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/Application/ErrorSystem/WinQLParamErrorDomain.h"
#include "WinQL/Application/Threading/WinQLThread.h"
#include "WinQL/Application/ErrorSystem/WinQLFunctionContext.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsParamCheck
	{
		using namespace nsWinQAPI;

		//--------------------------------------------------------------------------------
		void CNullPointerCheck::Check( const void* p )
		{			
			if( reinterpret_cast< long >( p ) <= 0x77 )
			{	
				CFunctionContext* pFContext = dynamic_cast< CFunctionContext* >( nsWin32::t_pCurrentWin32Thread->FunctionContext() );

				nsWin32::CError::Raise( pFContext->File(),
					0 , pFContext->Name(),
					CParamErrorDomain::NULL_POINTER,
					nsWin32::CError::ERR_LVL_CONTINUE );				
			}
		}

		//--------------------------------------------------------------------------------
		void CNullOrReadablePointerCheck::Check( const void* p, int iReadableSize )
		{
			if( p != 0 )	//This check allows NULL pointers
			{
				int bResult = CKernel32::IsBadReadPtr( const_cast< void* >( p ) , static_cast< UINT_PTR >( iReadableSize ) );
				if( bResult != 0 )
				{
					CFunctionContext* pFContext = dynamic_cast< CFunctionContext* >( nsWin32::t_pCurrentWin32Thread->FunctionContext() );

					nsWin32::CError::Raise( pFContext->File(),
						0, pFContext->Name(),
						CParamErrorDomain::UNREADABLE_POINTER,
						nsWin32::CError::ERR_LVL_CONTINUE );
				}
			}
		}

		//--------------------------------------------------------------------------------
		void CNullOrWriteablePointerCheck::Check( const void* p, int iWriteableSize )
		{
			if( p != 0 )	//This check allows NULL pointers
			{
				int bResult = CKernel32::IsBadWritePtr( const_cast< void* >( p ), static_cast< UINT_PTR >( iWriteableSize ) );
				if( bResult != 0 )
				{
					CFunctionContext* pFContext = dynamic_cast< CFunctionContext* >( nsWin32::t_pCurrentWin32Thread->FunctionContext() );

					nsWin32::CError::Raise( pFContext->File(),
						0, pFContext->Name(),
						CParamErrorDomain::UNWRITEABLE_POINTER,
						nsWin32::CError::ERR_LVL_CONTINUE );
				}
			}
		}

		//--------------------------------------------------------------------------------	
		void CCodePointerCheck::Check( void* p )
		{
			CNullPointerCheck::Check( p );
		}

		//------------------------------------------------------------------------------
		void CNullOrCodePointerCheck::Check( void* p )
		{
			///TODO:
		}

	};//namespace nsParamCheck

};//namespace nsWin32