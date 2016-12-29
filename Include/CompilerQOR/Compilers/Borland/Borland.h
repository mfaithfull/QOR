//Borland.h

// Copyright Querysoft Limited 2015
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

/*
This file provides the following definitions:
__QCMP_STRINGIZER(x)		produces "x" or L"x" under QOR_UNICODE on supporting compilers
__QCMP_PATHIFY(_X,_Y)		Make path by joining path to / to filename
__QCMP_PATHIFY3(_X,_Y,_Z)
__QCMP_PATHIFY4(_X,_Y,_Z,_A)
__QCMP_PATHIFY5(_X,_Y,_Z,_A,_B)
__QCMP_PATHIFY6(_X,_Y,_Z,_A,_B,_C)
__QCMP_ERROR( _X )			Ensure code location is reported for explicit compilation warnings and errors
__QCMP_WARNING( _X )
__QCMP_NAMELESS_STRUCT		Nameless struct/union extension support. Defined e,pty if supported otherwise a workaround to generate a name
__QCMP_TRY	
__QCMP_EXCEPT( _COND )	
__QCMP_EXCEPT_ALL	
__QCMP_FINALLY	
__QCMP_RETHROW	
__QCMP_TEMPLATE_OPERATOR_SPECIFIER	Defined as 'template' if template is needed in template operator member specifications
__QCMP_OPTIMIZEINCLUDE		pragma once support
__QCMP_MESSAGE				macro pragma supported compile tim emessages
TODO(_Message)				__QCMP_MESSAGE based development build TODO: reporting
__QCMP_WARNING_PUSH						//Warning control pragmas
__QCMP_WARNING_DISABLE(_X, _Reason )
__QCMP_WARNING_POP
__QCMP_WARNING_ENABLE(_X)
__QCMP_SUPPORTS__FUNCSIG__	//1 if __FUNCSIG__ available
__QCMP_FUNCSIG__( _X )
__QCMP_LONG_SUFFIX( _X )			//Type suffixes e.g. _X##l
__QCMP_UNSIGNED_SUFFIX( _X )	
__QCMP_UNSIGNEDLONG_SUFFIX( _X )
__QCMP_LONGLONG_SUFFIX( _X )	
__QCMP_FLOAT_SUFFIX( _X )		
__QCMP_i64_SUFFIX( _X )			
__QCMP_ui64_SUFFIX( _X )		
__QCMP_STATIC_CONSTANT		//Assignment at declaration support


//warnings
__QCMP_WARN_MACRO_REDEFINITION					
__QCMP_WARN_COND_EXPR_IS_CONST					
__QCMP_WARN_UNARY_MINUS_APPLIED_TO_UNSIGNED		
__QCMP_WARN_EXTENSION_USED_ZERO_SIZED_ARRAY		
__QCMP_WARN_NAMELESS_STRUCTUNION				
__QCMP_WARN_EXTENSION_EXTERN_TEMPLATE_INSTANCE	
__QCMP_WARN_CONV_FROM_LONG_DOUBLE_TO_DOUBLE		
__QCMP_WARN_CLASS_NEEDS_TO_HAVE_DLL_INTERFACE	
__QCMP_WARN_NON_EXPORTED_BASE_FOR_EXPORT		
__QCMP_WARN_TRUNCATION_FROM_DOUBLE_TO_FLOAT		
__QCMP_WARN_STRUCTURE_PADDED_DUE_TO_ALIGN		
__QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST			
__QCMP_WARN_NO_DEFINITION_FOR_TEMPLATE_INST_REQ	
__QCMP_WARN_UNREF_LOCAL_FUNCTION				
__QCMP_WARN_UNINIT_LOCAL_VAR_USED				
__QCMP_WARN_ASSIGNMENT_WITHIN_COND_EXPR			

//extensions e.g.
#define Unicode_Const_Str_Conversion_QCMPSUPPORTED		1	//Has L## builtin macro

//emulation of missing fundamental types e.g
#if ( !__QCMP_SUPPORTS( __QCMP_FEATURE_NATIVEWCHARTSUPPORT ) )
typedef unsigned short	wchar_t;
#endif

//Linkage modes
#ifdef __cplusplus
#	define __QCMP_LINKAGE_C					extern "C"
#	define __QCMP_STARTLINKAGE_C			extern "C" {
#	define __QCMP_ENDLINKAGE_C				}
#	define __QCMP_LINKAGE_CPP				extern "C++"
#	define __QCMP_STARTLINKAGE_CPP			extern "C++" {
#	define __QCMP_ENDLINKAGE_CPP			}
#else
#	define __QCMP_LINKAGE_C					extern
#	define __QCMP_STARTLINKAGE_C
#	define __QCMP_ENDLINKAGE_C
#endif//__cplusplus

//Calling conventions
#define __QCMP_CALLCON						__cdecl
#define __QCMP_STDCALLCONVENTION			__stdcall
#define __QCMP_THISCALL						//explicit __thiscall not supported? not sure why you'd need it anyway?
#define __QCMP_FASTCALL						__fastcall

//Attributes
#define __QCMP_ALWAYSINLINE					__forceinline
#define __QCMP_DECLARE_PERTHREAD			__declspec(thread)
#define __QCMP_DECLARE_NAKED				__declspec(naked)
#define __QCMP_DECLARE_NOTHROW				__declspec(nothrow)
#define __QCMP_DECLARE_MERGE_INITIALIZERS	__declspec(selectany)
#define __QCMP_DECLARE_NORETURN				__declspec(noreturn)
#define __QCMP_DECLARE_TYPE_GUID(_UID)		__declspec(uuid(_UID))
#define __QCMP_DECLARE_PROPERTY(_GET, _PUT)	__declspec( property( get=_GET, put=_PUT ) )
#define __QCMP_DECLARE_ALIGNED( _ALIGNMENT ) __declspec( align( _ALIGNMENT ) )
#define __QCMP_RESTRICT						//not supported
#define __QCMP_NORETURN						//not supported
#define deprecated( _X )					//not supported
#define __QCMP_DECLARE_DEPRECATED			//not supported
#define __QCMP_ALIGNOF						__alignof
#define __QCMP_ALIGNAS(x)					__declspec(align(__alignof(x)))
#define __QCMP_DATA_SEGMENT(_X)				data_seg(_X) //for pragma data_seg() declarations
#define __QCMP_DEFAULT_DATA_SEGMENT			data_seg()
#define __attribute__(__ATTRIB__)			//not supported
#ifndef DECLSPEC_NORETURN
#	define DECLSPEC_NORETURN				__QCMP_DECLARE_NORETURN//Enable MinGW32 Win32 headers to declare noreturn
#endif//DECLSPEC_NORETURN
#define	__extension__						//not supported
#ifdef __QCMP_ITANIUM
#	define __QCMP_DECLARE_UNALIGNED			__unaligned
#else
#	define __QCMP_DECLARE_UNALIGNED
#endif

#define __QCMP_TEMPLATE_INST

//Module Interface declarations
#define __QCMP_EXPORT						__declspec(dllexport)	//declare an item as exported from the module
#define __QCMP_IMPORT						__declspec(dllimport) //declare an item as imported from another module
#define __QCMP_LOCAL						//declare an item as being local to a module

//exception specifications
#define __QCMP_THROW0()
#define __QCMP_THROW1(x1)
#define __QCMP_THROW throw()
#define __QCMP_NO_THROW throw()
#ifndef __THROW
#	define __THROW
#endif
#ifndef __NTH
#	define __NTH(fct) fct __THROW
#endif

//const qualifiers
#ifndef __const__
#	define __const__ const
#endif

#ifndef __const
#	define __const const
#endif


*/


