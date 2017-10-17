//BuildAsmCmdLine.h

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


//Definitions needed to construct an MSVC 2017 assembler command line

#define QOR_PP_BUILD_ASM_OPT_SWTICH_PRE					/

#define QOR_PP_BUILD_ASM_MAKE_OPT( _X )					QOR_PP_IF( QOR_PP_IS_EMPTY( QOR_PP_EXPAND( _X ) ), QOR_PP_EMPTY(), QOR_PP_CAT(QOR_PP_BUILD_ASM_OPT_SWTICH_PRE, _X) )


//Stack Size
#ifdef QOR_PP_BUILD_ASM_STACK_SIZE
#	define QOR_PP_BUILD_ASM_STACK_SIZE_OPT				QOR_PP_CAT( F , QOR_PP_BUILD_ASM_STACK_SIZE )
#else
#	define QOR_PP_BUILD_ASM_STACK_SIZE_OPT
#endif

//Executable name
#ifdef QOR_PP_BUILD_ASM_EXECUTABLE_NAME
#	define QOR_PP_BUILD_ASM_EXECUTABLE_NAME_OPT			QOR_PP_CAT( Fe,QOR_PP_BUILD_ASM_EXECUTABLE_NAME ) 
#else
#	define QOR_PP_BUILD_ASM_EXECUTABLE_NAME_OPT
#endif

//Listing file
#ifdef QOR_PP_BUILD_ASM_LISTING_FILE
#	define QOR_PP_BUILD_ASM_LISTING_FILE_OPT			QOR_PP_CAT( Fl,QOR_PP_BUILD_ASM_LISTING_FILE ) 
#else
#	define QOR_PP_BUILD_ASM_LISTING_FILE_OPT
#endif

//Map file
#ifdef QOR_PP_BUILD_ASM_MAP_FILE
#	define QOR_PP_BUILD_ASM_MAP_FILE_OPT			QOR_PP_CAT( Fm,QOR_PP_BUILD_ASM_MAP_FILE ) 
#else
#	define QOR_PP_BUILD_ASM_MAP_FILE_OPT
#endif

//Object file
#ifdef QOR_PP_BUILD_ASM_OBJ_FILE
#	define QOR_PP_BUILD_ASM_OBJ_FILE_OPT			QOR_PP_CAT( Fo,QOR_PP_STRINGIZE(QOR_PP_BUILD_ASM_OBJ_FILE) ) 
#else
#	define QOR_PP_BUILD_ASM_OBJ_FILE_OPT
#endif

//Alternate Linker
#ifdef QOR_PP_BUILD_ASM_ALTERNATE_LINKER
#	define QOR_PP_BUILD_ASM_ALTERNATE_LINKER_OPT			QOR_PP_CAT( Bl, QOR_PP_BUILD_ASM_ALTERNATE_LINKER ) 
#else
#	define QOR_PP_BUILD_ASM_ALTERNATE_LINKER_OPT
#endif

//Browser info
#	define QOR_PP_BUILD_ASM_BROWSER_INFO_OPTS			( 3, ( QOR_PP_EMPTY(), Fr, FR ) )
#define QOR_PP_BUILD_ASM_BROWSER_INFO_SELECT_DEFAULT	0
#ifndef QOR_PP_BUILD_ASM_BROWSER_INFO_SELECT
#	define QOR_PP_BUILD_ASM_BROWSER_INFO_SELECT			QOR_PP_BUILD_ASM_BROWSER_INFO_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_BROWSER_INFO_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_BROWSER_INFO_SELECT, QOR_PP_BUILD_ASM_BROWSER_INFO_OPTS )

//preprocessed source listing to stdout
#	define QOR_PP_BUILD_ASM_PP_STDOUT_OPTS				( 2, ( QOR_PP_EMPTY(), EP ) )
#define QOR_PP_BUILD_ASM_PP_STDOUT_SELECT_DEFAULT		0
#ifndef QOR_PP_BUILD_ASM_PP_STDOUT_SELECT
#	define QOR_PP_BUILD_ASM_PP_STDOUT_SELECT			QOR_PP_BUILD_ASM_PP_STDOUT_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_PP_STDOUT_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_PP_STDOUT_SELECT, QOR_PP_BUILD_ASM_PP_STDOUT_OPTS )

//Object file format
#	define QOR_PP_BUILD_ASM_OBJ_FORMAT_OPTS				( 3, ( QOR_PP_EMPTY(), coff, omf ) )
#define QOR_PP_BUILD_ASM_OBJ_FORMAT_SELECT_DEFAULT		1
#ifndef QOR_PP_BUILD_ASM_OBJ_FORMAT_SELECT
#	define QOR_PP_BUILD_ASM_OBJ_FORMAT_SELECT			QOR_PP_BUILD_ASM_OBJ_FORMAT_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_OBJ_FORMAT_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_OBJ_FORMAT_SELECT, QOR_PP_BUILD_ASM_OBJ_FORMAT_OPTS )

