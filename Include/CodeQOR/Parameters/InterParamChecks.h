//InterParamChecks.h

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

//Facilitate testing of one parameter against another when passed between context tracked functions

#ifndef CODEQOR_INTERPARAMCHECKS_H_1
#define CODEQOR_INTERPARAMCHECKS_H_1

#include "CodeQOR/Tracing/CallContextBase.h"
#include "CodeQOR/Parameters/PChecks/TRangeChecks.h"
#include "CodeQOR/Parameters/PChecks/PointerChecks.h"

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __CODEQOR ) CInterCheckBase
	{
	public:

		CInterCheckBase();
		virtual ~CInterCheckBase();

		static CParameterBase* GetParameter( int iParam );
	};

	//--------------------------------------------------------------------------------
	template< class TCheckedParam, class TCheck >
	class CInterCheckParam : public CInterCheckBase
	{
	public:

		typedef typename TCheckedParam::TTarget TParam;

		//--------------------------------------------------------------------------------
		//Caller will initiate check on parameter construction
		CInterCheckParam( TParam param ) : CInterCheckBase(), m_Param( param )
		{
			TCheck::Check( m_Param );
		}

		//--------------------------------------------------------------------------------
		//Callee will get the paramter it needs via this type cast operator
		operator TParam()
		{
			return m_Param;//return the internal parameter instance
		}

	protected:

		TCheckedParam m_Param;			//Instance of parameter type

	};

	//--------------------------------------------------------------------------------
	//Template for >= checks
	template< typename TPType, int iParam >
	class CTInterLargerEqualCheck
	{
	public:

		//--------------------------------------------------------------------------------
		template< typename TPSrcType >
		static void Check( TPSrcType& src )
		{
			CParameterBase* pParamBase = CInterCheckBase::GetParameter( iParam );
			CCallContextBase::CParameterPass< TPType >* pParam = ( dynamic_cast< nsCodeQOR::CCallContextBase::CParameterPass< TPType >* >( pParamBase ) );
			if( pParam )
			{
				TPType& refParam( pParam->ParamterRef() );
				nsParamChecking::CLargerEqualCheck::Check( src, refParam );
			}
		}

	};

	//--------------------------------------------------------------------------------
	//Template for <= checks
	template< typename TPType, int iParam >
	class CTInterSmallerEqualCheck
	{
	public:

		//--------------------------------------------------------------------------------
		template< typename TPSrcType >
		static void Check( TPSrcType& src )
		{
			CParameterBase* pParamBase = CInterCheckBase::GetParameter( iParam );
			CCallContextBase::CParameterPass< TPType >* pParam = ( dynamic_cast< nsCodeQOR::CCallContextBase::CParameterPass< TPType >* >( pParamBase ) );
			if( pParam )
			{
				TPType& refParam( pParam->ParamterRef() );
				nsParamChecking::CSmallerEqualCheck::Check( src, refParam );
			}
		}

	};

	//------------------------------------------------------------------------------
	//Try to check that an array is at least as big as the parameter at index iParam claims it is
	template< typename T, int iParam >
	class CTArrayNCheck
	{
	public:
		static void Check( T pElem )
		{
			CParameterBase* pParamBase = CInterCheckBase::GetParameter( iParam );
			unsigned int& refParam( ( reinterpret_cast< CCallContextBase::CParameterPass< unsigned int >* >( pParamBase ) )->ParamterRef() );
			nsParamChecking::CRWPointerCheck::Check( const_cast< const void* >( reinterpret_cast< void* >( pElem ) ), refParam * sizeof( *pElem ) );
		}
	};

}//nsCodeQOR

#endif//CODEQOR_INTERPARAMCHECKS_H_1
