//WinQLRawInput.cpp

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
#include "WinQL/System/Devices/RawInput/WinQLRawInput.h"
#include "WinQAPI/User32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CRawInput );

	//--------------------------------------------------------------------------------
	CRawInput::CRawInput() : m_Library( CUser32::Instance() )
	{
		_WINQ_FCONTEXT( "CRawInput::CRawInput" );
	}

	//--------------------------------------------------------------------------------
	CRawInput::~CRawInput()
	{
		_WINQ_FCONTEXT( "CRawInput::~CRawInput" );
	}

	//--------------------------------------------------------------------------------
	Cmp_long_ptr CRawInput::DefaultProc( nsWin32::PRAWINPUT* paRawInput, int nInput, unsigned int cbSizeHeader )
	{				
		_WINQ_FCONTEXT( "CRawInput::DefaultProc" );
		LRESULT Result = 0;
		__QOR_PROTECT
		{
			Result = m_Library.DefRawInputProc( reinterpret_cast< ::PRAWINPUT* >( paRawInput ), nInput, cbSizeHeader );
		}__QOR_ENDPROTECT
		return Result;
	}

	//--------------------------------------------------------------------------------
	unsigned int CRawInput::GetBuffer( nsWin32::PRAWINPUT pData, unsigned int* pcbSize, unsigned int cbSizeHeader )
	{				
		_WINQ_FCONTEXT( "CRawInput::GetBuffer" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_Library.GetRawInputBuffer( reinterpret_cast< ::PRAWINPUT >( pData ), pcbSize, cbSizeHeader );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CRawInput::GetData( RawInputHandle hRawInput, unsigned int uiCommand, void* pData, unsigned int* pcbSize, unsigned int cbSizeHeader )
	{				
		_WINQ_FCONTEXT( "CRawInput::GetData" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_Library.GetRawInputData( reinterpret_cast< ::HRAWINPUT >( hRawInput ), uiCommand, pData, pcbSize, cbSizeHeader );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CRawInput::GetDeviceInfo( void* hDevice, unsigned int uiCommand, void* pData, unsigned int* pcbSize )
	{				
		_WINQ_FCONTEXT( "CRawInput::GetDeviceInfo" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_Library.GetRawInputDeviceInfo( hDevice, uiCommand, pData, pcbSize );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CRawInput::GetDeviceList( nsWin32::PRAWINPUTDEVICELIST pRawInputDeviceList, unsigned int* puiNumDevices, unsigned int cbSize )
	{				
		_WINQ_FCONTEXT( "CRawInput::GetDeviceList" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_Library.GetRawInputDeviceList( reinterpret_cast< ::PRAWINPUTDEVICELIST >( pRawInputDeviceList ), puiNumDevices, cbSize );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CRawInput::GetRegisteredDevices( nsWin32::RAWINPUTDEVICE* pRawInputDevices, unsigned int* puiNumDevices, unsigned int cbSize )
	{
		_WINQ_FCONTEXT( "CRawInput::GetRegisteredDevices" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_Library.GetRegisteredRawInputDevices( reinterpret_cast< ::RAWINPUTDEVICE* >( pRawInputDevices ), puiNumDevices, cbSize );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	bool CRawInput::RegisterDevices( const nsWin32::RAWINPUTDEVICE* pRawInputDevices, unsigned int uiNumDevices, unsigned int cbSize )
	{			
		_WINQ_FCONTEXT( "CRawInput::RegisterDevices" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_Library.RegisterRawInputDevices( reinterpret_cast< ::PCRAWINPUTDEVICE >( pRawInputDevices ), uiNumDevices, cbSize ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

}//nsWin32
