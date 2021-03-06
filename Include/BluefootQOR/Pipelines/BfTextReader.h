//BfTextReader.h

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

#ifndef BLUEFOOT_PIPELINES_TEXTREADER_H_3
#define BLUEFOOT_PIPELINES_TEXTREADER_H_3

//Defines a Bluefoot text reader pipeline

#include "BluefootQOR/BFPipeline.h"
#include "BluefootQOR/Filters/BOMRecognizerFilter.h"
#include "BluefootQOR/Filters/UTF8CodePointFilter.h"
#include "BluefootQOR/Filters/UTF16CodePointFilter.h"
#include "BluefootQOR/Sinks/StringSink.h"
#include "AppocritaQOR/Event.h"

//------------------------------------------------------------------------------
namespace nsBluefoot
{
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CTextReader;

	//------------------------------------------------------------------------------
	class CRecognizerEventSink : public nsQOR::CEventSink
	{
	public:

		CRecognizerEventSink( CTextReader* pContainer );
		virtual bool operator()( nsQOR::IEvent::ref_type, int iCookie );

	protected:

		CTextReader* m_pContainer;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CTextReader : public CPipeline
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CTextReader );

		CTextReader( CSource* pSource );
		virtual ~CTextReader();
		CTextReader(const CTextReader& src);
		CTextReader& operator = (const CTextReader& src);

		virtual void OnRecognizerEvent( CBOMRecognizedEvent::eBOMType BOMType );

	protected:

		CBOMRecognizerFilter m_BOMRecognizer;
		CRecognizerEventSink m_RecognizerEventSink;

		nsCodeQOR::CSTMember< CUTF16CodePointFilter > m_UTF16Filter;
		nsCodeQOR::CSTMember< CUTF8CodePointFilter > m_UTF8Filter;

		CUCS4StringSink m_StringSink;
	};

}//nsBluefoot

#endif//BLUEFOOT_PIPELINES_TEXTREADER_H_3
