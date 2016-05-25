//OLEAut32.h

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

#ifndef _QSYS_API_WIN32_MODULES_OLEAUT_H_
#define _QSYS_API_WIN32_MODULES_OLEAUT_H_

#include "../SystemQOR/MSWindows/WinQAPI/include/DynamicLibrary.h"
#include "Kernel32.h"

//--------------------------------------------------------------------------------
namespace nsWinQAPI
{
	/*
typedef struct tagSAFEARRAY 
{
  USHORT         cDims;
  USHORT         fFeatures;
  ULONG          cbElements;
  ULONG          cLocks;
  PVOID          pvData;
  SAFEARRAYBOUND rgsabound[1];
} SAFEARRAY, *LPSAFEARRAY;

typedef struct tagSAFEARRAYBOUND 
{
  ULONG cElements;
  LONG  lLbound;
} SAFEARRAYBOUND, *LPSAFEARRAYBOUND;

*/


	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQAPI ) COLEAut32 : public CDll
	{
	public:

		//--------------------------------------------------------------------------------
		COLEAut32() : CDll( TEXT("OLEAut32.dll") )
		{						
		}

		//--------------------------------------------------------------------------------
		static COLEAut32& Instance( void )
		{
			static COLEAut32 _instance;
			return _instance;
		}

		//--------------------------------------------------------------------------------
		~COLEAut32()
		{						
		}

//Conversion and Manipulation Functions
	//Array Manipulation Functions 
		SAFEARRAY* SafeArrayCreate( VARTYPE vt, UINT cDims, SAFEARRAYBOUND* rgsabound );
		HRESULT SafeArrayDestroy( SAFEARRAY* psa );
		UINT SafeArrayGetDim( SAFEARRAY* psa );
		UINT SafeArrayGetElemsize( SAFEARRAY* psa );
		HRESULT SafeArrayGetUBound( SAFEARRAY* psa, UINT nDim, LONG* plUbound );
		HRESULT SafeArrayGetLBound( SAFEARRAY* psa, UINT nDim, LONG* plLbound );
		HRESULT SafeArrayLock( SAFEARRAY* psa );
		HRESULT SafeArrayUnlock( SAFEARRAY* psa );
		HRESULT SafeArrayAccessData( SAFEARRAY* psa, void** ppvData);
		HRESULT SafeArrayUnaccessData( SAFEARRAY* psa );
		HRESULT SafeArrayGetElement( SAFEARRAY* psa, LONG* rgIndices, void* pv );
		HRESULT SafeArrayPutElement( SAFEARRAY* psa, LONG* rgIndices, void* pv );
		HRESULT SafeArrayCopy( SAFEARRAY* psa, SAFEARRAY** ppsaOut );
		HRESULT SafeArrayAllocDescriptor( UINT cDims, SAFEARRAY** ppsaOut );
		HRESULT SafeArrayAllocData( SAFEARRAY* psa );
		HRESULT SafeArrayDestroyDescriptor( SAFEARRAY* psa );
		HRESULT SafeArrayDestroyData( SAFEARRAY* psa );
		HRESULT SafeArrayRedim( SAFEARRAY* psa, SAFEARRAYBOUND* psaboundNew );
		HRESULT SafeArrayAllocDescriptorEx( VARTYPE vt, UINT cDims, SAFEARRAY** ppsaOut );
		SAFEARRAY* SafeArrayCreateEx( VARTYPE vt, UINT cDims, SAFEARRAYBOUND* rgsabound, PVOID pvExtra );
		HRESULT SafeArrayGetVartype( SAFEARRAY* psa, VARTYPE* pvt );
		HRESULT SafeArrayPtrOfIndex( SAFEARRAY* psa, LONG* rgIndices, void** ppvData );
		SAFEARRAY* SafeArrayCreateVector( VARTYPE vt, LONG lLbound, ULONG cElements );
		SAFEARRAY* SafeArrayCreateVectorEx( VARTYPE vt, LONG lLbound, ULONG cElements, PVOID pvExtra );
		HRESULT SafeArraySetRecordInfo( SAFEARRAY* psa, IRecordInfo* prinfo ); 
		HRESULT SafeArrayGetRecordInfo( SAFEARRAY* psa, IRecordInfo** prinfo );
		HRESULT SafeArraySetIID( SAFEARRAY* psa, REFGUID guid );
		HRESULT SafeArrayGetIID( SAFEARRAY* psa, GUID* pguid );
		HRESULT SafeArrayCopyData( SAFEARRAY* psaSource, SAFEARRAY* psaTarget );
	//BSTR and Vector Conversion Functions
		HRESULT VectorFromBstr( BSTR bstr, SAFEARRAY** ppsa );
		HRESULT BstrFromVector( SAFEARRAY* psa, BSTR* pbstr );
		HRESULT VarBstrCat( BSTR bstrLeft, BSTR bstrRight, LPBSTR pbstrResult );
		HRESULT VarBstrCmp( BSTR bstrLeft, BSTR bstrRight, LCID lcid, ULONG dwFlags );
		void __cdecl SetOaNoCache( void );
	//Currency Arithmetic Functions
		HRESULT VarCyAdd( CY cyLeft, CY cyRight, LPCY pcyResult );
		HRESULT VarCyMul( CY cyLeft, CY cyRight, LPCY pcyResult );
		HRESULT VarCyMulI4( CY cyLeft, long lRight, LPCY pcyResult );
		HRESULT VarCySub( CY cyLeft, CY cyRight, LPCY pcyResult );
		HRESULT VarCyAbs( CY cyIn, LPCY pcyResult );
		HRESULT VarCyFix( CY cyIn, LPCY pcyResult );
		HRESULT VarCyInt( CY cyIn, LPCY pcyResult );
		HRESULT VarCyMulI8( CY cyLeft, LONG64 lRight, LPCY pcyResult );
		HRESULT VarCyRound( CY cyIn, int cDecimals, LPCY pcyResult );
		HRESULT VarCyCmp( CY cyLeft, CY cyRight );
		HRESULT VarCyCmpR8( CY cyLeft, double dblRight );
	//Data Type Conversion Functions
		//Functions to convert to type char
		HRESULT VarI1FromR8( DOUBLE dblIn, CHAR* pcOut );
		HRESULT VarI1FromUI1( BYTE bIn, CHAR* pcOut );
		HRESULT VarI1FromI2( SHORT uiIn, CHAR* pcOut );
		HRESULT VarI1FromI4( LONG lIn, CHAR* pcOut );
		HRESULT VarI1FromR4( FLOAT fltIn, CHAR* pcOut );
		HRESULT VarI1FromDate( DATE dateIn, CHAR* pcOut );
		HRESULT VarI1FromCy( CY cyIn, CHAR* pcOut );
		HRESULT VarI1FromStr( LPCOLESTR strIn, LCID lcid, ULONG dwFlags, CHAR* pcOut );
		HRESULT VarI1FromDisp( IDispatch* pdispIn, LCID lcid, CHAR* pcOut );
		HRESULT VarI1FromBool( VARIANT_BOOL boolIn, CHAR* pcOut );
		HRESULT VarI1FromUI2( USHORT uiIn, CHAR* pcOut );
		HRESULT VarI1FromUI4( ULONG ulIn, CHAR* pcOut );
		HRESULT VarI1FromDec( const DECIMAL* pdecIn, CHAR* pcOut );
		HRESULT VarI1FromI8( LONG64 i64In, CHAR* pcOut );
		HRESULT VarI1FromUI8( ULONG64 i64In, CHAR* pcOut );

		//Functions to convert to currency type
		HRESULT VarCyFromI1( CHAR cIn, CY* pcyOut );
		HRESULT VarCyFromI2( SHORT sIn, CY* pcyOut );
		HRESULT VarCyFromI4( LONG lIn, CY* pcyOut );
		HRESULT VarCyFromI8( LONG64 i64In, CY* pcyOut );
		HRESULT VarCyFromR4( FLOAT fltIn, CY* pcyOut );
		HRESULT VarCyFromR8( DOUBLE dblIn, CY* pcyOut );
		HRESULT VarCyFromDate( DATE dateIn, CY* pcyOut );
		HRESULT VarCyFromStr( LPCOLESTR strIn, LCID lcid, ULONG dwFlags, CY* pcyOut );
		HRESULT VarCyFromBool( VARIANT_BOOL boolIn, CY* pcyOut );
		HRESULT VarCyFromUI1( BYTE bIn, CY* pcyOut );
		HRESULT VarCyFromUI2( USHORT uiIn, CY* pcyOut );
		HRESULT VarCyFromUI4( ULONG ulIn, CY* pcyOut );
		HRESULT VarCyFromUI8( ULONG64 ui64In, CY* pcyOut );
		HRESULT VarCyFromDisp( IDispatch* pdispIn, LCID lcid, CY* pcyOut );
		HRESULT VarCyFromDec( const DECIMAL* pdecIn, CY* pcyOut );



		/*
SysAllocString
SysReAllocString
SysAllocStringLen
SysReAllocStringLen
SysFreeString
SysStringLen
VariantInit
VariantClear
VariantCopy
VariantCopyInd
VariantChangeType
VariantTimeToDosDateTime
DispGetParam
DispGetIDsOfNames
DispInvoke
*/

/*
VarI2FromI4
VarI2FromR4
VarI2FromR8
VarI2FromCy
VarI2FromDate
VarI2FromStr
VarI4FromR4
VarI4FromR8
VarI4FromCy
VarI4FromDate
VarI4FromStr
VarR4FromI4
VarR4FromR8
VarR4FromCy
VarR4FromDate
VarR4FromStr
*/
/*
VarR8FromCy
VarR8FromDate
VarR8FromStr
VarDateFromI2
VarDateFromI4
VarDateFromR4
VarDateFromR8
VarDateFromCy
VarDateFromStr
VarDateFromBool
VarBstrFromUI1
VarBstrFromI2
VarBstrFromI4
VarBstrFromR4
VarBstrFromR8
VarBstrFromCy
VarBstrFromDate
VarBstrFromBool
VarBoolFromI2
VarBoolFromI4
VarBoolFromR4
VarBoolFromR8
VarBoolFromDate
VarBoolFromCy
VarBoolFromStr
VarFormatCurrency
VarUI1FromR8
VarDiv
VariantChangeTypeEx
*/
/*
SysStringByteLen
SysAllocStringByteLen
VarMul
VarPow
VarNeg
VarRound
VarCmp
SystemTimeToVariantTime
VariantTimeToSystemTime
VarBstrFromI1
VarBstrFromUI2
VarBstrFromUI4
VarUI2FromR8
VarUI4FromR8
VarUI4FromStr
BSTR_UserSize
BSTR_UserMarshal
BSTR_UserUnmarshal
BSTR_UserFree
VARIANT_UserSize
VARIANT_UserMarshal
VARIANT_UserUnmarshal
VARIANT_UserFree
LPSAFEARRAY_UserSize
LPSAFEARRAY_UserMarshal
LPSAFEARRAY_UserUnmarshal
LPSAFEARRAY_UserFree
LPSAFEARRAY_Size
LPSAFEARRAY_Marshal
LPSAFEARRAY_Unmarshal
VarI8FromR8
VarBstrFromI8
VarBstrFromUI8
VarUI8FromR8

LoadTypeLib
LoadRegTypeLib
RegisterTypeLib
CreateTypeLib2
LoadTypeLibEx
UnRegisterTypeLib
GetErrorInfo
SetErrorInfo
CreateErrorInfo
OleCreatePropertyFrameIndirect
OleCreatePropertyFrame
OleLoadPicture
OleCreatePictureIndirect
OleCreateFontIndirect
OleTranslateColor
RegisterTypeLibForUser
UnRegisterTypeLibForUser
OACleanup
DosDateTimeToVariantTime
CreateDispTypeInfo
CreateStdDispatch
RegisterActiveObject
RevokeActiveObject
GetActiveObject
DllCanUnloadNow
DllGetClassObject
DispCallFunc
DllRegisterServer
CreateTypeLib
QueryPathOfRegTypeLib
LHashValOfNameSys
LHashValOfNameSysA
OaBuildVersion
ClearCustData
DllUnregisterServer
OACreateTypeLib2
OleLoadPictureEx
OleLoadPictureFileEx
OleIconToCursor
OleLoadPictureFile
OleSavePictureFile
OleLoadPicturePath
GetRecordInfoFromGuids
GetRecordInfoFromTypeInfo
SetVarConversionLocaleSetting
GetVarConversionLocaleSetting
GetAltMonthNames
OaEnablePerUserTLibRegistration

VarParseNumFromStr
VarNumFromParseNum
VarI2FromUI1
VarI2FromDisp
VarI2FromBool

VarI4FromUI1
VarI4FromI2
VarI4FromDisp
VarI4FromBool

VarR4FromUI1
VarR4FromI2
VarR4FromDisp
VarR4FromBool
VarR8FromUI1
VarR8FromI2
VarR8FromI4
VarR8FromR4
VarR8FromDisp
VarR8FromBool
VarFormat
VarDateFromUI1
VarDateFromDisp
VarFormatDateTime
VarFormatNumber
VarBstrFromDisp
VarFormatPercent
VarBoolFromUI1
VarBoolFromDisp
VarWeekdayName
VarMonthName
VarUI1FromI2
VarUI1FromI4
VarUI1FromR4
VarUI1FromCy
VarUI1FromDate
VarUI1FromStr
VarUI1FromDisp
VarUI1FromBool
VarFormatFromTokens
VarTokenizeFormatString
VarAdd
VarAnd
VarEqv
VarIdiv
VarImp
VarMod
VarOr
VarSub
VarXor
VarAbs
VarFix
VarInt
VarNot
VarDecAdd
VarDecDiv
VarDecMul
VarDecSub
VarDecAbs
VarDecFix
VarDecInt
VarDecNeg
VarDecFromUI1
VarDecFromI2
VarDecFromI4
VarDecFromR4
VarDecFromR8
VarDecFromDate
VarDecFromCy
VarDecFromStr
VarDecFromDisp
VarDecFromBool
VarDecRound
VarDecCmp
VarI2FromI1
VarI2FromUI2
VarI2FromUI4
VarI2FromDec
VarI4FromI1
VarI4FromUI2
VarI4FromUI4
VarI4FromDec
VarR4FromI1
VarR4FromUI2
VarR4FromUI4
VarR4FromDec
VarR8FromI1
VarR8FromUI2
VarR8FromUI4
VarR8FromDec
VarDateFromI1
VarDateFromUI2
VarDateFromUI4
VarDateFromDec
VarBstrFromDec
VarBoolFromI1
VarBoolFromUI2
VarBoolFromUI4
VarBoolFromDec
VarUI1FromI1
VarUI1FromUI2
VarUI1FromUI4
VarUI1FromDec
VarDecFromI1
VarDecFromUI2
VarDecFromUI4

VarUI2FromUI1
VarUI2FromI2
VarUI2FromI4
VarUI2FromR4
VarUI2FromDate
VarUI2FromCy
VarUI2FromStr
VarUI2FromDisp
VarUI2FromBool
VarUI2FromI1
VarUI2FromUI4
VarUI2FromDec
VarUI4FromUI1
VarUI4FromI2
VarUI4FromI4
VarUI4FromR4
VarUI4FromDate
VarUI4FromCy
VarUI4FromDisp
VarUI4FromBool
VarUI4FromI1
VarUI4FromUI2
VarUI4FromDec
VarDecCmpR8


VarR8Pow
VarR4CmpR8
VarR8Round
VarCat
VarDateFromUdateEx
VarDateFromUdate
VarUdateFromDate
VarI8FromUI1
VarI8FromI2
VarI8FromR4
VarI8FromCy
VarI8FromDate
VarI8FromStr
VarI8FromDisp
VarI8FromBool
VarI8FromI1
VarI8FromUI2
VarI8FromUI4
VarI8FromDec
VarI2FromI8
VarI2FromUI8
VarI4FromI8
VarI4FromUI8
VarR4FromI8
VarR4FromUI8
VarR8FromI8
VarR8FromUI8
VarDateFromI8
VarDateFromUI8
VarBoolFromI8
VarBoolFromUI8
VarUI1FromI8
VarUI1FromUI8
VarDecFromI8
VarDecFromUI8
VarUI2FromI8
VarUI2FromUI8
VarUI4FromI8
VarUI4FromUI8
VarI8FromUI8
VarUI8FromI8
VarUI8FromUI1
VarUI8FromI2
VarUI8FromR4
VarUI8FromCy
VarUI8FromDate
VarUI8FromStr
VarUI8FromDisp
VarUI8FromBool
VarUI8FromI1
VarUI8FromUI2
VarUI8FromUI4
VarUI8FromDec


*/
	};

}//nsWinQAPI

#endif//_QSYS_API_WIN32_MODULES_OLEAUT_H_
