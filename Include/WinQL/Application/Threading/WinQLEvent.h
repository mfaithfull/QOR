//WinQLEvent.h

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

#ifndef WINQL_CS_EVENT_H_3
#define WINQL_CS_EVENT_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Security.h"
#include "WinQL/System/Info/WinQLSystemInfo.h"
#include "WinQL/CodeServices/Handles/WinQLSyncHandle.h"

//------------------------------------------------------------------------------
namespace nsWin32
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CEvent
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CEvent );

		__QCMP_STATIC_CONSTANT( unsigned long, _CREATE_EVENT_MANUAL_RESET    = 0x00000001 );
		__QCMP_STATIC_CONSTANT( unsigned long, _CREATE_EVENT_INITIAL_SET     = 0x00000002 );

		//------------------------------------------------------------------------------
		enum E_EVT_COPY_CONSTRUCT_OPTS
		{
			E_OPT_DEFAULT = 0,
			E_OPT_TRANSFER_HANDLE,
		};

		CEvent( SECURITY_ATTRIBUTES* lpEventAttributes = 0, const TCHAR* lpName = 0, unsigned long dwFlags = 0, unsigned long dwDesiredAccess = 0, bool* pbAlreadyExists = 0 );
		CEvent( unsigned long dwDesiredAccess, bool bInheritHandle, const TCHAR* lpName );
		CEvent( const CEvent& Src, E_EVT_COPY_CONSTRUCT_OPTS Opt = E_OPT_DEFAULT );
		CEvent( CSyncHandle& ExistingHandle );
		virtual ~CEvent();

		bool Pulse( void );
		bool Reset( void );
		bool Set( void );
		nsCodeQOR::CTCRef< CSyncHandle > Handle( void );
		unsigned long Wait( unsigned long dwMilliseconds, bool bAlertable = false );

	protected:

		bool m_bAlreadyExists;

	private:

		CSyncHandle m_Handle;

		CEvent& operator = ( const CEvent& );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CSessionEvent : public CEvent
	{
	public:

		CSessionEvent( TCHAR* pszName, SECURITY_ATTRIBUTES* pEventSecurity = 0, unsigned long dwFlags = 0, unsigned long dwAccessDesired = nsWin32::Event_All_Access );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CGlobalEvent : public CEvent
	{
	public:

		CGlobalEvent( TCHAR* pszName, SECURITY_ATTRIBUTES* pEventSecurity = 0, unsigned long dwFlags = 0, unsigned long dwAccessDesired = nsWin32::Event_All_Access );

	};

}//nsWin32

#endif//WINQL_CS_EVENT_H_3
