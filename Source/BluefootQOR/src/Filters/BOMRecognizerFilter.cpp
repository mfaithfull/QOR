//BOMRecognizerFilter.cpp

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

#include "BluefootQOR/Filters/BOMRecognizerFilter.h"

//------------------------------------------------------------------------------
namespace nsBluefoot
{
	//------------------------------------------------------------------------------
	static const byte Patterns[ CBOMRecognizerFilter::sculPatterns ][ CBOMRecognizerFilter::sculBOMBytes ] =
	{
		{ 0xFE, 0xFF, 0x00, 0x00 },
		{ 0xFF, 0xFE, 0x00, 0x00 },
		{ 0xEF, 0xBB, 0xBF, 0x00 }
	};

	//------------------------------------------------------------------------------
	static const byte Masks[ CBOMRecognizerFilter::sculPatterns ][ CBOMRecognizerFilter::sculBOMBytes ] =
	{
		{ 0xFF, 0xFF, 0x00, 0x00 },
		{ 0xFF, 0xFF, 0x00, 0x00 },
		{ 0xFF, 0xFF, 0xFF, 0x00 }
	};

	//------------------------------------------------------------------------------
	CBOMRecognizerFilter::CBOMRecognizerFilter() : CBFFilter()
	,	m_bRecognized( false )
	{
	}

	//------------------------------------------------------------------------------
	CBOMRecognizerFilter::~CBOMRecognizerFilter()
	{
	}

	//------------------------------------------------------------------------------
	CBOMRecognizerFilter::CBOMRecognizerFilter( const CBOMRecognizerFilter& src ) : CBFFilter( src )
	{
		m_bRecognized = src.m_bRecognized;
	}

	//------------------------------------------------------------------------------
	CBOMRecognizerFilter& CBOMRecognizerFilter::operator = ( const CBOMRecognizerFilter& src )
	{
		if( &src != this )
		{
			m_bRecognized = src.m_bRecognized;
		}
		return *this;
	}

	//------------------------------------------------------------------------------
	CBFBuffer* CBOMRecognizerFilter::GetSourceBuffer( void )
	{
		CBFBuffer* pBuffer = 0;
		if( GetSource() )
		{
			pBuffer = GetSource()->GetBuffer();
		}
		return pBuffer;
	}

	//------------------------------------------------------------------------------
	byte* CBOMRecognizerFilter::GetBOM( unsigned long& ulBOMBytes )
	{
		byte* pSequence = 0;
		CBFBuffer* pBuffer = GetSourceBuffer();
		if( pBuffer )
		{
			ulBOMBytes = sculBOMBytes;
			pSequence = pBuffer->ReadRequest( ulBOMBytes );
		}
		return pSequence;
	}

	//------------------------------------------------------------------------------
	void CBOMRecognizerFilter::AcknowledgeBOM( unsigned long ulBOMBytes )
	{
		CBFBuffer* pBuffer = GetSourceBuffer();
		if( pBuffer )
		{
			pBuffer->ReadAcknowledge( ulBOMBytes );
		}
	}

	//------------------------------------------------------------------------------
	void CBOMRecognizerFilter::RejectBOM( unsigned long ulBOMBytes )
	{
		CBFBuffer* pBuffer = GetSourceBuffer();
		if( pBuffer )
		{
			pBuffer->ReadReject( ulBOMBytes );
		}
	}

	//------------------------------------------------------------------------------
	void CBOMRecognizerFilter::RecognizeBOM()
	{
		unsigned long ulBOMBytes = sculBOMBytes;
		byte* pBOMData = GetBOM( ulBOMBytes );
		if( ulBOMBytes == sculBOMBytes && pBOMData )
		{
			unsigned int uiSequence = 0;

			bool Match[ CBOMRecognizerFilter::sculPatterns ];

			unsigned long ulPattern = 0;

			for( ulPattern = 0; ulPattern < CBOMRecognizerFilter::sculPatterns; ulPattern++ )
			{
				Match[ ulPattern ] = true;
			}

			while( uiSequence < ulBOMBytes )
			{
				bool bDone = true;
				for( ulPattern = 0; ulPattern < CBOMRecognizerFilter::sculPatterns && Match[ ulPattern ]; ulPattern++ )
				{
					if( !( ( pBOMData[ uiSequence ] & Masks[ ulPattern ][ uiSequence ] ) == Patterns[ ulPattern ][ uiSequence ] ) )
					{
						Match[ ulPattern ] = false;
					}
					else
					{
						bDone = false;
					}
				}
				if( bDone )
				{
					break;
				}
				uiSequence++;
			};


			unsigned int uiMatchCount = 0;
			unsigned int uiMatch = 0;
			for( ulPattern = 0; ulPattern < CBOMRecognizerFilter::sculPatterns; ulPattern++ )
			{
				if( Match[ ulPattern ] )
				{
					uiMatchCount++;
					uiMatch = uiSequence;
				}
			}

			if( uiMatchCount > 0 )
			{
				AcknowledgeBOM( ulBOMBytes );
				if( uiMatchCount == 1 )
				{
					switch ( uiMatch )
					{
					case 0:
						m_RecognitionEvent.BOMType() = CBOMRecognizedEvent::eUTF16BE;
					case 1:
						m_RecognitionEvent.BOMType() = CBOMRecognizedEvent::eUTF16LE;
					case 2:
						m_RecognitionEvent.BOMType() = CBOMRecognizedEvent::eUTF8;
					}
					m_RecognitionEvent(); //BOM Matched
					m_bRecognized = true;
				}
			}
			else
			{
				RejectBOM( ulBOMBytes );
				m_RecognitionEvent.BOMType() = CBOMRecognizedEvent::eNone;
				m_RecognitionEvent();//No BOM
				m_bRecognized = true;
			}
		}
		
	}

	//------------------------------------------------------------------------------
	bool CBOMRecognizerFilter::Read( unsigned long& ulUnitsRead, unsigned long ulUnitsToRead )
	{
		bool bResult = false;

		//Switch on whether recognition has taken place

		if( m_bRecognized )
		{
			bResult = GetSource()->Read( ulUnitsRead, ulUnitsToRead );
		}
		else
		{
			bResult = GetSource()->Read( ulUnitsRead, sculBOMBytes );
			RecognizeBOM();
		}
		return bResult;
	}
		
	//------------------------------------------------------------------------------
	bool CBOMRecognizerFilter::Write( unsigned long& ulUnitsWritten, unsigned long ulUnitsToWrite )
	{
		bool bResult = false;
		if( m_bRecognized )
		{
			bResult = GetSink()->Write( ulUnitsWritten, ulUnitsToWrite );
		}
		else
		{
			RecognizeBOM();
			bResult = true;
		}
		return bResult;
	}

}//nsBluefoot