// versions check:
// we don't support Borland prior to version 5.4:
#if __BORLANDC__ < 0x540
#  error "Compiler not supported or configured - please reconfigure"
#endif

// last known compiler version:
#if (__BORLANDC__ > 0x613)
//#  if defined(BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
//#  else
//#     pragma message( "Unknown compiler version - please run the configure tests and report the results")
//#  endif
#elif (__BORLANDC__ == 0x600)
#  error "CBuilderX preview compiler is no longer supported"
#endif

//
// Support macros to help with standard library detection
#if (__BORLANDC__ < 0x560) || defined(_USE_OLD_RW_STL)
#  define BOOST_BCB_WITH_ROGUE_WAVE
#elif __BORLANDC__ < 0x570
#  define BOOST_BCB_WITH_STLPORT
#else
#  define BOOST_BCB_WITH_DINKUMWARE
#endif

//
// Version 5.0 and below:
#   if __BORLANDC__ <= 0x0550
// Borland C++Builder 4 and 5:
#     define BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#     if __BORLANDC__ == 0x0550
// Borland C++Builder 5, command-line compiler 5.5:
#       define BOOST_NO_OPERATORS_IN_NAMESPACE
#     endif
// Variadic macros do not exist for C++ Builder versions 5 and below
#define BOOST_NO_CXX11_VARIADIC_MACROS
#   endif

