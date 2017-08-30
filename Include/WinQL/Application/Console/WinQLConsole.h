//WinQLConsole.h

// Copyright Querysoft Limited 2013, 2016, 2017
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

#ifndef WINQL_CONSOLE_H_3
#define WINQL_CONSOLE_H_3

#include "CompilerQOr.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/ErrorSystem/DefaultHandler.h"
#include "WinQL/System/FileSystem/WinQLCRTFile.h"
#include "WinQL/Application/Console/WinQLConsoleScreenBuffer.h"
#include "WinQL/Application/Console/WinQLConsoleHelper.h"
#include "WinQL/Application/Threading/WinQLWaitableObject.h"
#include "AppocritaQOR/Controller.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	class __QOR_INTERFACE(__WINQL) CCRTFile;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CConsStartContHandler  : public nsCodeQOR::CDefaultContinuableHandler
	{
	public:		

		CConsStartContHandler(){};
		virtual ~CConsStartContHandler(){};

		virtual bool Handle( nsCodeQOR::CError* pError );

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CConsoleController : public nsQOR::CController
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CConsoleController );

		CConsoleController();
		virtual ~CConsoleController();
		CConsoleController( const CConsoleController& src );
		CConsoleController& operator = ( const CConsoleController& );

		virtual bool HandleCtrl( unsigned long Ctrl );
		virtual void HandleEvent( InputRecord& Event );
		virtual void OnKeyEvent( KeyEventRecord& KeyEvent );
		virtual void OnMouseEvent( MouseEventRecord& MouseEvent );
		virtual void OnWindowBufferSizeEvent( WindowBufferSizeRecord& WindowBufferSizeEvent );
		virtual void OnFocusEvent( FocusEventRecord& FocusEvent );
		virtual void OnMenuEvent( MenuEventRecord& MenuEvent );
		virtual bool OnCtrlC( void );
		virtual bool OnClose( void );
		virtual bool OnBreak( void );
		virtual bool OnLogOff( void );
		virtual bool OnShutdown( void );
		virtual bool OnUnknownCtrl( void );
	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CConsoleInput : public CWaitableObject
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CConsoleInput );

		__QOR_DECLARE_REF_TYPE( CConsoleInput );

		CConsoleInput();
		virtual ~CConsoleInput();
		CConsoleInput( const CConsoleInput& );
		CConsoleInput& operator = ( const CConsoleInput& );

		bool operator == ( const CConsoleInput& cmp )
		{
			return m_Handle == cmp.m_Handle;
		}

		virtual bool OnCtrl( unsigned long ulCtrl );
		virtual void OnSignaled( void );

		nsCodeQOR::CSTMember< CConsoleController > Controller;

	protected:

		static const unsigned int scuiBufferSize = 65536 / sizeof( InputRecord );
		InputRecord m_InputBuffer[ scuiBufferSize ];

	};

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE(__WINQL) CConsole
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CConsole );
		__QOR_IMPL_REF( CConsole );

		//--------------------------------------------------------------------------------
		enum eConsoleDisplayMode
		{
			FullScreen_Mode = 1,
			Window_Mode
		};

		//Input Mode flags
		__QCMP_STATIC_CONSTANT(unsigned short, Processed_Input = 0x0001);
		__QCMP_STATIC_CONSTANT(unsigned short, Line_Input = 0x0002);
		__QCMP_STATIC_CONSTANT(unsigned short, Echo_Input = 0x0004);
		__QCMP_STATIC_CONSTANT(unsigned short, Window_Input = 0x0008);
		__QCMP_STATIC_CONSTANT(unsigned short, Mouse_Input = 0x0010);
		__QCMP_STATIC_CONSTANT(unsigned short, Insert_Mode = 0x0020);
		__QCMP_STATIC_CONSTANT(unsigned short, Quick_Edit_Mode = 0x0040);
		__QCMP_STATIC_CONSTANT(unsigned short, Extended_Flags = 0x0080);
		__QCMP_STATIC_CONSTANT(unsigned short, Auto_Position = 0x0100);

		// Output Mode flags:
		__QCMP_STATIC_CONSTANT(unsigned short, Processed_Output = 0x0001);
		__QCMP_STATIC_CONSTANT(unsigned short, Wrap_At_EOL_Output = 0x0002);

		//--------------------------------------------------------------------------------
		//Properties

		__QCS_REF_PROP(CConsole, eConsoleDisplayMode, DisplayMode);
		__QCS_REF_PROP(CConsole, CConsoleInput::ref_type, InputStdHandle);
		__QCS_REF_PROP(CConsole, CFileHandle, OutputStdHandle);
		__QCS_REF_PROP(CConsole, CFileHandle, ErrorStdHandle);
		__QCS_REF_PROP(CConsole, CTString, Title);
		__QCS_REF_PROP(CConsole, CCodePage, OutputCodePage);
		__QCS_REF_PROP(CConsole, CCodePage, InputCodePage);
		__QCS_REF_PROP(CConsole, CTString, OriginalTitle);//Read only
		__QCS_REF_PROP(CConsole, ConsoleHistoryInfo, HistoryInfo);
		__QCS_REF_PROP(CConsole, ConsoleSelectionInfo, SelectionInfo);//Read only
		__QCS_REF_PROP(CConsole, COSWindow::refType, Window);//Read only
		__QCS_REF_PROP(CConsole, unsigned long, NumberOfMouseButtons);//Read only
		__QCS_REF_PROP(CConsole, CConsoleScreenBuffer::refType, ScreenBuffer);	

#		include "WinQLConsoleAliases.h"

		friend class CAliases;

		CConsole();
		~CConsole();

		static ref_type TheWin32Console(void);
		static int __stdcall CtrlHandler( unsigned long CtrlType );

	protected:

		eConsoleDisplayMode GetDisplayMode(void);
		bool SetDisplayMode(const eConsoleDisplayMode& Mode);

		CTString GetTitleText(void);
		bool SetTitleText(const CTString& Title);

		CCodePage GetOutputCodePage(void);
		bool SetOutputCodePage(const CCodePage& OutputCP);

		CCodePage GetInputCodePage(void);
		bool SetInputCodePage(const CCodePage& InputCP);

		CTString GetOriginalTitle(void);

		ConsoleHistoryInfo GetHistoryInfo(void);
		bool SetHistoryInfo(const ConsoleHistoryInfo& HistoryInfo);

		ConsoleSelectionInfo GetSelectionInfo(void);
		COSWindow::refType GetWindow(void);
		unsigned long GetNumberOfMouseButtons(void);
		CConsoleScreenBuffer::refType GetScreenBuffer(void);

		CConsoleInput::ref_type GetInputStdHandle( void );

		CConsoleScreenBuffer m_Win32DefaultScreenBuffer;

	public:

		CConsoleHelper m_Helper;
		CConsoleInput m_ConsoleInput;

		static void __initconin(void);
		static void __initconout(void);
		static void __termcon(void);

		static CCRTFile* ConsoleInputFile(void);
		static CCRTFile* ConsoleOutputFile(void);

		static CCRTFile* s_pConsoleInput;// console input
		static CCRTFile* s_pConsoleOutput;// console output

	};

}//nsWin32

#endif//WINQL_CONSOLE_H_3
