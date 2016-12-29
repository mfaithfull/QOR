//netdb_types.h

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


#ifndef SYSTEMQOR_LIN_TYPES_NETDB_H_3
#define SYSTEMQOR_LIN_TYPES_NETDB_H_3

#include "SystemQOR/Linux/LIN_features.h"
#include <netinet/in.h>

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#	define __NEED_size_t
#	include QOR_SYS_ARCHHEADER(alltypes.h)
#endif

//------------------------------------------------------------------------------
namespace nsLinux
{
	//------------------------------------------------------------------------------
	struct addrinfo
	{
		int ai_flags;
		int ai_family;
		int ai_socktype;
		int ai_protocol;
		socklen_t ai_addrlen;
		struct sockaddr *ai_addr;
		char *ai_canonname;
		struct addrinfo *ai_next;
	};

#define IPPORT_RESERVED 1024

#define AI_PASSIVE      0x01
#define AI_CANONNAME    0x02
#define AI_NUMERICHOST  0x04
#define AI_V4MAPPED     0x08
#define AI_ALL          0x10
#define AI_ADDRCONFIG   0x20
#define AI_NUMERICSERV  0x400


#define NI_NUMERICHOST  0x01
#define NI_NUMERICSERV  0x02
#define NI_NOFQDN       0x04
#define NI_NAMEREQD     0x08
#define NI_DGRAM        0x10
#define NI_NUMERICSCOPE 0x100

#define EAI_BADFLAGS   -1
#define EAI_NONAME     -2
#define EAI_AGAIN      -3
#define EAI_FAIL       -4
#define EAI_FAMILY     -6
#define EAI_SOCKTYPE   -7
#define EAI_SERVICE    -8
#define EAI_MEMORY     -10
#define EAI_SYSTEM     -11
#define EAI_OVERFLOW   -12

	// Legacy functions follow (marked OBsolete in SUS)

	//------------------------------------------------------------------------------
	struct netent
	{
		char *n_name;
		char **n_aliases;
		int n_addrtype;
		uint32_t n_net;
	};

	//------------------------------------------------------------------------------
	struct hostent
	{
		char *h_name;
		char **h_aliases;
		int h_addrtype;
		int h_length;
		char **h_addr_list;
	};

#	define h_addr h_addr_list[0]

	//------------------------------------------------------------------------------
	struct servent
	{
		char *s_name;
		char **s_aliases;
		int s_port;
		char *s_proto;
	};


	//------------------------------------------------------------------------------
	struct protoent
	{
		char *p_name;
		char **p_aliases;
		int p_proto;
	};

}//nsLinux

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
#define HOST_NOT_FOUND 1
#define TRY_AGAIN      2
#define NO_RECOVERY    3
#define NO_DATA        4
#define NO_ADDRESS     NO_DATA
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define EAI_NODATA     -5
#define EAI_ADDRFAMILY -9
#define EAI_INPROGRESS -100
#define EAI_CANCELED   -101
#define EAI_NOTCANCELED -102
#define EAI_ALLDONE    -103
#define EAI_INTR       -104
#define EAI_IDN_ENCODE -105
#define NI_MAXHOST 255
#define NI_MAXSERV 32
#endif

#endif//SYSTEMQOR_LIN_TYPES_NETDB_H_3