//WinQLTape.cpp

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

#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/System/Devices/Storage/WinQLTape.h"
#include "WinQL/System/Devices/WinQLDeviceHandle.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	//--Tape--------------------------------------------------------------------------

	__QOR_IMPLEMENT_OCLASS_GUID( CTape, 0x53F5630B, 0xB6BF, 0x11D0, 0x94, 0xF2, 0x00, 0xA0, 0xC9, 0x1E, 0xFB, 0x8B );
	
	nsCodeQOR::CTExternalRegEntry< CTape > CTape::RegEntry;

	//--------------------------------------------------------------------------------
	CTape::CTape() : CDeviceInterface(), m_Handle( *( new CDeviceHandle() ) )
	{
		_WINQ_FCONTEXT( "CTape::CTape" );
	}

	//--------------------------------------------------------------------------------
	CTape::CTape( CDeviceHandle& DeviceHandle ) : CDeviceInterface(), m_Handle( DeviceHandle )
	{
		_WINQ_FCONTEXT( "CTape::CTape" );
	}

	//--------------------------------------------------------------------------------
	CTape::~CTape()
	{
		_WINQ_FCONTEXT( "CTape::~CTape" );
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::CreatePartition( E_PartitionMethod PartitionMethod, unsigned long dwCount, unsigned long dwSize )
	{
		_WINQ_FCONTEXT( "CTape::CreatePartition" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::CreateTapePartition( m_Handle.Use(), static_cast< DWORD >( PartitionMethod ), dwCount, dwSize );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::Erase( E_EraseType EraseType, bool bImmediate )
	{
		_WINQ_FCONTEXT( "CTape::Erase" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::EraseTape( m_Handle.Use(), static_cast< DWORD >( EraseType ), bImmediate ? TRUE : FALSE );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::GetParameters( E_ParameterOp Operation, unsigned long* lpdwSize, void* lpTapeInformation )
	{
		_WINQ_FCONTEXT( "CTape::GetParameters" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetTapeParameters( m_Handle.Use(), static_cast< DWORD >( Operation ), lpdwSize, lpTapeInformation );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::GetPosition( E_PositionType PositionType, unsigned long* lpdwPartition, unsigned long* lpdwOffsetLow, unsigned long* lpdwOffsetHigh )
	{
		_WINQ_FCONTEXT( "CTape::GetPosition" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetTapePosition( m_Handle.Use(), static_cast< DWORD >( PositionType ), lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::GetStatus()
	{
		_WINQ_FCONTEXT( "CTape::GetStatus" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetTapeStatus( m_Handle.Use() );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::Prepare( E_PrepOperation Operation, bool bImmediate )
	{
		_WINQ_FCONTEXT( "CTape::Prepare" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::PrepareTape( m_Handle.Use(), static_cast< DWORD >( Operation ), bImmediate ? TRUE : FALSE );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::SetParameters( E_ParameterOp Operation, void* lpTapeInformation )
	{
		_WINQ_FCONTEXT( "CTape::SetParameters" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::SetTapeParameters( m_Handle.Use(), static_cast< DWORD >( Operation ), lpTapeInformation );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::SetPosition( E_PositionMethod PositionMethod, unsigned long dwPartition, unsigned long dwOffsetLow, unsigned long dwOffsetHigh, bool bImmediate )
	{
		_WINQ_FCONTEXT( "CTape::SetPosition" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::SetTapePosition( m_Handle.Use(), static_cast< DWORD >( PositionMethod ), dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate ? TRUE : FALSE );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CTape::WriteTapemark( E_TapeMarkType TapemarkType, unsigned long dwTapemarkCount, bool bImmediate )
	{
		_WINQ_FCONTEXT( "CTape::WriteTapemark" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::WriteTapemark( m_Handle.Use(), static_cast< DWORD >( TapemarkType ), dwTapemarkCount, bImmediate ? TRUE : FALSE );
		}__QOR_ENDPROTECT
		return dwResult;
	}

}//nsWin32
