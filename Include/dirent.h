//dirent.h

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

#ifndef	QOR_DIRENT_H_3
#define QOR_DIRENT_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(dirent)		//Include platform specific types necessary to declare this interface

typedef nsPlatform::DIR DIR;
typedef nsPlatform::dirent dirent;
typedef nsPlatform::ino_t ino_t;
typedef nsPlatform::_diskfree_t _diskfree_t;

__QCMP_STARTLINKAGE_C

	__QOR_INTERFACE( __CQOR ) int alphasort( const dirent**, const dirent** );
	__QOR_INTERFACE( __CQOR ) int closedir( DIR* );
	__QOR_INTERFACE( __CQOR ) int dirfd( DIR* );
	__QOR_INTERFACE( __CQOR ) DIR* fdopendir( int );
	__QOR_INTERFACE( __CQOR ) DIR* opendir( const char* );
	__QOR_INTERFACE( __CQOR ) dirent* readdir( DIR* );
	__QOR_INTERFACE( __CQOR ) int readdir_r( DIR* __QCMP_RESTRICT, dirent* __QCMP_RESTRICT, dirent** __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) void rewinddir( DIR* );
	__QOR_INTERFACE( __CQOR ) int scandir( const char*, dirent***, int (*)( const dirent* ), int (*)( const dirent**, const dirent** ) );
	__QOR_INTERFACE( __CQOR ) void seekdir( DIR*, long );
	__QOR_INTERFACE( __CQOR ) long telldir( DIR* );
	__QOR_INTERFACE( __CQOR ) int _mkdir( const char* dirname );
	__QOR_INTERFACE( __CQOR ) unsigned long _getdrives( void );
	__QOR_INTERFACE( __CQOR ) int _getdrive( void );
	__QOR_INTERFACE( __CQOR ) unsigned _getdiskfree( unsigned drive, _diskfree_t* driveinfo );
	__QOR_INTERFACE( __CQOR ) int _chdir( const char* dirname );
	__QOR_INTERFACE( __CQOR ) int _chdrive( int drive );

__QCMP_ENDLINKAGE_C

#endif//QOR_DIRENT_H_3