// Version 5.51 and below:
#if (__BORLANDC__ <= 0x551)
#  define BOOST_NO_CV_SPECIALIZATIONS
#  define BOOST_NO_CV_VOID_SPECIALIZATIONS
#  define BOOST_NO_DEDUCED_TYPENAME
// workaround for missing WCHAR_MAX/WCHAR_MIN:
#ifdef __cplusplus
#include <climits>
#include <cwchar>
#else
#include <limits.h>
#include <wchar.h>
#endif // __cplusplus
#ifndef WCHAR_MAX
#  define WCHAR_MAX 0xffff
#endif
#ifndef WCHAR_MIN
#  define WCHAR_MIN 0
#endif
#endif

// Borland C++ Builder 6 and below:
#if (__BORLANDC__ <= 0x564)

#  if defined(NDEBUG) && defined(__cplusplus)
// fix broken <cstring> so that Boost.test works:
#     include <cstring>
#     undef strcmp
#  endif
// fix broken errno declaration:
#  include <errno.h>
#  ifndef errno
#     define errno errno
#  endif

#endif

//
// new bug in 5.61:
#if (__BORLANDC__ >= 0x561) && (__BORLANDC__ <= 0x580)
// this seems to be needed by the command line compiler, but not the IDE:
#  define BOOST_NO_MEMBER_FUNCTION_SPECIALIZATIONS
#endif

// Borland C++ Builder 2006 Update 2 and below:
#if (__BORLANDC__ <= 0x582)
#  define BOOST_NO_SFINAE
#  define BOOST_BCB_PARTIAL_SPECIALIZATION_BUG
#  define BOOST_NO_TEMPLATE_TEMPLATES

#  define BOOST_NO_PRIVATE_IN_AGGREGATE

#  ifdef _WIN32
#     define BOOST_NO_SWPRINTF
#  elif defined(linux) || defined(__linux__) || defined(__linux)
// we should really be able to do without this
// but the wcs* functions aren't imported into std::
#     define BOOST_NO_STDC_NAMESPACE
// _CPPUNWIND doesn't get automatically set for some reason:
#     pragma defineonoption BOOST_CPPUNWIND -x
#  endif
#endif

#if (__BORLANDC__ <= 0x613)  // Beman has asked Alisdair for more info
// we shouldn't really need this - but too many things choke
// without it, this needs more investigation:
#  define BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
#  define BOOST_NO_IS_ABSTRACT
#  define BOOST_NO_FUNCTION_TYPE_SPECIALIZATIONS
#  define BOOST_NO_USING_TEMPLATE
#  define BOOST_SP_NO_SP_CONVERTIBLE

// Temporary workaround
#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif

// Borland C++ Builder 2008 and below:
#  define BOOST_NO_INTEGRAL_INT64_T
#  define BOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#  define BOOST_NO_DEPENDENT_NESTED_DERIVATIONS
#  define BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#  define BOOST_NO_TWO_PHASE_NAME_LOOKUP
#  define BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE
#  define BOOST_NO_NESTED_FRIENDSHIP
#  define BOOST_NO_TYPENAME_WITH_CTOR
#if (__BORLANDC__ < 0x600)
#  define BOOST_ILLEGAL_CV_REFERENCES
#endif

