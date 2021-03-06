//LIN_netdb.h

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

//Linux overrides for netdb

#ifndef SYSTEMQOR_LIN_NETDB_H_3
#define SYSTEMQOR_LIN_NETDB_H_3

#include "SystemQOR/Linux/types/netdb_types.h"
//#include "SystemQOR/Posix/Baseregex.h"

//--------------------------------------------------------------------------------
namespace nsLinux
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __QSYS ) Cnetdb //: public nsBaseCRT::Cregex
	{
	public:

		Cnetdb(){}
		~Cnetdb(){}

		virtual int getaddrinfo (const char *__restrict, const char *__restrict, const struct addrinfo *__restrict, struct addrinfo **__restrict);
		virtual void freeaddrinfo (struct addrinfo *);
		virtual int getnameinfo (const struct sockaddr *__restrict, socklen_t, char *__restrict, socklen_t, char *__restrict, socklen_t, int);
		virtual const char *gai_strerror(int);

		virtual void sethostent (int);
		virtual void endhostent (void);
		virtual hostent *gethostent (void);

		virtual void setnetent (int);
		virtual void endnetent (void);
		virtual netent *getnetent (void);
		virtual netent *getnetbyaddr (uint32_t, int);
		virtual netent *getnetbyname (const char *);

		virtual void setservent (int);
		virtual void endservent (void);
		virtual servent *getservent (void);
		virtual servent *getservbyname (const char *, const char *);
		virtual servent *getservbyport (int, const char *);

		virtual void setprotoent (int);
		virtual void endprotoent (void);
		virtual protoent *getprotoent (void);
		virtual protoent *getprotobyname (const char *);
		virtual protoent *getprotobynumber (int);

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
		virtual hostent* gethostbyname( const char* );
		virtual hostent* gethostbyaddr( const void*, socklen_t, int );
#	ifdef __GNUC__
		__attribute__((const))
#	endif
		int* __h_errno_location( void );
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
		virtual void herror(const char *);
		virtual const char *hstrerror(int);
		virtual int gethostbyname_r(const char *, struct hostent *, char *, size_t, struct hostent **, int *);
		virtual int gethostbyname2_r(const char *, int, struct hostent *, char *, size_t, struct hostent **, int *);
		virtual hostent *gethostbyname2(const char *, int);
		virtual int gethostbyaddr_r(const void *, socklen_t, int, struct hostent *, char *, size_t, struct hostent **, int *);
		virtual int getservbyport_r(int, const char *, struct servent *, char *, size_t, struct servent **);
		virtual int getservbyname_r(const char *, const char *, struct servent *, char *, size_t, struct servent **);
#endif

	private:

		Cnetdb( const Cnetdb& );
		Cnetdb& operator = ( const Cnetdb& );

	};

}//nsLinux

#endif//SYSTEMQOR_LIN_NETDB_H_3
