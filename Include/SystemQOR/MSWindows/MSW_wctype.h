//MSW_wctype.h

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

//MSWindows overrides for wctype

#ifndef SYSTEMQOR_MSW_WCTYPE_H_3
#define SYSTEMQOR_MSW_WCTYPE_H_3

#include "SystemQOR/Posix/Basewctype.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Cwctype : public nsBaseCRT::Cwctype
	{
	public:

		Cwctype();
		virtual ~Cwctype();

		virtual int iswascii( wint_t wc );
		virtual int iswalnum( wint_t wc );
		virtual int iswalnum_l( wint_t, locale_t );
		virtual int iswalpha( wint_t wc );
		virtual int iswalpha_l( wint_t, locale_t );
		virtual int iswblank( wint_t wc );
		virtual int iswblank_l( wint_t, locale_t );
		virtual int iswcntrl( wint_t wc );
		virtual int iswcntrl_l( wint_t, locale_t );
		virtual int iswdigit( wint_t wc );
		virtual int iswdigit_l( wint_t, locale_t );
		virtual int iswgraph( wint_t wc );
		virtual int iswgraph_l( wint_t, locale_t );
		virtual int iswlower( wint_t wc );
		virtual int iswlower_l( wint_t, locale_t );
		virtual int iswprint( wint_t wc );
		virtual int iswprint_l( wint_t, locale_t );
		virtual int iswpunct( wint_t wc );
		virtual int iswpunct_l( wint_t wc, locale_t );
		virtual int iswspace( wint_t wc );
		virtual int iswspace_l( wint_t wc, locale_t );
		virtual int iswupper( wint_t wc );
		virtual int iswupper_l( wint_t wc, locale_t );
		virtual int iswxdigit( wint_t wc );
		virtual int iswxdigit_l( wint_t wc, locale_t );
		virtual int iswctype( wint_t wc, wctype_t desc );
		virtual int iswctype_l( wint_t wc, wctype_t desc, locale_t );
		virtual wint_t towctrans( wint_t wc, wctrans_t desc );
		virtual wint_t towctrans_l( wint_t wc, wctrans_t desc, locale_t );
		virtual wint_t towlower( wint_t wc );
		virtual wint_t towlower_l( wint_t wc, locale_t );
		virtual wint_t towupper( wint_t wc );
		virtual wint_t towupper_l( wint_t wc, locale_t );
		virtual wctrans_t wctrans( const char* pproperty );
		virtual wctrans_t wctrans_l( const char* pProperty, locale_t );
		virtual wctype_t wctype( const char* pproperty );
		virtual wctype_t wctype_l( const char*, locale_t );

	private:

		Cwctype( const Cwctype& );
		Cwctype& operator = ( const Cwctype& );
	};

}//nsWin32


#endif//SYSTEMQOR_MSW_WCTYPE_H_3

