//WinQLAppRestart.h

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

//Win32 Application Restart class

#ifndef WINQL_APPRESTART_H_2
#define WINQL_APPRESTART_H_2

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CAppRestart
	{

	public:

		typedef nsCodeQOR::CTLRef< CAppRestart > refType;

		__QOR_DECLARE_OCLASS_ID( CAppRestart );

		CAppRestart( const wchar_t* pwszCommandLine = _WTXT( "/restart" ), unsigned long ulFlags = 0 );
		~CAppRestart();

		long GetApplicationRestartSettings( void* hProcess, wchar_t* pwzCommandline, unsigned long* pcchSize, unsigned long* pdwFlags );

		refType Ref( void )
		{
			return refType( this );
		}

	protected:

		long RegisterApplicationRestart( const wchar_t* pwzCommandline, unsigned long dwFlags );
		long UnregisterApplicationRestart( void );

	};

}//nsWin32

#endif//WINQL_APPRESTART_H_2
