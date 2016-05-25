//WinQLLid.cpp

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
#include "WinQL/Definitions/Constants.h"
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQL/System/Devices/ACPI_Lid/WinQLLid.h"
#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterfaceClass.h"
#include "WinQL/System/WinQLSystem.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_GUID( CLid, 0x4AFA3D52, 0x74A7, 0x11d0, 0xbe, 0x5e, 0x00, 0xA0, 0xC9, 0x06, 0x28, 0x57 );

	nsCodeQOR::CTExternalRegEntry< CLid > CLid::RegEntry;

	//--------------------------------------------------------------------------------
	CLid::CLid() : CDeviceInterface()
	,	m_pIODevice( 0 )
	{
		_WINQ_FCONTEXT( "CLid::CLid" );
	}

	//--------------------------------------------------------------------------------
	CLid::CLid( const CLid& src ) : CDeviceInterface( src )
	{
		_WINQ_FCONTEXT( "CLid::CLid" );
		*this = src;
	}

	//--------------------------------------------------------------------------------
	CLid& CLid::operator = ( const CLid& src )
	{
		_WINQ_FCONTEXT( "CLid::operator =" );
		if( &src != this )
		{
			m_pIODevice = src.m_pIODevice;
		}
		return *this;
	}

	//--------------------------------------------------------------------------------
	CLid::~CLid()
	{
		_WINQ_FCONTEXT( "CLid::~CLid" );
		if( m_pIODevice != 0 )
		{
			Close();
		}
	}

	//--------------------------------------------------------------------------------
	void CLid::OpenDevice()
	{
		_WINQ_FCONTEXT( "CLid::OpenDevice" );

		if( m_pIODevice == 0 )
		{
			CIODeviceFile& IODeviceFile = Open( Generic_Read, File_Share_Read, File_Attribute_Normal );
			m_pIODevice = &IODeviceFile;
		}
	}

	//--------------------------------------------------------------------------------
	unsigned long CLid::GetStatus( void )
	{
		_WINQ_FCONTEXT( "CLid::GetStatus" );

		OpenDevice();

		unsigned long ulOut = 0;
		unsigned long ulResult = 0;
		if( m_pIODevice->Control( __WINQL_DEVICE_CONTROL_CODE( File_Device_Lid, Query_Status, Method_Buffered, File_Read_Access ), 0, 0, &ulResult, sizeof( unsigned long ), &ulOut, 0 ) )
		{
		}
		return ulResult;
	}

}//nsWin32

