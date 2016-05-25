//NSW_limits.h

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

//MSWindows overrides for limits

#ifndef SYSTEMQOR_MSW_LIMITS_H_3
#define SYSTEMQOR_MSW_LIMITS_H_3

#include "SystemQOR/Posix/Baselimits.h"
#include "SystemQOR/MSWindows/types/float_types.h"
#include <float.h>

#define _HEAP_MAXREQ ( ::nsWin32::Climits::HeapMaxRequest() )
#define __CHAR_BIT__		8
#define __FLT_MANT_DIG__   FLT_MANT_DIG
#define __FLT_DIG__        FLT_DIG
#define __FLT_RADIX__      FLT_RADIX
#define __FLT_MIN_EXP__    FLT_MIN_EXP
#define __FLT_MIN_10_EXP__ FLT_MIN_10_EXP
#define __FLT_MAX_EXP__    FLT_MAX_EXP
#define __FLT_MAX_10_EXP__ FLT_MAX_10_EXP
#define __FLT_MIN__        FLT_MIN
#define __FLT_MAX__        FLT_MAX
#define __FLT_EPSILON__    FLT_EPSILON
// predefined by MinGW GCC
#define __FLT_DENORM_MIN__ 1.40129846432481707092e-45F

#define __DBL_MANT_DIG__   DBL_MANT_DIG
#define __DBL_DIG__        DBL_DIG
#define __DBL_RADIX__      DBL_RADIX
#define __DBL_MIN_EXP__    DBL_MIN_EXP
#define __DBL_MIN_10_EXP__ DBL_MIN_10_EXP
#define __DBL_MAX_EXP__    DBL_MAX_EXP
#define __DBL_MAX_10_EXP__ DBL_MAX_10_EXP
#define __DBL_MIN__        DBL_MIN
#define __DBL_MAX__        DBL_MAX
#define __DBL_EPSILON__    DBL_EPSILON
// predefined by MinGW GCC
#define __DBL_DENORM_MIN__ double(4.94065645841246544177e-324L)

#define __LDBL_MANT_DIG__   LDBL_MANT_DIG
#define __LDBL_DIG__        LDBL_DIG
#define __LDBL_RADIX__      LDBL_RADIX
#define __LDBL_MIN_EXP__    LDBL_MIN_EXP
#define __LDBL_MIN_10_EXP__ LDBL_MIN_10_EXP
#define __LDBL_MAX_EXP__    LDBL_MAX_EXP
#define __LDBL_MAX_10_EXP__ ( nsPlatform::LongDoubleMax10Exponent )//LDBL_MAX_10_EXP
#define __LDBL_MIN__        LDBL_MIN
#define __LDBL_MAX__        LDBL_MAX
#define __LDBL_EPSILON__    LDBL_EPSILON

// predefined by MinGW GCC
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L

// __builtin replacements/workarounds
#include <math.h> // HUGE_VAL
//#include <ymath.h> // internal MSVC header providing the needed functionality
#define __builtin_huge_val()     HUGE_VAL
#define __builtin_huge_valf()    _FInf._Float
#define __builtin_huge_vall()    _LInf._Long_double
#define __builtin_nan(__dummy)   _Nan._Double
#define __builtin_nanf(__dummy)  _FNan._Float
#define __builtin_nanl(__dummmy) _LNan._Long_double
#define __builtin_nans(__dummy)  _Snan._Double
#define __builtin_nansf(__dummy) _FSnan._Float
#define __builtin_nansl(__dummy) _LSnan._Long_double



//--------------------------------------------------------------------------------
namespace nsWin32
{
	__QCMP_STATIC_CONSTANT( Cmp_long_long, LongLongMax = ( ( Cmp_unsigned_long_long( ~0x0 ) ) >> 1 ) );
	__QCMP_STATIC_CONSTANT( Cmp_long_long, LongLongMin = ~( ( Cmp_unsigned_long_long( ~0x0 ) ) >> 1 ) );

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Climits : public nsBaseCRT::Climits
	{
	private:

		__QCMP_STATIC_CONSTANT( unsigned long long,  ull = (0x7ff0000000000000) );

	public:

		static double HugeVal();
		static unsigned long long HeapMaxRequest();
		
		static const Cmp_unsigned__int64 _ullHuge;

		Climits();
		virtual ~Climits();

	private:

		Climits( const Climits& );
		Climits& operator = ( const Climits& );
	};

}//nsWin32

#endif//SYSTEMQOR_MSW_LIMITS_H_3

