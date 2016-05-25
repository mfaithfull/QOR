//WinQLTimerQueue.h

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

#ifndef WINQL_TIMERQUEUE_H_3
#define WINQL_TIMERQUEUE_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/codingmacros.h"
#include "WinQL/Application/Threading/WinQLWait.h"
#include "WinQL/CodeServices/Handles/WinQLSyncHandle.h"

//------------------------------------------------------------------------------
namespace nsWin32
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CTimerQueue
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CTimerQueue );

		//------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CTimer
		{
			friend class CTimerQueue;

		public:

			__QOR_DECLARE_OCLASS_ID( CTimerQueue::CTimer );

			CTimer( CTimerQueue& Queue, unsigned long DueTime, unsigned long Period, unsigned long Flags, bool* pResult = 0 );
			virtual ~CTimer();
			void SetCompletionEvent( CSyncHandle* pCompletionEvent );

		protected:

			virtual void InstanceCallback( unsigned char ucData );

		private:

			CTimerQueue& m_Queue;
			CSyncHandle m_TimerHandle;
			CSyncHandle* m_pTimerCompletionEvent;
			bool* m_pResult;

			static void __stdcall StaticCallback( void* pData1 , unsigned char ucData2 );

			__QCS_DECLARE_NONCOPYABLE( CTimer );

		};
			
		friend class CTimer;

		CTimerQueue();
		virtual ~CTimerQueue();
		void SetCompletionEvent( CSyncHandle* pCompletionEvent );
		bool ChangeTimer( CTimerQueue::CTimer& Timer, unsigned long DueTime, unsigned long Period );

	private:

		CSyncHandle m_Handle;
		CSyncHandle* m_pCompletionEvent;
	};

}//nsWin32

#endif//WINQL_TIMERQUEUE_H_3
