//WinQLLocalSecAutority.cpp

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

#include "WinQL/System/Security/WinQLLocalSecAuthority.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	// Authentication Info classes

	//--------------------------------------------------------------------------------
	CAuthenticationInfo::CAuthenticationInfo()
	{
		AuthType = nsWin32::TrustAuthTypeNone;
		m_bFree = false;
		LastUpdateTime.QuadPart = 0;
		AuthInfoLength = 0;
		AuthInfo = 0;
	}

	//--------------------------------------------------------------------------------
	CNT4OWFAuthenticationInfo::CNT4OWFAuthenticationInfo() : CAuthenticationInfo() 
	{
		AuthType = nsWin32::TrustAuthTypeNT4OWF;
	}

	//--------------------------------------------------------------------------------
	CNT4OWFAuthenticationInfo::CNT4OWFAuthenticationInfo( const nsWin32::LSAAuthInformation& Src ) : 
	CAuthenticationInfo( Src )
	{
	}

	//--------------------------------------------------------------------------------
	unsigned char* CNT4OWFAuthenticationInfo::NT4OWFPassword( unsigned long& ulLength )
	{
		ulLength = AuthInfoLength;
		return AuthInfo;
	}

	//--------------------------------------------------------------------------------
	CClearAuthenticationInfo::CClearAuthenticationInfo() : CAuthenticationInfo()
	{
		AuthType = nsWin32::TrustAuthTypeClear;
	}

	//--------------------------------------------------------------------------------
	CClearAuthenticationInfo::CClearAuthenticationInfo( const nsWin32::LSAAuthInformation& Src ) : 
	CAuthenticationInfo( Src )
	{
	}

	//--------------------------------------------------------------------------------
	wchar_t* CClearAuthenticationInfo::ClearTextPassword( unsigned long& ulLength )
	{
		ulLength = AuthInfoLength / sizeof( wchar_t );
		return reinterpret_cast< wchar_t* >( AuthInfo );
	}

	//--------------------------------------------------------------------------------
	CVersionAuthenticationInfo::CVersionAuthenticationInfo() : CAuthenticationInfo()
	{
		AuthType = nsWin32::TrustAuthTypeVersion;
	}

	//--------------------------------------------------------------------------------
	CVersionAuthenticationInfo::CVersionAuthenticationInfo( const nsWin32::LSAAuthInformation& Src ) : 
	CAuthenticationInfo( Src )
	{
	}

	//--------------------------------------------------------------------------------
	unsigned long CVersionAuthenticationInfo::Version( void )
	{
		unsigned long ulResult = reinterpret_cast< unsigned long >( AuthInfo );
		return ulResult;
	}

	//--------------------------------------------------------------------------------
	CAuthenticationInfo::~CAuthenticationInfo()
	{
		Free();
	}

	//--------------------------------------------------------------------------------
	CAuthenticationInfo::CAuthenticationInfo( const CAuthenticationInfo& Src )
	{
		m_bFree = false;
		*this = Src;
	}

	//--------------------------------------------------------------------------------
	CAuthenticationInfo& CAuthenticationInfo::operator=( const CAuthenticationInfo& Src )
	{
		Free();
		m_bFree = true;
		AuthType = Src.AuthType;
		LastUpdateTime = Src.LastUpdateTime;
		AuthInfoLength = Src.AuthInfoLength;
		AuthInfo = new unsigned char[ Src.AuthInfoLength ];
		memcpy( AuthInfo, Src.AuthInfo, Src.AuthInfoLength );
		return *this;
	}

	//--------------------------------------------------------------------------------
	CAuthenticationInfo::CAuthenticationInfo( const nsWin32::LSAAuthInformation& Src )
	{
		m_bFree = false;
		*this = Src;
	}

	//--------------------------------------------------------------------------------
	CAuthenticationInfo& CAuthenticationInfo::operator=( const nsWin32::LSAAuthInformation& Src )
	{
		Free();
		m_bFree = true;
		AuthType = Src.AuthType;
		LastUpdateTime = Src.LastUpdateTime;
		AuthInfoLength = Src.AuthInfoLength;
		AuthInfo = new unsigned char[ AuthInfoLength ];
		memcpy( AuthInfo, Src.AuthInfo, AuthInfoLength );		
		return *this;
	}

	//--------------------------------------------------------------------------------
	void CAuthenticationInfo::Free()
	{
		if( m_bFree )
		{
			delete [] AuthInfo;
		}
		AuthInfo = 0;
	}

	//--------------------------------------------------------------------------------
	//Trusted Domain AuthenticationInfo

	//--------------------------------------------------------------------------------
	CTrustedDomainAuthenticationInfo::CTrustedDomainAuthenticationInfo()
	{
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainAuthenticationInfo::~CTrustedDomainAuthenticationInfo()
	{
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainAuthenticationInfo::CTrustedDomainAuthenticationInfo( const CTrustedDomainAuthenticationInfo& Src )
	{
		m_IncomingAuthenticationInformation = Src.m_IncomingAuthenticationInformation;
		m_IncomingPreviousAuthenticationInformation = Src.m_IncomingPreviousAuthenticationInformation;
		m_OutgoingAuthenticationInformation = Src.m_OutgoingAuthenticationInformation;
		m_OutgoingPreviousAuthenticationInformation = Src.m_OutgoingPreviousAuthenticationInformation;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainAuthenticationInfo::CTrustedDomainAuthenticationInfo( const nsWin32::TrustedDomainAuthInformation& Src )
	{
		unsigned long ulIndex = 0;
		for( ; ulIndex < Src.IncomingAuthInfos; ulIndex++ )
		{
			const nsWin32::LSAAuthInformation& LSA_Auth( Src.IncomingAuthenticationInformation[ ulIndex ] );
			CAuthenticationInfo* pInfo = 0;
			switch( LSA_Auth.AuthType )
			{
			case nsWin32::TrustAuthTypeVersion:
				pInfo = new CVersionAuthenticationInfo( LSA_Auth );
				break;
			case nsWin32::TrustAuthTypeClear:
				pInfo = new CClearAuthenticationInfo( LSA_Auth );
				break;
			case nsWin32::TrustAuthTypeNT4OWF:
				pInfo = new CNT4OWFAuthenticationInfo( LSA_Auth );
				break;
			default:				
				pInfo = new CAuthenticationInfo( LSA_Auth );							
			}
			if( pInfo )
			{
				m_IncomingAuthenticationInformation.Append( pInfo );
			}

			const nsWin32::LSAAuthInformation& LSA_PrevAuth( Src.IncomingPreviousAuthenticationInformation[ ulIndex ] );

			switch( LSA_PrevAuth.AuthType )
			{
			case nsWin32::TrustAuthTypeVersion:
				pInfo = new CVersionAuthenticationInfo( LSA_PrevAuth );
				break;
			case nsWin32::TrustAuthTypeClear:
				pInfo = new CClearAuthenticationInfo( LSA_PrevAuth );
				break;
			case nsWin32::TrustAuthTypeNT4OWF:
				pInfo = new CNT4OWFAuthenticationInfo( LSA_PrevAuth );
				break;
			default:
				pInfo = new CAuthenticationInfo( LSA_PrevAuth );									
			}
			if( pInfo )
			{
				m_IncomingPreviousAuthenticationInformation.Append( pInfo );
			}
		}

		for( ulIndex = 0; ulIndex < Src.OutgoingAuthInfos; ulIndex++ )
		{
			const nsWin32::LSAAuthInformation& LSA_Auth( Src.OutgoingAuthenticationInformation[ ulIndex ] );
			CAuthenticationInfo* pInfo = 0;

			switch( LSA_Auth.AuthType )
			{
			case nsWin32::TrustAuthTypeVersion:
				pInfo = new CVersionAuthenticationInfo( LSA_Auth );
				break;
			case nsWin32::TrustAuthTypeClear:
				pInfo = new CClearAuthenticationInfo( LSA_Auth );
				break;
			case nsWin32::TrustAuthTypeNT4OWF:
				pInfo = new CNT4OWFAuthenticationInfo( LSA_Auth );
				break;
			default:
				pInfo = new CAuthenticationInfo( LSA_Auth );					
			}

			if( pInfo )
			{
				m_OutgoingAuthenticationInformation.Append( pInfo );
			}

			const nsWin32::LSAAuthInformation& LSA_PrevAuth( Src.OutgoingPreviousAuthenticationInformation[ ulIndex ] );
			pInfo = 0;

			switch( LSA_PrevAuth.AuthType )
			{
			case nsWin32::TrustAuthTypeVersion:
				pInfo = new CVersionAuthenticationInfo( LSA_PrevAuth );
				break;
			case nsWin32::TrustAuthTypeClear:
				pInfo = new CClearAuthenticationInfo( LSA_PrevAuth );
				break;
			case nsWin32::TrustAuthTypeNT4OWF:
				pInfo = new CNT4OWFAuthenticationInfo( LSA_PrevAuth );
				break;
			default:
				pInfo = new CAuthenticationInfo( LSA_PrevAuth );								
			}

			if( pInfo )
			{
				m_OutgoingPreviousAuthenticationInformation.Append( pInfo );
			}
		}
	}

	//--------------------------------------------------------------------------------
	//Translated Name

    //--------------------------------------------------------------------------------
    CTranslatedName::~CTranslatedName()
    {
        delete m_strName;
    }

    //--------------------------------------------------------------------------------
    CTranslatedName::CTranslatedName( const nsWin32::LSATranslatedName& Src ) : 
    m_lDomainIndex( Src.DomainIndex )
        , m_Usage( Src.Use )
    {
        switch( m_Usage )
        {
		case nsWin32::SidTypeUnknown:
		case nsWin32::SidTypeInvalid:
            m_lDomainIndex = -1;
            //deliberate fall through
		case nsWin32::SidTypeDomain:
            m_strName = 0;
            break;
		case nsWin32::SidTypeWellKnownGroup:
            m_lDomainIndex = -1;
            //deliberate fall through
        default:
            m_strName = CLSAUnicodeString( (const nsWin32::LSAUnicodeString*)&Src.Name );
        }
    }

	//--------------------------------------------------------------------------------
	//Trust Information

    //--------------------------------------------------------------------------------
    CTrustInformation::~CTrustInformation()
    {
        delete m_strName;
    }

    //--------------------------------------------------------------------------------
    CTrustInformation::CTrustInformation( const nsWin32::LSATrustInformation& Src ) : m_Sid( Src.Sid )
    {
        m_strName = new wchar_t[ Src.Name.MaximumLength / sizeof( wchar_t ) ];
		wcsncpy( m_strName, Src.Name.Buffer, Src.Name.Length / sizeof( wchar_t ) );
		m_strName[ ( Src.Name.MaximumLength / sizeof( wchar_t ) ) - 1 ] = wchar_t(0);
    }


	//--------------------------------------------------------------------------------
	//SecurityAuthority

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CSecurityAuthority()
	{
	}

	//--------------------------------------------------------------------------------
	CSecurityAuthority::~CSecurityAuthority()
	{
	}

	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< CSecurityAuthority::CAccount > CSecurityAuthority::Account( wchar_t* strAccountName, nsCodeQOR::CTLRef< CSession > Session )
	{		
		nsCodeQOR::CTLRef< CSecurityAuthority::CAccount > Result( new CSecurityAuthority::CAccount( strAccountName, Session ) );
		return Result;
	}

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CTrustedDomain* CSecurityAuthority::NewTrustedDomain( CTrustedDomainInfoEx& DomainInfo, sPolicyMask PolicyMask, nsCodeQOR::CTLRef< CSession >& Session )
	{
		nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > Result( new CSecurityAuthority::CTrustedDomain( DomainInfo, PolicyMask, Session ) );
		return Result;
	}
	
	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > CSecurityAuthority::TrustedDomain( wchar_t* strDomainName, sPolicyMask PolicyMask, nsCodeQOR::CTLRef< CSession >& Session )
	{
		nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > Result( new CSecurityAuthority::CTrustedDomain( strDomainName, PolicyMask, Session ) );
		return Result;
	}

	//--------------------------------------------------------------------------------
	//Account

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CAccount::CAccount( wchar_t* strAccountName, nsCodeQOR::CTLRef< CSession >& Session ) :
		m_Session( Session )
	{
		m_pReferencedDomains = 0;
		bool bLookupNames = m_Session->LookupNames( 1, &strAccountName, &m_pReferencedDomains, &m_pLsaSID );		
		if( bLookupNames && m_pReferencedDomains != 0 )
		{
			nsWin32::LSATrustInformation* pEntry = m_pReferencedDomains->Domains;
			for( unsigned int ui = 0; ui < m_pReferencedDomains->Entries; ui++, pEntry++ )
			{
				nsWin32::LSAUnicodeString* pOrphan = 0;
				CLSAUnicodeString Name( &pEntry->Name );				
				Name.Orphan( pOrphan );//Don't free the underlying LSAUnicodeString after conversion, it's part of a block
				m_ReferencedDomainList.Append( new DomainItem( Name, pEntry->Sid ) );				
			}
		}		
		void* pDomainSid = m_ReferencedDomainList.GetItem( m_pLsaSID->DomainIndex + 1 )->Second();
		m_pAccountSID = 0;

		switch( m_pLsaSID->Use )
		{
		case nsWin32::SidTypeAlias:
		case nsWin32::SidTypeUser:
		case nsWin32::SidTypeGroup:
		case nsWin32::SidTypeWellKnownGroup:
			{
				CSID DomainSid( pDomainSid );
				if( DomainSid.IsValid() )
				{
					nsWin32::SID_NAME_USE Use = nsWin32::SidTypeInvalid;
					CTString strFullName;
					CWString strDomain( m_ReferencedDomainList.GetItem( m_pLsaSID->DomainIndex + 1 )->First() );
					if( !strDomain.IsEmpty() )
					{
						strFullName.Append( strDomain.toTString() );
						strFullName.Append( _TXT("\\").c_str()[ 0 ] );
					}
                    CWString AccountName( strAccountName );
					strFullName.Append( AccountName.toTString() );

					m_pAccountSID = new CSID( 0, strFullName.GetBuffer(), &Use );
				}
			}
		case nsWin32::SidTypeDomain:
			break;
		case nsWin32::SidTypeInvalid:
			break;
		case nsWin32::SidTypeUnknown:
			break;
		case nsWin32::SidTypeDeletedAccount:
			break;
		}
	}

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CAccount::CAccount( void* pSID, nsCodeQOR::CTLRef< CSession >& Session ) : 
		m_Session( Session )
	{
        m_pLsaSID = 0;
        m_pLsaSID2 = 0;
		m_pReferencedDomains = 0;		
		m_pAccountSID = new CSID( pSID );
	}

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CAccount::~CAccount()
	{
		if( m_pReferencedDomains != 0 )
		{
			m_Session->m_Policy.FreeMemory( m_pReferencedDomains );
		}
		delete m_pAccountSID;
	}

	//--------------------------------------------------------------------------------
	nsWin32::LSATranslatedSID* CSecurityAuthority::CAccount::LSASID( void )
	{
		return m_pLsaSID;
	}

	//--------------------------------------------------------------------------------
	void* CSecurityAuthority::CAccount::SID( void )
	{
		void* pSID = 0;
		if( m_pAccountSID != 0 )
		{
			pSID = m_pAccountSID->Data();
		}
		return pSID;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CAccount::AddRights( wchar_t** paRights, unsigned long CountOfRights )
	{
		bool bResult = false;
		bResult = m_Session->m_Policy.AddAccountRights( SID(), paRights, CountOfRights );
		return bResult;
	}	

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CAccount::EnumerateRights( nsCodeQOR::CTLinkedList< nsWin32::CWString::ref_type >& Rights )
	{
		bool bResult = false;
		//__QOR_PROTECT
		{
			bResult = m_Session->m_Policy.EnumerateAccountRights( SID(), Rights );
		}//__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CAccount::RemoveRights( bool bAll, wchar_t** paUserRights, unsigned long CountOfRights )
	{
		bool bResult = false;
		unsigned char AllRights = bAll ? 1 : 0;
		bResult = m_Session->m_Policy.RemoveAccountRights( SID(), AllRights, paUserRights, CountOfRights );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	//Session

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CSession::CSession( wchar_t* strSystemName, unsigned long DesiredAccess ) :
		m_Policy( strSystemName, DesiredAccess )
	{
	}

	//--------------------------------------------------------------------------------
	CSecurityAuthority::CSession::~CSession()
	{
	}		

	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< nsCodeQOR::CTLinkedList< CSecurityAuthority::CAccount > > CSecurityAuthority::CSession::EnumerateAccountsWithUserRight( CWString& strRight )
	{
		bool bResult = false;
		void* EnumerationBuffer = 0;
		unsigned long ulCount = 0;

        bResult = m_Policy.EnumerateAccountsWithUserRight( strRight.GetBuffer(), &EnumerationBuffer, &ulCount );
		CAccountList* pAccountList = 0;
		if( bResult )
		{
			nsWin32::LSAEnumerationInformation** ppInfoArray = reinterpret_cast< nsWin32::LSAEnumerationInformation** >( EnumerationBuffer );
			pAccountList = new CAccountList;
			RefSession ThisSession( this, false );//Create a non owning reference
			for( unsigned int i = 0; i < ulCount; i++ )
			{
				pAccountList->Append( new CSecurityAuthority::CAccount( ppInfoArray[ i ], ThisSession ) );
			}
		}
		m_Policy.FreeMemory( EnumerationBuffer );
		return RefAccountList( pAccountList );
	}

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CSession::LookupNames( unsigned long Count, wchar_t** paNames, 
		nsWin32::LSAReferencedDomainList** ReferencedDomains, nsWin32::LSATranslatedSID** Sids )
	{
		bool bResult = false;
		bResult = m_Policy.LookupNames( Count, paNames, ReferencedDomains, Sids );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CSession::LookupNames2( unsigned long Flags, unsigned long Count, 
		wchar_t** paNames, nsWin32::LSAReferencedDomainList** ReferencedDomains, nsWin32::LSATranslatedSID2** Sids )
	{
		bool bResult = false;
		bResult = m_Policy.LookupNames2( Flags, Count, paNames, ReferencedDomains, Sids );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< CSecurityAuthority::CSession::CTrustedDomainEnumeration > CSecurityAuthority::CSession::TrustedDomainEnumeration( unsigned long ulPreferedMaximumLength )
	{
		nsCodeQOR::CTLRef< CSecurityAuthority::CSession > ThisSession( this );
		nsCodeQOR::CTLRef< CSecurityAuthority::CSession::CTrustedDomainEnumeration > Result = 
			new CSecurityAuthority::CSession::CTrustedDomainEnumeration( ulPreferedMaximumLength, ThisSession );
		return Result;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CSession::LookupPrivilegeValue( wchar_t* StrName, nsWin32::LUID& Value )
	{
		bool bResult = false;
		bResult = m_Policy.LookupPrivilegeValueT( StrName, &Value );
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CSecurityAuthority::CSession::LookupSids( unsigned long ulCount, void** Sids, 
        nsCodeQOR::CTLinkedList< CTrustInformation >& ReferencedDomains, 
        nsCodeQOR::CTLinkedList< CTranslatedName >& Names )
	{
		bool bResult = false;
        nsWin32::LSAReferencedDomainList* pReferencedDomainList = 0;
        nsWin32::LSATranslatedName* pNames = 0;
		bResult = m_Policy.LookupSids( ulCount, Sids, &pReferencedDomainList, &pNames );
        if( bResult && pReferencedDomainList )
        {
            for( unsigned long i = 0; i < pReferencedDomainList->Entries; i++ )
            {
                ReferencedDomains.Append( new CTrustInformation( pReferencedDomainList->Domains[ i ] ) );
            }
            m_Policy.FreeMemory( pReferencedDomainList );
        }
        if( bResult && pNames )
        {
            for( unsigned long i = 0; i < ulCount; i++ )
            {
                Names.Append( new CTranslatedName( pNames[ i ] ) );
            }
            m_Policy.FreeMemory( pNames );
        }
		return bResult;
	}

	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< CSecurityAuthority::CSession::CPrivateData > CSecurityAuthority::CSession::PrivateData( 
		wchar_t* StrKeyName )
	{
		nsCodeQOR::CTLRef< CSecurityAuthority::CSession > ThisSession( this, false );
		nsCodeQOR::CTLRef< CSecurityAuthority::CSession::CPrivateData > Ref( 
			new CSecurityAuthority::CSession::CPrivateData( ThisSession, StrKeyName ) );
		return Ref;
	}

		//--------------------------------------------------------------------------------
		//Session Trusted Domain Enumeration

		//--------------------------------------------------------------------------------
		CSecurityAuthority::CSession::CTrustedDomainEnumeration::~CTrustedDomainEnumeration()
		{
		}

		//--------------------------------------------------------------------------------
		CSecurityAuthority::CSession::CTrustedDomainEnumeration::CTrustedDomainEnumeration( unsigned long ulPreferredMaximumLength, nsCodeQOR::CTLRef< CSession >& Session ) :
			m_Session( Session )
		{
			m_EnumerationContext = 0;
			m_ulPrefMax = ulPreferredMaximumLength;
			More();
		}

		//--------------------------------------------------------------------------------
		bool CSecurityAuthority::CSession::CTrustedDomainEnumeration::More( void )
		{
			bool bResult = false;
			void* EnumerationBuffer = 0;
			unsigned long ulCount = 0;		
			bResult = m_Session->m_Policy.EnumerateTrustedDomains( &m_EnumerationContext, &EnumerationBuffer, m_ulPrefMax, &ulCount );		
			if( bResult )
			{
				nsWin32::LSATrustInformation** ppInfoArray = reinterpret_cast< nsWin32::LSATrustInformation** >( EnumerationBuffer );			
				for( unsigned int i = 0; i < ulCount; i++ )
				{
					CLSAUnicodeString DomainName( &((*ppInfoArray)[ i ].Name) );
					wchar_t* StrName = DomainName;
					m_List.Append( new DomainItem( StrName, (*ppInfoArray)[ i ].Sid ) );
				}
			}
			m_Session->m_Policy.FreeMemory( EnumerationBuffer );
			return bResult;
		}

		//--------------------------------------------------------------------------------
		RefDomainList CSecurityAuthority::CSession::CTrustedDomainEnumeration::List( void )
		{
			RefDomainList Result( &m_List, false );
			return Result;
		}

		//--------------------------------------------------------------------------------
		bool CSecurityAuthority::CSession::CTrustedDomainEnumeration::Query( 
			unsigned int uiIndex, nsWin32::eTrustedInformationClass InformationClass, void** ppBuffer )
		{
			bool bResult = false;
			if( uiIndex < m_List.GetCount() )
			{
				bResult = m_Session->m_Policy.QueryTrustedDomainInfo( m_List.GetItem( uiIndex + 1 )->Second(), 
				InformationClass, ppBuffer );
			}
			return bResult;
		}

		//--------------------------------------------------------------------------------
		bool CSecurityAuthority::CSession::CTrustedDomainEnumeration::Set( 
			unsigned int uiIndex, nsWin32::eTrustedInformationClass InformationClass, void* pBuffer )
		{
			bool bResult = false;
			if( uiIndex < m_List.GetCount() )
			{
				bResult = m_Session->m_Policy.SetTrustedDomainInformation( m_List.GetItem( uiIndex + 1 )->Second(),
				InformationClass, pBuffer );
			}
			return bResult;
		}

		//--------------------------------------------------------------------------------
		nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > CSecurityAuthority::CSession::CTrustedDomainEnumeration::Domain( unsigned int uiIndex, nsWin32::sPolicyMask PolicyMask )
		{
			if( uiIndex < m_List.GetCount() )
			{
				nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > RefResult( new CSecurityAuthority::CTrustedDomain( m_List.GetItem( uiIndex )->First(), PolicyMask, m_Session ) );
				return RefResult;
			}

			nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > NullResult;
			return NullResult;
		}

		//--------------------------------------------------------------------------------
		//Session Trusted Domain Enumeration Ex

		//--------------------------------------------------------------------------------
		CSecurityAuthority::CSession::CTrustedDomainEnumerationEx::~CTrustedDomainEnumerationEx()
		{
		}

		//--------------------------------------------------------------------------------
		CSecurityAuthority::CSession::CTrustedDomainEnumerationEx::CTrustedDomainEnumerationEx( 
			unsigned long ulPreferredMaximumLength, nsCodeQOR::CTLRef< CSession >& Session ) : m_Session( Session )
		{
			m_EnumerationContext = 0;
			m_ulPrefMax = ulPreferredMaximumLength;
			More();
		}

		//--------------------------------------------------------------------------------
		bool CSecurityAuthority::CSession::CTrustedDomainEnumerationEx::More( void )
		{
			bool bResult = false;
			void* EnumerationBuffer = 0;
			unsigned long ulCount = 0;		
			bResult = m_Session->m_Policy.EnumerateTrustedDomainsEx( &m_EnumerationContext, &EnumerationBuffer, m_ulPrefMax, &ulCount );		
			if( bResult )
			{
				nsWin32::TrustedDomainInformationEx* pInfoArray = reinterpret_cast< nsWin32::TrustedDomainInformationEx* >( EnumerationBuffer );
				for( unsigned int i = 0; i < ulCount; i++ )
				{
					m_List.Append( new CTrustedDomainInfoEx( pInfoArray[ i ] ) );
				}
			}
			m_Session->m_Policy.FreeMemory( EnumerationBuffer );
			return bResult;
		}

		//--------------------------------------------------------------------------------
		RefDomainInfoExList CSecurityAuthority::CSession::CTrustedDomainEnumerationEx::List( void )
		{
			RefDomainInfoExList Result( &m_List, false );
			return Result;
		}

		//--------------------------------------------------------------------------------
		nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > CSecurityAuthority::CSession::CTrustedDomainEnumerationEx::Domain( unsigned int uiIndex, nsWin32::sPolicyMask PolicyMask )
		{
			if( uiIndex < m_List.GetCount() )
			{
				CTrustedDomainInfoEx Info( *m_List.GetItem( uiIndex ) );
				nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > RefResult(
					new CSecurityAuthority::CTrustedDomain( Info.Name(), PolicyMask, m_Session ) );
				return RefResult;
			}

			nsCodeQOR::CTLRef< CSecurityAuthority::CTrustedDomain > NullResult;
			return NullResult;
		}

		//--------------------------------------------------------------------------------
		//Session Private Data

		//--------------------------------------------------------------------------------
		CSecurityAuthority::CSession::CPrivateData::CPrivateData( nsCodeQOR::CTLRef<CSession>& Session, wchar_t* StrKeyName ) :
			m_Session( Session )
		{
			m_strKeyName = StrKeyName;
			m_strData = 0;
		}

		//--------------------------------------------------------------------------------
		void CSecurityAuthority::CSession::CPrivateData::Set( wchar_t* pStrPrivateData )
		{
			m_Session->m_Policy.StorePrivateData( m_strKeyName, pStrPrivateData );
		};

		//--------------------------------------------------------------------------------
		wchar_t* CSecurityAuthority::CSession::CPrivateData::Get( void )
		{
			wchar_t* Result = 0;
			m_Session->m_Policy.RetrievePrivateData( m_strKeyName, &Result );
			return Result;
		}


	//--------------------------------------------------------------------------------
	//Trusted Domain

	//--------------------------------------------------------------------------------
	//Opens a trusted Domain by name and retrieves the full set of information from it
	CSecurityAuthority::CTrustedDomain::CTrustedDomain( wchar_t* strDomainName, sPolicyMask PolicyMask, nsCodeQOR::CTLRef< CSession >& Session ) : 
	CTrustedDomainInfoEx(), m_Policy( Session->m_Policy, strDomainName, PolicyMask.Mask )
	{
		void* pBuffer = 0;
		if( m_Policy.QueryTrustedDomainInfoByName( strDomainName, nsWin32::eTrustedDomainFullInformation, &pBuffer ) )
		{
			nsWin32::TrustedDomainFullInformation* pInfo = reinterpret_cast< nsWin32::TrustedDomainFullInformation* >( pBuffer );
			const nsWin32::TrustedDomainFullInformation& RefInfo( *pInfo );
			*this = RefInfo;
		}
		m_Policy.FreeMemory( pBuffer );
	}

	//--------------------------------------------------------------------------------
	//Creates a new Trusted Domain according to the supplied information
	CSecurityAuthority::CTrustedDomain::CTrustedDomain( CTrustedDomainInfoEx& DomainInfo, sPolicyMask PolicyMask, nsCodeQOR::CTLRef< CSession >& Session ) :
	CTrustedDomainInfoEx( DomainInfo ), m_Policy( Session->m_Policy, DomainInfo.Name(), PolicyMask.Mask )
	{
	}

	//--------------------------------------------------------------------------------
	//Commit the details of a new or modified trsuted domain to the system
	bool CSecurityAuthority::CTrustedDomain::Commit( void )
	{
		bool bResult = false;
		nsWin32::TrustedDomainFullInformation Info;
		Info.PosixOffset.Offset = m_ulPosixOffset;
		Info.AuthInformation.IncomingAuthInfos = m_pAuthentication->m_IncomingAuthenticationInformation.Size();
		Info.AuthInformation.OutgoingAuthInfos = m_pAuthentication->m_OutgoingAuthenticationInformation.Size();
		Info.AuthInformation.IncomingAuthenticationInformation = new nsWin32::LSAAuthInformation[ m_pAuthentication->m_IncomingAuthenticationInformation.Size() ];
		Info.AuthInformation.IncomingPreviousAuthenticationInformation = new nsWin32::LSAAuthInformation[ m_pAuthentication->m_IncomingAuthenticationInformation.Size() ];
		Info.AuthInformation.OutgoingAuthenticationInformation = new nsWin32::LSAAuthInformation[ m_pAuthentication->m_OutgoingAuthenticationInformation.Size() ];
		Info.AuthInformation.OutgoingPreviousAuthenticationInformation = new nsWin32::LSAAuthInformation[ m_pAuthentication->m_OutgoingAuthenticationInformation.Size() ];

		unsigned int ui = 0;
		for( ; ui < m_pAuthentication->m_IncomingAuthenticationInformation.Size(); ui++ )
		{
			Info.AuthInformation.IncomingAuthenticationInformation[ ui ] = *m_pAuthentication->m_IncomingAuthenticationInformation[ ui ];
			Info.AuthInformation.IncomingPreviousAuthenticationInformation[ ui ] = *m_pAuthentication->m_IncomingPreviousAuthenticationInformation[ ui ];
		}

		for( ui = 0; ui < m_pAuthentication->m_OutgoingAuthenticationInformation.Size(); ui++ )
		{
			Info.AuthInformation.OutgoingAuthenticationInformation[ ui ] = *m_pAuthentication->m_OutgoingAuthenticationInformation[ ui ];
			Info.AuthInformation.OutgoingPreviousAuthenticationInformation[ ui ] = *m_pAuthentication->m_OutgoingPreviousAuthenticationInformation[ ui ];
		}
				
		Info.Information.FlatName = CLSAUnicodeString( m_StrFlatName );
		Info.Information.Name = CLSAUnicodeString( m_StrName );
		Info.Information.Sid = m_Sid.Data();
		Info.Information.TrustAttributes = m_ulTrustAttributes;
		Info.Information.TrustDirection = m_ulTrustDirection;
		Info.Information.TrustType = m_ulTrustType;
		void* pBuffer = &Info;
		bResult = m_Policy.SetTrustedDomainInformation( m_Sid.Data(), nsWin32::eTrustedDomainFullInformation, pBuffer );

		delete [] Info.AuthInformation.IncomingAuthenticationInformation;
		delete [] Info.AuthInformation.IncomingPreviousAuthenticationInformation;
		delete [] Info.AuthInformation.OutgoingAuthenticationInformation;
		delete [] Info.AuthInformation.OutgoingPreviousAuthenticationInformation;

		return bResult;
	}

	//--------------------------------------------------------------------------------
	//Trusted Domain Info Ex

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx::CTrustedDomainInfoEx() : m_Sid( _TXT("") )
	{
		m_StrName = 0;
		m_StrFlatName = 0;		
		m_ulTrustDirection = 0;
		m_ulTrustType = 0;
		m_ulTrustAttributes = 0;
		m_ulPosixOffset = 0;
		m_pAuthentication = 0;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx::CTrustedDomainInfoEx( const CTrustedDomainInfoEx& Src ) : m_Sid( Src.SID() )
	{
		m_pAuthentication = 0;
		*this = Src;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx::CTrustedDomainInfoEx( const nsWin32::TrustedDomainInformationEx& src ) : m_Sid( src.Sid )
	{
		m_ulTrustType = src.TrustType;
		m_ulTrustDirection = src.TrustDirection;
		m_ulTrustAttributes = src.TrustAttributes;		
		m_StrName = CLSAUnicodeString( const_cast< nsWin32::LSAUnicodeString* >( &src.Name ) );
		m_StrFlatName = CLSAUnicodeString( const_cast< nsWin32::LSAUnicodeString* >( &src.FlatName ) );		
		m_ulPosixOffset = 0;
		m_pAuthentication = 0;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx::CTrustedDomainInfoEx( const nsWin32::TrustedDomainFullInformation& src ) : m_Sid( src.Information.Sid )
	{
		m_pAuthentication = 0;
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx& CTrustedDomainInfoEx::operator=( const nsWin32::TrustedDomainFullInformation& src )
	{
		m_ulTrustType = src.Information.TrustType;
		m_ulTrustDirection = src.Information.TrustDirection;
		m_ulTrustAttributes = src.Information.TrustAttributes;		
		m_StrName = CLSAUnicodeString( const_cast< nsWin32::LSAUnicodeString* >( &src.Information.Name ) );
		m_StrFlatName = CLSAUnicodeString( const_cast< nsWin32::LSAUnicodeString* >( &src.Information.FlatName ) );		
		m_ulPosixOffset = src.PosixOffset.Offset;
		delete m_pAuthentication;
		m_pAuthentication = new CTrustedDomainAuthenticationInfo( src.AuthInformation );
		return *this;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx& CTrustedDomainInfoEx::operator=( const CTrustedDomainInfoEx& src )
	{
		m_StrName = src.Name();
		m_StrFlatName = src.FlatName();		
		m_ulTrustDirection = src.TrustDirection();
		m_ulTrustType = src.TrustType();
		m_ulTrustAttributes = src.TrustAttributes();
		m_ulPosixOffset = src.PosixOffset();
		delete m_pAuthentication;
		m_pAuthentication = new CTrustedDomainAuthenticationInfo( *src.m_pAuthentication );
		return *this;
	}

	//--------------------------------------------------------------------------------
	CTrustedDomainInfoEx::~CTrustedDomainInfoEx()
	{
		delete m_pAuthentication;
	}
	
	//--------------------------------------------------------------------------------
	wchar_t* CTrustedDomainInfoEx::Name( void ) const
	{
		return m_StrName;
	}

	//--------------------------------------------------------------------------------
	wchar_t* CTrustedDomainInfoEx::FlatName( void ) const
	{
		return m_StrFlatName;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTrustedDomainInfoEx::PosixOffset( void ) const
	{
		return m_ulPosixOffset;
	}

	//--------------------------------------------------------------------------------
	void* CTrustedDomainInfoEx::SID( void ) const
	{
		return m_Sid.Data();
	}

	//--------------------------------------------------------------------------------
	unsigned long CTrustedDomainInfoEx::TrustDirection( void ) const
	{
		return m_ulTrustDirection;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTrustedDomainInfoEx::TrustType( void ) const
	{
		return m_ulTrustType;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTrustedDomainInfoEx::TrustAttributes( void ) const
	{
		return m_ulTrustAttributes;
	}

	//--------------------------------------------------------------------------------
	nsCodeQOR::CTLRef< CTrustedDomainAuthenticationInfo > CTrustedDomainInfoEx::Authentication( void ) const
	{
		nsCodeQOR::CTLRef< CTrustedDomainAuthenticationInfo > Result( m_pAuthentication, false );
		return Result;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::Name( wchar_t* strName )
	{
		m_StrName = strName;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::FlatName( wchar_t* strFlatName )
	{
		m_StrFlatName = strFlatName;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::PosixOffset( unsigned long ulOffset )
	{
		m_ulPosixOffset = ulOffset;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::SID( void* pSID )
	{
		m_Sid = pSID;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::TrustDirection( unsigned long ulDirection )
	{
		m_ulTrustDirection = ulDirection;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::TrustType( unsigned long ulType )
	{
		m_ulTrustType = ulType;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::TrustAttributes( unsigned long ulAttributes )
	{
		m_ulTrustAttributes = ulAttributes;
	}

	//--------------------------------------------------------------------------------
	void CTrustedDomainInfoEx::Authentication( nsCodeQOR::CTLRef< CTrustedDomainAuthenticationInfo > AuthInfo )
	{
		CTrustedDomainAuthenticationInfo* pInfo = AuthInfo;
		delete m_pAuthentication;
		m_pAuthentication = new CTrustedDomainAuthenticationInfo( *pInfo );
	}

}//nsWin32

