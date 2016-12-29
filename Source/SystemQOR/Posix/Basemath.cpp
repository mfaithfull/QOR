//Basemath.cpp

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

#include "SystemQOR/Posix/Basemath.h"
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID( Cmath );

	const bool Cmath::largest_exponent_is_normal = false;
	const bool Cmath::no_denormals = false;
	const long double Cmath::X_TLOSS = 1.41484755040568800000e+16;

	//------------------------------------------------------------------------------
	const bool& Cmath::NoDenormals( void )
	{
		return Cmath::no_denormals;
	}

	//------------------------------------------------------------------------------
	const bool& Cmath::LargestExponentIsNormal( void )
	{
		return Cmath::largest_exponent_is_normal;
	}

	//--------------------------------------------------------------------------------
	Cmath::Cmath()
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::Cmath" );
	}

	//--------------------------------------------------------------------------------
	Cmath::~Cmath()
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::~Cmath" );
	}

	//--------------------------------------------------------------------------------
	int Cmath::fpclassify( long double x )
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fpclassify" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cmath::isfinite(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::isfinite" );
		errno = ENOSYS;
		return (int)(0);
	}

	//--------------------------------------------------------------------------------
	int Cmath::isinf(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::isinf" );
		errno = ENOSYS;
		return (int)(0);
	}

	//--------------------------------------------------------------------------------
	int Cmath::isnan(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::isnan" );
		errno = ENOSYS;
		return (int)(0);
	}

	//--------------------------------------------------------------------------------
	int Cmath::isnormal(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::isnormal" );
		errno = ENOSYS;
		return (int)(0);
	}

	//--------------------------------------------------------------------------------
	int Cmath::signbit(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::signbit" );
		errno = ENOSYS;
		return (int)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::atanl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::atanl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::atan2l(long double y, long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::atan2l" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::cosl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::cosl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::sinl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::sinl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::tanl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::tanl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::atanhl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::atanhl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::coshl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::coshl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::sinhl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::sinhl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::tanhl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::tanhl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::expl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::expl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::exp2l(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::exp2l" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::expm1l(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::expm1l" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::frexpl(long double value, int *exp)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::frexpl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	int Cmath::ilogbl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::ilogbl" );
		errno = ENOSYS;
		return (int)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::ldexpl(long double x, int exp)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::ldexpl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::logl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::logl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::log10l(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::log10l" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::log1pl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::log1pl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	double Cmath::log2(double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::log2" );
		errno = ENOSYS;
		return (double)(0);
	}

	//--------------------------------------------------------------------------------
	float Cmath::log2f(float x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::log2f" );
		errno = ENOSYS;
		return (float)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::log2l(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::log2l" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::logbl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::logbl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::modfl(long double value, long double *iptr)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::modfl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::scalbnl(long double x, int n)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::scalbnl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::scalblnl(long double x, long int n)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::scalblnl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::cbrtl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::cbrtl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::fabsl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fabsl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::hypotl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::hypotl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::powl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::powl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::sqrtl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::sqrtl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::erfl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::erfl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::erfcl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::erfcl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::lgammal(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::lgammal" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::tgammal(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::tgammal" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::ceill(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::ciell" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::floorl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::floorl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::nearbyintl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::nearbyintl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::rintl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::rintl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long int Cmath::lrintl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::lrintl" );
		errno = ENOSYS;
		return (long int)(0);
	}

	//--------------------------------------------------------------------------------
	long long int Cmath::llrint(double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::llrint" );
		errno = ENOSYS;
		return (long long int)(0);
	}

	//--------------------------------------------------------------------------------
	long long int Cmath::llrintf(float x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::llrintf" );
		errno = ENOSYS;
		return (long long int)(0);
	}

	//--------------------------------------------------------------------------------
	long long int Cmath::llrintl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::llrintl" );
		errno = ENOSYS;
		return (long long int)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::roundl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::roundl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long int Cmath::lroundl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::lroundl" );
		errno = ENOSYS;
		return (long int)(0);
	}

	//--------------------------------------------------------------------------------
	long long int Cmath::llround(double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::llround" );
		errno = ENOSYS;
		return (long long int)(0);
	}

	//--------------------------------------------------------------------------------
	long long int Cmath::llroundf(float x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::llroundf" );
		errno = ENOSYS;
		return (long long int)(0);
	}

	//--------------------------------------------------------------------------------
	long long int Cmath::llroundl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::llroundl" );
		errno = ENOSYS;
		return (long long int)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::truncl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::truncl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::fmodl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fmodl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::remainderl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::remainderl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::remquol(long double x, long double y, int *quo)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::remquol" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::copysignl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::copysignl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::nanl(const char *tagp)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::nanl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::nextafterl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::nextafterl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	double Cmath::nexttoward(double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::nettoward" );
		errno = ENOSYS;
		return (double)(0);
	}

	//--------------------------------------------------------------------------------
	float Cmath::nexttowardf(float x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::nexttowardf" );
		errno = ENOSYS;
		return (float)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::nexttowardl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::nexttowardl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::fdiml(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fdiml" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::fmaxl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fmaxl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::fminl(long double x, long double y)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fminl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::fmal( long double x, long double y, long double z )
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::fmal" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::asinhl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::asinhl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::acoshl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::acoshl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::asinl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::asinl" );
		errno = ENOSYS;
		return (long double)(0);
	}

	//--------------------------------------------------------------------------------
	long double Cmath::acosl(long double x)
	{
		__QCS_MEMBER_FCONTEXT( "Cmath::acosl" );
		errno = ENOSYS;
		return (long double)(0);
	}

}//nsBaseCRT
