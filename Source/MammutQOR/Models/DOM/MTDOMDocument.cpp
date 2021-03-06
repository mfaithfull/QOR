//MTDOMDocument.cpp

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

#include "MammutQOR/Models/DOM/MTDOMDocument.h"

#define ATT_DOCTYPE		_TXT( "DocType" )
#define ATT_IMPL		_TXT( "Implementation" )
#define ATT_DOCELEMENT	_TXT( "DocumentElement" )

//------------------------------------------------------------------------------
namespace nsMammut
{
	//------------------------------------------------------------------------------
	CDocument::CDocument(CModel* pContainer) : CDOMNode(pContainer)
	, m_DocType(this, ATT_DOCTYPE)
	, m_Implementation( this, ATT_IMPL)
	, m_DocumentElement( this, ATT_DOCELEMENT)
	{
		m_NodeType.Set(CMUint16(DOCUMENT_NODE));
	}

	//------------------------------------------------------------------------------
	CDocument::CDocument(const CDocument& src) : CDOMNode(src)
	, m_DocType( this, src.m_DocType )
	, m_Implementation(this, src.m_Implementation )
	, m_DocumentElement(this, src.m_DocumentElement)
	{
	}

	//--------------------------------------------------------------------------------
	//Construct from a generic PropertySet
	CDocument::CDocument(CPropertySet& src) : CDOMNode(src)
	, m_DocType(this, ATT_DOCTYPE, src[ ATT_DOCTYPE ] )
	, m_Implementation(this, ATT_IMPL, src[ ATT_IMPL ] )
	, m_DocumentElement(this, ATT_DOCELEMENT, src[ ATT_DOCELEMENT ] )
	{
		m_NodeType.Set(CMUint16(DOCUMENT_NODE));
	}

	//------------------------------------------------------------------------------
	CDocument::~CDocument()
	{
	}

	//------------------------------------------------------------------------------
	CDocument& CDocument::operator = (const CDocument& src)
	{
		if (&src != this)
		{
			CDOMNode::operator=(src);
			m_DocType = src.m_DocType;
			m_Implementation = src.m_Implementation;
			m_DocumentElement = src.m_DocumentElement;
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	//assign from a generic property set
	CDocument& CDocument::operator = (CPropertySet& src)
	{
		if (&src != this)
		{
			CDOMNode::operator=(src);
			m_DocType = src[ATT_DOCTYPE];
			m_Implementation = src[ATT_IMPL];
			m_DocumentElement = src[ATT_DOCELEMENT];
		}
		return *this;
	}

	//------------------------------------------------------------------------------
	bool CDocument::operator == (const CDocument& src)
	{
		return &(const_cast< CDocument& >(src)) == this ? true : false;
	}

	//------------------------------------------------------------------------------
	CElement CDocument::CreateElement(nsCodeQOR::CUCS2String& TagName)
	{
		CElement* pNewElement = new CElement(this);
		pNewElement->m_TagName.Set(TagName);
		return *pNewElement;
	}

	//------------------------------------------------------------------------------
	CDocumentFragment CDocument::CreateDocumentFragment(void)
	{
		return *new CDocumentFragment(this);
	}

	//------------------------------------------------------------------------------
	CText CDocument::CreateTextNode(nsCodeQOR::CUCS2String& Data)
	{
		return *new CText(this);
	}

	//------------------------------------------------------------------------------
	CComment CDocument::CreateComment(nsCodeQOR::CUCS2String& Data)
	{
		return *new CComment(this);
	}

	//------------------------------------------------------------------------------
	CDATASection CDocument::CreateCDATASection(nsCodeQOR::CUCS2String& Data)
	{
		return *new CDATASection(this);
	}

	//------------------------------------------------------------------------------
	CProcessingInstruction CDocument::CreateProcessingInstruction(nsCodeQOR::CUCS2String& Target, nsCodeQOR::CUCS2String& Data)
	{
		return *new CProcessingInstruction(this);
	}

	//------------------------------------------------------------------------------
	CAttr CDocument::CreateAttribute(nsCodeQOR::CUCS2String& Name)
	{
		return *new CAttr(this);
	}

	//------------------------------------------------------------------------------
	CEntityReference CDocument::CreateEntityReference(nsCodeQOR::CUCS2String& Name)
	{
		return *new CEntityReference(this);
	}

	//------------------------------------------------------------------------------
	CVectorModel< CDOMNode > CDocument::GetElementsByTagName(nsCodeQOR::CUCS2String& TagName)
	{
		CVectorModel< CDOMNode > Collection;
		//TODO:
		return Collection;
	}

	//------------------------------------------------------------------------------
	bool CDocument::ValidChildType( CMUint16 NodeType )
	{
		return ( NodeType == COMMENT_NODE || NodeType == PROCESSING_INSTRUCTION_NODE );
	}

}//nsMammut

