//SanQLModuleBootstrap.h

// Copyright Querysoft Limited 2013.
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

//Defines a SanOS specific bootstrap object base class for EXEs and DLLs

#ifndef SANQL_MODULEBOOTSTRAP_H_1
#define SANQL_MODULEBOOTSTRAP_H_1

#include "CodeQOR/Modules/LoadableModuleBase.h"
//#include "SanQL/CodeServices/CriticalSection.h"

//--------------------------------------------------------------------------------
namespace nsSanOS
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __SANQL ) CModuleBootStrap
	{
	public:

		typedef void ( __QCMP_CALLCON* InitFunc)( void );

		void InitTerm( InitFunc* pfbegin, InitFunc* pfend );
		virtual void InitStatic( void ) = 0;

		int atexit( void (*pFunc)(void) );
		void doexit( void );

	protected:

		CModuleBootStrap();
		virtual ~CModuleBootStrap();

		bool m_bStaticInitialised;

	private:

		__QCMP_STATIC_CONSTANT( unsigned int, scui_AtExitPageSize = 20 );
		void* m_apAtExit[ scui_AtExitPageSize ];
		void** m_pAtExit;
		int m_iAtExitIndex;
	};

}//nsSanOS

#endif//SANQL_MODULEBOOTSTRAP_H_1

