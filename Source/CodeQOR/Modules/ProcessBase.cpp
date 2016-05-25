//ProcessBase.cpp

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

//Implements a very basic Process representative object

#include "CodeQOR/Modules/ProcessBase.h"

extern nsCodeQOR::CLoadableModuleBase& ThisModule();

//--------------------------------------------------------------------------------
namespace 
{
	nsCodeQOR::CProcessBase* _pThisProcess;

	//--------------------------------------------------------------------------------
	struct sPreInitializer
	{
		sPreInitializer()
		{
			_pThisProcess = 0;
		}
	};
}

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//--------------------------------------------------------------------------------
	CProcessBase* CProcessBase::ThisProcess()
	{
#if ( !( __QCMP_COMPILER == __QCMP_MSVC && _MSC_VER >= 1900 ) )
		static sPreInitializer OneTimeInit;
#endif
		return _pThisProcess;
	}

	//--------------------------------------------------------------------------------
    CProcessBase::CProcessBase() : CLoadableModuleBase( "The Process" )
    {
		_pThisProcess = this;
		m_pMainThreadContext = 0;
    }

    //--------------------------------------------------------------------------------
    CProcessBase::CProcessBase( const char* szProcessName ) : CLoadableModuleBase( szProcessName )
    {
		m_pMainThreadContext = 0;
    }

	//--------------------------------------------------------------------------------
    CProcessBase::~CProcessBase()
    {
		m_pMainThreadContext = 0;
		_pThisProcess = 0;
    }

	//--------------------------------------------------------------------------------
	bool CProcessBase::RegisterLibrary( CLibraryBase* pLibrary )
	{
		if( m_pStaticLibraryList == 0 )
		{
			m_pStaticLibraryList = pLibrary;
		}
		else
		{
			m_pStaticLibraryList->AppendLibrary( pLibrary );
		}

		return true;
	}

	//--------------------------------------------------------------------------------
	void CProcessBase::UnregisterLibrary( CLibraryBase* pLibrary )
	{
	}

	//--------------------------------------------------------------------------------
	void CProcessBase::StaticLibraryList( void( pCallback )( CLibraryBase*, void* ), void* pContext )
	{
		CLibraryBase* pLibrary = m_pStaticLibraryList;
		while( pLibrary != 0 )
		{
			(pCallback)( pLibrary, pContext );
			pLibrary = pLibrary->NextLibrary();
		}
	}

	//--------------------------------------------------------------------------------
	CThreadContextBase* CProcessBase::ThreadContext( void )
	{
		return m_pMainThreadContext;
	}

	//--------------------------------------------------------------------------------
	void CProcessBase::SetMainThread( CThreadContextBase* pMainThread )
	{
		m_pMainThreadContext = pMainThread;
	}

	//--------------------------------------------------------------------------------
	Cmp_uint_ptr CProcessBase::Identifier( void )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	CClassReg& CProcessBase::ClassReg( void )											//Return the Class Registry for this process
	{
		//static CClassReg sClassReg;
		//return sClassReg;
		return m_ClassReg;
	}

	//--------------------------------------------------------------------------------
	CExternalClassReg& CProcessBase::ExternalClassReg( void )							//Return the External Class Registry for this process
	{
		//static CExternalClassReg sExternalClassReg;
		//return sExternalClassReg;
		return m_ExternalClassReg;
	}

}//nsCodeQOR
