//SEH.cpp

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

#include "WinQL/WinQL.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "../SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/SEH/SEH.h"
#include "../SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/SEH/excpt.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"

__QCMP_LINKAGE_C extern Cmp_uint_ptr __security_cookie;
__QCMP_LINKAGE_C extern Cmp_uint_ptr __security_cookie_complement;

//--------------------------------------------------------------------------------
namespace nsCompiler
{
	void CallMemberFunction( void* pObject, void* pfn, ... );
	void JumpToFunction( void* target, void* targetStack, void* targetEBP );
	void* __stdcall CallOnFrame0( void* addr, void* new_frame, void* temp1 = 0, void* temp2 = 0 );
	void* __stdcall CallOnFrame2( void* addr, void* new_frame, void* arg1, void* arg2, void* temp1 = 0, void* temp2 = 0 );

	//--------------------------------------------------------------------------------
	__QCMP_NORETURN void CExceptionFrame::RaiseException( const void* prec )
	{
		nsWin32::CError::RaiseException(prec);
	}

	//--------------------------------------------------------------------------------
	void __stdcall CExceptionFrame::UnwindNestedFrames( nsWin32::EXCEPTION_RECORD* pExcept )
	{	
		CExceptionFrame* const pDispatcherFrame = reinterpret_cast< CExceptionFrame* >( GetCurrent() );
		UnwindStack( pExcept, 0 );
		pExcept->ExceptionFlags &= 0xFFFFFFFD;
		pDispatcherFrame->m_pNext = reinterpret_cast< CExceptionFrame* >( GetCurrent() );
		pDispatcherFrame->SetCurrent();
	}

	//--------------------------------------------------------------------------------
	namespace SEH
	{
		const unsigned int EH_NONCONTINUABLE	= 0x01;
		const unsigned int EH_UNWINDING			= 0x02;
		const unsigned int EH_EXIT_UNWIND		= 0x04;
		const unsigned int EH_STACK_INVALID		= 0x08;
		const unsigned int EH_NESTED_CALL		= 0x10;
		const unsigned int EH_UNKNOWN1			= 0x20;
		const unsigned int EH_UNKNOWN2			= 0x20;
		const unsigned int EH_UNKNOWN3			= 0x40;

		//--------------------------------------------------------------------------------
		const ScopeTableEntry& ExceptionFrame::CurrentEntry() const
		{
			const ScopeTableEntry* pEntry = m_pScopeTable;
			unsigned int uiTmpEntry = reinterpret_cast< unsigned int >( pEntry );
			
			uiTmpEntry ^= __security_cookie;
#			pragma warning(disable : 4312)//_TXT( "Suppressed 64bit compatability warning" ) )
			pEntry = reinterpret_cast< ScopeTableEntry* >( uiTmpEntry + 0x10 );
#			pragma warning(default : 4312)

			return pEntry[ m_TryLevel ];
		}

		//--------------------------------------------------------------------------------
		const ScopeTableEntry& ExceptionFrame::Entry( int level ) const
		{	
			const ScopeTableEntry* pEntry = m_pScopeTable;
			unsigned int uiTmpEntry = reinterpret_cast< unsigned int >( pEntry );

			uiTmpEntry ^= __security_cookie;
#			pragma warning(disable : 4312)//_TXT( "Suppressed 64bit compatability warning" ) )
			pEntry = reinterpret_cast< ScopeTableEntry* >( uiTmpEntry + 0x10 );
#			pragma warning(default : 4312)

			return pEntry[ level ];
		}

		//--------------------------------------------------------------------------------
		EXCEPTION_DISPOSITION UnwindHandler( ExceptionRecord* pExcept, ExceptionFrame* pFrame, nsWin32::CONTEXT* /*pContext*/, void* pDC )
		{
			if ( !pExcept->IsUnwinding() )
			{
				return ExceptionContinueSearch;
			}
			*( void** )pDC = pFrame->Next();
			return ExceptionCollidedUnwind;
		}
		
		//--------------------------------------------------------------------------------
		void LocalUnwind( ExceptionFrame* pFrame, int tryLevel )
		{
			UnwindFrame local_frame( reinterpret_cast< void* >( UnwindHandler ), -2, pFrame );
			local_frame.SetCurrent();

			while ( pFrame->TryLevel() != -1 && pFrame->TryLevel() != tryLevel )
			{				
				const ScopeTableEntry& entry = pFrame->CurrentEntry();
				local_frame.SetTryLevel( entry.previousTryLevel );
				pFrame->SetTryLevel( entry.previousTryLevel );

				if ( entry.previousTryLevel != 0 )
				{
					continue;
				}

				entry.lpfnHandler();
			}
			
			local_frame.Remove();
		}