//
//  Positive Feature detection
//
// Borland C++ Builder 2008 and below:
#if (__BORLANDC__ >= 0x599)
#  pragma defineonoption BOOST_CODEGEAR_0X_SUPPORT -Ax
#endif
//
// C++0x Macros:
//
#if !defined( BOOST_CODEGEAR_0X_SUPPORT ) || (__BORLANDC__ < 0x610)
#  define BOOST_NO_CXX11_CHAR16_T
#  define BOOST_NO_CXX11_CHAR32_T
#  define BOOST_NO_CXX11_DECLTYPE
#  define BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#  define BOOST_NO_CXX11_EXTERN_TEMPLATE
#  define BOOST_NO_CXX11_RVALUE_REFERENCES
#  define BOOST_NO_CXX11_SCOPED_ENUMS
#  define BOOST_NO_CXX11_STATIC_ASSERT
#else
#  define BOOST_HAS_ALIGNOF
#  define BOOST_HAS_CHAR16_T
#  define BOOST_HAS_CHAR32_T
#  define BOOST_HAS_DECLTYPE
#  define BOOST_HAS_EXPLICIT_CONVERSION_OPS
#  define BOOST_HAS_REF_QUALIFIER
#  define BOOST_HAS_RVALUE_REFS
#  define BOOST_HAS_STATIC_ASSERT
#endif

#define BOOST_NO_CXX11_AUTO_DECLARATIONS
#define BOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define BOOST_NO_CXX11_CONSTEXPR
#define BOOST_NO_CXX11_DECLTYPE_N3276
#define BOOST_NO_CXX11_DEFAULTED_FUNCTIONS
#define BOOST_NO_CXX11_DELETED_FUNCTIONS
#define BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define BOOST_NO_CXX11_HDR_INITIALIZER_LIST
#define BOOST_NO_CXX11_LAMBDAS
#define BOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#define BOOST_NO_CXX11_NULLPTR
#define BOOST_NO_CXX11_RANGE_BASED_FOR
#define BOOST_NO_CXX11_RAW_LITERALS
#define BOOST_NO_CXX11_RVALUE_REFERENCES
#define BOOST_NO_CXX11_SCOPED_ENUMS
#define BOOST_NO_SFINAE_EXPR
#define BOOST_NO_CXX11_TEMPLATE_ALIASES
#define BOOST_NO_CXX11_UNICODE_LITERALS    // UTF-8 still not supported
#define BOOST_NO_CXX11_VARIADIC_TEMPLATES
#define BOOST_NO_CXX11_NOEXCEPT
#define BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
#define BOOST_NO_CXX11_USER_DEFINED_LITERALS
#define BOOST_NO_CXX11_ALIGNAS
#define BOOST_NO_CXX11_TRAILING_RESULT_TYPES
#define BOOST_NO_CXX11_INLINE_NAMESPACES
#define BOOST_NO_CXX11_REF_QUALIFIERS
#define BOOST_NO_CXX11_FINAL

// C++ 14:
#if !defined(__cpp_aggregate_nsdmi) || (__cpp_aggregate_nsdmi < 201304)
#  define BOOST_NO_CXX14_AGGREGATE_NSDMI
#endif
#if !defined(__cpp_binary_literals) || (__cpp_binary_literals < 201304)
#  define BOOST_NO_CXX14_BINARY_LITERALS
#endif
#if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
#  define BOOST_NO_CXX14_CONSTEXPR
#endif
#if !defined(__cpp_decltype_auto) || (__cpp_decltype_auto < 201304)
#  define BOOST_NO_CXX14_DECLTYPE_AUTO
#endif
#if (__cplusplus < 201304) // There's no SD6 check for this....
#  define BOOST_NO_CXX14_DIGIT_SEPARATORS
#endif
#if !defined(__cpp_generic_lambdas) || (__cpp_generic_lambdas < 201304)
#  define BOOST_NO_CXX14_GENERIC_LAMBDAS
#endif
#if !defined(__cpp_init_captures) || (__cpp_init_captures < 201304)
#  define BOOST_NO_CXX14_INITIALIZED_LAMBDA_CAPTURES
#endif
#if !defined(__cpp_return_type_deduction) || (__cpp_return_type_deduction < 201304)
#  define BOOST_NO_CXX14_RETURN_TYPE_DEDUCTION
#endif
#if !defined(__cpp_variable_templates) || (__cpp_variable_templates < 201304)
#  define BOOST_NO_CXX14_VARIABLE_TEMPLATES
#endif

