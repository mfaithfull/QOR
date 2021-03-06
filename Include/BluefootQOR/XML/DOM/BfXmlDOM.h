//BfXmlDOM.h

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

//Derived from QtSDK/QtSources/4.8.0/src/xml/dom/qdom.h under the following LGPL license:-

/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef BLUEFOOT_XML_DOM_H_3
#define BLUEFOOT_XML_DOM_H_3

#include "CodeQOR/Text/TString.h"
#include "BluefootQOR/Sources/StringSource.h"

//------------------------------------------------------------------------------
namespace nsBluefoot
{

	class CIODevice;
	class CTextStream;

	//class CXmlInputSource;
	class CXmlReader;

	class CDomDocumentPrivate;
	class CDomDocumentTypePrivate;
	class CDomDocumentFragmentPrivate;
	class CDomNodePrivate;
	class CDomNodeListPrivate;
	class CDomImplementationPrivate;
	class CDomElementPrivate;
	class CDomNotationPrivate;
	class CDomEntityPrivate;
	class CDomEntityReferencePrivate;
	class CDomProcessingInstructionPrivate;
	class CDomAttrPrivate;
	class CDomCharacterDataPrivate;
	class CDomTextPrivate;
	class CDomCommentPrivate;
	class CDomCDATASectionPrivate;
	class CDomNamedNodeMapPrivate;
	class CDomImplementationPrivate;

