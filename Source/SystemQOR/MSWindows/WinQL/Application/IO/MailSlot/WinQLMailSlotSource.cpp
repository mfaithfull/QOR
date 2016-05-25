//WinQLMailSlotSource.cpp

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

#include "WinQL/WinQL.h"
#include "WinQL/Application/ErrorSystem/WinQLFunctionContext.h"
#include "WinQL/Application/IO/MailSlot/WinQLMailSlotSource.h"
#include "WinQL/Application/IO/MailSlot/WinQLMailSlotConnector.h"
#include "WinQL/Application/IO/WinQLIOSink.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	__QOR_IMPLEMENT_OCLASS_LUID( CMailSlotSource );

	//--------------------------------------------------------------------------------
	CMailSlotSource::CMailSlotSource(  CMailSlotConnector* pMailSlotConnector ) : CIOSource( pMailSlotConnector )
	{
		_WINQ_FCONTEXT( "CMailSlotSource::CMailSlotSource" );
	}

	//--------------------------------------------------------------------------------
	CMailSlotSource::~CMailSlotSource()
	{
		_WINQ_FCONTEXT( "CMailSlotSource::~CMailSlotSource" );
	}

	//--------------------------------------------------------------------------------
	bool CMailSlotSource::Read( unsigned long& ulNumberOfUnitsRead, unsigned long ulNumberOfUnitsToRead )
	{
		_WINQ_FCONTEXT( "CMailSlotSource::Read" );
		bool bResult = false;
		CMailSlotConnector* pMailSlotConnector = dynamic_cast< CMailSlotConnector* >( m_pIOSourceConnector );
		if( pMailSlotConnector )
		{
			unsigned long ulNextSize = 0;
			unsigned long ulMessageCount = 0;
			pMailSlotConnector->MailSlot().GetInfo( 0, &ulNextSize, &ulMessageCount, 0 );

			if( ulMessageCount > 0 )
			{
				byte* pBuffer = GetBuffer()->WriteRequest( ulNumberOfUnitsToRead );

				if( pMailSlotConnector->AsyncConnection() )
				{
					bResult = pMailSlotConnector->MailSlot().Read( (void*)(pBuffer), ulNumberOfUnitsToRead * GetBuffer()->GetUnitSize(), 
					reinterpret_cast< OVERLAPPED* >( pMailSlotConnector->GetSyncObject() ), (LPOVERLAPPED_COMPLETION_ROUTINE)(&COverlappedHandler::OnOverlappedReadCompleted) );
					ulNumberOfUnitsRead = 0;

					if( !bResult && pMailSlotConnector->Protocol() )
					{
						pMailSlotConnector->Protocol()->OnReadError();
					}
				}
				else
				{				
					if( pMailSlotConnector->MailSlot().Read( pBuffer, ulNumberOfUnitsToRead, ulNumberOfUnitsRead, 0 ) )
					{
						ulNumberOfUnitsRead /= GetBuffer()->GetUnitSize();
						m_pBuffer->WriteAcknowledge( ulNumberOfUnitsRead );
						//unsigned long ulNumberOfUnitsWritten = 0;
						//dynamic_cast< nsBluefoot::CBFSink* >( m_pSink )->Write( ulNumberOfUnitsRead, ulNumberOfUnitsWritten, m_pBuffer->ReadRequest( ulNumberOfUnitsRead ) );
						bResult = ulNumberOfUnitsRead > 0 ? true : false;
					}

					if( pMailSlotConnector->Protocol() )
					{
						if( bResult )
						{
							pMailSlotConnector->Protocol()->OnReadSuccess( ulNumberOfUnitsRead );
						}
						else
						{
							pMailSlotConnector->Protocol()->OnReadError();
						}
					}
				}
			}
		}
		return bResult;
	}

}//nsWin32


