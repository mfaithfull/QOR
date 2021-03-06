//Utils.cpp

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

#include "CodeQOR.h"
#include "CodeQOR/Utils/Utils.h"
#include <string.h>
#include <assert.h>

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	static const char letters[] = "0123456789ABCDEF";

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __CODEQOR ) char* mycpy(char* dst, const char* src, Cmp_uint_ptr len) __QCMP_THROW
	{
		if( src != 0 )
		{
			if( len == (Cmp_uint_ptr)-1 )
			{
				while( *src )
				{
					*dst++ = *src++;
				}
			}
			else
			{
				memcpy( dst, src, len );
				dst += len;
			}
		}
		return dst;
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __CODEQOR ) char* myutoa( char* dst, Cmp_uint_ptr i, Cmp_uint_ptr base) __QCMP_THROW
	{
		assert( base <= 16 );

		char buf[ 128 ];
		char* p = buf + 128;

		do 
		{
			Cmp_int_ptr b = i % base;
			*--p = letters[ b ];
			i /= base;
		} while (i);

		return mycpy(dst, p, (Cmp_uint_ptr)(buf + 128 - p));
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __CODEQOR ) char* myitoa(char* dst, Cmp_int_ptr i, Cmp_uint_ptr base) __QCMP_THROW
	{
		if (i < 0)
		{
			*dst++ = '-';
			i = -i;
		}

		return myutoa(dst, (Cmp_uint_ptr)i, base);
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __CODEQOR ) char* myfill( char* dst, const int c, Cmp_uint_ptr len) __QCMP_THROW
	{
		memset(dst, c, len);
		return dst + len;
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __CODEQOR ) char* myhex(char* dst, const Cmp_unsigned__int8* src, Cmp_uint_ptr len) __QCMP_THROW
	{
		for (Cmp_uint_ptr i = len; i; i--, dst += 2, src += 1)
		{
			dst[0] = letters[(src[0] >> 4) & 0xF];
			dst[1] = letters[(src[0]     ) & 0xF];
		}

		return dst;
	}

}//nsCodeQOR
