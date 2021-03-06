//IO.h

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

//Input/Output constant and structure definitions for use with the Microsoft Windows Operating System

#ifndef WINQL_IO_H_1
#define WINQL_IO_H_1

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/Definitions/Data.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{

	//--------------------------------------------------------------------------------
	typedef void ( __QCMP_STDCALLCONVENTION *LPOVERLAPPED_COMPLETION_ROUTINE )(  unsigned long dwErrorCode, unsigned long dwNumberOfBytesTransfered, nsWin32::LPOVERLAPPED lpOverlapped );

	__QCMP_STATIC_CONSTANT( unsigned long, File_Share_Read					 = 0x00000001  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Share_Write					 = 0x00000002  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Share_Delete				 = 0x00000004  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_ReadOnly            = 0x00000001  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Hidden              = 0x00000002  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_System              = 0x00000004  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Directory           = 0x00000010  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Archive             = 0x00000020  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Device              = 0x00000040  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Normal              = 0x00000080  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Temporary           = 0x00000100  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Sparse_File         = 0x00000200  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Reparse_Point       = 0x00000400  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Compressed          = 0x00000800  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Offline             = 0x00001000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Not_Content_Indexed = 0x00002000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Encrypted           = 0x00004000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Attribute_Virtual             = 0x00010000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_File_Name		 = 0x00000001  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Dir_Name		 = 0x00000002  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Attributes		 = 0x00000004  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Size			 = 0x00000008  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Last_Write		 = 0x00000010  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Last_Access	 = 0x00000020  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Creation		 = 0x00000040  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Notify_Change_Security		 = 0x00000100  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Action_Added                  = 0x00000001  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Action_Removed                = 0x00000002  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Action_Modified               = 0x00000003  );
	__QCMP_STATIC_CONSTANT( unsigned long, FILE_Action_Renamed_Old_Name       = 0x00000004  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Action_Renamed_New_Name       = 0x00000005  );
	__QCMP_STATIC_CONSTANT( unsigned long, Mailslot_No_Message				 = ((unsigned long)-1) );
	__QCMP_STATIC_CONSTANT( unsigned long, Mailslot_Wait_Forever				 = ((unsigned long)-1) );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Case_Sensitive_Search         = 0x00000001  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Case_Preserved_Names          = 0x00000002  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Unicode_On_Disk               = 0x00000004  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Persistent_ACLs               = 0x00000008  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_File_Compression              = 0x00000010  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Volume_Quotas                 = 0x00000020  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Sparse_Files         = 0x00000040  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Reparse_Points       = 0x00000080  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Remote_Storage       = 0x00000100  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Volume_Is_Compressed          = 0x00008000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Object_IDs           = 0x00010000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Encryption           = 0x00020000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Named_Streams                 = 0x00040000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Read_Only_Volume              = 0x00080000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Sequential_Write_Once         = 0x00100000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Transactions         = 0x00200000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Hard_Links           = 0x00400000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Extended_Attributes  = 0x00800000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_Open_By_File_ID      = 0x01000000  );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Supports_USN_Journal          = 0x02000000  );

	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Write_Through            = 0x80000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Overlapped               = 0x40000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_No_Buffering             = 0x20000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Random_Access            = 0x10000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Sequential_Scan          = 0x08000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Delete_On_Close          = 0x04000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Backup_Semantics         = 0x02000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_POSIX_Semantics          = 0x01000000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Open_Reparse_Point       = 0x00200000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_Open_No_Recall           = 0x00100000 );
	__QCMP_STATIC_CONSTANT( unsigned long, File_Flag_First_Pipe_Instance      = 0x00080000 );

	__QCMP_STATIC_CONSTANT( int, Create_New = 1 );
	__QCMP_STATIC_CONSTANT( int, Create_Always = 2 );
	__QCMP_STATIC_CONSTANT( int, Open_Existing = 3 );
	__QCMP_STATIC_CONSTANT( int, Open_Always = 4 );
	__QCMP_STATIC_CONSTANT( int, Truncate_Existing = 5 );

	__QCMP_STATIC_CONSTANT( unsigned short, File_Type_Unknown = 0x0000 );
	__QCMP_STATIC_CONSTANT( unsigned short, File_Type_Disk = 0x0001 );
	__QCMP_STATIC_CONSTANT( unsigned short, File_Type_Char = 0x0002 );
	__QCMP_STATIC_CONSTANT( unsigned short, File_Type_Pipe = 0x0003 );
	__QCMP_STATIC_CONSTANT( unsigned short, File_Type_Remote = 0x8000 );

#ifdef _MAC

	//--------------------------------------------------------------------------------
    struct __QOR_INTERFACE( __WINQL ) STATSTG
    {                      
        wchar_t* pwcsName;
        FSSpec *pspec;
        unsigned long type;
        ULARGE_INTEGER cbSize;
        FILETIME mtime;
        FILETIME ctime;
        FILETIME atime;
        unsigned long grfMode;
        unsigned long grfLocksSupported;
        GUID clsid;
        unsigned long grfStateBits;
        unsigned long reserved;
    };

#else //_MAC

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) STATSTG
    {
		wchar_t* pwcsName;
		unsigned long type;
		ULARGE_INTEGER cbSize;
		FILETIME mtime;
		FILETIME ctime;
		FILETIME atime;
		unsigned long grfMode;
		unsigned long grfLocksSupported;
		GUID clsid;
		unsigned long grfStateBits;
		unsigned long reserved;
    };
#endif //_MAC

	//--------------------------------------------------------------------------------
	struct __QOR_INTERFACE( __WINQL ) CAFileTime
	{
		unsigned long cElems;
		FILETIME* pElems;
	};

}//nsWin32

#endif//WINQL_IO_H_1
