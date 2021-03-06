//MSW_unistd.h

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

//MSWindows overrides for unistd

#ifndef SYSTEMQOR_MSW_UNISTD_H_3
#define SYSTEMQOR_MSW_UNISTD_H_3

#include "SystemQOR/Posix/Baseunistd.h"
#include "PosumQOR/MSWindows/WinProcess.h"
#include "PosumQOR/MSWindows/WinMemoryManager.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Cunistd : public nsBaseCRT::Cunistd
	{
	public:

		Cunistd();
		virtual ~Cunistd();

        virtual int access( const char*, int );
        virtual unsigned alarm( unsigned );
        virtual int chdir( const char* );
        virtual int chown( const char*, uid_t, gid_t );
        virtual int close( int );
        virtual size_t confstr( int, char*, size_t );

        //[XSI]
        virtual char* crypt( const char*, const char* );
        virtual char* ctermid( char* );

        virtual int dup( int );

        virtual int dup2( int, int );
        //[XSI]
        virtual void encrypt( char[64], int );

        virtual int execl( const char*, const char*, ... );
        virtual int execle( const char*, const char*, ... );
        virtual int execlp( const char*, const char*, ... );
        virtual int execv( const char*, char* const[] );
        virtual int execve( const char*, char* const[], char* const[] );
        virtual int execvp( const char*, char* const[] );
        virtual void _exit( int );
        virtual int fchown( int, uid_t, gid_t );
        //[XSI]
        virtual int fchdir( int );

        //[SIO]
        virtual int fdatasync( int );

        virtual pid_t fork( void );
        virtual long fpathconf( int, int );
        //[FSC]
        virtual int fsync( int );

        virtual int ftruncate( int, off_t );
        virtual char* getcwd( char*, size_t );
        virtual gid_t getegid( void );
        virtual uid_t geteuid( void );
        virtual gid_t getgid( void );
        virtual int getgroups( int, gid_t[] );
        //[XSI]
        virtual long gethostid( void );

        virtual int gethostname( char*, size_t );
        virtual char* getlogin( void );
        virtual int getlogin_r( char*, size_t );
        virtual int getopt( int, char* const[], const char* );
        //[XSI]
        virtual pid_t getpgid( pid_t );

        virtual pid_t getpgrp( void );
        virtual pid_t getpid( void );
        virtual pid_t getppid( void );
        //[XSI]
        virtual pid_t getsid( pid_t );

        virtual uid_t getuid( void );
        //[XSI]
        virtual char* getwd( char* );// (LEGACY )

        virtual int isatty( int );
        //[XSI]
        virtual int lchown( const char*, uid_t, gid_t );

        virtual int link( const char* , const char* );
        //[XSI]
        virtual int lockf( int, int, off_t );

        virtual off_t lseek( int, off_t, int );
        //[XSI]
        virtual int nice( int );

        virtual long pathconf( const char*, int );
        virtual int pause( void );
        virtual int pipe( int[ 2 ] );
        //[XSI]
        virtual ssize_t pread( int, void*, size_t, off_t );
        virtual ssize_t pwrite( int, const void*, size_t, off_t );

        virtual ssize_t read( int, void*, size_t );
        virtual ssize_t readlink( const char* __QCMP_RESTRICT, char* __QCMP_RESTRICT, size_t );
        virtual int rmdir( const char* );
        virtual int setegid( gid_t );
        virtual int seteuid( uid_t );
        virtual int setgid( gid_t );


        virtual int setpgid( pid_t, pid_t );
        //[XSI]
        virtual pid_t setpgrp( void );
        virtual int setregid( gid_t, gid_t );
        virtual int setreuid( uid_t, uid_t );

        virtual pid_t setsid( void );
        virtual int setuid( uid_t );
        virtual unsigned sleep( unsigned );
        //[XSI]
        virtual void swab( const void* __QCMP_RESTRICT, void* __QCMP_RESTRICT, ssize_t );

        virtual int symlink( const char*, const char* );
        //[XSI]
        virtual void sync( void );

        virtual long sysconf( int );
        virtual pid_t tcgetpgrp( int );
        virtual int tcsetpgrp( int, pid_t );
        //[XSI]
        virtual int truncate( const char*, off_t );

        virtual char* ttyname( int );
        virtual int ttyname_r( int, char*, size_t );
        //[XSI]
        virtual useconds_t ualarm( useconds_t, useconds_t );

        virtual int unlink( const char* );
        virtual int usleep( useconds_t );
        virtual pid_t vfork( void );
        virtual ssize_t write( int, const void*, size_t );

		//extensions for UNIX compatibility

		virtual void* sbrk( intptr_t delta );

	private:

		Cunistd( const Cunistd& );
		Cunistd& operator = ( const Cunistd& );

		nsWinPosum::CProcess m_Process;
		nsWinPosum::CMemoryManager m_MemoryManager;
	};

}//nsWin32


#endif//SYSTEMQOR_MSW_UNISTD_H_3
