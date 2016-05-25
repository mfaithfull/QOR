//stdarg.h

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

//NOTE: This file is included by <windows.h> when used under Windows. Beware circular dependencies

#ifndef	QOR_STDARG_H_3
#define QOR_STDARG_H_3

#ifndef _QSYS_STDARG_DEFINES
#   include "SystemQOR.h"
#endif

#include QOR_SYS_PLATFORMTYPES(stdarg)

typedef nsPlatform::va_list va_list;
/*
The <stdarg.h> header shall contain a set of macros which allows portable functions that accept variable argument lists to be written. Functions that have variable argument lists (such as printf()) but do not use these macros are inherently non-portable, as different systems use different argument-passing conventions.
The type va_list shall be defined for variables used to traverse the list.
The va_start() macro is invoked to initialize ap to the beginning of the list before any calls to va_arg().
The va_copy() macro initializes dest as a copy of src, as if the va_start() macro had been applied to dest followed by the same sequence of uses of the va_arg() macro as had previously been used to reach the present state of src. Neither the va_copy() nor va_start() macro shall be invoked to reinitialize dest without an intervening invocation of the va_end() macro for the same dest.
The object ap may be passed as an argument to another function; if that function invokes the va_arg() macro with parameter ap, the value of ap in the calling function is unspecified and shall be passed to the va_end() macro prior to any further reference to ap. The parameter argN is the identifier of the rightmost parameter in the variable parameter list in the function definition (the one just before the ...). If the parameter argN is declared with the register storage class, with a function type or array type, or with a type that is not compatible with the type that results after application of the default argument promotions, the behavior is undefined.
The va_arg() macro shall return the next argument in the list pointed to by ap. Each invocation of va_arg() modifies ap so that the values of successive arguments are returned in turn. The type parameter shall be a type name specified such that the type of a pointer to an object that has the specified type can be obtained simply by postfixing a '*' to type. If there is no actual next argument, or if type is not compatible with the type of the actual next argument (as promoted according to the default argument promotions), the behavior is undefined, except for the following cases:
One type is a signed integer type, the other type is the corresponding unsigned integer type, and the value is representable in both types.
One type is a pointer to void and the other is a pointer to a character type.
[XSI]  Both types are pointers. 
Different types can be mixed, but it is up to the routine to know what type of argument is expected.
The va_end() macro is used to clean up; it invalidates ap for use (unless va_start() or va_copy() is invoked again).
Each invocation of the va_start() and va_copy() macros shall be matched by a corresponding invocation of the va_end() macro in the same function.
Multiple traversals, each bracketed by va_start() ... va_end(), are possible.
void va_start(va_list ap, argN);
void va_copy(va_list dest, va_list src);
type va_arg(va_list ap, type);
*/


#endif//QOR_STDARG_H_3

