//Basedirent.h

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

//Base CRT class for Cdirent

#ifndef SYSTEMQOR_POSIX_DIRENT_H_3
#define SYSTEMQOR_POSIX_DIRENT_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(dirent)	//include the platform specific types necessary to declare this interface
#include "CodeQOR/DataTypes/GUID.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
    using nsPlatform::DIR;
    using nsPlatform::dirent;
	using nsPlatform::ino_t;

    //--------------------------------------------------------------------------------	
    class __QOR_INTERFACE( __QSYS ) Cdirent
    {
    public:

		__QOR_DECLARE_OCLASS_ID( Cdirent );

		virtual int alphasort( const dirent**, const dirent** );
        virtual int closedir( DIR* );
		virtual int dirfd( DIR* );
		virtual DIR* fdopendir( int );
        virtual DIR* opendir( const char* );
        virtual dirent* readdir( DIR* );
        virtual int readdir_r( DIR* __QCMP_RESTRICT, dirent* __QCMP_RESTRICT, dirent** __QCMP_RESTRICT );
        virtual void rewinddir( DIR* );
        virtual int scandir( const char*, dirent***, int (*)( const dirent* ), int (*)( const dirent**, const dirent** ) );
        virtual void seekdir( DIR*, long );
        virtual long telldir( DIR* );

	protected:

        Cdirent();
        virtual ~Cdirent();

	private:

		Cdirent( const Cdirent& );
		Cdirent& operator = ( const Cdirent& );
    };

}//nsBaseCRT

#endif//SYSTEMQOR_POSIX_DIRENT_H_3
