//Error.h

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

//Declares CError. A class to represent errors and other out of flow conditions

#ifndef CODEQOR_ERROR_H_1
#define CODEQOR_ERROR_H_1

#include "CodeQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Text/TString.h"
#include "CodeQOR/Instancing/STMember.h"
#include "CodeQOR/Traits/Policy.h"
#include "CodeQOR/Tracing/ObjectContextBase.h"

//Declare some macros to make raising and handling errors easier

#if		( __QOR_PERFORMANCE != __QCS_MAX_PERFORMANCE_ )

#	define __QCS_RAISE_ERROR( _PARAMS, Level )												\
	nsCodeQOR::CError::Raise( __FILE__ ,__LINE__ , _FContext_.Name().astr(),				\
		nsCodeQOR::CError::CBaseErrorParams _PARAMS , &ErrorDomain, Level );

#	define __QCS_FATAL_ERROR( _PARAMS )			__QCS_RAISE_ERROR( _PARAMS, nsCodeQOR::CError::ERR_LVL_FATAL )
#	define __QCS_SERIOUS_ERROR( _PARAMS )		__QCS_RAISE_ERROR( _PARAMS, nsCodeQOR::CError::ERR_LVL_SERIOUS )
#	define __QCS_CONTINUABLE_ERROR( _PARAMS )	__QCS_RAISE_ERROR( _PARAMS, nsCodeQOR::CError::ERR_LVL_CONTINUE )
#	define __QCS_WARNING( _PARAMS )				__QCS_RAISE_ERROR( _PARAMS, nsCodeQOR::CError::ERR_LVL_WARNING )
#	define __QCS_NOTE( _PARAMS )				__QCS_RAISE_ERROR( _PARAMS, nsCodeQOR::CError::ERR_LVL_NOTE )

#	define __QCS_TRACE( _FUNC, _TRACE_TEXT )	nsCodeQOR::CError::Raise( __FILE__, __LINE__, _FUNC, \
	nsCodeQOR::CError::CBaseErrorParams( _TRACE_TEXT ), &ErrorDomain, nsCodeQOR::CError::ERR_LVL_NOTE );

//Integrate errors with exception handling
#if __QOR_CPP_EXCEPTIONS
#	define __QCS_PROTECT try

#	define __QCS_ENDPROTECT						\
	catch( nsCodeQOR::CError* pError )			\
	{											\
		pError->Catch();						\
	}											\
	catch( ... )								\
	{											\
		throw;									\
	}//rethrow all unhandled exceptions
#else
#   define __QCS_PROTECT
#   define __QCS_ENDPROTECT
#endif

#else//__QOR_PERFORMANCE == __QCS_MAX_PERFORMANCE_ is defined so neutralize all error raising and handling
	#define __QCS_FATAL_ERROR( Description )
	#define __QCS_SERIOUS_ERROR( Description )
	#define __QCS_CONTINUABLE_ERROR( Description )
	#define __QCS_WARNING( Description )
	#define __QCS_NOTE( Description )
	#define __QCS_PROTECT
	#define __QCS_ENDPROTECT
	//#pragma warning (disable : 4390 )//Don't report empty controlled statements due to missing error reporting
#endif

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	class __QOR_INTERFACE( __CODEQOR ) CBaseErrorDomain;
	class __QOR_INTERFACE( __CODEQOR ) CWhat;
	class __QOR_INTERFACE( __CODEQOR ) CWhere;
	class __QOR_INTERFACE( __CODEQOR ) CWhen;
	class __QOR_INTERFACE( __CODEQOR ) CProcessBase;
	class __QOR_INTERFACE( __CODEQOR ) CLoadableModuleBase;

	//--------------------------------------------------------------------------------
	//A base class for a property of an Error
	//This means a string representation of each property will always be available
	class __QOR_INTERFACE( __CODEQOR ) CErrorPropertyBase
	{
	public:

		CErrorPropertyBase();
		CErrorPropertyBase( const CErrorPropertyBase& );
		CErrorPropertyBase& operator = ( const CErrorPropertyBase& );
		virtual ~CErrorPropertyBase();
		virtual CErrorPropertyBase* Clone( void );

		CString GetDescription( void );
		void SetDescription( CString& strDesc );

	protected:

		CString m_strErrorDesc;
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CError
	{
	public:

		//--------------------------------------------------------------------------------
		//A container to hold pointers to whatever parameters are part of the error
		class __QOR_INTERFACE( __CODEQOR ) CBaseErrorParams
		{
		public:

			__QCMP_STATIC_CONSTANT( unsigned char, sMaxParams = CPolicy::MAX_ERROR_PARAMETERS );

			CBaseErrorParams();
			CBaseErrorParams( unsigned int uiCode, ... );			//Construct a parameter holder from a code and a null terminated sequence of parameters
			CBaseErrorParams( CBaseErrorParams const& src );
			virtual ~CBaseErrorParams();

			void* operator[]( unsigned int uiIndex );				//Retrieve a parameter address
			unsigned int Code();									//Retrieve the error code

		protected:

			unsigned int m_uiCode;									//Every error needs an identity to link it to additional information
			void* m_pParams[ sMaxParams ];							//Array of parameter addresses

		private:

			CBaseErrorParams& operator = ( CBaseErrorParams const& );
		};


		static CString ErrorLevel[];								//Names for the severity categories

		//--------------------------------------------------------------------------------
		//Error and out of flow conditions are divided into the following categories
		typedef enum E_LEVEL
		{
			ERR_LVL_FATAL,		//A non recoverable situation in which we should report as much about the cause as possible and then terminate
			ERR_LVL_SERIOUS,	//A serious error from which recovery is unlikely but a relatively clean shutdown might be attempted
			ERR_LVL_CONTINUE,	//A possibly recoverable error after which we may be able to continue safe execution
			ERR_LVL_WARNING,	//A warning, not an error yet and no need to stop the program but a problem may be indicated
			ERR_LVL_NOTE,		//Not a problem just an informational note which can always be safely ignored
		}Level;

		CError();
		CError( const CError& src );
		CError& operator = ( const CError& src );

		CWhere& Where();
		CWhat& What();
		CWhen& When();

		static void Raise( const char* szFile, int iLine, const char* szFunc, CObjectContextBase& ObjContext, CBaseErrorParams Params, CBaseErrorDomain* pDomain, CError::Level eLevel );
		static void Raise( const char* szFile, int iLine, nsCodeQOR::CCodeString szFunc, CObjectContextBase& ObjContext, CBaseErrorParams Params, CBaseErrorDomain* pDomain, CError::Level eLevel );
		static void Raise( const char* strFile, int iLine, const char* szFunc, CObjectContextBase& ObjContext, unsigned int uiErrCode, CBaseErrorDomain* pDomain, CError::Level eLevel );
		static void Raise( unsigned int uiErrCode, nsCodeQOR::CBaseErrorDomain* pDomain, CError::Level eLevel );

		virtual void Catch( void );					//process an Error caught by an exception catch clause
		virtual bool Handle(void);					//handle an error by passing it to the appropriate error handler
		virtual void Resolved( bool bResolved );	//What to do if an error is or isn't resolved by the handler

		CString Description( void );				//Retrieve the full formatted text description

	protected:

		virtual ~CError();							//Errors can only be destroyed by being handled so destruction is protected

		//The what, when and where properties of an error. These are 'replaceable' by derived classes so that additional data can be added

		CSTMember< CErrorPropertyBase > m_What;
		CSTMember< CErrorPropertyBase > m_Where;
		CSTMember< CErrorPropertyBase > m_When;

	};

}//nsCodeQOR

#endif//CODEQOR_ERROR_H_1
