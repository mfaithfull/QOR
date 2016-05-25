//MapModel.h

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

#ifndef MAMMUTQOR_MODELS_MAP_H_3
#define MAMMUTQOR_MODELS_MAP_H_3

#include "SystemQOR.h"
#include "MammutQOR/Model.h"
#include "map"

//------------------------------------------------------------------------------
namespace nsMammut
{
    //------------------------------------------------------------------------------
    //Model that is a Map of Model Items of some kind
	template< class TKey, class TItem >
    class CMapModel : public CModel
    {
    public:

		typedef typename std::map< TKey, TItem >::iterator indexType;

		friend class CModelIterator< CMapModel >;
		typedef CModelIterator< CMapModel > iterator;

        CMapModel() : CModel()
		{
		}

		CMapModel( const CMapModel& src ) : CModel( src )
		{
			*this = src;
		}

		CMapModel( CModel* pContainer ) : CModel( pContainer )
		{
		}

        virtual ~CMapModel()
		{
		}

		CMapModel& operator = ( const CMapModel& src )
		{
			m_ItemMap = src.m_ItemMap;
			return *this;
		}
                    
		//------------------------------------------------------------------------------
		iterator begin( void )
		{
			return iterator( iterator::CModelNode( this, m_ItemMap.begin() ) );
		}

		//------------------------------------------------------------------------------
		iterator end( void )
		{
			return iterator( iterator::CModelNode( this, m_ItemMap.end() ) );
		}
		
		//------------------------------------------------------------------------------
		virtual iterator insert( const TKey& key, refType Item )
		{
			std::pair< TKey, TItem > entry( key, Item->As< TItem >() );
			m_ItemMap.insert( entry );
			return --end();
		}

		//------------------------------------------------------------------------------
		virtual iterator find( const TKey& key )
		{
			return iterator( iterator::CModelNode( this, m_ItemMap.find( key ) ) );
		}

		//------------------------------------------------------------------------------
		virtual void erase( const TKey& key )
		{
			/*std::map< TKey, TItem >::size_type result =*/ m_ItemMap.erase( key );
		}

		//------------------------------------------------------------------------------
		unsigned long size( void )
		{
			return m_ItemMap.size();
		}

    protected:

		std::map< TKey, TItem > m_ItemMap;

	private:

		refType operator[]( const std::__map_iterator< std::__tree_iterator< std::__value_type< TKey, TItem >, std::__tree_node< std::__value_type< TKey, TItem >, void* >*, int > > index )
		{
			return refType( &( index->second.As< TItem >() ), false );
		}
		
		refType operator[]( unsigned long );
    };

}//nsMammut

#endif//MAMMUTQOR_MODELS_MAP_H_3
