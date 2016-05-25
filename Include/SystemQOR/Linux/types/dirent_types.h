//dirent_types.h

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


#ifndef SYSTEMQOR_LIN_TYPES_DIRENT_H_3
#define SYSTEMQOR_LIN_TYPES_DIRENT_H_3

#include "SystemQOR/Linux/LIN_features.h"

#define __NEED_ino_t
#define __NEED_off_t
#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#	define __NEED_size_t
#endif

#include QOR_SYS_ARCHHEADER(alltypes.h)

//------------------------------------------------------------------------------
namespace nsLinux
{
	typedef struct __dirstream DIR;

	//------------------------------------------------------------------------------
	struct dirent
	{
		ino_t d_ino;
		off_t d_off;
		unsigned short d_reclen;
		unsigned char d_type;
		char d_name[256];
	};

    //compatibiity
    //--------------------------------------------------------------------------------
	struct _diskfree_t
	{
		unsigned total_clusters;
		unsigned avail_clusters;
		unsigned sectors_per_cluster;
		unsigned bytes_per_sector;
	};

}//nsLinux

#define d_fileno d_ino

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#	define DT_UNKNOWN 0
#	define DT_FIFO 1
#	define DT_CHR 2
#	define DT_DIR 4
#	define DT_BLK 6
#	define DT_REG 8
#	define DT_LNK 10
#	define DT_SOCK 12
#	define DT_WHT 14
#	define IFTODT(x) ((x)>>12 & 017)
#	define DTTOIF(x) ((x)<<12)
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#	define dirent64 dirent
#	define readdir64 readdir
#	define readdir64_r readdir_r
#	define scandir64 scandir
#	define alphasort64 alphasort
#	define versionsort64 versionsort
#	define off64_t off_t
#	define ino64_t ino_t
#	define getdents64 getdents
#endif


#endif//SYSTEMQOR_LIN_TYPES_DIRENT_H_3
