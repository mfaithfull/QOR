//WinPosumLibraryLoader.cpp

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

//Posum Library Loader for Windows

#include "PosumQOR.h"
#include "SystemQOR.h"
#include "PosumQOR/MSWindows/WinLibraryLoader.h"
#include "PosumQOR/MSWindows/WinPath.h"

//--------------------------------------------------------------------------------
namespace nsWinPosum
{
	__QOR_IMPLEMENT_OCLASS_LUID( CLibraryLoader );

__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: stored in member for use later" );
	//--------------------------------------------------------------------------------
	CLibraryLoader::CLibraryLoader() : nsPosum::CLibraryLoader( this )
	{
	}
__QCMP_WARNING_POP
	//--------------------------------------------------------------------------------
	CLibraryLoader::~CLibraryLoader()
	{
	}
	
	//--------------------------------------------------------------------------------
	int CLibraryLoader::Close( CSharedLibrary* pLibrary )
	{
		nsWinPosum::CSharedLibrary* pWinLibrary = dynamic_cast< nsWinPosum::CSharedLibrary* >( pLibrary );
		if( pWinLibrary )
		{
			return pWinLibrary->Close();
		}
		//TODO: Set error state info
		return -1;
	}

	//--------------------------------------------------------------------------------
	nsPosum::CString CLibraryLoader::Error( void )
	{
		nsPosum::CString strError;
		return strError;
	}

	//--------------------------------------------------------------------------------
	CSharedLibrary* CLibraryLoader::Open( CPath& Path, int iMode )
	{
		nsPosum::CString strPath = Path.ToString();
		nsWinPosum::CSharedLibrary* pNewWinLibrary = new CSharedLibrary( strPath, iMode );
		return pNewWinLibrary;
	}

}//nsWinPosum
