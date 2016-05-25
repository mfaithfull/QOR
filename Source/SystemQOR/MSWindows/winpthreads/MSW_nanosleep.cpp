//MSW_nanosleep.cpp

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

#include "WinQL/Definitions/Interfaces.h"
#include "WinQL/System/Clock/WinQLTime.h"
#include <errno.h>
#include <time.h>
#include "SystemQOR/MSWindows/types/pthread_types.h"
#include "SystemQOR/MSWindows/MSW_pthread.h"

#define POW10_3                 1000
#define POW10_4                 10000
#define POW10_6                 1000000
#define POW10_9                 1000000000
#define MAX_SLEEP_IN_MS         4294967294UL

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	/**
	 * Sleep for the specified time.
	 * @param  request The desired amount of time to sleep.
	 * @param  remain The remain amount of time to sleep.
	 * @return If the function succeeds, the return value is 0.
	 *         If the function fails, the return value is -1,
	 *         with errno set to indicate the error.
	 */
	int nanosleep( const timespec* request, timespec* remain )
	{
		nsWin32::CTimeHelper TimeHelper;
		unsigned long ms, rc = 0;
		unsigned __int64 u64, want, real;

		union 
		{
			unsigned __int64 ns100;
			nsWin32::FILETIME ft;
		}  _start, _end;

		if ( request->tv_sec < 0 || request->tv_nsec < 0 || request->tv_nsec >= POW10_9) {
			errno = EINVAL;
			return -1;
		}

		if (remain != NULL) TimeHelper.GetSystemTimeAsFileTime(&_start.ft);

		want = u64 = request->tv_sec * POW10_3 + request->tv_nsec / POW10_6;
		while (u64 > 0 && rc == 0) 
		{
			if( u64 >= MAX_SLEEP_IN_MS )
			{
				ms = MAX_SLEEP_IN_MS;
			}
			else 
			{
				ms = (unsigned long) u64;
			}

			u64 -= ms;
			rc = Cpthread::delay_np_ms(ms);
		}

		if( rc != 0 ) 
		{ /* WAIT_IO_COMPLETION (192) */
			if( remain != NULL ) 
			{
				TimeHelper.GetSystemTimeAsFileTime(&_end.ft);
				real = (_end.ns100 - _start.ns100) / POW10_4;

				if( real >= want )
				{
					u64 = 0;
				}
				else 
				{
					u64 = want - real;
				}

				remain->tv_sec = u64 / POW10_3;
				remain->tv_nsec = (long) (u64 % POW10_3) * POW10_6;
			}

			errno = EINTR;
			return -1;
		}

		return 0;
	}

}//nsWin32

#endif//(QOR_SYS_OS == QOR_SYS_MSW)
