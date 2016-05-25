//WinQLEventLog.h

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

//Win32 Event Logging

#ifndef WINQL_SYSTEM_EVTLOG_H_3
#define WINQL_SYSTEM_EVTLOG_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/codingmacros.h"
#include "WinQL/WinQL.h"
#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/CodeServices/Handles/WinQLRAIISessionHandle.h"
#include "WinQL/CodeServices/WinQLSharedRef.h"
#include "WinQL/CodeServices/Text/WinString.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CAdvAPI32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{

	//--------------------------------------------------------------------------------
	//Use only as a base class for Event Log classes
	class __QOR_INTERFACE( __WINQL ) CEventLogAccess
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CEventLogAccess );

	protected:

		CEventLogAccess();
		virtual ~CEventLogAccess();

		bool Backup( const TCHAR* lpBackupFileName );
		bool Clear( const TCHAR* lpBackupFileName );
		bool GetInformation( unsigned long ulInfoLevel, void* lpBuffer, unsigned long cbBufSize, unsigned long* pcbBytesNeeded );
		bool GetNumberOfRecords( unsigned long* pNumberOfRecords );
		bool GetOldestRecord( unsigned long* pOldestRecord );
		bool NotifyChange( void* hEvent );
		bool Read( unsigned long ulReadFlags, unsigned long ulRecordOffset, void* pBuffer, unsigned long nNumberOfBytesToRead, unsigned long* pnBytesRead, unsigned long* pnMinNumberOfBytesNeeded );

		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;
		CRAIISessionHandle m_Handle;

		__QCS_DECLARE_NONCOPYABLE( CEventLogAccess );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CEventLogClient : public CEventLogAccess
	{
	public:

		typedef nsCodeQOR::CTLRef< CEventLogClient > refType;

		__QOR_DECLARE_OCLASS_ID( CEventLogClient );

		CEventLogClient( const TCHAR* UNCServerName, const TCHAR* SourceName );
		virtual ~CEventLogClient();

		//--------------------------------------------------------------------------------
		refType Ref( void )
		{
			return refType( this, false );
		}

	private:

		CEventLogClient();
		__QCS_DECLARE_NONCOPYABLE( CEventLogClient );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CBackupEventLog : public CEventLogAccess
	{
	public:

		typedef nsCodeQOR::CTLRef< CBackupEventLog > refType;

		__QOR_DECLARE_OCLASS_ID( CBackupEventLog );

		CBackupEventLog( const TCHAR* UNCServerName, const TCHAR* FileName );
		virtual ~CBackupEventLog();

		//--------------------------------------------------------------------------------
		refType Ref( void )
		{
			return refType( this, false );
		}

	private:

		CBackupEventLog();
		__QCS_DECLARE_NONCOPYABLE( CBackupEventLog );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CEventLogServer : public CEventLogAccess
	{
	public:

		typedef nsCodeQOR::CTLRef< CEventLogServer > refType;

		__QOR_DECLARE_OCLASS_ID( CEventLogServer );

		CEventLogServer( const TCHAR* UNCServerName, const TCHAR* lpSourceName );
		virtual ~CEventLogServer();

		bool Report( unsigned short wType, unsigned short wCategory, unsigned long dwEventID, void* lpUserSid, unsigned short wNumStrings, unsigned long dwDataSize, const TCHAR** lpStrings, void* lpRawData );

		//--------------------------------------------------------------------------------
		refType Ref( void )
		{
			return refType( this, false );
		}

	private:

		CEventLogServer();
		__QCS_DECLARE_NONCOPYABLE( CEventLogServer );		
		
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CEventLog
	{
		QOR_PP_WINQL_SHARED;

	public:

		__QOR_DECLARE_OCLASS_ID( CEventLog );

		CEventLog( const CTString& = CTString() );
		~CEventLog();

		CEventLogServer::refType Server( const CTString& strLogName );
		CBackupEventLog::refType Backup( const CTString& strFullFilePath );
		CEventLogClient::refType Client( const CTString& strLogName );

	private:

		CTString m_strUNCServerName;

		CEventLog( const CEventLog& );
		CEventLog& operator = ( const CEventLog& );
	};

}//nsWin32

#endif//WINQL_SYSTEM_EVTLOG_H_3

