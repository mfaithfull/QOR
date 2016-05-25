//MSW_math.h

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

//MSWindows overrides for math

#ifndef SYSTEMQOR_MSW_MATH_H_3
#define SYSTEMQOR_MSW_MATH_H_3

#include "SystemQOR/Posix/Basemath.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Cmath : public nsBaseCRT::Cmath
	{
		
	public:

		Cmath();
		virtual ~Cmath();

#pragma __QCMP_WARNING_PUSH
#pragma __QCMP_WARNING_DISABLE( __QCMP_WARN_CONV_FROM_LONG_DOUBLE_TO_DOUBLE, "Intentional conversion of long double to double" )

		/*
		int fpclassify(long double x);
		int isfinite(long double x);
		int isinf(long double x);
		int isnan(long double x);
		int isnormal(long double x);
		int signbit(long double x);
		*/
		//--------------------------------------------------------------------------------
		virtual long double acosl( long double x )
		{
			return acos( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double asinl( long double x )
		{
			return asin( x );
		}

		
		//--------------------------------------------------------------------------------
		virtual long double atanl(long double x)
		{
			return atan( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double atan2l( long double y, long double x )
		{
			return atan2( y, x );
		}

		//--------------------------------------------------------------------------------
		virtual long double cosl( long double x )
		{
			return cos( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double sinl( long double x )
		{
			return sin( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double tanl( long double x )
		{
			return tan( x );
		}
		
		//--------------------------------------------------------------------------------
		virtual long double acoshl( long double x )
		{
			return acosh( x );
		}
		//--------------------------------------------------------------------------------
		virtual long double asinhl( long double x )
		{
			return asinh( x );
		}
		
		//--------------------------------------------------------------------------------
		virtual long double atanhl( long double x )
		{
			return atanh( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double coshl( long double x )
		{
			return cosh( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double sinhl( long double x )
		{
			return sinh( x );
		}
		
		//--------------------------------------------------------------------------------
		virtual long double tanhl( long double x )
		{
			return tanh( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double expl( long double x )
		{
			return exp( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double exp2l( long double x )
		{
			return exp2( x );
		}
		
		//--------------------------------------------------------------------------------
		virtual long double expm1l( long double x )
		{
			return expm1( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double frexpl( long double value, int* exp )
		{
			return frexp( value, exp );
		}

		//--------------------------------------------------------------------------------
		virtual int ilogbl( long double x )
		{
			return ilogb( x );
		}
		
		//--------------------------------------------------------------------------------
		virtual long double ldexpl( long double x, int exp )
		{
			return ldexpl( x, exp );
		}

		//--------------------------------------------------------------------------------
		virtual long double logl( long double x )
		{
			return log( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double log10l( long double x )
		{
			return log10( x );
		}
		
		//--------------------------------------------------------------------------------
		virtual long double log1pl( long double x )
		{
			return log1p( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double log2l( long double x )
		{
			return log2( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double logbl( long double x )
		{
			return logb( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double modfl( long double value, long double* iptr )
		{
			return modf( value, reinterpret_cast< double* >( iptr ) );
		}

		//--------------------------------------------------------------------------------
		virtual long double scalbnl( long double x, int n )
		{
			return scalbn( x, n );
		}

		//--------------------------------------------------------------------------------
		virtual long double scalblnl( long double x, long int n )
		{
			return scalbln( x, n );
		}

		//--------------------------------------------------------------------------------
		virtual long double cbrtl( long double x )
		{
			return cbrt( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double fabsl( long double x )
		{
			return fabs( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double hypotl( long double x, long double y )
		{
			return hypot( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double powl( long double x, long double y )
		{
			return pow( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double sqrtl( long double x )
		{
			return sqrt( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double erfl( long double x )
		{
			return erf( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double erfcl( long double x )
		{
			return erfc( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double lgammal( long double x )
		{
			return lgamma( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double tgammal( long double x )
		{
			return tgamma( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double ceill( long double x )
		{
			return ceil( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double floorl( long double x )
		{
			return floor( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double nearbyintl( long double x )
		{
			return nearbyint( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double rintl( long double x )
		{
			return rint( x );
		}

		//--------------------------------------------------------------------------------
		virtual long int lrintl(long double x)
		{
			return lrint( x );
		}

		//--------------------------------------------------------------------------------
		virtual long long int llrintl( long double x )
		{
			return llrint( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double roundl( long double x )
		{
			return round( x );
		}

		//--------------------------------------------------------------------------------
		virtual long int lroundl( long double x )
		{
			return lround( x );
		}

		//--------------------------------------------------------------------------------
		virtual long long int llroundl( long double x )
		{
			return llround( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double truncl( long double x )
		{
			return trunc( x );
		}

		//--------------------------------------------------------------------------------
		virtual long double fmodl( long double x, long double y )
		{
			return fmod( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double remainderl( long double x, long double y )
		{
			return remainder( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double remquol( long double x, long double y, int* quo )
		{
			return remquo( x, y, quo );
		}

		//--------------------------------------------------------------------------------
		virtual long double copysignl( long double x, long double y )
		{
			return copysign( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double nanl( const char* tagp )
		{
			return nan( tagp );
		}

		//--------------------------------------------------------------------------------
		virtual long double nextafterl( long double x, long double y )
		{
			return nextafter( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double nexttowardl( long double x, long double y )
		{
			return nexttoward( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double fdiml( long double x, long double y )
		{
			return fdim( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double fmaxl( long double x, long double y )
		{
			return fmax( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double fminl( long double x, long double y )
		{
			return fmin( x, y );
		}

		//--------------------------------------------------------------------------------
		virtual long double fmal( long double x, long double y, long double z )
		{
			return fma( x, y, z );
		}
		
		//--------------------------------------------------------------------------------
		/*
		virtual int isgreater(long double x, long double y);
		virtual int isgreaterequal(long double x, long double y);
		virtual int isless(long double x, long double y);
		virtual int islessequal(long double x, long double y);
		virtual int islessgreater(long double x, long double y);
		virtual int isunordered(long double x, long double y);
		*/
#pragma __QCMP_WARNING_POP

	private:

		Cmath( const Cmath& );
		Cmath& operator = ( const Cmath& );

	};

}//nsWin32


#endif//SYSTEMQOR_MSW_MATH_H_3