	class CDomNodeList;
	class CDomElement;
	class CDomText;
	class CDomComment;
	class CDomCDATASection;
	class CDomProcessingInstruction;
	class CDomAttr;
	class CDomEntityReference;
	class CDomNamedNodeMap;
	class CDomDocument;
	class CDomDocumentFragment;
	class CDomDocumentType;
	class CDomImplementation;
	class CDomNode;
	class CDomEntity;
	class CDomNotation;
	class CDomCharacterData;

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomImplementation
	{
	public:
		CDomImplementation();
		CDomImplementation( const CDomImplementation& );
		~CDomImplementation();
		CDomImplementation& operator= ( const CDomImplementation& );
		bool operator== ( const CDomImplementation& ) const;
		bool operator!= ( const CDomImplementation& ) const;

		// functions
		bool hasFeature( const nsCodeQOR::CUCS2String& feature, const nsCodeQOR::CUCS2String& version ) const;
		CDomDocumentType createDocumentType( const nsCodeQOR::CUCS2String& qName, const nsCodeQOR::CUCS2String& publicId, const nsCodeQOR::CUCS2String& systemId );
		CDomDocument createDocument( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& qName, const CDomDocumentType& doctype );

		//------------------------------------------------------------------------------
		enum InvalidDataPolicy 
		{ 
			AcceptInvalidChars = 0, 
			DropInvalidChars, 
			ReturnNullNode 
		};

		static InvalidDataPolicy invalidDataPolicy();
		static void setInvalidDataPolicy( InvalidDataPolicy policy );

		bool isNull();

	private:

		CDomImplementationPrivate* impl;
		CDomImplementation( CDomImplementationPrivate* );

		friend class CDomDocument;
	};


	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomNode
	{
	public:

		//------------------------------------------------------------------------------
		enum NodeType 
		{
			ElementNode               = 1,
			AttributeNode             = 2,
			TextNode                  = 3,
			CDATASectionNode          = 4,
			EntityReferenceNode       = 5,
			EntityNode                = 6,
			ProcessingInstructionNode = 7,
			CommentNode               = 8,
			DocumentNode              = 9,
			DocumentTypeNode          = 10,
			DocumentFragmentNode      = 11,
			NotationNode              = 12,
			BaseNode                  = 21,// this is not in the standard
			CharacterDataNode         = 22 // this is not in the standard
		};

		//------------------------------------------------------------------------------
		enum EncodingPolicy
		{
			EncodingFromDocument      = 1,
			EncodingFromTextStream    = 2
		};

		CDomNode();
		CDomNode( const CDomNode& );
		CDomNode& operator= ( const CDomNode& );
		bool operator == ( const CDomNode& ) const;
		bool operator != ( const CDomNode& ) const;
		~CDomNode();

		// DOM functions
		CDomNode insertBefore( const CDomNode& newChild, const CDomNode& refChild );
		CDomNode insertAfter( const CDomNode& newChild, const CDomNode& refChild );
		CDomNode replaceChild( const CDomNode& newChild, const CDomNode& oldChild );
		CDomNode removeChild( const CDomNode& oldChild );
		CDomNode appendChild( const CDomNode& newChild );
		bool hasChildNodes() const;
		CDomNode cloneNode( bool deep = true ) const;
		void normalize();
		bool isSupported( const nsCodeQOR::CUCS2String& feature, const nsCodeQOR::CUCS2String& version ) const;

		// DOM read-only attributes
		nsCodeQOR::CUCS2String nodeName() const;
		NodeType nodeType() const;
		CDomNode parentNode() const;
		CDomNodeList childNodes() const;
		CDomNode firstChild() const;
		CDomNode lastChild() const;
		CDomNode previousSibling() const;
		CDomNode nextSibling() const;
		CDomNamedNodeMap attributes() const;
		CDomDocument ownerDocument() const;
		nsCodeQOR::CUCS2String namespaceURI() const;
		nsCodeQOR::CUCS2String localName() const;
		bool hasAttributes() const;

		// DOM attributes
		nsCodeQOR::CUCS2String nodeValue() const;
		void setNodeValue( const nsCodeQOR::CUCS2String& );
		nsCodeQOR::CUCS2String prefix() const;
		void setPrefix( const nsCodeQOR::CUCS2String& pre );

		// Qt extensions
		bool isAttr() const;
		bool isCDATASection() const;
		bool isDocumentFragment() const;
		bool isDocument() const;
		bool isDocumentType() const;
		bool isElement() const;
		bool isEntityReference() const;
		bool isText() const;
		bool isEntity() const;
		bool isNotation() const;
		bool isProcessingInstruction() const;
		bool isCharacterData() const;
		bool isComment() const;

		//Shortcut to avoid dealing with CDomNodeList all the time.
		CDomNode namedItem( const nsCodeQOR::CUCS2String& name ) const;

		bool isNull() const;
		void clear();

		CDomAttr toAttr() const;
		CDomCDATASection toCDATASection() const;
		CDomDocumentFragment toDocumentFragment() const;
		CDomDocument toDocument() const;
		CDomDocumentType toDocumentType() const;
		CDomElement toElement() const;
		CDomEntityReference toEntityReference() const;
		CDomText toText() const;
		CDomEntity toEntity() const;
		CDomNotation toNotation() const;
		CDomProcessingInstruction toProcessingInstruction() const;
		CDomCharacterData toCharacterData() const;
		CDomComment toComment() const;

		//void save( CTextStream&, int) const;
		//void save( CTextStream&, int, EncodingPolicy ) const; // ### Qt 5: Merge overload(if we at all keep this)

		CDomElement firstChildElement( const nsCodeQOR::CUCS2String& tagName = nsCodeQOR::CUCS2String() ) const;
		CDomElement lastChildElement( const nsCodeQOR::CUCS2String& tagName = nsCodeQOR::CUCS2String() ) const;
		CDomElement previousSiblingElement( const nsCodeQOR::CUCS2String& tagName = nsCodeQOR::CUCS2String() ) const;
		CDomElement nextSiblingElement( const nsCodeQOR::CUCS2String& taName = nsCodeQOR::CUCS2String() ) const;

		int lineNumber() const;
		int columnNumber() const;

	protected:

		CDomNodePrivate* impl;
		CDomNode( CDomNodePrivate* );

	private:

		friend class CDomDocument;
		friend class CDomDocumentType;
		friend class CDomNodeList;
		friend class CDomNamedNodeMap;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomNodeList
	{
	public:

		CDomNodeList();
		CDomNodeList( const CDomNodeList& );
		CDomNodeList& operator= ( const CDomNodeList& );
		bool operator == ( const CDomNodeList& ) const;
		bool operator != ( const CDomNodeList& ) const;
		~CDomNodeList();

		// DOM functions
		CDomNode item( int index ) const;

		//------------------------------------------------------------------------------
		inline CDomNode at( int index ) const 
		{ 
			return item( index ); 
		}

		// DOM read only attributes
		unsigned int length() const;

		//------------------------------------------------------------------------------
		inline int count() const 
		{ 
			return length(); 
		} 

		//------------------------------------------------------------------------------
		inline int size() const 
		{ 
			return length(); 
		}

		//------------------------------------------------------------------------------
		inline bool isEmpty() const 
		{ 
			return length() == 0; 
		}

	private:

		CDomNodeListPrivate* impl;
		CDomNodeList( CDomNodeListPrivate* );

		friend class CDomNode;
		friend class CDomElement;
		friend class CDomDocument;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomDocumentType : public CDomNode
	{
	public:

		CDomDocumentType();
		CDomDocumentType( const CDomDocumentType& x );
		CDomDocumentType& operator = ( const CDomDocumentType& );

		// DOM read only attributes
		nsCodeQOR::CUCS2String name() const;
		CDomNamedNodeMap entities() const;
		CDomNamedNodeMap notations() const;
		nsCodeQOR::CUCS2String publicId() const;
		nsCodeQOR::CUCS2String systemId() const;
		nsCodeQOR::CUCS2String internalSubset() const;

		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return DocumentTypeNode; 
		}

	private:

		CDomDocumentType( CDomDocumentTypePrivate* );

		friend class CDomImplementation;
		friend class CDomDocument;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomDocument : public CDomNode
	{
	public:

		CDomDocument();
		explicit CDomDocument( const nsCodeQOR::CUCS2String& name );
		explicit CDomDocument( const CDomDocumentType& doctype );
		CDomDocument( const CDomDocument& x );
		CDomDocument& operator = ( const CDomDocument& );
		~CDomDocument();

		// DOM functions
		CDomElement createElement( const nsCodeQOR::CUCS2String& tagName );
		CDomDocumentFragment createDocumentFragment();
		CDomText createTextNode( const nsCodeQOR::CUCS2String& data );
		CDomComment createComment( const nsCodeQOR::CUCS2String& data );
		CDomCDATASection createCDATASection( const nsCodeQOR::CUCS2String& data );
		CDomProcessingInstruction createProcessingInstruction( const nsCodeQOR::CUCS2String& target, const nsCodeQOR::CUCS2String& data );
		CDomAttr createAttribute( const nsCodeQOR::CUCS2String& name );
		CDomEntityReference createEntityReference( const nsCodeQOR::CUCS2String& name );
		CDomNodeList elementsByTagName( const nsCodeQOR::CUCS2String& tagname ) const;
		CDomNode importNode( const CDomNode& importedNode, bool deep );
		CDomElement createElementNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& qName );
		CDomAttr createAttributeNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& qName );
		CDomNodeList elementsByTagNameNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName );
		CDomElement elementById( const nsCodeQOR::CUCS2String& elementId );

