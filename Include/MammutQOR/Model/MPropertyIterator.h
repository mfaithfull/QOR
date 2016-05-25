//MPropertyIterator.h

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

#ifndef MAMMUTQOR_MODEL_PROPERTYITERATOR_H_3
#define MAMMUTQOR_MODEL_PROPERTYITERATOR_H_3

#include "SystemQOR.h"
#include "MammutQOR/Model.h"
#include "MammutQOR/Model/MProperty.h"

//------------------------------------------------------------------------------
namespace nsMammut
{
	class __QOR_INTERFACE( __MAMMUT ) CPropertySet;

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __MAMMUT ) CPropertyIterator : public CModel::iterator
	{
		friend class CPropertySet;

		explicit CPropertyIterator( CPropertySet& Container, CModel::iterator::CModelNode __p ) __QCMP_THROW;

	public:

		CPropertyIterator( CPropertySet& Container );
		CPropertyIterator( const CPropertyIterator& src );
		bool operator == ( const CPropertyIterator& cmp );
		CPropertyIterator& operator = ( const CPropertyIterator& src );
		virtual ~CPropertyIterator();
		operator CPropertyBase*();
		CPropertyIterator& operator +( unsigned long uiStep );
		CPropertyIterator& operator ++( void );
		CPropertyIterator& operator -( unsigned long uiStep );
		CPropertyIterator& operator --( void );

	protected:

		void AcquireProperty( void );

		CPropertySet& m_Container;
		CPropertyBase* m_pProperty;
		unsigned long m_ulIndex;

	private:

		CPropertyIterator();
	};

}//nsMammut

#endif//MAMMUTQOR_MODEL_PROPERTYITERATOR_H_3
