//WinQLSlideshow.cpp

// Copyright Querysoft Limited 2013, 2017
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
#include "WinQL/System/Devices/Slideshow/WinQLSlideshow.h"
#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterfaceClass.h"
#include "WinQL/System/WinQLSystem.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_OCLASS_GUID( CSlideshow, 0x152E5811, 0xFEB9, 0x4B00, 0x90, 0xF4, 0xD3, 0x29, 0x47, 0xAE, 0x16, 0x81 );
	
	nsCodeQOR::CTExternalRegEntry< CSlideshow > CSlideshow::RegEntry;

	//--------------------------------------------------------------------------------
	CSlideshow::CSlideshow() : CDeviceInterface()
	{
		_WINQ_FCONTEXT( "CSlideshow::CSlideshow" );
	}

	//--------------------------------------------------------------------------------
	CSlideshow::~CSlideshow()
	{
		_WINQ_FCONTEXT( "CSlideshow::~CSlideshow" );
	}

}//nsWin32