//Calling Convention 
#if( QOR_ARCH == QOR_ARCH_X86_32 )
#	define QOR_PP_BUILD_ASM_CALLING_CONVENTION_OPTS			( 4, ( QOR_PP_EMPTY(), Gc, Gd, GZ ) )
#define QOR_PP_BUILD_ASM_CALLING_CONVENTION_SELECT_DEFAULT	0
#ifndef QOR_PP_BUILD_ASM_CALLING_CONVENTION_SELECT
#	define QOR_PP_BUILD_ASM_CALLING_CONVENTION_SELECT		QOR_PP_BUILD_ASM_CALLING_CONVENTION_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_CALLING_CONVENTION_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_CALLING_CONVENTION_SELECT, QOR_PP_BUILD_ASM_CALLING_CONVENTION_OPTS )
#else
#define QOR_PP_BUILD_ASM_CALL_CONVENTION_OPT
#endif

//	Logo supression
#define QOR_PP_BUILD_ASM_SUPRESS_LOGO_OPTS				( 2, ( QOR_PP_EMPTY(), nologo ) )
#define QOR_PP_BUILD_ASM_SUPRESS_LOGO_SELECT_DEFAULT	1
#ifndef QOR_PP_BUILD_ASM_SUPRESS_LOGO_SELECT
#	define QOR_PP_BUILD_ASM_SUPRESS_LOGO_SELECT			QOR_PP_BUILD_ASM_SUPRESS_LOGO_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_SUPRESS_LOGO_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_SUPRESS_LOGO_SELECT, QOR_PP_BUILD_ASM_SUPRESS_LOGO_OPTS )


//	Preserve case
#define QOR_PP_BUILD_ASM_PRESERVE_CASE_OPTS				( 4, ( QOR_PP_EMPTY(), Cp, Cu, Cx ) )
#define QOR_PP_BUILD_ASM_PRESERVE_CASE_SELECT_DEFAULT	3
#ifndef QOR_PP_BUILD_ASM_PRESERVE_CASE_SELECT
#	define QOR_PP_BUILD_ASM_PRESERVE_CASE_SELECT		QOR_PP_BUILD_ASM_PRESERVE_CASE_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_PRESERVE_CASE_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_PRESERVE_CASE_SELECT, QOR_PP_BUILD_ASM_PRESERVE_CASE_OPTS )

//Syntax only
#define QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_OPTS				( 2, ( QOR_PP_EMPTY(), Zs ) )
#define QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_SELECT_DEFAULT	0
#ifndef QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_SELECT
#	define QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_SELECT		QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_SELECT, QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_OPTS )

//Structure Alignment
#define QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_OPTS			( 4, ( QOR_PP_EMPTY(), 1, 2, 4 ) )
#define QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_SELECT_DEFAULT	0
#ifndef QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_SELECT
#	define QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_SELECT		QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_OPT			QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_SELECT, QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_OPTS )

//MASM 5.10 Compatability
#if( QOR_ARCH == QOR_ARCH_X86_32 )
#	define QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_OPTS				( 2, ( QOR_PP_EMPTY(), Zm ) )
#	define QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_SELECT_DEFAULT	0
#	ifndef QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_SELECT
#		define	QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_SELECT		QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_SELECT_DEFAULT
#	endif
#	define QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_SELECT, QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_OPTS )
#else
#	define QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_OPT
#endif

//CodeView information
#define QOR_PP_BUILD_ASM_CODEVIEW_INFO_OPTS				( 2, ( QOR_PP_EMPTY(), Zi ) )
#define QOR_PP_BUILD_ASM_CODEVIEW_INFO_SELECT_DEFAULT	1
#ifndef QOR_PP_BUILD_ASM_CODEVIEW_INFO_SELECT
#	define QOR_PP_BUILD_ASM_CODEVIEW_INFO_SELECT		QOR_PP_BUILD_ASM_CODEVIEW_INFO_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_CODEVIEW_INFO_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_CODEVIEW_INFO_SELECT, QOR_PP_BUILD_ASM_CODEVIEW_INFO_OPTS )

//Line No debug info
#define QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_OPTS				( 2, ( QOR_PP_EMPTY(), Zd ) )
#define QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_SELECT_DEFAULT		1
#ifndef QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_SELECT
#	define QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_SELECT			QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_SELECT, QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_OPTS )

