//MSW_clock.cpp

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

/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include "SystemQOR.h"

#if		(QOR_SYS_OS == QOR_SYS_MSW)

#include "WinQL/System/Performance/WinQLPerformanceHelper.h"
#include "WinQL/System/Clock/WinQLTime.h"
#include "WinQL/Application/Process/WinQLProcess.h"
#include "WinQL/Application/Threading/WinQLThread.h"
#include <errno.h>
#define __STDC_CONSTANT_MACROS
#include <stdint.h>
#include <time.h>
#include <pthread.h>

#define POW10_7                 10000000
#define POW10_9                 1000000000

/* Number of 100ns-seconds between the beginning of the Windows epoch
 * (Jan. 1, 1601) and the Unix epoch (Jan. 1, 1970)
 */
#define DELTA_EPOCH_IN_100NS    __QCMP_LONG_SUFFIX(116444736000000000)

//--------------------------------------------------------------------------------
namespace nsWin32
{

	//--------------------------------------------------------------------------------
	static __QCMP_INLINE int lc_set_errno( int result )
	{
		if (result != 0) 
		{
			errno = result;
			return -1;
		}
		return 0;
	}

	//--------------------------------------------------------------------------------
	/**
	 * Get the resolution of the specified clock clock_id and
	 * stores it in the struct timespec pointed to by res.
	 * @param  clock_id The clock_id argument is the identifier of the particular
	 *         clock on which to act. The following clocks are supported:
	 * <pre>
	 *     CLOCK_REALTIME  System-wide real-time clock. Setting this clock
	 *                 requires appropriate privileges.
	 *     CLOCK_MONOTONIC Clock that cannot be set and represents monotonic
	 *                 time since some unspecified starting point.
	 *     CLOCK_PROCESS_CPUTIME_ID High-resolution per-process timer from the CPU.
	 *     CLOCK_THREAD_CPUTIME_ID  Thread-specific CPU-time clock.
	 * </pre>
	 * @param  res The pointer to a timespec structure to receive the time
	 *         resolution.
	 * @return If the function succeeds, the return value is 0.
	 *         If the function fails, the return value is -1,
	 *         with errno set to indicate the error.
	 */
	int clock_getres( clockid_t clock_id, timespec* res)
	{
		switch(clock_id) 
		{
		case CLOCK_MONOTONIC:
			{
				nsWin32::LARGE_INTEGER pf;
				nsWin32::CPerformanceHelper PerformanceHelper;

				if( PerformanceHelper.QueryFrequency( pf ) == 0 )
				{
					return lc_set_errno( EINVAL );
				}

				res->tv_sec = 0;
				res->tv_nsec = (int)( ( POW10_9 + ( pf.QuadPart >> 1 ) ) / pf.QuadPart );
				if( res->tv_nsec < 1 )
				{
					res->tv_nsec = 1;
				}

				return 0;
			}

		case CLOCK_REALTIME:
		case CLOCK_PROCESS_CPUTIME_ID:
		case CLOCK_THREAD_CPUTIME_ID:
			{
				unsigned long timeAdjustment, timeIncrement;
				int isTimeAdjustmentDisabled;
				nsWin32::CTimeHelper TimeHelper;
				TimeHelper.GetSystemTimeAdjustment( &timeAdjustment, &timeIncrement, &isTimeAdjustmentDisabled );
				res->tv_sec = 0;
				res->tv_nsec = timeIncrement * 100;
				return 0;
			}
		default:
			break;
		}

		return lc_set_errno( EINVAL );
	}

