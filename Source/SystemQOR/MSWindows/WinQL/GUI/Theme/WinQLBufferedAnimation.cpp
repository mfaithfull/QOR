//WinQLBufferedAnimation.cpp

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
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usafe: stored in member for later use" );
#include "WinQL/GUI/Theme/BufferedAnimation.h"
__QCMP_WARNING_POP
#include "WinQAPI/User32.h"
#include "WinQAPI/UxTheme.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace ::nsWinQAPI;

__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usafe: stored in member for later use" );
	//--------------------------------------------------------------------------------
	CBufferedAnimation::CBufferedAnimation( COSWindow::refType Wnd, CDeviceContext::refType dcTarget, const nsWin32::RECT* rcTarget, nsWin32::BP_BUFFERFORMAT dwFormat, nsWin32::BP_PAINTPARAMS* pPaintParams, nsWin32::BP_ANIMATIONPARAMS* pAnimationParams, CDeviceContext::refType dcFrom, CDeviceContext::refType dcTo ) : m_UXTheme( CUXTheme::Instance() )
	,	m_Handle( this, 0 )
	{
		void* phdcFrom = 0;
		void* phdcTo = 0;
		m_Handle = ( m_UXTheme.BeginBufferedAnimation( 
			reinterpret_cast< ::HWND >( Wnd->Handle()->Use() ), 
			reinterpret_cast< ::HDC >( dcTarget->Handle()->Use() ), 
			reinterpret_cast< const ::RECT* >( rcTarget ), 
			static_cast< ::BP_BUFFERFORMAT >( dwFormat ),
			reinterpret_cast< ::BP_PAINTPARAMS* >( pPaintParams ), 
			reinterpret_cast< ::BP_ANIMATIONPARAMS* >( pAnimationParams ), 
			reinterpret_cast< ::HDC* >( phdcFrom ), 
			reinterpret_cast< ::HDC* >( phdcTo ) ) );
		dcFrom = CDeviceContext::FromHandle( CDCHandle( 0, phdcFrom ).Ref() );
		dcTo = CDeviceContext::FromHandle( CDCHandle( 0, phdcTo ).Ref() );

		m_bUpdateTarget = ( !m_Handle.IsNull() );
	}
__QCMP_WARNING_POP

	//--------------------------------------------------------------------------------
	CBufferedAnimation::~CBufferedAnimation()
	{
		m_UXTheme.EndBufferedAnimation( 
			reinterpret_cast< ::HANIMATIONBUFFER >( m_Handle.Use() ), m_bUpdateTarget ? 1 : 0 );
	}

	//--------------------------------------------------------------------------------
	CBufferedAnimation& CBufferedAnimation::operator = ( const CBufferedAnimation& src )
	{
		return *this;
	}

	//--------------------------------------------------------------------------------
	void CBufferedAnimation::UpdateTargetOnClose( bool bUpdate )
	{
		m_bUpdateTarget = bUpdate;
	}

}//nsWin32
