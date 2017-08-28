
//  (C) Copyright Edward Diener 2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined( QOR_VMD_ARRAY_TO_TUPLE_H )
#define QOR_VMD_ARRAY_TO_TUPLE_H

#include "CompilerQOR/Preprocessor/preprocessor/vmd/detail/setup.h"

#if QOR_PP_VARIADICS

#include "CompilerQOR/Preprocessor/preprocessor/control/iif.h"
#include "CompilerQOR/Preprocessor/preprocessor/array/to_tuple.h"
#include "CompilerQOR/Preprocessor/preprocessor/vmd/empty.h"
#include "CompilerQOR/Preprocessor/preprocessor/vmd/is_empty_array.h"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def QOR_VMD_ARRAY_TO_TUPLE(array)

    \brief converts an array to a tuple.

    array = array to be converted.

    If the array is an array of 0 elements it is converted to an empty tuple.
    Otherwise the array is converted to a tuple with the same number of elements as the array.
*/

#define QOR_VMD_ARRAY_TO_TUPLE( array )                                                                                \
	QOR_PP_IIF( QOR_VMD_IS_EMPTY_ARRAY( array ), QOR_VMD_EMPTY, QOR_PP_ARRAY_TO_TUPLE )                                \
	( array ) \
/**/

#endif /* QOR_PP_VARIADICS */
#endif /* QOR_VMD_ARRAY_TO_TUPLE_H */
