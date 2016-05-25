//Basepwd.cpp

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

#include "SystemQOR/Posix/Basepwd.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID( Cpwd );

	//--------------------------------------------------------------------------------
	Cpwd::Cpwd()
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::Cpwd" );
	}

	//--------------------------------------------------------------------------------
	Cpwd::~Cpwd()
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::~Cpwd" );
	}

	//--------------------------------------------------------------------------------
	passwd* Cpwd::getpwnam( const char* )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::getpwnam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	passwd* Cpwd::getpwuid( uid_t )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::getpwuid" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpwd::getpwnam_r( const char*, passwd*, char *, size_t, passwd** )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::getpwnam_r" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cpwd::getpwuid_r( uid_t, passwd*, char*, size_t, passwd** )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::getpwuid_r" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cpwd::endpwent( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::endpwent" );
	}

	//--------------------------------------------------------------------------------
	passwd* Cpwd::getpwent( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::getpwent" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cpwd::setpwent( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cpwd::setpwent" );
	}
	
}//nsBaseCRT
