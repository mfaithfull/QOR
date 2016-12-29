//Authentication.cpp

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

#include "WinQAPI/AdvAPI32.h"
#include "../Source/SystemQOR/MSWindows/WinQAPI/include/ReturnCheck.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	//------------------------------------------------------------------------------
	//CredDeleteA
	BOOL CAdvAPI32::CredDeleteA( LPCSTR TargetName, DWORD Type, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredDeleteA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredDeleteA );
		bResult = Call< BOOL, LPCSTR, DWORD, DWORD >( pFunc, TargetName, Type, Flags );
#else
		QOR_PP_UNREF( TargetName );
		QOR_PP_UNREF( Type );
		QOR_PP_UNREF( Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredDeleteA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredDeleteW
	BOOL CAdvAPI32::CredDeleteW( LPCWSTR TargetName, DWORD Type, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredDeleteW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredDeleteW );
		bResult = Call< BOOL, LPCWSTR, DWORD, DWORD >( pFunc, TargetName, Type, Flags );
#else
		QOR_PP_UNREF( TargetName );
		QOR_PP_UNREF( Type );
		QOR_PP_UNREF( Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredDeleteW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredEnumerateA
	BOOL CAdvAPI32::CredEnumerateA( LPCSTR Filter, DWORD Flags, DWORD* Count, PCREDENTIAL** Credentials )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredEnumerateA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredEnumerateA );
		bResult = Call< BOOL, LPCSTR, DWORD, DWORD*, PCREDENTIAL** >( pFunc, Filter, Flags, Count, Credentials );
#else
		QOR_PP_UNREF( Filter );
		QOR_PP_UNREF( Flags );
		QOR_PP_UNREF( Count );
		QOR_PP_UNREF( Credentials );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredEnumerateA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredEnumerateW
	BOOL CAdvAPI32::CredEnumerateW( LPCWSTR Filter, DWORD Flags, DWORD* Count, PCREDENTIAL** Credentials )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredEnumerateW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredEnumerateW );
		bResult = Call< BOOL, LPCWSTR, DWORD, DWORD*, PCREDENTIAL** >( pFunc, Filter, Flags, Count, Credentials );
#else
		QOR_PP_UNREF( Filter );
		QOR_PP_UNREF( Flags );
		QOR_PP_UNREF( Count );
		QOR_PP_UNREF( Credentials );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredEnumerateW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredFree
	VOID CAdvAPI32::CredFree( PVOID Buffer )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredFree" );
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredFree );
		voidCall< PVOID >( pFunc, Buffer ); 
#else
		QOR_PP_UNREF( Buffer );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredFree"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
	}

	//------------------------------------------------------------------------------
	//CredGetSessionTypes
	BOOL CAdvAPI32::CredGetSessionTypes( DWORD MaximumPersistCount, LPDWORD MaximumPersist )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredGetSessionTypes" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredGetSessionTypes );
		bResult = Call< BOOL, DWORD, LPDWORD >( pFunc, MaximumPersistCount, MaximumPersist );
#else
		QOR_PP_UNREF( MaximumPersistCount );
		QOR_PP_UNREF( MaximumPersist );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredGetSessionTypes"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredGetTargetInfoA
	BOOL CAdvAPI32::CredGetTargetInfoA( LPCSTR TargetName, DWORD Flags, PCREDENTIAL_TARGET_INFORMATION* TargetInfo )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredGetTargetInfoA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredGetTargetInfoA );
		bResult = Call< BOOL, LPCSTR, DWORD, PCREDENTIAL_TARGET_INFORMATION* >( pFunc, TargetName, Flags, TargetInfo );
#else
		QOR_PP_UNREF( TargetName );
		QOR_PP_UNREF( Flags );
		QOR_PP_UNREF( TargetInfo );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredGetTargetInfoA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredGetTargetInfoW
	BOOL CAdvAPI32::CredGetTargetInfoW( LPCWSTR TargetName, DWORD Flags, PCREDENTIAL_TARGET_INFORMATION* TargetInfo )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredGetTargetInfoW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredGetTargetInfoW );
		bResult = Call< BOOL, LPCWSTR, DWORD, PCREDENTIAL_TARGET_INFORMATION* >( pFunc, TargetName, Flags, TargetInfo );