//All symbols public
#define QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_OPTS				( 2, ( QOR_PP_EMPTY(), Zf ) )
#define QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_SELECT_DEFAULT		1
#ifndef QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_SELECT
#	define	QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_SELECT			QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_SELECT, QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_OPTS )

//Ignore default includes
#define QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_OPTS				( 2, ( QOR_PP_EMPTY(), Zf ) )
#define QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_SELECT_DEFAULT		0
#ifndef QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_SELECT
#	define	QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_SELECT			QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_SELECT, QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_OPTS )

//Safe SEH
#define QOR_PP_BUILD_ASM_SAFE_SEH_OPTS							( 2, ( QOR_PP_EMPTY(), safeseh ) )
#define QOR_PP_BUILD_ASM_SAFE_SEH_SELECT_DEFAULT				0
#ifndef QOR_PP_BUILD_ASM_SAFE_SEH_SELECT
#	define	QOR_PP_BUILD_ASM_SAFE_SEH_SELECT					QOR_PP_BUILD_ASM_SAFE_SEH_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_SAFE_SEH_OPT							QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_SAFE_SEH_SELECT, QOR_PP_BUILD_ASM_SAFE_SEH_OPTS )

//Warning level
#define QOR_PP_BUILD_ASM_WARNING_LEVEL_OPTS						( 4, ( W0, W1, W2, W3 ) )
#define QOR_PP_BUILD_ASM_WARNING_LEVEL_SELECT_DEFAULT			3
#ifndef QOR_PP_BUILD_ASM_WARNING_LEVEL_SELECT
#	define	QOR_PP_BUILD_ASM_WARNING_LEVEL_SELECT				QOR_PP_BUILD_ASM_WARNING_LEVEL_SELECT_DEFAULT
#endif
#define QOR_PP_BUILD_ASM_WARNING_LEVEL_OPT						QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_ASM_WARNING_LEVEL_SELECT, QOR_PP_BUILD_ASM_WARNING_LEVEL_OPTS )


#define QOR_PP_BUILD_ASM_SWITCHES_GENERAL				QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_SUPRESS_LOGO_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_ALTERNATE_LINKER_OPT )\
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_PRESERVE_CASE_OPT) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_OBJ_FORMAT_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_PP_STDOUT_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_STACK_SIZE_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_EXECUTABLE_NAME_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_LISTING_FILE_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_MAP_FILE_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_BROWSER_INFO_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_CALLING_CONVENTION_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_SAFE_SEH_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_WARNING_LEVEL_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_IGNORE_DEF_INCLUDE_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_LINE_NO_DEBUG_INFO_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_ALL_SYMBOLS_PUBLIC_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_CODEVIEW_INFO_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_MASM_5_10_COMPAT_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_STRUCTURE_ALIGNMENT_OPT ) \
														QOR_PP_BUILD_ASM_MAKE_OPT( QOR_PP_BUILD_ASM_SYNTAX_CHECK_ONLY_OPT )/*
														//QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_SHA256_DEBUG_EXPERIMENTAL_OPT )

														/*
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_NON_ASM_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_MAX_SOURCE_LISTING_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_GEN_FIRST_PASS_LISTING_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_SET_LINE_WIDTH_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_SUPRESS_SYMBOL_TABLE_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_SET_PAGE_LENGTH_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_SET_SUBTITLE_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_SET_TITLE_OPT ) \
														QOR_PP_BUILD_CMP_MAKE_OPT( QOR_PP_BUILD_ASM_LIST_FALSE_CONDS_OPT ) \*/

#define QOR_PP_BUILD_ASM_SWITCHES_ALL					QOR_PP_BUILD_ASM_SWITCHES_GENERAL

#define QOR_PP_BUILD_ASM_OPTIONS(_X)					QOR_PP_BUILD_ASM_SWITCHES_ALL\
														QOR_PP_BUILD_ASM_MAKE_OPT( Fo ) QOR_PP_STRINGIZE( QOR_PP_CAT(QOR_PP_CONFIG_OBJ_DIR,QOR_PP_CAT( _X, QOR_OBJECT_EXT )) )

#define QOR_PP_BUILD_ASM_COMMAND_LINE(_PATH,_EXTENSION,_X) \
														QOR_PP_BUILD_ASSEMBLER_EXECUTABLE QOR_PP_BUILD_ASM_MAKE_OPT( c ) QOR_PP_BUILD_ASM_OPTIONS(_X) QOR_PP_CAT(_PATH,QOR_PP_CAT(_X,_EXTENSION))