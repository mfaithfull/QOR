//ErrorDomain.h

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

#ifndef WINQAPI_ERR_DOMAIN_H_1
#define WINQAPI_ERR_DOMAIN_H_1

#include "WinQAPI/WinQAPI.h"
#include "CodeQOR/Macros/codingmacros.h"
#include "Error.h"
#include "CodeQOR/ErrorSystem/BaseErrorDomain.h"

#define __WINQAPI_ERROR __WINQAPI_CONT_ERROR(( GENERAL_API_ERROR, _FContext_.Name(), 0 ))

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) CErrorDomain;
	__QOR_INTERFACE( __WINQAPI ) CErrorDomain* ErrorDomainPtr( void );

	//--------------------------------------------------------------------------------
	enum E_Notes
	{
        TAG_NOTE = nsCodeQOR::CBaseErrorDomain::MAX_NOTES,
		MAX_NOTES //Always last
	};

	//--------------------------------------------------------------------------------
	enum E_Warnings
	{
        RESULT_INDICATES_FAILURE_OR_PENDING = nsCodeQOR::CBaseErrorDomain::MAX_WARNS,
		BUFFER_INADEQUATE,
		API_RETURNED_NO_DATA,
		RESULT_INDICATES_UNSUPPORTED_FEATURE,
		UNRELIABLE_API,
		RETURN_MAY_INDICATE_SECURITY_ISSUE,
		RESULT_INDICATES_INFO_UNAVAILABLE,
		API_TIMEOUT_OR_FAILURE,//
		MAX_WARNINGS //Always Last
	};

	//--------------------------------------------------------------------------------
	enum E_Errors
	{
        GENERAL_API_ERROR = ( nsCodeQOR::CBaseErrorDomain::MAX_ERRORS ),
		API_REQUIRES_VERSION,
		NO_STANDARD_HANDLE,
		TAPE_API_ERROR,
		API_FAILED,
		APP_RECOVERY_API_ERROR,
		SNAPSHOT_API_ERROR,
		LZ_API_ERROR,
		WINEXEC_API_ERROR,
		DDE_API_ERROR,
		DDEML_API_ERROR,
		API_WAIT_FAILED,
		DISP_CHANGE_API_ERROR,
		SPOOLER_API_ERROR,
		DIRECTORY_API_ERROR,

		NAMED_KERNELOBJ_NOT_FOUND,
		API_INVALID_PARAMETER,

		API_RETURNED_NTSTATUS,
		SEH_ERROR,
		INVALID_SID,
		SECURITY_ERROR,

		UNINITIALIZED_PARAMETER,

		API_NOT_IN_MINGW32,
		MISSING_LIBRARY_FUNCTION,

		WINSOCK_ERROR,

		MAX_ERROR //Always last
	};

#	define _ERR_SEVERITY_ &CErrorDomain::GetSeverity
#	define _ERR_PARAM0_ &CErrorDomain::GetParam< 0 >
#	define _ERR_PARAM1_ &CErrorDomain::GetParam< 1 >
#   define _ERR_PARAM2_ &CErrorDomain::GetParam< 2 >
#	define _ERR_SOURCE_ &CErrorDomain::GetSource

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQAPI ) CErrorDomain : public nsCodeQOR::CBaseErrorDomain
	{
	public:

		__QCMP_STATIC_CONSTANT( unsigned short, Max_OS_Message_Size = 1024 );

		CErrorDomain();
		virtual ~CErrorDomain();
		virtual bool GetDescription( mxTCHAR** ppDescription, nsCodeQOR::CError* pError );
		//virtual void ReportError( mxTCHAR* );

	protected:

		typedef void* ( CErrorDomain::*fpWin32ErrorDescriptor )( nsCodeQOR::CError* pError );

		//--------------------------------------------------------------------------------
		struct s_WinQAPIError
		{
			const mxTCHAR* pText;
			fpWin32ErrorDescriptor pDescriptorFuncs[ MAX_ERRPARTS ];
		};

		//--------------------------------------------------------------------------------
		template< int i >
		void* GetParam( nsCodeQOR::CError* pError )
		{
			void* psz = 0;
			if( pError != 0 )
			{
				psz = pError->What().Parameter( static_cast< unsigned char >( i ) );
			}
			return psz;
		}

		void* GetWinError( nsCodeQOR::CError* pError, unsigned int ui );
		void* GetNTStatusMsg( nsCodeQOR::CError* pError, unsigned int ui );

		//--------------------------------------------------------------------------------
		template< unsigned int ui >
		void* GetWinError( nsCodeQOR::CError* pError )
		{
			return GetWinError( pError, ui );
		}

		//--------------------------------------------------------------------------------
		template< unsigned int ui >
		void* GetNTStatus( nsCodeQOR::CError* pError )
		{
			return GetNTStatusMsg( pError, ui );		//Get the NTStatus message corresponding to the value of parameter ui
		}


		//--------------------------------------------------------------------------------
		template< unsigned int ui >
		void* GetDDEError( nsCodeQOR::CError* pError )
		{
			void* pResult = _T( "<DDE Error message>" );
			//Get the DDE Error message corresponding to the value of parameter ui
			return pResult;
		}

		//--------------------------------------------------------------------------------
		template< unsigned int ui >
		void* GetDispChangeError( nsCodeQOR::CError* pError )
		{
			mxTCHAR* pResult = _T( "<Disp Change Error>" );
			//Get the Disp Change Error message corresponding to the value of parameter ui
			/*
			#define DISP_CHANGE_SUCCESSFUL       0
			#define DISP_CHANGE_RESTART          1
			#define DISP_CHANGE_FAILED          -1
			#define DISP_CHANGE_BADMODE         -2
			#define DISP_CHANGE_NOTUPDATED      -3
			#define DISP_CHANGE_BADFLAGS        -4
			#define DISP_CHANGE_BADPARAM        -5
			#if(_WIN32_WINNT >= 0x0501)
			#define DISP_CHANGE_BADDUALVIEW     -6
			#endif // _WIN32_WINNT >= 0x0501
			*/
			return pResult;
		}

		//--------------------------------------------------------------------------------

		void* GetSeverity( nsCodeQOR::CError* pError );
		void* GetSource( nsCodeQOR::CError* pError );
		void* GetOSError( nsCodeQOR::CError* pError );

		virtual const nsCodeQOR::CBaseErrorDomain::s_BaseError* NoteTemplate( unsigned int uiCode );
		virtual const nsCodeQOR::CBaseErrorDomain::s_BaseError* WarningTemplate( unsigned int uiCode );
		virtual const nsCodeQOR::CBaseErrorDomain::s_BaseError* ErrorTemplate( unsigned int uiCode );
		virtual unsigned int GetErrorParts( nsCodeQOR::CError* pError, const nsCodeQOR::CBaseErrorDomain::s_BaseError& ErrorTemplate, mxTCHAR** ppszParts );

		typedef mxTCHAR* ( CErrorDomain::*fpErrorDescriptor )( nsCodeQOR::CError* pError );

		static const s_WinQAPIError m_Notes[ MAX_NOTES ];
		static const s_WinQAPIError m_Warnings[ MAX_WARNINGS ];
		static const s_WinQAPIError m_Errors[ MAX_ERROR ];

	private:

		__QCS_DECLARE_NONCOPYABLE( CErrorDomain );

	};

}//nsWinQAPI

#endif//WINQAPI_ERR_DOMAIN_H_1
