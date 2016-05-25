//Basegrp.cpp

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

#include "SystemQOR/Posix/Basegrp.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	//--------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID( Cgrp );

	//--------------------------------------------------------------------------------
	Cgrp::Cgrp()
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::Cgrp" );
	}

	//--------------------------------------------------------------------------------
	Cgrp::~Cgrp()
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::~Cgrp" );
	}
	
	//--------------------------------------------------------------------------------
	void Cgrp::endgrent( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::endgrent" );
		errno = ENOSYS;
	}

	//--------------------------------------------------------------------------------
	group* Cgrp::getgrent( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::getgrent" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	group* Cgrp::getgrgid( gid_t )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::getgrgid" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cgrp::getgrgid_r( gid_t, group*, char*, size_t, group** )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::getgrgid_r" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	group* Cgrp::getgrnam( const char* )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::getrnam" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Cgrp::getgrnam_r( const char*, group*, char*, size_t, group** )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::getrnam_r" );
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	void Cgrp::setgrent( void )
	{
		__QCS_MEMBER_FCONTEXT( "Cgrp::setgrent" );
		errno = ENOSYS;
	}
	
}//namespace nsBaseCRT
