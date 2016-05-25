//SafeArray.h

// Copyright Querysoft Limited 2013, 2015
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

#ifndef WINQL_CS_COM_SAFEARRAY_H_3
#define WINQL_CS_COM_SAFEARRAY_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "SystemQOR.h"
#include "WinQL/Definitions/Constants.h"
#include "WinQL/Definitions/Data.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	class __QOR_INTERFACE( __WINQAPI ) COLEAut32;
}

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_COM ) CSafeArray
	{
	public:

		__QOR_DECLARE_OCLASS_ID( CSafeArray );

		CSafeArray( unsigned short usVarType, unsigned int uiCountDims, SafeArrayBound* pBounds );
		CSafeArray( unsigned short usVarType, unsigned int uiCountDims, SafeArrayBound* pBounds, void* pvExtra );
		CSafeArray( unsigned short usVarType, long lLBound, unsigned long ulCountElements );
		CSafeArray( unsigned short usVarType, long lLBound, unsigned long ulCountElements, void* pvExtra );
		CSafeArray( const CSafeArray& src );
		CSafeArray& operator = ( const CSafeArray& src );
		virtual ~CSafeArray();

		unsigned int GetDim( void );
		unsigned int GetElemSize( void );
		long GetUBound( unsigned int nDim, long* plUBound );
		long GetLBound( unsigned int nDim, long* plLBound );
		long Lock( void );
		long Unlock( void );
		long AccessData( void** ppvData );
		long UnaccessData( void );
		long GetElement( long* pIndices, void* pv );
		long PutElement( long* pIndicies, void* pv );			
		long CopyTo( CSafeArray* ppsaOut ) const;
		long AllocDescriptor( unsigned int uiCountDims, CSafeArray* ppsaOut );
		long AllocData( void );
		long DestroyDescriptor( void );
		long DestroyData( void );
		long Redim( SafeArrayBound* psaBoundNew );
		long AllocDescriptorEx( unsigned short uiVarType, unsigned int uiCountDims, CSafeArray* ppsaOut );
		long GetVarType( unsigned short* puiVarType );
		long PtrOfIndex( long* pIndicies, void** ppData );
		long SetRecordInfo( IRecordInfo* prinfo );
		long GetRecordInfo( IRecordInfo** prinfo );
		long SetIID( const GUID& );
		long GetIID( nsCodeQOR::__mxGUID* pGUID );
		long CopyDataTo( CSafeArray* psaTarget );

	protected:

		nsWinQAPI::COLEAut32& m_Library;
		SafeArray* m_pArray;

	private:

		CSafeArray();
	};

}//nsWin32

#endif//WINQL_CS_COM_SAFEARRAY_H_3

