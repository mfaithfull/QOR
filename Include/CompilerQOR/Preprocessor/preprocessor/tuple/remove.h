//remove.h

# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2013.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */

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

# ifndef QOR_PREPROCESSOR_TUPLE_REMOVE_H
# define QOR_PREPROCESSOR_TUPLE_REMOVE_H
#
# include "CompilerQOR/Preprocessor/preprocessor/config/config.h"
#
# if QOR_PP_VARIADICS
#
# include "CompilerQOR/Preprocessor/preprocessor/array/remove.h"
# include "CompilerQOR/Preprocessor/preprocessor/array/to_tuple.h"
# include "CompilerQOR/Preprocessor/preprocessor/comparison/greater.h"
# include "CompilerQOR/Preprocessor/preprocessor/control/iif.h"
# include "CompilerQOR/Preprocessor/preprocessor/tuple/size.h"
# include "CompilerQOR/Preprocessor/preprocessor/tuple/to_array.h"
#
# /* QOR_PP_TUPLE_REMOVE */
#
# define QOR_PP_TUPLE_REMOVE(tuple, i) \
	QOR_PP_IIF \
		( \
		QOR_PP_GREATER(QOR_PP_TUPLE_SIZE(tuple),1), \
		QOR_PP_TUPLE_REMOVE_EXEC, \
		QOR_PP_TUPLE_REMOVE_RETURN \
		) \
	(tuple, i) \
/**/
#
# define QOR_PP_TUPLE_REMOVE_EXEC(tuple, i) \
	QOR_PP_ARRAY_TO_TUPLE(QOR_PP_ARRAY_REMOVE(QOR_PP_TUPLE_TO_ARRAY(tuple), i)) \
/**/
#
# define QOR_PP_TUPLE_REMOVE_RETURN(tuple, i) tuple
#
# /* QOR_PP_TUPLE_REMOVE_D */
#
# define QOR_PP_TUPLE_REMOVE_D(d, tuple, i) \
	QOR_PP_IIF \
		( \
		QOR_PP_GREATER_D(d, QOR_PP_TUPLE_SIZE(tuple), 1), \
		QOR_PP_TUPLE_REMOVE_D_EXEC, \
		QOR_PP_TUPLE_REMOVE_D_RETURN \
		) \
	(d, tuple, i) \
/**/
#
# define QOR_PP_TUPLE_REMOVE_D_EXEC(d, tuple, i) \
	QOR_PP_ARRAY_TO_TUPLE(QOR_PP_ARRAY_REMOVE_D(d, QOR_PP_TUPLE_TO_ARRAY(tuple), i)) \
/**/
#
# define QOR_PP_TUPLE_REMOVE_D_RETURN(d, tuple, i) tuple
#
# endif // QOR_PP_VARIADICS
#
# endif //QOR_PREPROCESSOR_TUPLE_REMOVE_H