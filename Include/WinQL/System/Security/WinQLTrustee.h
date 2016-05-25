//WinQLTrustee.h

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

//Win32 Security Trustee

#ifndef WINQL_SECURITY_TRUSTEE_H_3
#define WINQL_SECURITY_TRUSTEE_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/CodingMacros.h"
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
	enum SeObjectType
	{
		SE_UNKNOWN_OBJECT_TYPE = 0,
		SE_FILE_OBJECT,
		SE_SERVICE,
		SE_PRINTER,
		SE_REGISTRY_KEY,
		SE_LMSHARE,
		SE_KERNEL_OBJECT,
		SE_WINDOW_OBJECT,
		SE_DS_OBJECT,
		SE_DS_OBJECT_ALL,
		SE_PROVIDER_DEFINED_OBJECT,
		SE_WMIGUID_OBJECT,
		SE_REGISTRY_WOW64_32KEY,
	};

	//--------------------------------------------------------------------------------
	struct ObjectsAndSID
	{
		unsigned long   ObjectsPresent;
		GUID    ObjectTypeGuid;
		GUID    InheritedObjectTypeGuid;
		SID* pSid;
	};

	//--------------------------------------------------------------------------------
	struct ObjectsAndName
	{
		unsigned long ObjectsPresent;
		SeObjectType ObjectType;
		TCHAR*    ObjectTypeName;
		TCHAR*    InheritedObjectTypeName;
		TCHAR*    ptstrName;
	};

	//--------------------------------------------------------------------------------
	enum TrusteeType
	{
		TRUSTEE_IS_UNKNOWN,
		TRUSTEE_IS_USER,
		TRUSTEE_IS_GROUP,
		TRUSTEE_IS_DOMAIN,
		TRUSTEE_IS_ALIAS,
		TRUSTEE_IS_WELL_KNOWN_GROUP,
		TRUSTEE_IS_DELETED,
		TRUSTEE_IS_INVALID,
		TRUSTEE_IS_COMPUTER
	};

	//--------------------------------------------------------------------------------
	enum TrusteeForm
	{
		TRUSTEE_IS_SID,
		TRUSTEE_IS_NAME,
		TRUSTEE_BAD_FORM,
		TRUSTEE_IS_OBJECTS_AND_SID,
		TRUSTEE_IS_OBJECTS_AND_NAME
	};

	//--------------------------------------------------------------------------------
	enum MultipleTrusteeOperation
	{
		NO_MULTIPLE_TRUSTEE,
		TRUSTEE_IS_IMPERSONATE,
	};

	//--------------------------------------------------------------------------------
	struct Trustee
	{
		struct Trustee*				pMultipleTrustee;
		MultipleTrusteeOperation	MultipleTrusteeOperation;
		TrusteeForm                 Form;
		TrusteeType                 Type;
		TCHAR*                      ptstrName;
	};

	bool operator == ( const Trustee& T1, const Trustee& T2 );

	//--------------------------------------------------------------------------------
	/*A trustee is the user account, group account, or logon session to which an access 
	control entry (ACE) applies. Each ACE in an access control list (ACL) has one 
	security identifier (SID) that identifies a trustee.*/
	class __QOR_INTERFACE( __WINQL ) CTrustee : public nsWin32::Trustee
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CTrustee );
				
		CTrustee( TCHAR* pName );
		CTrustee( void* pSid );
		CTrustee( nsWin32::ObjectsAndName* pObjName, nsWin32::SeObjectType ObjectType, TCHAR* ObjectTypeName, TCHAR* InheritedObjectTypeName, TCHAR* Name );
		CTrustee( nsWin32::ObjectsAndSID* pObjSid, nsWin32::GUID* pObjectGuid, nsWin32::GUID* pInheritedObjectGuid, void* pSid );
		virtual ~CTrustee();
		TrusteeForm Form( void );
		bool GetData( void** ppData );
		bool GetData( nsWin32::ObjectsAndName** ppObjectsAndName );
		bool GetSid( void** ppSid );
		bool GetData( nsWin32::ObjectsAndSID** ppObjectsAndSid );
		TCHAR* Name( void );
		nsWin32::TrusteeType Type( void );

	private:

		nsWinQAPI::CAdvAPI32& m_AdvAPI32Library;

		__QCS_DECLARE_NONCOPYABLE( CTrustee );

	};

}//nsWin32

#endif//WINQL_SECURITY_TRUSTEE_H_3
