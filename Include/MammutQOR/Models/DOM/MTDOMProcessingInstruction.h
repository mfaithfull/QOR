//MTDOMProcessingInstruction.h

// Copyright Querysoft Limited 2015
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

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef MAMMUTQOR_MODELS_DOM_PI_H_3
#define MAMMUTQOR_MODELS_DOM_PI_H_3

#include "MammutQOR/Models/DOM/MTDOMNode.h"
#include "MammutQOR/Models/DOM/MTXMLDOM.h"

//------------------------------------------------------------------------------
namespace nsMammut
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE(__MAMMUT) CProcessingInstruction : public CDOMNode
	{
	public:

		typedef CDOMNode BaseType;

		CProcessingInstruction(CModel* pContainer = 0);
		CProcessingInstruction(const CProcessingInstruction& src);
		CProcessingInstruction(CPropertySet& src);

		virtual ~CProcessingInstruction();

		CProcessingInstruction& operator = (const CProcessingInstruction& src);
		CProcessingInstruction& operator = (CPropertySet& src);

		bool operator == (const CProcessingInstruction& src);

		virtual CDOMNode& InsertBefore( CDOMNode& newChild, CDOMNode& refChild );
		virtual CDOMNode& ReplaceChild( CDOMNode& newChild, CDOMNode& oldChild );
		virtual CDOMNode& RemoveChild( CDOMNode& oldChild );
		virtual CDOMNode& AppendChild( CDOMNode& newChild );
		virtual bool HasChildNodes( void );

		CProperty< CDOMString > m_Target;
		CProperty< CDOMString > m_Data;

	};

}//nsMammut

#endif//MAMMUTQOR_MODELS_DOM_PI_H_3
