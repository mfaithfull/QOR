//BuildLibCmdLine.h

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


//Definitions needed to construct a clang-cl 5.0 Lib.exe command line

//Simple switches

//	DEF
#define QOR_PP_BUILD_LIB_DEF_OPTS						( 2, ( QOR_PP_EMPTY(), DEF ) )
#define QOR_PP_BUILD_LIB_DEF_SELECT_DEF					0
#ifndef QOR_PP_BUILD_LIB_DEF_SELECT
#	define QOR_PP_BUILD_LIB_DEF_SELECT					QOR_PP_BUILD_LIB_DEF_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_DEF_OPT						QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_DEF_SELECT, QOR_PP_BUILD_LIB_DEF_OPTS )

//	nodefaultlib
#define QOR_PP_BUILD_LIB_NODEFAULTLIB_OPTS				( 2, ( QOR_PP_EMPTY(), NODEFAULTLIB ) )
#define QOR_PP_BUILD_LIB_NODEFAULTLIB_SELECT_DEF		1
#ifndef QOR_PPBUILD_LIB_NODEFAULTLIB_SELECT
#	define QOR_PP_BUILD_LIB_NODEFAULTLIB_SELECT			QOR_PP_BUILD_LIB_NODEFAULTLIB_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_NODEFAULTLIB_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_NODEFAULTLIB_SELECT, QOR_PP_BUILD_LIB_NODEFAULTLIB_OPTS )

//	nologo
#define QOR_PP_BUILD_LIB_NOLOGO_OPTS					( 2, ( QOR_PP_EMPTY(), NOLOGO ) )
#define QOR_PP_BUILD_LIB_NOLOGO_SELECT_DEF				1
#ifndef QOR_PP_BUILD_LIB_NOLOGO_SELECT
#	define QOR_PP_BUILD_LIB_NOLOGO_SELECT				QOR_PP_BUILD_LIB_NOLOGO_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_NOLOGO_OPT						QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_NOLOGO_SELECT, QOR_PP_BUILD_LIB_NOLOGO_OPTS )

//	verbose
#define QOR_PP_BUILD_LIB_VERBOSE_OPTS					( 2, ( QOR_PP_EMPTY(), VERBOSE ) )
#define QOR_PP_BUILD_LIB_VERBOSE_SELECT_DEF				0
#ifndef QOR_PP_BUILD_LIB_VERBOSE_SELECT
#	define QOR_PP_BUILD_LIB_VERBOSE_SELECT				QOR_PP_BUILD_LIB_VERBOSE_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_VERBOSE_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_VERBOSE_SELECT, QOR_PP_BUILD_LIB_VERBOSE_OPTS )

//	ltcg
#define QOR_PP_BUILD_LIB_LTCG_OPTS						( 2, ( QOR_PP_EMPTY(), LTCG ) )
#define QOR_PP_BUILD_LIB_LTCG_SELECT_DEF				0
#ifndef QOR_PP_BUILD_LIB_LTCG_SELECT
#	define QOR_PP_BUILD_LIB_LTCG_SELECT					QOR_PP_BUILD_LIB_LTCG_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_LTCG_OPT						QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_LTCG_SELECT, QOR_PP_BUILD_LIB_LTCG_OPTS )


//Named switches
//	error report
#define QOR_PP_BUILD_LIB_ERROR_REPORT_OPTS				( 4, ( none , prompt , queue , send ) )
#define QOR_PP_BUILD_LIB_ERROR_REPORT_SELECT_DEF		1
#ifndef QOR_PP_BUILD_LIB_ERROR_REPORT_SELECT
#	define QOR_PP_BUILD_LIB_ERROR_REPORT_SELECT			QOR_PP_BUILD_LIB_ERROR_REPORT_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_ERROR_REPORT_OPT				QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_ERROR_REPORT_SELECT, QOR_PP_BUILD_LIB_ERROR_REPORT_OPTS )

//	machine
#define QOR_PP_BUILD_LIB_MACHINE_OPTS					( 11, ( X86, X64, THUMB, SH4, MIPS, MIPS16, MIPSFPU, MIPSFPU16, IA64, EBC, ARM ) )
#define QOR_PP_BUILD_LIB_MACHINE_SELECT_DEF				0
#ifndef QOR_PP_BUILD_LIB_MACHINE_SELECT
#	define QOR_PP_BUILD_LIB_MACHINE_SELECT				QOR_PP_BUILD_LIB_MACHINE_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_MACHINE_OPT					QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_MACHINE_SELECT, QOR_PP_BUILD_LIB_MACHINE_OPTS )

//	wx
#define QOR_PP_BUILD_LIB_WX_OPTS						( 2, ( QOR_PP_EMPTY(), NO ) )
#define QOR_PP_BUILD_LIB_WX_SELECT_DEF					1
#ifndef QOR_PP_BUILD_LIB_WX_SELECT
#	define QOR_PP_BUILD_LIB_WX_SELECT					QOR_PP_BUILD_LIB_WX_SELECT_DEF
#endif
#define QOR_PP_BUILD_LIB_WX_OPT							QOR_PP_ARRAY_ELEM( QOR_PP_BUILD_LIB_WX_SELECT, QOR_PP_BUILD_LIB_WX_OPTS )


