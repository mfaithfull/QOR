//semaphore.h

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

//POSIX semaphore interface

#ifndef QOR_SEMAPHORE_H_3
#define QOR_SEMAPHORE_H_3

#include <time.h>
#include <limits.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(semaphore)

typedef nsPlatform::sem_t sem_t;
typedef nsPlatform::_sem_t _sem_t;

__QCMP_STARTLINKAGE_C

    __QOR_INTERFACE( __CQOR ) int sem_close( ::sem_t* pSem );
    __QOR_INTERFACE( __CQOR ) int sem_destroy( ::sem_t* pSem );
    __QOR_INTERFACE( __CQOR ) int sem_getvalue( ::sem_t* __QCMP_RESTRICT pSem, int* __QCMP_RESTRICT piValue );
    __QOR_INTERFACE( __CQOR ) int sem_init( ::sem_t* pSem, int iPShared, unsigned uValue );
    __QOR_INTERFACE( __CQOR ) ::sem_t* sem_open( const char* szName, int iOFlags, ... );
    __QOR_INTERFACE( __CQOR ) int sem_post( ::sem_t* pSem );
    __QOR_INTERFACE( __CQOR ) int sem_timedwait( ::sem_t* __QCMP_RESTRICT pSem, const ::timespec* __QCMP_RESTRICT pAbs_Timeout );
    __QOR_INTERFACE( __CQOR ) int sem_trywait( ::sem_t* pSem );
    __QOR_INTERFACE( __CQOR ) int sem_unlink( const char* szName );
    __QOR_INTERFACE( __CQOR ) int sem_wait( ::sem_t* pSem );

//extensions

    __QOR_INTERFACE( __CQOR ) int sem_post_multiple( ::sem_t* sem, int count );

__QCMP_ENDLINKAGE_C

#endif//QOR_SEMAPHORE_H_3

