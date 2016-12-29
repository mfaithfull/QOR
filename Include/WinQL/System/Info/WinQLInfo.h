//WinQLInfo.h

// Copyright Querysoft Limited 2015
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

//System Info object

#ifndef WINQL_SYSTEM_INFO_H_3
#define WINQL_SYSTEM_INFO_H_3

#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/Application/ErrorSystem/WinQLErrorSystem.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQL/System/Info/WinQLSystemInfo.h"
#include "WinQL/CodeServices/WinQLSharedRef.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CSystemInfo
	{

		QOR_PP_WINQL_SHARED;

	public:
		
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_BuildNumber		= 0x00000004 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_MajorVersion		= 0x00000002 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_MinorVersion		= 0x00000001 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_PlatformId		= 0x00000008 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_ServicePackMajor	= 0x00000020 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_ServicePackMinor	= 0x00000010 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_SuitName			= 0x00000040 );
		__QCMP_STATIC_CONSTANT( unsigned long, Ver_ProductType		= 0x00000080 );

		__QOR_DECLARE_OCLASS_ID( CSystemInfo );

		//--------------------------------------------------------------------------------
		//Access System metrics and colours
		class __QOR_INTERFACE( __WINQL ) CParameters
		{

			__QOR_DECLARE_OCLASS_ID( CParameters );

		public:

			//--------------------------------------------------------------------------------
			CParameters()
			{
			}

			//--------------------------------------------------------------------------------
			CParameters( const CParameters& src )
			{
			}

			//--------------------------------------------------------------------------------
			CParameters& operator = ( const CParameters& src )
			{
				return *this;
			}

			//--------------------------------------------------------------------------------
			~CParameters()
			{
			}

			//--------------------------------------------------------------------------------
			//Return the Colour value of the indicated system colour
			unsigned long GetColour( int nIndex )
			{
				unsigned long dwResult = m_Win32SysParams.GetColour( nIndex );
				return dwResult;
			}

			//--------------------------------------------------------------------------------
			//Return the indicated system metric
			int GetMetrics( int nIndex )
			{
				return m_Win32SysParams.GetMetrics( nIndex );
			}
	
		private:

			CSystemParameterHelper m_Win32SysParams;
		};

		CSystemInfo();
		CSystemInfo( const CSystemInfo& src );
		CSystemInfo& operator = ( const CSystemInfo& src );
		virtual ~CSystemInfo();

		bool IsWindows98orME();																			//Returns true if running on Windows 98 or Windows Missing Edition
		unsigned long GetMajorVersion();																//Returns Windows major version number
		unsigned long GetMinorVersion();																//Returns Window minor version number
		unsigned long GetBuild();																		//Returns Windows Build Number
		unsigned int GetOSVerNumber( void );															//Return Windows Version Number;
		unsigned long GetVersion(void);																	//Returns packed Windows version number
		void GetNativeSystemInfo( SystemInfo* lpSystemInfo );											//Fill out supplied structure with System information
		void GetSystemInfo( SystemInfo* lpSystemInfo );													//Fill out supplied structure with System information
		bool GetVersionExT( OSVersionInfo* lpVersionInfo );												//Fill out supplied structure with Version information
		eProductType GetProductInfo( unsigned long dwOSMajorVersion, unsigned long dwOSMinorVersion, unsigned long dwSpMajorVersion, unsigned long dwSpMinorVersion );		//Return the product type e.g. Home Premium or Enterprise Server
		bool VerifyVersionInfo( OSVersionInfoEx& VersionInfo, unsigned long ulTypeMask, Cmp_unsigned_long_long ullConditionMask );		//Verify that the OS version meets the specified requirements
		Cmp_unsigned_long_long VerSetConditionMask( Cmp_unsigned_long_long ullConditionMask, unsigned long ulTypeBitMask, unsigned char ucConditionMask );		//Setup a condition mask for calling VerifyVersionInfo
		CParameters& Parameters();																		//Retruns object for accessing system metrics and colour values
		CTString ExpandEnvironmentStrings( const TCHAR* lpSrc );										//Return an evironemnt string with variables expanded
		CTString GetComputerName( void );																//Return the local machine name
		CTString GetComputerNameEx( eComputerNameFormat NameType );										//Return the requested type of Computer name
		bool SetComputerName( const TCHAR* lpComputerName );											//Set the local machine name
		bool SetComputerNameEx( eComputerNameFormat NameType, const TCHAR* lpBuffer );					//Sets a new NetBIOS or DNS name for the local computer
		
		//NOTE: This API is mising or broken, nothing will be returned
		CTString EnumerateLocalComputerNames( eComputerNameType NameType, unsigned long ulFlags, unsigned long& ulNameCount, unsigned int& uiCharCount );		//Get the names of local computers or just this computer or both
		CTString DnsHostnameToComputerName( const TCHAR* Hostname );									//Return the NetBIOS name of the Computer given its DnsHostname
		nsCodeQOR::CTLRef< byte > GetSystemFirmwareTable( unsigned long FirmwareTableProviderSignature, unsigned long FirmwareTableID, unsigned int& uiByteCount );
		nsCodeQOR::CTLRef< byte > EnumSystemFirmwareTables( unsigned long FirmwareTableProviderSignature, unsigned int& uiByteCount );		//Enumerate System Firmware Tables
		nsCodeQOR::CTLRef< byte > EnumSystemFirmwareTablesFIRM( unsigned int& uiByteCount );			//Enumerate Raw Firmware Tables
		nsCodeQOR::CTLRef< unsigned long > EnumSystemFirmwareTablesACPI( unsigned int& uiTableCount );		//Enumerate ACPI Firmware Tables
		nsCodeQOR::CTLRef< byte > EnumSystemFirmwareTablesRSMB( unsigned int& uiByteCount );			//Enumerate raw SMBIOS Firmware Tables
		unsigned long GetFirmwareEnvironmentVariable( const TCHAR* lpName, const TCHAR* lpGuid, void* pBuffer, unsigned long nSize );		//Get the value of a firmware environment variable
		bool SetFirmwareEnvironmentVariable( const TCHAR* lpName, const TCHAR* lpGuid, void* pBuffer, unsigned long nSize );		//Set the value of a firmware environment variable
		CTString GetSystemDirectory( void );															//Return the Windows System Directory path
		CTString GetSystemWindowsDirectory( void );														//Return the path of the shared Windows directory on a multi-user system.
		CTString GetSystemWow64Directory( void );														//Return the path of the system directory used by WOW64. This directory is not present on 32-bit Windows.
		CTString GetWindowsDirectory( void );															//Return the Windows Directory
		void GetSystemRegistryQuota( unsigned long& ulQuotaAllowed, unsigned long& ulQuotaUsed );		//Get the maximum and current size of the Registry
		bool IsProcessorFeaturePresent( eProcessorFeature ProcessorFeature );							//Returns whether the specified processor feature is supported.
		nsCodeQOR::CTLRef< SystemLogicalProcessorInformation > GetLogicalProcessorInformation( unsigned int& uiCount );		//Returns an array of descriptors of logical processors and related hardware.
		Cmp_unsigned_long_long GetNumaAvailableMemoryNode( Cmp_unsigned__int8 uiNode );					//Return the amount of memory available in the specified node. 
		unsigned long GetNumaHighestNodeNumber();														//Returns the node that currently has the highest number.
		Cmp_unsigned_long_long GetNumaNodeProcessorMask( Cmp_unsigned__int8 uiNode );					//Returns the processor mask for the specified node. 
		Cmp_unsigned__int8 GetNumaProcessorNode( Cmp_unsigned__int8 uiProcessor );						//Returns the node number for the specified processor.
		Cmp_unsigned__int8 GetNumaProximityNode( unsigned long ulProximityId );							//Returns the NUMA node number that corresponds to the specified proximity domain identifier.

	private:

		void AcquireVersion( void );

		bool m_bAcquiredVersion;
		bool m_bWin9x;
		unsigned long m_dwMajorVersion;
		unsigned long m_dwMinorVersion;
		unsigned long m_dwBuild;
		CParameters m_Parameters;
		CSystemInfoHelper m_Win32SysInfo;			

	};

}//nsWin32

#endif//WINQL_SYSTEM_INFO_H_3