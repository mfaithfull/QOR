//to_array.h

# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */

// Copyright Querysoft Limited 2017
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

#ifndef QOR_PREPROCESSOR_TUPLE_TO_ARRAY_H_1
#define QOR_PREPROCESSOR_TUPLE_TO_ARRAY_H_1

#include "../cat.h"
#include "../config/config.h"
#include "../facilities/overload.h"
#include "../variadic/size.h"

//QOR_PP_TUPLE_TO_ARRAY

# if QOR_PP_VARIADICS
#    if QOR_PP_VARIADICS_MSVC
#        define QOR_PP_TUPLE_TO_ARRAY(...) QOR_PP_TUPLE_TO_ARRAY_I(QOR_PP_OVERLOAD(QOR_PP_TUPLE_TO_ARRAY_, __VA_ARGS__), (__VA_ARGS__))
#        define QOR_PP_TUPLE_TO_ARRAY_I(m, args) QOR_PP_TUPLE_TO_ARRAY_II(m, args)
#        define QOR_PP_TUPLE_TO_ARRAY_II(m, args) QOR_PP_CAT(m ## args,)
#        define QOR_PP_TUPLE_TO_ARRAY_1(tuple) (QOR_PP_TUPLE_SIZE(tuple), tuple)
#    else
#        define QOR_PP_TUPLE_TO_ARRAY(...) QOR_PP_OVERLOAD(QOR_PP_TUPLE_TO_ARRAY_, __VA_ARGS__)(__VA_ARGS__)
#        define QOR_PP_TUPLE_TO_ARRAY_1(tuple) (QOR_PP_VARIADIC_SIZE tuple, tuple)
#    endif
#    define QOR_PP_TUPLE_TO_ARRAY_2(size, tuple) (size, tuple)
# else
#    define QOR_PP_TUPLE_TO_ARRAY(size, tuple) (size, tuple)
# endif

#endif//QOR_PREPROCESSOR_TUPLE_TO_ARRAY_H_1
