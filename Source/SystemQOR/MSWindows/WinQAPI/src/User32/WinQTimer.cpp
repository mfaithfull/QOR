//WinQTimer.cpp

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

//Timer functions

#include "WinQAPI/User32.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//--------------------------------------------------------------------------------
	BOOL CUser32::KillTimer( HWND hWnd, UINT_PTR uIDEvent )
	{
		_WINQ_FCONTEXT( "CUser32::KillTimer" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
		_WINQ_USESAPI( KillTimer );
		bResult = Call< BOOL, HWND, UINT_PTR >( pFunc, hWnd, uIDEvent );
		return bResult; 
	}

	//--------------------------------------------------------------------------------
	UINT_PTR CUser32::SetTimer( HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc )
	{
		_WINQ_FCONTEXT( "CUser32::SetTimer" );
		CCheckReturn< UINT_PTR, CCheckNonZero< UINT_PTR > >::TType Result;
		_WINQ_USESAPI( SetTimer );
		Result = Call< UINT_PTR, HWND, UINT_PTR, UINT, TIMERPROC >( pFunc, hWnd, nIDEvent, uElapse, lpTimerFunc );
		return Result;
	}

}//nsWinQAPI

