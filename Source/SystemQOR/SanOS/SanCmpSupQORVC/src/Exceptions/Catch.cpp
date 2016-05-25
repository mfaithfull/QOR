//Catch.cpp

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
#include "SystemQOR.h"
#include "WinQL/CodeServices/CriticalSection.h"

#ifndef _WIN64		//This doesn't apply to 64bit Windows

#include "../SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/EH_Context.h"
#include "../SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/EH_GuardDescriptor.h"
#include "../SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/TranslatorGuard.h"
#include "../SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/EH_Data.h"
#include "CodeQOR/Threading/ThreadContext.h"
#include <exception>

#else

#include "CompilerQOR.h"
#include "CodeQOR/Threading/ThreadContext.h"
#include <exception>
#include <typeinfo>
#include "CodeQOR/ErrorSystem/DefaultHandler.h"

#endif

#ifndef _WIN64		//This doesn't apply to 64bit Windows
//--------------------------------------------------------------------------------
namespace nsCompiler
{
	//--------------------------------------------------------------------------------
	namespace EH
	{
		//--------------------------------------------------------------------------------
		static void FindHandlerForForeignException( ExceptionContext& context, GuardDescriptor& guard, BasicRegistrationNode* pMarkerRN )
		{
			if ( context.ExceptionCode() == ( (long)0x80000003L )/*STATUS_BREAKPOINT*/ )
			{
				return;
			}

			const int curState = guard.CurrentState();

			unsigned int curTry = 0, end = 0;

			for( const TryBlockMapEntry* pEntry = guard.GetRangeOfTrysToCheck( &curTry, &end ); curTry < end; ++curTry, ++pEntry )
			{
				if ( curState < pEntry->tryLow || curState > pEntry->tryHigh )
				{
					continue;
				}
				const HandlerType* const pCatch = &( pEntry->pHandlerArray[ pEntry->nCatches - 1 ] );
				if ( !pCatch->pType || !pCatch->pType->name[0] )
				{
					guard.Catch( context, pCatch, 0, pEntry, pMarkerRN );
				}
			}
		}


		//--------------------------------------------------------------------------------
		static void FindHandler( ExceptionContext context, GuardDescriptor& guard, BasicRegistrationNode* pMarkerRN )
		{
			const int curState = guard.CurrentState();

			unsigned int curTry=0, end=0;

			for( const TryBlockMapEntry* pEntry = guard.GetRangeOfTrysToCheck( &curTry, &end ); curTry < end; ++curTry, ++pEntry )
			{
				if ( curState < pEntry->tryLow || curState > pEntry->tryHigh )
				{
					continue;
				}

				const HandlerType* pCatch = pEntry->pHandlerArray;

				for( int catches = pEntry->nCatches; catches > 0; --catches,++pCatch )
				{
					const CatchableType* pCatchable = context.ExceptionObject().FindMatch( pCatch );

					if ( pCatchable )
					{
						guard.Catch( context, pCatch, pCatchable, pEntry, pMarkerRN );
						break;
					}
				}
			}
		}

		//--------------------------------------------------------------------------------
		nsWin32::EXCEPTION_DISPOSITION CallHandler( HandlerPtr pfn, ExceptionContext& context, const GuardDescriptor& guard, BasicRegistrationNode* pMarkerRN, int recursive )
		{
			return pfn( context.Record(), guard.m_pRN, context.Context(), context.DispatcherContext(), guard.m_pFuncInfo, guard.m_CatchDepth, pMarkerRN, recursive ? 1 : 0);
		}

