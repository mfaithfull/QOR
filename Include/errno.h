//errno.h

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

#ifndef QOR_ERRNO_H_1
#define QOR_ERRNO_H_1

#include "SystemQOR.h"

#ifdef errno
#	undef errno
#endif

#include QOR_SYS_PLATFORMTYPES(errno)

__QOR_INTERFACE( __CQOR ) int&		f_errno();
#define errno ( f_errno() )

#ifndef OS_EXPORTS_ERRNO__ERRNO
__QCMP_STARTLINKAGE_C
    //__QOR_INTERFACE( __CQOR ) int* _errno(void);
__QCMP_ENDLINKAGE_C
#endif

#define E2BIG			( nsBaseCRT::CCRTErrorDomain::CRT_E2BIG )//Argument list too long.
#define EACCESS			( nsBaseCRT::CCRTErrorDomain::CRT_EACCESS )//Permission denied.
#define EACCES			( nsBaseCRT::CCRTErrorDomain::CRT_EACCESS )//Permission denied.
#define EADDRINUSE		( nsBaseCRT::CCRTErrorDomain::CRT_EADDRINUSE )//Address in use.
#define EADDRNOTAVAIL	( nsBaseCRT::CCRTErrorDomain::CRT_EADDRNOTAVAIL )//Address not available.
#define EAFNOSUPPORT	( nsBaseCRT::CCRTErrorDomain::CRT_EAFNOSUPPORT )//Address family not supported.
#define EAGAIN			( nsBaseCRT::CCRTErrorDomain::CRT_EAGAIN )//Resource unavailable, try again (may be the same value as [EWOULDBLOCK]).
#define EALREADY		( nsBaseCRT::CCRTErrorDomain::CRT_EALREADY )//Connection already in progress.
#define EBADF			( nsBaseCRT::CCRTErrorDomain::CRT_EBADF )//Bad file descriptor.
#define EBADMSG			( nsBaseCRT::CCRTErrorDomain::CRT_EBADMSG )//Bad message.
#define EBUSY			( nsBaseCRT::CCRTErrorDomain::CRT_EBUSY )//Device or resource busy.
#define ECANCELED		( nsBaseCRT::CCRTErrorDomain::CRT_ECANCELED )//Operation canceled.
#define ECHILD			( nsBaseCRT::CCRTErrorDomain::CRT_ECHILD )//No child processes.
#define ECONNABORTED	( nsBaseCRT::CCRTErrorDomain::CRT_ECONNABORTED )//Connection aborted.
#define ECONNREFUSED	( nsBaseCRT::CCRTErrorDomain::CRT_ECONNREFUSED )//Connection refused.
#define ECONNRESET		( nsBaseCRT::CCRTErrorDomain::CRT_ECONNRESET )//Connection reset.
#define EDEADLK			( nsBaseCRT::CCRTErrorDomain::CRT_EDEADLK )//Resource deadlock would occur.
#define EDESTADDRREQ	( nsBaseCRT::CCRTErrorDomain::CRT_EDESTADDRREQ )//Destination address required.
#define EDOM			( nsBaseCRT::CCRTErrorDomain::CRT_EDOM )//Mathematics argument out of domain of function.
#define EDQUOT			( nsBaseCRT::CCRTErrorDomain::CRT_EDQUOT )//Reserved.
#define EEXIST			( nsBaseCRT::CCRTErrorDomain::CRT_EEXIST )//File exists.
#define EFAULT			( nsBaseCRT::CCRTErrorDomain::CRT_EFAULT )//Bad address.
#define EFBIG			( nsBaseCRT::CCRTErrorDomain::CRT_EFBIG )//File too large.
#define EHOSTUNREACH	( nsBaseCRT::CCRTErrorDomain::CRT_EHOSTUNREACH )//Host is unreachable.
#define	EIDRM			( nsBaseCRT::CCRTErrorDomain::CRT_EIDRM )//Identifier removed.
#define	EILSEQ			( nsBaseCRT::CCRTErrorDomain::CRT_EILSEQ )//Illegal byte sequence.
#define	EINPROGRESS		( nsBaseCRT::CCRTErrorDomain::CRT_EINPROGRESS )//Operation in progress.
#define	EINTR			( nsBaseCRT::CCRTErrorDomain::CRT_EINTR )//Interrupted function.
#define	EINVAL			( nsBaseCRT::CCRTErrorDomain::CRT_EINVAL )//Invalid argument.
#define	EIO				( nsBaseCRT::CCRTErrorDomain::CRT_EIO )//I/O error.
#define	EISCONN			( nsBaseCRT::CCRTErrorDomain::CRT_EISCONN )//Socket is connected.
#define	EISDIR			( nsBaseCRT::CCRTErrorDomain::CRT_EISDIR )//Is a directory.
#define	ELOOP			( nsBaseCRT::CCRTErrorDomain::CRT_ELOOP )//Too many levels of symbolic links.
#define	EMFILE			( nsBaseCRT::CCRTErrorDomain::CRT_EMFILE )//Too many open files.
#define	EMLINK			( nsBaseCRT::CCRTErrorDomain::CRT_EMLINK )//Too many links.
#define	EMSGSIZE		( nsBaseCRT::CCRTErrorDomain::CRT_EMSGSIZE )//Message too large.
#define	EMULTIHOP		( nsBaseCRT::CCRTErrorDomain::CRT_EMULTIHOP )//Reserved
#define	ENAMETOOLONG	( nsBaseCRT::CCRTErrorDomain::CRT_ENAMETOOLONG )//Filename too long.
#define	ENETDOWN		( nsBaseCRT::CCRTErrorDomain::CRT_ENETDOWN )//Network is down.
#define	ENETRESET		( nsBaseCRT::CCRTErrorDomain::CRT_ENETRESET )//Connection aborted by network.
#define	ENETUNREACH		( nsBaseCRT::CCRTErrorDomain::CRT_ENETUNREACH )//Network unreachable.
#define	ENFILE			( nsBaseCRT::CCRTErrorDomain::CRT_ENFILE )//Too many files open in system.
#define	ENOBUFS			( nsBaseCRT::CCRTErrorDomain::CRT_ENOBUFS )//No buffer space available.
#define	ENODATA			( nsBaseCRT::CCRTErrorDomain::CRT_ENODATA )//[XSR]  No message is available on the STREAM head read queue.
#define	ENODEV			( nsBaseCRT::CCRTErrorDomain::CRT_ENODEV )//No such device.
#define	ENOENT			( nsBaseCRT::CCRTErrorDomain::CRT_ENOENT )//No such file or directory.
#define	ENOEXEC			( nsBaseCRT::CCRTErrorDomain::CRT_ENOEXEC )//Executable file format error.
#define	ENOLCK			( nsBaseCRT::CCRTErrorDomain::CRT_ENOLCK )//No locks available.
#define	ENOLINK			( nsBaseCRT::CCRTErrorDomain::CRT_ENOLINK )//Reserved.
#define	ENOMEM			( nsBaseCRT::CCRTErrorDomain::CRT_ENOMEM )//Not enough space.
#define	ENOMSG			( nsBaseCRT::CCRTErrorDomain::CRT_ENOMSG )//No message of the desired type.
#define	ENOPROTOOPT		( nsBaseCRT::CCRTErrorDomain::CRT_ENOPROTOOPT )//Protocol not available.
#define	ENOSPC			( nsBaseCRT::CCRTErrorDomain::CRT_ENOSPC )//No space left on device.
#define	ENOSR			( nsBaseCRT::CCRTErrorDomain::CRT_ENOSR )//[XSR]  No STREAM resources.
#define	ENOSTR			( nsBaseCRT::CCRTErrorDomain::CRT_ENOSTR )//[XSR]  Not a STREAM.
#define	ENOSYS			( nsBaseCRT::CCRTErrorDomain::CRT_ENOSYS )//Function not supported.
#define	ENOTCONN		( nsBaseCRT::CCRTErrorDomain::CRT_ENOTCONN )//The socket is not connected.
#define	ENOTDIR			( nsBaseCRT::CCRTErrorDomain::CRT_ENOTDIR )//Not a directory.
#define	ENOTEMPTY		( nsBaseCRT::CCRTErrorDomain::CRT_ENOTEMPTY )//Directory not empty.
#define	ENOTSOCK		( nsBaseCRT::CCRTErrorDomain::CRT_ENOTSOCK )//Not a socket.
#define	ENOTSUP			( nsBaseCRT::CCRTErrorDomain::CRT_ENOTSUP )//Not supported.
#define	ENOTTY			( nsBaseCRT::CCRTErrorDomain::CRT_ENOTTY )//Inappropriate I/O control operation.
#define	ENXIO			( nsBaseCRT::CCRTErrorDomain::CRT_ENXIO )//No such device or address.
#define	EOPNOTSUPP		( nsBaseCRT::CCRTErrorDomain::CRT_EOPNOTSUPP )//Operation not supported on socket.
#define	EOVERFLOW		( nsBaseCRT::CCRTErrorDomain::CRT_EOVERFLOW )//Value too large to be stored in data type.
#define	EPERM			( nsBaseCRT::CCRTErrorDomain::CRT_EPERM )//Operation not permitted.
#define	EPIPE			( nsBaseCRT::CCRTErrorDomain::CRT_EPIPE )//Broken pipe.
#define	EPROTO			( nsBaseCRT::CCRTErrorDomain::CRT_EPROTO )//Protocol error.
#define	EPROTONOSUPPORT	( nsBaseCRT::CCRTErrorDomain::CRT_EPROTONOSUPPORT )//Protocol not supported.
#define	EPROTOTYPE		( nsBaseCRT::CCRTErrorDomain::CRT_EPROTOTYPE )//Protocol wrong type for socket.
#define ERANGE			( nsBaseCRT::CCRTErrorDomain::CRT_ERANGE )//Result too large.
#define	EROFS			( nsBaseCRT::CCRTErrorDomain::CRT_EROFS )//Read-only file system.
#define	ESPIPE			( nsBaseCRT::CCRTErrorDomain::CRT_ESPIPE )//Invalid seek.
#define	ESRCH			( nsBaseCRT::CCRTErrorDomain::CRT_ESRCH )//No such process.
#define ESTALE			( nsBaseCRT::CCRTErrorDomain::CRT_ESTALE )//Reserved.
#define	ETIME			( nsBaseCRT::CCRTErrorDomain::CRT_ETIME )//[XSR]  Stream ioctl() timeout.
#define	ETIMEDOUT		( nsBaseCRT::CCRTErrorDomain::CRT_ETIMEDOUT )//Connection timed out.
#define	ETXTBSY			( nsBaseCRT::CCRTErrorDomain::CRT_ETXTBSY )//Text file busy.
#define	EWOULDBLOCK		( nsBaseCRT::CCRTErrorDomain::CRT_EWOULDBLOCK )//Operation would block (may be the same value as [EAGAIN]).
#define	EXDEV			( nsBaseCRT::CCRTErrorDomain::CRT_EXDEV )//Cross-device link.
#define ENOTRECOVERABLE	( nsBaseCRT::CCRTErrorDomain::CRT_ENOTRECOVERABLE )//State not recoverable.
#define EOWNERDEAD		( nsBaseCRT::CCRTErrorDomain::CRT_EOWNERDEAD )//Previous owner died.

#include "SystemQOR/Posix/Baseerrno.h"

#endif //QOR_ERRNO_H_1

