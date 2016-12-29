//WinQLActivate.cpp

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

#include "SystemQOR.h"
#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_THIS_USED_IN_BASE_INIT_LIST, "Safe usage: saved in member for later use" );
#include "WinQL/MediaFoundation/Activate.h"
__QCMP_WARNING_POP
#include "WinQAPI/MedFoundAPI.h"
#include "WinQAPI/OLE32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsMediaFoundation
	{
		__QOR_IMPLEMENT_OCLASS_LUID( CTransformActivate );

		//--------------------------------------------------------------------------------
		CTransformActivate::CTransformActivate()
		{
			_WINQ_FCONTEXT( "CTransformActivate::CTransformActivate" );
			m_ulStatus = MediaFoundationHelper.MFCreateTransformActivate( 
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CTransformActivate::~CTransformActivate()
		{
			_WINQ_FCONTEXT( "CTransformActivate::~CTransformActivate" );
		}


		__QOR_IMPLEMENT_OCLASS_LUID( CASFStreamingMediaSinkActivate );

		//--------------------------------------------------------------------------------
		CASFStreamingMediaSinkActivate::CASFStreamingMediaSinkActivate( IMFActivate* pByteStreamActivate, IMFASFContentInfo* pContentInfo )
		{
			_WINQ_FCONTEXT( "CASFStreamingMediaSinkActivate::CASFStreamingMediaSinkActivate" );
			m_ulStatus = m_MFLibrary.MFCreateASFStreamingMediaSinkActivate(
				reinterpret_cast< ::IMFActivate* >( pByteStreamActivate ),
				reinterpret_cast< ::IMFASFContentInfo* >( pContentInfo ),
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CASFStreamingMediaSinkActivate::~CASFStreamingMediaSinkActivate()
		{
			_WINQ_FCONTEXT( "CASFStreamingMediaSinkActivate::~CASFStreamingMediaSinkActivate" );
		}


		__QOR_IMPLEMENT_OCLASS_LUID( CASFMediaSinkActivate );

		//--------------------------------------------------------------------------------
		CASFMediaSinkActivate::CASFMediaSinkActivate( const wchar_t* pwszFileName, IMFASFContentInfo* pContentInfo )
		{
			_WINQ_FCONTEXT( "CASFMediaSinkActivate::CASFMediaSinkActivate" );
			m_ulStatus = m_MFLibrary.MFCreateASFMediaSinkActivate( pwszFileName,
				reinterpret_cast< ::IMFASFContentInfo* >( pContentInfo ),
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CASFMediaSinkActivate::~CASFMediaSinkActivate()
		{
			_WINQ_FCONTEXT( "CASFMediaSinkActivate::~CASFMediaSinkActivate" );
		}

		
		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CActivationArray );

		//--------------------------------------------------------------------------------
		CActivationArray::CActivationArray( CAttributes& Attributes ) : m_OLE32Library( *( new nsWinQAPI::COLE32 ) ), m_MFLibrary( *( new nsWinQAPI::CMFAPI ) )
		{
			_WINQ_FCONTEXT( "CActivationArray::CActivationArray" );

			m_ElementCount = 0;
			m_apMFActivate = 0;
			m_MFLibrary.MFEnumDeviceSources( reinterpret_cast< ::IMFAttributes* >( Attributes.operator->() ), 
				reinterpret_cast< ::IMFActivate*** >( &m_apMFActivate ), &m_ElementCount );
		}

		//--------------------------------------------------------------------------------
		CActivationArray::~CActivationArray()
		{
			_WINQ_FCONTEXT( "CActivationArray::~CActivationArray" );

			for( unsigned long i = 0; i < m_ElementCount; i++)
			{
				if( m_apMFActivate[ i ] )
				{
					m_apMFActivate[ i ]->Release();
					m_apMFActivate[ i ] = 0;
				}
			}

			m_OLE32Library.CoTaskMemFree( m_apMFActivate );
		}

		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CSampleGrabberSinkActivate );

		//--------------------------------------------------------------------------------
		CSampleGrabberSinkActivate::CSampleGrabberSinkActivate( IMFMediaType* pIMFMediaType, IMFSampleGrabberSinkCallback* pIMFSampleGrabberSinkCallback )
		{
			_WINQ_FCONTEXT( "CSampleGrabberSinkActivate::CSampleGrabberSinkActivate" );
			m_ulStatus = m_MFLibrary.MFCreateSampleGrabberSinkActivate(
				reinterpret_cast< ::IMFMediaType* >( pIMFMediaType ),
				reinterpret_cast< ::IMFSampleGrabberSinkCallback* >( pIMFSampleGrabberSinkCallback ),
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CSampleGrabberSinkActivate::~CSampleGrabberSinkActivate()
		{
			_WINQ_FCONTEXT( "CSampleGrabberSinkActivate::~CSampleGrabberSinkActivate" );
		}

		
		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CDeviceSourceActivate );

		//--------------------------------------------------------------------------------
		CDeviceSourceActivate::CDeviceSourceActivate( IMFAttributes* pAttributes )
		{
			_WINQ_FCONTEXT( "CDeviceSourceActivate::CDeviceSourceActivate" );
			m_ulStatus = m_MFLibrary.MFCreateDeviceSourceActivate(
				reinterpret_cast< ::IMFAttributes* >( pAttributes ),
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CDeviceSourceActivate::~CDeviceSourceActivate()
		{
			_WINQ_FCONTEXT( "CDeviceSourceActivate::~CDeviceSourceActivate" );
		}

		
		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CTranscodeSinkActivate );

		//--------------------------------------------------------------------------------
		CTranscodeSinkActivate::CTranscodeSinkActivate()
		{
			_WINQ_FCONTEXT( "CTranscodeSinkActivate::CTranscodeSinkActivate" );
			m_ulStatus = m_MFLibrary.MFCreateTranscodeSinkActivate( 
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CTranscodeSinkActivate::~CTranscodeSinkActivate()
		{
			_WINQ_FCONTEXT( "CTranscodeSinkActivate::~CTranscodeSinkActivate" );
		}

		
		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CVideoRendererActivate );

		//--------------------------------------------------------------------------------
		CVideoRendererActivate::CVideoRendererActivate( COSWindow::refType WndVideo )
		{
			_WINQ_FCONTEXT( "CVideoRendererActivate::CVideoRendererActivate" );
			m_ulStatus = m_MFLibrary.MFCreateVideoRendererActivate( 
				reinterpret_cast< ::HWND >( WndVideo->Handle()->Use() ), 
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CVideoRendererActivate::~CVideoRendererActivate()
		{
			_WINQ_FCONTEXT( "CVideoRendererActivate::~CVideoRendererActivate" );
		}

		
		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CWMAEncoderActivate );

		//--------------------------------------------------------------------------------
		CWMAEncoderActivate::CWMAEncoderActivate( IMFMediaType* pMediaType, IPropertyStore* pEncodingConfigurationProperties )
		{
			_WINQ_FCONTEXT( "CWMAEncoderActivate::CWMAEncoderActivate" );
			m_ulStatus = m_MFLibrary.MFCreateWMAEncoderActivate( 
				reinterpret_cast< ::IMFMediaType* >( pMediaType ), 
				reinterpret_cast< ::IPropertyStore* >( pEncodingConfigurationProperties ),
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CWMAEncoderActivate::~CWMAEncoderActivate()
		{
			_WINQ_FCONTEXT( "CWMAEncoderActivate::~CWMAEncoderActivate" );
		}

		
		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CWMVEncoderActivate );

		//--------------------------------------------------------------------------------
		CWMVEncoderActivate::CWMVEncoderActivate( IMFMediaType* pMediaType, IPropertyStore* pEncodingConfigurationProperties )
		{
			_WINQ_FCONTEXT( "CWMVEncoderActivate::CWMVEncoderActivate" );
			m_ulStatus = m_MFLibrary.MFCreateWMVEncoderActivate(
				reinterpret_cast< ::IMFMediaType* >( pMediaType ),
				reinterpret_cast< ::IPropertyStore* >( pEncodingConfigurationProperties ),
				reinterpret_cast< ::IMFActivate** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CWMVEncoderActivate::~CWMVEncoderActivate()
		{
			_WINQ_FCONTEXT( "CWMVEncoderActivate::~CWMVEncoderActivate" );
		}

	}//nsMediaFoundation

}//nsWin32