#if __BORLANDC__ >= 0x590
#  define BOOST_HAS_TR1_HASH

#  define BOOST_HAS_MACRO_USE_FACET
#endif

//
// Post 0x561 we have long long and stdint.h:
#if __BORLANDC__ >= 0x561
#  ifndef __NO_LONG_LONG
#     define BOOST_HAS_LONG_LONG
#  else
#     define BOOST_NO_LONG_LONG
#  endif
// On non-Win32 platforms let the platform config figure this out:
#  ifdef _WIN32
#      define BOOST_HAS_STDINT_H
#  endif
#endif

// Borland C++Builder 6 defaults to using STLPort.  If _USE_OLD_RW_STL is
// defined, then we have 0x560 or greater with the Rogue Wave implementation
// which presumably has the std::DBL_MAX bug.
#if defined( BOOST_BCB_WITH_ROGUE_WAVE )
// <climits> is partly broken, some macros define symbols that are really in
// namespace std, so you end up having to use illegal constructs like
// std::DBL_MAX, as a fix we'll just include float.h and have done with:
#include <float.h>
#endif
//
// __int64:
//
#if (__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__)
#  define BOOST_HAS_MS_INT64
#endif
//
// check for exception handling support:
//
#if !defined(_CPPUNWIND) && !defined(BOOST_CPPUNWIND) && !defined(__EXCEPTIONS) && !defined(BOOST_NO_EXCEPTIONS)
#  define BOOST_NO_EXCEPTIONS
#endif
//
// all versions have a <dirent.h>:
//
#ifndef __STRICT_ANSI__
#  define BOOST_HAS_DIRENT_H
#endif
//
// all versions support __declspec:
//
#if defined(__STRICT_ANSI__)
// config/platform/win32.hpp will define BOOST_SYMBOL_EXPORT, etc., unless already defined
#  define BOOST_SYMBOL_EXPORT
#endif
//
// ABI fixing headers:
//
#if __BORLANDC__ != 0x600 // not implemented for version 6 compiler yet
#ifndef BOOST_ABI_PREFIX
#  define BOOST_ABI_PREFIX "config/abi/borland_prefix.h"
#endif
#ifndef BOOST_ABI_SUFFIX
#  define BOOST_ABI_SUFFIX "config/abi/borland_suffix.h"
#endif
#endif
//
// Disable Win32 support in ANSI mode:
//
#if __BORLANDC__ < 0x600
#  pragma defineonoption BOOST_DISABLE_WIN32 -A
#elif defined(__STRICT_ANSI__)
#  define BOOST_DISABLE_WIN32
#endif
//
// MSVC compatibility mode does some nasty things:
// TODO: look up if this doesn't apply to the whole 12xx range
//
#if defined(_MSC_VER) && (_MSC_VER <= 1200)
#  define BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP
#  define BOOST_NO_VOID_RETURNS
#endif

// Borland did not implement value-initialization completely, as I reported
// in 2007, Borland Report 51854, "Value-initialization: POD struct should be
// zero-initialized", http://qc.embarcadero.com/wc/qcmain.aspx?d=51854
// See also: http://www.boost.org/libs/utility/value_init.htm#compiler_issues
// (Niels Dekker, LKEB, April 2010)
#define BOOST_NO_COMPLETE_VALUE_INITIALIZATION

//#define BOOST_COMPILER "Borland C++ version " BOOST_STRINGIZE(__BORLANDC__)