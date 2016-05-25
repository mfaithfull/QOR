//resource_types.h

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

#ifndef SYSTEMQOR_LIN_TYPES_SYS_RESOURCETYPES_H_3
#define SYSTEMQOR_LIN_TYPES_SYS_RESOURCETYPES_H_3

#include "SystemQOR/Linux/LIN_features.h"

#define __NEED_id_t
#define __NEED_time_t
#define __NEED_suseconds_t
#define __NEED_struct_timeval

#ifdef _GNU_SOURCE
#   define __NEED_pid_t
#endif

#include QOR_SYS_ARCHHEADER(alltypes.h)
#include QOR_SYS_ARCHHEADER(resource.h)

//------------------------------------------------------------------------------
namespace nsLinux
{
    typedef unsigned long long rlim_t;

    //------------------------------------------------------------------------------
    struct rlimit
    {
        rlim_t rlim_cur;
        rlim_t rlim_max;
    };

    //------------------------------------------------------------------------------
    struct rusage
    {
        timeval ru_utime;
        timeval ru_stime;
        /* linux extentions, but useful */
        long	ru_maxrss;
        long	ru_ixrss;
        long	ru_idrss;
        long	ru_isrss;
        long	ru_minflt;
        long	ru_majflt;
        long	ru_nswap;
        long	ru_inblock;
        long	ru_oublock;
        long	ru_msgsnd;
        long	ru_msgrcv;
        long	ru_nsignals;
        long	ru_nvcsw;
        long	ru_nivcsw;
        /* room for more... */
        long    __reserved[16];
    };

#ifdef _GNU_SOURCE
#   define prlimit64 prlimit
#endif

#define PRIO_MIN (-20)
#define PRIO_MAX 20

#define PRIO_PROCESS 0
#define PRIO_PGRP    1
#define PRIO_USER    2

#define RUSAGE_SELF     0
#define RUSAGE_CHILDREN 1

#define RLIM_INFINITY (~0ULL)
#define RLIM_SAVED_CUR RLIM_INFINITY
#define RLIM_SAVED_MAX RLIM_INFINITY

#define RLIMIT_CPU     0
#define RLIMIT_FSIZE   1
#define RLIMIT_DATA    2
#define RLIMIT_STACK   3
#define RLIMIT_CORE    4
#ifndef RLIMIT_RSS
#define RLIMIT_RSS     5
#define RLIMIT_NPROC   6
#define RLIMIT_NOFILE  7
#define RLIMIT_MEMLOCK 8
#define RLIMIT_AS      9
#endif
#define RLIMIT_LOCKS   10
#define RLIMIT_SIGPENDING 11
#define RLIMIT_MSGQUEUE 12
#define RLIMIT_NICE    13
#define RLIMIT_RTPRIO  14
#define RLIMIT_NLIMITS 15

#define RLIM_NLIMITS RLIMIT_NLIMITS

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#   define getrlimit64 getrlimit
#   define setrlimit64 setrlimit
#   define rlimit64 rlimit
#   define rlim64_t rlim_t
#endif

}//nsLinux


#endif//SYSTEMQOR_LIN_TYPES_SYS_RESOURCETYPES_H_3