		// DOM read only attributes
		CDomDocumentType doctype() const;
		CDomImplementation implementation() const;
		CDomElement documentElement() const;

		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const { return DocumentNode; }

		// Qt extensions
		//bool setContent(const QByteArray& text, bool namespaceProcessing, nsCodeQOR::CUCS2String *errorMsg=0, int *errorLine=0, int *errorColumn=0 );
		bool setContent( const nsCodeQOR::CUCS2String& text, bool namespaceProcessing, nsCodeQOR::CUCS2String* errorMsg = 0, int* errorLine = 0, int* errorColumn = 0 );
		//bool setContent(QIODevice* dev, bool namespaceProcessing, nsCodeQOR::CUCS2String *errorMsg=0, int *errorLine=0, int *errorColumn=0 );
		bool setContent( CBFSource* source, bool namespaceProcessing, nsCodeQOR::CUCS2String* errorMsg = 0, int* errorLine = 0, int* errorColumn = 0 );
		//bool setContent(const QByteArray& text, nsCodeQOR::CUCS2String *errorMsg=0, int *errorLine=0, int *errorColumn=0 );
		bool setContent(const nsCodeQOR::CUCS2String& text, nsCodeQOR::CUCS2String *errorMsg=0, int *errorLine=0, int *errorColumn=0 );
		//bool setContent(QIODevice* dev, nsCodeQOR::CUCS2String *errorMsg=0, int *errorLine=0, int *errorColumn=0 );
		bool setContent( CBFSource* source, CXmlReader* reader, nsCodeQOR::CUCS2String* errorMsg = 0, int* errorLine = 0, int* errorColumn = 0 );

