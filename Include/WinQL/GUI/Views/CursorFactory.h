//CursorFactory.h

// Copyright Querysoft Limited 2013, 2015
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

//Factory for Cursors

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef WINQL_VIEWS_CURSORFACTORY_H_3
#define WINQL_VIEWS_CURSORFACTORY_H_3

#include "CompilerQOR.h"
#include "CodeQOR/ClassReg/ClassRegEntry.h"
#include "WinQL/GUI/Cursor.h"
#include "WinQL/GUI/VisualModels/CursorModel.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_GUI ) CCursorFactory : public nsCodeQOR::CTClassRegEntry< nsWin32::CCursor >
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CIconFactory );

		CCursorFactory();
		virtual ~CCursorFactory();

		virtual void* Instance( void );
		virtual void* Instance( nsMammut::CPropertySet& srcModel );
		CCursor::refType Ref( void );

		//Add a reader and a writer to the factory which create and use the same model
		//The overall factory will be looked up by a generic reader or writer according to the class ID 

		nsCodeQOR::CSTMember< CCursorModel > m_Model;

	};
	
}//nsWin32

#endif//WINQL_VIEWS_CURSORFACTORY_H_3
