//CQOR.pp

// Copyright Querysoft Limited 2016
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

//Preprocessor build script generator for CQOR.dll

#include "ModuleHeader.pph"

//Set CQOR specific definitions and overrides

#define QOR_MODULE_NAME CQOR

//Append the module specific PP defines to the list from the Operating System
#define QOR_CONFIG_DEFINES_CQOR1 QOR_PP_LIST_APPEND( QOR_CONFIG_DEFINES_OS,("__CQOR") )
#define QOR_CONFIG_DEFINES_CQOR2 QOR_PP_LIST_APPEND( QOR_CONFIG_DEFINES_CQOR1,("_LIBCPP_DLL") )
#define QOR_CONFIG_DEFINES_MODULE QOR_PP_LIST_APPEND( QOR_CONFIG_DEFINES_CQOR2,("") )


#define QOR_CONFIG_INCLUDES (../../../include)\
(D:\Tools\Microsoft Visual Studio 14.0\VC\include)\
(D:\Tools\Microsoft Visual Studio 14.0\VC\atlmfc\include)\
(C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt)\
(C:\Program Files (x86)\Windows Kits\8.1\Include\um)\
(C:\Program Files (x86)\Windows Kits\8.1\Include\shared)\
(C:\Program Files (x86)\Windows Kits\8.1\Include\winrt)

#define QOR_PP_BUILD_CMP_IGNORE_STANDARD_INC_SELECT 1
#define QOR_PP_BUILD_CMP_CPP_EXCEPTIONS_SELECT 1
#define QOR_PP_BUILD_CMP_BUFFER_SECURITY_SELECT 1
#define QOR_PP_BUILD_CMP_RUNTIME_CHECKS_SELECT 4

//Include this to do any setup needed for a build such as creating folders
#include "BuildQOR/BeginBuild.pph"

//For each group of files that have the same folder and build options, define a group of sources

#define SOURCE_PATH ../../../Source/CQOR/
#define SOURCES	(aio)\
	(assert)\
	(complex)\
	(CQOR0)\
	(ctype)\
	(dirent)\
	(dlfcn)\
	(errno)\
	(fcntl)\
	(fenv)\
	(float)\
	(fmtmsg)\
	(fnmatch)\
	(ftw)\
	(glob)\
	(grp)\
	(iconv)\
	(inttypes)\
	(langinfo)\
	(libgen)\
	(locale)\
	(math)\
	(monetary)\
	(mqueue)\
	(ndbm)\
	(netdb)\
	(nl_types)\
	(poll)\
	(pthread)\
	(pwd)\
	(regex)\
	(sched)\
	(search)\
	(semaphore)\
	(setjmp)\
	(signal)\
	(spawn)\
	(stddef)\
	(stdio)\
	(stdlib)\
	(string)\
	(strings)\
	(stropts)\
	(syslog)\
	(termios)\
	(time)\
	(trace)\
	(ulimit)\
	(unistd)\
	(utime)\
	(utmpx)\
	(wchar)\
	(wctype)\
	(wordexp)
#include "BuildQOR/BuildGroup.pph"

#define SOURCE_PATH ../../../Source/CQOR/arpa/
#define SOURCES	(inet)
#include "BuildQOR/BuildGroup.pph"

#define SOURCE_PATH ../../../Source/CQOR/sys/
#define SOURCES	(_time)\
				(ipc)\
				(mman)\
				(msg)\
				(resource)\
				(select)\
				(sem)\
				(shm)\
				(socket)\
				(stat)\
				(statvfs)\
				(timeb)\
				(times)\
				(uio)\
				(utsname)\
				(wait)
#include "BuildQOR/BuildGroup.pph"

//Generate the export and import libraries for the module where the linker will require them
#include "LibCmd2.pph"