#define QOR_PP_BUILD_LIB_SWITCHES_SIMPLE				QOR_PP_BUILD_LINK_MAKE_SIMPLE_OPT( QOR_PP_BUILD_LIB_DEF_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_SIMPLE_OPT( QOR_PP_BUILD_LIB_NODEFAULTLIB_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_SIMPLE_OPT( QOR_PP_BUILD_LIB_NOLOGO_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_SIMPLE_OPT( QOR_PP_BUILD_LIB_VERBOSE_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_SIMPLE_OPT( QOR_PP_BUILD_LIB_LTCG_OPT )

#define QOR_PP_BUILD_LINK_MAKE_LIB_NAME( _LIB_NAME ) \
														QOR_PP_STRINGIZE( QOR_PP_CAT( QOR_PP_CAT( QOR_PP_CONFIG_INT_DIR, _LIB_NAME ), .lib ) )


#define QOR_PP_BUILD_LIB_SWITCHES_NAMED(_LIB_NAME)		QOR_PP_BUILD_LINK_MAKE_NAMED_OPT( ErrorReport, QOR_PP_BUILD_LIB_ERROR_REPORT_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_NAMED_OPT( Machine, QOR_PP_BUILD_LIB_MACHINE_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_NAMED_OPT( WX, QOR_PP_BUILD_LIB_WX_OPT ) \
														QOR_PP_BUILD_LINK_MAKE_NAMED_OPT( OUT, QOR_PP_BUILD_LINK_MAKE_LIB_NAME(_LIB_NAME) )


#define QOR_PP_BUILD_LIB_SWITCHES_ALL( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _LIB_NAME ) \
														QOR_PP_BUILD_LIB_SWITCHES_SIMPLE \
														QOR_PP_BUILD_LIB_SWITCHES_NAMED( _LIB_NAME ) \
														QOR_PP_SEQ_FOR_EACH_I(QOR_PP_BUILD_LINK_MAKE_LIBPATH, _, _LIBPATHS_SEQUENCE) \
														QOR_PP_SEQ_FOR_EACH_I(QOR_PP_BUILD_LINK_MAKE_LIB, _, _LIBS_SEQUENCE)

#define QOR_PP_BUILD_LIB_NODEPENDS_SWITCHES_ALL( _LIB_NAME ) \
														QOR_PP_BUILD_LIB_SWITCHES_SIMPLE \
														QOR_PP_BUILD_LIB_SWITCHES_NAMED( _LIB_NAME )														

#define QOR_PP_BUILD_LIB_OPTIONS( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _LIB_NAME ) \
														QOR_PP_BUILD_LIB_SWITCHES_ALL( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _LIB_NAME )


#define QOR_PP_BUILD_LIB_NODEPENDS_OPTIONS( _LIB_NAME ) \
														QOR_PP_BUILD_LIB_NODEPENDS_SWITCHES_ALL( _LIB_NAME )

#define QOR_PP_BUILD_LIB_OBJLISTNAME( _LIB_NAME )		QOR_PP_CAT( QOR_PP_CAT( QOR_PP_CONFIG_INT_DIR, _LIB_NAME ), objlist.txt )

#define QOR_PP_BUILD_LIB_COMMAND_LINE( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _OBJS_SEQUENCE, _LIB_NAME ) \
														QOR_PP_BUILD_LIB_EXECUTABLE QOR_PP_BUILD_LIB_OPTIONS( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _LIB_NAME ) \
														QOR_PP_SEQ_FOR_EACH_I( QOR_PP_BUILD_LINK_MAKE_OBJ, .o, _OBJS_SEQUENCE )

#define QOR_PP_BUILD_LIB_COMMAND_LINE2( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _LIB_NAME ) \
														QOR_PP_BUILD_LIB_EXECUTABLE QOR_PP_BUILD_LIB_OPTIONS( _LIBPATHS_SEQUENCE, _LIBS_SEQUENCE, _LIB_NAME ) \
														QOR_PP_CAT(@,QOR_PP_BUILD_LIB_OBJLISTNAME(_LIB_NAME))

#define QOR_PP_BUILD_LIB_COMMAND_LINE3( _LIB_NAME ) \
														QOR_PP_BUILD_LIB_EXECUTABLE QOR_PP_BUILD_LIB_NODEPENDS_OPTIONS( _LIB_NAME ) \
														QOR_PP_CAT(@,QOR_PP_BUILD_LIB_OBJLISTNAME(_LIB_NAME))

//TODO: These are batch dependent and should be redefined in a shell independent way!

#define QOR_PP_BUILD_LIB_EXPORT_OBJNAME( r, _LIB_NAME, _, _X ) \
														echo QOR_PP_CAT( _X,.obj ) >> QOR_PP_BUILD_LIB_OBJLISTNAME( _LIB_NAME )

#define QOR_PP_BUILD_LIB_PREPARE_OBJLIST( _LIB_NAME )	echo ??/n > QOR_PP_BUILD_LIB_OBJLISTNAME( _LIB_NAME )