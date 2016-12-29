//Basestdio.cpp

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

#include "SystemQOR/Posix/Basestdio.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID( Cstdio );

	//--------------------------------------------------------------------------------
	Cstdio::Cstdio()
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::Cstdio" );
	}

	//--------------------------------------------------------------------------------
	Cstdio::~Cstdio()
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::~Cstdio" );
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::_stdin( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::_stdin" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::_stdout( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::_stdout" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::_stderr( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::_stderr" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    void Cstdio::clearerr( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::clearerr" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
    errno_t Cstdio::clearerr_s( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::clearerr_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    char* Cstdio::ctermid( char* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::ctermid" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdio::dprintf( int fd, const char* format, va_list args )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::dprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fclose( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fclose" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::fdopen( int, const char* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fdopen" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::feof( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::feof" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::ferror( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::ferror" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fflush( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fflush" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fgetc( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fgetc" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fgetpos( FILE* stream, fpos_t* pos )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fgetpos" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    char* Cstdio::fgets( char* s, int n, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fgets" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fileno( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fileno" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    void Cstdio::flockfile( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::flockfile" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
	FILE* Cstdio::fmemopen( void* buf, size_t size, const char* szMode )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fmemopen" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::fopen( const char* filename, const char* mode )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fopen" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    errno_t Cstdio::fopen_s( FILE** ppFile, const char* szFilename, const char* szMode )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fopen_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fprintf( FILE* stream, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fprintf_s( FILE* stream, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fprintf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fputc( int c, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fputc" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fputs( const char* s, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fputs" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    size_t Cstdio::fread( void* ptr, size_t size, size_t nmemb, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fread" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    size_t Cstdio::fread_s( void* ptr, size_t DstSize, size_t ElementSize, size_t Count, FILE* pFile )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fread_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::freopen( const char* filename, const char* mode, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::freopen" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    errno_t Cstdio::freopen_s( FILE** ppFile, const char* szFilename, const char* szMode, FILE* pOldFile )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::freopen_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fscanf( FILE* stream, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fscanf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fscanf_s( FILE* pFile, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fscanf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fseek( FILE* stream, long int offset, int whence )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fseek" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fseeko( FILE*, off_t, int )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fseeko" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::fsetpos( FILE* stream, const fpos_t* pos )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fsetpos" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    long int Cstdio::ftell( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::ftell" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    off_t Cstdio::ftello( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::ftello" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::ftrylockfile( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::ftrylockfile" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    void Cstdio::funlockfile( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::funlockfile" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
    size_t Cstdio::fwrite( const void* ptr, size_t size, size_t nmemb, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::fwrite" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::getc( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::getc" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::getchar( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::getchar" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::getc_unlocked( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::getc_unlocked" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::getchar_unlocked( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::getchar_unlocked" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Cstdio::getdelim( char** lineptr, size_t* n, int delimiter, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::getdelim" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Cstdio::getline( char** lineptr, size_t* n, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::getline" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    char* Cstdio::gets( char* s )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::gets" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    char* Cstdio::gets_s( char* s, size_t _Size )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::gets_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	FILE* Cstdio::open_memstream( char** bufp, size_t* sizep )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::open_memstream" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::pclose( FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::pclose" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    void Cstdio::perror( const char* s )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::perror" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::popen( const char*, const char* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::popen" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::printf( const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::printf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::printf_s( const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::printf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::putc( int c, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::putc" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::putchar( int c )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::putchar" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::putc_unlocked( int, FILE* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::putc_unlocked" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::putchar_unlocked( int )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::putchar_unlocked" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::puts( const char* s )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::puts" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::remove( const char* filename )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::remove" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::rename( const char* old, const char* pnew )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::rename" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdio::renameat( int ofd, const char* szOld, int newfd, const char* szNew )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::renameat" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    void Cstdio::rewind( FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::rewind" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::scanf( const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::scanf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::scanf_s( const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::scanf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    void Cstdio::setbuf( FILE* stream, char* buf )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::setbuf" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::setvbuf( FILE* stream, char* buf, int mode, size_t size )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::setvbuf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::snprintf( char* s, size_t n, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::snprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::sprintf( char* s, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::sprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::sprintf_s( char* s, size_t SizeInBytes, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::sprintf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::sscanf( const char* s, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::sscanf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::sscanf_s( const char* s, const char* format, va_list vargs )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::sscanf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    char* Cstdio::tempnam( const char*, const char* )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::tempnam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    FILE* Cstdio::tmpfile( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::tmpfile" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    errno_t Cstdio::tmpfile_s( FILE** ppFile )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::tmpfile_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    char* Cstdio::tmpnam( char* s )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::tmpnam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    errno_t Cstdio::tmpnam_s( char* s, size_t Size )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::tmpnam_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::ungetc( int c, FILE* stream )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::ungetc" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vfprintf( FILE* stream, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vfprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vfprintf_s( FILE* stream, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vfprintf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vfscanf( FILE* stream, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vfscanf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vprintf( const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vprintf_s( const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vprintf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vscanf( const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vscanf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vsnprintf( char* s, size_t n, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vsnprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vsprintf( char* s, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vsprintf" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vsprintf_s( char* s, size_t SizeInBytes, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vsprintf_s" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cstdio::vsscanf( const char* s, const char* format, va_list arg )
	{
		__QCS_MEMBER_FCONTEXT( "Cstdio::vsscanf" );
		errno = ENOSYS;
		return 0;
	}

}//nsBaseCRT