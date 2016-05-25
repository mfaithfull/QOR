//msg.h

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

#ifndef QOR_SYS_MSG_H_3
#define QOR_SYS_MSG_H_3

#include <sys/ipc.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMSYSTYPES(msg)


typedef nsPlatform::msgqnum_t msgqnum_t;
typedef nsPlatform::msglen_t msglen_t;

//the following symbolic constant as a message operation flag:
#define MSG_NOERROR					( nsPlatform::MsgNoError )				//No error if big message. 

typedef nsPlatform::msqid_ds msqid_ds;
typedef nsPlatform::key_t key_t;
typedef nsPlatform::pid_t pid_t;
typedef nsPlatform::ssize_t ssize_t;
typedef nsPlatform::time_t time_t;

__QCMP_STARTLINKAGE_C

    __QOR_INTERFACE( __CQOR ) int msgctl( int, int, ::msqid_ds* );
    __QOR_INTERFACE( __CQOR ) int msgget( ::key_t, int );
    __QOR_INTERFACE( __CQOR ) ::ssize_t msgrcv( int, void*, size_t, long, int );
    __QOR_INTERFACE( __CQOR ) int msgsnd( int, const void*, size_t, int );

__QCMP_ENDLINKAGE_C

#endif //QOR_SYS_MSG_H_3

