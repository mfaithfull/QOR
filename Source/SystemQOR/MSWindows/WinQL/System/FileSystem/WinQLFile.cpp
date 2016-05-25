//WinQLFile.cpp

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
#include "WinQL/Application/ErrorSystem/WinQLErrDomain.h"
#include "WinQL/System/FileSystem/WinQLFile.h"
#include "WinQAPI/Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	//--------------------------------------------------------------------------------
	CFile::CFile()
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
	}

	//--------------------------------------------------------------------------------
	CFile::CFile( const char* lpFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, nsWin32::LPSECURITY_ATTRIBUTES lpSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile ) : CDeviceFile()
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
		__QOR_PROTECT
		{
			m_Handle = CKernel32::CreateFileA( lpFileName, dwDesiredAccess, dwShareMode, reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpSecurityAttributes ), dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
			m_Handle.Attach( this );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CFile::CFile( const wchar_t* lpFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, nsWin32::LPSECURITY_ATTRIBUTES lpSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile ) : CDeviceFile()
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
		__QOR_PROTECT
		{
			m_Handle = CKernel32::CreateFileW( lpFileName, dwDesiredAccess, dwShareMode, reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpSecurityAttributes ), dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
			m_Handle.Attach( this );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CFile::CFile( const TCHAR* lpFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, nsWin32::LPSECURITY_ATTRIBUTES lpSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile, void* hTransaction, unsigned short* pusMiniVersion, void* pExtendedParameter ) : CDeviceFile()
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
		__QOR_PROTECT
		{
			m_Handle = CKernel32::Instance().CreateFileTransacted( lpFileName, dwDesiredAccess, dwShareMode, reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpSecurityAttributes ), dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile, hTransaction, pusMiniVersion, pExtendedParameter );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CFile::CFile( const char* lpFileName, nsWin32::LPOFSTRUCT lpReOpenBuff, unsigned int uStyle ) : CDeviceFile()
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
		__QOR_PROTECT
		{
			(dynamic_cast< CFileHandle&>(m_Handle)) = CKernel32::OpenFile( lpFileName, reinterpret_cast< ::LPOFSTRUCT >( lpReOpenBuff ), uStyle );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CFile::CFile( CFileHandle& hFile, nsWin32::FILE_ID_DESCRIPTOR* lpFileID, unsigned long dwDesiredAccess, unsigned long dwShareMode, nsWin32::LPSECURITY_ATTRIBUTES lpSecurityAttributes, unsigned long dwFlags ) : CDeviceFile()
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
		__QOR_PROTECT
		{
#			if ( _WIN32_WINNT >= 0x0600 )
			m_Handle = CKernel32::Instance().OpenFileById( hFile.Use(), reinterpret_cast< ::FILE_ID_DESCRIPTOR* >( lpFileID ), dwDesiredAccess, dwShareMode, reinterpret_cast< ::LPSECURITY_ATTRIBUTES >( lpSecurityAttributes ), dwFlags );
#			else
				QOR_PP_UNREF6( hFile, lpFileID, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags );
				_QSYS_MSW_WWL_CONT_ERROR(( API_REQUIRES_VERSION, _CTXT( "OpenFileById" ), _CTXT( "Windows Vista" ), 0 ));
#			endif

		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CFile::~CFile()
	{
		_WINQ_FCONTEXT( "CFile::~CFile" );
	}

	//--------------------------------------------------------------------------------
	bool CFile::CancelIo()
	{
		_WINQ_FCONTEXT( "CFile::CancelIo" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::CancelIo( m_Handle.Use() ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::CancelIoEx( nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::CancelIoEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::Instance().CancelIoEx( m_Handle.Use(), reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::FlushBuffers()
	{
		_WINQ_FCONTEXT( "CFile::FlushBuffers" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::FlushFileBuffers( m_Handle.Use() ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::GetBandwidthReservation( unsigned long* lpPeriodMilliseconds, unsigned long* lpBytesPerPeriod, int* pDiscardable, unsigned long* lpTransferSize, unsigned long* lpNumOutstandingRequests )
	{
		_WINQ_FCONTEXT( "CFile::GetBandwidthReservation" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::Instance().GetFileBandwidthReservation( m_Handle.Use(), lpPeriodMilliseconds, lpBytesPerPeriod, pDiscardable, lpTransferSize, lpNumOutstandingRequests ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::GetInformation( nsWin32::LPBY_HANDLE_FILE_INFORMATION lpFileInformation )
	{
		_WINQ_FCONTEXT( "CFile::GetInformation" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::GetFileInformationByHandle( m_Handle.Use(), reinterpret_cast< ::LPBY_HANDLE_FILE_INFORMATION >( lpFileInformation ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::GetInformationEx( nsWin32::FILE_INFO_BY_HANDLE_CLASS FileInformationClass, void* lpFileInformation, unsigned long dwBufferSize )
	{
		_WINQ_FCONTEXT( "CFile::GetInformationEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::GetFileInformationByHandleEx( m_Handle.Use(), static_cast< ::FILE_INFO_BY_HANDLE_CLASS >( FileInformationClass ), lpFileInformation, dwBufferSize ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFile::GetSize( unsigned long* lpFileSizeHigh )
	{
		_WINQ_FCONTEXT( "CFile::GetSize" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetFileSize( m_Handle.Use(), lpFileSizeHigh );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::GetSizeEx( nsWin32::LARGE_INTEGER* lpFileSize )
	{
		_WINQ_FCONTEXT( "CFile::GetSizeEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::GetFileSizeEx( m_Handle.Use(), reinterpret_cast< ::PLARGE_INTEGER >( lpFileSize ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFile::GetType()
	{
		_WINQ_FCONTEXT( "CFile::GetType" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetFileType( m_Handle.Use() );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFile::GetFinalPathName( TCHAR* lpszFilePath, unsigned long cchFilePath, unsigned long dwFlags )
	{
		_WINQ_FCONTEXT( "CFile::GetFinalPathName" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::GetFinalPathNameByHandle( m_Handle.Use(), lpszFilePath, cchFilePath, dwFlags );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::Lock( unsigned long dwFileOffsetLow, unsigned long dwFileOffsetHigh, unsigned long nNumberOfBytesToLockLow, unsigned long nNumberOfBytesToLockHigh )
	{
		_WINQ_FCONTEXT( "CFile::Lock" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::LockFile( m_Handle.Use(), dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::LockEx( unsigned long dwFlags, unsigned long dwReserved, unsigned long nNumberOfBytesToLockLow, unsigned long nNumberOfBytesToLockHigh, nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::LockEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::LockFileEx( m_Handle.Use(), dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::Read( void* lpBuffer, unsigned long nNumberOfBytesToRead, unsigned long* lpNumberOfBytesRead, nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::Read" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::ReadFile( m_Handle.Use(), lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::ReadEx( void* lpBuffer, unsigned long nNumberOfBytesToRead, nsWin32::LPOVERLAPPED lpOverlapped, nsWin32::LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine )
	{
		_WINQ_FCONTEXT( "CFile::ReadEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::ReadFileEx( m_Handle.Use(), lpBuffer, nNumberOfBytesToRead, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ), reinterpret_cast< ::LPOVERLAPPED_COMPLETION_ROUTINE >( lpCompletionRoutine ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::ReadScatter( nsWin32::FILE_SEGMENT_ELEMENT aSegmentArray[], unsigned long nNumberOfBytesToRead, unsigned long* lpReserved, nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::ReadScatter" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::ReadFileScatter( m_Handle.Use(), reinterpret_cast< ::FILE_SEGMENT_ELEMENT* >( aSegmentArray ), nNumberOfBytesToRead, lpReserved, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	CFile& CFile::ReOpen( unsigned long dwDesiredAccess, unsigned long dwShareMode, unsigned long dwFlags )
	{
		_WINQ_FCONTEXT( "CFile::ReOpen" );
		__QOR_PROTECT
		{
			m_Handle = CKernel32::ReOpenFile( m_Handle.Use(), dwDesiredAccess, dwShareMode, dwFlags );
		}__QOR_ENDPROTECT
		return *this;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetEOF()
	{
		_WINQ_FCONTEXT( "CFile::SetEOF" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::SetEndOfFile( m_Handle.Use() ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetBandwidthReservation( unsigned long nPeriodMilliseconds, unsigned long nBytesPerPeriod, bool bDiscardable, unsigned long* lpTransferSize, unsigned long* lpNumOutstandingRequests )
	{
		_WINQ_FCONTEXT( "CFile::SetBandwidthReservation" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::Instance().SetFileBandwidthReservation( m_Handle.Use(), nPeriodMilliseconds, nBytesPerPeriod, bDiscardable ? TRUE : FALSE, lpTransferSize, lpNumOutstandingRequests ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetCompletionNotificationModes( unsigned char Flags )
	{
		_WINQ_FCONTEXT( "CFile::SetCompletionNotificationModes" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::Instance().SetFileCompletionNotificationModes( m_Handle.Use(), Flags ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetInformation( nsWin32::FILE_INFO_BY_HANDLE_CLASS FileInformationClass, void* lpFileInformation, unsigned long dwBufferSize )
	{
		_WINQ_FCONTEXT( "CFile::SetInformation" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::Instance().SetFileInformationByHandle( m_Handle.Use(), static_cast< ::FILE_INFO_BY_HANDLE_CLASS >( FileInformationClass ), lpFileInformation, dwBufferSize ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetIoOverlappedRange( unsigned char* OverlappedRangeStart, unsigned long Length )
	{
		_WINQ_FCONTEXT( "CFile::SetIoOverlappedRange" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::Instance().SetFileIoOverlappedRange( m_Handle.Use(), OverlappedRangeStart, Length ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	unsigned long CFile::SetPointer( long lDistanceToMove, long* lpDistanceToMoveHigh, unsigned long dwMoveMethod )
	{
		_WINQ_FCONTEXT( "CFile::SetPointer" );
		DWORD dwResult = 0;
		__QOR_PROTECT
		{
			dwResult = CKernel32::SetFilePointer( m_Handle.Use(), lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod );
		}__QOR_ENDPROTECT
		return dwResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetPointerEx( nsWin32::LARGE_INTEGER liDistanceToMove, nsWin32::LARGE_INTEGER* lpNewFilePointer, unsigned long dwMoveMethod )
	{
		_WINQ_FCONTEXT( "CFile::SetPointerEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::SetFilePointerEx( m_Handle.Use(), *( reinterpret_cast< ::LARGE_INTEGER* >( &liDistanceToMove ) ), reinterpret_cast< ::PLARGE_INTEGER >( lpNewFilePointer ), dwMoveMethod ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetShortName( const TCHAR* lpShortName )
	{
		_WINQ_FCONTEXT( "CFile::SetShortName" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::SetFileShortName( m_Handle.Use(), lpShortName ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::SetValidData( Cmp_long_long ValidDataLength )
	{
		_WINQ_FCONTEXT( "CFile::SetValidData" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::SetFileValidData( m_Handle.Use(), ValidDataLength ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::Unlock( unsigned long dwFileOffsetLow, unsigned long dwFileOffsetHigh, unsigned long nNumberOfBytesToUnlockLow, unsigned long nNumberOfBytesToUnlockHigh )
	{
		_WINQ_FCONTEXT( "CFile::Unlock" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::UnlockFile( m_Handle.Use(), dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::UnlockEx( unsigned long dwReserved, unsigned long nNumberOfBytesToUnlockLow, unsigned long nNumberOfBytesToUnlockHigh, nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::UnlockEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::UnlockFileEx( m_Handle.Use(), dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::Write( const void* lpBuffer, unsigned long nNumberOfBytesToWrite, unsigned long* lpNumberOfBytesWritten, nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::Write" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::WriteFile( m_Handle.Use(), lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::WriteEx( const void* lpBuffer, unsigned long nNumberOfBytesToWrite, nsWin32::LPOVERLAPPED lpOverlapped, nsWin32::LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine )
	{
		_WINQ_FCONTEXT( "CFile::WriteEx" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::WriteFileEx( m_Handle.Use(), lpBuffer, nNumberOfBytesToWrite, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ), reinterpret_cast< ::LPOVERLAPPED_COMPLETION_ROUTINE >( lpCompletionRoutine ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CFile::WriteGather( nsWin32::FILE_SEGMENT_ELEMENT aSegmentArray[], unsigned long nNumberOfBytesToWrite, unsigned long* lpReserved, nsWin32::LPOVERLAPPED lpOverlapped )
	{
		_WINQ_FCONTEXT( "CFile::WriteGather" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = CKernel32::WriteFileGather( m_Handle.Use(), reinterpret_cast< ::FILE_SEGMENT_ELEMENT* >( aSegmentArray ), nNumberOfBytesToWrite, lpReserved, reinterpret_cast< ::LPOVERLAPPED >( lpOverlapped ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	CFile::CFile( CFileHandle& hExisting ) : CDeviceFile( hExisting )
	{
		_WINQ_FCONTEXT( "CFile::CFile" );
	}

	//--------------------------------------------------------------------------------
	bool CFile::IsOpen()
	{
		return ( !Handle()->IsInvalid() && !Handle()->IsNull() );
	}

}//nsWin32
