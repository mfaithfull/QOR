//stdbool.h

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

#ifndef	QOR_STDBOOL_H_3
#define QOR_STDBOOL_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(stdbool)

///NOTE: Non standard behaviour. We do not conform to SUSV4 in regard to this header. 
///bool, true, and false are not redefiend as macros and __bool_true_false_are_defined is not defined

/*
The <stdbool.h> header shall define the following macros:
bool Expands to _Bool. 
true Expands to the integer constant 1. 
false Expands to the integer constant 0. 
__bool_true_false_are_defined Expands to the integer constant 1. 
An application may undefine and then possibly redefine the macros bool, true, and false.
*/

#endif//QOR_STDBOOL_H_3
