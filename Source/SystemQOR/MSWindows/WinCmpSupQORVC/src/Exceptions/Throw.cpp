//Throw.cpp

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
#include "CodeQOR/Threading/ThreadContext.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "../Source/SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/EH_Context.h"
#include "../Source/SystemQOR/MSWindows/WinCmpSupQORVC/include/Exceptions/ExceptionHandling.h"
#include "CodeQOR/Modules/ProcessBase.h"

#if ( __QCMP_COMPILER == __QCMP_INTEL )
#   include <exception>
#endif
using namespace nsCompiler;

//--------------------------------------------------------------------------------
__QCMP_LINKAGE_C void __stdcall _CxxThrowException( void* pObject, const _s__ThrowInfo* pObjectInfo )
{
	if ( pObject )
	{
		EH::ThrownObject object( pObject, pObjectInfo );
		EH::ExceptionRecord rec( object, reinterpret_cast< void* >( &_CxxThrowException ) );
		rec.Throw();
	}
	else
	{
		const EH::ExceptionContext& Context = reinterpret_cast< const EH::ExceptionContext& >( nsCodeQOR::CProcessBase::ThisProcess()->ThreadContext()->ExceptionContext()->CurrentException() );

		if ( !Context.IsValid() )
		{
			std::terminate();
		}

		Context.Rethrow();
	}
}

