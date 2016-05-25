//WinQLDCSelectedFont.h

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

//inline header file for Device Context Selected Font component class

#ifndef WINQL_GRAPHICS_DC_SELFONT_H_3
#define WINQL_GRAPHICS_DC_SELFONT_H_3

//--------------------------------------------------------------------------------
class __QOR_INTERFACE( __WINQL ) CSelectedFont
{
public:

	__QOR_DECLARE_OCLASS_ID( CSelectedFont );

	CSelectedFont( CDeviceContext& DC );
	virtual ~CSelectedFont();
	unsigned long GetData( unsigned long dwTable, unsigned long dwOffset, void* lpvBuffer, unsigned long cbData );
	unsigned long GetLanguageInfo( void );
	unsigned long GetUnicodeRanges( nsWin32::LPGLYPHSET lpgs );
	unsigned long GetGlyphIndicesT( const TCHAR* lpstr, int c, unsigned short* pgi, unsigned long fl );
	unsigned long GetGlyphOutlineT( unsigned int uChar, unsigned int uFormat, nsWin32::LPGLYPHMETRICS lpgm, unsigned long cbBuffer, void* lpvBuffer, const nsWin32::MAT2* lpmat2 );
	unsigned long GetKerningPairsT( unsigned long nNumPairs, nsWin32::LPKERNINGPAIR lpkrnpair );
	unsigned int GetOutlineTextMetricsT( unsigned int cbData, nsWin32::LPOUTLINETEXTMETRIC lpOTM );

protected:

	CDeviceContext& m_DC;

private:

	//--------------------------------------------------------------------------------
	CSelectedFont();//Not to be implemented
	CSelectedFont( const CSelectedFont& Src );//Not to be implemented
	CSelectedFont& operator = ( const CSelectedFont& Src );//Not to be implemented

};

#endif//WINQL_GRAPHICS_DC_SELFONT_H_3