		// Qt extensions
		nsCodeQOR::CUCS2String toString(int = 1) const;
		//QByteArray toByteArray(int = 1) const;

	private:

		CDomDocument( CDomDocumentPrivate* );

		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomNamedNodeMap
	{
	public:

		CDomNamedNodeMap();
		CDomNamedNodeMap( const CDomNamedNodeMap& );
		CDomNamedNodeMap& operator = ( const CDomNamedNodeMap& );
		bool operator == ( const CDomNamedNodeMap& ) const;
		bool operator != ( const CDomNamedNodeMap& ) const;
		~CDomNamedNodeMap();

		// DOM functions
		CDomNode namedItem( const nsCodeQOR::CUCS2String& name ) const;
		CDomNode setNamedItem( const CDomNode& newNode );
		CDomNode removeNamedItem( const nsCodeQOR::CUCS2String& name );
		CDomNode item( int index ) const;
		CDomNode namedItemNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName ) const;
		CDomNode setNamedItemNS( const CDomNode& newNode );
		CDomNode removeNamedItemNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName );

		// DOM read only attributes
		unsigned int length() const;

		//------------------------------------------------------------------------------
		int count() const 
		{ 
			return length(); 
		}

		//------------------------------------------------------------------------------
		inline int size() const 
		{ 
			return length(); 
		}

		//------------------------------------------------------------------------------
		inline bool isEmpty() const 
		{ 
			return length() == 0; 
		}

		// Qt extension
		bool contains(const nsCodeQOR::CUCS2String& name) const;

	private:

		CDomNamedNodeMapPrivate* impl;
		CDomNamedNodeMap( CDomNamedNodeMapPrivate* );

		friend class CDomNode;
		friend class CDomDocumentType;
		friend class CDomElement;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomDocumentFragment : public CDomNode
	{
	public:

		CDomDocumentFragment();
		CDomDocumentFragment( const CDomDocumentFragment& x );
		CDomDocumentFragment& operator= ( const CDomDocumentFragment& );

		//------------------------------------------------------------------------------
		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return DocumentFragmentNode; 
		}

	private:

		CDomDocumentFragment( CDomDocumentFragmentPrivate* );

		friend class CDomDocument;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomCharacterData : public CDomNode
	{
	public:

		CDomCharacterData();
		CDomCharacterData( const CDomCharacterData& x );
		CDomCharacterData& operator = ( const CDomCharacterData& );

		// DOM functions
		nsCodeQOR::CUCS2String substringData( unsigned long offset, unsigned long count );
		void appendData( const nsCodeQOR::CUCS2String& arg );
		void insertData( unsigned long offset, const nsCodeQOR::CUCS2String& arg );
		void deleteData( unsigned long offset, unsigned long count );
		void replaceData (unsigned long offset, unsigned long count, const nsCodeQOR::CUCS2String& arg );

		// DOM read only attributes
		unsigned int length() const;

		// DOM attributes
		nsCodeQOR::CUCS2String data() const;
		void setData( const nsCodeQOR::CUCS2String& );

		// Overridden from CDomNode
		CDomNode::NodeType nodeType() const;

	private:

		CDomCharacterData( CDomCharacterDataPrivate* );

		friend class CDomDocument;
		friend class CDomText;
		friend class CDomComment;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomAttr : public CDomNode
	{
	public:

		CDomAttr();
		CDomAttr( const CDomAttr& x );
		CDomAttr& operator = ( const CDomAttr& );

		// DOM read only attributes
		nsCodeQOR::CUCS2String name() const;
		bool specified() const;
		CDomElement ownerElement() const;

		// DOM attributes
		nsCodeQOR::CUCS2String value() const;
		void setValue( const nsCodeQOR::CUCS2String& );

		//------------------------------------------------------------------------------
		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return AttributeNode; 
		}

	private:

		CDomAttr( CDomAttrPrivate* );

		friend class CDomDocument;
		friend class CDomElement;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomElement : public CDomNode
	{
	public:

		CDomElement();
		CDomElement( const CDomElement& x );
		CDomElement& operator = ( const CDomElement& );

		// DOM functions
		nsCodeQOR::CUCS2String attribute( const nsCodeQOR::CUCS2String& name, const nsCodeQOR::CUCS2String& defValue = nsCodeQOR::CUCS2String() ) const;
		void setAttribute( const nsCodeQOR::CUCS2String& name, const nsCodeQOR::CUCS2String& value );
		void setAttribute( const nsCodeQOR::CUCS2String& name, Cmp_long_long value );
		void setAttribute( const nsCodeQOR::CUCS2String& name, Cmp_unsigned_long_long value );

		//------------------------------------------------------------------------------
		inline void setAttribute(const nsCodeQOR::CUCS2String& name, int value)
		{ 
			setAttribute( name, Cmp_long_long( value ) ); 
		}

		//------------------------------------------------------------------------------
		inline void setAttribute( const nsCodeQOR::CUCS2String& name, unsigned int value )
		{ 
			setAttribute( name, Cmp_unsigned_long_long(value) ); 
		}

		void setAttribute( const nsCodeQOR::CUCS2String& name, float value );
		void setAttribute( const nsCodeQOR::CUCS2String& name, double value );
		void removeAttribute( const nsCodeQOR::CUCS2String& name );
		CDomAttr attributeNode( const nsCodeQOR::CUCS2String& name );
		CDomAttr setAttributeNode( const CDomAttr& newAttr );
		CDomAttr removeAttributeNode( const CDomAttr& oldAttr );
		CDomNodeList elementsByTagName( const nsCodeQOR::CUCS2String& tagname ) const;
		bool hasAttribute( const nsCodeQOR::CUCS2String& name ) const;

		nsCodeQOR::CUCS2String attributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& localName, const nsCodeQOR::CUCS2String& defValue = nsCodeQOR::CUCS2String() ) const;
		void setAttributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& qName, const nsCodeQOR::CUCS2String& value );

		//------------------------------------------------------------------------------
		inline void setAttributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& qName, int value )
		{ 
			setAttributeNS( nsURI, qName, Cmp_long_long(value) ); 
		}

		//------------------------------------------------------------------------------
		inline void setAttributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& qName, unsigned int value )
		{ 
			setAttributeNS( nsURI, qName, Cmp_unsigned_long_long( value ) ); 
		}

		void setAttributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& qName, Cmp_long_long value );
		void setAttributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& qName, Cmp_unsigned_long_long value );
		void setAttributeNS( const nsCodeQOR::CUCS2String nsURI, const nsCodeQOR::CUCS2String& qName, double value );
		void removeAttributeNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName );
		CDomAttr attributeNodeNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName );
		CDomAttr setAttributeNodeNS( const CDomAttr& newAttr );
		CDomNodeList elementsByTagNameNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName ) const;
		bool hasAttributeNS( const nsCodeQOR::CUCS2String& nsURI, const nsCodeQOR::CUCS2String& localName ) const;

		// DOM read only attributes
		nsCodeQOR::CUCS2String tagName() const;
		void setTagName( const nsCodeQOR::CUCS2String& name );

		// Overridden from CDomNode
		CDomNamedNodeMap attributes() const;

		//------------------------------------------------------------------------------
		inline CDomNode::NodeType nodeType() const 
		{ 
			return ElementNode; 
		}

		nsCodeQOR::CUCS2String text() const;

	private:

		CDomElement( CDomElementPrivate* );

		friend class CDomDocument;
		friend class CDomNode;
		friend class CDomAttr;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomText : public CDomCharacterData
	{
	public:

		CDomText();
		CDomText( const CDomText& x );
		CDomText& operator = ( const CDomText& );

		// DOM functions
		CDomText splitText( int offset );

		//------------------------------------------------------------------------------
		// Overridden from CDomCharacterData
		inline CDomNode::NodeType nodeType() const 
		{ 
			return TextNode; 
		}

	private:

		CDomText( CDomTextPrivate* );

		friend class CDomCDATASection;
		friend class CDomDocument;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomComment : public CDomCharacterData
	{
	public:

		CDomComment();
		CDomComment( const CDomComment& x );
		CDomComment& operator = ( const CDomComment& );

		//------------------------------------------------------------------------------
		// Overridden from CDomCharacterData
		inline CDomNode::NodeType nodeType() const 
		{ 
			return CommentNode; 
		}

	private:

		CDomComment( CDomCommentPrivate* );

		friend class CDomDocument;
		friend class CDomNode;
	};


	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomCDATASection : public CDomText
	{
	public:

		CDomCDATASection();
		CDomCDATASection( const CDomCDATASection& x );
		CDomCDATASection& operator = ( const CDomCDATASection& );

		//------------------------------------------------------------------------------
		// Overridden from CDomText
		inline CDomNode::NodeType nodeType() const 
		{ 
			return CDATASectionNode; 
		}

	private:

		CDomCDATASection( CDomCDATASectionPrivate* );

		friend class CDomDocument;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomNotation : public CDomNode
	{
	public:

		CDomNotation();
		CDomNotation( const CDomNotation& x );
		CDomNotation& operator = ( const CDomNotation& );

		// DOM read only attributes
		nsCodeQOR::CUCS2String publicId() const;
		nsCodeQOR::CUCS2String systemId() const;

		//------------------------------------------------------------------------------
		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return NotationNode; 
		}

	private:

		CDomNotation( CDomNotationPrivate* );

		friend class CDomDocument;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomEntity : public CDomNode
	{
	public:

		CDomEntity();
		CDomEntity( const CDomEntity& x );
		CDomEntity& operator = ( const CDomEntity& );

		// DOM read only attributes
		nsCodeQOR::CUCS2String publicId() const;
		nsCodeQOR::CUCS2String systemId() const;
		nsCodeQOR::CUCS2String notationName() const;

		//------------------------------------------------------------------------------
		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return EntityNode; 
		}

	private:

		CDomEntity( CDomEntityPrivate* );

		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomEntityReference : public CDomNode
	{
	public:

		CDomEntityReference();
		CDomEntityReference( const CDomEntityReference& x );
		CDomEntityReference& operator = ( const CDomEntityReference& );

		//------------------------------------------------------------------------------
		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return EntityReferenceNode; 
		}

	private:

		CDomEntityReference( CDomEntityReferencePrivate* );

		friend class CDomDocument;
		friend class CDomNode;
	};

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CDomProcessingInstruction : public CDomNode
	{
	public:

		CDomProcessingInstruction();
		CDomProcessingInstruction( const CDomProcessingInstruction& x );
		CDomProcessingInstruction& operator = ( const CDomProcessingInstruction& );

		// DOM read only attributes
		nsCodeQOR::CUCS2String target() const;

		// DOM attributes
		nsCodeQOR::CUCS2String data() const;
		void setData(const nsCodeQOR::CUCS2String& d);

		//------------------------------------------------------------------------------
		// Overridden from CDomNode
		inline CDomNode::NodeType nodeType() const 
		{ 
			return ProcessingInstructionNode; 
		}

	private:

		CDomProcessingInstruction( CDomProcessingInstructionPrivate* );

		friend class CDomDocument;
		friend class CDomNode;
	};


	//Q_XML_EXPORT CTextStream& operator<<(CTextStream&, const CDomNode&);

}//nsBluefoot

#endif//BLUEFOOT_XML_DOM_H_3
