//Selection.h

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

#ifndef _MONKIQOR_UIG_SELECTION_H_3
#define _MONKIQOR_UIG_SELECTION_H_3

#include "Interaction.h"
#include <vector>

//------------------------------------------------------------------------------
namespace nsMonki
{

	//------------------------------------------------------------------------------
	//Intermediate class for User Interaction Selection elements
	class __QOR_INTERFACE( __MONKI ) CInteractionSelection : public CInteractionElement
	{
	public:

		CInteractionSelection();
		virtual ~CInteractionSelection();

	protected:

		std::vector< CInteractionElement* > m_VecSelection;

		unsigned long m_ulMaxSelect;						//Number of items user can select at once, 1-n, 0 for unlimited
		bool m_bVisualContext;								//True if the selection items must all be presented together for the user to make the selection
	};

	//All visual layouts will be tied to selections

}//nsMonki

#endif//_MONKIQOR_UIG_SELECTION_H_3
