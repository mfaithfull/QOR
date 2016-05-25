//Basectype.cpp

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

#include "SystemQOR/Posix/Basectype.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID(Cctype);

	//--------------------------------------------------------------------------------
    Cctype::Cctype()
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::Cctype" );
	}

	//--------------------------------------------------------------------------------
    Cctype::~Cctype()
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::~Cctype" );
	}

	//--------------------------------------------------------------------------------
    int Cctype::isalnum(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isalnum" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isalnum_l( int, locale_t )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isalnum_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isalpha(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isalpha" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isalpha_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isalpha_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isblank(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isblank" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isblank_l(int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isblank_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::iscntrl(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::iscntrl" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::iscntrl_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::iscntrl_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isdigit(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isdigit" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isdigit_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isdigit_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isgraph(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isgraph" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isgraph_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isgraph_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::islower(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::islower" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::islower_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::islower_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isprint(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isprint" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isprint_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isprint_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::ispunct(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::ispunct" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::ispunct_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::ispunct_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isspace(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isspace" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isspace_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isspace_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isupper(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isupper" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isupper_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isupper_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isxdigit(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isxdigit" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isxdigit_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isxdigit_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::tolower(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::tolower" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::tolower_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::tolower_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::toupper(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::toupper" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::toupper_l( int c, locale_t l )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::toupper_l" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::isascii(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isascii" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
    int Cctype::toascii(int c)
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::toascii" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::isatty( int fd )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::isatty" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cctype::_ismbbalnum( unsigned int c )
	{
		__QCS_MEMBER_FCONTEXT( "Cctype::_ismbbalnum" );
		errno = ENOSYS;
		return 0;
	}
	
}//nsBaseCRT