		//--------------------------------------------------------------------------------
		EXCEPTION_DISPOSITION ExceptionHandler( ExceptionRecord* pExcept, ExceptionFrame* pFrame, Context* pContext, void* /*pDC*/)
		{
			nsWin32::EXCEPTION_POINTERS ex_ptrs;
			ex_ptrs.ContextRecord = pContext;
			ex_ptrs.ExceptionRecord = pExcept;

			pFrame->SetExceptionPointers( &ex_ptrs );

			const ScopeTableEntry* pEntry = 0;

			for ( int tryLevel = pFrame->TryLevel(); tryLevel != -2; tryLevel = pEntry->previousTryLevel )
			{
				pEntry = &pFrame->Entry( tryLevel );

				if ( !pEntry->lpfnFilter )
				{
					continue;
				}

				void* const new_ebp = pFrame->EBP();

				const int FilterResult = ( int )CallOnFrame0( reinterpret_cast< void* >( pEntry->lpfnFilter ), new_ebp ); 

				if ( FilterResult < 0 ) // EXCEPTION_CONTINUE_EXECUTION
				{
					return ExceptionContinueExecution;
				}

				if ( FilterResult != EXCEPTION_CONTINUE_SEARCH )
				{
					// If we get here, EXCEPTION_EXECUTE_HANDLER was specified					
					pFrame->UnwindStack( 0, 0 );

					CallOnFrame2( reinterpret_cast< void* >( LocalUnwind ), new_ebp, pFrame, ( void* )( unsigned _W64 )tryLevel );

					pFrame->SetTryLevel( pEntry->previousTryLevel );

					CallOnFrame0( reinterpret_cast< void* >( pEntry->lpfnHandler ), new_ebp );
				}
			}

			return ExceptionContinueSearch;
		}

		//--------------------------------------------------------------------------------
		EXCEPTION_DISPOSITION CleanupHandler( ExceptionRecord* /*pExcept*/, ExceptionFrame* pFrame, Context* /*pContext*/, void * /*pDC*/)
		{
			void* const new_ebp = pFrame->EBP();
			CallOnFrame2( reinterpret_cast< void* >( LocalUnwind ), new_ebp, pFrame, (void*)-1 );
			return ::ExceptionContinueSearch;
		}

		//--------------------------------------------------------------------------------
		int AbnormalTermination()
		{
			const CExceptionFrame* pCurrentFrame = reinterpret_cast< CExceptionFrame* >( CExceptionFrame::GetCurrent() );

			if ( reinterpret_cast< void* >( pCurrentFrame->Handler() ) != UnwindHandler )
			{
				return 0;
			}

			const UnwindFrame* pUnwindFrame = ( const UnwindFrame* )pCurrentFrame;
			const ExceptionFrame* pOriginalFrame = pUnwindFrame->OriginalFrame();

			if ( pUnwindFrame->TryLevel() != pOriginalFrame->TryLevel() )
			{
				return 0;
			}

			return 0;
		}

	}//SEH

}//nsCompiler

#ifndef _WIN64		//This doesn't apply t 64bit Windows

__QCMP_STARTLINKAGE_C

	using namespace nsCompiler::SEH;

	//--------------------------------------------------------------------------------
	EXCEPTION_DISPOSITION __cdecl _except_handler3( ExceptionRecord* pExcept, ExceptionFrame* pFrame, Context* pContext, void* pDC )
	{
		__asm cld;

		if ( pExcept->IsUnwinding() )
		{
			return CleanupHandler( pExcept, pFrame, pContext, pDC );
		}
		return ExceptionHandler( pExcept, pFrame, pContext, pDC );
	}

	//--------------------------------------------------------------------------------
	EXCEPTION_DISPOSITION __cdecl _except_handler4( ExceptionRecord* pExcept, ExceptionFrame* pFrame, Context* pContext, void* pDC )
	{
		__asm cld;

		if ( pExcept->IsUnwinding() )
		{
			return CleanupHandler( pExcept, pFrame, pContext, pDC );
		}
		return ExceptionHandler( pExcept, pFrame, pContext, pDC );
	}

__QCMP_ENDLINKAGE_C

#endif//_WIN64

