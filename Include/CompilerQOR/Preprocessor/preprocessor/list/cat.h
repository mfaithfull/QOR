//cat.h

# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */

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

#ifndef QOR_PREPROCESSOR_LIST_CAT_H_1
#define QOR_PREPROCESSOR_LIST_CAT_H_1

#include "../cat.h"
#include "../config/config.h"
#include "adt.h"
#include "fold_left.h"

//QOR_PP_LIST_CAT

#if ~QOR_PP_CONFIG_FLAGS() & QOR_PP_CONFIG_EDG()
#   define QOR_PP_LIST_CAT( list )		QOR_PP_LIST_FOLD_LEFT( QOR_PP_LIST_CAT_O, QOR_PP_LIST_FIRST( list ), QOR_PP_LIST_REST( list ) )
#else
#   define QOR_PP_LIST_CAT( list )		QOR_PP_LIST_CAT_I( list )
#   define QOR_PP_LIST_CAT_I( list )	QOR_PP_LIST_FOLD_LEFT( QOR_PP_LIST_CAT_O, QOR_PP_LIST_FIRST( list ), QOR_PP_LIST_REST( list ) )
#endif

#define QOR_PP_LIST_CAT_O( d, s, x )	QOR_PP_CAT( s, x )

//QOR_PP_LIST_CAT_D

#if ~QOR_PP_CONFIG_FLAGS() & QOR_PP_CONFIG_EDG()
#   define QOR_PP_LIST_CAT_D( d, list )		QOR_PP_LIST_FOLD_LEFT_ ## d( QOR_PP_LIST_CAT_O, QOR_PP_LIST_FIRST( list ), QOR_PP_LIST_REST( list ) )
#else
#   define QOR_PP_LIST_CAT_D( d, list )		QOR_PP_LIST_CAT_D_I( d, list )
#   define QOR_PP_LIST_CAT_D_I( d, list )	QOR_PP_LIST_FOLD_LEFT_ ## d( QOR_PP_LIST_CAT_O, QOR_PP_LIST_FIRST( list ), QOR_PP_LIST_REST( list ) )
#endif

#endif//QOR_PREPROCESSOR_LIST_CAT_H_1
