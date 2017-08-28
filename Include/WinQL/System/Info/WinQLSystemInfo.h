//WinQLSystemInfo.h

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

//Win32 System Info

#ifndef WINQL_SYSINFO_H_2
#define WINQL_SYSINFO_H_2

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/codingmacros.h"
#include "WinQL/WinQL.h"
#include "WinQL/Definitions/Data.h"
#include "WinQL/CodeServices/Text/WinString.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CUser32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	enum eComputerNameFormat 
	{
		ComputerNameNetBIOS,
		ComputerNameDnsHostname,
		ComputerNameDnsDomain,
		ComputerNameDnsFullyQualified,
		ComputerNamePhysicalNetBIOS,
		ComputerNamePhysicalDnsHostname,
		ComputerNamePhysicalDnsDomain,
		ComputerNamePhysicalDnsFullyQualified,
		ComputerNameMax
	};

	//--------------------------------------------------------------------------------
	enum eComputerNameType
	{
		PrimaryComputerName,
		AlternateComputerNames,
		AllComputerNames
	};

	//--------------------------------------------------------------------------------
	enum eProductType
	{
		Product_Business =					0x00000006,
		Product_Business_N =				0x00000010,
		Product_Cluster_Server =			0x00000012,
		Product_DataCenter_Server =			0x00000008,
		Product_DataCenter_Server_Core =	0x0000000C,
		Product_DataCenter_Server_Core_V =	0000000027,
		Product_DataCenter_Server_V =		0x00000025,
		Product_Enterprise =				0x00000004,
		Product_Enterprise_E =				0x00000046,
		Product_Enterprise_N =				0x0000001B,
		Product_Enterprise_Server =			0x0000000A,
		Product_Enterprise_Server_Core =	0x0000000E,
		Product_Enterprise_Server_Core_V =	0x00000029,
		Product_Enterprise_Server_IA64 =	0x0000000F,
		Product_Enterprise_Server_V =		0x00000026,
		Product_Home_Basic =				0x00000002,
		Product_Home_Basic_E =				0x00000043,
		Product_Home_Basic_N =				0x00000005,
		Product_Home_Premium =				0x00000003,
		Product_Home_Premium_E =			0x00000044,
		Product_Home_Premium_N =			0x0000001A,
		Product_HyperV =					0x0000002A,
		Product_Med_Business_Server_Management =	0x0000001E,
		Product_Med_Business_Server_Messaging =		0x00000020,
		Product_Med_Business_Server_Security =		0x0000001F,
		Product_Professional =				0x00000030,
		Product_Professional_E =			0x00000045,
		Product_Professional_N =			0x00000031,
		Product_Server_For_Small_Business =	0x00000018,
		Product_Server_For_Small_Business_V =	0x00000023,
		Product_Server_Foundation =			0x00000021,
		Product_Home_Premium_Server =		0x00000022,
		Product_Small_Business_Solution_Server = 0x00000032,
		Product_Home_Server =				0x00000013,
		Product_Small_Business_Server =		0x00000009,
		Product_Solution_EmbeddedServer =	0x00000038,
		Product_Standard_Server =			0x00000007,
		Product_Standard_Server_Core =		0x0000000D,
		Product_Standard_Server_Core_V =	0x00000028,
		Product_Standard_Server_V =			0x00000024,
		Product_Starter =					0x0000000B,
		Product_Starter_E =					0x00000042,
		Product_Starter_N =					0x0000002F,
		Product_Storage_Enterprise_Server =	0x00000017,
		Product_Storage_Express_Server =	0x00000014,
		Product_Storage_Standard_Server =	0x00000015,
		Product_Storage_Workgroup_Server =	0x00000016,
		Product_Undefined =					0x00000000,
		Product_Ultimate =					0x00000001,
		Product_Ultimate_E =				0x00000047,
		Product_Ultimate_N =				0x0000001C,
		Product_Web_Server =				0x00000011,
		Product_Web_Server_Core =			0x0000001D,
	};

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) SystemInfo 
	{
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_NAMELESS_STRUCTUNION, "Deliberate use of Microsoft extension" )
		//--------------------------------------------------------------------------------
		union __QCMP_NAMELESS_STRUCT
		{
			unsigned long dwOemId;          // Obsolete field...do not use
			struct __QCMP_NAMELESS_STRUCT
			{
				unsigned short wProcessorArchitecture;
				unsigned short wReserved;
			} DUMMYSTRUCTNAME;
		} DUMMYUNIONNAME;

