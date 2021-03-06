//BfPipeline.h

// Copyright Querysoft Limited 2013, 2016
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

#ifndef BLUEFOOT_PIPELINE_H_3
#define BLUEFOOT_PIPELINE_H_3

//Defines a Bluefoot pipeline

#include "BFElement.h"
#include "BFFilter.h"

//------------------------------------------------------------------------------
namespace nsBluefoot
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CPipeline : public CElement
	{
	public:

		//------------------------------------------------------------------------------
		enum eFilterPos
		{
			eBeforeSink,
			eAfterSource,
		};

		CPipeline();
		virtual ~CPipeline();
		CPipeline(const CPipeline& src);
		CPipeline& operator = (const CPipeline& src);

		//------------------------------------------------------------------------------
		template< class TSourceConnection, class TSinkConnection  > 
		CPipeline( TSourceConnection& SourceConnection, TSinkConnection& SinkConnection, CElement::eFlowMode FlowMode = ePull ) : m_FlowMode( FlowMode ), m_pSource( 0 ), m_pSink( 0 )
		{
			SetSource( SourceConnection.GetSource() );
			SetSink( SinkConnection.GetSink() );
		}

		//------------------------------------------------------------------------------
		eFlowMode GetMode(void)
		{
			return m_FlowMode;
		}

		//------------------------------------------------------------------------------
		void SetMode(eFlowMode FlowMode)
		{
			m_FlowMode = FlowMode;
		}

		void SetSink( CSink* pSink );
		CSink* GetSink( void );
		void SetSource( CSource* pSource );
		CSource* GetSource( void );

		virtual void Run( void );
		bool Pump( void );

		virtual bool Pump( unsigned long& ulNumberOfUnitsPumped, unsigned long ulNumberOfUnitsToPump = 1 );
		virtual void InsertFilter( CFilter* pFilter, eFilterPos Pos = eBeforeSink );

	protected:

		eFlowMode m_FlowMode;
		CSource* m_pSource;
		CSink* m_pSink;

	};

}//nsBluefoot

#endif//BLUEFOOT_PIPELINE_H_3
