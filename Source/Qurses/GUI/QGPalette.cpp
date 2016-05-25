//QGPalette.cpp

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

#include "Qurses/GUI/QGPalette.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "Qurses/curses.h"
#include "Qurses/curspriv.h"

//--------------------------------------------------------------------------------
namespace nsQurses
{
	__QOR_IMPLEMENT_OCLASS_LUID( CQGPalette );

	//--------------------------------------------------------------------------------
	CQGPalette::CQGPalette()
	{
		__QCS_MEMBER_FCONTEXT( "CQGPalette::CQGPalette" );
	}

	//--------------------------------------------------------------------------------
	CQGPalette::~CQGPalette()
	{
		__QCS_MEMBER_FCONTEXT( "CQGPalette::~CQGPalette" );
	}

	//--------------------------------------------------------------------------------
	void CQGPalette::Initialise( void )
	{
		__QCS_MEMBER_FCONTEXT( "CQGPalette::Initialise" );
		start_color();

# if defined(NCURSES_VERSION) || (defined(PDC_BUILD) && PDC_BUILD > 3000)
		use_default_colors();
# endif
		
	}

	//--------------------------------------------------------------------------------
	unsigned int CQGPalette::GetNumberOfEntries( void )
	{
		return PDC_COLOR_PAIRS;
	}

	//--------------------------------------------------------------------------------
	void CQGPalette::SetEntry( unsigned int uiIndex, CQGPalette::eColour Fore, CQGPalette::eColour Back )
	{
		if( uiIndex < GetNumberOfEntries() )
		{
			init_pair( static_cast< unsigned short >( uiIndex ), static_cast< short >( Fore ), static_cast< short >( Back ) );
		}
	}

	//--------------------------------------------------------------------------------
	void CQGPalette::GetEntry( unsigned int uiIndex, CQGPalette::eColour& Fore, CQGPalette::eColour& Back )
	{
		if( uiIndex < GetNumberOfEntries() )
		{
			pair_content( static_cast< unsigned short >( uiIndex ), reinterpret_cast< short* >( &Fore ), reinterpret_cast< short* >( &Back ) );
		}
	}

}//nsQurses
