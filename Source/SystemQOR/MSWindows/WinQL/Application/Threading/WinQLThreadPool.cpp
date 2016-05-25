//WinQLThreadPool.cpp

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

#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/Application/Threading/WinQLThreadPool.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPool::CThreadPoolHelper );

	//--------------------------------------------------------------------------------
	CThreadPool::CThreadPoolHelper::CThreadPoolHelper()
	{
		__QCS_FCONTEXT( "CThreadPoolHelper::CThreadPoolHelper" );
	}

	//--------------------------------------------------------------------------------
	CThreadPool::CThreadPoolHelper::CThreadPoolHelper( const CThreadPool::CThreadPoolHelper& src )
	{
		__QCS_FCONTEXT( "CThreadPoolHelper::CThreadPoolHelper" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CThreadPool::CThreadPoolHelper& CThreadPool::CThreadPoolHelper::operator = ( const CThreadPool::CThreadPoolHelper& src )
	{
		__QCS_FCONTEXT( "CThreadPoolHelper::operator =" );
		if( &src != this )
		{
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	CThreadPool::CThreadPoolHelper::~CThreadPoolHelper()
	{
		__QCS_FCONTEXT( "CThreadPoolHelper::~CThreadPoolHelper" );
	}
		
	//--------------------------------------------------------------------------------
	bool CThreadPool::CThreadPoolHelper::TrySubmitCallback( nsWin32::PTP_SIMPLE_CALLBACK pfns, void* pv, CThreadPoolEnvironment* pcbe )
	{
		_WINQ_FCONTEXT( "CThreadPoolHelper::TrySubmitCallback" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::TrySubmitThreadpoolCallback( reinterpret_cast< ::PTP_SIMPLE_CALLBACK >( pfns ), pv, reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( pcbe ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CThreadPool::CThreadPoolHelper::CallbackMayRunLong( nsWin32::PTP_CALLBACK_INSTANCE pci )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::CallbackMayRunLong" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::CallbackMayRunLong( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::CThreadPoolHelper::DisassociateCurrentThreadFromCallback( nsWin32::PTP_CALLBACK_INSTANCE pci )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::DisassociateCurrentThreadFromCallback" );
		__QOR_PROTECT
		{
			CKernel32::DisassociateCurrentThreadFromCallback( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::CThreadPoolHelper::FreeLibraryWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, ModuleHandle mod )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::FreeLibraryWhenCallbackReturns" );
		__QOR_PROTECT
		{
			CKernel32::FreeLibraryWhenCallbackReturns( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ), reinterpret_cast< HMODULE >( mod ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::CThreadPoolHelper::LeaveCriticalSectionWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, nsWin32::PRTL_CRITICAL_SECTION pcs )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::LeaveCriticalSectionWhenCallbackReturns" );
		__QOR_PROTECT
		{
			CKernel32::LeaveCriticalSectionWhenCallbackReturns( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ), reinterpret_cast< ::PCRITICAL_SECTION >( pcs ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::CThreadPoolHelper::ReleaseMutexWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, void* mut )
	{		
		__QCS_FCONTEXT( "CThreadPoolHelper::ReleaseMutexWhenCallbackReturns" );
		__QOR_PROTECT
		{
			CKernel32::ReleaseMutexWhenCallbackReturns( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ), mut );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::CThreadPoolHelper::ReleaseSemaphoreWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, void* sem, unsigned long crel )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::ReleaseSemaphoreWhenCallbackReturns" );
		__QOR_PROTECT
		{
			CKernel32::ReleaseSemaphoreWhenCallbackReturns( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ), sem, crel );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::CThreadPoolHelper::SetEventWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, void* evt )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::SetEventWhenCallbackReturns" );
		__QOR_PROTECT
		{
			CKernel32::SetEventWhenCallbackReturns( reinterpret_cast< ::PTP_CALLBACK_INSTANCE >( pci ), evt );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	bool CThreadPool::CThreadPoolHelper::QueueUserWorkItem( nsWin32::LPTHREAD_START_ROUTINE Function, void* Context, unsigned long Flags )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::QueueUserWorkItem" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::QueueUserWorkItem( reinterpret_cast< ::LPTHREAD_START_ROUTINE >( Function ), Context, Flags ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CThreadPool::CThreadPoolHelper::BindIoCompletionCallback( void* FileHandle, nsWin32::LPOVERLAPPED_COMPLETION_ROUTINE Function, unsigned long Flags )
	{		
		_WINQ_FCONTEXT( "CThreadPoolHelper::BindIoCompletionCallback" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::BindIoCompletionCallback( FileHandle, reinterpret_cast< ::LPOVERLAPPED_COMPLETION_ROUTINE >( Function ), Flags ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}


	//--Thread Pool-------------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPool );

	//--------------------------------------------------------------------------------
	CThreadPool::CThreadPool( void* reserved )
	{
		_WINQ_FCONTEXT( "CThreadPool::CThreadPool" );
		__QOR_PROTECT
		{
			m_pPool = reinterpret_cast< nsWin32::PTP_POOL >( CKernel32::CreateThreadpool( reserved ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPool::~CThreadPool()
	{
		_WINQ_FCONTEXT( "CThreadPool::~CThreadPool" );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpool( reinterpret_cast< ::PTP_POOL >( m_pPool ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPool::SetThreadMaximum( unsigned long cthrdMost )
	{
		_WINQ_FCONTEXT( "CThreadPool::SetThreadMaximum" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolThreadMaximum( reinterpret_cast< ::PTP_POOL >( m_pPool ), cthrdMost );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	bool CThreadPool::SetThreadMinimum( unsigned long cthrdMic )
	{
		_WINQ_FCONTEXT( "CThreadPool::SetThreadMinimum" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::SetThreadpoolThreadMinimum( reinterpret_cast< ::PTP_POOL >( m_pPool ), cthrdMic ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}


	//--Cleanup group-----------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPoolCleanupGroup );

	//--------------------------------------------------------------------------------
	CThreadPoolCleanupGroup::CThreadPoolCleanupGroup()
	{
		_WINQ_FCONTEXT( "CThreadPoolCleanupGroup::CThreadPoolCleanupGroup" );
		__QOR_PROTECT
		{
			m_pGroup = reinterpret_cast< nsWin32::PTP_CLEANUP_GROUP >( CKernel32::CreateThreadpoolCleanupGroup() );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPoolCleanupGroup::~CThreadPoolCleanupGroup()
	{
		_WINQ_FCONTEXT( "CThreadPoolCleanupGroup::~CThreadPoolCleanupGroup" );				
		CloseMembers( TRUE, 0 );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpoolCleanupGroup( reinterpret_cast< ::PTP_CLEANUP_GROUP >( m_pGroup ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolCleanupGroup::CloseMembers( bool fCancelPendingCallbacks, void* pvCleanupContext )
	{
		_WINQ_FCONTEXT( "CThreadPoolCleanupGroup::CloseMembers" );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpoolCleanupGroupMembers( reinterpret_cast< ::PTP_CLEANUP_GROUP >( m_pGroup ), fCancelPendingCallbacks ? TRUE : FALSE, pvCleanupContext );
		}__QOR_ENDPROTECT
	}


	//--Thread Pool Environment

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPoolEnvironment );

	//--------------------------------------------------------------------------------
	CThreadPoolEnvironment::CThreadPoolEnvironment()
	{
		_WINQ_FCONTEXT( "CThreadPoolEnvironment::CThreadPoolEnvironment" );
		__QOR_PROTECT
		{
			CKernel32::InitializeThreadpoolEnvironment( reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( this ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPoolEnvironment::~CThreadPoolEnvironment()
	{
		_WINQ_FCONTEXT( "CThreadPoolEnvironment::~CThreadPoolEnvironment" );
		__QOR_PROTECT
		{
			CKernel32::DestroyThreadpoolEnvironment( reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( this ) );
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	void CThreadPoolEnvironment::SetThreadPoolCallbackCleanupGroup( CThreadPoolCleanupGroup* ptpcg, nsWin32::PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng )
	{
		_WINQ_FCONTEXT( "CThreadPoolEnvironment::SetThreadPoolCallbackCleanupGroup" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolCallbackCleanupGroup( reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( this ), reinterpret_cast< ::PTP_CLEANUP_GROUP >( ptpcg->m_pGroup ), reinterpret_cast< ::PTP_CLEANUP_GROUP_CANCEL_CALLBACK >( pfng ) );
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	void CThreadPoolEnvironment::SetThreadPoolCallbackLibrary( void* mod )
	{
		_WINQ_FCONTEXT( "CThreadPoolEnvironment::SetThreadPoolCallbackLibrary" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolCallbackLibrary( reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( this ), mod );
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	void CThreadPoolEnvironment::SetThreadPoolCallbackPool( CThreadPool* ptpp )
	{
		_WINQ_FCONTEXT( "CThreadPoolEnvironment::SetThreadPoolCallbackPool" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolCallbackPool( reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( this ), reinterpret_cast< ::PTP_POOL >( ptpp->m_pPool ) );
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	void CThreadPoolEnvironment::SetThreadPoolCallbackRunsLong()
	{
		_WINQ_FCONTEXT( "CThreadPoolEnvironment::SetThreadPoolCallbackRunsLong" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolCallbackRunsLong( reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( this ) );
		}__QOR_ENDPROTECT
	}


	//--IO Session--------------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPoolIOSession );

	//--------------------------------------------------------------------------------
	CThreadPoolIOSession::CThreadPoolIOSession( void* fl, fpThreadPoolIOCallback pfnio, void* pv, CThreadPoolEnvironment* pcbe )
	{
		_WINQ_FCONTEXT( "CThreadPoolIOSession::CThreadPoolIOSession" );
		__QOR_PROTECT
		{
			m_pIO = reinterpret_cast< nsWin32::PTP_IO >( CKernel32::CreateThreadpoolIo( fl, reinterpret_cast< PTP_WIN32_IO_CALLBACK >( pfnio ), pv, reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( pcbe ) ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPoolIOSession::~CThreadPoolIOSession()
	{
		_WINQ_FCONTEXT( "CThreadPoolIOSession::~CThreadPoolIOSession" );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpoolIo( reinterpret_cast< ::PTP_IO >( m_pIO ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolIOSession::Cancel()
	{
		_WINQ_FCONTEXT( "CThreadPoolIOSession::Cancel" );
		__QOR_PROTECT
		{
			CKernel32::CancelThreadpoolIo( reinterpret_cast< ::PTP_IO >( m_pIO ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolIOSession::Start()
	{
		_WINQ_FCONTEXT( "CThreadPoolIOSession::Start" );
		__QOR_PROTECT
		{
			CKernel32::StartThreadpoolIo( reinterpret_cast< ::PTP_IO >( m_pIO ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolIOSession::WaitForCallbacks( bool fCancelPendingCallbacks )
	{
		_WINQ_FCONTEXT( "CThreadPoolIOSession::WaitForCallbacks" );
		__QOR_PROTECT
		{
			CKernel32::WaitForThreadpoolIoCallbacks( reinterpret_cast< ::PTP_IO >( m_pIO ), fCancelPendingCallbacks ? TRUE : FALSE );
		}__QOR_ENDPROTECT
	}


	//--Thread Pool Timer

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPoolTimer );

	//--------------------------------------------------------------------------------
	CThreadPoolTimer::CThreadPoolTimer( nsWin32::PTP_TIMER_CALLBACK pfnti, void* pv, CThreadPoolEnvironment* pcbe )
	{
		_WINQ_FCONTEXT( "CThreadPoolTimer::CThreadPoolTimer" );
		__QOR_PROTECT
		{
			m_pTimer = reinterpret_cast< nsWin32::PTP_TIMER >( CKernel32::CreateThreadpoolTimer( reinterpret_cast< ::PTP_TIMER_CALLBACK >( pfnti ), pv, reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( pcbe ) ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPoolTimer::~CThreadPoolTimer()
	{
		_WINQ_FCONTEXT( "CThreadPoolTimer::~CThreadPoolTimer" );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpoolTimer( reinterpret_cast< ::PTP_TIMER >( m_pTimer ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolTimer::Set( nsWin32::PFILETIME pftDueTime, unsigned long msPeriod, unsigned long msWindowLength )
	{
		_WINQ_FCONTEXT( "CThreadPoolTimer::Set" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolTimer( reinterpret_cast< ::PTP_TIMER >( m_pTimer ), reinterpret_cast< ::PFILETIME >( pftDueTime ), msPeriod, msWindowLength );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolTimer::WaitForCallbacks( bool fCancelPendingCallbacks )
	{
		_WINQ_FCONTEXT( "CThreadPoolTimer::WaitForCallbacks" );
		__QOR_PROTECT
		{
			CKernel32::WaitForThreadpoolTimerCallbacks( reinterpret_cast< ::PTP_TIMER >( m_pTimer ), fCancelPendingCallbacks ? TRUE : FALSE );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	bool CThreadPoolTimer::IsSet()
	{
		_WINQ_FCONTEXT( "CThreadPoolTimer::IsSet" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::IsThreadpoolTimerSet( reinterpret_cast< ::PTP_TIMER >( m_pTimer ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}


	//--Thread Pool Wait

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPoolWait );

	//--------------------------------------------------------------------------------
	CThreadPoolWait::CThreadPoolWait( nsWin32::PTP_WAIT_CALLBACK pfnwa, void* pv, CThreadPoolEnvironment* pcbe )
	{
		_WINQ_FCONTEXT( "CThreadPoolWait::CThreadPoolWait" );
		__QOR_PROTECT
		{
			m_pWait = reinterpret_cast< nsWin32::PTP_WAIT >( CKernel32::CreateThreadpoolWait( reinterpret_cast< ::PTP_WAIT_CALLBACK >( pfnwa ), pv, reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( pcbe ) ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPoolWait::~CThreadPoolWait()
	{
		_WINQ_FCONTEXT( "CThreadPoolWait::~CThreadPoolWait" );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpoolWait( reinterpret_cast< ::PTP_WAIT >( m_pWait ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolWait::Set( void* h, nsWin32::PFILETIME pftTimeout )
	{
		_WINQ_FCONTEXT( "CThreadPoolWait::Set" );
		__QOR_PROTECT
		{
			CKernel32::SetThreadpoolWait( reinterpret_cast< ::PTP_WAIT >( m_pWait ), h, reinterpret_cast< ::PFILETIME >( pftTimeout ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolWait::WaitForCallbacks( bool fCancelPendingCallbacks )
	{
		_WINQ_FCONTEXT( "CThreadPoolWait::WaitForCallbacks" );
		__QOR_PROTECT
		{
			CKernel32::WaitForThreadpoolWaitCallbacks( reinterpret_cast< ::PTP_WAIT >( m_pWait ), fCancelPendingCallbacks ? TRUE : FALSE );
		}__QOR_ENDPROTECT
	}


	//--Thread pool work--------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CThreadPoolWork );

	//--------------------------------------------------------------------------------
	CThreadPoolWork::CThreadPoolWork( nsWin32::PTP_WORK_CALLBACK pfnwk, void* pv, CThreadPoolEnvironment* pcbe )
	{
		_WINQ_FCONTEXT( "CThreadPoolWork::CThreadPoolWork" );
		__QOR_PROTECT
		{
			m_pWork = reinterpret_cast< nsWin32::PTP_WORK >( CKernel32::CreateThreadpoolWork( reinterpret_cast< ::PTP_WORK_CALLBACK >( pfnwk ), pv, reinterpret_cast< ::PTP_CALLBACK_ENVIRON >( pcbe ) ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CThreadPoolWork::~CThreadPoolWork()
	{
		_WINQ_FCONTEXT( "CThreadPoolWork::~CThreadPoolWork" );
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolWork::Close()
	{
		_WINQ_FCONTEXT( "CThreadPoolWork::Close" );
		__QOR_PROTECT
		{
			CKernel32::CloseThreadpoolWork( reinterpret_cast< ::PTP_WORK >( m_pWork ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolWork::Submit()
	{
		_WINQ_FCONTEXT( "CThreadPoolWork::Submit" );
		__QOR_PROTECT
		{
			CKernel32::SubmitThreadpoolWork( reinterpret_cast< ::PTP_WORK >( m_pWork ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CThreadPoolWork::WaitForCallbacks( bool fCancelPendingCallbacks )
	{
		_WINQ_FCONTEXT( "CThreadPoolWork::WaitForCallbacks" );
		__QOR_PROTECT
		{
			CKernel32::WaitForThreadpoolWorkCallbacks( reinterpret_cast< ::PTP_WORK >( m_pWork ), fCancelPendingCallbacks ? true : false );
		}__QOR_ENDPROTECT
	}

}//nsWin32
