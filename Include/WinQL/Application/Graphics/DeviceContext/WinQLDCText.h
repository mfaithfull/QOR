//WinQLDCText.h

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

//inline header file for Device Context Text component class

#ifndef _QSYS_MSWINDOWS_WIN32_OSGRAPHICS_DC_TEXT_H_
#define _QSYS_MSWINDOWS_WIN32_OSGRAPHICS_DC_TEXT_H_

//--------------------------------------------------------------------------------
class __QOR_INTERFACE( __WINQL ) CText
{
public:

	__QOR_DECLARE_OCLASS_ID( CText );
	
	CText( CDeviceContext& DC );
	virtual ~CText();
	unsigned int GetAlignment( void );
	int GetCharacterExtra( void );
	int GetCharset( void );
	int GetCharsetInfo( nsWin32::LPFONTSIGNATURE lpSig, unsigned long dwFlags );
	unsigned long GetColour( void );
	bool GetExtentExPoint( const TCHAR* lpszStr, int cchString, int nMaxExtent, int* lpnFit, int* alpDx, nsWin32::SIZE* lpSize );
	bool GetExtentExPointI( unsigned short* pgiIn, int cgi, int nMaxExtent, int* lpnFit, int* alpDx, nsWin32::SIZE* lpSize );
	bool GetExtentPoint( const TCHAR* lpString, int cbString, nsWin32::SIZE* lpSize );
	bool GetExtentPoint32( const TCHAR* lpString, int c, nsWin32::SIZE* lpSize );
	bool GetExtentPointI( unsigned short* pgiIn, int cgi, nsWin32::SIZE* lpSize );
	int GetFace( int nCount, TCHAR* lpFaceName );
	bool GetMetrics( nsWin32::LPTEXTMETRIC lptm );
	bool PolyOut( const nsWin32::POLYTEXT* pptxt, int cStrings );
	unsigned int SetAlignment( unsigned int fMode );
	int SetCharacterExtra( int nCharExtra );
	unsigned long SetColour( unsigned long crColour );
	bool SetJustification( int nBreakExtra, int nBreakCount );
	bool Output( int nXStart, int nYStart, const TCHAR* lpString, int cbString );

protected:

	CDeviceContext& m_DC;

private:

	//--------------------------------------------------------------------------------
	CText();//Not to be implemented
	CText( const CText& Src );//Not to be implemented
	CText& operator = ( const CText& Src );//Not to be implemented
};

#endif//_QSYS_MSWINDOWS_WIN32_OSGRAPHICS_DC_TEXT_H_
