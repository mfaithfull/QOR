//Basemath.h

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

//Base CRT class for Cmath

#ifndef SYSTEMQOR_POSIX_MATH_H_3
#define SYSTEMQOR_POSIX_MATH_H_3

#include <errno.h>
#include <limits.h>
#include "Baseerrno.h"
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(math)

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
    //--------------------------------------------------------------------------------
    class __QOR_INTERFACE( __QSYS ) Cmath
    {

	public:

		__QOR_DECLARE_OCLASS_ID( Cmath );

        //set X_TLOSS = pi*2**52, which is possibly defined in <values.h>
        static const long double X_TLOSS;//		1.41484755040568800000e+16
        static const bool no_denormals;//		_FLT_NO_DENORMALS
        static const bool largest_exponent_is_normal;//_FLT_LARGEST_EXPONENT_IS_NORMAL

		static const bool& NoDenormals( void );
		static const bool& LargestExponentIsNormal( void );

        //REENT temporary replacements
        //TODO: Make this thread safe
        int m_isigngam;

#ifndef QOR_ARCH_ENDIAN
#	error Must define endianness
#endif

        // A union which permits us to convert between a double and two 32 bit ints.

#if (QOR_ARCH_ENDIAN == QOR_ARCH_BYTE_BIG_ENDIAN )
        //------------------------------------------------------------------------------
        typedef union
        {
            double value;
            struct
            {
                Cmp_unsigned__int32 msw;
                Cmp_unsigned__int32 lsw;
            } parts;
        } ieee_double_shape_type;
#endif

#if (QOR_ARCH_ENDIAN == QOR_ARCH_BYTE_LITTLE_ENDIAN )
        //------------------------------------------------------------------------------
        typedef union
        {
            double value;
            struct
            {
                Cmp_unsigned__int32 lsw;
                Cmp_unsigned__int32 msw;
            } parts;
        } ieee_double_shape_type;

#endif

        //--------------------------------------------------------------------------------
        typedef union
        {
            float value;
            Cmp_unsigned__int32 word;
        } ieee_float_shape_type;

        //------------------------------------------------------------------------------
        // Global control over fdlibm error handling.
        enum __fdlibm_version
        {
            _IEEE_ = -1,
            _SVID_,
            _XOPEN_,
            _POSIX_
        };

        static __fdlibm_version m_fdlib_version;

        //------------------------------------------------------------------------------
        // The exception structure passed to the matherr routine.
        struct fexception
        {
            int type;
            char *name;
            double arg1;
            double arg2;
            double retval;
            int err;
        };

        //------------------------------------------------------------------------------
        enum Eexceptions
        {
            EX_DOMAIN = 1,
            EX_SING,
            EX_OVERFLOW,
            EX_UNDERFLOW,
            EX_TLOSS,
            EX_PLOSS
        };

        //------------------------------------------------------------------------------
        union __dmath
        {
            Cmp_unsigned__int32 i[2];
            double d;
        };

        //------------------------------------------------------------------------------
        union __fmath
        {
            Cmp_unsigned__int32 i[1];
            float f;
        };

        //------------------------------------------------------------------------------
        union __ldmath
        {
            Cmp_unsigned__int32 i[4];
            Cmp_long_double ld;
        };

        //------------------------------------------------------------------------------
        struct dcomplex
        {
            double x;
            double y;
        };

        //------------------------------------------------------------------------------
        struct fcomplex
        {
            float x;
            float y;
        };

        virtual int fpclassify( long double x );
        virtual float infinityf();
        virtual double infinity();
        virtual double cabs( dcomplex z );
        virtual float cabsf( fcomplex z );
        virtual double drem( double x, double y );
        virtual float dremf( float x, float y );
        virtual int finitef( float x );
        virtual int finite( double x );

        virtual int isfinite(long double x);
        virtual int isinf(long double x);
        virtual int isinff( float x );
        virtual int isinf( double x );
        virtual int isnan( double x );
        virtual int isnan(long double x);
        virtual int isnanf( float x );
        virtual int isnormal(long double x);
        virtual int signbit(long double x);
        virtual double acos(double x);
        virtual float acosf(float x);
        virtual long double acosl(long double x);
        virtual double asin(double x);
        virtual float asinf(float x);
        virtual long double asinl(long double x);
        virtual double atan(double x);
        virtual float atanf(float x);
        virtual long double atanl(long double x);
        virtual double atan2(double y, double x);
        virtual float atan2f(float y, float x);
        virtual long double atan2l(long double y, long double x);
        virtual double cos(double x);
        virtual float cosf(float x);
        virtual long double cosl(long double x);
        virtual double sin(double x);
        virtual float sinf(float x);
        virtual long double sinl(long double x);
        virtual double tan(double x);
        virtual float tanf(float x);
        virtual long double tanl(long double x);
        virtual double acosh(double x);
        virtual float acoshf(float x);
        virtual long double acoshl(long double x);
        virtual double asinh(double x);
        virtual float asinhf(float x);
        virtual long double asinhl(long double x);
        virtual double atanh(double x);
        virtual float atanhf(float x);
        virtual long double atanhl(long double x);
        virtual double cosh(double x);
        virtual float coshf(float x);
        virtual long double coshl(long double x);
        virtual double sinh(double x);
        virtual float sinhf(float x);
        virtual long double sinhl(long double x);
        virtual double tanh(double x);
        virtual float tanhf(float x);
        virtual long double tanhl(long double x);
        virtual double exp(double x);
        virtual float expf(float x);
        virtual long double expl(long double x);
        virtual double exp2(double x);
        virtual float exp2f(float x);
        virtual long double exp2l(long double x);
        virtual double expm1(double x);
        virtual float expm1f(float x);
        virtual long double expm1l(long double x);
        virtual double frexp(double value, int *exp);
        virtual float frexpf(float value, int *exp);
        virtual long double frexpl(long double value, int *exp);
        virtual int ilogb(double x);
        virtual int ilogbf(float x);
        virtual int ilogbl(long double x);
        virtual double ldexp(double x, int exp);
        virtual float ldexpf(float x, int exp);
        virtual long double ldexpl(long double x, int exp);
        virtual double log(double x);
        virtual float logf(float x);
        virtual long double logl(long double x);
        virtual double log10(double x);
        virtual float log10f(float x);
        virtual long double log10l(long double x);
        virtual double log1p(double x);
        virtual float log1pf(float x);
        virtual long double log1pl(long double x);
        virtual double log2(double x);
        virtual float log2f(float x);
        virtual long double log2l(long double x);
        virtual double logb(double x);
        virtual float logbf(float x);
        virtual long double logbl(long double x);
        virtual double modf(double value, double *iptr);
        virtual float modff(float value, float *iptr);
        virtual long double modfl(long double value, long double *iptr);
        virtual double scalbn(double x, int n);
        virtual float scalbnf(float x, int n);
        virtual long double scalbnl(long double x, int n);
        virtual double scalbln(double x, long int n);
        virtual float scalblnf(float x, long int n);
        virtual long double scalblnl(long double x, long int n);
        virtual double cbrt( double x );
        virtual float cbrtf(float x);
        virtual long double cbrtl(long double x);
        virtual double fabs(double x);
        virtual float fabsf(float x);
        virtual long double fabsl(long double x);
        virtual double hypot(double x, double y);
        virtual float hypotf(float x, float y);
        virtual long double hypotl(long double x, long double y);
        virtual double pow(double x, double y);
        virtual float powf(float x, float y);
        virtual long double powl(long double x, long double y);
        virtual double sqrt(double x);
        virtual float sqrtf(float x);
        virtual long double sqrtl(long double x);
        virtual double erf(double x);
        virtual float erff(float x);
        virtual long double erfl(long double x);
        virtual double erfc(double x);
        virtual float erfcf(float x);
        virtual long double erfcl(long double x);
        virtual double lgamma(double x);
        virtual float lgammaf(float x);
        virtual double lgamma_r( double x, int* signgamp );
        virtual float lgammaf_r( float x, int* signgamp );
        virtual long double lgammal(long double x);
        virtual double tgamma(double x);
        virtual float tgammaf(float x);
        virtual long double tgammal(long double x);
        virtual float gammaf_r( float x, int* signgamp );
        virtual float gammaf( float x );
        virtual double gamma_r( double x, int* signgamp );
        virtual double gamma( double x );
        virtual double ceil(double x);
        virtual float ceilf(float x);
        virtual long double ceill(long double x);
        virtual double floor(double x);
        virtual float floorf(float x);
        virtual long double floorl(long double x);
        virtual double nearbyint(double x);
        virtual float nearbyintf(float x);
        virtual long double nearbyintl(long double x);
        virtual double rint(double x);
        virtual float rintf(float x);
        virtual long double rintl(long double x);
        virtual long int lrint(double x);
        virtual long int lrintf(float x);
        virtual long int lrintl(long double x);
        virtual long long int llrint(double x);
        virtual long long int llrintf(float x);
        virtual long long int llrintl(long double x);
        virtual double round(double x);
        virtual float roundf(float x);
        virtual long double roundl(long double x);
        virtual long int lround(double x);
        virtual long int lroundf(float x);
        virtual long int lroundl(long double x);
        virtual long long int llround(double x);
        virtual long long int llroundf(float x);
        virtual long long int llroundl(long double x);
        virtual double trunc(double x);
        virtual float truncf(float x);
        virtual long double truncl(long double x);
        virtual double fmod(double x, double y);
        virtual float fmodf(float x, float y);
        virtual long double fmodl(long double x, long double y);
        virtual double remainder(double x, double y);
        virtual float remainderf(float x, float y);
        virtual long double remainderl(long double x, long double y);
        virtual double remquo(double x, double y, int *quo);
        virtual float remquof(float x, float y, int *quo);
        virtual long double remquol(long double x, long double y, int *quo);
        virtual double copysign(double x, double y);
        virtual float copysignf(float x, float y);
        virtual long double copysignl(long double x, long double y);
        virtual double nan(const char *tagp);
        virtual float nanf(const char *tagp);
        virtual long double nanl(const char *tagp);
        virtual double nextafter(double x, double y);
        virtual float nextafterf(float x, float y);
        virtual long double nextafterl(long double x, long double y);
        virtual double nexttoward(double x, long double y);
        virtual float nexttowardf(float x, long double y);
        virtual long double nexttowardl(long double x, long double y);
        virtual double fdim(double x, double y);
        virtual float fdimf(float x, float y);
        virtual long double fdiml(long double x, long double y);
        virtual double fmax(double x, double y);
        virtual float fmaxf(float x, float y);
        virtual long double fmaxl(long double x, long double y);
        virtual double fmin(double x, double y);
        virtual float fminf(float x, float y);
        virtual long double fminl(long double x, long double y);
        virtual double fma( double x, double y, double z );
        virtual float fmaf( float x, float y, float z );
        virtual long double fmal( long double x, long double y, long double z );
        /*
        virtual int isgreater( long double x, long double y );
        virtual int isgreaterequal( long double x, long double y );
        virtual int isless( long double x, long double y );
        virtual int islessequal( long double x, long double y );
        virtual int islessgreater( long double x, long double y );
        virtual int isunordered( long double x, long double y );
        */
        template< typename t1, typename t2 >
        bool isgreater( t1& x, t2& y )
        {
            return ( ( !isunordered( x, y ) ) && ( x > y ) ) ? true : false;
        }

        template< typename t1, typename t2 >
        bool isgreaterequal( t1& x, t2& y )
        {
            return ( ( !isunordered( x, y ) ) && ( x >=  y ) ) ? true : false;
        }

        template< typename t1, typename t2 >
        bool isless( t1& x, t2& y )
        {
            return ( ( !isunordered( x, y ) ) && ( x < y ) ) ? true : false;
        }

        template< typename t1, typename t2 >
        bool islessequal( t1& x, t2& y )
        {
            return ( ( !isunordered( x, y ) ) && ( x <=  y ) ) ? true : false;
        }

        template< typename t1, typename t2 >
        bool islessgreater( t1& x, t2& y )
        {
            return ( ( !isunordered( x, y ) && ( x < y || x > y ) ) )? true : false;
        }

        template< typename t1, typename t2 >
        bool isunordered( t1& a, t2& b )
        {
            return ( fpclassify( a ) == nsPlatform::FpNAN || fpclassify( b ) == nsPlatform::FpNAN ) ? true : false;
        }

        virtual double j0( double x );
        virtual float j0f( float x );
        virtual double j1( double x );
        virtual float j1f( float x );
        virtual double jn( int n, double x );
        virtual float jnf( int n, float x );
        virtual double scalb( double x, double y );
        virtual float scalbf( float x, float fn );
        virtual double y0( double x );

        virtual double y1( double x );

        virtual double yn( int n, double x );

    protected:

        Cmath();
        virtual ~Cmath();

        virtual float y0f( float x );
        virtual float y1f( float x );
        virtual float ynf( int n, float x );
        virtual float significandf( float x );
        virtual double significand( double x );
        virtual void sincosf( float x, float* sinx, float* cosx );
        virtual void sincos( double x, double* sinx, double* cosx );

        virtual int __isinfd( double x );
        virtual int __isnand( double x );
        virtual int __signbitf( float x );
        virtual int __signbitd( double x );

        int matherr( struct fexception* x );

        double __ieee754_acos( double x );
        float __ieee754_acosf( float x );
        double __ieee754_acosh( double x );
        float __ieee754_acoshf( float x );
        double __ieee754_asin( double x );
        float __ieee754_asinf( float x );
        double __ieee754_atan2( double y, double x );
        float __ieee754_atan2f( float y, float x );
        double __ieee754_atanh( double x );
        float __ieee754_atanhf( float x );
        double __ieee754_cosh( double x );
        float __ieee754_coshf( float x );
        double __ieee754_exp( double x );
        float __ieee754_expf( float x );
        double __ieee754_fmod( double x, double y );
        float __ieee754_fmodf( float x, float y );
        double __ieee754_hypot( double x, double y );
        float __ieee754_hypotf( float x, float y );
        double __ieee754_j0( double x );
        float __ieee754_j0f( float x );
        double __ieee754_y0( double x );
        float __ieee754_y0f( float x );
        double __ieee754_j1( double x );
        float __ieee754_j1f( float x );
        double __ieee754_y1( double x );
        float __ieee754_y1f( float x );
        double __ieee754_jn( int n, double x );
        double __ieee754_yn( int n, double x );
        float __ieee754_jnf( int n, float x );
        float __ieee754_ynf( int n, float x );
        double __ieee754_log( double x );
        float __ieee754_logf( float x );
        double __ieee754_log10( double x );
        float __ieee754_log10f( float x );
        double __ieee754_pow( double x, double y );
        float __ieee754_powf( float x, float y );
        Cmp_signed__int32 __ieee754_rem_pio2( double x, double* y );
        Cmp_signed__int32 __ieee754_rem_pio2f( float x, float* y );
        double __ieee754_remainder( double x, double p );
        float __ieee754_remainderf( float x, float p );
        double __ieee754_scalb( double x, double fn );
        float __ieee754_scalbf( float x, float fn );
        double __ieee754_sinh( double x );
        float __ieee754_sinhf( float x );
        double __ieee754_sqrt( double x );
        float __ieee754_sqrtf( float x );
        double __ieee754_gamma_r( double x, int* signgamp );
        float __ieee754_gammaf_r( float x, int* signgamp );
        double __ieee754_lgamma_r( double x, int* signgamp );
        float __ieee754_lgammaf_r( float x, int* signgamp );

    private:

        int __fpclassifyf( float x );
        int __fpclassifyd( double x );

        double pzero( double x );
        double qzero( double x );
        float pzerof( float x );
        float qzerof( float x );
        double pone( double x );
        double qone( double x );
        float ponef( float x );
        float qonef( float x );
        double sin_pi( double x );
        float sin_pif( float x );

        int __kernel_rem_pio2( double* x, double* y, int e0, int nx, int prec, const Cmp_signed__int32* ipio2 );
        int __kernel_rem_pio2f( float* x, float* y, int e0, int nx, int prec, const Cmp_signed__int32* ipio2 );
        double __kernel_cos( double x, double y );
        float __kernel_cosf( float x, float y );
        double __kernel_sin( double x, double y, int iy );
        float __kernel_sinf( float x, float y, int iy );
        double __kernel_tan( double x, double y, int iy );
        float __kernel_tanf( float x, float y, int iy );
        double __kernel_standard( double x, double y, int type );

        //------------------------------------------------------------------------------
        // Get two 32 bit ints from a double.
        template< typename t1, typename t2, typename t3 >
        void extract_words( t1& ix0, t2& ix1, t3 d )
        {
            ieee_double_shape_type ew_u;
            ew_u.value = d;
            ix0 = ew_u.parts.msw;
            ix1 = ew_u.parts.lsw;
        }

        //------------------------------------------------------------------------------
        // Get the more significant 32 bit int from a double.
        template< typename t1, typename t2 >
        void get_high_word( t1& i, t2 d )
        {
            ieee_double_shape_type gh_u;
            gh_u.value = d;
            i = gh_u.parts.msw;
        }

        //------------------------------------------------------------------------------
        // Get the less significant 32 bit int from a double.
        template< typename t1, typename t2 >
        void get_low_word( t1& i, t2 d )
        {
            ieee_double_shape_type gl_u;
            gl_u.value = d;
            i = gl_u.parts.lsw;
        }

        //------------------------------------------------------------------------------
        // Set a double from two 32 bit ints.
        template< typename t1 >
        void insert_words( t1& d, Cmp_unsigned__int32 ix0, Cmp_unsigned__int32 ix1 )
        {
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = ix0;
            iw_u.parts.lsw = ix1;
            d = iw_u.value;
        }

        //------------------------------------------------------------------------------
        // Set the more significant 32 bits of a double from an int.
        template< typename t1, typename t2 >
        void set_high_word( t1& d, t2 v )
        {
            ieee_double_shape_type sh_u;
            sh_u.value = d;
            sh_u.parts.msw = v;
            d = sh_u.value;
        }

        //------------------------------------------------------------------------------
        // Set the less significant 32 bits of a double from an int.
        template< typename t1, typename t2 >
        void set_low_word( t1& d, t2 v )
        {
            ieee_double_shape_type sl_u;
            sl_u.value = d;
            sl_u.parts.lsw = v;
            d = sl_u.value;
        }

        //------------------------------------------------------------------------------
        // Get a 32 bit int from a float.
        template< typename t1, typename t2 >
        void get_float_word( t1& i, t2 d )
        {
            ieee_float_shape_type gf_u;
            gf_u.value = d;
            i = gf_u.word;
        }

        //------------------------------------------------------------------------------
        // Set a float from a 32 bit int.
        template< typename t1, typename t2 >
        void set_float_word( t1& d, t2 i )
        {
            ieee_float_shape_type sf_u;
            sf_u.word = i;
            d = sf_u.value;
        }

        //------------------------------------------------------------------------------
        template< typename t1 >
        bool uword_is_zero( t1 x )
        {
            if( no_denormals )
            {
                return x < 0x00800000L;
            }
            else
            {
                return x == 0;
            }
        }

        //------------------------------------------------------------------------------
        template< typename t1 >
        bool uword_is_subnormal( t1& x )
        {
            if( no_denormals )
            {
                return false;
            }
            else
            {
                return x < 0x00800000L;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_min()
        {
            if( NoDenormals() )
            {
                return 0x00800000;
            }
            else
            {
                return 0x00000001;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_exp_min()
        {
            if( NoDenormals() )
            {
                return 0x42fc0000;
            }
            else
            {
                return 0x43160000;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_log_min()
        {
            if( NoDenormals() )
            {
                return 0x42aeac50;
            }
            else
            {
                return 0x42cff1b5;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_signed__int32 smallest_exp()
        {
            if( NoDenormals() )
            {
                return 1;
            }
            else
            {
                return -22;
            }
        }

        //------------------------------------------------------------------------------
        //True if a positive float with bitmask x is finite.
        template< typename t1 >
        bool uword_isfinite( t1& x )
        {
            if( largest_exponent_is_normal )
            {
                return true;
            }
            else
            {
                return x < 0x7f800000L;
            }
        }

        //------------------------------------------------------------------------------
        //True if a positive float with bitmask x is not a number.
        template< typename t1 >
        bool uword_isnan( t1& x )
        {
            if( largest_exponent_is_normal )
            {
                return false;
            }
            else
            {
                return x > 0x7f800000L;
            }
        }

        //------------------------------------------------------------------------------
        template< typename t1 >
        bool uword_is_infinite( t1& x )
        {
            if( largest_exponent_is_normal )
            {
                return false;
            }
            else
            {
                return x == 0x7f800000L;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_max()
        {
            if( LargestExponentIsNormal() )
            {
                return 0x7fffffff;
            }
            else
            {
                return 0x7f7fffffL;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_exp_max()
        {
            if( LargestExponentIsNormal() )
            {
                return 0x43010000;
            }
            else
            {
                return 0x43000000;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_log_max()
        {
            if( LargestExponentIsNormal() )
            {
                return 0x42b2d4fc;
            }
            else
            {
                return 0x42b17217;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_log2_max()
        {
            if( LargestExponentIsNormal() )
            {
                return 0x42b437e0;
            }
            else
            {
                return 0x42b2d4fc;
            }
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 uword_half_max()
        {
            return (uword_max()-(1L<<23));
        }

        //------------------------------------------------------------------------------
        Cmp_unsigned__int32 largest_exp()
        {
            return (uword_max()>>23);
        }

        //------------------------------------------------------------------------------
        float Huge()
        {
            if( LargestExponentIsNormal() )
            {
                //return ((float)(0x7ff0000000000000));
                return ((float)(0x7ff00000));
                //return ((float)0X1.FFFFFEP128);
            }
            else
            {
                return ((float)3.40282346638528860e+38);
            }
        }

		Cmath( const Cmath& );
		Cmath& operator = ( const Cmath& );
    };

}//nsBaseCRT

#endif//SYSTEMQOR_POSIX_MATH_H_3

