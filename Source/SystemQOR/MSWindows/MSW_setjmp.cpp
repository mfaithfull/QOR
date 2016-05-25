//MSW_setjmp.cpp

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

#include "SystemQOR/MSWindows/MSW_setjmp.h"
#include "WinQL/WinQL.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	Csetjmp::Csetjmp()
	{
		__QCS_MEMBER_FCONTEXT( "Csetjmp::Csetjmp" );
	}

	//--------------------------------------------------------------------------------
	Csetjmp::~Csetjmp()
	{
		__QCS_MEMBER_FCONTEXT( "Csetjmp::~Csetjmp" );
	}

	//--------------------------------------------------------------------------------
	int Csetjmp::setjmp( jmp_buf env )
	{
		_WINQ_FCONTEXT( "Csetjmp::setjmp" );
		///A call to setjmp() shall save the calling environment in its env argument 
		///for later use by longjmp().
		//TODO:
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csetjmp::sigsetjmp( sigjmp_buf env, int val )
	{
		//TODO:
		return -1;
	}

	//--------------------------------------------------------------------------------
	void Csetjmp::longjmp( jmp_buf env, int val )
	{
		_WINQ_FCONTEXT( "Csetjmp::longjmp" );
		//TODO:
	}

	//--------------------------------------------------------------------------------
	__QCMP_NORETURN void Csetjmp::siglongjmp( sigjmp_buf env, int val )
	{
		//TODO:
	}

}//nsWin32

#endif//(QOR_SYS_OS == QOR_SYS_MSW)
