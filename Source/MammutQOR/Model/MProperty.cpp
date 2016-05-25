//MProperty.cpp

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

#include "MammutQOR.h"
#include "MammutQOR/Model/MProperty.h"
#include "MammutQOR/Model/MPropertySet.h"

//------------------------------------------------------------------------------
namespace nsMammut
{

	//------------------------------------------------------------------------------
	CPropertyBase::CPropertyBase( CModel* pContainer, const nsCodeQOR::CString& strName ) : CModelItem( pContainer ), m_Name( strName )
	{
		CPropertySet* pPropertySet = dynamic_cast< CPropertySet* >( pContainer );
		if( pPropertySet )
		{
			pPropertySet->insert( Ref() );
		}
	}

	//------------------------------------------------------------------------------
	CPropertyBase::~CPropertyBase()
	{
	}

	//------------------------------------------------------------------------------
	CPropertyBase::CPropertyBase( const CPropertyBase& src ) : CModelItem( src ), m_Name( src.m_Name )
	{
	}

	//------------------------------------------------------------------------------
	CPropertyBase& CPropertyBase::operator = ( const CPropertyBase& src )
	{
		CModelItem::operator=( src );
		if( &src != this )
		{
			m_Name = src.m_Name;
		}
		return *this;
	}

	//------------------------------------------------------------------------------
	const nsCodeQOR::CString& CPropertyBase::Name( void ) const
	{
		return m_Name;
	}

	//------------------------------------------------------------------------------
	CPropertyBase::refType CPropertyBase::Clone( void )
	{
		return refType( new CPropertyBase( *this ), true );
	}

}//nsMammut


