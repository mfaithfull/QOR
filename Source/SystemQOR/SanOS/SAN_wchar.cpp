//SAN_wchar.cpp

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
#include <stdio.h>
#include <errno.h>
#include <limits.h>

#if		(QOR_SYS_OS == QOR_SYS_SANOS)

#include "SystemQOR/SanOS/SAN_wchar.h"
#include "SanQL/SanQL.h"

//#include "WinQL/CodeServices/ErrorSystem/Error.h"

//------------------------------------------------------------------------------
__QOR_IMPLEMENT_OCLASS_GUID( nsSanOS::Cwchar, 0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 )

//--------------------------------------------------------------------------------
namespace nsSanOS
{

	//--------------------------------------------------------------------------------
	int Cwchar::swprintf(wchar_t* s, size_t n, const wchar_t* format, ...)
	{
		//_WINQ_FCONTEXT( "Cwchar::swprintf" );
		int iResult = 0;
		//nsWin32::CTString Format( format, wcslen( format ) );
		//nsWin32::CTString Output( s, wcslen( s ) );
		//iResult = Output.Format( Format, vargs );
		return iResult;

	}

	//--------------------------------------------------------------------------------
	int Cwchar::wprintf( const wchar_t* format, va_list vargs )
	{
		//_WINQ_FCONTEXT( "Cwchar::wprintf" );
		int iResult = 0;
		if( format == 0 )
		{
			errno = EINVAL;
			iResult = -1;
		}
		else
		{
			/*
			::nsPosum::CStream Stream( 1 );
			iResult = Stream.Wprintf( format, vargs );
			*/
		}
		return iResult;
	}

	//--------------------------------------------------------------------------------
	size_t Cwchar::wcslen( const wchar_t* s )
	{
		//_WINQ_FCONTEXT( "Cwchar::wcslen" );
		size_t stResult = 0;
		if( s != 0 )
		{
			const wchar_t* pwchEOS = s;

			while( *pwchEOS++ ) ;

			stResult = static_cast< size_t >( pwchEOS - s - 1 );
		}
		return stResult;
	}

	//--------------------------------------------------------------------------------
	int Cwchar::_wcsicmp( const wchar_t* pStr1, const wchar_t* pStr2 )
	{
		//_WINQ_FCONTEXT("Cwchar::_wcsicmp" );
		return 0;
	}

}//nsSanOS


#endif//(QOR_SYS_OS == QOR_SYS_SANOS)

