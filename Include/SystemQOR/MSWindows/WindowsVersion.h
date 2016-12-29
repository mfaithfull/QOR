//WindowsVersion.h

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

//Select the version of Windows to target

#ifndef SYSTEMQOR_WINDOWS_VERSION_H_1
#define SYSTEMQOR_WINDOWS_VERSION_H_1

#define PSAPI_VERSION	1

//Control header for Windows versions
__QCMP_MESSAGE( "Target Operating System: Microsoft Windows " )
#	ifndef _QSYS_WIN_VERSION	
__QCMP_MESSAGE( "No minimum Windows version set. Defaulting to Windows 7." )
#		define _QSYS_WIN_VERSION	_QSYS_MSWVER_WIN7
#		define _QSYS_MSWVER_SERVPACK 0
#	endif//!_QSYS_WIN_VERSION	

//	Windows version selection
#	if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WIN95 )
__QCMP_MESSAGE( "Version: Windows 95 with Internet Explorer 3 is minimum target." )
#		define _WIN32_WINDOWS	0x0400		//Assume only Win95 OS support
#		define WINVER			0x0400		//Assume only Win95 OS support
#		define _WIN32_WINNT		0x0000		//No Windows NT reliance
#		define _WIN32_IE		0x0300		//Assume only I.E. 3
#	else
#		if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WIN98 )
__QCMP_MESSAGE( "Version: Windows 98 with Internet Explorer 3 is minimum target." )
#			define _WIN32_WINDOWS	0x0410
#			define WINVER			0x0410
#			define _WIN32_WINNT		0x0000
#			define _WIN32_IE		0x0300
#		else
#			if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WINME )
__QCMP_MESSAGE( "Version: Windows ME with Internet Explorer 3 is minimum target." )
#				define _WIN32_WINDOWS	0x0500
#				define WINVER			0x0500
#				define _WIN32_WINNT		0x0000
#				define _WIN32_IE		0x0300
#			else
#				if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WINNT4 )
__QCMP_MESSAGE( "Version: Windows NT4 with Internet Explorer 3 is minimum target." )
#					define _WIN32_WINDOWS	0x0000
#					define WINVER			0x0400
#					define _WIN32_WINNT		0x0400
#					define _WIN32_IE		0x0300
#				else
#					if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WIN2K )
__QCMP_MESSAGE( "Version: Windows 2000 with Internet Explorer 4 is minimum target." )
#						define _WIN32_WINDOWS	0x0500
#						define WINVER			0x0500
#						define _WIN32_WINNT		0x0500
#						define _WIN32_IE		0x0400
#						ifndef _QSYS_MSWVER_SERVPACK
#							define NTDDI_VERSION 0x05000000
#						elif	( _QSYS_MSWVER_SERVPACK == 1 )
#							define NTDDI_VERSION 0x05000100
#						elif	( _QSYS_MSWVER_SERVPACK == 2 )
#							define NTDDI_VERSION 0x05000200
#						elif	( _QSYS_MSWVER_SERVPACK == 3 )
#							define NTDDI_VERSION 0x05000300
#						elif	( _QSYS_MSWVER_SERVPACK == 4 )
#							define NTDDI_VERSION 0x05000400
#						endif
#					else
#						if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WINXP )
__QCMP_MESSAGE( "Version: Windows XP with Internet Explorer 6 is minimum target." )
#							define _WIN32_WINDOWS	0x0500
#							define WINVER			0x0501
#							define _WIN32_WINNT		0x0501
#							define _WIN32_IE		0x0600
#							ifndef _QSYS_MSWVER_SERVPACK
#								define NTDDI_VERSION 0x05010000
#							elif	( _QSYS_MSWVER_SERVPACK == 1 )
#								define NTDDI_VERSION 0x05010100
#							elif	( _QSYS_MSWVER_SERVPACK == 2 )
#								define NTDDI_VERSION 0x05010200
#							elif	( _QSYS_MSWVER_SERVPACK == 3 )
#								define NTDDI_VERSION 0x05010300
#							elif	( _QSYS_MSWVER_SERVPACK == 4 )
#								define NTDDI_VERSION 0x05010400
#							endif
#						else
#							if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WIN2K3 )
__QCMP_MESSAGE( "Version: Windows Server 2003 with Internet Explorer 5 is minimum target." )
#								define _WIN32_WINDOWS	0x0500
#								define WINVER			0x0502
#								define _WIN32_WINNT		0x0502
#								define _WIN32_IE		0x0500
#								ifndef _QSYS_MSWVER_SERVPACK
#									define NTDDI_VERSION 0x05020000
#								elif	( _QSYS_MSWVER_SERVPACK == 1 )
#									define NTDDI_VERSION 0x05020100
#								elif	( _QSYS_MSWVER_SERVPACK == 2 )
#									define NTDDI_VERSION 0x05020200
#								elif	( _QSYS_MSWVER_SERVPACK == 3 )
#									define NTDDI_VERSION 0x05020300
#								elif	( _QSYS_MSWVER_SERVPACK == 4 )
#									define NTDDI_VERSION 0x05020400
#								endif
#							else
#								if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WINVISTA )
__QCMP_MESSAGE( "Version: Windows Vista with Internet Explorer 6 is minimum target." )
#									define _WIN32_WINDOWS 0x0500
#									define WINVER		0x0600
#									define _WIN32_WINNT 0x0600
#									define _WIN32_IE	0x0600
#									ifndef _QSYS_MSWVER_SERVPACK
#										define NTDDI_VERSION 0x06000000
#									elif	( _QSYS_MSWVER_SERVPACK == 1 )
#										define NTDDI_VERSION 0x06000100
#									elif	( _QSYS_MSWVER_SERVPACK == 2 )
#										define NTDDI_VERSION 0x06000200
#									elif	( _QSYS_MSWVER_SERVPACK == 3 )
#										define NTDDI_VERSION 0x06000300
#									elif	( _QSYS_MSWVER_SERVPACK == 4 )
#										define NTDDI_VERSION 0x06000400
#									endif
#								else
#									if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WIN2K8 )
__QCMP_MESSAGE( "Version: Windows Server 2008 with Internet Explorer 6 is minimum target." )
#										define _WIN32_WINDOWS 0x0500
#										define WINVER		0x0600
#										define _WIN32_WINNT 0x0600
#										define _WIN32_IE	0x0600
#										ifndef _QSYS_MSWVER_SERVPACK
#											define NTDDI_VERSION 0x06000100
#										elif	( _QSYS_MSWVER_SERVPACK == 1 )
#											define NTDDI_VERSION 0x06000100
#										elif	( _QSYS_MSWVER_SERVPACK == 2 )
#											define NTDDI_VERSION 0x06000200
#										elif	( _QSYS_MSWVER_SERVPACK == 3 )
#											define NTDDI_VERSION 0x06000300
#										elif	( _QSYS_MSWVER_SERVPACK == 4 )
#											define NTDDI_VERSION 0x06000400
#										endif
#									else
#										if	( _QSYS_WIN_VERSION == _QSYS_MSWVER_WIN7 )
__QCMP_MESSAGE( "Version: Windows 7 with Internet Explorer 8 is minimum target." )
#											define _WIN32_WINDOWS 0x0500
#											define WINVER		0x0601
#											define _WIN32_WINNT 0x0601
#											define _WIN32_IE	0x0800
#											define NTDDI_VERSION 0x06010000
#										endif
#									endif
#								endif
#							endif
#						endif
#					endif
#				endif
#			endif
#		endif
#	endif

#endif//SYSTEMQOR_WINDOWS_VERSION_H_1