//GUI.h

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

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#ifndef MONKIQOR_GUI_H_3
#define MONKIQOR_GUI_H_3

#include "CodeQOR/Macros/ClassIdentityMacros.h"
#include "CodeQOR/DataTypes/GUID.h"
#include "CodeQOR/MemoryManagement/DefaultAllocator.h"
#include "CodeQOR/DataStructures/TLRef.h"

//------------------------------------------------------------------------------
namespace nsMonki
{
	//------------------------------------------------------------------------------
	//RAII Session class for making use of a GUI
	class __QOR_INTERFACE( __MONKI ) CGUISession
	{
	public:

		typedef nsCodeQOR::CTLRef< CGUISession > refType;

		__QOR_DECLARE_OCLASS_ID( CGUISession );

		CGUISession();
		virtual ~CGUISession();

		//--------------------------------------------------------------------------------
		refType Ref( void )
		{
			refType ref( this, false );
			return ref;
		}
	};

	//------------------------------------------------------------------------------
	//A generic base for GUI toolkit instances
	//This will determine the minimal set of factories they need to provide so we can create the necessary visual artifacts to render the basic View types
	class __QOR_INTERFACE( __MONKI ) CGUI
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CGUI );

		CGUI();
		virtual ~CGUI();

		virtual CGUISession::refType Session( void );
	};

}//nsMonki

#endif//MONKIQOR_GUI_H_3