		//--------------------------------------------------------------------------------
		nsWin32::EXCEPTION_DISPOSITION __QCMP_NOINLINE CxxFrameHandler( ExceptionContext& context, GuardDescriptor& guard, BasicRegistrationNode* pMarkerRN, bool recursive )
		{
			if ( !guard.IsValid() )
			{
				inconsistency();
			}

			//Probably meant to catch SEH exceptions sourced from pre VS2005 code, never mind for now
			//if ( !context.IsCppException() && ( guard.MagicNumber() == 0x19930522 /*VS2005-*/) && ( CCompilerBase::EH_MAGIC >= 0x19930522 ) /*&& guard.Synchronous()*/ )
			//{
			//	return nsWin32::ExceptionContinueSearch;
			//}

			const unsigned long unwinding_mask = SEH::EH_UNKNOWN3 | SEH::EH_UNKNOWN2 | SEH::EH_EXIT_UNWIND | SEH::EH_UNWINDING;

			if ( context.ExceptionFlags() & unwinding_mask )
			{
				if ( guard.MaxState() != 0 && guard.CatchDepth() == 0 )
				{
					guard.FrameUnwindToState( -1 );
				}
				return nsWin32::ExceptionContinueSearch;
			}

			if ( guard.MayBeUnwound() )
			{
				HandlerPtr pfn = context.CustomHandler();
				if (pfn)
				{
					return CallHandler( pfn, context, guard, pMarkerRN, recursive );
				}
			}

			const int curState = guard.CurrentState();
			if ( curState < -1 || curState >= guard.MaxState() )
			{
				inconsistency();
			}

			if ( !context.IsCppException() )
			{
				if (!recursive)
				{
					std::terminate();
				}
				FindHandlerForForeignException( context, guard, pMarkerRN );
			}
			else
			{
				ExceptionContext ValidContext = context;

				if ( !context.ExceptionObject().IsValid() )
				{
					ValidContext = nsCodeQOR::CThreadContextBase::GetCurrent()->ExceptionContext()->CurrentException();

					if ( !ValidContext.IsValid() )
					{
						return nsWin32::ExceptionContinueSearch;
					}

					if ( ValidContext.IsCppException() && !ValidContext.ExceptionObject().IsValid() )
					{
						inconsistency();
					}

				}

				FindHandler( ValidContext, guard, pMarkerRN );

				if ( recursive && ValidContext.IsValid() )
				{
					ValidContext.ExceptionObject().Destruct(true);
				}
			}

			return nsWin32::ExceptionContinueSearch;
		}

	}//EH

}//nsCompiler

using namespace nsCompiler;

//--------------------------------------------------------------------------------
__QCMP_LINKAGE_C nsWin32::EXCEPTION_DISPOSITION __CxxFrameHandler( EH::ExceptionRecord* pExcept, EH::RegistrationNode* pRN, void* pContext, void* pDC)
{
	__asm cld;

	const EH::FuncInfo* pFuncInfo;
	__asm mov pFuncInfo, eax;

	EH::GuardDescriptor guard( pRN, pFuncInfo, 0 );
	EH::ExceptionContext context( pExcept, ( EH::Context* )pContext, pDC );
	const nsWin32::EXCEPTION_DISPOSITION result = EH::CxxFrameHandler( context, guard, 0, false );
	return result;
}

//--------------------------------------------------------------------------------
static __forceinline unsigned int get_eax()
{
	__asm xchg eax, eax
}

//--------------------------------------------------------------------------------
__QCMP_LINKAGE_C nsWin32::EXCEPTION_DISPOSITION __CxxFrameHandler3Impl( EH::ExceptionRecord* pExcept, EH::RegistrationNode* pRN, nsWin32::CONTEXT* pContext, void* pDC, EH::RegistrationNode* pRN2, const EH::FuncInfo* pFuncInfo )
{
	EH::GuardDescriptor guard( pRN, pFuncInfo, 0 );
	EH::ExceptionContext context( pExcept, ( EH::Context* )pContext, pDC );
	const nsWin32::EXCEPTION_DISPOSITION result = EH::CxxFrameHandler( context, guard, 0, false );
	return result;
}

//--------------------------------------------------------------------------------
__QCMP_LINKAGE_C nsWin32::EXCEPTION_DISPOSITION __CxxFrameHandler3( EH::ExceptionRecord* pExcept, EH::RegistrationNode* pRN, nsWin32::CONTEXT* pContext, void* pDC, EH::RegistrationNode* pRN2 )//, int i, EH::RegistrationNode* pRN2, unsigned char uc )
{
	return __CxxFrameHandler3Impl( pExcept, pRN, pContext, pDC, pRN2, reinterpret_cast< const EH::FuncInfo* >( get_eax() ) );
}

//--------------------------------------------------------------------------------
__QCMP_LINKAGE_C nsWin32::EXCEPTION_DISPOSITION TranslatorGuardHandler( EH::ExceptionRecord* pExcept, EH::TranslatorGuardRN* pRN, void* pContext, void* pDC )
{
	const nsWin32::EXCEPTION_DISPOSITION result = nsWin32::ExceptionContinueSearch;
	return result;
}
#else

__QCMP_STARTLINKAGE_C

int __CxxFrameHandler( void* pExcept, void* pRN, void* pContext, void* pDC)
{
	return 3;
}

//--------------------------------------------------------------------------------
void __CxxFrameHandler3( void* pExcept, void* pRN, void* pContext, void* pDC, void* pRN2 )
{

}

//--------------------------------------------------------------------------------
void __GSHandlerCheck_EH( void* pExcept, void* pRN, void* pContext, void* pDC, void* pRN2 )
{

}

//--------------------------------------------------------------------------------
void __GSHandlerCheck( void* pExcept, void* pRN, void* pContext, void* pDC, void* pRN2 )
{

}

//--------------------------------------------------------------------------------
void __C_specific_handler( void* pExcept, void* pRN, void* pContext, void* pDC, void* pRN2 )
{

}

__QCMP_ENDLINKAGE_C

#endif//_WIN64
