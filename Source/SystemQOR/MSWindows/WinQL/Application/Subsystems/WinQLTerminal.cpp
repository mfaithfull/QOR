//WinQLTerminal.cpp

// Copyright Querysoft Limited 2016
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

//WinQL Terminal Subsystem

#include "WinQL/WinQL.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/System/FileSystem/WinQLFile.h"
#include "WinQL/System/FileSystem/WinQLStream.h"
#include "WinQL/Application/Subsystems/WinQLTerminal.h"
#include "WinQL/Application/WinQLApplication.h"

#define NOMINMAX
#include "WinQAPI/Kernel32.h"
#include <errno.h>
#include <algorithm>

//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QOR_IMPLEMENT_EXTERNAL_FACTORY( CTerminal, 0x261fc4e5, 0xad60, 0x4b8a, 0xb8, 0x4a, 0xd5, 0xa2, 0x3, 0x2e, 0xac, 0x86 );

	//--------------------------------------------------------------------------------
	CTerminal::CTerminal() : nsQOR::CSubSystem()
	{
		m_Console = CConsole::TheWin32Console();
	}

	//--------------------------------------------------------------------------------
	CTerminal::~CTerminal()
	{
	}

	//--------------------------------------------------------------------------------
	void CTerminal::Setup( nsQOR::IApplication& Application )
	{
		CWin32Application& WindowsApp = dynamic_cast<CWin32Application&>( Application );

		CConsole::ref_type console = Console();
		WindowsApp.AddWaitableObject( console->InputStdHandle() );

		unsigned long ulMode = 0;
		if( console->ScreenBuffer()->GetInputMode( ulMode ) )
		{
			console->ScreenBuffer()->SetInputMode( ulMode | CConsole::Window_Input | CConsole::Mouse_Input );
		}
	}

	//--------------------------------------------------------------------------------
	void CTerminal::Shutdown( nsQOR::IApplication& Application )
	{
		CWin32Application& WindowsApp = dynamic_cast<CWin32Application&>( Application );
		WindowsApp.RemoveWaitableObject( Console()->InputStdHandle() );
	}

	//--------------------------------------------------------------------------------
	CConsole::ref_type CTerminal::Console( void )
	{
		return m_Console->Ref();
	}

}//nsWin32
