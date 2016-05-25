//fnmatch.h

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

#ifndef	QOR_FNMATCH_H_3
#define QOR_FNMATCH_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(fnmatch)

#define FNM_NOMATCH			( nsPlatform::FNMNoMatch )			//The string does not match the specified pattern. 
#define FNM_PATHNAME		( nsPlatform::FNMPathName )			//<slash> in string only matches <slash> in pattern. 
#define FNM_PERIOD			( nsPlatform::FNMPeriod )			//Leading <period> in string must be exactly matched by <period> in pattern. 
#define FNM_NOESCAPE		( nsPlatform::FNMNoEscape )			//Disable backslash escaping. 

__QCMP_STARTLINKAGE_C

    __QOR_INTERFACE( __CQOR ) int fnmatch( const char* pattern, const char* str, int flags );

__QCMP_ENDLINKAGE_C

#endif//QOR_FNMATCH_H_3
