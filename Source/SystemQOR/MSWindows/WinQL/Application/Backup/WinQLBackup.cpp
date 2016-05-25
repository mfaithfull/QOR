//WinQLBackup.cpp

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

#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/Application/Backup/WinQLBackup.h"
#include "WinQL/System/FileSystem/WinQLFile.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CBackup );

	//--------------------------------------------------------------------------------
	CBackup::CBackup( CFile& File ) : m_File( File )
	,	m_iReadWrite( 0 )
	,	m_pContext( 0 )
	{
		_WINQ_FCONTEXT( "CBackup::CBackup" );
	}

	//--------------------------------------------------------------------------------
	CBackup::~CBackup()
	{
		_WINQ_FCONTEXT( "CBackup::~CBackup" );

		if( m_iReadWrite == 1 )
		{
			CKernel32::BackupRead( m_File.Handle()->Use(), 0, 0, 0, TRUE, FALSE, &m_pContext );
		}
		else if( m_iReadWrite == 2 )
		{
			CKernel32::BackupWrite( m_File.Handle()->Use(), 0, 0, 0, TRUE, FALSE, &m_pContext );
		}
	}

	//--------------------------------------------------------------------------------
	bool CBackup::Read( unsigned char* lpBuffer, unsigned long nNumberOfBytesToRead, unsigned long* lpNumberOfBytesRead, bool bProcessSecurity )
	{
		_WINQ_FCONTEXT( "CBackup::Read" );
		bool bResult = false;
		__QOR_PROTECT
		{
			if( m_iReadWrite != 2 )
			{
				m_iReadWrite = 1;
				bResult = CKernel32::BackupRead( m_File.Handle()->Use(), lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, FALSE, bProcessSecurity ? TRUE : FALSE, &m_pContext ) ? true : false;
			}
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CBackup::Seek( unsigned long dwLowBytesToSeek, unsigned long dwHighBytesToSeek, unsigned long* lpdwLowByteSeeked, unsigned long* lpdwHighByteSeeked )
	{
		_WINQ_FCONTEXT( "CBackup::Seek" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::BackupSeek( m_File.Handle()->Use(), dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, &m_pContext ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CBackup::Write( unsigned char* lpBuffer, unsigned long nNumberOfBytesToWrite, unsigned long* lpNumberOfBytesWritten, bool bProcessSecurity )
	{
		_WINQ_FCONTEXT( "CBackup::Write" );
		bool bResult = false;
		__QOR_PROTECT
		{
			if( m_iReadWrite != 1 )
			{
				m_iReadWrite = 2;
				bResult = CKernel32::BackupWrite( m_File.Handle()->Use(), lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, FALSE, bProcessSecurity ? TRUE : FALSE, &m_pContext ) ? true : false;
			}
		}__QOR_ENDPROTECT
		return bResult;
	}

}//nsWin32
