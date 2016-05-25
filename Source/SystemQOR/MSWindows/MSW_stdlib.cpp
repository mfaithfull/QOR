//MSW_stdlib.cpp

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

#if		(QOR_SYS_OS == QOR_SYS_MSW)

#include "SystemQOR/MSWindows/MSW_stdlib.h"
#include "SystemQOR/SharedBootStrap.h"
#include "WinQL/CodeServices/Locale/WinQLLocaleUpdate.h"
#include <errno.h>

//--------------------------------------------------------------------------------
namespace
{
	nsBaseCRT::Cstdlib* g_pstdlib = 0;
}//anonymous

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	int WaitExitStatus( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int WaitIfExited( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int WaitIfSignaled( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int WaitIfStopped( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int WaitStopSignal( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int WaitTermSignal( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __QSYS )  int MBCurMax( void )
	{
		return 1;
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __QSYS ) int MBCurMax_l( locale_t l )
	{
		return 1;//TODO: Fix this
	}

	//--------------------------------------------------------------------------------
	Cstdlib::Cstdlib()
	{
		g_pstdlib = this;
	}

	//--------------------------------------------------------------------------------
	Cstdlib::~Cstdlib()
	{
		g_pstdlib = 0;
	}

	//--------------------------------------------------------------------------------
	nsBaseCRT::Cstdlib* Cstdlib::Thestdlib()
	{
		return g_pstdlib;
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::_get_doserrno( int* pValue )
	{
        _WINQ_FCONTEXT( "Cstdlib::_get_doserrno" );
        errno_t Result = 0;
		//TODO:
        return Result;
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::_set_doserrno( int value )
	{
        _WINQ_FCONTEXT( "Cstdlib::_set_doserrno" );
        errno_t Result = 0;
		//TODO:
        return Result;
	}

	//--------------------------------------------------------------------------------
	__QCMP_NORETURN void Cstdlib::abort( void )
	{
		_WINQ_FCONTEXT( "Cstdlib::abort" );
		_exit( 3 );
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::atexit( void (*pFunc)(void) )
	{
		_WINQ_FCONTEXT( "Cstdlib::atexit" );

		int iResult = g_pBootStrap->atexit( pFunc );
		/*
		if( nsWin32::nsCodeServices::CProcess::ThisProcess() )
		{
			nsWin32::nsCodeServices::CProcess::ThisProcess()->AtExitList().Append( pFunc );
		}
		*/
		return iResult;
	}

	//--------------------------------------------------------------------------------
	void* Cstdlib::calloc( size_t nNum, size_t nSize )
	{
		_WINQ_FCONTEXT( "Cstdlib::calloc" );
		void* pvBlk = 0;
		__QCS_PROTECT
		{
			// ensure that (nSize * nNum) does not overflow
			//if( nNum == 0 || ( nSize < ( _HEAP_MAXREQ / nNum ) ) )
			{
				nSize *= nNum;
				pvBlk = this->malloc( nSize );//try to malloc the requested space
				if( pvBlk != 0 )
				{
					memset( pvBlk, 0, nSize );// If malloc() succeeded, initialize the allocated space to zeros.
				}
			}
			/*
			else
			{
				errno = ENOMEM;
			}
			*/
		}__QCS_ENDPROTECT

		return pvBlk;
	}

	//--------------------------------------------------------------------------------
	void Cstdlib::exit( int status )
	{
		_WINQ_FCONTEXT( "Cstdlib::exit" );
		doexit( status, 0, 0 );
	}

	//--------------------------------------------------------------------------------
	void Cstdlib::_exit( int status )
	{
		_WINQ_FCONTEXT( "Cstdlib::_exit" );
		doexit( status, 1, 0 ); // quick term, kill process
	}

	//--------------------------------------------------------------------------------
	void Cstdlib::free( void* ptr )
	{
		_WINQ_FCONTEXT( "Cstdlib::free" );
		__QCS_PROTECT
		{
			m_ProcessHeap.Free( 0, ptr );
		}__QCS_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	char* Cstdlib::getenv( const char* name)
	{
		_WINQ_FCONTEXT( "Cstdlib::getenv" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::getenv_s( size_t* pReturnSize, char* pDstBuf, size_t DstSize, const char* pszVarName )
	{
		_WINQ_FCONTEXT( "Cstdlib::getenv_s" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::grantpt( int iFileDes )
	{
		_WINQ_FCONTEXT( "Cstdlib::grantpt" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	char* Cstdlib::initstate( unsigned int uiSeed, char* pState, size_t Size )
	{
		_WINQ_FCONTEXT( "Cstdlib::initstate" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	void* Cstdlib::malloc( size_t size )
	{
		_WINQ_FCONTEXT( "Cstdlib::malloc" );
		void* pAlloc = 0;
		__QCS_PROTECT
		{
			pAlloc = m_ProcessHeap.Alloc( 0, size );
		}__QCS_ENDPROTECT
		return pAlloc;
	}

	//--------------------------------------------------------------------------------
	size_t Cstdlib::mbstowcs( wchar_t* pwcs, const char* s, size_t n )
	{
		_WINQ_FCONTEXT( "Cstdlib::mbstows" );
		return _mbstowcs_l( pwcs, s, n, NULL );
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::mbstowcs_s( size_t* pNumOfCharConverted, wchar_t* pDstBuf, size_t SizeInWords, const char* s, size_t MaxCount )
	{
		_WINQ_FCONTEXT( "Cstdlib::mbstowcs_s" );
		return _mbstowcs_s_l( pNumOfCharConverted, pDstBuf, SizeInWords, s, MaxCount, NULL );
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::mbtowc( wchar_t* pwc, const char* s, size_t n )
	{
		_WINQ_FCONTEXT( "Cstdlib::mbtowc" );
		if( !s || n == 0 )
		{
			// indicate do not have state-dependent encodings,handle zero length string
			return 0;
		}

		if( !*s )
		{
			// handle NULL char
			if( pwc )
			{
				*pwc = 0;
			}
			return 0;
		}


		CLocaleThreadData* pLocaleThreadData = 0;//TODO:
		CLocaleUpdate _loc_update( pLocaleThreadData );


		if ( _loc_update.GetLocaleT()->LocaleInfoPtr()->Handles()[ CLocale::LCCTYPE ] == CLocale::_CLOCALEHANDLE )
		{
			if (pwc)
			{
				*pwc = (wchar_t)(unsigned char)*s;
			}
			return sizeof(char);
		}

		if( _loc_update.GetLocaleT()->LocaleInfoPtr()->CType()[ (unsigned char)(*s) ] & CharData::E_LEADBYTE )//lead byte check
		{
			// multi-byte char

			if ( ( _loc_update.GetLocaleT()->LocaleInfoPtr()->MBCurMax() <= 1) || 
				( (int)n < _loc_update.GetLocaleT()->LocaleInfoPtr()->MBCurMax() ) || 
				_loc_update.GetLocaleT()->LocaleInfoPtr()->CodePage().MultiByteToWideChar( MB_Precomposed | MB_Err_Invalid_Chars, s, _loc_update.GetLocaleT()->LocaleInfoPtr()->MBCurMax(), pwc, (pwc) ? 1 : 0 ) == 0 )				
			{
				// validate high byte of mbcs char
				if ( (n < (size_t)_loc_update.GetLocaleT()->LocaleInfoPtr()->MBCurMax() ) || (!*(s + 1)) )
				{
					errno = EILSEQ;
					return -1;
				}
			}
			return _loc_update.GetLocaleT()->LocaleInfoPtr()->MBCurMax();
		}
		else 
		{
			// single byte char
			if( _loc_update.GetLocaleT()->LocaleInfoPtr()->CodePage().MultiByteToWideChar( MB_Precomposed | MB_Err_Invalid_Chars, s, 1, pwc, (pwc) ? 1 : 0 ) == 0 )
			{
				errno = EILSEQ;
				return -1;
			}
			return sizeof(char);
		}
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::posix_openpt( int oflag )
	{
		_WINQ_FCONTEXT( "Cstdlib::posix_openpt" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	char* Cstdlib::ptsname( int iFileDes )
	{
		_WINQ_FCONTEXT( "Cstdlib::ptsname" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cstdlib::qsort_s( void* base, size_t nmemb, size_t SizeOfElements, int ( *pFuncCompare )( void*, const void*, const void* ), void* pvContext )
	{
		_WINQ_FCONTEXT( "Cstdlib::qsort_s" );
	}

	//--------------------------------------------------------------------------------
	long Cstdlib::random( void )
	{
		_WINQ_FCONTEXT( "Cstdlib::random" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	void* Cstdlib::realloc( void* ptr, size_t size )
	{
		_WINQ_FCONTEXT( "Cstdlib::realloc" );
		void* pAlloc = 0;
		__QCS_PROTECT
		{
			if( ptr == 0 )
			{
				pAlloc = m_ProcessHeap.Alloc( 0, size );
			}
			else
			{
				pAlloc = m_ProcessHeap.ReAlloc( 0, ptr, size );
			}
		}__QCS_ENDPROTECT
		return pAlloc;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::setenv( const char* envname, const char* envval, int overwrite )
	{
		_WINQ_FCONTEXT( "Cstdlib::setenv" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cstdlib::setkey( const char* pszKey )
	{
		_WINQ_FCONTEXT( "Cstdlib::setkey" );
	}

	//--------------------------------------------------------------------------------
	char* Cstdlib::setstate( const char* state )
	{
		_WINQ_FCONTEXT( "Cstdlib::setstate" );
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cstdlib::srandom( unsigned int uiSeed )
	{
		_WINQ_FCONTEXT( "Cstdlib::srandom" );
	}

	//--------------------------------------------------------------------------------
	long double Cstdlib::strtold( const char* nptr, char** endptr )
	{
		_WINQ_FCONTEXT( "Cstdlib::strtold" );
		return strtox( nptr, endptr, 2 );
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::system( const char* string )
	{
		_WINQ_FCONTEXT( "Cstdlib::system" );
		/*
        _TSCHAR *argv[4];
        _TSCHAR *envbuf = NULL;
        int retval = 0;

        _ERRCHECK_EINVAL(_tdupenv_s_crt(&envbuf, NULL, _T("COMSPEC")));
        argv[0] = envbuf;

        //
         // If command == NULL, return true IFF %COMSPEC%
         // is set AND the file it points to exists.
         //

        if (command == NULL)
        {
            if(argv[0]==NULL)
            {
                goto cleanup;
            }
            else
            {
                // _taccess_s does not change errno if the return value is 0
                errno_t e = _taccess_s(argv[0], 0);
                retval = (e == 0);
                goto cleanup;
            }
        }

        _ASSERTE(*command != _T('\0'));

        argv[1] = _T("/c");
        argv[2] = (_TSCHAR *) command;
        argv[3] = NULL;

        // If there is a COMSPEC defined, try spawning the shell

        // Do not try to spawn the null string
        if (argv[0])
        {
                errno_t save_errno = errno;
                errno = 0;

                if ((retval = (int)_tspawnve(_P_WAIT,argv[0],argv,NULL)) != -1)
                {
                    errno = save_errno;
                    goto cleanup;
                }
                if (errno != ENOENT && errno != EACCES)
                {
                    goto cleanup;
                }
                errno = save_errno;
        }

        // No COMSPEC so set argv[0] to what COMSPEC should be
        argv[0] = _T("cmd.exe");

        // Let the _spawnvpe routine do the path search and spawn.

        retval = (int)_tspawnvpe(_P_WAIT,argv[0],argv,NULL);
        goto cleanup;

cleanup:
        _free_crt(envbuf);
        return retval;
		*/
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::unlockpt( int iFileDes )
	{
		_WINQ_FCONTEXT( "Cstdlib::unlockpt" );
		/*
			int unlock = 0;
			return ioctl( iFileDes, TIOCSPTLCK, &unlock );
		*/
		return 0;
	}

	//--------------------------------------------------------------------------------
	size_t Cstdlib::wcstombs( char* s, const wchar_t* pwcs, size_t n )
	{
		_WINQ_FCONTEXT( "Cstdlib::wcstombs" );
		return _wcstombs_l_helper( s, pwcs, n, NULL );
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::wctomb( char* s, wchar_t wchar )
	{
		_WINQ_FCONTEXT( "Cstdlib::wctomb" );
		
		int retval = -1;
		errno_t e;

		e = _wctomb_s_l( &retval, s, MB_CUR_MAX, wchar, NULL );
		return ( e == 0 ? retval : -1 );
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::wcstombs_s( size_t* pReturnValue, char* mbstr, size_t sizeInBytes, const wchar_t* wcstr, size_t count )
	{
		_WINQ_FCONTEXT( "Cstdlib::wcstomb_s" );
		return _wcstombs_s_l( pReturnValue, mbstr, sizeInBytes, wcstr, count, NULL);
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::wctomb_s( int* pRetValue, char* mbchar, size_t sizeInBytes, wchar_t wchar )
	{
		_WINQ_FCONTEXT( "Cstdlib::wctomb_s" );
		return _wctomb_s_l( pRetValue, mbchar, sizeInBytes, wchar, NULL );
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitExitStatus( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitIfExited( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitIfSignaled( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitIfStopped( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitStopSignal( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitTermSignal( int status )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitUntraced( void )
	{
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::WaitNoHang( void )
	{
		return 0;
	}





	//--------------------------------------------------------------------------------
	long double Cstdlib::strtox( const char *s, char** p, int prec )
	{
		/*
		FILE f = {
		.buf = (void *)s, .rpos = (void *)s,
		.rend = (void *)-1, .lock = -1
		};
		*/
		//shlim(&f, 0);
		/*
		long double y = __floatscan(&f, prec, 1);
		off_t cnt = shcnt(&f);
		if (p) *p = cnt ? (char *)s + cnt : (char *)s;
		return y;*/
		return 0;
	}

	//--------------------------------------------------------------------------------
	errno_t Cstdlib::_wcstombs_s_l( size_t *pConvertedChars, char * dst, size_t sizeInBytes, const wchar_t * src, size_t n, nsWin32::CLocaleThreadData* plocinfo )
	{
		size_t retsize;
		errno_t retvalue = 0;

		/*
		_VALIDATE_RETURN_ERRCODE((dst != NULL && sizeInBytes > 0) || (dst == NULL && sizeInBytes == 0), EINVAL);
		if (dst != NULL)
		{
			_RESET_STRING(dst, sizeInBytes);
		}

		if (pConvertedChars != NULL)
		{
			*pConvertedChars = 0;
		}

		size_t bufferSize = n > sizeInBytes ? sizeInBytes : n;
		_VALIDATE_RETURN_ERRCODE(bufferSize <= INT_MAX, EINVAL);

		retsize = _wcstombs_l_helper(dst, src, bufferSize, plocinfo);

		if (retsize == (size_t)-1)
		{
			if (dst != NULL)
			{
				_RESET_STRING(dst, sizeInBytes);
			}
			return errno;
		}

		// count the null terminator
		retsize++;

		if (dst != NULL)
		{
			// return error if the string does not fit, unless n == _TRUNCATE
			if (retsize > sizeInBytes)
			{
				if (n != _TRUNCATE)
				{
					_RESET_STRING(dst, sizeInBytes);
					_VALIDATE_RETURN_ERRCODE(sizeInBytes > retsize, ERANGE);
				}
				retsize = sizeInBytes;
				retvalue = STRUNCATE;
			}

			// ensure the string is null terminated
			dst[retsize - 1] = '\0';
		}

		if (pConvertedChars != NULL)
		{
			*pConvertedChars = retsize;
		}
		*/
		return retvalue;
	}

	//--------------------------------------------------------------------------------
	size_t Cstdlib::_wcstombs_l_helper( char* s, const wchar_t* pwcs, size_t n, nsWin32::CLocaleThreadData* plocinfo )
	{
		size_t count = 0;
		int i, retval;
		/*
		char buffer[MB_LEN_MAX];
		BOOL defused = 0;

		if (s && n == 0)
			// dest string exists, but 0 bytes converted 
			return 0;

		// validation section
		_VALIDATE_RETURN(pwcs != NULL, EINVAL, (size_t)-1);


		// if destination string exists, fill it in

		_LocaleUpdate _loc_update(plocinfo);

		if (s)
		{
			if ( _loc_update.GetLocaleT()->locinfo->lc_handle[LC_CTYPE] == _CLOCALEHANDLE )
			{
				// C locale: easy and fast
				// Actually, there are such wchar_t characters which are > 255,
				// but they can be transformed to a valid single byte char
				// (i.e. a char in the C locale case). Like, for example,
				// alternative digits in unicode like Arabic-Indic U+0660..U+0669.
				// The problem is that WideCharToMultiByte() does not translate those
				// wchar_t unless we pass the correct codepage (1256, Arabic).
				// See bug VSW:192653.
				 
				while(count < n)
				{
					if (*pwcs > 255)  // validate high byte
					{
						errno = EILSEQ;
						return (size_t)-1;  // error
					}
					s[count] = (char) *pwcs;
					if (*pwcs++ == L'\0')
						return count;
					count++;
				}
				return count;
			} else {

				if (1 == _loc_update.GetLocaleT()->locinfo->mb_cur_max)
				{
					// If SBCS, one wchar_t maps to one char

					// WideCharToMultiByte will compare past NULL - reset n
					if (n > 0)
						n = wcsncnt(pwcs, n);
					if ( ((count = WideCharToMultiByte( _loc_update.GetLocaleT()->locinfo->lc_codepage,
														0,
														pwcs,
														(int)n,
														s,
														(int)n,
														NULL,
														&defused )) != 0) &&
						 (!defused) )
					{
						if (*(s + count - 1) == '\0')
							count--; // don't count NUL

						return count;
					}

					errno = EILSEQ;
					return (size_t)-1;
				}
				else {

					// If MBCS, wchar_t to char mapping unknown

					// Assume that usually the buffer is large enough
					if ( ((count = WideCharToMultiByte( _loc_update.GetLocaleT()->locinfo->lc_codepage,
														0,
														pwcs,
														-1,
														s,
														(int)n,
														NULL,
														&defused )) != 0) &&
						 (!defused) )
					{
						return count - 1; // don't count NUL
					}

					if (defused || GetLastError() != ERROR_INSUFFICIENT_BUFFER)
					{
						errno = EILSEQ;
						return (size_t)-1;
					}

					// buffer not large enough, must do char by char
					while (count < n)
					{
						if ( ((retval = WideCharToMultiByte( _loc_update.GetLocaleT()->locinfo->lc_codepage,
															 0,
															 pwcs,
															 1,
															 buffer,
															 _loc_update.GetLocaleT()->locinfo->mb_cur_max,
															 NULL,
															 &defused )) == 0)
							 || defused )
						{
							errno = EILSEQ;
							return (size_t)-1;
						}

						// enforce this for prefast 
						if (retval < 0 ||
							retval > _countof(buffer))
						{
							errno = EILSEQ;
							return (size_t)-1;
						}

						if (count + retval > n)
							return count;

						for (i = 0; i < retval; i++, count++) // store character
							if((s[count] = buffer[i])=='\0')
								return count;

						pwcs++;
					}

					return count;
				}
			}
		}
		else { // s == NULL, get size only, pwcs must be NUL-terminated
			if ( _loc_update.GetLocaleT()->locinfo->lc_handle[LC_CTYPE] == _CLOCALEHANDLE )
			{
				size_t len = 0;
				for (wchar_t *pw = (wchar_t *)pwcs; *pw != 0; pw++)  // validate high byte
				{
					if (*pw > 255)  // validate high byte
					{
						errno = EILSEQ;
						return (size_t)-1;  // error
					}
					++len;
				}

				return len;
			}
			else {
				if ( ((count = WideCharToMultiByte( _loc_update.GetLocaleT()->locinfo->lc_codepage,
													0,
													pwcs,
													-1,
													NULL,
													0,
													NULL,
													&defused )) == 0) ||
					 (defused) )
				{
					errno = EILSEQ;
					return (size_t)-1;
				}

				return count - 1;
			}
		}
		*/
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cstdlib::_wctomb_s_l( int* pRetValue, char* dst, size_t sizeInBytes, wchar_t wchar, nsWin32::CLocaleThreadData* plocinfo )
	{
		/*
		if (dst == NULL && sizeInBytes > 0)
		{
			// indicate do not have state-dependent encodings
			if (pRetValue != NULL)
			{
				*pRetValue = 0;
			}
			return 0;
		}

		if (pRetValue != NULL)
		{
			*pRetValue = -1;
		}

		// validation section
		// we need to cast sizeInBytes to int, so we make sure we are not going to truncate sizeInBytes
		_VALIDATE_RETURN_ERRCODE(sizeInBytes <= INT_MAX, EINVAL);


		_LocaleUpdate _loc_update(plocinfo);

		if ( _loc_update.GetLocaleT()->locinfo->lc_handle[LC_CTYPE] == _CLOCALEHANDLE )
		{
			if ( wchar > 255 )  // validate high byte
			{
				if (dst != NULL && sizeInBytes > 0)
				{
					memset(dst, 0, sizeInBytes);
				}
				errno = EILSEQ;
				return errno;
			}

			if (dst != NULL)
			{
				_VALIDATE_RETURN_ERRCODE(sizeInBytes > 0, ERANGE);
				*dst = (char) wchar;
			}
			if (pRetValue != NULL)
			{
				*pRetValue = 1;
			}
			return 0;
		}
		else
		{
			int size;
			BOOL defused = 0;

			if ( ((size = WideCharToMultiByte( _loc_update.GetLocaleT()->locinfo->lc_codepage,
											   0,
											   &wchar,
											   1,
											   dst,
											   (int)sizeInBytes,
											   NULL,
											   &defused) ) == 0) ||
				 (defused) )
			{
				if (size == 0 && GetLastError() == ERROR_INSUFFICIENT_BUFFER)
				{
					if (dst != NULL && sizeInBytes > 0)
					{
						memset(dst, 0, sizeInBytes);
					}
					_VALIDATE_RETURN_ERRCODE(("Buffer too small", 0), ERANGE);
				}
				errno = EILSEQ;
				return errno;
			}

			if (pRetValue != NULL)
			{
				*pRetValue = size;
			}
			return 0;
		}
		*/
		return 0;
	}

}//nsWin32

#endif//(QOR_SYS_OS == QOR_SYS_MSW)
