//WinQLLSAPolicy.h

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

#ifndef WINQL_SECURITY_LSAPOLICY_H_3
#define WINQL_SECURITY_LSAPOLICY_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/CodeServices/Text/WinString.h"
#include "CodeQOR/DataStructures/TLinkedList.h"
#include "WinQLLUID.h"
#include "WinQL/Definitions/Security.h"
#include "WinQL/Definitions/Data.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CAdvAPI32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	struct UnicodeString 
	{
		unsigned short Length;
		unsigned short MaximumLength;
		wchar_t*  Buffer;
	};

	typedef UnicodeString LSAUnicodeString;

	//--------------------------------------------------------------------------------
	enum eTrustedInformationClass 
	{
		eTrustedDomainNameInformation = 1,
		eTrustedControllersInformation,
		eTrustedPosixOffsetInformation,
		eTrustedPasswordInformation,
		eTrustedDomainInformationBasic,
		eTrustedDomainInformationEx,
		eTrustedDomainAuthInformation,
		eTrustedDomainFullInformation,
		eTrustedDomainAuthInformationInternal,
		eTrustedDomainFullInformationInternal,
		eTrustedDomainInformationEx2Internal,
		eTrustedDomainFullInformation2Internal,
		eTrustedDomainSupportedEncryptionTypes,
	};

	//--------------------------------------------------------------------------------
	struct LSATrustInformation
	{
		LSAUnicodeString Name;
		void* Sid;
	};

	//--------------------------------------------------------------------------------
	struct LSAReferencedDomainList 
	{
		unsigned long Entries;
		LSATrustInformation* Domains;
	};

	//--------------------------------------------------------------------------------
	struct LSATranslatedSID 
	{
		SID_NAME_USE Use;
		unsigned long RelativeId;
		long DomainIndex;
	};

	//--------------------------------------------------------------------------------
	struct LSATranslatedSID2 
	{
		SID_NAME_USE Use;
		void* Sid;
		long DomainIndex;
		unsigned long Flags;
	};

	//--------------------------------------------------------------------------------
	struct LSATranslatedName 
	{
		SID_NAME_USE Use;
		LSAUnicodeString Name;
		long DomainIndex;
	};

	//--------------------------------------------------------------------------------
	struct ObjectAttributes
	{
		unsigned long Length;
		void* RootDirectory;
		UnicodeString* ObjectName;
		unsigned long Attributes;
		void* SecurityDescriptor;
		void* SecurityQualityOfService;
	};

	typedef ObjectAttributes LSAObjectAttributes;

	//--------------------------------------------------------------------------------
	struct TrustedDomainInformationEx
	{
		LSAUnicodeString Name;
		LSAUnicodeString FlatName;
		void* Sid;
		unsigned long TrustDirection;
		unsigned long TrustType;
		unsigned long TrustAttributes;
	};

	//--------------------------------------------------------------------------------
	struct TrustedPosixOffsetInfo
	{
		unsigned long Offset;
	};

	//--------------------------------------------------------------------------------
	struct LSAAuthInformation
	{
		LARGE_INTEGER LastUpdateTime;
		unsigned long AuthType;
		unsigned long AuthInfoLength;
		unsigned char* AuthInfo;
	};

	//--------------------------------------------------------------------------------
	struct TrustedDomainAuthInformation
	{
		unsigned long IncomingAuthInfos;
		LSAAuthInformation*   IncomingAuthenticationInformation;
		LSAAuthInformation*   IncomingPreviousAuthenticationInformation;
		unsigned long OutgoingAuthInfos;
		LSAAuthInformation*   OutgoingAuthenticationInformation;
		LSAAuthInformation*   OutgoingPreviousAuthenticationInformation;
	};

	//--------------------------------------------------------------------------------
	struct TrustedDomainFullInformation
	{
		TrustedDomainInformationEx   Information;
		TrustedPosixOffsetInfo       PosixOffset;
		TrustedDomainAuthInformation AuthInformation;
	};

	//--------------------------------------------------------------------------------
	struct LSAEnumerationInformation
	{
		void* Sid;
	};

	__QCMP_STATIC_CONSTANT( int, TrustAuthTypeNone		= 0 );   // Ignore this entry
	__QCMP_STATIC_CONSTANT( int, TrustAuthTypeNT4OWF	= 1 );   // NT4 OWF password
	__QCMP_STATIC_CONSTANT( int, TrustAuthTypeClear		= 2 );   // Cleartext password
	__QCMP_STATIC_CONSTANT( int, TrustAuthTypeVersion	= 3 );   // Cleartext password version number

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CLSAUnicodeStringArray
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CLSAUnicodeStringArray );
				
		CLSAUnicodeStringArray( nsWin32::LSAUnicodeString* pSrcArray, unsigned long ulCount );
		CLSAUnicodeStringArray( wchar_t** pStrArray, unsigned long ulCount );
		~CLSAUnicodeStringArray();
		operator nsWin32::LSAUnicodeString*( void );
		operator wchar_t**( void );

	private:

		nsWin32::LSAUnicodeString* m_pLSAArray;
		wchar_t** m_pStrArray;
		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;
		bool m_bFreeLSA;
		bool m_bFreeLSAArray;
        bool m_bFreeString;
		unsigned long m_ulCount;

		__QCS_DECLARE_NONCOPYABLE( CLSAUnicodeStringArray );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CLSAUnicodeString : public nsWin32::LSAUnicodeString
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CLSAUnicodeString );

		CLSAUnicodeString();
		CLSAUnicodeString( wchar_t* Str );
		CLSAUnicodeString( const nsWin32::LSAUnicodeString* pLSAString );
		~CLSAUnicodeString();
		operator wchar_t*( void );
		bool Orphan( nsWin32::LSAUnicodeString*& pString );

	private:

		bool m_bFree;
		nsWin32::LSAUnicodeString* m_pContainedString;
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CLSAPolicy
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CLSAPolicy );

		CLSAPolicy( wchar_t* strSystemName, unsigned long DesiredAccess );
		virtual ~CLSAPolicy();
		bool AddAccountRights( void* AccountSid, wchar_t** paRights, unsigned long CountOfRights );
		bool EnumerateAccountRights( void* AccountSid, nsCodeQOR::CTLinkedList< nsWin32::CWString::ref_type >& Rights );
		bool EnumerateAccountsWithUserRight( wchar_t* strRight, void** EnumerationBuffer, unsigned long* CountReturned );
		bool EnumerateTrustedDomains( unsigned long* EnumerationContext, void** Buffer, unsigned long PreferedMaximumLength, unsigned long* CountReturned );
		bool EnumerateTrustedDomainsEx( unsigned long* EnumerationContext, void** Buffer, unsigned long PreferredMaximumLength, unsigned long* CountReturned );
		bool FreeMemory( void* pMem );
		bool LookupNames( unsigned long Count, wchar_t** paNames, nsWin32::LSAReferencedDomainList** ReferencedDomains, nsWin32::LSATranslatedSID** Sids );
		bool LookupNames2( unsigned long Flags, unsigned long Count, wchar_t** paNames, nsWin32::LSAReferencedDomainList** ReferencedDomains, nsWin32::LSATranslatedSID2** Sids );
		bool LookupPrivilegeValueT( wchar_t* StrName, nsWin32::PLUID Value );
		bool LookupSids( unsigned long Count, void** Sids, nsWin32::LSAReferencedDomainList** ReferencedDomains, nsWin32::LSATranslatedName** Names );
		bool QueryTrustedDomainInfo( void* TrustedDomainSid, nsWin32::eTrustedInformationClass InformationClass, void** Buffer );
		bool QueryTrustedDomainInfoByName( wchar_t* StrTrustedDomainName, nsWin32::eTrustedInformationClass InformationClass, void** Buffer );
		bool RemoveAccountRights( void* AccountSid, unsigned char AllRights, wchar_t** paUserRights, unsigned long CountOfRights );
		bool RetrievePrivateData( wchar_t* StrKeyName, wchar_t** pStrPrivateData );
		bool SetTrustedDomainInfoByName( wchar_t* StrTrustedDomainName, nsWin32::eTrustedInformationClass InformationClass, void* Buffer );
		bool SetTrustedDomainInformation( void* TrustedDomainSid, nsWin32::eTrustedInformationClass InformationClass, void* Buffer );
		bool StorePrivateData( wchar_t* StrKeyName, wchar_t* StrPrivateData );
		void* Handle( void ) const;

	protected:

		CLSAPolicy();

		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;
		long m_Status;
		LSAObjectAttributes m_Attributes;
		void* m_PolicyHandle;

		__QCS_DECLARE_NONCOPYABLE( CLSAPolicy );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CLSATrustedDomain : public CLSAPolicy
	{
	public:
				
		__QOR_DECLARE_OCLASS_ID( CLSATrustedDomain );

		CLSATrustedDomain( const CLSAPolicy& src, wchar_t* StrTrustedDomainName, unsigned long DesiredAccess );
		CLSATrustedDomain( const CLSAPolicy& src, TrustedDomainInformationEx* TrustedDomainInformation, TrustedDomainAuthInformation* AuthenticationInformation, unsigned long DesiredAccess );
		virtual ~CLSATrustedDomain();
		void MakePersistent( bool bPersistent );

	protected:

		bool m_bPersistent;
		void* m_pSID;

	private:

		CLSATrustedDomain();
		__QCS_DECLARE_NONCOPYABLE( CLSATrustedDomain );
				
	};

}//nsWin32

#endif//WINQL_SECURITY_LSAPOLICY_H_3
