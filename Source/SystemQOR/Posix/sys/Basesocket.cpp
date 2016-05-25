//Basesocket.cpp

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

#include "SystemQOR/Posix/sys/Basesocket.h"
#include <errno.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	__QOR_IMPLEMENT_OCLASS_LUID( Csys_socket );

	//--------------------------------------------------------------------------------
	Csys_socket::Csys_socket()
	{
		__QCS_FCONTEXT("Csys_socket::Csys_socket");
	}

	//--------------------------------------------------------------------------------
	Csys_socket::~Csys_socket()
	{
		__QCS_FCONTEXT("Csys_socket::~Csys_socket");
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::accept( int, sockaddr* __QCMP_RESTRICT, socklen_t* __QCMP_RESTRICT )
	{
		__QCS_FCONTEXT("Csys_socket::accept");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::bind( int, const sockaddr*, socklen_t )
	{
		__QCS_FCONTEXT("Csys_socket::bind");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::connect( int, const sockaddr*, socklen_t )
	{
		__QCS_FCONTEXT("Csys_socket::connect");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::getpeername( int, sockaddr* __QCMP_RESTRICT, socklen_t* __QCMP_RESTRICT )
	{
		__QCS_FCONTEXT("Csys_socket::getpeername");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::getsockname( int, sockaddr* __QCMP_RESTRICT, socklen_t* __QCMP_RESTRICT )
	{
		__QCS_FCONTEXT("Csys_socket::getsockname");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::getsockopt( int, int, int, void* __QCMP_RESTRICT, socklen_t* __QCMP_RESTRICT )
	{
		__QCS_FCONTEXT("Csys_socket::getsockopt");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::listen( int, int )
	{
		__QCS_FCONTEXT("Csys_socket::listen");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Csys_socket::recv( int, void*, size_t, int )
	{
		__QCS_FCONTEXT("Csys_socket::recv");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Csys_socket::recvfrom( int, void* __QCMP_RESTRICT, size_t, int, sockaddr* __QCMP_RESTRICT, socklen_t* __QCMP_RESTRICT )
	{
		__QCS_FCONTEXT("Csys_socket::recvfrom");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Csys_socket::recvmsg( int, msghdr*, int )
	{
		__QCS_FCONTEXT("Csys_socket::recvmsg");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Csys_socket::send( int, const void*, size_t, int )
	{
		__QCS_FCONTEXT("Csys_socket::send");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Csys_socket::sendmsg( int, const msghdr*, int )
	{
		__QCS_FCONTEXT("Csys_socket::sendmsg");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	ssize_t Csys_socket::sendto( int, const void*, ::size_t, int, const sockaddr*, socklen_t)
	{
		__QCS_FCONTEXT("Csys_socket::sendto");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::setsockopt( int, int, int, const void*, socklen_t )
	{
		__QCS_FCONTEXT("Csys_socket::setsockopt");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::shutdown( int, int )
	{
		__QCS_FCONTEXT("Csys_socket::shutdown");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::sockatmark( int )
	{
		__QCS_FCONTEXT("Csys_socket::sockatmark");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::socket( int, int, int )
	{
		__QCS_FCONTEXT("Csys_socket::socket");
		errno = ENOSYS;
		return 0;
	}

	//--------------------------------------------------------------------------------
	int Csys_socket::socketpair( int, int, int, int[ 2 ] )
	{
		__QCS_FCONTEXT("Csys_socket::socketpair");
		errno = ENOSYS;
		return 0;
	}

}//nsBaseCRT
