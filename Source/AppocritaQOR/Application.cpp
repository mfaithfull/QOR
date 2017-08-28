//Application.cpp

// Copyright Querysoft Limited 2016
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

#include "CodeQOR/Instancing/TInstancePtr.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "AppocritaQOR/AppocritaQOR.h"
#include "AppocritaQOR/Application.h"

//------------------------------------------------------------------------------
namespace nsQOR
{
	static CApplication* theApplication = nullptr;	

	__QOR_IMPLEMENT_OCLASS_GUID( IApplication, 0x11110951, 0xebb7, 0x4b5d, 0x84, 0xfd, 0x56, 0x71, 0xa0, 0x73, 0xd0, 0x62 );	

	//------------------------------------------------------------------------------
	CApplication::CApplication() : IApplication()
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::CApplication" );
		nsCodeQOR::CClassInstanceFactory* pFactory = ThisModule().ExternalClassReg().GetFactory( IApplication::ClassID() );
		if( pFactory )
		{
			m_Impl.Attach( reinterpret_cast< IApplication* >( pFactory->Instance() ), true );
			m_Impl->SetOuter( Ref() );
		}
		theApplication = this;
	}

	//------------------------------------------------------------------------------
	CApplication::CApplication( CRole::ref_type Role ) : CApplication()
	{
		__QCS_MEMBER_FCONTEXT("CApplication::CApplication");
		m_Impl->SetRole( Role );
	}

	//------------------------------------------------------------------------------
	CApplication::CApplication( const nsCodeQOR::mxGUID* pRoleID ) : CApplication()
	{
		__QCS_MEMBER_FCONTEXT("CApplication::CApplication");
		m_Impl->SetRole( new_ref< CRole >( pRoleID )/*.Detach()->Ref()*/ );
	}

	//------------------------------------------------------------------------------
	CApplication::~CApplication()
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::~CApplication" );
	}

	//------------------------------------------------------------------------------
	void CApplication::SetRole( IRole::ref_type Role )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::SetRole" );
		m_Impl->SetRole( Role );
	}

	//------------------------------------------------------------------------------
	IRole::ref_type CApplication::GetRole()
	{
		return m_Impl->GetRole();
	}

	//------------------------------------------------------------------------------
	void CApplication::SetWorkflow( IWorkflow::ref_type pWorkflow )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::SetWorkflow" );
		m_Impl->SetWorkflow( pWorkflow );
	}

	//------------------------------------------------------------------------------
	IWorkflow::ref_type CApplication::GetWorkflow()
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::GetWorkflow" );
		return m_Impl->GetWorkflow();
	}

	//------------------------------------------------------------------------------
	void CApplication::SetOuter( IApplication::ref_type /*Application*/ )
	{
		//ignore unless we implement aggregation
	}

	//------------------------------------------------------------------------------
	void CApplication::Setup( void )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::Setup" );
	}

	//------------------------------------------------------------------------------
	void CApplication::Shutdown( void )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::Shutdown" );
	}

	//------------------------------------------------------------------------------
	int CApplication::Run( void )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::Run" );
		return m_Impl->Run();
	}

	//------------------------------------------------------------------------------
	int CApplication::Run( IWorkflow::ref_type pWorkflow )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::Run" );
		return m_Impl->Run( pWorkflow );
	}

	//------------------------------------------------------------------------------
	void CApplication::EnqueueEvent( nsQOR::IEvent::ref_type pEvent )
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::EnqueueEvent" );
		m_Impl->EnqueueEvent( pEvent );
	}

	//------------------------------------------------------------------------------
	void CApplication::Stop()
	{
		__QCS_MEMBER_FCONTEXT( "CApplication::Stop" );
		m_Impl->Stop();
	}

	//------------------------------------------------------------------------------
	void CApplication::OnIdle()
	{
		__QCS_MEMBER_FCONTEXT("CApplication::OnIdle");
	}

}//nsAppocrita

 //------------------------------------------------------------------------------
__QCMP_EXPORT nsQOR::CApplication::ref_type TheApplication( void )
{
	return nsQOR::theApplication->Ref();
}

