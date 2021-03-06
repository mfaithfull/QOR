//mqueue.h

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

#ifndef	QOR_MQUEUE_H_3
#define QOR_MQUEUE_H_3

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(mqueue)

typedef nsPlatform::pthread_attr_t pthread_attr_t;
typedef nsPlatform::ssize_t ssize_t;
typedef nsPlatform::mqd_t mqd_t;
typedef nsPlatform::mq_attr mq_attr;
typedef nsPlatform::timespec timespec;

__QCMP_STARTLINKAGE_C

    __QOR_INTERFACE( __CQOR ) int mq_close( mqd_t );
    __QOR_INTERFACE( __CQOR ) int mq_getattr( mqd_t, mq_attr* );
    __QOR_INTERFACE( __CQOR ) int mq_notify( mqd_t, const sigevent* );
    __QOR_INTERFACE( __CQOR ) mqd_t mq_open( const char*, int, ... );
    __QOR_INTERFACE( __CQOR ) ssize_t mq_receive( mqd_t, char*, size_t, unsigned* );
    __QOR_INTERFACE( __CQOR ) int mq_send( mqd_t, const char*, size_t, unsigned );
    __QOR_INTERFACE( __CQOR ) int mq_setattr( mqd_t, const mq_attr* __QCMP_RESTRICT, mq_attr* __QCMP_RESTRICT );
    __QOR_INTERFACE( __CQOR ) ssize_t mq_timedreceive( mqd_t, char* __QCMP_RESTRICT, size_t, unsigned* __QCMP_RESTRICT, const timespec* __QCMP_RESTRICT );
    __QOR_INTERFACE( __CQOR ) int mq_timedsend( mqd_t, const char*, size_t, unsigned, const timespec* );
    __QOR_INTERFACE( __CQOR ) int mq_unlink( const char* );

__QCMP_ENDLINKAGE_C

#endif//QOR_MQUEUE_H_3