__QCMP_WARNING_POP

		unsigned long dwPageSize;
		void* lpMinimumApplicationAddress;
		void* lpMaximumApplicationAddress;
		Cmp_ulong_ptr dwActiveProcessorMask;
		unsigned long dwNumberOfProcessors;
		unsigned long dwProcessorType;
		unsigned long dwAllocationGranularity;
		unsigned short wProcessorLevel;
		unsigned short wProcessorRevision;
	};

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) OSVersionInfo
	{
		unsigned long dwOSVersionInfoSize;
		unsigned long dwMajorVersion;
		unsigned long dwMinorVersion;
		unsigned long dwBuildNumber;
		unsigned long dwPlatformId;
		TCHAR szCSDVersion[ 128 ];
	};

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) OSVersionInfoEx
	{
		unsigned long dwOSVersionInfoSize;
		unsigned long dwMajorVersion;
		unsigned long dwMinorVersion;
		unsigned long dwBuildNumber;
		unsigned long dwPlatformId;
		TCHAR szCSDVersion[ 128 ];
		unsigned short wServicePackMajor;
		unsigned short wServicePackMinor;
		unsigned short wSuiteMask;
		unsigned char wProductType;
		unsigned char wReserved;
	};

	//--------------------------------------------------------------------------------
	enum eLogicalProcessorRelationship
	{
		RelationProcessorCore,
		RelationNumaNode,
		RelationCache,
		RelationProcessorPackage,
		RelationGroup,
		RelationAll = 0xffff
	};

	//--------------------------------------------------------------------------------
	enum eProcessorCacheType
	{
		CacheUnified,
		CacheInstruction,
		CacheData,
		CacheTrace
	};

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) CacheDescriptor
	{
		unsigned char Level;
		unsigned char Associativity;
		unsigned short LineSize;
		unsigned long Size;
		eProcessorCacheType Type;
	};

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) SystemLogicalProcessorInformation 
	{
		Cmp_ulong_ptr ProcessorMask;
		eLogicalProcessorRelationship Relationship;
		union 
		{
			struct 
			{
				unsigned char Flags;
			} ProcessorCore;
			struct 
			{
				unsigned long NodeNumber;
			} NumaNode;
			CacheDescriptor Cache;
			Cmp_unsigned_long_long Reserved[ 2 ];
		} DUMMYUNIONNAME;
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CSystemInfoHelper
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CSystemInfoHelper );

		CSystemInfoHelper();
		CSystemInfoHelper( const CSystemInfoHelper& );
		CSystemInfoHelper& operator = ( const CSystemInfoHelper& );
		~CSystemInfoHelper();

		unsigned long ExpandEnvironmentStringsT( const TCHAR* lpSrc, TCHAR* lpDst, unsigned long nSize );

		bool DnsHostnameToComputerNameT( const TCHAR* Hostname, TCHAR* ComputerName, unsigned long* nSize );
		bool GetComputerNameT( TCHAR* lpBuffer, unsigned long* lpnSize );
		bool GetComputerNameExT( nsWin32::eComputerNameFormat NameType, TCHAR* lpBuffer, unsigned long* lpnSize );
		unsigned long EnumerateLocalComputerNames( int NameType, unsigned long ulFlags, void* lpBuffer, unsigned int nSize );
		bool SetComputerNameT( const TCHAR* szComputerName );
		bool SetComputerNameExT( nsWin32::eComputerNameFormat NameType, const TCHAR* szComputerName );

		unsigned int EnumSystemFirmwareTables( unsigned long FirmwareTableProviderSignature, void* pFirmwareTableBuffer, unsigned long BufferSize );
		unsigned long GetFirmwareEnvironmentVariableT( const TCHAR* lpName, const TCHAR* lpGuid, void* pBuffer, unsigned long nSize );
		unsigned int GetSystemFirmwareTable( unsigned long FirmwareTableProviderSignature, unsigned long FirmwareTableID, void* pFirmwareTableBuffer, unsigned long BufferSize );
		bool SetFirmwareEnvironmentVariableT( const TCHAR* lpName, const TCHAR* lpGuid, void* pBuffer, unsigned long nSize );

		void GetNativeSystemInfo( nsWin32::SystemInfo* lpSystemInfo );
		bool GetProductInfo( unsigned long dwOSMajorVersion, unsigned long dwOSMinorVersion, unsigned long dwSpMajorVersion, unsigned long dwSpMinorVersion, unsigned long* pdwReturnedProductType );
		unsigned long GetVersion( void );
		bool GetVersionExT( nsWin32::OSVersionInfo* lpVersionInfo );		
		void GetSystemInfo( nsWin32::SystemInfo* lpSystemInfo );
		bool VerifyVersionInfoT( nsWin32::OSVersionInfoEx* lpVersionInfo, unsigned long dwTypeMask, Cmp_unsigned_long_long dwlConditionMask );
		Cmp_unsigned_long_long VerSetConditionMask( Cmp_unsigned_long_long dwlConditionMask, unsigned long dwTypeBitMask, unsigned char dwConditionMask );

		CTString GetSystemDirectoryT( void );
		CTString GetWindowsDirectoryT( void );
		CTString GetSystemWindowsDirectoryT( void );
		CTString GetSystemWow64DirectoryT( void );
		bool GetSystemRegistryQuota( unsigned long* pdwQuotaAllowed, unsigned long* pdwQuotaUsed );

		bool IsProcessorFeaturePresent( eProcessorFeature ProcessorFeature );
		nsCodeQOR::CTLRef< nsWin32::SystemLogicalProcessorInformation > CSystemInfoHelper::GetLogicalProcessorInformation( unsigned int& uiCount );
		bool GetNumaAvailableMemoryNode( unsigned char Node, Cmp_unsigned_long_long* AvailableBytes );
		bool GetNumaHighestNodeNumber( unsigned long* HighestNodeNumber );
		bool GetNumaNodeProcessorMask( unsigned char Node, Cmp_unsigned_long_long* ProcessorMask );
		bool GetNumaProcessorNode( unsigned char Processor, unsigned char* NodeNumber );
		bool GetNumaProximityNode( unsigned long ProximityId, unsigned char* NodeNumber );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CSystemParameterHelper
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CSystemParameterHelper );

		CSystemParameterHelper();
		~CSystemParameterHelper();
		unsigned long GetColour( int nIndex );
		int GetMetrics( int nIndex );
		bool SetColors( int cElements, const int* lpaElements, const unsigned long* lpaRgbValues );
		bool ParametersInfo( unsigned int uiAction, unsigned int uiParam, void* pvParam, unsigned int fWinIni );

	private:

		nsWinQAPI::CUser32& m_User32Library;

		__QCS_DECLARE_NONCOPYABLE( CSystemParameterHelper );
	};

}//nsWin32

#endif//WINQL_SYSINFO_H_2
