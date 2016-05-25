//WinQLClassicControllerSession.h

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

#ifndef WINQL_OSSERV_EVTLOGGING_CLASSCTRLSESS_H_3
#define WINQL_OSSERV_EVTLOGGING_CLASSCTRLSESS_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Security.h"
#include "WinQL/Definitions/Data.h"
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
	enum Trace_Level
	{
		Trace_Level_None,
		Trace_Level_Critical,
		Trace_Level_Error,
		Trace_Level_Warning,
		Trace_Level_Information,
		Trace_Level_Verbose,
		Trace_Level_Reserved6,
		Trace_Level_Reserved7,
		Trace_Level_Reserved8,
		Trace_Level_Reserved9,
	};

	__QCMP_STATIC_CONSTANT( int, Event_Trace_Control_Query	= 0 );
	__QCMP_STATIC_CONSTANT( int, Event_Trace_Control_Stop	= 1 );
	__QCMP_STATIC_CONSTANT( int, Event_Trace_Control_Update	= 2 );
	__QCMP_STATIC_CONSTANT( int, Event_Trace_Control_Flush	= 3 );

	// Logger Mode flags
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_File_Mode_None          = 0x00000000 ); // Logfile is off
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_File_Mode_Sequential    = 0x00000001 ); // Log sequentially
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_File_Mode_Circular      = 0x00000002 ); // Log in circular manner
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_File_Mode_Append        = 0x00000004 ); // Append sequential log
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Real_Time_Mode          = 0x00000100 ); // Real time mode on
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Delay_Open_File_Mode    = 0x00000200 ); // Delay opening file
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Buffering_Mode          = 0x00000400 ); // Buffering mode only
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Private_Logger_Mode     = 0x00000800 ); // Process Private Logger
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Add_Header_Mode         = 0x00001000 ); // Add a logfile header
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Use_Global_Sequence     = 0x00004000 ); // Use global sequence no.
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Use_Local_Sequence      = 0x00008000 ); // Use local sequence no.
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Relog_Mode              = 0x00010000 ); // Relogger
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Use_Paged_Memory        = 0x01000000 ); // Use pageable buffers

	// Logger Mode flags on XP and above

	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_File_Mode_NewFile       = 0x00000008 ); // Auto-switch log file
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_File_Mode_Preallocate   = 0x00000020 ); // Pre-allocate mode

	// Logger Mode flags on Vista and above

	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_NonStoppable_Mode       = 0x00000040 ); // Session cannot be stopped (Autologger only)
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Secure_Mode             = 0x00000080 ); // Secure session
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Use_KBytes_For_Size     = 0x00002000 ); // Use KBytes as file size unit
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Private_In_Proc         = 0x00020000 ); // In process private logger
	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_Mode_Reserved           = 0x00100000 ); // Reserved bit, used to signal Heap/Critsec tracing

// Logger Mode flags on Win7 and above

	__QCMP_STATIC_CONSTANT( unsigned long, Event_Trace_No_Per_Procesor_Buffering     = 0x10000000 ); // Use this for low frequency sessions.

	//------------------------------------------------------------------------------
	typedef struct
	{
		unsigned long BufferSize;        // Size of entire buffer inclusive of this ULONG
		unsigned long ProviderId;    // Provider Id of driver returning this buffer
		union
		{
			Cmp_unsigned__int64 HistoricalContext;  // Logger use
			struct
			{
				unsigned long Version;           // Reserved
				unsigned long Linkage;           // Linkage field reserved for WMI
			} DUMMYSTRUCTNAME;

		} DUMMYUNIONNAME;

		union
		{
			unsigned long CountLost;        // Reserved
			void* KernelHandle;				// Kernel handle for data block
			LARGE_INTEGER TimeStamp;		// Timestamp as returned in units of 100ns
											// since 1/1/1601
		} DUMMYUNIONNAME2;

		GUID Guid;							// Guid for data block returned with results
		unsigned long ClientContext;
		unsigned long Flags;				// Flags, see below

	} WNode_Header;

	//--------------------------------------------------------------------------------
	typedef struct
	{
		WNode_Header Wnode;
	
		// data provided by caller
		unsigned long BufferSize;                   // buffer size for logging (kbytes)
		unsigned long MinimumBuffers;               // minimum to preallocate
		unsigned long MaximumBuffers;               // maximum buffers allowed
		unsigned long MaximumFileSize;              // maximum logfile size (in MBytes)
		unsigned long LogFileMode;                  // sequential, circular
		unsigned long FlushTimer;                   // buffer flush timer, in seconds
		unsigned long EnableFlags;                  // trace enable flags
		long  AgeLimit;								// unused

		// data returned to caller
		unsigned long NumberOfBuffers;              // no of buffers in use
		unsigned long FreeBuffers;                  // no of buffers free
		unsigned long EventsLost;                   // event records lost
		unsigned long BuffersWritten;               // no of buffers written to file
		unsigned long LogBuffersLost;               // no of logfile write failures
		unsigned long RealTimeBuffersLost;          // no of rt delivery failures
		void* LoggerThreadId;						// thread id of Logger
		unsigned long LogFileNameOffset;            // Offset to LogFileName
		unsigned long LoggerNameOffset;             // Offset to LoggerName
	} Event_Trace_Properties;

	//--------------------------------------------------------------------------------
	//Event tracing session class
	class __QOR_INTERFACE( __WINQL ) CClassicEventControllerSession
	{
	public:

		CClassicEventControllerSession( CTString& LogFilePath, CTString& LogSessionName, const GUID& SessionGuid, const GUID& ProviderGuid  );
		virtual ~CClassicEventControllerSession();

	private:

		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;
		CTString m_LogFilePath;
		CTString m_LogSessionName;
		unsigned long m_ulStatus;
		Cmp_unsigned__int64 m_SessionHandle;
		Event_Trace_Properties* m_pSessionProperties;
		unsigned long m_BufferSize;
		bool m_bTrace;
		const GUID& m_SessionGuid;
		const GUID& m_ProviderGuid;

		CClassicEventControllerSession();
		__QCS_DECLARE_NONCOPYABLE( CClassicEventControllerSession );
	};

}//nsWin32

#endif//WINQL_OSSERV_EVTLOGGING_CLASSCTRLSESS_H_3