	//--------------------------------------------------------------------------------
	/**
	 * Get the time of the specified clock clock_id and stores it in the struct
	 * timespec pointed to by tp.
	 * @param  clock_id The clock_id argument is the identifier of the particular
	 *         clock on which to act. The following clocks are supported:
	 * <pre>
	 *     CLOCK_REALTIME  System-wide real-time clock. Setting this clock
	 *                 requires appropriate privileges.
	 *     CLOCK_MONOTONIC Clock that cannot be set and represents monotonic
	 *                 time since some unspecified starting point.
	 *     CLOCK_PROCESS_CPUTIME_ID High-resolution per-process timer from the CPU.
	 *     CLOCK_THREAD_CPUTIME_ID  Thread-specific CPU-time clock.
	 * </pre>
	 * @param  tp The pointer to a timespec structure to receive the time.
	 * @return If the function succeeds, the return value is 0.
	 *         If the function fails, the return value is -1,
	 *         with errno set to indicate the error.
	 */
	int clock_gettime( clockid_t clock_id, timespec* tp )
	{
		unsigned __int64 t;
		nsWin32::LARGE_INTEGER pf, pc;
		union 
		{
			unsigned __int64 u64;
			nsWin32::FILETIME ft;
		}  ct, et, kt, ut;

		switch( clock_id ) 
		{
		case CLOCK_REALTIME:
			{
				nsWin32::CTimeHelper TimeHelper;
				TimeHelper.GetSystemTimeAsFileTime( &ct.ft );
				t = ct.u64 - DELTA_EPOCH_IN_100NS;
				tp->tv_sec = t / POW10_7;
				tp->tv_nsec = ((int) (t % POW10_7)) * 100;

				return 0;
			}

		case CLOCK_MONOTONIC:
			{
				nsWin32::CPerformanceHelper PerformanceHelper;
				if( PerformanceHelper.QueryFrequency(pf) == 0 )
				{
					return lc_set_errno( EINVAL );
				}

				if( PerformanceHelper.QueryCounter(pc) == 0 )
				{
					return lc_set_errno( EINVAL );
				}

				tp->tv_sec = pc.QuadPart / pf.QuadPart;
				tp->tv_nsec = (int)( ( ( pc.QuadPart % pf.QuadPart ) * POW10_9 + ( pf.QuadPart >> 1 ) ) / pf.QuadPart );
				if( tp->tv_nsec >= POW10_9 ) 
				{
					tp->tv_sec ++;
					tp->tv_nsec -= POW10_9;
				}

				return 0;
			}

		case CLOCK_PROCESS_CPUTIME_ID:
			{
				nsWin32::CProcess* pProcess = nsWin32::ThisProcess();
				if( 0 == pProcess->GetTimes( ct.ft, et.ft, kt.ft, ut.ft ) )
				{
					return lc_set_errno( EINVAL );
				}
				t = kt.u64 + ut.u64;
				tp->tv_sec = t / POW10_7;
				tp->tv_nsec = ( (int)( t % POW10_7 ) ) * 100;

				return 0;
			}

		case CLOCK_THREAD_CPUTIME_ID: 
			{
				if( 0 == nsWin32::GetCurrentWin32Thread()->GetTimes( &ct.ft, &et.ft, &kt.ft, &ut.ft ) )
				{
					return lc_set_errno(EINVAL);
				}
				t = kt.u64 + ut.u64;
				tp->tv_sec = t / POW10_7;
				tp->tv_nsec = ( (int)( t % POW10_7 ) ) * 100;

				return 0;
			}

		default:
			break;
		}

		return lc_set_errno( EINVAL );
	}

	//--------------------------------------------------------------------------------
	/**
	 * Sleep for the specified time.
	 * @param  clock_id This argument should always be CLOCK_REALTIME (0).
	 * @param  flags 0 for relative sleep interval, others for absolute waking up.
	 * @param  request The desired sleep interval or absolute waking up time.
	 * @param  remain The remain amount of time to sleep.
	 *         The current implemention just ignore it.
	 * @return If the function succeeds, the return value is 0.
	 *         If the function fails, the return value is -1,
	 *         with errno set to indicate the error.
	 */
	int clock_nanosleep( clockid_t clock_id, int flags, const timespec* request, timespec* remain )
	{
		timespec tp;

		if( clock_id != CLOCK_REALTIME )
		{
			return lc_set_errno( EINVAL );
		}

		if( flags == 0 )
		{
			return nanosleep( request, remain );
		}

		// TIMER_ABSTIME = 1
		clock_gettime( CLOCK_REALTIME, &tp );

		tp.tv_sec = request->tv_sec - tp.tv_sec;
		tp.tv_nsec = request->tv_nsec - tp.tv_nsec;
		if( tp.tv_nsec < 0 ) 
		{
			tp.tv_nsec += POW10_9;
			tp.tv_sec --;
		}

		return nanosleep( &tp, remain );
	}

	//--------------------------------------------------------------------------------
	/**
	 * Set the time of the specified clock clock_id.
	 * @param  clock_id This argument should always be CLOCK_REALTIME (0).
	 * @param  tp The requested time.
	 * @return If the function succeeds, the return value is 0.
	 *         If the function fails, the return value is -1,
	 *         with errno set to indicate the error.
	 */
	int clock_settime( clockid_t clock_id, const timespec* tp )
	{
		nsWin32::CTimeHelper TimeHelper;
		nsWin32::SystemTime st;

		union 
		{
			unsigned __int64 u64;
			nsWin32::FILETIME ft;
		}t;

		if( clock_id != CLOCK_REALTIME )
		{
			return lc_set_errno( EINVAL );
		}

		t.u64 = tp->tv_sec * (__int64) POW10_7 + tp->tv_nsec / 100 + DELTA_EPOCH_IN_100NS;

		if ( TimeHelper.FileTimeToSystemTime(&t.ft, &st) == 0)
		{
			return lc_set_errno(EINVAL);
		}

		if( TimeHelper.SetSystemTime( &st ) == 0 )
		{
			return lc_set_errno(EPERM);
		}

		return 0;
	}

}//nsWin32

#endif//(QOR_SYS_OS == QOR_SYS_MSW)
