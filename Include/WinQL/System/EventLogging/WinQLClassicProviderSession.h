//WinQLClassicProviderSession.h

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

//Win32 Event Tracing

#ifndef WINQL_OSSERV_EVTTRACE_CLASSPROVSESS_H_3
#define WINQL_OSSERV_EVTTRACE_CLASSPROVSESS_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Security.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CAdvAPI32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	typedef unsigned long( __QCMP_STDCALLCONVENTION *WMIDPRequest )( WMIDPRequestCode RequestCode, void* RequestContext, unsigned long* BufferSize, void* Buffer );

	//--------------------------------------------------------------------------------
	struct Trace_GUID_Registration
	{
		GUID const* Guid;            // Guid of data block being registered or updated.
		void* RegHandle;        // Guid Registration Handle is returned.
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CClassicEventProviderSession
	{
	public:

		CClassicEventProviderSession( WMIDPRequest RequestAddress, GUID const* ControlGuid, unsigned long GuidCount, Trace_GUID_Registration* TraceGuidReg, const TCHAR* MofImagePath, const TCHAR* MofResourceName );
		virtual ~CClassicEventProviderSession();

		virtual unsigned long HandleCallback( WMIDPRequestCode RequestCode, unsigned long* pBufferSize, void* pBuffer );
		virtual	unsigned long EnableEvents( void* pHeader );
		virtual	unsigned long DisableEvents( void* pHeader );

	protected:

		unsigned long m_ulEnableFlags; // Determines which class of events to log.
		unsigned char m_ucEnableLevel; // Determines the severity of events to log.
		bool m_bTrace;  // Used by the provider to determine whether it should log events.

	private:

		static unsigned long __QCMP_STDCALLCONVENTION Callback( WMIDPRequestCode RequestCode, void* RequestContext, unsigned long* BufferSize, void* Buffer );

		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;
		unsigned long m_ulStatus;
		Cmp_unsigned__int64 m_Registration;
		Cmp_unsigned__int64 m_Session;

		CClassicEventProviderSession();
		__QCS_DECLARE_NONCOPYABLE( CClassicEventProviderSession );
	};

}//nsWin32

#endif//WINQL_OSSERV_EVTTRACE_CLASSPROVSESS_H_3
