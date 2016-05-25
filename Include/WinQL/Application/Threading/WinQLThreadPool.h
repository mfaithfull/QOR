//WinQLThreadPool.h

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

//Win32 Code Services ThreadPool

#ifndef WINQL_CS_THRDPOOL_H_3
#define WINQL_CS_THRDPOOL_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Application/Threading/WinQLThread.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	typedef struct _TP_CALLBACK_INSTANCE TP_CALLBACK_INSTANCE, *PTP_CALLBACK_INSTANCE;
	typedef struct _TP_CLEANUP_GROUP TP_CLEANUP_GROUP, *PTP_CLEANUP_GROUP; 
	typedef void ( __QCMP_STDCALLCONVENTION *PTP_SIMPLE_CALLBACK )( nsWin32::PTP_CALLBACK_INSTANCE Instance, void* Context );
	typedef struct _TP_POOL TP_POOL, *PTP_POOL; 
	typedef void ( __QCMP_STDCALLCONVENTION *PTP_CLEANUP_GROUP_CANCEL_CALLBACK )( void* ObjectContext, void* CleanupContext );

	//--------------------------------------------------------------------------------
	typedef enum _TP_CALLBACK_PRIORITY 
	{
		TP_CALLBACK_PRIORITY_HIGH,
		TP_CALLBACK_PRIORITY_NORMAL,
		TP_CALLBACK_PRIORITY_LOW,
		TP_CALLBACK_PRIORITY_INVALID
	} TP_CALLBACK_PRIORITY;

#	if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

	//--------------------------------------------------------------------------------
	typedef struct _TP_CALLBACK_ENVIRON_V3 
	{
		unsigned long                      Version;
		PTP_POOL                           Pool;
		PTP_CLEANUP_GROUP                  CleanupGroup;
		PTP_CLEANUP_GROUP_CANCEL_CALLBACK  CleanupGroupCancelCallback;
		void*                              RaceDll;
		struct _ACTIVATION_CONTEXT        *ActivationContext;
		PTP_SIMPLE_CALLBACK                FinalizationCallback;
		union 
		{
			unsigned long                  Flags;
			struct 
			{
				unsigned long              LongFunction :  1;
				unsigned long              Persistent   :  1;
				unsigned long              Private      : 30;
			} s;
		} u;    
		TP_CALLBACK_PRIORITY               CallbackPriority;
		unsigned long                      Size;
	} TP_CALLBACK_ENVIRON_V3;

	typedef TP_CALLBACK_ENVIRON_V3 TP_CALLBACK_ENVIRON, *PTP_CALLBACK_ENVIRON;

#	else

	//--------------------------------------------------------------------------------
	typedef struct _TP_CALLBACK_ENVIRON_V1 
	{
		TP_VERSION                         Version;
		PTP_POOL                           Pool;
		PTP_CLEANUP_GROUP                  CleanupGroup;
		PTP_CLEANUP_GROUP_CANCEL_CALLBACK  CleanupGroupCancelCallback;
		void*                              RaceDll;
		struct _ACTIVATION_CONTEXT        *ActivationContext;
		PTP_SIMPLE_CALLBACK                FinalizationCallback;
		union 
		{
			unsigned long                  Flags;
			struct 
			{
				unsigned long              LongFunction :  1;
				unsigned long              Persistent   :  1;
				unsigned long              Private      : 30;
			} s;
		} u;    
	} TP_CALLBACK_ENVIRON_V1;

	typedef TP_CALLBACK_ENVIRON_V1 TP_CALLBACK_ENVIRON, *PTP_CALLBACK_ENVIRON;

