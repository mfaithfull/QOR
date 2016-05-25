//QGWindow.h

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

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include <stdio.h>
#include <string>
#include "Qurses/QursesPolicy.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"
#include "CodeQOR/DataTypes/GUID.h"
#include "Qurses/GUI/QGLayout.h"

#ifndef QURSES_GUI_WINDOW_H_3
#define	QURSES_GUI_WINDOW_H_3

struct _win;

# if _LP64
typedef unsigned int chtype;
# else
typedef unsigned long chtype;  /* 16-bit attr + 16-bit char */
# endif

//--------------------------------------------------------------------------------
namespace nsQurses
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( QURSES_QOR ) CQGWindow
	{

	public:		

		typedef nsCodeQOR::CTLRef< CQGWindow > refType;

		static const int sc_iDefaultLines = 25;
		static const int sc_iDefaultCols = 40;
		static const int sc_iDefaultXPos = 0;
		static const int sc_iDefaultYPos = 0;

		__QOR_DECLARE_OCLASS_ID( CQGWindow );

		CQGWindow( _win* pWindowStruct = 0, int iLines = sc_iDefaultLines, int iCols = sc_iDefaultCols, int iXPos = sc_iDefaultXPos, int iYPos = sc_iDefaultYPos );
		CQGWindow( FILE* pFile );
		CQGWindow( const CQGWindow& src );
		virtual ~CQGWindow();

		void Detach( void );

		//--------------------------------------------------------------------------------
		refType Ref( void )
		{
			return refType( this, false );
		}

		virtual int MoveTo( int XPos, int YPos );
		virtual void Resize( int XSize, int YSize );
		
		CQGWindow* CreateChild( int iLines, int iCols, int XPos, int YPos  );

		const _win* PrivateData( void ) const;

		virtual int Scroll( int iLines );	//TODO: disable in Pad subclass

		int SaveToFile( FILE* pFile );
		int Scan( const char* fmt, ... );
		int MoveScan( int y, int x, const char *fmt, ... );

		int Refresh( void );
		int OutRefesh( void );
		int Redraw( void );
		int RedrawLines( int iStartLine, int iNumLines );

		int Print( const char* fmt, ... );
		int MovePrint( int x, int y, const char* fmt, ... );

		int ClearOK( bool bf );
		int idlOK( bool bf );
		void idcOK( bool bf );
		void immedOK( bool bf );
		int leaveOK( bool bf );
		int SetScrReg( int iTop, int iBot );
		int ScrollOK( bool bf );

		void MousePosition( int& XPos, int& YPos );

		int InStr( char* str );
		int InNStr( char* str, int n );
		int MoveInStr( int XPos, int YPos, char* str );
		int MoveInNStr( int XPos, int YPos, char* str, int n );

		/*
		int InWStr( wchar_t* wstr );
		int InNWStr( wchar_t* wstr, int n );
		int MoveInWStr( int XPos, int YPos, wchar_t* wstr );
		int MoveInNWStr( int XPos, int YPos, wchar_t* wstr, int n );
		*/

		int InsertStr( const char* str );
		int InsertNStr( const char*, int n );
		int MoveInsertStr( int XPos, int YPos, const char* str );
		int MoveInsertNStr( int XPos, int YPos, const char* str, int n );

		int InsertChType( chtype ch );
		int MoveInsertChType( int XPos, int YPos, chtype ch );

		chtype GetBackground( void );
		void SetBackgroundColour( unsigned int uiPaletteColour );
		void SetBackground( chtype ch );
		int PaintBackground( chtype ch );

		int Erase( void );

		int SetAttributes( chtype attrs );
		chtype GetAttributes( void );

		int SetNoDelay( bool bNoDelay );

		void SetLayout( CQGLayout::refType Layout );

		unsigned int GetWidth( void );
		unsigned int GetHeight( void );
		unsigned int Left( void );
		unsigned int Top( void );

		std::string GetWindowTitle( void );
		void SetWindowTitle( std::string& strWindowTitle );

		int MoveAddChArray( int XPos, int YPos, const chtype* pch, int n );

		void AddChild( CQGWindow* pChild );

	protected:

		CQGWindow( CQGWindow* pChild );
		void LoadFromFile( FILE* pFile );

		void SyncDown( void );
		void CursSyncUp( void );
		int SyncOK( bool bf );
		void SyncUp( void );

		int Touch( void );
		int TouchLine( int iStart, int iCount );
		int UnTouch( void );
		int TouchedLines( int y, int n, bool bTouched );
		bool IsLineTouched( int iLine );
		bool IsTouched( void );

		_win* m_pWindowStruct;
		CQGLayout::refType m_Layout;
		std::string m_strWindowTitle;
		std::vector< CQGWindow* > m_VecChildWindows;
	};

}//nsQurses

#endif//QURSES_GUI_WINDOW_H_3

