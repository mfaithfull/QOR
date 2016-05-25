//complex.cpp

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

//Generic ccomplex implementation
//An exported standard C interface which forwards calls to the matching C++ implementaion for the platform

#include "CQOR/CQORPolicy.h"
#include <complex.h>
#include <errno.h>
#include "SystemQOR.h"
#include QOR_SYS_PLATFORMHEADER(_complex.h)
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "CodeQOR/ErrorSystem/Error.h"
#include "CQOR.h"

//--------------------------------------------------------------------------------
namespace
{
	nsPlatform::Ccomplex _complex;
}//anonymous

__QCMP_STARTLINKAGE_C

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex cacos( double_complex z )
{
    __QCS_FCONTEXT( "cacos" );

	double_complex dResult;
    __QCS_PROTECT
    {
        dResult = _complex.cacos( z );
    }__QCS_ENDPROTECT
    return dResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex cacosf( float_complex z )
{
    __QCS_FCONTEXT( "cacosf" );
    float_complex fResult;
    __QCS_PROTECT
    {
		//fResult._init();
        fResult = _complex.cacosf( z );
    }__QCS_ENDPROTECT
    return fResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex cacosl( long_double_complex z )
{
    __QCS_FCONTEXT( "cacosl" );

	long_double_complex lResult;
    __QCS_PROTECT
    {
		//lResult._init();
        lResult = _complex.cacosl( z );
    }__QCS_ENDPROTECT
    return lResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex casin( double_complex z )
{
    __QCS_FCONTEXT( "casin" );

	double_complex dResult;
    __QCS_PROTECT
    {
	    //dResult._init();
        dResult = _complex.casin( z );
    }__QCS_ENDPROTECT
    return dResult;
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex casinf(float_complex z)
{
    __QCS_FCONTEXT( "casinf" );
    return _complex.casinf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex casinl(long_double_complex z)
{
    __QCS_FCONTEXT( "casinl" );
    return _complex.casinl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex catan(double_complex z)
{
    __QCS_FCONTEXT( "catan" );
    return _complex.catan( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex catanf(float_complex z)
{
    __QCS_FCONTEXT( "catanf" );
    return _complex.catanf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex catanl(long_double_complex z)
{
    __QCS_FCONTEXT( "catanl" );
    return _complex.catanl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex ccos(double_complex z)
{
    __QCS_FCONTEXT( "ccos" );
    return _complex.ccos( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex ccosf(float_complex z)
{
    __QCS_FCONTEXT( "ccosf" );
    return _complex.ccosf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex ccosl(long_double_complex z)
{
    __QCS_FCONTEXT( "ccosl" );
    return _complex.ccosl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex csin( double_complex z )
{
    __QCS_FCONTEXT( "csin" );
    return _complex.csin( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex csinf( float_complex z )
{
    __QCS_FCONTEXT( "csinf" );
    return _complex.csinf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex csinl( long_double_complex z )
{
    __QCS_FCONTEXT( "csinl" );
    return _complex.csinl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex ctan( double_complex z )
{
    __QCS_FCONTEXT( "ctan" );
    return _complex.ctan( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex ctanf( float_complex z )
{
    __QCS_FCONTEXT( "ctanf" );
    return _complex.ctanf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex ctanl( long_double_complex z )
{
    __QCS_FCONTEXT( "ctanl" );
    return _complex.ctanl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex cacosh( double_complex z )
{
    __QCS_FCONTEXT( "cacosh" );
    return _complex.cacosh( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex cacoshf( float_complex z )
{
    __QCS_FCONTEXT( "cacoshf" );
    return _complex.cacoshf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex cacoshl( long_double_complex z )
{
    __QCS_FCONTEXT( "cacoshl" );
    return _complex.cacoshl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex casinh( double_complex z )
{
    __QCS_FCONTEXT( "casinh" );
    return _complex.casinh( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex casinhf( float_complex z )
{
    __QCS_FCONTEXT( "casinhf" );
    return _complex.casinhf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex casinhl( long_double_complex z )
{
    __QCS_FCONTEXT( "casinhl" );
    return _complex.casinhl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex catanh( double_complex z )
{
    __QCS_FCONTEXT( "catanh" );
    return _complex.catanh( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex catanhf( float_complex z )
{
    __QCS_FCONTEXT( "catanhf" );
    return _complex.catanhf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex catanhl( long_double_complex z )
{
    __QCS_FCONTEXT( "catanhl" );
    return _complex.catanhl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex ccosh( double_complex z )
{
    __QCS_FCONTEXT( "ccosh" );
    return _complex.ccosh( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex ccoshf( float_complex z )
{
    __QCS_FCONTEXT( "ccoshf" );
    return _complex.ccoshf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex ccoshl( long_double_complex z )
{
    __QCS_FCONTEXT( "ccoshl" );
    return _complex.ccoshl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex csinh( double_complex z )
{
    __QCS_FCONTEXT( "csinh" );
    return _complex.csinh( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex csinhf( float_complex z )
{
    __QCS_FCONTEXT( "csinhf" );
    return _complex.csinhf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex csinhl( long_double_complex z )
{
    __QCS_FCONTEXT( "csinhl" );
    return _complex.csinhl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex ctanh( double_complex z )
{
    __QCS_FCONTEXT( "ctanh" );
    return _complex.ctanh( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex ctanhf( float_complex z )
{
    __QCS_FCONTEXT( "ctanhf" );
    return _complex.ctanhf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex ctanhl( long_double_complex z )
{
    __QCS_FCONTEXT( "ctanhl" );
    return _complex.ctanhl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex cexp( double_complex z )
{
    __QCS_FCONTEXT( "cexp" );
    return _complex.cexp( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex cexpf( float_complex z )
{
    __QCS_FCONTEXT( "cexpf" );
    return _complex.cexpf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex cexpl( long_double_complex z )
{
    __QCS_FCONTEXT( "cexpl" );
    return _complex.cexpl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex clog( double_complex z )
{
    __QCS_FCONTEXT( "clog" );
    return _complex.clog( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex clogf( float_complex z )
{
    __QCS_FCONTEXT( "clogf" );
    return _complex.clogf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex clogl( long_double_complex z )
{
    __QCS_FCONTEXT( "clogl" );
    return _complex.clogl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double cabs( double_complex z )
{
    __QCS_FCONTEXT( "cabs" );
    return _complex.cabs( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float cabsf( float_complex z )
{
    __QCS_FCONTEXT( "cabsf" );
    return _complex.cabsf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long double cabsl( long_double_complex z )
{
    __QCS_FCONTEXT( "cabsl" );
    return _complex.cabsl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex cpow( double_complex x, double_complex y )
{
    __QCS_FCONTEXT( "cpow" );
    return _complex.cpow( x, y );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex cpowf( float_complex x, float_complex y )
{
    __QCS_FCONTEXT( "cpowf" );
    return _complex.cpowf( x, y );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex cpowl( long_double_complex x, long_double_complex y )
{
    __QCS_FCONTEXT( "cpowl" );
    return _complex.cpowl( x, y );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex csqrt( double_complex z )
{
    __QCS_FCONTEXT( "csqrt" );
    return _complex.csqrt( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex csqrtf( float_complex z )
{
    __QCS_FCONTEXT( "csqrtf" );
    return _complex.csqrtf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex csqrtl( long_double_complex z )
{
    __QCS_FCONTEXT( "csqrtl" );
    return _complex.csqrtl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double carg( double_complex z )
{
    __QCS_FCONTEXT( "carg" );
    return _complex.carg( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float cargf( float_complex z )
{
    __QCS_FCONTEXT( "cargf" );
    return _complex.cargf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long double cargl( long_double_complex z )
{
    __QCS_FCONTEXT( "cargl" );
    return _complex.cargl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double cimag( double_complex z )
{
    __QCS_FCONTEXT( "cimag" );
    return _complex.cimag( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float cimagf( float_complex z )
{
    __QCS_FCONTEXT( "cimagf" );
    return _complex.cimagf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long double cimagl( long_double_complex z )
{
    __QCS_FCONTEXT( "cimagl" );
    return _complex.cimagl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex conj( double_complex z )
{
    __QCS_FCONTEXT( "conj" );
    return _complex.conj( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex conjf( float_complex z )
{
    __QCS_FCONTEXT( "conjf" );
    return _complex.conjf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex conjl( long_double_complex z )
{
    __QCS_FCONTEXT( "conjl" );
    return _complex.conjl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double_complex cproj( double_complex z )
{
    __QCS_FCONTEXT( "cproj" );
    return _complex.cproj( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float_complex cprojf( float_complex z )
{
    __QCS_FCONTEXT( "cprojf" );
    return _complex.cprojf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long_double_complex cprojl( long_double_complex z )
{
    __QCS_FCONTEXT( "cprojl" );
    return _complex.cprojl( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) double creal( double_complex z )
{
    __QCS_FCONTEXT( "creal" );
    return _complex.creal( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) float crealf( float_complex z )
{
    __QCS_FCONTEXT( "crealf" );
    return _complex.crealf( z );
}

//--------------------------------------------------------------------------------
__QOR_INTERFACE( __CQOR ) long double creall( long_double_complex z )
{
    __QCS_FCONTEXT( "creall" );
    return _complex.creall( z );
}

__QCMP_ENDLINKAGE_C

