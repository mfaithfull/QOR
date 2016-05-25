//CodePointSAXParser.cpp

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

#include "BluefootQOR/Filters/CodePointSAXParser.h"

//------------------------------------------------------------------------------
namespace nsBluefoot
{
	//------------------------------------------------------------------------------
	CCodePointSAXParser::CCodePointSAXParser() : CBFFilter()
	{

	}

	//------------------------------------------------------------------------------
	CCodePointSAXParser::~CCodePointSAXParser()
	{
	}

	//------------------------------------------------------------------------------
	CCodePointSAXParser::CCodePointSAXParser( const CCodePointSAXParser& src ) : CBFFilter( src )
	{
	}

	//------------------------------------------------------------------------------
	CCodePointSAXParser& CCodePointSAXParser::operator = ( const CCodePointSAXParser& src )
	{
		if( &src != this ){}
		return *this;
	}

	//------------------------------------------------------------------------------
	CBFBuffer* CCodePointSAXParser::GetSourceBuffer( void )
	{
		return m_pBuffer;
	}

	//------------------------------------------------------------------------------
	bool CCodePointSAXParser::Read( unsigned long& ulUnitsRead, unsigned long ulUnitsToRead )
	{
		//Read up to the number of code points 1-to-1 for the number of UTF-8 chars requested
		if( m_SinkProxy.GetSource()->Read( ulUnitsRead, ulUnitsToRead ) )
		{
			unsigned int* pCodePointBuffer = reinterpret_cast< unsigned int* >( m_SinkProxy.GetSource()->GetBuffer()->ReadRequest( ulUnitsToRead ) );

			for( ulUnitsRead = 0; ulUnitsRead < ulUnitsToRead; ulUnitsRead++ )
			{
				//ProcessCodePointToUTF8Buffer( ulUnitsRead, pCodePointBuffer );
			}

			m_SinkProxy.GetSource()->GetBuffer()->ReadAcknowledge( ulUnitsRead );
		}
		return ulUnitsRead > 0 ? true : false;
	}


	//------------------------------------------------------------------------------
	bool CCodePointSAXParser::Write( unsigned long& ulUnitsWritten, unsigned long ulUnitsToWrite )
	{
		unsigned int* pCodePointBuffer = reinterpret_cast< unsigned int* >( m_SinkProxy.GetSource()->GetBuffer()->ReadRequest( ulUnitsToWrite ) );

		for( ulUnitsWritten = 0; ulUnitsWritten < ulUnitsToWrite; ulUnitsWritten++ )
		{
			unsigned long ulUTF8Written = 0;//ProcessCodePointToUTF8Buffer( ulUnitsWritten, pCodePointBuffer );
			unsigned long ulSinkUnits = 0;
			//m_SourceProxy.GetSink()->Write( ulSinkUnits, ulUTF8Written );
		}

		m_SinkProxy.GetSource()->GetBuffer()->ReadAcknowledge( ulUnitsWritten );

		return ulUnitsWritten > 0 ? true : false;
	}
}
