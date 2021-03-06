//Timer.h

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

//Win32 Window based Timer

#ifndef WINQL_OSSERV_TIMER_H_3
#define WINQL_OSSERV_TIMER_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/Definitions/Handles.h"
#include "WinQL/GUI/Window.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CUser32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	typedef void ( __QCMP_STDCALLCONVENTION *TimerCallback )( void*, unsigned int, Cmp_uint_ptr, unsigned long );

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CTimer
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CTimer );

		CTimer( COSWindow::refType Wnd, Cmp_uint_ptr nIDEvent, unsigned int uElapse, TimerCallback lpTimerFunc, bool* pbResult = 0 );
		~CTimer();
		void Reset( Cmp_uint_ptr nIDEvent, unsigned int uElapse, TimerCallback lpTimerFunc );

	protected:

		bool* m_pResult;
		COSWindow::refType m_Wnd;
		Cmp_uint_ptr m_uTimerId;

	private:			

		nsWinQAPI::CUser32& m_User32Library;

		CTimer();
		__QCS_DECLARE_NONCOPYABLE( CTimer );

	};

}//nsWin32

#endif//WINQL_OSSERV_TIMER_H_3

