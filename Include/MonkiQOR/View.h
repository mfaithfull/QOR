//View.h

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

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef _MONKIQOR_VIEW_H_
#define _MONKIQOR_VIEW_H_

#include "SystemQOR.h"
#include "CodeQOR/Observer/Observer.h"

//------------------------------------------------------------------------------
namespace nsAppocrita
{
	class __QOR_INTERFACE( __APPOCRITA ) CController; 
	class __QOR_INTERFACE( __APPOCRITA ) CCompoundController;
};

//------------------------------------------------------------------------------
namespace nsMonki
{
	//------------------------------------------------------------------------------
	//Base class for View
	class __QOR_INTERFACE( __MONKI ) CView
	{
	public:

		CView();
		CView( nsAppocrita::CController* pController, CView* pParent = 0 );
		virtual ~CView();

		void SetController( nsAppocrita::CController* pController );
		nsAppocrita::CController* GetController( void );

		void SetParent( CView* pParent );
		CView* GetParent( void );

	protected:

		nsAppocrita::CController* m_pController;
		CView* m_pParent;

	};
	/*
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __MONKI ) CCompoundView : public CView, public nsCodeQOR::CTArray< CView* >
	{
	public:

		CCompoundView();
		CCompoundView( nsAppocrita::CCompoundController* pController, CCompoundView* pParent = 0 );
		virtual ~CCompoundView();

	};
	*/
};

#endif//_MONKIQOR_VIEW_H_
