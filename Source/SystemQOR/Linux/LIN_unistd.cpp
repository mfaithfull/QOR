//LIN_unistd.cpp

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

#include "SystemQOR.h"

#if		(QOR_SYS_OS == QOR_SYS_LINUX)

#include "SystemQOR/Linux/LIN_unistd.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <termios.h>
#include <signal.h>
#include <string.h>
#include <sys/uio.h>
#include "SystemQOR/Linux/sys/LIN_ioctl.h"
#include <sys/resource.h>
#include <sys/utsname.h>
#include "LinQSys/syscall.h"
#include "LinQSys/libc.h"
#include "LinQSys/pthread_impl.h"
#include "SystemQOR/Linux/types/sys/wait_types.h"

//--------------------------------------------------------------------------------
namespace nsLinux
{
    void __procfdname( char*, unsigned );

    //--------------------------------------------------------------------------------
    const int Cunistd::errors[] =
    {
        0, -EACCES, -ELOOP, -ENAMETOOLONG, -ENOENT, -ENOTDIR,
        -EROFS, -EBADF, -EINVAL, -ETXTBSY, -EFAULT, -EIO, -ENOMEM,
        -EBUSY
    };


    //--------------------------------------------------------------------------------
    _Noreturn void Cunistd::_exit( int status )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::_exit" );
        _Exit(status);
    }

    //--------------------------------------------------------------------------------
    int Cunistd::access( const char* filename, int amode )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::access" );
#ifdef SYS_access
        return syscall( SYS_access, filename, amode );
#else
        return syscall( SYS_faccessat, AT_FDCWD, filename, amode, 0 );
#endif
    }

#ifdef _GNU_SOURCE

    //--------------------------------------------------------------------------------
    int Cunistd::acct( const char* filename )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::acct" );
        return syscall( SYS_acct, filename );
    }

#endif//_GNU_SOURCE

    //--------------------------------------------------------------------------------
    unsigned Cunistd::alarm( unsigned seconds )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::alarm" );
        itimerval it = { .it_value.tv_sec = seconds };
        __syscall( SYS_setitimer, ITIMER_REAL, &it, &it );
        return it.it_value.tv_sec + !!it.it_value.tv_usec;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::chdir( const char* path )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::chdir" );
        return syscall( SYS_chdir, path );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::chown( const char* path, uid_t uid, gid_t gid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::chown" );
#ifdef SYS_chown
        return syscall( SYS_chown, path, uid, gid );
#else
        return syscall( SYS_fchownat, AT_FDCWD, path, uid, gid, 0 );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::close( int fd )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::close" );
        int r = __syscall_cp( SYS_close, fd );
        if( r == -EINTR )
        {
            r = -EINPROGRESS;
        }
        return __syscall_ret( r );
    }

    //--------------------------------------------------------------------------------
    char* Cunistd::ctermid( char* s )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::ctermid" );
        return s ? strcpy(s, "/dev/tty") : (char*)"/dev/tty";
    }

    //--------------------------------------------------------------------------------
    int Cunistd::dup( int fd )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::dup" );
        return syscall( SYS_dup, fd );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::dup2( int old, int pnew )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::dup2" );
        int r;
#ifdef SYS_dup2
        while( ( r = __syscall( SYS_dup2, old, pnew ) ) == -EBUSY );
#else
        if( old == pnew )
        {
            r = __syscall( SYS_fcntl, old, F_GETFD );
            if( r >= 0 )
            {
                return old;
            }
        }
        else
        {
            while( ( r = __syscall( SYS_dup3, old, pnew, 0 ) ) == -EBUSY );
        }
#endif
        return __syscall_ret( r );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::__dup3( int old, int pnew, int flags )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::__dup3" );
        int r;
#ifdef SYS_dup2
        if( old == pnew )
        {
            return __syscall_ret(-EINVAL);
        }

        if( flags & O_CLOEXEC )
        {
            while( ( r = __syscall( SYS_dup3, old, pnew, flags ) ) == -EBUSY );
            if( r != -ENOSYS )
            {
                return __syscall_ret( r );
            }
        }

        while( ( r = __syscall( SYS_dup2, old, pnew ) ) == -EBUSY );

        if( flags & O_CLOEXEC )
        {
            __syscall( SYS_fcntl, pnew, F_SETFD, FD_CLOEXEC );
        }
#else
        while( ( r = __syscall( SYS_dup3, old, pnew, flags ) ) == -EBUSY );

