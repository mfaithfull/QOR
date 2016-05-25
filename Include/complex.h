//complex.h

// Copyright Querysoft Limited 2015
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

#ifndef QOR_COMPLEX_H_3
#define QOR_COMPLEX_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(_Complex)

#ifndef __CQOR_COMPLEXTYPE_SUPPORTED
typedef nsPlatform::long_double_complex long_double_complex;
typedef nsPlatform::double_complex double_complex;
typedef nsPlatform::float_complex float_complex;
#endif

__QCMP_STARTLINKAGE_C

//#pragma STDC CX_LIMITED_RANGE on-off-switch

    __QOR_INTERFACE( __CQOR ) double_complex cacos(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex cacosf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex cacosl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex casin(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex casinf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex casinl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex catan(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex catanf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex catanl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex ccos(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex ccosf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex ccosl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex csin(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex csinf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex csinl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex ctan(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex ctanf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex ctanl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex cacosh(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex cacoshf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex cacoshl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex casinh(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex casinhf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex casinhl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex catanh(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex catanhf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex catanhl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex ccosh(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex ccoshf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex ccoshl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex csinh(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex csinhf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex csinhl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex ctanh(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex ctanhf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex ctanhl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex cexp(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex cexpf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex cexpl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex clog(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex clogf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex clogl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double cabs(double_complex z);
    __QOR_INTERFACE( __CQOR ) float cabsf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long double cabsl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex cpow(double_complex x, double_complex y);
    __QOR_INTERFACE( __CQOR ) float_complex cpowf(float_complex x, float_complex y);
    __QOR_INTERFACE( __CQOR ) long_double_complex cpowl(long_double_complex x, long_double_complex y);
    __QOR_INTERFACE( __CQOR ) double_complex csqrt(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex csqrtf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex csqrtl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double carg(double_complex z);
    __QOR_INTERFACE( __CQOR ) float cargf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long double cargl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double cimag(double_complex z);
    __QOR_INTERFACE( __CQOR ) float cimagf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long double cimagl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex conj(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex conjf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex conjl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double_complex cproj(double_complex z);
    __QOR_INTERFACE( __CQOR ) float_complex cprojf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long_double_complex cprojl(long_double_complex z);
    __QOR_INTERFACE( __CQOR ) double creal(double_complex z);
    __QOR_INTERFACE( __CQOR ) float crealf(float_complex z);
    __QOR_INTERFACE( __CQOR ) long double creall(long_double_complex z);

    //The following names are reserved for future addition to this header
#	define cerf __reserved__
#	define cerfc __reserved__
#	define cexp2 __reserved__
#	define cexpm1 __reserved__
#	define clog10 __reserved__
#	define clog1p __reserved__
#	define clog2 __reserved__
#	define clgamma __reserved__
#	define ctgamma __reserved__

__QCMP_ENDLINKAGE_C

#endif //QOR_COMPLEX_H_3