#	endif

	//--------------------------------------------------------------------------------
	typedef struct _TP_IO TP_IO, *PTP_IO;
	typedef struct _TP_TIMER TP_TIMER, *PTP_TIMER;
	typedef struct _TP_WAIT TP_WAIT, *PTP_WAIT;
	typedef struct _TP_WORK TP_WORK, *PTP_WORK;	

	typedef unsigned long TP_WAIT_RESULT;
	
	typedef void ( __QCMP_STDCALLCONVENTION *fpThreadPoolIOCallback )( nsWin32::PTP_CALLBACK_INSTANCE Instance, void* Context, void* Overlapped, unsigned long IoResult, Cmp_ulong_ptr NumberOfBytesTransferred, nsWin32::PTP_IO Io );
	typedef void ( __QCMP_STDCALLCONVENTION *PTP_TIMER_CALLBACK )( nsWin32::PTP_CALLBACK_INSTANCE Instance, void* Context, nsWin32::PTP_TIMER Timer );
	typedef void ( __QCMP_STDCALLCONVENTION *PTP_WAIT_CALLBACK )( nsWin32::PTP_CALLBACK_INSTANCE Instance, void* Context, nsWin32::PTP_WAIT Wait, nsWin32::TP_WAIT_RESULT WaitResult );
	typedef void ( __QCMP_STDCALLCONVENTION *PTP_WORK_CALLBACK )( nsWin32::PTP_CALLBACK_INSTANCE Instance, void* Context, nsWin32::PTP_WORK Work );

	class CThreadPoolEnvironment;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPool
	{
		friend class CThreadPoolEnvironment;

	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPool );

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CThreadPoolHelper
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CThreadPool::CThreadPoolHelper );

			CThreadPoolHelper();
			CThreadPoolHelper( const CThreadPoolHelper& );
			~CThreadPoolHelper();
			CThreadPoolHelper& operator = ( const CThreadPoolHelper& );

			bool TrySubmitCallback( nsWin32::PTP_SIMPLE_CALLBACK pfns, void* pv, CThreadPoolEnvironment* pcbe );
			bool CallbackMayRunLong( nsWin32::PTP_CALLBACK_INSTANCE pci );
			void DisassociateCurrentThreadFromCallback( nsWin32::PTP_CALLBACK_INSTANCE pci );
			void FreeLibraryWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, ModuleHandle mod );
			void LeaveCriticalSectionWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, nsWin32::PRTL_CRITICAL_SECTION pcs );
			void ReleaseMutexWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, void* mut );
			void ReleaseSemaphoreWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, void* sem, unsigned long crel );
			void SetEventWhenCallbackReturns( nsWin32::PTP_CALLBACK_INSTANCE pci, void* evt );
			bool QueueUserWorkItem( nsWin32::LPTHREAD_START_ROUTINE Function, void* Context, unsigned long Flags );
			bool BindIoCompletionCallback( void* FileHandle, nsWin32::LPOVERLAPPED_COMPLETION_ROUTINE Function, unsigned long Flags );
		};

		static CThreadPoolHelper Helper;

		CThreadPool( void* reserved = 0 );
		virtual ~CThreadPool();
		void SetThreadMaximum( unsigned long cthrdMost );
		bool SetThreadMinimum( unsigned long cthrdMic );

	private:

		nsWin32::PTP_POOL m_pPool;

		CThreadPool( const CThreadPool& );
		CThreadPool& operator = ( const CThreadPool& );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPoolCleanupGroup
	{
		friend class CThreadPoolEnvironment;

	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPoolCleanupGroup );

		CThreadPoolCleanupGroup();
		virtual ~CThreadPoolCleanupGroup();
		void CloseMembers( bool fCancelPendingCallbacks, void* pvCleanupContext );

	private:

		nsWin32::PTP_CLEANUP_GROUP m_pGroup;

		CThreadPoolCleanupGroup( const CThreadPoolCleanupGroup& );
		CThreadPoolCleanupGroup& operator = ( const CThreadPoolCleanupGroup& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPoolEnvironment : public nsWin32::TP_CALLBACK_ENVIRON
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPoolEnvironment );

		CThreadPoolEnvironment();
		virtual ~CThreadPoolEnvironment();

		void SetThreadPoolCallbackCleanupGroup( CThreadPoolCleanupGroup* ptpcg, nsWin32::PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng );
		void SetThreadPoolCallbackLibrary( void* mod );
		void SetThreadPoolCallbackPool( CThreadPool* ptpp );
		void SetThreadPoolCallbackRunsLong();

	private:

		CThreadPoolEnvironment( const CThreadPoolEnvironment& );
		CThreadPoolEnvironment& operator = ( const CThreadPoolEnvironment& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPoolIOSession 
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPoolIOSession );

		CThreadPoolIOSession( void* fl, fpThreadPoolIOCallback, void* pv, CThreadPoolEnvironment* pcbe );
		virtual ~CThreadPoolIOSession();
		void Cancel();
		void Start();
		void WaitForCallbacks( bool fCancelPendingCallbacks );

	private:

		nsWin32::PTP_IO m_pIO;

		CThreadPoolIOSession( const CThreadPoolIOSession& );
		CThreadPoolIOSession& operator = ( const CThreadPoolIOSession& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPoolTimer
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPoolTimer );

		CThreadPoolTimer( nsWin32::PTP_TIMER_CALLBACK pfnti, void* pv, CThreadPoolEnvironment* pcbe );
		virtual ~CThreadPoolTimer();
		void Set( nsWin32::PFILETIME pftDueTime, unsigned long msPeriod, unsigned long msWindowLength );
		void WaitForCallbacks( bool fCancelPendingCallbacks );
		bool IsSet();

	private:

		nsWin32::PTP_TIMER m_pTimer;

		CThreadPoolTimer( const CThreadPoolTimer& );
		CThreadPoolTimer& operator = ( const CThreadPoolTimer& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPoolWait
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPoolWait );

		CThreadPoolWait( nsWin32::PTP_WAIT_CALLBACK pfnwa, void* pv, CThreadPoolEnvironment* pcbe );
		virtual ~CThreadPoolWait();

		void Set( void* h, nsWin32::PFILETIME pftTimeout );
		void WaitForCallbacks( bool fCancelPendingCallbacks );

	private:

		nsWin32::PTP_WAIT m_pWait;

		CThreadPoolWait( const CThreadPoolWait& );
		CThreadPoolWait& operator = ( const CThreadPoolWait& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadPoolWork
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CThreadPoolWork );

		CThreadPoolWork( nsWin32::PTP_WORK_CALLBACK pfnwk, void* pv, CThreadPoolEnvironment* pcbe );
		virtual ~CThreadPoolWork();

		void Close( void );
		void Submit( void );
		void WaitForCallbacks( bool fCancelPendingCallbacks );

	private:

		nsWin32::PTP_WORK m_pWork;

		CThreadPoolWork( const CThreadPoolWork& );
		CThreadPoolWork& operator = ( const CThreadPoolWork& );
	};

}//nsWin32

#endif//WINQL_CS_THRDPOOL_H_3

