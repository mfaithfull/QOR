//SocketSink.cpp

// Copyright Querysoft Limited 2017
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

//Implements a Bluefoot Socket Sink class

#include "BluefootQOR/Sinks/SocketSink.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"

#if( QOR_SYS_OS == QOR_SYS_MSW )
#include "WinQL/Application/Comms/Network/WinQLSocket.h"
#endif
//------------------------------------------------------------------------------
namespace nsBluefoot
{
	//------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID(CSocketSink);
	//------------------------------------------------------------------------------
	CSocketSink::CSocketSink(CSocketConnector* pSocketConnector) : CIOSink(pSocketConnector)
	{
		__QCS_MEMBER_FCONTEXT("CSocketSink::CSocketSink");
	}

	//------------------------------------------------------------------------------
	CSocketSink::~CSocketSink()
	{
		__QCS_MEMBER_FCONTEXT("CSocketSink::~CSocketSink");
	}

	//------------------------------------------------------------------------------
	bool CSocketSink::AsyncWrite(unsigned long& ulNumberOfUnitsWritten, unsigned long ulNumberOfUnitsToWrite, ISocket::ref_type Socket, void* pSyncObject)
	{
		bool bResult = false;
		byte* pBuffer = GetSource()->GetBuffer()->ReadRequest(ulNumberOfUnitsToWrite);
		ulNumberOfUnitsWritten = 0;

		if (pBuffer)
		{
			unsigned long ulUnitSize = GetSource()->GetBuffer()->GetUnitSize();
			int iBytes = Socket->AsyncSend((char*)(pBuffer), ulNumberOfUnitsToWrite * ulUnitSize, pSyncObject);
			ulNumberOfUnitsWritten = static_cast<unsigned int>(iBytes) / ulUnitSize;
			bResult = (ulNumberOfUnitsWritten > 0) ? true : false;
		}

		if (!bResult)
		{
			WriteError.OnSignaled();
		}
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSocketSink::SyncWrite(unsigned long& ulNumberOfUnitsWritten, unsigned long ulNumberOfUnitsToWrite, ISocket::ref_type Socket)
	{
		bool bResult = false;
		byte* pBuffer = GetSource()->GetBuffer()->ReadRequest(ulNumberOfUnitsToWrite);
		if (pBuffer && ulNumberOfUnitsToWrite > 0)
		{
			unsigned long ulUnitSize = GetSource()->GetBuffer()->GetUnitSize();
			ulNumberOfUnitsWritten = 0;
			int iBytes = Socket->Send((char*)(pBuffer), ulNumberOfUnitsToWrite * ulUnitSize);
			ulNumberOfUnitsWritten = static_cast<unsigned int>(iBytes) / ulUnitSize;
			bResult = (ulNumberOfUnitsWritten > 0) ? true : false;

			GetSource()->GetBuffer()->ReadAcknowledge(ulNumberOfUnitsWritten);
		}

		if (bResult)
		{
			WriteSuccess.Signal();
		}
		else
		{
			WriteError.Signal();
		}
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSocketSink::Write(unsigned long& ulNumberOfUnitsWritten, unsigned long ulNumberOfUnitsToWrite)
	{
		__QCS_MEMBER_FCONTEXT("CSocketSink::Write");

		if (GetMode() == ePull)
		{
			unsigned long ulUnitsRead = 0;
			GetSource()->Read(ulUnitsRead, ulNumberOfUnitsToWrite);
		}

		bool bResult = false;
		CSocketConnector* pConnector = dynamic_cast< CSocketConnector* >(m_pIOSinkConnector);
		if (pConnector && pConnector->IsConnected())
		{
			if (pConnector->AsyncConnection())
			{
				bResult = AsyncWrite(ulNumberOfUnitsWritten, ulNumberOfUnitsToWrite, pConnector->Socket(), pConnector->GetSyncObject());
			}
			else
			{
				bResult = SyncWrite(ulNumberOfUnitsWritten, ulNumberOfUnitsToWrite, pConnector->Socket());
			}
		}
		return bResult;
	}

	//------------------------------------------------------------------------------
	bool CSocketSink::Flush(void)
	{
		__QCS_MEMBER_FCONTEXT("CSocketSink::Flush");
		bool bResult = true;
		return bResult;
	}

}//nsBluefoot
