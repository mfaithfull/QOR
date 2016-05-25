//glob_types.h

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


#ifndef SYSTEMQOR_LIN_TYPES_GLOB_H_3
#define SYSTEMQOR_LIN_TYPES_GLOB_H_3

#include "SystemQOR/Linux/LIN_features.h"

#define __NEED_size_t

#include QOR_SYS_ARCHHEADER(alltypes.h)

//------------------------------------------------------------------------------
namespace nsLinux
{
	//------------------------------------------------------------------------------
	typedef struct 
	{
		size_t gl_pathc;
		char **gl_pathv;
		size_t gl_offs;
		int __dummy1;
		void *__dummy2[5];
	} glob_t;

}//nsLinux

#define GLOB_ERR      0x01
#define GLOB_MARK     0x02
#define GLOB_NOSORT   0x04
#define GLOB_DOOFFS   0x08
#define GLOB_NOCHECK  0x10
#define GLOB_APPEND   0x20
#define GLOB_NOESCAPE 0x40
#define	GLOB_PERIOD   0x80

#define GLOB_NOSPACE 1
#define GLOB_ABORTED 2
#define GLOB_NOMATCH 3
#define GLOB_NOSYS   4

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#	define glob64 glob
#	define globfree64 globfree
#	define glob64_t glob_t
#endif

#endif//SYSTEMQOR_LIN_TYPES_GLOB_H_3
