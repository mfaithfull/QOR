//WinQLIOFilter.cpp

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

//#include "stdafx.h"
#include <string.h>
#include "WinQL/IO/IOFilter.h"
#include "WinQL/CodeServices/ErrorSystem/FunctionContext.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_LUID( CIOFilter );

	//--------------------------------------------------------------------------------
	CIOFilter::CIOFilter() : m_bError( false )
	{
		_WINQ_FCONTEXT( "CIOFilter::CIOFilter" );
	}

	//--------------------------------------------------------------------------------
	CIOFilter::CIOFilter( const CIOFilter& src )
	{
		_WINQ_FCONTEXT( "CIOFilter::CIOFilter" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CIOFilter& CIOFilter::operator = ( const CIOFilter& src )
	{
		_WINQ_FCONTEXT( "CIOFilter::operator =" );
		if( &src != this )
		{
			m_bError = m_bError;
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	CIOFilter::~CIOFilter()
	{
		_WINQ_FCONTEXT( "CIOFilter::~CIOFilter" );
	}

	//--------------------------------------------------------------------------------
	void CIOFilter::SetError( void )
	{
		_WINQ_FCONTEXT( "CIOFilter::SetError" );
		m_bError = true;
	}

	//--------------------------------------------------------------------------------
	void CIOFilter::ClearError( void )
	{
		_WINQ_FCONTEXT( "CIOFilter::ClearError" );
		m_bError = false;
	}

	//--------------------------------------------------------------------------------
	bool CIOFilter::IsError( void )
	{
		_WINQ_FCONTEXT( "CIOFilter::IsError" );
		return m_bError;
	}

	//--------------------------------------------------------------------------------
	void CIOFilter::SetFilter( CIOFilter::refFilterType refFilter )
	{
		_WINQ_FCONTEXT( "CIOFilter::SetFilter" );
		m_refFilter = refFilter;
	}

	//--------------------------------------------------------------------------------
	CIOFilter::refFilterType CIOFilter::GetFilter( void )
	{
		return m_refFilter;
	}

	//--------------------------------------------------------------------------------
	unsigned long CIOFilter::Process( const byte* pSource, byte* pDest, unsigned long ulNumberOfBytesToWrite, unsigned long& ulNumberOfBytesProcessed  )
	{
		_WINQ_FCONTEXT( "CIOFilter::Process" );

		unsigned long ulNumberOfBytesWritten = 0;
		unsigned long ulNumberOfBytesRead = 0;

		while( ulNumberOfBytesToWrite > 0 )
		{
			if( m_refFilter.IsNull() )
			{
				memcpy( pDest + ulNumberOfBytesWritten, pSource + ulNumberOfBytesRead, 1 );
				ulNumberOfBytesRead += 1;
				ulNumberOfBytesWritten += 1;
			}
			else
			{
				unsigned long ulNumberOfBytesProcessed = 0;
				unsigned long ulFilterResult = m_refFilter->Process( pSource + ulNumberOfBytesRead, pDest + ulNumberOfBytesWritten, 1, ulNumberOfBytesProcessed );
				ulNumberOfBytesRead += 1;
				ulNumberOfBytesWritten += ulFilterResult;
			}
		}
		ulNumberOfBytesProcessed = ulNumberOfBytesRead;
		return ulNumberOfBytesWritten;
	}




	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CByteBlockFilter );

	//--------------------------------------------------------------------------------
	CByteBlockFilter::CByteBlockFilter()
	{
		_WINQ_FCONTEXT( "CByteBlockFilter::CByteBlockFilter" );
	}

	//--------------------------------------------------------------------------------
	CByteBlockFilter::CByteBlockFilter( const CByteBlockFilter& src )
	{
		_WINQ_FCONTEXT( "CByteBlockFilter::CByteBlockFilter" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CByteBlockFilter& CByteBlockFilter::operator = ( const CByteBlockFilter& src )
	{
		_WINQ_FCONTEXT( "CByteBlockFilter::operator =" );
		m_usBlockSize = src.m_usBlockSize;
		return *this;
	}

	//--------------------------------------------------------------------------------
	CByteBlockFilter::~CByteBlockFilter()
	{
		_WINQ_FCONTEXT( "CByteBlockFilter::~CByteBlockFilter" );
	}

	//--------------------------------------------------------------------------------
	void CByteBlockFilter::SetBlockSize( unsigned short usSize )
	{
		m_usBlockSize = usSize;
	}

	//--------------------------------------------------------------------------------
	unsigned short CByteBlockFilter::GetBlockSize( void )
	{
		return m_usBlockSize;
	}

	//--------------------------------------------------------------------------------
	unsigned long CByteBlockFilter::Process( const byte* pSource, byte* pDest, unsigned long ulNumberOfBytesToWrite, unsigned long& ulNumberOfBytesProcessed )
	{
		_WINQ_FCONTEXT( "CByteBlockFilter::Process" );

		unsigned long ulNumberOfBytesWritten = 0;
		unsigned long ulNumberOfBytesRead = 0;

		while( ulNumberOfBytesToWrite > m_usBlockSize )
		{
			if( m_refFilter.IsNull() )
			{
				memcpy( pDest + ulNumberOfBytesWritten, pSource + ulNumberOfBytesRead, m_usBlockSize );
				ulNumberOfBytesRead += m_usBlockSize;
				ulNumberOfBytesWritten += m_usBlockSize;
			}
			else
			{
				unsigned long ulNumberOfBytesProcessed = 0;
				unsigned long ulFilterResult = m_refFilter->Process( pSource + ulNumberOfBytesRead, pDest + ulNumberOfBytesWritten, m_usBlockSize, ulNumberOfBytesProcessed );
				ulNumberOfBytesRead += ulNumberOfBytesProcessed;
				ulNumberOfBytesWritten += ulFilterResult;

			}
		}
		ulNumberOfBytesProcessed = ulNumberOfBytesRead;
		return ulNumberOfBytesWritten;
	}



	/*


	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( CLineFilter );

	//--------------------------------------------------------------------------------
	CLineFilter::CLineFilter()
	{
		_WINQ_FCONTEXT( "CLineFilter::CLineFilter" );
	}

	//--------------------------------------------------------------------------------
	CLineFilter::CLineFilter( const CLineFilter& src )
	{
		_WINQ_FCONTEXT( "CLineFilter::CLineFilter" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CLineFilter& CLineFilter::operator = ( const CLineFilter& src )
	{
		_WINQ_FCONTEXT( "CLineFilter::operator =" );
		
		return *this;
	}

	//--------------------------------------------------------------------------------
	CLineFilter::~CLineFilter()
	{
		_WINQ_FCONTEXT( "CLineFilter::~CLineFilter" );
	}

	//--------------------------------------------------------------------------------
	void CLineFilter::SetLineEnd( TCHAR tc1, TCHAR tc2 )
	{
		
	}

	//--------------------------------------------------------------------------------
	unsigned short CLineFilter::GetLineEnd( void )
	{
		return 0
	}

	//--------------------------------------------------------------------------------
	unsigned long CLineFilter::Process( const byte* pSource, byte* pDest, unsigned long ulNumberOfBytesToWrite, unsigned long& ulNumberOfBytesProcessed )
	{
		_WINQ_FCONTEXT( "CLineFilter::Process" );

		unsigned long ulNumberOfBytesRead = 0;
		unsigned long ulNumberOfBytesWritten = 0;
		bool bFinished = false;

		do
		{
			bFinished = true;
			byte* pTestByte = const_cast< byte* >( pSource + ulNumberOfBytesRead );
			unsigned long ulLineLength = 0;			
			while( ulLineLength < ( ulNumberOfBytesToWrite - m_usEndSequenceLength ) )
			{
				unsigned short usSequence = 0;
				bool bFound = true;
				while( usSequence < m_usEndSequenceLength )
				{
					if( pTestByte[ usSequence ] != m_aEndSequence[ usSequence ] )
					{
						bFound = false;
						break;
					}
					usSequence++;
				}

				if( bFound )
				{
					if( m_refFilter.IsNull() )
					{
						memcpy( pDest + ulNumberOfBytesWritten, pSource + ulNumberOfBytesRead, ulLineLength );
						ulNumberOfBytesRead += ( ulLineLength + m_usEndSequenceLength );
						ulNumberOfBytesWritten += ulLineLength;
					}
					else
					{
						unsigned long ulFilterResult = m_refFilter->Process( pSource + ulNumberOfBytesRead, pDest + ulNumberOfBytesWritten, ulLineLength );
						ulNumberOfBytesRead += ( ulLineLength + m_usEndSequenceLength );;
						ulNumberOfBytesWritten += ulFilterResult;
					}
					bFinished = false;
					break;
				}
			
				ulLineLength++;
				pTestByte++;
			}
		}while( !bFinished );		
		ulNumberOfBytesProcessed = ulNumberOfBytesRead;
		return ulNumberOfBytesWritten;
	}

	*/

}//nsWin32