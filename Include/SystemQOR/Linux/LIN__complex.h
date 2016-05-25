//LIN_complex.h

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

//Linux overrides for complex

#ifndef SYSTEMQOR_LIN_COMPLEX_H_3
#define SYSTEMQOR_LIN_COMPLEX_H_3

#include "SystemQOR.h"
#include "SystemQOR/Linux/types/_Complex_types.h"
//#include "SystemQOR/Posix/Baseregex.h"

//--------------------------------------------------------------------------------
namespace nsLinux
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Ccomplex //: public nsBaseCRT::Cregex
	{
	public:

		Ccomplex(){}
		~Ccomplex(){}

		virtual double complex cacos(double complex);
		virtual float complex cacosf(float complex);
		virtual long double complex cacosl(long double complex);

		virtual double complex casin(double complex);
		virtual float complex casinf(float complex);
		virtual long double complex casinl(long double complex);

		virtual double complex catan(double complex);
		virtual float complex catanf(float complex);
		virtual long double complex catanl(long double complex);

		virtual double complex ccos(double complex);
		virtual float complex ccosf(float complex);
		virtual long double complex ccosl(long double complex);

		virtual double complex csin(double complex);
		virtual float complex csinf(float complex);
		virtual long double complex csinl(long double complex);

		virtual double complex ctan(double complex);
		virtual float complex ctanf(float complex);
		virtual long double complex ctanl(long double complex);

		virtual double complex cacosh(double complex);
		virtual float complex cacoshf(float complex);
		virtual long double complex cacoshl(long double complex);

		virtual double complex casinh(double complex);
		virtual float complex casinhf(float complex);
		virtual long double complex casinhl(long double complex);

		virtual double complex catanh(double complex);
		virtual float complex catanhf(float complex);
		virtual long double complex catanhl(long double complex);

		virtual double complex ccosh(double complex);
		virtual float complex ccoshf(float complex);
		virtual long double complex ccoshl(long double complex);

		virtual double complex csinh(double complex);
		virtual float complex csinhf(float complex);
		virtual long double complex csinhl(long double complex);

		virtual double complex ctanh(double complex);
		virtual float complex ctanhf(float complex);
		virtual long double complex ctanhl(long double complex);

		virtual double complex cexp(double complex);
		virtual float complex cexpf(float complex);
		virtual long double complex cexpl(long double complex);

		virtual double complex clog(double complex);
		virtual float complex clogf(float complex);
		virtual long double complex clogl(long double complex);

		virtual double cabs(double complex);
		virtual float cabsf(float complex);
		virtual long double cabsl(long double complex);

		virtual double complex cpow(double complex, double complex);
		virtual float complex cpowf(float complex, float complex);
		virtual long double complex cpowl(long double complex, long double complex);

		virtual double complex csqrt(double complex);
		virtual float complex csqrtf(float complex);
		virtual long double complex csqrtl(long double complex);

		virtual double carg(double complex);
		virtual float cargf(float complex);
		virtual long double cargl(long double complex);

		virtual double cimag(double complex);
		virtual float cimagf(float complex);
		virtual long double cimagl(long double complex);

		virtual double complex conj(double complex);
		virtual float complex conjf(float complex);
		virtual long double complex conjl(long double complex);

		virtual double complex cproj(double complex);
		virtual float complex cprojf(float complex);
		virtual long double complex cprojl(long double complex);

		virtual double creal(double complex);
		virtual float crealf(float complex);
		virtual long double creall(long double complex);

	private:

		Ccomplex( const Ccomplex& );
		Ccomplex& operator = ( const Ccomplex& );

	};

}//nsLinux

#endif//SYSTEMQOR_LIN_COMPLEX_H_3