#endif
        return __syscall_ret( r );
    }

    //--------------------------------------------------------------------------------
    int checker(void *p)
    {
 		//__QCS_MEMBER_FCONTEXT( "Cunistd::checker" );
        Cunistd::ctx2* c = reinterpret_cast< Cunistd::ctx2* >( p );
        int ret;
        int i;
        if( __syscall(SYS_setregid, __syscall(SYS_getegid), -1) || __syscall(SYS_setreuid, __syscall(SYS_geteuid), -1) )
        {
            __syscall(SYS_exit, 1);
        }
        ret = __syscall( SYS_faccessat, c->fd, c->filename, c->amode, 0 );
        for( i = 0; i < sizeof Cunistd::errors / sizeof * Cunistd::errors - 1 && ret != Cunistd::errors[ i ]; i++ );
        return i;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::faccessat( int fd, const char* filename, int amode, int flag )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::faccessat" );
        if( !flag || ( flag == AT_EACCESS && getuid() == geteuid() && getgid() == getegid() ) )
        {
            return syscall( SYS_faccessat, fd, filename, amode, flag );
        }

        if( flag != AT_EACCESS )
        {
            return __syscall_ret(-EINVAL);
        }

        char stack[ 1024 ];
        sigset_t set;
        pid_t pid;
        int ret = -EBUSY;
        ctx2 c = { .fd = fd, .filename = filename, .amode = amode };

        __block_all_sigs( &set );

        pid = __clone( &checker, stack + sizeof stack, 0, &c );
        if( pid > 0 )
        {
            int status;
            do
            {
                __syscall( SYS_wait4, pid, &status, __WCLONE, 0 );
            } while( !WIFEXITED( status ) && !WIFSIGNALED( status ) );

            if( WIFEXITED( status ) )
            {
                ret = errors[ WEXITSTATUS( status ) ];
            }
        }

        __restore_sigs( &set );

        return __syscall_ret( ret );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::fchdir( int fd )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::fchdir" );
        int ret = __syscall( SYS_fchdir, fd );
        if( ret != -EBADF || __syscall( SYS_fcntl, fd, F_GETFD ) < 0 )
        {
            return __syscall_ret( ret );
        }

        char buf[ 15 + 3 * sizeof( int ) ];
        __procfdname( buf, fd );
        return syscall( SYS_chdir, buf );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::fchown( int fd, uid_t uid, gid_t gid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::fchown" );
        int ret = __syscall( SYS_fchown, fd, uid, gid );
        if( ret != -EBADF || __syscall( SYS_fcntl, fd, F_GETFD ) < 0 )
        {
            return __syscall_ret( ret );
        }

        char buf[ 15 + 3 * sizeof( int ) ];
        __procfdname( buf, fd );
#ifdef SYS_chown
        return syscall( SYS_chown, buf, uid, gid );
#else
        return syscall( SYS_fchownat, AT_FDCWD, buf, uid, gid );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::fchownat( int fd, const char* path, uid_t uid, gid_t gid, int flag )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::fchownat" );
        return syscall( SYS_fchownat, fd, path, uid, gid, flag );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::fdatasync( int fd )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::fdatasync" );
        return syscall( SYS_fdatasync, fd );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::fsync( int fd )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::fsync" );
        return syscall( SYS_fsync, fd );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::ftruncate( int fd, off_t length )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::ftruncate" );
        return syscall( SYS_ftruncate, fd, __SYSCALL_LL_O(length) );
        //return __syscall4( SYS_ftruncate, fd, __SYSCALL_LL_O(length) );
    }

    //LFS64(ftruncate);

    //--------------------------------------------------------------------------------
    char* Cunistd::getcwd( char* buf, size_t size )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getcwd" );
        char tmp[ PATH_MAX ];
        if( !buf )
        {
            buf = tmp;
            size = PATH_MAX;
        }
        else if( !size )
        {
            errno = EINVAL;
            return 0;
        }
        if( syscall( SYS_getcwd, buf, size ) < 0 )
        {
            return 0;
        }
        return buf == tmp ? strdup( buf ) : buf;
    }

    //--------------------------------------------------------------------------------
    gid_t Cunistd::getegid(void)
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getegid" );
        return __syscall( SYS_getegid );
    }

    //--------------------------------------------------------------------------------
    uid_t Cunistd::geteuid( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::geteuid" );
        return __syscall( SYS_geteuid );
    }

    //--------------------------------------------------------------------------------
    gid_t Cunistd::getgid( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getgid" );
        return __syscall( SYS_getgid );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::getgroups( int count, gid_t list[] )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getgroups" );
        return syscall( SYS_getgroups, count, list );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::gethostname( char* name, size_t len )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::gethostname" );
        size_t i;
        utsname uts;
        if( uname( &uts ) )
        {
            return -1;
        }
        if( len > sizeof uts.nodename )
        {
            len = sizeof uts.nodename;
        }
        for( i = 0; i < len && ( name[ i ] = uts.nodename[ i ] ); i++ );

        if( i == len )
        {
            name[ i - 1 ] = 0;
        }
        return 0;
    }

    //--------------------------------------------------------------------------------
    char* Cunistd::getlogin( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getlogin" );
        return getenv( "LOGNAME" );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::getlogin_r( char* name, size_t size )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getlogin_r" );
        char* logname = getlogin();
        if( !logname )
        {
            return ENXIO; /* or...? */
        }
        if( strlen( logname ) >= size )
        {
            return ERANGE;
        }
        strcpy( name, logname );
        return 0;
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::getpgid( pid_t pid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getpgid" );
        return syscall( SYS_getpgid, pid );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::getpgrp( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getpgrp" );
        return __syscall( SYS_getpgid, 0 );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::getpid(void)
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getpid" );
        return __syscall( SYS_getpid );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::getppid( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getppid" );
        return __syscall( SYS_getppid );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::getsid( pid_t pid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getsid" );
        return syscall( SYS_getsid, pid );
    }

    //--------------------------------------------------------------------------------
    uid_t Cunistd::getuid( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::getuid" );
        return __syscall( SYS_getuid );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::isatty( int fd )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::isatty" );
        termios t;
        return tcgetattr( fd, &t ) == 0;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::lchown( const char* path, uid_t uid, gid_t gid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::lchown" );
#ifdef SYS_lchown
        return syscall( SYS_lchown, path, uid, gid );
#else
        return syscall( SYS_fchownat, AT_FDCWD, path, uid, gid, AT_SYMLINK_NOFOLLOW );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::link( const char* existing, const char* pnew )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::link" );
#ifdef SYS_link
        return syscall( SYS_link, existing, pnew );
#else
        return syscall( SYS_linkat, AT_FDCWD, existing, AT_FDCWD, pnew, 0 );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::linkat( int fd1, const char* existing, int fd2, const char* pnew, int flag )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::linkat" );
        return syscall( SYS_linkat, fd1, existing, fd2, pnew, flag );
    }

    //--------------------------------------------------------------------------------
    off_t Cunistd::lseek( int fd, off_t offset, int whence )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::lseek" );
#ifdef SYS__llseek
        off_t result;
        return syscall( SYS__llseek, fd, offset >> 32, offset, &result, whence ) ? -1 : result;
#else
        return syscall( SYS_lseek, fd, offset, whence );
#endif
    }

    //LFS64(lseek);

    //--------------------------------------------------------------------------------
    int Cunistd::nice( int inc )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::nice" );
#ifdef SYS_nice
        return syscall( SYS_nice, inc );
#else
        return setpriority( PRIO_PROCESS, 0, getpriority( PRIO_PROCESS, 0 ) + inc );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::pause( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::pause" );
#ifdef SYS_pause
        return syscall_cp( SYS_pause );
#else
        return syscall_cp( SYS_ppoll, 0, 0, 0, 0 );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::pipe( int fd[ 2 ] )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::pipe" );

#ifdef SYS_pipe
        return syscall( SYS_pipe, fd );
#else
        return syscall( SYS_pipe2, fd, 0 );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::pipe2( int fd[ 2 ], int flag )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::pipe2" );
        if( !flag )
        {
            return pipe( fd );
        }

        int ret = __syscall( SYS_pipe2, fd, flag );
        if( ret != -ENOSYS )
        {
            return __syscall_ret( ret );
        }

        ret = pipe( fd );
        if( ret )
        {
            return ret;
        }

        if( flag & O_CLOEXEC )
        {
            __syscall( SYS_fcntl, fd[ 0 ], F_SETFD, FD_CLOEXEC );
            __syscall( SYS_fcntl, fd[ 1 ], F_SETFD, FD_CLOEXEC );
        }

        if( flag & O_NONBLOCK )
        {
            __syscall( SYS_fcntl, fd[ 0 ], F_SETFL, O_NONBLOCK );
            __syscall( SYS_fcntl, fd[ 1 ], F_SETFL, O_NONBLOCK );
        }
        return 0;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::posix_close( int fd, int flags )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::posix_close" );
        return close( fd );
    }

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::pread( int fd, void* buf, size_t size, off_t ofs )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::pread" );
        return syscall_cp( SYS_pread, fd, buf, size, __SYSCALL_LL_O( ofs ) );
    }

    //LFS64(pread);

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::pwrite( int fd, const void* buf, size_t size, off_t ofs )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::pwrite" );
        return syscall_cp( SYS_pwrite, fd, buf, size, __SYSCALL_LL_O( ofs ) );
    }

    //LFS64(pwrite);

#ifdef _BSD_SOURCE

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::preadv( int fd, const iovec* iov, int count, off_t ofs )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::preadv" );
        return syscall_cp( SYS_preadv, fd, iov, count, (long)(ofs), (long)( ofs >> 32 ) );
    }

    //LFS64(preadv);

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::pwritev( int fd, const iovec* iov, int count, off_t ofs )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::pwritev" );
        return syscall_cp( SYS_pwritev, fd, iov, count, (long)(ofs), (long)( ofs >> 32 ) );
    }

    //LFS64(pwritev);
