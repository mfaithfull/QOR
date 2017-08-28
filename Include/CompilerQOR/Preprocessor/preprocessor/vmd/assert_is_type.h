
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if !defined(QOR_VMD_ASSERT_IS_TYPE_H)
#define QOR_VMD_ASSERT_IS_TYPE_H

#include "CompilerQOR/Preprocessor/preprocessor/vmd/detail/setup.h"

#if QOR_PP_VARIADICS

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def QOR_VMD_ASSERT_IS_TYPE(sequence)

    \brief Asserts that the sequence is a VMD type.

    The macro checks that the sequence is a VMD type.
    If it is not a VMD type, it forces a compiler error.
    
    The macro normally checks for a VMD type only in 
    debug mode. However an end-user can force the macro 
    to check or not check by defining the macro 
    QOR_VMD_ASSERT_DATA to 1 or 0 respectively.

    sequence = a possible VMD type.

    returns = Normally the macro returns nothing. 
    
              If the sequence is a VMD type, nothing is 
              output.
              
              For VC++, because there is no sure way of forcing  
              a compiler error from within a macro without producing
              output, if the sequence is not a VMD type the 
              macro forces a compiler error by outputting invalid C++.
              
              For all other compilers a compiler error is forced 
              without producing output if the sequence is not a 
              VMD type.
    
*/

/** \def QOR_VMD_ASSERT_IS_TYPE_D(d,sequence)

    \brief Asserts that the sequence is a VMD type. Re-entrant version.

    The macro checks that the sequence is a VMD type.
    If it is not a VMD type, it forces a compiler error.
    
    The macro normally checks for a VMD type only in 
    debug mode. However an end-user can force the macro 
    to check or not check by defining the macro 
    QOR_VMD_ASSERT_DATA to 1 or 0 respectively.

    d       = The next available QOR_PP_WHILE iteration. 
    sequence = a possible VMD type.

    returns = Normally the macro returns nothing. 
    
              If the sequence is a VMD type, nothing is 
              output.
              
              For VC++, because there is no sure way of forcing  
              a compiler error from within a macro without producing
              output, if the sequence is not a VMD type the 
              macro forces a compiler error by outputting invalid C++.
              
              For all other compilers a compiler error is forced 
              without producing output if the sequence is not a 
              VMD type.
    
*/

#if !QOR_VMD_ASSERT_DATA

#define QOR_VMD_ASSERT_IS_TYPE(sequence)
#define QOR_VMD_ASSERT_IS_TYPE_D(d,sequence)

#else

#include "CompilerQOR/Preprocessor/preprocessor/vmd/assert.h"
#include "CompilerQOR/Preprocessor/preprocessor/vmd/is_type.h"

#define QOR_VMD_ASSERT_IS_TYPE(sequence) \
    QOR_VMD_ASSERT \
          ( \
          QOR_VMD_IS_TYPE(sequence), \
          QOR_VMD_IS_TYPE_ASSERT_ERROR \
          ) \
/**/

#define QOR_VMD_ASSERT_IS_TYPE_D(d,sequence) \
    QOR_VMD_ASSERT \
          ( \
          QOR_VMD_IS_TYPE_D(d,sequence), \
          QOR_VMD_IS_TYPE_ASSERT_ERROR \
          ) \
/**/

#endif // !QOR_VMD_ASSERT_DATA

#endif /* QOR_PP_VARIADICS */
#endif /* QOR_VMD_ASSERT_IS_TYPE_H */
