//WinQLTimerQueue.cpp

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

#include "WinQL/Definitions/Constants.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/Application/Timer/WinQLTimerQueue.h"
#include "WinQAPI/Kernel32.h"

//------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	//--Timer Queue Timer ----------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CTimerQueue::CTimer );

	//------------------------------------------------------------------------------
	CTimerQueue::CTimer::CTimer( CTimerQueue& Queue, unsigned long DueTime, unsigned long Period, unsigned long Flags, bool* pResult ) : m_Queue( Queue )
	,	m_pResult( pResult )
	{
		_WINQ_FCONTEXT( "CTimerQueue::CTimer::CTimer" );
		__QOR_PROTECT
		{
			m_pTimerCompletionEvent = 0;
			void* pHandle = 0;
			if( CKernel32::CreateTimerQueueTimer( &pHandle, m_Queue.m_Handle.Use(), &CTimerQueue::CTimer::StaticCallback, this, DueTime, Period, Flags ) != 0 )
			{
				m_TimerHandle = pHandle;
			}
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	CTimerQueue::CTimer::~CTimer()
	{
		_WINQ_FCONTEXT( "CTimerQueue::CTimer::~CTimer" );
		__QOR_PROTECT
		{
			BOOL bResult = FALSE;
			bool bRetry = false;
			do
			{
				bResult = CKernel32::DeleteTimerQueueTimer( m_Queue.m_Handle.Use(), m_TimerHandle.Use(),
					m_pTimerCompletionEvent ? m_pTimerCompletionEvent->Use() : INVALID_HANDLE_VALUE, bRetry );
			}while( bResult == FALSE && bRetry == true );
			if( m_pResult )
			{
				*m_pResult = bResult ? true : false;
			}
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	void CTimerQueue::CTimer::SetCompletionEvent( CSyncHandle* pCompletionEvent )
	{
		_WINQ_FCONTEXT( "CTimerQueue::CTimer::SetCompletionEvent" );
		m_pTimerCompletionEvent = pCompletionEvent;
	}


	//--------------------------------------------------------------------------------
	void __stdcall CTimerQueue::CTimer::StaticCallback( void* pData1 , unsigned char ucData2 )
	{
		_WINQ_SFCONTEXT( "CTimerQueue::CTimer::StaticCallback" );
		__QOR_PROTECT
		{
			CTimerQueue::CTimer* pTimer = reinterpret_cast< CTimerQueue::CTimer* >( pData1 );
			if( pTimer )
			{
				pTimer->InstanceCallback( ucData2 );
			}
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	void CTimerQueue::CTimer::InstanceCallback( unsigned char ucData )
	{
		_WINQ_FCONTEXT( "CTimerQueue::CTimer::InstanceCallback" );
		//Override this to implement a specific callback
	}

	//--Timer Queue-------------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_LUID( CTimerQueue );

	//--------------------------------------------------------------------------------
	CTimerQueue::CTimerQueue()
	{
		_WINQ_FCONTEXT( "CTimerQueue::CTimerQueue" );
		__QOR_PROTECT
		{
			m_pCompletionEvent = 0;
			m_Handle = CKernel32::CreateTimerQueue();
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	CTimerQueue::~CTimerQueue()
	{
		_WINQ_FCONTEXT( "CTimerQueue::~CTimerQueue" );
		BOOL bResult = FALSE;
		__QOR_PROTECT
		{					
			bResult = CKernel32::DeleteTimerQueueEx( m_Handle.Use(), 
				m_pCompletionEvent ? m_pCompletionEvent->Use() : (void*)Invalid_Handle_Value );
		}__QOR_ENDPROTECT
	}

	//------------------------------------------------------------------------------
	void CTimerQueue::SetCompletionEvent( CSyncHandle* pCompletionEvent )
	{
		_WINQ_FCONTEXT( "CTimerQueue::SetCompletionEvent" );
		m_pCompletionEvent = pCompletionEvent;
	}

	//------------------------------------------------------------------------------
	bool CTimerQueue::ChangeTimer( CTimerQueue::CTimer& Timer, unsigned long DueTime, unsigned long Period )
	{
		_WINQ_FCONTEXT( "CTimerQueue::ChangeTimer" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::ChangeTimerQueueTimer( m_Handle.Use(), Timer.m_TimerHandle.Use(), DueTime, Period ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

}//nsWin32