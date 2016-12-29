//WinQLFindFile.h

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

#ifndef WINQL_FILESYSTEM_FINDFILE_H_3
#define WINQL_FILESYSTEM_FINDFILE_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/WinQL.h"
#include "WinQL/CodeServices/Handles/WinQLRAIISessionHandle.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	typedef struct _WIN32_FIND_DATA 
	{
		unsigned long dwFileAttributes;
		nsWin32::FILETIME ftCreationTime;
		nsWin32::FILETIME ftLastAccessTime;
		nsWin32::FILETIME ftLastWriteTime;
		unsigned long nFileSizeHigh;
		unsigned long nFileSizeLow;
		unsigned long dwReserved0;
		unsigned long dwReserved1;
		TCHAR cFileName[ Max_Path ];
		TCHAR cAlternateFileName[ 14 ];
#ifdef _MAC
		unsigned long dwFileType;
		unsigned long dwCreatorType;
		unsigned short wFinderFlags;
#endif
	} WIN32_FIND_DATA, *PWIN32_FIND_DATA, *LPWIN32_FIND_DATA;

	//--------------------------------------------------------------------------------
	typedef enum _FINDEX_INFO_LEVELS 
	{
		FindExInfoStandard,
		FindExInfoBasic,
		FindExInfoMaxInfoLevel
	} FINDEX_INFO_LEVELS;

	//--------------------------------------------------------------------------------
	typedef enum _FINDEX_SEARCH_OPS 
	{
		FindExSearchNameMatch,
		FindExSearchLimitToDirectories,
		FindExSearchLimitToDevices,
		FindExSearchMaxSearchOp
	} FINDEX_SEARCH_OPS;

	//--------------------------------------------------------------------------------
	typedef enum _STREAM_INFO_LEVELS 
	{

		FindStreamInfoStandard,
		FindStreamInfoMaxInfoLevel
	} STREAM_INFO_LEVELS;

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CFindFile
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CFindFile );

		CFindFile( const TCHAR* lpFileName, nsWin32::LPWIN32_FIND_DATA lpFindFileData );
		CFindFile( const TCHAR* lpFileName, nsWin32::FINDEX_INFO_LEVELS fInfoLevelId, void* lpFindFileData, nsWin32:: FINDEX_SEARCH_OPS fSearchOp, void* lpSearchFilter, unsigned long dwAdditionalFlags );
		CFindFile( const wchar_t* lpFileName, unsigned long dwFlags, unsigned long* StringLength, wchar_t* LinkName, void* hTransaction );
		CFindFile( const wchar_t* lpFileName, unsigned long dwFlags, unsigned long* StringLength, wchar_t* LinkName );
		CFindFile( const TCHAR* lpFileName, nsWin32::FINDEX_INFO_LEVELS fInfoLevelId, void* lpFindFileData, nsWin32::FINDEX_SEARCH_OPS fSearchOp, void* lpSearchFilter, unsigned long dwAdditionalFlags, void* hTransaction );
		CFindFile( const wchar_t* lpFileName, nsWin32::STREAM_INFO_LEVELS InfoLevel, void* lpFindStreamData, unsigned long dwFlags, void* hTransaction );
		CFindFile( const wchar_t* lpFileName, nsWin32::STREAM_INFO_LEVELS InfoLevel, void* lpFindStreamData, unsigned long dwFlags );
		virtual ~CFindFile();
		bool Next( nsWin32::LPWIN32_FIND_DATA lpFindFileData );
		bool Next( unsigned long* StringLength, wchar_t* LinkName );
		bool Next( void* lpFindStreamData );

	protected:

		CRAIISessionHandle m_Handle;
	};

}//nsWin32

#endif//WINQL_FILESYSTEM_FINDFILE_H_3