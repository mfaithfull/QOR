//APQApplication.h

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

//QOR Application class

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef APPOCRITAQOR_APPLICATION_H_3
#define APPOCRITAQOR_APPLICATION_H_3

#include "CompilerQOR.h"

//------------------------------------------------------------------------------
namespace nsAppocrita
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __APPOCRITA ) CApplication
	{
	public:

		//------------------------------------------------------------------------------
		enum eRole
		{
			eService,
			eConsole,
			eOffice,
			eSysTray,
			eGame,
			eTool,
			eCOMServer,
		};

		CApplication( eRole Role = eOffice );		
		CApplication( const CApplication& src );
		virtual ~CApplication();

		void SetRole( eRole Role );

		int Run( void );//headless single threaded operation
		void Start( void );//headless multi threaded operation
		int RunUI( void );//Single threaded UI operation
		void StartUI( void );//Multi threaded UI operation

	protected:

		eRole m_Role;

	private:

		CApplication& operator = ( const CApplication& src );	//not to be implemented
	};

}//nsAppocrita

typedef nsAppocrita::CApplication CQORApplication;

#endif//APPOCRITAQOR_APPLICATION_H_3