#endif//_BSD_SOURCE

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::read( int fd, void* buf, size_t count )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::read" );
        return syscall_cp( SYS_read, fd, buf, count );
    }

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::readlink( const char* path, char* buf, size_t bufsize )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::readlink" );
#ifdef SYS_readlink
        return syscall( SYS_readlink, path, buf, bufsize );
#else
        return syscall( SYS_readlinkat, AT_FDCWD, path, buf, bufsize );
#endif
    }

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::readlinkat( int fd, const char* path, char* buf, size_t bufsize )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::readlinkat" );
        return syscall( SYS_readlinkat, fd, path, buf, bufsize );
    }

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::readv( int fd, const iovec* iov, int count )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::readv" );
        return syscall_cp( SYS_readv, fd, iov, count );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::renameat( int oldfd, const char* old, int newfd, const char* pnew )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::renameat" );
        return syscall( SYS_renameat, oldfd, old, newfd, pnew );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::rmdir( const char* path )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::rmdir" );
#ifdef SYS_rmdir
        return syscall( SYS_rmdir, path );
#else
        return syscall( SYS_unlinkat, AT_FDCWD, path, AT_REMOVEDIR );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::setegid( gid_t egid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setegid" );
        return __setxid( SYS_setresgid, -1, egid, -1 );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::seteuid( uid_t euid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::seteuid" );
        return __setxid( SYS_setresuid, -1, euid, -1 );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::setgid( gid_t gid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setgid" );
        return __setxid( SYS_setgid, gid, 0, 0 );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::setpgid( pid_t pid, pid_t pgid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setpgid" );
        return syscall( SYS_setpgid, pid, pgid );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::setpgrp( void )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setgrp" );
        return setpgid(0, 0);
    }

    //--------------------------------------------------------------------------------
    int Cunistd::setregid( gid_t rgid, gid_t egid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setregid" );
        return __setxid( SYS_setregid, rgid, egid, 0 );
    }

#ifdef _GNU_SOURCE

    //--------------------------------------------------------------------------------
    int Cunistd::setresgid( gid_t rgid, gid_t egid, gid_t sgid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setresgid" );
        return __setxid( SYS_setresgid, rgid, egid, sgid );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::setresuid( uid_t ruid, uid_t euid, uid_t suid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setresuid" );
        return __setxid( SYS_setresuid, ruid, euid, suid );
    }

#endif//_GNU_SOURCE

    //--------------------------------------------------------------------------------
    int Cunistd::setreuid( uid_t ruid, uid_t euid )
    {
 		__QCS_MEMBER_FCONTEXT( "Cunistd::setreuid" );
        return __setxid( SYS_setreuid, ruid, euid, 0 );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::setsid( void )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::setsid" );
        return syscall( SYS_setsid );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::setuid( uid_t uid )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::setuid" );
        return __setxid( SYS_setuid, uid, 0, 0 );
    }

    //--------------------------------------------------------------------------------
    void do_setxid( void* p )
    {
		//__QCS_MEMBER_FCONTEXT( "Cunistd::do_setxid" );

        Cunistd::ctx* c = reinterpret_cast< Cunistd::ctx* >( p );
        if( c->err > 0 )
        {
            return;
        }
        int ret = -__syscall(c->nr, c->id, c->eid, c->sid);
        if( ret && !c->err )
        {
            /* If one thread fails to set ids after another has already succeeded, forcibly killing the process is the only safe
             * thing to do. State is inconsistent and dangerous. Use SIGKILL because it is uncatchable. */
            __block_all_sigs( 0 );
            __syscall( SYS_kill, __syscall( SYS_getpid ), SIGKILL );
        }
        c->err = ret;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::__setxid( int nr, int id, int eid, int sid )
    {
        // err is initially nonzero so that failure of the first thread does not trigger the safety kill above.
		__QCS_MEMBER_FCONTEXT( "Cunistd::__setxid" );
        ctx c = { .nr = nr, .id = id, .eid = eid, .sid = sid, .err = -1 };
        __synccall(&do_setxid, &c);
        if( c.err )
        {
            errno = c.err;
            return -1;
        }
        return 0;
    }

    //--------------------------------------------------------------------------------
    unsigned Cunistd::sleep( unsigned seconds )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::sleep" );
        struct timespec tv = { .tv_sec = seconds, .tv_nsec = 0 };
        if( nanosleep( &tv, &tv ) )
        {
            return tv.tv_sec;
        }
        return 0;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::symlink( const char* existing, const char* pnew )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::symlink" );
#ifdef SYS_symlink
        return syscall( SYS_symlink, existing, pnew );
#else
        return syscall( SYS_symlinkat, existing, AT_FDCWD, pnew );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::symlinkat( const char* existing, int fd, const char* pnew )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::symlinkat" );
        return syscall( SYS_symlinkat, existing, fd, pnew );
    }

    //--------------------------------------------------------------------------------
    void Cunistd::sync( void )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::sync" );
        __syscall( SYS_sync );
    }

    //--------------------------------------------------------------------------------
    pid_t Cunistd::tcgetpgrp( int fd )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::tcgetprgrp" );
        int pgrp;
        if( ioctl( fd, TIOCGPGRP, &pgrp ) < 0 )
        {
            return -1;
        }
        return pgrp;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::tcsetpgrp( int fd, pid_t pgrp )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::tcsetpgrp" );
        int pgrp_int = pgrp;
        return ioctl( fd, TIOCSPGRP, &pgrp_int );
    }

    //--------------------------------------------------------------------------------
    int Cunistd::truncate( const char* path, off_t length )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::truncate" );
        return syscall( SYS_truncate, path, __SYSCALL_LL_O( length ) );
    }

    //LFS64(truncate);

    //--------------------------------------------------------------------------------
    char* Cunistd::ttyname( int fd )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::ttyname" );
        static char buf[ TTY_NAME_MAX ];
        int result;
        if( ( result = ttyname_r( fd, buf, sizeof buf ) ) )
        {
            errno = result;
            return NULL;
        }
        return buf;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::ttyname_r( int fd, char* name, size_t size )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::ttyname_r" );
        char procname[ sizeof "/proc/self/fd/" + 3 * sizeof( int ) + 2 ];
        ssize_t l;

        if( !isatty( fd ) )
        {
            return ENOTTY;
        }

        __procfdname( procname, fd );
        l = readlink( procname, name, size );

        if( l < 0 )
        {
            return errno;
        }
        else if( l == size )
        {
            return ERANGE;
        }
        else
        {
            name[l] = 0;
            return 0;
        }
    }

    //--------------------------------------------------------------------------------
    unsigned Cunistd::ualarm( unsigned value, unsigned interval )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::alarm" );
        struct itimerval it =
        {
            .it_interval.tv_usec = interval,
            .it_value.tv_usec = value
        };
        setitimer( ITIMER_REAL, &it, &it );
        return it.it_value.tv_sec * 1000000 + it.it_value.tv_usec;
    }

    //--------------------------------------------------------------------------------
    int Cunistd::unlink( const char* path )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::unlink" );
#ifdef SYS_unlink
        return syscall( SYS_unlink, path );
#else
        return syscall( SYS_unlinkat, AT_FDCWD, path, 0 );
#endif
    }

    //--------------------------------------------------------------------------------
    int Cunistd::unlinkat( int fd, const char* path, int flag )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::unlinkat" );
        return syscall( SYS_unlinkat, fd, path, flag );
    }

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
    //--------------------------------------------------------------------------------
    int Cunistd::usleep( unsigned useconds )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::usleep" );
        timespec tv =
        {
            .tv_sec = useconds/1000000,
            .tv_nsec = (useconds%1000000)*1000
        };
        return nanosleep( &tv, &tv );
    }
#endif//defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::write( int fd, const void* buf, size_t count )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::write" );
        return syscall_cp( SYS_write, fd, buf, count );
    }

    //--------------------------------------------------------------------------------
    ssize_t Cunistd::writev( int fd, const iovec* iov, int count )
    {
		__QCS_MEMBER_FCONTEXT( "Cunistd::writev" );
        return syscall_cp( SYS_writev, fd, iov, count );
    }

}//nsLinux

#endif//(QOR_SYS_OS == QOR_SYS_LINUX)
