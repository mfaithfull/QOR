//WinQLEnhMetaFile.cpp

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
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: saved in member for later use" );
#include "WinQL/Application/Graphics/WinQLEnhMetaFile.h"
__QCMP_WARNING_POP
#include "WinQAPI/GDI32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QCMP_DECLARE_PERTHREAD CEnhMetaFileHandleMap* p_tEnhMetaFileHandleMap = 0;

	__QOR_IMPLEMENT_OCLASS_LUID( CEnhMetaFile );

	//--------------------------------------------------------------------------------
	CEnhMetaFileHandleMap& CEnhMetaFile::HandleMap( void )
	{
		_WINQ_SFCONTEXT( "CEnhMetaFile::HandleMap" );
		if( p_tEnhMetaFileHandleMap == 0 )
		{
			p_tEnhMetaFileHandleMap = new CEnhMetaFileHandleMap;
		}

		return *p_tEnhMetaFileHandleMap;
	}

	//--------------------------------------------------------------------------------
	CEnhMetaFile::CEnhMetaFile( CEnhMetaFile& Src, const TCHAR* lpszFile, int* pbResult ) : CGDIObject< CEnhMetaFile >()
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::CEnhMetaFile" );
		m_pResult = pbResult;
		__QOR_PROTECT
		{
			m_bOwner = true;
			SetHandle( m_GDI32Library.CopyEnhMetaFile( reinterpret_cast< ::HENHMETAFILE >( Src.Handle()->Use() ), lpszFile ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CEnhMetaFile::CEnhMetaFile( const TCHAR* lpszMetaFile, int* pbResult ) : CGDIObject< CEnhMetaFile >()
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::CEnhMetaFile" );
		m_pResult = pbResult;
		__QOR_PROTECT
		{
			m_bOwner = true;
			SetHandle( m_GDI32Library.GetEnhMetaFile( lpszMetaFile ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CEnhMetaFile::CEnhMetaFile( unsigned int cbBuffer, const unsigned char* lpbBuffer, CDCInternal& DCRef, const nsWin32::METAFILEPICT* lpmfp, int* pbResult ) : CGDIObject< CEnhMetaFile >()
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::CEnhMetaFile" );
		m_pResult = pbResult;
		__QOR_PROTECT
		{
			m_bOwner = true;
			SetHandle( m_GDI32Library.SetWinMetaFileBits( cbBuffer, lpbBuffer, reinterpret_cast< ::HDC >( DCRef.Handle()->Use() ), reinterpret_cast< const ::METAFILEPICT* >( lpmfp ) ) );
		}__QOR_ENDPROTECT
	}
		
	//--------------------------------------------------------------------------------
	CEnhMetaFile::CEnhMetaFile( unsigned int cbBuffer, const unsigned char* lpData, int* pbResult ) : CGDIObject< CEnhMetaFile >()
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::CEnhMetaFile" );
		m_pResult = pbResult;
		__QOR_PROTECT
		{
			m_bOwner = true;
			SetHandle( m_GDI32Library.SetEnhMetaFileBits( cbBuffer, lpData ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CEnhMetaFile::~CEnhMetaFile()
	{	
		_WINQ_FCONTEXT( "CEnhMetaFile::~CEnhMetaFile" );
		bool bResult = !m_bOwner;
		__QOR_PROTECT
		{
			if( m_bOwner )
			{
				bResult = m_GDI32Library.DeleteEnhMetaFile( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ) ) ? true : false;
			}
			if( m_pResult != 0 )
			{
				*m_pResult = bResult;
			}
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	bool CEnhMetaFile::Enum( CDCInternal& DC, nsWin32::ENHMFENUMPROC lpEnhMetaFunc, void* lpData, const nsWin32::RECT* lpRect )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::Enum" );
		bool bResult = false;
		__QOR_PROTECT
		{
			bResult = m_GDI32Library.EnumEnhMetaFile( reinterpret_cast< ::HDC >( DC.Handle()->Use() ), reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), reinterpret_cast< ::ENHMFENUMPROC >( lpEnhMetaFunc ), lpData, reinterpret_cast< const ::RECT* >( lpRect ) ) ? true : false;
		}__QOR_ENDPROTECT
		return bResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CEnhMetaFile::GetBits( unsigned int cbBuffer, unsigned char* lpbBuffer )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::GetBits" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_GDI32Library.GetEnhMetaFileBits( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), cbBuffer, lpbBuffer );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CEnhMetaFile::GetDescription( unsigned int cchBuffer, TCHAR* lpszDescription )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::GetDescription" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_GDI32Library.GetEnhMetaFileDescription( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), cchBuffer, lpszDescription );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CEnhMetaFile::GetHeader( unsigned int cbBuffer, nsWin32::LPENHMETAHEADER lpemh )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::GetHeader" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_GDI32Library.GetEnhMetaFileHeader( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), cbBuffer, reinterpret_cast< ::LPENHMETAHEADER >( lpemh ) );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CEnhMetaFile::GetPaletteEntries( unsigned int cEntries, nsWin32::LPPALETTEENTRY lppe )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::GetPaletteEntries" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_GDI32Library.GetEnhMetaFilePaletteEntries( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), cEntries, reinterpret_cast< ::LPPALETTEENTRY >( lppe ) );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------
	unsigned int CEnhMetaFile::GetWinMetaFileBits( unsigned int cbBuffer, unsigned char* lpbBuffer, int fnMapMode, CDCInternal& DCRef )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::GetWinMetaFileBits" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_GDI32Library.GetWinMetaFileBits( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), cbBuffer, lpbBuffer, fnMapMode, reinterpret_cast< ::HDC >( DCRef.Handle()->Use() ) );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//--------------------------------------------------------------------------------			
	unsigned int CEnhMetaFile::GetPixelFormat( unsigned long cbBuffer, const nsWin32::PIXELFORMATDESCRIPTOR* ppfd )
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::GetPixelFormat" );
		UINT uiResult = 0;
		__QOR_PROTECT
		{
			uiResult = m_GDI32Library.GetEnhMetaFilePixelFormat( reinterpret_cast< ::HENHMETAFILE >( Handle()->Use() ), cbBuffer, reinterpret_cast< const ::PIXELFORMATDESCRIPTOR* >( ppfd ) );
		}__QOR_ENDPROTECT
		return uiResult;
	}

	//protected:

	//--------------------------------------------------------------------------------
	CEnhMetaFile::CEnhMetaFile( CEnhMetaFileHandle::refType hemf, bool bOwnership ) : CGDIObject< CEnhMetaFile >()
	{
		_WINQ_FCONTEXT( "CEnhMetaFile::CEnhMetaFile" );
		m_pResult = 0;
		SetHandle( hemf->AsHandle().ptr() );
		m_bOwner = bOwnership;
	}



	//--EnhMetaFile DC----------------------------------------------------------------			

	__QOR_IMPLEMENT_OCLASS_LUID( CEnhMetaFileDC );

	__QCMP_DECLARE_PERTHREAD CEnhMetaFileDCHandleMap* p_tEnhMetaFileDCHandleMap = 0;

	//--------------------------------------------------------------------------------
	CEnhMetaFileDCHandleMap& CEnhMetaFileDC::HandleMap( void )
	{
		_WINQ_SFCONTEXT( "CEnhMetaFileDC::HandleMap" );
		if( p_tEnhMetaFileDCHandleMap == 0 )
		{
			p_tEnhMetaFileDCHandleMap = new CEnhMetaFileDCHandleMap;
		}

		return *p_tEnhMetaFileDCHandleMap;
	}

	//--------------------------------------------------------------------------------			
	CEnhMetaFileDC::CEnhMetaFileDC( CDCInternal& DCRef, const TCHAR* lpFilename, const nsWin32::RECT* lpRect, const TCHAR* lpDescription ) : CGDIObject< CEnhMetaFileDC >()
	{
		_WINQ_FCONTEXT( "CEnhMetaFileDC::CEnhMetaFileDC" );
		__QOR_PROTECT
		{
			SetHandle( m_GDI32Library.CreateEnhMetaFile( reinterpret_cast< ::HDC >( DCRef.Handle()->Use() ), lpFilename, reinterpret_cast< const ::RECT* >( lpRect ), lpDescription ) );
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CEnhMetaFileDC::~CEnhMetaFileDC()
	{
		_WINQ_FCONTEXT( "CEnhMetaFileDC::~CEnhMetaFileDC" );
	}

	//--------------------------------------------------------------------------------
	CEnhMetaFile::refType CEnhMetaFileDC::Close()
	{
		_WINQ_FCONTEXT( "CEnhMetaFileDC::Close" );
		__QOR_PROTECT
		{
			CEnhMetaFile::refType Result( new CEnhMetaFile( CEnhMetaFileHandle( 0, (void*)( m_GDI32Library.CloseEnhMetaFile( reinterpret_cast< ::HDC >( Handle()->Use() ) ) ) ).Ref(), true ), true );
			delete this;
			return Result;
		}__QOR_ENDPROTECT
	}

}//nsWin32