//WinQLConsoleHelper.h

// Copyright Querysoft Limited 2013, 2016
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

//Win32 Console

#ifndef WINQL_CONSOLE_HELPER_H_3
#define WINQL_CONSOLE_HELPER_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Handles.h"
#include "WinQL/Definitions/Security.h"
#include "CodeQOR/DataTypes/Property.h"
#include "CodeQOR/ErrorSystem/DefaultHandler.h"
#include "WinQL/System/FileSystem/WinQLFileHandle.h"
#include "CodeQOR/DataStructures/TArray.h"
#include "WinQL/CodeServices/Text/WinQLCodePage.h"
#include "WinQL/CodeServices/Text/WinString.h"
#include "WinQL/GUI/Window.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	//--------------------------------------------------------------------------------
	struct Coord 
	{
		short X;
		short Y;
	};

	//--------------------------------------------------------------------------------
	struct SmallRect 
	{
		short Left;
		short Top;
		short Right;
		short Bottom;
	};

	//--------------------------------------------------------------------------------
	struct ConsoleSelectionInfo
	{
		unsigned long dwFlags;
		Coord dwSelectionAnchor;
		SmallRect srSelection;
	};

	//--------------------------------------------------------------------------------
	struct ConsoleHistoryInfo
	{
		unsigned int cbSize;
		unsigned int HistoryBufferSize;
		unsigned int NumberOfHistoryBuffers;
		unsigned long dwFlags;
	};

	typedef int (__QCMP_STDCALLCONVENTION *CtrlHandlerCallback)(unsigned long CtrlType);

	//--------------------------------------------------------------------------------
	//Stateless helper class for Console APIs
	class __QOR_INTERFACE(__WINQL) CConsoleHelper
	{
	public:

		__QOR_DECLARE_OCLASS_ID(CConsoleHelper);

		CConsoleHelper();
		virtual ~CConsoleHelper();
		bool AddAlias(const TCHAR* Source, const TCHAR* Target, const TCHAR* ExeName);
		bool Alloc(void);
		bool Attach(unsigned long dwProcessId);
		bool Free(void);
		bool GenerateCtrlEvent(unsigned long dwCtrlEvent, unsigned long dwProcessGroupId);
		unsigned long GetAlias(const TCHAR* szSource, CTStringRef strTarget, const TCHAR* szExeName);
		unsigned long GetAliases(CTStringRef strAliases, const TCHAR* szExeName);
		unsigned long GetAliasesLength(const TCHAR* szExeName);
		unsigned long GetAliasExes(CTStringRef strNameBuffer);
		unsigned long GetAliasExesLength();
		CCodePage GetCP(void);
		bool GetDisplayMode(unsigned long& ModeFlags);
		bool GetHistoryInfo(ConsoleHistoryInfo& ConsoleHistoryInfo);
		unsigned long GetOriginalTitle(CTStringRef strConsoleTitle);
		CCodePage GetOutputCP(void);
		unsigned long GetProcessList(nsCodeQOR::CTArray< unsigned long >& ProcessList);
		bool GetSelectionInfo(ConsoleSelectionInfo& ConsoleSelectionInfo);
		unsigned long GetTitle(CTString& strConsoleTitle);
		COSWindow::refType GetWindow(void);
		bool GetNumberOfMouseButtons(unsigned long& NumberOfMouseButtons);
		CStdHandle GetStdHandle(unsigned long nStdHandle);
		bool SetCP(const CCodePage& CodePage);
		bool SetCtrlHandler(CtrlHandlerCallback HandlerRoutine, bool Add);
		bool SetHistoryInfo(const ConsoleHistoryInfo& ConsoleHistoryInfo);
		bool SetOutputCP(const CCodePage& CodePage);
		bool SetTitle(const TCHAR* lpConsoleTitle);
		bool SetStdHandle(unsigned long nStdHandle, CStdHandle& hHandle);

	};

}//nsWin32

#endif//WINQL_CONSOLE_HELPER_H_3
