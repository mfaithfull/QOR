//WinQLTime.h

// Copyright Querysoft Limited 2013, 2017
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

//Win32 System Time

#ifndef WINQL_SYSTEM_TIME_H_3
#define WINQL_SYSTEM_TIME_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/Definitions/IO.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQL/CodeServices/WinQLSharedRef.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	struct SystemTime 
	{
		unsigned short wYear;
		unsigned short wMonth;
		unsigned short wDayOfWeek;
		unsigned short wDay;
		unsigned short wHour;
		unsigned short wMinute;
		unsigned short wSecond;
		unsigned short wMilliseconds;
	};

	//--------------------------------------------------------------------------------
	struct DynamicTimeZoneInformation
	{
		long Bias;
		wchar_t StandardName[ 32 ];
		nsWin32::SystemTime StandardDate;
		long StandardBias;
		wchar_t DaylightName[ 32 ];
		nsWin32::SystemTime DaylightDate;
		long DaylightBias;
		wchar_t TimeZoneKeyName[ 128 ];
		unsigned char DynamicDaylightTimeDisabled;
	};

	//--------------------------------------------------------------------------------
	struct TimeZoneInformation 
	{
		long Bias;
		wchar_t StandardName[ 32 ];
		nsWin32::SystemTime StandardDate;
		long StandardBias;
		wchar_t DaylightName[ 32 ];
		nsWin32::SystemTime DaylightDate;
		long DaylightBias;
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CTimeHelper
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CTimeHelper );

		CTimeHelper();
		CTimeHelper(const CTimeHelper&);
		CTimeHelper(CTimeHelper&&);
		CTimeHelper& operator = (const CTimeHelper&);
		CTimeHelper& operator = (CTimeHelper&&);
		virtual ~CTimeHelper();
		long CompareFileTime( const nsWin32::FILETIME* lpFileTime1, const nsWin32::FILETIME* lpFileTime2 ) const;
		bool DosDateTimeToFileTime( unsigned short wFatDate, unsigned short wFatTime, nsWin32::LPFILETIME lpFileTime ) const;
		bool FileTimeToDosDateTime( const nsWin32::FILETIME* lpFileTime, unsigned short* lpFatDate, unsigned short* lpFatTime ) const;
		bool FileTimeToLocalFileTime( const nsWin32::FILETIME* lpFileTime, nsWin32::LPFILETIME lpLocalFileTime ) const;
		bool FileTimeToSystemTime( const nsWin32::FILETIME* lpFileTime, nsWin32::SystemTime* lpSystemTime ) const;
		unsigned long GetDynamicTimeZoneInformation( nsWin32::DynamicTimeZoneInformation* pTimeZoneInformation ) const;
		bool GetFileTime( void* hFile, nsWin32::LPFILETIME lpCreationTime, nsWin32::LPFILETIME lpLastAccessTime, nsWin32::LPFILETIME lpLastWriteTime ) const;
		void GetLocalTime( nsWin32::SystemTime* lpSystemTime ) const;
		void GetSystemTime( nsWin32::SystemTime* lpSystemTime ) const;
		bool GetSystemTimeAdjustment( unsigned long* lpTimeAdjustment, unsigned long* lpTimeIncrement, int* lpTimeAdjustmentDisabled ) const;
		void GetSystemTimeAsFileTime( nsWin32::LPFILETIME lpSystemTimeAsFileTime ) const;
		bool GetSystemTimes( nsWin32::LPFILETIME lpIdleTime, nsWin32::LPFILETIME lpKernelTime, nsWin32::LPFILETIME lpUserTime ) const;
		unsigned long GetTickCount( void ) const;
		Cmp_unsigned_long_long GetTickCount64( void ) const;
		unsigned long GetTimeZoneInformation( nsWin32::TimeZoneInformation* lpTimeZoneInformation ) const;
		bool GetTimeZoneInformationForYear( unsigned short wYear, nsWin32::DynamicTimeZoneInformation* pdtzi, nsWin32::TimeZoneInformation* ptzi ) const;
		bool LocalFileTimeToFileTime( const nsWin32::FILETIME* lpLocalFileTime, nsWin32::LPFILETIME lpFileTime ) const;
		bool SetDynamicTimeZoneInformation( const nsWin32::DynamicTimeZoneInformation* lpTimeZoneInformation ) const;
		bool SetFileTime( void* hFile, const nsWin32::FILETIME* lpCreationTime, const nsWin32::FILETIME* lpLastAccessTime, const nsWin32::FILETIME* lpLastWriteTime ) const;
		bool SetLocalTime( const nsWin32::SystemTime* lpSystemTime ) const;
		bool SetSystemTime( const nsWin32::SystemTime* lpSystemTime ) const;
		bool SetSystemTimeAdjustment( unsigned long dwTimeAdjustment, bool bTimeAdjustmentDisabled ) const;
		bool SetTimeZoneInformation( const nsWin32::TimeZoneInformation* lpTimeZoneInformation ) const;
		bool SystemTimeToFileTime( const nsWin32::SystemTime* lpSystemTime, nsWin32::LPFILETIME lpFileTime ) const;
		bool SystemTimeToTzSpecificLocalTime( nsWin32::TimeZoneInformation* lpTimeZone, nsWin32::SystemTime* lpUniversalTime, nsWin32::SystemTime* lpLocalTime ) const;
		bool TzSpecificLocalTimeToSystemTime( nsWin32::TimeZoneInformation* lpTimeZoneInformation, nsWin32::SystemTime* lpLocalTime, nsWin32::SystemTime* lpUniversalTime ) const;
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CTime
	{

	public:

		typedef nsWin32::FILETIME CFileTime;

		__QOR_DECLARE_REF_TYPE(CTime);
		__QOR_DECLARE_OCLASS_ID( CTime );

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CClockTime : public nsWin32::SystemTime
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CClockTime );

			CClockTime(const CClockTime&);
			CClockTime(CClockTime&&);
			CClockTime( const SystemTime& Src );
			CClockTime( const CFileTime* pFileTime );
			CClockTime( unsigned short aYear = 0, unsigned short aMonth = 0, unsigned short aDayOfWeek = 0, unsigned short aDay = 0, unsigned short aHour = 0, unsigned short aMinute = 0, unsigned short aSecond = 0, unsigned short aMilliseconds = 0 );
			CClockTime& operator = (const CClockTime&);
			CClockTime& operator = (CClockTime&&);
			~CClockTime();

			unsigned short Year( void ) const;
			unsigned short Month( void ) const;
			unsigned short DayOfWeek( void ) const;
			unsigned short Day( void ) const;
			unsigned short Hour( void ) const;
			unsigned short Minute( void ) const;
			unsigned short Second( void ) const;
			unsigned short MilliSeconds( void ) const;

		protected:

			CTimeHelper m_Win32TimeHelper;
		} SystemTime;

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CUTCClock
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CUTCClock );

			//--------------------------------------------------------------------------------
			class __QOR_INTERFACE( __WINQL ) CAdjustment
			{
			public:

				__QOR_DECLARE_OCLASS_ID( CAdjustment );

				CAdjustment();
				CAdjustment(const CAdjustment&);
				CAdjustment(CAdjustment&&);
				CAdjustment& operator = (const CAdjustment&);
				CAdjustment& operator = (CAdjustment&&);
				~CAdjustment();

				bool Enabled( void );
				void Enable( bool bEnable );
				void Set( unsigned long dwAdjust );
				unsigned long Get( unsigned long* pdwIncrement );

			protected:

				bool GetSystemTimeAdjustment();
				bool SetSystemTimeAdjustment( bool bTimeAdjustmentDisabled );

			private:

				unsigned long m_dwTimeAdjust;
				unsigned long m_dwTimeIncrement;
				int m_bTimeAdjustDisabled;
				CTimeHelper m_Win32TimeHelper;
			}Adjustment;

			//--------------------------------------------------------------------------------

			CUTCClock();
			CUTCClock(const CUTCClock&);
			CUTCClock(CUTCClock&&);
			CUTCClock& operator = (const CUTCClock&);
			CUTCClock& operator = (CUTCClock&&);
			~CUTCClock();

			virtual CClockTime Time();
			virtual bool SetTime( CClockTime& NewTime );
			virtual CFileTime FileTime();

		protected:

			void GetLocalTime();
			void GetSystemTime();
			bool SetLocalTime( const CClockTime* pLocalTime );
			bool SetSystemTime( const CClockTime* pSystemTime );
			void GetSystemTimeAsFileTime( CFileTime* pSystemTimeAsFileTime );

			CClockTime m_ClockTime;
			CTimeHelper m_Win32TimeHelper;

		} UTCClock;

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CLocalClock : public CUTCClock
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CLocalClock );

			//--------------------------------------------------------------------------------
			class __QOR_INTERFACE( __WINQL ) CTimeZone
			{
			public:

				__QOR_DECLARE_OCLASS_ID( CTimeZone );

				CTimeZone();
				~CTimeZone();

				long GetBias( void );
				void SetBias( long lBias );
				long GetStandardBias( void );
				void SetStandardBias( long lStandardBias );
				long GetDaylightBias( void );
				void SetDaylightBias( long lDaylightBias );
				CWString GetStandardName( void );
				void SetStandardName( wchar_t* wszStandardName );
				CClockTime GetStandardDate( void );
				void SetStandardDate( CClockTime StandardDate );
				CWString GetDaylightName( void );
				void SetDaylightName( wchar_t* wszDaylightName );
				CClockTime GetDaylightDate( void );
				void SetDaylightDate( CClockTime DaylightDate );
				CWString GetTimeZoneKeyName( void );
				void SetTimeZoneKeyName( wchar_t* wszKeyName );
				unsigned char GetDynamicDaylightTimeDisabled( void );
				void SetDynamicDaylightTimeDisabled( unsigned char bDisabled );
    
			protected:

				bool SetTimeZoneInformation();
				unsigned long GetDynamicTimeZoneInformation();
				unsigned long GetTimeZoneInformation();
				bool SetDynamicTimeZoneInformation();

			private:

				DynamicTimeZoneInformation m_DynamicTimeZoneInfo;
				TimeZoneInformation m_TimeZoneInfo;
				CTimeHelper m_Win32TimeHelper;

			} TimeZone;

			//--------------------------------------------------------------------------------
			virtual CClockTime Time();
			virtual bool SetTime( CClockTime& NewTime );
			virtual CFileTime FileTime();

		protected:

		} LocalClock;

		//--------------------------------------------------------------------------------

		CTime();
		CTime(const CTime&);
		CTime(CTime&&);
		CTime& operator = (const CTime&);
		CTime& operator = (CTime&&);
		virtual ~CTime();
		bool GetSystemTimes( CFileTime* pIdleTime, CFileTime* pKernelTime, CFileTime* pUserTime ) const;
		unsigned long GetTickCount(void) const;
		Cmp_unsigned_long_long GetTickCount64(void) const;
		bool GetTimeZoneInformationForYear( unsigned short wYear, DynamicTimeZoneInformation* pdtzi, TimeZoneInformation* ptzi ) const;
		bool LocalFileTimeToFileTime( const CFileTime* pLocalFileTime, CFileTime* pFileTime ) const;
		bool SystemTimeToFileTime( const CClockTime* pSystemTime, CFileTime* pFileTime ) const;
		bool SystemTimeToTzSpecificLocalTime( TimeZoneInformation* pTimeZone, CClockTime* pUniversalTime, CClockTime* pLocalTime ) const;
		bool TzSpecificLocalTimeToSystemTime( TimeZoneInformation* pTimeZoneInformation, CClockTime* pLocalTime, CClockTime* pUniversalTime ) const;

		const CTimeHelper& Helper( void ) const;

	protected:

		CTimeHelper m_Win32TimeHelper;
	};

}//nsWin32

#endif//WINQL_SYSTEM_TIME_H_3