#else
		QOR_PP_UNREF( TargetName );
		QOR_PP_UNREF( Flags );
		QOR_PP_UNREF( TargetInfo );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredGetTargetInfoW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredIsMarshaledCredentialA
	BOOL CAdvAPI32::CredIsMarshaledCredentialA( LPCSTR MarshaledCredential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredIsMarshaledCredentialA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredIsMarshaledCredentialA );
		bResult = Call< BOOL, LPCSTR >( pFunc, MarshaledCredential );
#else
		QOR_PP_UNREF( MarshaledCredential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredIsMarshaledCredentialA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredIsMarshaledCredentialW
	BOOL CAdvAPI32::CredIsMarshaledCredentialW( LPCWSTR MarshaledCredential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredIsMarshaledCredentialW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredIsMarshaledCredentialW );
		bResult = Call< BOOL, LPCWSTR >( pFunc, MarshaledCredential );
#else
		QOR_PP_UNREF( MarshaledCredential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredIsMarshaledCredentialW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredMarshalCredentialA
	BOOL CAdvAPI32::CredMarshalCredentialA( CRED_MARSHAL_TYPE CredType, PVOID Credential, LPSTR* MarshaledCredential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredMarshalCredentialA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredMarshalCredentialA );
		bResult = Call< BOOL, CRED_MARSHAL_TYPE, PVOID, LPSTR* >( pFunc, CredType, Credential, MarshaledCredential );
#else
		QOR_PP_UNREF( CredType );
		QOR_PP_UNREF( Credential );
		QOR_PP_UNREF( MarshaledCredential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredMarshalCredentialA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredMarshalCredentialW
	BOOL CAdvAPI32::CredMarshalCredentialW( CRED_MARSHAL_TYPE CredType, PVOID Credential, LPWSTR* MarshaledCredential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredMarshalCredentialW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredMarshalCredentialW );
		bResult = Call< BOOL, CRED_MARSHAL_TYPE, PVOID, LPWSTR* >( pFunc, CredType, Credential, MarshaledCredential );
#else
		QOR_PP_UNREF( CredType );
		QOR_PP_UNREF( Credential );
		QOR_PP_UNREF( MarshaledCredential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredMarshalCredentialW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredReadDomainCredentialsA
	BOOL CAdvAPI32::CredReadDomainCredentialsA( PCREDENTIAL_TARGET_INFORMATION TargetInfo, DWORD Flags, DWORD* Count, PCREDENTIAL** Credentials )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredReadDomainCredentialsA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredReadDomainCredentialsA );
		bResult = Call< BOOL, PCREDENTIAL_TARGET_INFORMATION, DWORD, DWORD*, PCREDENTIAL** >( pFunc, TargetInfo, Flags, Count, Credentials );
#else
		QOR_PP_UNREF4( TargetInfo, Flags, Count, Credentials );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredReadDomainCredentialsA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredReadDomainCredentialsW
	BOOL CAdvAPI32::CredReadDomainCredentialsW( PCREDENTIAL_TARGET_INFORMATION TargetInfo, DWORD Flags, DWORD* Count, PCREDENTIAL** Credentials )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredReadDomainCredentialsW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredReadDomainCredentialsW );
		bResult = Call< BOOL, PCREDENTIAL_TARGET_INFORMATION, DWORD, DWORD*, PCREDENTIAL** >( pFunc, TargetInfo, Flags, Count, Credentials );
#else
		QOR_PP_UNREF4( TargetInfo, Flags, Count, Credentials );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredReadDomainCredentialsW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredReadA
	BOOL CAdvAPI32::CredReadA( LPCSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIAL* Credential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredReadA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredReadA );
		bResult = Call< BOOL, LPCSTR, DWORD, DWORD, PCREDENTIAL* >( pFunc, TargetName, Type, Flags, Credential );
#else
		QOR_PP_UNREF4( TargetName, Type, Flags, Credential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredReadA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredReadW
	BOOL CAdvAPI32::CredReadW( LPCWSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIAL* Credential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredReadW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredReadW );
		bResult = Call< BOOL, LPCWSTR, DWORD, DWORD, PCREDENTIAL* >( pFunc, TargetName, Type, Flags, Credential );
#else
		QOR_PP_UNREF4( TargetName, Type, Flags, Credential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredReadW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredRenameA
	BOOL CAdvAPI32::CredRenameA( LPCSTR OldTargetName, LPCSTR NewTargetName, DWORD Type, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredRenameA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredRenameA );
		bResult = Call< BOOL, LPCSTR, LPCSTR, DWORD, DWORD >( pFunc, OldTargetName, NewTargetName, Type, Flags );
#else
		QOR_PP_UNREF4( OldTargetName, NewTargetName, Type, Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredRenameA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredRenameW
	BOOL CAdvAPI32::CredRenameW( LPCWSTR OldTargetName, LPCWSTR NewTargetName, DWORD Type, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredRenameW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredRenameW );
		bResult = Call< BOOL, LPCWSTR, LPCWSTR, DWORD, DWORD >( pFunc, OldTargetName, NewTargetName, Type, Flags );
#else
		QOR_PP_UNREF4( OldTargetName, NewTargetName, Type, Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredRenameW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredUnmarshalCredentialA
	BOOL CAdvAPI32::CredUnmarshalCredentialA( LPCSTR MarshaledCredential, PCRED_MARSHAL_TYPE CredType, PVOID* Credential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredUnmarshalCredentialA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredUnmarshalCredentialA );
		bResult = Call< BOOL, LPCSTR, PCRED_MARSHAL_TYPE, PVOID* >( pFunc, MarshaledCredential, CredType, Credential );
#else
		QOR_PP_UNREF( MarshaledCredential );
		QOR_PP_UNREF( CredType );
		QOR_PP_UNREF( Credential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredUnmarshalCredentialA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredUnmarshalCredentialW
	BOOL CAdvAPI32::CredUnmarshalCredentialW( LPCWSTR MarshaledCredential, PCRED_MARSHAL_TYPE CredType, PVOID* Credential )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredUnmarshalCredentialW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredUnmarshalCredentialW );
		bResult = Call< BOOL, LPCWSTR, PCRED_MARSHAL_TYPE, PVOID* >( pFunc, MarshaledCredential, CredType, Credential );
#else
		QOR_PP_UNREF( MarshaledCredential );
		QOR_PP_UNREF( CredType );
		QOR_PP_UNREF( Credential );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredUnmarshalCredentialW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredWriteA
	BOOL CAdvAPI32::CredWriteA( PCREDENTIAL Credential, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredWriteA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredWriteA );
		bResult = Call< BOOL, PCREDENTIAL, DWORD >( pFunc, Credential, Flags );
#else
		QOR_PP_UNREF( Credential );
		QOR_PP_UNREF( Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredWriteA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredWriteW
	BOOL CAdvAPI32::CredWriteW( PCREDENTIAL Credential, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredWriteW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredWriteW );
		bResult = Call< BOOL, PCREDENTIAL, DWORD >( pFunc, Credential, Flags );
#else
		QOR_PP_UNREF( Credential );
		QOR_PP_UNREF( Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredWriteW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredWriteDomainCredentialsA
	BOOL CAdvAPI32::CredWriteDomainCredentialsA( PCREDENTIAL_TARGET_INFORMATION TargetInfo, PCREDENTIAL Credential, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredWriteDomainCredentialsA" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredWriteDomainCredentialsA );
		bResult = Call< BOOL, PCREDENTIAL_TARGET_INFORMATION, PCREDENTIAL, DWORD >( pFunc, TargetInfo, Credential, Flags );
#else
		QOR_PP_UNREF( TargetInfo );
		QOR_PP_UNREF( Credential );
		QOR_PP_UNREF( Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredWriteDomainCredentialsA"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

	//------------------------------------------------------------------------------
	//CredWriteDomainCredentialsW
	BOOL CAdvAPI32::CredWriteDomainCredentialsW( PCREDENTIAL_TARGET_INFORMATION TargetInfo, PCREDENTIAL Credential, DWORD Flags )
	{
		_WINQ_FCONTEXT( "CAdvAPI32::CredWriteDomainCredentialsW" );
		CCheckReturn< BOOL, CBoolCheck< > >::TType bResult;
#if		( _WIN32_WINNT >= 0x0501 )
		_WINQ_USESAPI( CredWriteDomainCredentialsW );
		bResult = Call< BOOL, PCREDENTIAL_TARGET_INFORMATION, PCREDENTIAL, DWORD >( pFunc, TargetInfo, Credential, Flags );
#else
		QOR_PP_UNREF( TargetInfo );
		QOR_PP_UNREF( Credential );
		QOR_PP_UNREF( Flags );
		__WINQAPI_CONT_ERROR(( API_REQUIRES_VERSION, _T("CredWriteDomainCredentialsW"), _T( "Windows XP" ), 0 ));
#endif//( _WIN32_WINNT >= 0x0501 )
		return bResult;
	}

}//nsWinQAPI
