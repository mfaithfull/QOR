//adt.h

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

#ifndef QOR_PREPROCESSOR_LIST_ADT_H_1
#define QOR_PREPROCESSOR_LIST_ADT_H_1

#include "../config/config.h"
#include "../detail/is_binary.h"
#include "../logical/compl.h"
#include "../tuple/eat.h"

//QOR_PP_LIST_CONS

#define QOR_PP_LIST_CONS( head, tail )          ( head, tail )

//QOR_PP_LIST_NIL

#define QOR_PP_LIST_NIL							QOR_PP_NIL

//QOR_PP_LIST_FIRST

#define QOR_PP_LIST_FIRST( list )               QOR_PP_LIST_FIRST_D( list )

#if	~QOR_PP_CONFIG_FLAGS() & QOR_PP_CONFIG_MWCC()
#	define QOR_PP_LIST_FIRST_D( list )			QOR_PP_LIST_FIRST_I list
#else//MWCC
#	define QOR_PP_LIST_FIRST_D( list )			QOR_PP_LIST_FIRST_I ## list
#endif

#define QOR_PP_LIST_FIRST_I( head, tail )       head

//QOR_PP_LIST_REST

#define QOR_PP_LIST_REST( list )                QOR_PP_LIST_REST_D( list )

#if	~QOR_PP_CONFIG_FLAGS() & QOR_PP_CONFIG_MWCC()
#	define QOR_PP_LIST_REST_D( list )			QOR_PP_LIST_REST_I list
#else//MWCC
#	define QOR_PP_LIST_REST_D( list )			QOR_PP_LIST_REST_I ## list
#endif

#define QOR_PP_LIST_REST_I( head, tail )        tail

//QOR_PP_LIST_IS_CONS

#if QOR_PP_CONFIG_FLAGS() & QOR_PP_CONFIG_BCC()
#   define QOR_PP_LIST_IS_CONS( list )			QOR_PP_LIST_IS_CONS_D( list )
#   define QOR_PP_LIST_IS_CONS_D( list )		QOR_PP_LIST_IS_CONS_ ## list
#   define QOR_PP_LIST_IS_CONS_( head, tail )	1
#   define QOR_PP_LIST_IS_CONS_QOR_PP_NIL		0
#else
#   define QOR_PP_LIST_IS_CONS( list )			QOR_PP_IS_BINARY( list )
#endif

//QOR_PP_LIST_IS_NIL

#if ~QOR_PP_CONFIG_FLAGS() & QOR_PP_CONFIG_BCC()
#   define QOR_PP_LIST_IS_NIL( list )			QOR_PP_COMPL( QOR_PP_IS_BINARY( list ) )
#else
#   define QOR_PP_LIST_IS_NIL( list )			QOR_PP_COMPL( QOR_PP_LIST_IS_CONS( list ) )
#endif

#endif//QOR_PREPROCESSOR_LIST_ADT_H_1
