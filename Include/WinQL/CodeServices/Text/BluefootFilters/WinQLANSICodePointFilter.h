//WinQLANSICodePointFilter.h

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

#ifndef WINQL_BLUEFOOT_FILTERS_ANSICODEPOINT_H_3
#define WINQL_BLUEFOOT_FILTERS_ANSICODEPOINT_H_3

//Defines a filter converting ANSI Code Page encoded text to Unicode code points
//This filter can be operated in both Push and Pull modes

#include "WinQL/WinQL.h"
#include "BluefootQOR/BfFilter.h"
#include "WinQL/CodeServices/Text/WinQLCodePage.h"

//------------------------------------------------------------------------------
namespace nsWin32
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __BLUEFOOTQOR ) CANSICodePointFilter : public nsBluefoot::CFilter
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CANSICodePointFilter );

		CANSICodePointFilter();
		virtual ~CANSICodePointFilter();
		CANSICodePointFilter( const CANSICodePointFilter& src );
		CANSICodePointFilter& operator = ( const CANSICodePointFilter& src );
		virtual bool Read( unsigned long& ulUnitsRead, unsigned long ulUnitsToRead );
		bool Write( unsigned long& ulUnitsWritten, unsigned long ulUnitsToWrite );

	protected:

		nsBluefoot::CPODStreamBuffer< unsigned int > m_SourceBuffer;		//Internal buffer to use when behaving as a Source.

	private:

		bool WriteCodePoint( unsigned int uiCodePoint );

		CCodePage m_CodePage;

	};
}

#endif//WINQL_BLUEFOOT_FILTERS_ANSICODEPOINT_H_3

