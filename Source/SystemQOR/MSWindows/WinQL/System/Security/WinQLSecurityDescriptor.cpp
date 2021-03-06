//WinQLSecurityDescriptor.cpp

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

#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/System/Security/WinQLSecurityDescriptor.h"
#include "WinQAPI/AdvAPI32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace ::nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CSecurityDescriptor );

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor() : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{		
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = reinterpret_cast< PSECURITY_DESCRIPTOR >( CKernel32::LocalAlloc( LMEM_ZEROINIT, SECURITY_DESCRIPTOR_MIN_LENGTH ) );
		m_bPrivateFree = false;
		m_bLocalFree = true;					
		Initialize( SECURITY_DESCRIPTOR_REVISION );
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( const CSecurityDescriptor& src ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = src.m_pDescriptor;
		m_bLocalFree = false;
		m_bPrivateFree = false;
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( void* pDescriptor, bool bTemp ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = pDescriptor;
		m_bLocalFree = bTemp;
		m_bPrivateFree = false;
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( void* ParentDescriptor, void* CreatorDescriptor, 
		bool IsDirectoryObject, void* Token, nsWin32::GenericMapping* GenericMapping ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		m_bLocalFree = false;
		bool bResult = m_AdvAPI32Library.CreatePrivateObjectSecurity( ParentDescriptor, 
			CreatorDescriptor, &m_pDescriptor, IsDirectoryObject ? TRUE : FALSE, Token, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ) ) ? true : false;
		if( bResult )
		{						
			m_bPrivateFree = true;
		}
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( void* ParentDescriptor, void* CreatorDescriptor, nsWin32::GUID* ObjectType, bool IsContainerObject, unsigned long AutoInheritFlags, void* Token, nsWin32::GenericMapping* GenericMapping ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		m_bLocalFree = false;
		m_bPrivateFree = false;
		bool bResult = m_AdvAPI32Library.CreatePrivateObjectSecurityEx( ParentDescriptor, 
			CreatorDescriptor, &m_pDescriptor, reinterpret_cast< ::GUID* >( ObjectType ), IsContainerObject, AutoInheritFlags, 
			Token, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ) ) ? true : false;
		if( bResult )
		{						
			m_bPrivateFree = true;
		}
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( void* ParentDescriptor, void* CreatorDescriptor, nsWin32::GUID** ObjectTypes, unsigned long GuidCount, bool IsContainerObject, unsigned long AutoInheritFlags, 
		void* Token, nsWin32::GenericMapping* GenericMapping ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		m_bLocalFree = false;
		m_bPrivateFree = false;
		bool bResult= m_AdvAPI32Library.CreatePrivateObjectSecurityWithMultipleInheritance( 
			ParentDescriptor, CreatorDescriptor, &m_pDescriptor, reinterpret_cast< ::GUID** >( ObjectTypes ), GuidCount, 
			IsContainerObject, AutoInheritFlags, Token, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ) ) ? true : false;
		if( bResult )
		{
			m_bPrivateFree = true;
		}
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( nsWin32::Trustee* pOwner, nsWin32::Trustee* pGroup, unsigned long cCountOfAccessEntries, 
		nsWin32::ExplicitAccess* pListOfAccessEntries, unsigned long cCountOfAuditEntries, 
		nsWin32::ExplicitAccess* pListOfAuditEntries, void* pOldSD, unsigned long* pSizeNewSD ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		DWORD dwResult = m_AdvAPI32Library.BuildSecurityDescriptor( 
			reinterpret_cast< ::PTRUSTEE >( pOwner ), reinterpret_cast< ::PTRUSTEE >( pGroup ), cCountOfAccessEntries, 
			reinterpret_cast< ::PEXPLICIT_ACCESS >( pListOfAccessEntries ), cCountOfAuditEntries, 
			reinterpret_cast< ::PEXPLICIT_ACCESS >( pListOfAuditEntries ), pOldSD, pSizeNewSD, &m_pDescriptor );
		if( dwResult == ERROR_SUCCESS )
		{
			m_bLocalFree = true;
			m_bPrivateFree = false;
		}
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( void* handle, nsWin32::SeObjectType ObjectType, unsigned long SecurityInfo, 
		void** ppsidOwner, void** ppsidGroup, nsWin32::AccessControlList** ppDacl, nsWin32::AccessControlList** ppSacl ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		m_bLocalFree = true;
		m_bPrivateFree = false;
		m_AdvAPI32Library.GetSecurityInfo( handle, static_cast< ::SE_OBJECT_TYPE >( ObjectType ), SecurityInfo, ppsidOwner, ppsidGroup, 
			reinterpret_cast< ::PACL* >( ppDacl ), reinterpret_cast< ::PACL* >( ppSacl ), &m_pDescriptor );
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( const TCHAR* pObjectName, nsWin32::SeObjectType ObjectType, unsigned long SecurityInfo, void** ppsidOwner, void** ppsidGroup, nsWin32::AccessControlList** ppDacl, nsWin32::AccessControlList** ppSacl ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		m_bLocalFree = true;
		m_bPrivateFree = false;
		m_AdvAPI32Library.GetNamedSecurityInfo( pObjectName, static_cast< ::SE_OBJECT_TYPE >( ObjectType ), SecurityInfo, ppsidOwner, ppsidGroup, reinterpret_cast< ::PACL* >( ppDacl ), reinterpret_cast< ::PACL* >( ppSacl ), &m_pDescriptor );
	}

	//--------------------------------------------------------------------------------
	/*
	CSecurityDescriptor::CSecurityDescriptor( LPCTSTR lpObjectName, SeObjectType objectType, SECURITY_INFORMATION securityInfo,
					LPCTSTR lpProvider, LPCTSTR lpProperty, PACTRL_ACCESS* ppAccessList, 
					PACTRL_AUDIT* ppAuditList, LPTSTR* lppOwner, LPTSTR* lppGroup )
	{
		m_pDescriptor = 0;
		m_bLocalFree = true;
		m_AdvAPI32Library.GetNamedSecurityInfoEx( lpObjectName, objectType, securityInfo, lpProvider,
			lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup );
	}
	*/

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::CSecurityDescriptor( const TCHAR* StringSecurityDescriptor, unsigned long StringSDRevision ) : m_AdvAPI32Library( CAdvAPI32::Instance() )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::CSecurityDescriptor" );
		m_pDescriptor = 0;
		m_bLocalFree = true;
		m_bPrivateFree = false;
		m_AdvAPI32Library.ConvertStringSecurityDescriptorToSecurityDescriptor( 
			StringSecurityDescriptor, StringSDRevision, &m_pDescriptor, 0 );
	}

	//--------------------------------------------------------------------------------
	CSecurityDescriptor::~CSecurityDescriptor()
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::~CSecurityDescriptor" );
		if( m_bLocalFree )
		{
			CKernel32::LocalFree( reinterpret_cast< HLOCAL >( m_pDescriptor ) );
		}
		else if( m_bPrivateFree )
		{
			m_AdvAPI32Library.DestroyPrivateObjectSecurity( &m_pDescriptor );
		}
	}

	//--------------------------------------------------------------------------------
	TCHAR* CSecurityDescriptor::ToString ( unsigned long SecurityInformation )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::operator LPTSTR" );
		LPTSTR StringSecurityDescriptor = 0;
		DWORD RequestedStringSDRevision = SDDL_REVISION_1;
		m_AdvAPI32Library.ConvertSecurityDescriptorToStringSecurityDescriptor( 
			this, RequestedStringSDRevision, SecurityInformation, &StringSecurityDescriptor, 0 );
		return StringSecurityDescriptor;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheck( void* ClientToken, unsigned long DesiredAccess, nsWin32::GenericMapping* GenericMapping, nsWin32::PPRIVILEGE_SET PrivilegeSet, 
		unsigned long* PrivilegeSetLength, unsigned long* GrantedAccess, int* AccessStatus )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheck" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheck( m_pDescriptor, ClientToken, DesiredAccess, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ),
				reinterpret_cast< ::PPRIVILEGE_SET >( PrivilegeSet ), PrivilegeSetLength, GrantedAccess, AccessStatus ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheckAndAuditAlarmT( const TCHAR* SubsystemName, void* HandleId, TCHAR* ObjectTypeName, TCHAR* ObjectName,
		unsigned long DesiredAccess, nsWin32::GenericMapping* GenericMapping, bool ObjectCreation, unsigned long* GrantedAccess, int* AccessStatus, int* pfGenerateOnClose )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheckAndAuditAlarm" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheckAndAuditAlarm( SubsystemName, HandleId, 
				ObjectTypeName, ObjectName, m_pDescriptor, DesiredAccess, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), 
				ObjectCreation ? TRUE : FALSE, GrantedAccess, AccessStatus, pfGenerateOnClose ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheckByType( void* PrincipalSelfSid, void* ClientToken, unsigned long DesiredAccess, nsWin32::ObjectTypeList* ObjectTypeList, unsigned long ObjectTypeListLength,
		nsWin32::GenericMapping* GenericMapping, nsWin32::PPRIVILEGE_SET PrivilegeSet, unsigned long* PrivilegeSetLength, unsigned long* GrantedAccess, int* AccessStatus )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheckByType" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheckByType( m_pDescriptor, PrincipalSelfSid, 
				ClientToken, DesiredAccess, reinterpret_cast< ::POBJECT_TYPE_LIST >( ObjectTypeList ), ObjectTypeListLength, 
				reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), reinterpret_cast< ::PPRIVILEGE_SET >( PrivilegeSet ), PrivilegeSetLength, GrantedAccess, AccessStatus ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheckByTypeAndAuditAlarmT( const TCHAR* SubsystemName, void* HandleId, const TCHAR* ObjectTypeName, const TCHAR* ObjectName, 
		void* PrincipalSelfSid, unsigned long DesiredAccess, nsWin32::AuditEventType AuditType, unsigned long Flags, nsWin32::ObjectTypeList* ObjectTypeList, 
		unsigned long ObjectTypeListLength, nsWin32::GenericMapping* GenericMapping, bool ObjectCreation, unsigned long* GrantedAccess, int* AccessStatus, int* pfGenerateOnClose )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheckByTypeAndAuditAlarm" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheckByTypeAndAuditAlarm( SubsystemName, HandleId, ObjectTypeName, ObjectName, m_pDescriptor, PrincipalSelfSid, 
				DesiredAccess, static_cast< ::AUDIT_EVENT_TYPE >( AuditType ), Flags, reinterpret_cast< ::POBJECT_TYPE_LIST >( ObjectTypeList ), 
				ObjectTypeListLength, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), ObjectCreation ? TRUE : FALSE, GrantedAccess, AccessStatus, pfGenerateOnClose ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheckByTypeResultList( void* PrincipalSelfSid, void* ClientToken, unsigned long DesiredAccess, nsWin32::ObjectTypeList* ObjectTypeList, 
		unsigned long ObjectTypeListLength, nsWin32::GenericMapping* GenericMapping, nsWin32::PPRIVILEGE_SET PrivilegeSet, unsigned long* PrivilegeSetLength, unsigned long* GrantedAccessList,
		unsigned long* AccessStatusList )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheckByTypeResultList" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheckByTypeResultList( m_pDescriptor, PrincipalSelfSid, ClientToken, DesiredAccess, 
				reinterpret_cast< ::POBJECT_TYPE_LIST >( ObjectTypeList ), ObjectTypeListLength, 
				reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), reinterpret_cast< ::PPRIVILEGE_SET >( PrivilegeSet ), PrivilegeSetLength,
				GrantedAccessList, AccessStatusList ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheckByTypeResultListAndAuditAlarmT( const TCHAR* SubsystemName, void* HandleId, const TCHAR* ObjectTypeName, const TCHAR* ObjectName, void* PrincipalSelfSid, unsigned long DesiredAccess, 
		nsWin32::AuditEventType AuditType, unsigned long Flags, nsWin32::ObjectTypeList* ObjectTypeList, unsigned long ObjectTypeListLength, 
		nsWin32::GenericMapping* GenericMapping, bool ObjectCreation, unsigned long* GrantedAccess, unsigned long* AccessStatusList, int* pfGenerateOnClose )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheckByTypeResultListAndAuditAlarm" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheckByTypeResultListAndAuditAlarm( SubsystemName, HandleId, ObjectTypeName, ObjectName, m_pDescriptor, 
				PrincipalSelfSid, DesiredAccess, static_cast< ::AUDIT_EVENT_TYPE >( AuditType ), Flags, 
				reinterpret_cast< ::POBJECT_TYPE_LIST >( ObjectTypeList ), ObjectTypeListLength, 
				reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), ObjectCreation ? TRUE : FALSE, GrantedAccess, AccessStatusList, pfGenerateOnClose ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::AccessCheckByTypeResultListAndAuditAlarmByHandleT( const TCHAR* SubsystemName, void* HandleId, void* ClientToken, const TCHAR* ObjectTypeName,
		const TCHAR* ObjectName, void* PrincipalSelfSid, unsigned long DesiredAccess, nsWin32::AuditEventType AuditType, unsigned long Flags,
		nsWin32::ObjectTypeList* ObjectTypeList, unsigned long ObjectTypeListLength, nsWin32::GenericMapping* GenericMapping, bool ObjectCreation, 
		unsigned long* GrantedAccess, unsigned long* AccessStatusList, int* pfGenerateOnClose )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::AccessCheckByTypeResultListAndAuditAlarmByHandle" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.AccessCheckByTypeResultListAndAuditAlarmByHandle( SubsystemName, HandleId, ClientToken, ObjectTypeName, ObjectName, 
				m_pDescriptor, PrincipalSelfSid, DesiredAccess, static_cast< ::AUDIT_EVENT_TYPE >( AuditType ), Flags, 
				reinterpret_cast< ::POBJECT_TYPE_LIST >( ObjectTypeList ), ObjectTypeListLength, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ),
				ObjectCreation ? TRUE : FALSE, GrantedAccess, AccessStatusList, pfGenerateOnClose ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CSecurityDescriptor::Build( nsWin32::Trustee* pOwner, nsWin32::Trustee* pGroup, unsigned long cCountOfAccessEntries, 
		nsWin32::ExplicitAccess* pListOfAccessEntries, unsigned long cCountOfAuditEntries, 
		nsWin32::ExplicitAccess* pListOfAuditEntries, unsigned long* pSizeNewSD )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::Build" );
		PSECURITY_DESCRIPTOR pNewSD = 0;
        DWORD dwResult = 0;
        __QOR_PROTECT
        {
			dwResult = m_AdvAPI32Library.BuildSecurityDescriptor( reinterpret_cast< ::PTRUSTEE >( pOwner ), reinterpret_cast< ::PTRUSTEE >( pGroup ), 
				cCountOfAccessEntries, reinterpret_cast< ::PEXPLICIT_ACCESS >( pListOfAccessEntries ), cCountOfAuditEntries, 
				reinterpret_cast< ::PEXPLICIT_ACCESS >( pListOfAuditEntries ), m_pDescriptor, pSizeNewSD, &pNewSD );
			if( dwResult == ERROR_SUCCESS )
			{
				m_pDescriptor = pNewSD;
				m_bLocalFree = true;
			}
        }__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::ConvertToAutoInheritPrivateObjectSecurity( void* ParentDescriptor, nsWin32::GUID* ObjectType, unsigned char IsDirectoryObject, 
		nsWin32::GenericMapping* GenericMapping )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::ConvertToAutoInheritPrivateObjectSecurity" );
		bool bResult = false;
        __QOR_PROTECT
        {
			PSECURITY_DESCRIPTOR pNewDescriptor = 0;
			bResult = m_AdvAPI32Library.ConvertToAutoInheritPrivateObjectSecurity( ParentDescriptor, 
				m_pDescriptor, &pNewDescriptor, reinterpret_cast< ::GUID* >( ObjectType ), IsDirectoryObject, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ) ) ? true : false;
			if( bResult )
			{
				m_pDescriptor = pNewDescriptor;
				m_bLocalFree = true;
			}
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::GetControl( unsigned short* pControl, unsigned long* lpdwRevision )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetControl" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.GetSecurityDescriptorControl( m_pDescriptor, pControl, lpdwRevision ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::GetDacl( int* lpbDaclPresent, nsWin32::AccessControlList** pDacl, int* lpbDaclDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetDacl" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.GetSecurityDescriptorDacl( m_pDescriptor, lpbDaclPresent, reinterpret_cast< ::PACL* >( pDacl ), lpbDaclDefaulted ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::GetGroup( void** pGroup, int* lpbGroupDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetGroup" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.GetSecurityDescriptorGroup( m_pDescriptor, pGroup, lpbGroupDefaulted ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CSecurityDescriptor::GetLength( void )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetLength" );
		DWORD dwResult = 0;
        __QOR_PROTECT
        {
			dwResult = m_AdvAPI32Library.GetSecurityDescriptorLength( m_pDescriptor );
        }__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::GetOwner( void** pOwner, int* lpbOwnerDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetOwner" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.GetSecurityDescriptorOwner( m_pDescriptor, pOwner, lpbOwnerDefaulted ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CSecurityDescriptor::GetRMControl( unsigned char* RMControl )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetRMControl" );
		DWORD dwResult = 0;
        __QOR_PROTECT
        {
			dwResult = m_AdvAPI32Library.GetSecurityDescriptorRMControl( m_pDescriptor, RMControl );
        }__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::GetSacl( int* lpbSaclPresent, nsWin32::AccessControlList** pSacl, int* lpbSaclDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetSacl" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.GetSecurityDescriptorSacl( m_pDescriptor, lpbSaclPresent, reinterpret_cast< ::PACL* >( pSacl ), lpbSaclDefaulted ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::GetPrivateObjectInformation( unsigned long SecurityInformation, void* ResultantDescriptor, unsigned long DescriptorLength, unsigned long* ReturnLength )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetPrivateObjectInformation" );
		bool bResult = false;
        __QOR_PROTECT
        {
			if( m_bPrivateFree )
			{
				bResult = m_AdvAPI32Library.GetPrivateObjectSecurity( m_pDescriptor, SecurityInformation, ResultantDescriptor, DescriptorLength, ReturnLength ) ? true : false;
			}
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::SetPrivateObjectInformation( unsigned long SecurityInformation, 
		void* ModificationDescriptor, unsigned long AutoInheritFlags, nsWin32::GenericMapping* GenericMapping, void* Token )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::SetPrivateObjectInformation" );
		bool bResult = false;
        __QOR_PROTECT
        {
			if( m_bPrivateFree )
			{
				if( AutoInheritFlags == 0 )
				{
					bResult = m_AdvAPI32Library.SetPrivateObjectSecurity( SecurityInformation,
						ModificationDescriptor, &m_pDescriptor, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), Token ) ? true : false;
				}
				else
				{
					bResult = m_AdvAPI32Library.SetPrivateObjectSecurityEx( SecurityInformation, 
					ModificationDescriptor, &m_pDescriptor, AutoInheritFlags, reinterpret_cast< ::PGENERIC_MAPPING >( GenericMapping ), Token ) ? true : false;
				}
			}
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::Initialize( DWORD /*dwRevision*/ )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::Initialize" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.InitializeSecurityDescriptor( m_pDescriptor, SECURITY_DESCRIPTOR_REVISION ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::IsValid( void )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::IsValid" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.IsValidSecurityDescriptor( m_pDescriptor ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CSecurityDescriptor::LookupParts( nsWin32::Trustee** pOwner, nsWin32::Trustee** pGroup, unsigned long* cCountOfAccessEntries,
		nsWin32::ExplicitAccess** pListOfAccessEntries, unsigned long* cCountOfAuditEntries, nsWin32::ExplicitAccess** pListOfAuditEntries )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::LookupParts" );
		DWORD dwResult = 0;
        __QOR_PROTECT
        {
			dwResult = m_AdvAPI32Library.LookupSecurityDescriptorParts( reinterpret_cast< ::PTRUSTEE* >( pOwner ), reinterpret_cast< ::PTRUSTEE* >( pGroup ), 
				cCountOfAccessEntries, reinterpret_cast< ::PEXPLICIT_ACCESS* >( pListOfAccessEntries ), cCountOfAuditEntries, 
				reinterpret_cast< ::PEXPLICIT_ACCESS* >( pListOfAuditEntries ), m_pDescriptor );
        }__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::SetDacl( bool bDaclPresent, nsWin32::AccessControlList* pDacl, bool bDaclDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::SetDacl" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.SetSecurityDescriptorDacl( m_pDescriptor, bDaclPresent ? TRUE : FALSE, reinterpret_cast< ::PACL >( pDacl ), bDaclDefaulted ? TRUE : FALSE ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::SetGroup( void* pGroup, bool bGroupDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::SetGroup" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.SetSecurityDescriptorGroup( m_pDescriptor, pGroup, bGroupDefaulted ? TRUE : FALSE ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::SetOwner( void* pOwner, bool bOwnerDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::SetOwner" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.SetSecurityDescriptorOwner( m_pDescriptor, pOwner, bOwnerDefaulted ? TRUE : FALSE ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	unsigned long CSecurityDescriptor::SetRMControl( unsigned char* RMControl )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::SetRMControl" );
		DWORD dwResult = ERROR_SUCCESS;
        __QOR_PROTECT
        {
			dwResult = m_AdvAPI32Library.SetSecurityDescriptorRMControl( m_pDescriptor, RMControl );
        }__QOR_ENDPROTECT
		return dwResult;
	}

	//------------------------------------------------------------------------------
	bool CSecurityDescriptor::SetSacl( bool bSaclPresent, nsWin32::AccessControlList* pSacl, bool bSaclDefaulted )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::SetSacl" );
		bool bResult = false;
        __QOR_PROTECT
        {
			bResult = m_AdvAPI32Library.SetSecurityDescriptorSacl( m_pDescriptor, bSaclPresent ? TRUE : FALSE, reinterpret_cast< ::PACL >( pSacl ), bSaclDefaulted ? TRUE : FALSE ) ? true : false;
        }__QOR_ENDPROTECT
		return bResult;
	}

	//------------------------------------------------------------------------------
	void* CSecurityDescriptor::GetDescriptor( void )
	{
		_WINQ_FCONTEXT( "CSecurityDescriptor::GetDescriptor" );
		return m_pDescriptor;
	}

}//nsWin32
