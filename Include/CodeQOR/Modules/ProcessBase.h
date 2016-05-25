// ProcessBase.h

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

//An intermediate base for process modules
//A process module is the main executable module of a process

#ifndef CODEQOR_MODULES_PROCESSBASE_H_1
#define CODEQOR_MODULES_PROCESSBASE_H_1

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/MemoryManagement/BaseHeap.h"
#include "CodeQOR/ClassReg/ClassReg.h"
#include "CodeQOR/ClassReg/ExternalClassReg.h"
#include "CodeQOR/Threading/ThreadContext.h"
#include "CodeQOR/Modules/LoadableModuleBase.h"
#include "CodeQOR.h"

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
    //--------------------------------------------------------------------------------
	//Base class representing the running process
    class __QOR_INTERFACE( __CODEQOR ) CProcessBase : public CLoadableModuleBase
    {
		friend class CThreadContextBase;

    public:

		static CProcessBase* ThisProcess( void );

        CProcessBase();
        CProcessBase( const char* szProcessName );
        virtual ~CProcessBase();
		virtual bool RegisterLibrary( CLibraryBase* pLibrary );
		virtual void UnregisterLibrary( CLibraryBase* pLibrary );
		virtual void StaticLibraryList( void( pCallback )( CLibraryBase*, void* ), void* pContext );		
		virtual CThreadContextBase* ThreadContext( void );
		virtual void SetMainThread( CThreadContextBase* pMainThread );
		virtual Cmp_uint_ptr Identifier( void );

		virtual CClassReg& ClassReg( void );									//Return the Class Registry for this process
		virtual CExternalClassReg& ExternalClassReg( void );					//Return the External Class Registry for this process

	protected:

		CThreadContextBase* m_pMainThreadContext;
		
	private:

		CProcessBase( const CProcessBase& );
		CProcessBase& operator = ( const CProcessBase& );

		CClassReg m_ClassReg;
		CExternalClassReg m_ExternalClassReg;
    };

}//nsCodeQOR

#endif//CODEQOR_MODULES_PROCESSBASE_H_1
