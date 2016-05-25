//Baseresource.h

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

//Base CRT class for sys/resource

#ifndef SYSTEMQOR_BASE_SYS_RESOURCE_H_3
#define SYSTEMQOR_BASE_SYS_RESOURCE_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMSYSTYPES( resource )
#include "CodeQOR/ClassReg/ClassRegEntry.h"

//--------------------------------------------------------------------------------
namespace nsBaseCRT
{
	using nsPlatform::id_t;
	using nsPlatform::rlimit;
	using nsPlatform::rusage;

    //--------------------------------------------------------------------------------
    class __QOR_INTERFACE( __QSYS ) Cresource
    {
    public:

		__QOR_DECLARE_OCLASS_ID( Cresource );

		virtual int getpriority( int, id_t );
		virtual int getrlimit( int, rlimit* );
		virtual int getrusage( int, rusage* );
		virtual int setpriority( int, id_t, int );
		virtual int setrlimit( int, const rlimit* );

	protected:

		Cresource();
		virtual ~Cresource();

	private:

		Cresource( const Cresource& );
		Cresource& operator = ( const Cresource& );
    };

}//nsBaseCRT

#endif//SYSTEMQOR_BASE_SYS_RESOURCE_H_3
