//MProperty.h

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

#ifndef MAMMUTQOR_MODEL_PROPERTY_H_3
#define MAMMUTQOR_MODEL_PROPERTY_H_3

#include "SystemQOR.h"
#include "CodeQOR/DataTypes/OTypes.h"
#include "CodeQOR/Observer/Observer.h"
#include "CodeQOR/DataStructures/TLRef.h"
#include "CodeQOR/Text/Char.h"
#include "CodeQOR/DataStructures/TMap.h"
#include "CodeQOR/Instancing/STMember.h"
#include "MammutQOR/Model.h"

//------------------------------------------------------------------------------
namespace nsMammut
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __MAMMUT ) CPropertyBase : public CModelItem
	{
	public:

		CPropertyBase( CModel* pContainer, const nsCodeQOR::CString& strName );
		virtual ~CPropertyBase();
		CPropertyBase( const CPropertyBase& src );
		CPropertyBase& operator = ( const CPropertyBase& src );
		const nsCodeQOR::CString& Name( void ) const;
		virtual refType Clone( void );

	protected:

		nsCodeQOR::CString m_Name;

	};

	//------------------------------------------------------------------------------
	template< class TValue >
	class CProperty : public CPropertyBase
	{
	public:		

		//------------------------------------------------------------------------------
		CProperty( CModel* pContainer, const nsCodeQOR::CString& strName ) : CPropertyBase( pContainer, strName )
		{			
		}

		//------------------------------------------------------------------------------
		CProperty( CModel* pContainer, const nsCodeQOR::CString& strName, const TValue& Value ) : CPropertyBase( pContainer, strName ), m_Value( Value )
		{
		}

		//------------------------------------------------------------------------------
		CProperty( CModel* pContainer, const nsCodeQOR::CString& strName, nsMammut::CModelItem::refType Ref ) : CPropertyBase( pContainer, strName )
		{
			CProperty< TValue >* pProp = dynamic_cast< CProperty< TValue >* >( Ref.operator->() );
			if( pProp )
			{
				m_Value = pProp->m_Value;
			}
		}

		//------------------------------------------------------------------------------
		CProperty( const CProperty< TValue >& src ) : CPropertyBase( src )
		{
			*this = src;
		}

		//------------------------------------------------------------------------------
		CProperty( CModel* pContainer, const CProperty< TValue >& src ) : CPropertyBase( pContainer, src.m_Name )
		{
			*this = src;
		}
		
		//------------------------------------------------------------------------------
		CProperty< TValue >& operator = ( const CProperty< TValue >& src )
		{
			CPropertyBase::operator=( src );
			if( &src != this )
			{				
				m_Value = src.m_Value;
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		CProperty< TValue >& operator = ( nsMammut::CModelItem::refType Ref )
		{
			CProperty< TValue >* pProp = dynamic_cast< CProperty< TValue >* >( Ref.operator->() );
			if( pProp )
			{
				m_Value = pProp->m_Value;
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		virtual ~CProperty()
		{
		}

		//------------------------------------------------------------------------------
		virtual void Set( const TValue& src )
		{
			Lock();
			m_Value = src;
			Unlock();
			m_pContainer->OnChanged( Ref() );
		}

		//------------------------------------------------------------------------------
		virtual TValue Value( void ) const
		{
			Lock();
			TValue Result( m_Value );
			Unlock();
			return Result;
		}

		//------------------------------------------------------------------------------
		operator TValue( void )
		{
			return Value();
		}

		//------------------------------------------------------------------------------
		nsCodeQOR::CTLRef< TValue > ValueRef( void )
		{
			Lock();
			nsCodeQOR::CTLRef< TValue > ValueRef( &m_Value, false );
			Unlock();
			return ValueRef;
		}

		//------------------------------------------------------------------------------
		virtual refType Clone( void )
		{
			return refType( new CProperty< TValue >( m_pContainer, *this ), true );
		}

	protected:
		
		TValue m_Value;

	private:

		CProperty();
	};


	//------------------------------------------------------------------------------
	template< class TValue >
	class COptionalProperty : public CPropertyBase
	{
	public:		

		//------------------------------------------------------------------------------
		COptionalProperty( CModel* pContainer, const nsCodeQOR::CString& strName ) : CPropertyBase( pContainer, strName )
		{			
		}

		//------------------------------------------------------------------------------
		COptionalProperty( CModel* pContainer, const nsCodeQOR::CString& strName, TValue& Value ) : CPropertyBase( pContainer, strName)
		{
			m_pValue.Configure( &Value );
		}

		//------------------------------------------------------------------------------
		COptionalProperty( CModel* pContainer, const nsCodeQOR::CString& strName, nsMammut::CModelItem::refType Ref ) : CPropertyBase( pContainer, strName )
		{
			COptionalProperty< TValue >* pOptProp = dynamic_cast< COptionalProperty< TValue >* >( Ref.operator->() );
			if( pOptProp )
			{
				m_pValue() = pOptProp->m_pValue();
			}
		}

		//------------------------------------------------------------------------------
		COptionalProperty( const COptionalProperty< TValue >& src ) : CPropertyBase( src )
		{
			*this = src;
		}

		//------------------------------------------------------------------------------
		COptionalProperty( CModel* pContainer, const COptionalProperty< TValue >& src ) : CPropertyBase( pContainer, src.m_Name )
		{
			*this = src;
		}
		
		//------------------------------------------------------------------------------
		COptionalProperty< TValue >& operator = ( const COptionalProperty< TValue >& src )
		{
			CPropertyBase::operator=( src );
			if( &src != this )
			{				
				m_pValue() = ( const_cast< COptionalProperty< TValue >& >( src ) ).m_pValue();
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		COptionalProperty< TValue >& operator = ( nsMammut::CModelItem::refType Ref )
		{
			COptionalProperty< TValue >* pOptProp = dynamic_cast< COptionalProperty< TValue >* >( Ref.operator->() );
			if( pOptProp )
			{
				m_pValue() = pOptProp->m_pValue();
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		virtual ~COptionalProperty()
		{
		}

		//------------------------------------------------------------------------------
		virtual void Set( const TValue& src )
		{
			Lock();
			m_pValue.operator()() = src;
			Unlock();
			m_pContainer->OnChanged( Ref() );
		}

		//------------------------------------------------------------------------------
		virtual TValue Value( void )/* const*/
		{
			Lock();
			TValue Result( m_pValue.operator()() );
			Unlock();
			return Result;
		}

		//------------------------------------------------------------------------------
		operator TValue( void )
		{
			return Value();
		}

	protected:

		nsCodeQOR::CSTMember< TValue > m_pValue;

	private:

		COptionalProperty();
	};

	//------------------------------------------------------------------------------
	template< class TValue, class TImpl >
	class CFunctionalProperty : public CPropertyBase
	{
	public:		

		//------------------------------------------------------------------------------
		CFunctionalProperty( CModel* pContainer, const nsCodeQOR::CString& strName ) : CPropertyBase( pContainer, strName )
		{			
		}

		//------------------------------------------------------------------------------
		CFunctionalProperty( CModel* pContainer, const nsCodeQOR::CString& strName, TImpl* pImpl ) : CPropertyBase( pContainer, strName )
		{
			SetImpl( pImpl );
		}

		//------------------------------------------------------------------------------
		CFunctionalProperty( const CFunctionalProperty< TValue, TImpl >& src ) : CPropertyBase( src ), m_pImpl( src.m_pImpl )
		{
			*this = src;
		}

		//------------------------------------------------------------------------------
		CFunctionalProperty( CModel* pContainer, const COptionalProperty< TValue >& src ) : CPropertyBase( pContainer, src.Name() ), m_pImpl( 0 )
		{
			*this = src;
		}
		
		//------------------------------------------------------------------------------
		CFunctionalProperty< TValue, TImpl >& operator = ( const CFunctionalProperty< TValue, TImpl >& src )
		{
			CPropertyBase::operator=( src );
			if( &src != this )
			{			
				Set( ( const_cast< CFunctionalProperty< TValue, TImpl >& >( src ) ).Value() );
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		CFunctionalProperty< TValue, TImpl >& operator = ( const COptionalProperty< TValue >& src )
		{
			CPropertyBase::operator=( src );
			Set( ( const_cast< COptionalProperty< TValue >& >( src ) ).Value() );
			return *this;
		}

		//------------------------------------------------------------------------------
		CFunctionalProperty< TValue, TImpl >& operator = ( nsMammut::CModelItem::refType Ref )
		{
			CProperty< TValue >* pProp = dynamic_cast< CProperty< TValue >* >( Ref.operator->() );
			if( pProp )
			{
				Set( pProp->Value() );
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		virtual ~CFunctionalProperty()
		{
		}

		//------------------------------------------------------------------------------
		virtual void Set( const TValue& src )
		{
			Lock();

			m_pImpl->SetValue( src );

			Unlock();
			m_pContainer->OnChanged( Ref() );
		}

		//------------------------------------------------------------------------------
		virtual TValue Value( void ) const
		{
			Lock();

			TValue Result = m_pImpl->GetValue();

			Unlock();
			return Result;
		}

		//------------------------------------------------------------------------------
		operator TValue( void )
		{
			return Value();
		}

		//------------------------------------------------------------------------------
		void SetImpl( TImpl* pImpl )
		{
			m_pImpl = pImpl;
		}

	protected:

		TImpl* m_pImpl;

	private:

		CFunctionalProperty();
	};

}//nsMammut

#endif//MAMMUTQOR_MODEL_PROPERTY_H_3
