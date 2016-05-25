//ExtendTaskpadImpl.h

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

//Base class for implementing IExtendTaskpad for MMC snapin

#ifndef WINQL_COM_MMC_EXTENDTASKPADIMPL_H_3
#define WINQL_COM_MMC_EXTENDTASKPADIMPL_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/COM/MMC/MMCInterfaces.h"
#include "WinQL/COM/TInterfaceMember.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL_COM ) CExtendTaskpadImpl : public CInterfaceImplBase< IExtendTaskpad >
	{
	public:

		__QOR_DECLARE_COMCLASS_ID( CExtendTaskpadImpl );

		CExtendTaskpadImpl( CIUnknownImplBase<>* pImpl );
		virtual ~CExtendTaskpadImpl();

        virtual long __QCMP_STDCALLCONVENTION TaskNotify( IDataObject *pdo, VARIANT *arg, VARIANT *param );
        virtual long __QCMP_STDCALLCONVENTION EnumTasks( IDataObject *pdo, wchar_t* szTaskGroup, IEnumTASK** ppEnumTASK );
        virtual long __QCMP_STDCALLCONVENTION GetTitle( wchar_t* pszGroup, wchar_t** pszTitle);
        virtual long __QCMP_STDCALLCONVENTION GetDescriptiveText( wchar_t* pszGroup, wchar_t** pszDescriptiveText );
        virtual long __QCMP_STDCALLCONVENTION GetBackground( wchar_t* pszGroup, MMC_TASK_DISPLAY_OBJECT* pTDO );
        virtual long __QCMP_STDCALLCONVENTION GetListPadInfo( wchar_t* pszGroup, MMC_LISTPAD_INFO* lpListPadInfo );

	private:

		CExtendTaskpadImpl();
		CExtendTaskpadImpl( const CExtendTaskpadImpl& );
		CExtendTaskpadImpl& operator = ( const CExtendTaskpadImpl& );
	};

}//nsWin32

#endif//WINQL_COM_MMC_EXTENDTASKPADIMPL_H_3

