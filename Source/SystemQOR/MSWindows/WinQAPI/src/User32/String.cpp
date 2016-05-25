//String.cpp
//String functions

#include "WinQAPI/User32.h"
#include "ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	LPSTR CUser32::CharLowerA( LPSTR lpsz )
	{
		_WINQ_FCONTEXT( "CUser32::CharLowerA" );
		_WINQ_USESAPI( CharLowerA );
		return Call< LPSTR, LPSTR >( pFunc, lpsz );
	}

	//--------------------------------------------------------------------------------
	LPWSTR CUser32::CharLowerW( LPWSTR lpwsz )
	{
		_WINQ_FCONTEXT( "CUser32::CharLowerW" );
		_WINQ_USESAPI( CharLowerW );
		return Call< LPWSTR, LPWSTR >( pFunc, lpwsz );
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::CharLowerBuffA( LPSTR lpsz, DWORD cchLength )
	{
		_WINQ_FCONTEXT( "CUser32::CharLowerBuffA" );
		_WINQ_USESAPI( CharLowerBuffA );
		return Call< DWORD, LPSTR, DWORD >( pFunc, lpsz, cchLength );
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::CharLowerBuffW( LPWSTR lpwsz, DWORD cchLength )
	{
		_WINQ_FCONTEXT( "CUser32::CharLowerBuffW" );
		_WINQ_USESAPI( CharLowerBuffW );
		return Call< DWORD, LPWSTR, DWORD >( pFunc, lpwsz, cchLength );
	}

	//--------------------------------------------------------------------------------
	LPSTR CUser32::CharNextA( LPCSTR lpsz )
	{
		_WINQ_FCONTEXT( "CUser32::CharNextA" );
		_WINQ_USESAPI( CharNextA );
		return Call< LPSTR, LPCSTR >( pFunc, lpsz );
	}

	//--------------------------------------------------------------------------------
	LPWSTR CUser32::CharNextW( LPCWSTR lpwsz )
	{
		_WINQ_FCONTEXT( "CUser32::CharNextW" );
		_WINQ_USESAPI( CharNextW );
		return Call< LPWSTR, LPCWSTR >( pFunc, lpwsz );
	}

	//--------------------------------------------------------------------------------
	LPSTR CUser32::CharNextExA( WORD CodePage, LPCSTR lpCurrentChar, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::CharNextExA" );
		_WINQ_USESAPI( CharNextExA );
		return Call< LPSTR, WORD, LPCSTR, DWORD >( pFunc, CodePage, lpCurrentChar, dwFlags );
	}

	//--------------------------------------------------------------------------------
	LPSTR CUser32::CharPrevA( LPCSTR lpszStart, LPCSTR lpszCurrent )
	{
		_WINQ_FCONTEXT( "CUser32::CharPrevA" );
		_WINQ_USESAPI( CharPrevA );
		return Call< LPSTR, LPCSTR, LPCSTR >( pFunc, lpszStart, lpszCurrent );
	}

	//--------------------------------------------------------------------------------
	LPWSTR CUser32::CharPrevW( LPCWSTR lpwszStart, LPCWSTR lpwszCurrent )
	{
		_WINQ_FCONTEXT( "CUser32::CharPrevW" );
		_WINQ_USESAPI( CharPrevW );
		return Call< LPWSTR, LPCWSTR, LPCWSTR >( pFunc, lpwszStart, lpwszCurrent );
	}

	//--------------------------------------------------------------------------------
	LPSTR CUser32::CharPrevExA( WORD CodePage, LPCSTR lpStart, LPCSTR lpCurrentChar, DWORD dwFlags )
	{
		_WINQ_FCONTEXT( "CUser32::CharPrevExA" );
		_WINQ_USESAPI( CharPrevExA );
		return Call< LPSTR, WORD, LPCSTR, LPCSTR, DWORD >( pFunc, CodePage, lpStart, lpCurrentChar, dwFlags );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::CharToOemA( LPCSTR lpszSrc, LPSTR lpszDst )
	{
		_WINQ_FCONTEXT( "CUser32::CharToOemA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( CharToOemA );
		bResult = Call< BOOL, LPCSTR, LPSTR >( pFunc, lpszSrc, lpszDst );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::CharToOemW( LPCWSTR lpwszSrc, LPSTR lpszDst )
	{
		_WINQ_FCONTEXT( "CUser32::CharToOemW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( CharToOemW );
		bResult = Call< BOOL, LPCWSTR, LPSTR >( pFunc, lpwszSrc, lpszDst );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::CharToOemBuffA( LPCSTR lpszSrc, LPSTR lpszDst, DWORD cchDstLength )
	{
		_WINQ_FCONTEXT( "CUser32::CharToOemBuffA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( CharToOemBuffA );
		bResult = Call< BOOL, LPCSTR, LPSTR, DWORD >( pFunc, lpszSrc, lpszDst, cchDstLength );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::CharToOemBuffW( LPCWSTR lpwszSrc, LPSTR lpszDst, DWORD cchDstLength )
	{
		_WINQ_FCONTEXT( "CUser32::CharToOemBuffW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( CharToOemBuffW );
		bResult = Call< BOOL, LPCWSTR, LPSTR, DWORD >( pFunc, lpwszSrc, lpszDst, cchDstLength );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	LPSTR CUser32::CharUpperA( LPSTR lpsz )
	{
		_WINQ_FCONTEXT( "CUser32::CharUpperA" );
		_WINQ_USESAPI( CharUpperA );
		return Call< LPSTR, LPSTR >( pFunc, lpsz );
	}

	//--------------------------------------------------------------------------------
	LPWSTR CUser32::CharUpperW( LPWSTR lpwsz )
	{
		_WINQ_FCONTEXT( "CUser32::CharUpperW" );
		_WINQ_USESAPI( CharUpperW );
		return Call< LPWSTR, LPWSTR >( pFunc, lpwsz );
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::CharUpperBuffA( LPSTR lpsz, DWORD cchLength )
	{
		_WINQ_FCONTEXT( "CUser32::CharUpperBuffA" );
		_WINQ_USESAPI( CharUpperBuffA );
		return Call< DWORD, LPSTR, DWORD >( pFunc, lpsz, cchLength );
	}

	//--------------------------------------------------------------------------------
	DWORD CUser32::CharUpperBuffW( LPWSTR lpwsz, DWORD cchLength )
	{
		_WINQ_FCONTEXT( "CUser32::CharUpperBuffW" );
		_WINQ_USESAPI( CharUpperBuffW );
		return Call< DWORD, LPWSTR, DWORD >( pFunc, lpwsz, cchLength );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharAlphaA( char ch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharAlphaA" );
		_WINQ_USESAPI( IsCharAlphaA );
		return Call< BOOL, char >( pFunc, ch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharAlphaW( wchar_t wch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharAlphaW" );
		_WINQ_USESAPI( IsCharAlphaW );
		return Call< BOOL, wchar_t >( pFunc, wch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharAlphaNumericA( char ch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharAlphaNumericA" );
		_WINQ_USESAPI( IsCharAlphaNumericA );
		return Call< BOOL, char >( pFunc, ch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharAlphaNumericW( wchar_t wch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharAlphaNumericW" );
		_WINQ_USESAPI( IsCharAlphaNumericW );
		return Call< BOOL, wchar_t >( pFunc, wch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharLowerA( char ch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharLowerA" );
		_WINQ_USESAPI( IsCharLowerA );
		return Call< BOOL, char >( pFunc, ch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharLowerW( wchar_t wch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharLowerW" );
		_WINQ_USESAPI( IsCharLowerW );
		return Call< BOOL, wchar_t >( pFunc, wch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharUpperA( char ch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharUpperA" );
		_WINQ_USESAPI( IsCharUpperA );
		return Call< BOOL, char >( pFunc, ch );
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::IsCharUpperW( wchar_t wch )
	{
		_WINQ_FCONTEXT( "CUser32::IsCharUpperW" );
		_WINQ_USESAPI( IsCharUpperW );
		return Call< BOOL, wchar_t >( pFunc, wch );
	}

	//--------------------------------------------------------------------------------
	int CUser32::LoadStringA( HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int nBufferMax )
	{
		_WINQ_FCONTEXT( "CUser32::LoadStringA" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult;
		_WINQ_USESAPI( LoadStringA );
		iResult = Call< int, HINSTANCE, UINT, LPSTR, int >( pFunc, hInstance, uID, lpBuffer, nBufferMax );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::LoadStringW( HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int nBufferMax )
	{
		_WINQ_FCONTEXT( "CUser32::LoadStringW" );
		CCheckReturn< int, CCheckNonZero< int > >::TType iResult;
		_WINQ_USESAPI( LoadStringW );
		iResult = Call< int, HINSTANCE, UINT, LPWSTR, int >( pFunc, hInstance, uID, lpBuffer, nBufferMax );
		return iResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::OemToCharA( LPCSTR lpszSrc, LPSTR lpszDst )
	{
		_WINQ_FCONTEXT( "CUser32::OemToCharA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( OemToCharA );
		bResult = Call< BOOL, LPCSTR, LPSTR >( pFunc, lpszSrc, lpszDst );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::OemToCharW( LPCSTR lpszSrc, LPWSTR lpwszDst )
	{
		_WINQ_FCONTEXT( "CUser32::OemToCharW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( OemToCharW );
		bResult = Call< BOOL, LPCSTR, LPWSTR >( pFunc, lpszSrc, lpwszDst );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::OemToCharBuffA( LPCSTR lpszSrc, LPSTR lpszDst, DWORD cchDstLength )
	{
		_WINQ_FCONTEXT( "CUser32::OemToCharBuffA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( OemToCharBuffA );
		bResult = Call< BOOL, LPCSTR, LPSTR, DWORD >( pFunc, lpszSrc, lpszDst, cchDstLength );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	BOOL CUser32::OemToCharBuffW( LPCWSTR lpwszSrc, LPWSTR lpwszDst, DWORD cchDstLength )
	{
		_WINQ_FCONTEXT( "CUser32::OemToCharBuffW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( OemToCharBuffW );
		bResult = Call< BOOL, LPCWSTR, LPWSTR, DWORD >( pFunc, lpwszSrc, lpwszDst, cchDstLength );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	int CUser32::wvsprintfA( LPSTR lpOutput, LPCSTR lpFmt, va_list arglist )
	{
		_WINQ_FCONTEXT( "CUser32::wvsprintfA" );
		_WINQ_USESAPI( wvsprintfA );
		return Call< int, LPSTR, LPCSTR, va_list >( pFunc, lpOutput, lpFmt, arglist );
	}

	//--------------------------------------------------------------------------------
	int CUser32::wvsprintfW( LPWSTR lpOutput, LPCWSTR lpFmt, va_list arglist )
	{
		_WINQ_FCONTEXT( "CUser32::wvsprintfW" );
		_WINQ_USESAPI( wvsprintfW );
		return Call< int, LPWSTR, LPCWSTR, va_list >( pFunc, lpOutput, lpFmt, arglist );
	}

};//namespace nsWinQAPI
