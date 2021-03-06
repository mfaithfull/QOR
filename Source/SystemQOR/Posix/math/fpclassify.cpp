/* Copyright (C) 2002 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

#include "SystemQOR/Posix/Basemath.h"
#include <math.h>

//------------------------------------------------------------------------------
namespace nsBaseCRT
{
	//------------------------------------------------------------------------------
	int Cmath::__fpclassifyf( float x )
	{
		Cmp_unsigned__int32 w;

		get_float_word( w, x );

		if( w == 0x00000000 || w == 0x80000000 )
		{
			return FP_ZERO;
		}
		else if( ( w >= 0x00800000 && w <= 0x7f7fffff ) || ( w >= 0x80800000 && w <= 0xff7fffff ) )
		{
			return FP_NORMAL;
		}
		else if ( ( w >= 0x00000001 && w <= 0x007fffff ) || ( w >= 0x80000001 && w <= 0x807fffff ) )
		{
			return FP_SUBNORMAL;
		}
		else if ( w == 0x7f800000 || w == 0xff800000 )
		{
			return FP_INFINITE;
		}
		else
		{
			return FP_NAN;
		}
	}

	//------------------------------------------------------------------------------
	int Cmath::__fpclassifyd( double x )
	{
		Cmp_unsigned__int32 msw, lsw;

		extract_words( msw, lsw, x );

		if( ( msw == 0x00000000 && lsw == 0x00000000 ) || ( msw == 0x80000000 && lsw == 0x00000000 ) )
		{
			return FP_ZERO;
		}
		else if( ( msw >= 0x00100000 && msw <= 0x7fefffff ) || ( msw >= 0x80100000 && msw <= 0xffefffff ) )
		{
			return FP_NORMAL;
		}
		else if( ( msw >= 0x00000000 && msw <= 0x000fffff ) || ( msw >= 0x80000000 && msw <= 0x800fffff ) )
		{
			// zero is already handled above
			return FP_SUBNORMAL;
		}
		else if( ( msw == 0x7ff00000 && lsw == 0x00000000 ) || ( msw == 0xfff00000 && lsw == 0x00000000 ) )
		{
			return FP_INFINITE;
		}
		else
		{
			return FP_NAN;
		}
	}

};//namespace nsBaseCRT
