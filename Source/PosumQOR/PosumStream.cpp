//PosumStream.cpp

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

#include "PosumQOR.h"
#include "SystemQOR.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "PosumQOR/PosumStream.h"
#include <stdarg.h>

#include QOR_SYS_POSUMHEADER(PosumStream) //e.g WinPosum/WinPosumStream.h

//--------------------------------------------------------------------------------
namespace nsPosum
{
	//--------------------------------------------------------------------------------
	CStream::CStream( int nFD ) : m_pFILE( nsPlatform::CPosumStreamAccessor::Stream( nFD ) )
	{		
		__QCS_FCONTEXT( "CStream::CStream" );
	}

	//--------------------------------------------------------------------------------
	CStream::CStream( FILE* pFILE ) : m_pFILE( pFILE )
	{
		__QCS_FCONTEXT( "CStream::CStream" );
	}

	//--------------------------------------------------------------------------------
	CStream::~CStream()
	{
		__QCS_FCONTEXT( "CStream::~CStream" );
	}

	//--------------------------------------------------------------------------------
	CStream& CStream::operator = ( const CStream& src )
	{
		__QCS_FCONTEXT( "CStream::operator =" );
		if( &src != this )
		{
			m_pFILE = src.m_pFILE;
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	FILE* CStream::GetFILE( void )
	{
		__QCS_FCONTEXT( "CStream::GetFILE" );
		return m_pFILE;
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_stdin( void )
	{
		__QCS_FCONTEXT( "CStream::_stdin" );
		return nsPlatform::CPosumStreamAccessor::_stdin();
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_stdout( void )
	{
		__QCS_FCONTEXT( "CStream::_stdout" );
		return nsPlatform::CPosumStreamAccessor::_stdout();
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_stderr( void )
	{
		__QCS_FCONTEXT( "CStream::_stderr" );
		return nsPlatform::CPosumStreamAccessor::_stderr();
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::fopen( const char* __QCMP_RESTRICT filename, const char* __QCMP_RESTRICT mode )
	{
		__QCS_FCONTEXT( "CStream::fopen" );
		return nsPlatform::CPosumStreamAccessor::fopen( filename, mode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::fdopen( int fd, const char* mode )
	{
		__QCS_FCONTEXT( "CStream::fdopen" );
		return nsPlatform::CPosumStreamAccessor::fdopen( fd, mode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_fdopen( int fd, const char* mode )
	{
		__QCS_FCONTEXT( "CStream::_fdopen" );
		return nsPlatform::CPosumStreamAccessor::fdopen( fd, mode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::fmemopen( void* __QCMP_RESTRICT p1, size_t s1, const char * __QCMP_RESTRICT sz )
	{
		__QCS_FCONTEXT( "CStream::fmemopen" );
		return nsPlatform::CPosumStreamAccessor::fmemopen( p1, s1, sz );
	}

	//--------------------------------------------------------------------------------
	errno_t CStream::fopen_s( CStream::refType& ppFile, const char* szFilename, const char* szMode )
	{
		__QCS_FCONTEXT( "CStream::fopen_s" );
		return nsPlatform::CPosumStreamAccessor::fopen_s( ppFile, szFilename, szMode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::freopen( const char* __QCMP_RESTRICT filename, const char* __QCMP_RESTRICT mode )
	{
		__QCS_FCONTEXT( "CStream::freopen" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.freopen( filename, mode );
	}

	//--------------------------------------------------------------------------------
	errno_t CStream::freopen_s( CStream::refType& ppFile, const char* szFilename, const char* szMode )
	{
		__QCS_FCONTEXT( "CStream::freopen_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.freopen_s( ppFile, szFilename, szMode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::open_memstream( char** ppsz, size_t* psize )
	{
		__QCS_FCONTEXT( "CStream::open_memstream" );
		return nsPlatform::CPosumStreamAccessor::open_memstream( ppsz, psize );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::popen( const char* sz1, const char* sz2 )
	{
		__QCS_FCONTEXT( "CStream::popen" );
		return nsPlatform::CPosumStreamAccessor::popen( sz1, sz2 );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_popen( const char* command, const char* mode )
	{
		__QCS_FCONTEXT( "CStream::_popen" );
		return nsPlatform::CPosumStreamAccessor::popen( command, mode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::tmpfile( void )
	{
		__QCS_FCONTEXT( "CStream::tmpfile" );
		return nsPlatform::CPosumStreamAccessor::tmpfile();
	}

	//--------------------------------------------------------------------------------
	errno_t CStream::tmpfile_s( CStream::refType& ppFile )
	{
		__QCS_FCONTEXT( "CStream::tmpfile_s" );
		return nsPlatform::CPosumStreamAccessor::tmpfile_s( ppFile );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_fsopen( const char* filename, const char* mode, int shflag )
	{
		__QCS_FCONTEXT( "CStream::_fsopen" );
		return nsPlatform::CPosumStreamAccessor::_fsopen( filename, mode, shflag );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::open_wmemstream( wchar_t** ppwsz, size_t* psize )
	{
		__QCS_FCONTEXT( "CStream::open_wmemstream" );
		return nsPlatform::CPosumStreamAccessor::open_wmemstream( ppwsz, psize );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_wpopen( const wchar_t* pCommand, const wchar_t* pMode )
	{
		__QCS_FCONTEXT( "CStream::_wpopen" );
		return nsPlatform::CPosumStreamAccessor::_wpopen( pCommand, pMode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_wfsopen( const wchar_t* pFilename, const wchar_t* pMode )
	{
		__QCS_FCONTEXT( "CStream::_wfsopen" );
		return nsPlatform::CPosumStreamAccessor::_wfopen( pFilename, pMode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_wfreopen( const wchar_t* pFilename, const wchar_t* pMode )
	{
		__QCS_FCONTEXT( "CStream::_wfreopen" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._wfreopen( pFilename, pMode );
	}

	//--------------------------------------------------------------------------------
	errno_t CStream::_wfreopen_s( CStream::refType& pFile, const wchar_t* pFilename, const wchar_t* pMode )
	{
		__QCS_FCONTEXT( "CStream::_wfreopen_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._wfreopen_s( pFile, pFilename, pMode );
	}

	//--------------------------------------------------------------------------------
	CStream::refType CStream::_wfopen( const wchar_t* pFilename, const wchar_t* pMode )
	{
		__QCS_FCONTEXT( "CStream::_wfopen" );
		return nsPlatform::CPosumStreamAccessor::_wfopen( pFilename, pMode );
	}

	//--------------------------------------------------------------------------------
	errno_t CStream::_wfopen_s( CStream::refType& ppFile, const wchar_t* pFilename, const wchar_t* pMode )
	{
		__QCS_FCONTEXT( "CStream::_wfopen_s" );
		return nsPlatform::CPosumStreamAccessor::_wfopen_s( ppFile, pFilename, pMode );
	}

	//--------------------------------------------------------------------------------
	void CStream::clearerr()
	{
		__QCS_FCONTEXT( "CStream::clearerr" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		PSA.clearerr();
	}

	//--------------------------------------------------------------------------------
	errno_t CStream::clearerr_s( void )
	{
		__QCS_FCONTEXT( "CStream::clearerr_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.clearerr_s();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fclose( void )
	{
		__QCS_FCONTEXT( "CStream::fclose" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fclose();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::feof( void )
	{
		__QCS_FCONTEXT( "CStream::feof" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.feof();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::ferror( void )
	{
		__QCS_FCONTEXT( "CStream::ferror" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.ferror();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fflush( void )
	{
		__QCS_FCONTEXT( "CStream::fflush" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fflush();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fgetc( void )
	{
		__QCS_FCONTEXT( "CStream::fgetc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fgetc();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fgetpos( fpos_t* pos )
	{
		__QCS_FCONTEXT( "CStream::fgetpos" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fgetpos( pos );
	}
	
	//--------------------------------------------------------------------------------
	char* CStream::fgets( char* s, int n )
	{
		__QCS_FCONTEXT( "CStream::fgets" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fgets( s, n );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fileno( void )
	{
		__QCS_FCONTEXT( "CStream::fileno" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fileno();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fileno( void )
	{
		__QCS_FCONTEXT( "CStream::_fileno" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fileno();
	}
	
	//--------------------------------------------------------------------------------
	void CStream::flockfile( void )
	{
		__QCS_FCONTEXT( "CStream::flockfile" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		PSA.flockfile();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fprintf( const char* __QCMP_RESTRICT format, ... )
	{
		__QCS_FCONTEXT( "CStream::fprintf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fprintf( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fprintf_s( const char* format, ... )
	{
		__QCS_FCONTEXT( "CStream::fprintf_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fprintf_s( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fputc( int c )
	{
		__QCS_FCONTEXT( "CStream::fputc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fputc( c );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fputs( const char* __QCMP_RESTRICT s )
	{
		__QCS_FCONTEXT( "CStream::fputs" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fputs( s );
	}
	
	//--------------------------------------------------------------------------------
	size_t CStream::fread( void* __QCMP_RESTRICT ptr, size_t size, size_t nmemb )
	{
		__QCS_FCONTEXT( "CStream::fread" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fread( ptr, size, nmemb );
	}
	
	//--------------------------------------------------------------------------------
	size_t CStream::fread_s( void* ptr, size_t DstSize, size_t ElementSize, size_t Count )
	{
		__QCS_FCONTEXT( "CStream::fread_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fread_s( ptr, DstSize, ElementSize, Count );
	}
	
	//--------------------------------------------------------------------------------
	void CStream::rewind( void )
	{
		__QCS_FCONTEXT( "CStream::rewind" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.rewind();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fscanf( const char* __QCMP_RESTRICT format, ... )
	{
		__QCS_FCONTEXT( "CStream::fscanf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fscanf( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fscanf_s( const char* format, ... )
	{
		__QCS_FCONTEXT( "CStream::fscanf_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fscanf_s( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fseek( long int offset, int whence )
	{
		__QCS_FCONTEXT( "CStream::fseek" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fseek( offset, whence );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fseeko( off_t offset, int whence )
	{
		__QCS_FCONTEXT( "CStream::fseeko" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fseeko( offset, whence );
	}
	
	//--------------------------------------------------------------------------------
	void CStream::setbuf( char* __QCMP_RESTRICT buf )
	{
		__QCS_FCONTEXT( "CStream::setbuf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.setbuf( buf );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::setvbuf( char* __QCMP_RESTRICT buf, int mode, size_t size )
	{
		__QCS_FCONTEXT( "CStream::setvbuf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.setvbuf( buf, mode, size );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fsetpos( const fpos_t* pos )
	{
		__QCS_FCONTEXT( "CStream::fsetpos" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fsetpos( pos );
	}
	
	//--------------------------------------------------------------------------------
	long int CStream::ftell( void )
	{
		__QCS_FCONTEXT( "CStream::ftell" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.ftell();
	}
	
	//--------------------------------------------------------------------------------
	off_t CStream::ftello( void )
	{
		__QCS_FCONTEXT( "CStream::ftello" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.ftello();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::ftrylockfile( void )
	{
		__QCS_FCONTEXT( "CStream::ftrylockfile" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.ftrylockfile();
	}
		
	//--------------------------------------------------------------------------------
	void CStream::funlockfile( void )
	{
		__QCS_FCONTEXT( "CStream::funlockfile" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.funlockfile();
	}
	
	//--------------------------------------------------------------------------------
	size_t CStream::fwrite( const void* __QCMP_RESTRICT ptr, size_t size, size_t nmemb )
	{
		__QCS_FCONTEXT( "CStream::fwrite" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fwrite( ptr, size, nmemb );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::getc( void )
	{
		__QCS_FCONTEXT( "CStream::getc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.getc();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::getc_unlocked( void )
	{
		__QCS_FCONTEXT( "CStream::getc_unlocked" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.getc_unlocked();
	}
	
	//--------------------------------------------------------------------------------
	ssize_t CStream::getdelim( char** __QCMP_RESTRICT ppsz, size_t* __QCMP_RESTRICT pSize, int n )
	{
		__QCS_FCONTEXT( "CStream::getdelim" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.getdelim( ppsz, pSize, n );
	}
	
	//--------------------------------------------------------------------------------
	ssize_t CStream::getline( char** __QCMP_RESTRICT ppsz, size_t* __QCMP_RESTRICT pSize )
	{
		__QCS_FCONTEXT( "CStream::getline" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.getline( ppsz, pSize );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::pclose( void )
	{
		__QCS_FCONTEXT( "CStream::pclose" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.pclose();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::putc( int c )
	{
		__QCS_FCONTEXT( "CStream::putc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.putc( c );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::putc_unlocked( int c )
	{
		__QCS_FCONTEXT( "CStream::putc_unlocked" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.putc_unlocked( c );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::ungetc( int c )
	{
		__QCS_FCONTEXT( "CStream::ungetc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.ungetc( c );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::vfprintf( const char* __QCMP_RESTRICT format, va_list arg )
	{
		__QCS_FCONTEXT( "CStream::vfprintf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.vfprintf( format, arg );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::vfprintf_s( const char* format, va_list arg )
	{
		__QCS_FCONTEXT( "CStream::vfprintf_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.vfprintf_s( format, arg );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::vfscanf( const char* __QCMP_RESTRICT format, va_list arg )
	{
		__QCS_FCONTEXT( "CStream::vfscanf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.vfscanf( format, arg );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_putw( int binint )
	{
		__QCS_FCONTEXT( "CStream::_putw" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._putw( binint );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_getw( void )
	{
		__QCS_FCONTEXT( "CStream::_getw" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._getw();
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fwprintf_l( const wchar_t* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fwprintf_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale );
        iResult = PSA._fwprintf_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fwprintf_p( const wchar_t* format, ...)
	{
		__QCS_FCONTEXT( "CStream::_fwprintf_p" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA._fwprintf_p( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fwprintf_p_l( const wchar_t* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fwprintf_p_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fwprintf_p_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fwprintf_s_l( const wchar_t* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fwprintf_s_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fwprintf_s_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fwscanf_l( const wchar_t* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fwscanf_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fwscanf_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fwscanf_s_l( const wchar_t* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fwscanf_s_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fwscanf_s_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fscanf_l( const char* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fscanf_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fscanf_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fscanf_s_l( const char* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fscanf_s_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fscanf_s_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fseeki64( Cmp__int64 offset, int origin )
	{
		__QCS_FCONTEXT( "CStream::_fseeki64" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._fseeki64( offset, origin );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fprintf_l( const char* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fprintf_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fprintf_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fprintf_p( const char* format, ... )
	{
		__QCS_FCONTEXT( "CStream::_fprintf_p" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA._fprintf_p( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fprintf_p_l( const char* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fprintf_p_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fprintf_p_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_fprintf_s_l( const char* format, locale_t locale, ... )
	{
		__QCS_FCONTEXT( "CStream::_fprintf_s_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, locale);
        iResult = PSA._fprintf_s_l( format, locale, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	wint_t CStream::fgetwc()
	{
		__QCS_FCONTEXT( "CStream::fgetwc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fgetwc();
	}
	
	//--------------------------------------------------------------------------------
	wchar_t* CStream::fgetws( wchar_t* __QCMP_RESTRICT s, int n )
	{
		__QCS_FCONTEXT( "CStream::fgetws" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fgetws( s, n );
	}
	
	//--------------------------------------------------------------------------------
	wint_t CStream::fputwc( wchar_t c )
	{
		__QCS_FCONTEXT( "CStream::fputwc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fputwc( c );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fputws( const wchar_t* __QCMP_RESTRICT s )
	{
		__QCS_FCONTEXT( "CStream::fputws" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fputws( s );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fwide( int mode )
	{
		__QCS_FCONTEXT( "CStream::fwide" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.fwide( mode );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fwprintf( const wchar_t* __QCMP_RESTRICT format, ... )
	{
		__QCS_FCONTEXT( "CStream::fwprintf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fwprintf( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fwscanf( const wchar_t* __QCMP_RESTRICT format, ... )
	{
		__QCS_FCONTEXT( "CStream::fwscanf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fwscanf( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	wint_t CStream::getwc()
	{
		__QCS_FCONTEXT( "CStream::getwc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.getwc();
	}
	
	//--------------------------------------------------------------------------------
	wint_t CStream::putwc( wchar_t c )
	{
		__QCS_FCONTEXT( "CStream::putwc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.putwc( c );
	}
	
	//--------------------------------------------------------------------------------
	wint_t CStream::ungetwc( wint_t c )
	{
		__QCS_FCONTEXT( "CStream::ungetwc" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.ungetwc( c );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::vfwprintf( const wchar_t* __QCMP_RESTRICT format, va_list arg )
	{
		__QCS_FCONTEXT( "CStream::vfwprintf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.vfwprintf( format, arg );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::vfwscanf( const wchar_t* __QCMP_RESTRICT format, va_list arg )
	{
		__QCS_FCONTEXT( "CStream::vfwscanf" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.vfwscanf( format, arg );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fwprintf_s( const wchar_t* format, ... )
	{
		__QCS_FCONTEXT( "CStream::fwprintf_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fwprintf_s( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::fwscanf_s( const wchar_t* format, ... )
	{
		__QCS_FCONTEXT( "CStream::fwscanf_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		int iResult = 0;
        va_list args;
        va_start(args, format);
        iResult = PSA.fwscanf_s( format, args );
        va_end(args);
		return iResult;
	}
	
	//--------------------------------------------------------------------------------
	int CStream::vfwprintf_s( const wchar_t* format, va_list arg )
	{
		__QCS_FCONTEXT( "CStream::vfwprintf_s" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA.vfwprintf_s( format, arg );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfprintf_l( const char* format, locale_t locale, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfprintf_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfprintf_l( format, locale, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfprintf_p( const char* format, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfprintf_p" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfprintf_p( format, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfprintf_p_l( const char* format, locale_t locale, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfprintf_p_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfprintf_p_l( format, locale, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfprintf_s_l( const char* format, locale_t locale, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfprintf_s_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfprintf_s_l( format, locale, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfwprintf_l( const wchar_t* format, locale_t locale, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfwprintf_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfwprintf_l( format, locale, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfwprintf_p( const wchar_t* format, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfwprintf_p" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfwprintf_p( format, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfwprintf_p_l( const wchar_t* format, locale_t locale, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfwprintf_p_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfwprintf_p_l( format, locale, argptr );
	}
	
	//--------------------------------------------------------------------------------
	int CStream::_vfwprintf_s_l( const wchar_t* format, locale_t locale, va_list argptr )
	{
		__QCS_FCONTEXT( "CStream::_vfwprintf_s_l" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		return PSA._vfwprintf_s_l( format, locale, argptr );
	}

	//--------------------------------------------------------------------------------
	void CStream::AddRef( void )
	{
		__QCS_FCONTEXT( "CStream::AddRef" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		PSA.AddRef();
	}

	//--------------------------------------------------------------------------------
	void CStream::Release( void )
	{
		__QCS_FCONTEXT( "CStream::Release" );
		nsPlatform::CPosumStreamAccessor PSA( m_pFILE );
		PSA.Release();
	}

}//nsPosum
