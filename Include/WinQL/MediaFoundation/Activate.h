//Activate.h

// Copyright Querysoft Limited 2015
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

#ifndef WINQL_MEDIAFOUND_ACTIVATE_H_3
#define WINQL_MEDIAFOUND_ACTIVATE_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/MediaFoundation/MediaFoundation.h"
#include "WinQL/MediaFoundation/Attributes.h"
#include "WinQL/GUI/Window.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsMediaFoundation
	{
		typedef CTMediaFoundationObject< IMFActivate > CActivate;
		typedef CTMediaFoundationAPIObject< IMFActivate > CAPIActivate;

		//-------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CTransformActivate : public CAPIActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CTransformActivate );

			CTransformActivate();
			virtual ~CTransformActivate();

		private:

			CTransformActivate( const CTransformActivate& );
			CTransformActivate& operator = ( const CTransformActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CASFStreamingMediaSinkActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CASFStreamingMediaSinkActivate );

			CASFStreamingMediaSinkActivate( IMFActivate* pByteStreamActivate, IMFASFContentInfo* pContentInfo );
			virtual ~CASFStreamingMediaSinkActivate();

		private:

			CASFStreamingMediaSinkActivate();
			CASFStreamingMediaSinkActivate( const CASFStreamingMediaSinkActivate& );
			CASFStreamingMediaSinkActivate& operator = ( const CASFStreamingMediaSinkActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL_MEDIA ) CASFMediaSinkActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CASFMediaSinkActivate );

			CASFMediaSinkActivate( const wchar_t* pwszFileName, IMFASFContentInfo* pContentInfo );
			virtual ~CASFMediaSinkActivate();

		private:
		
			CASFMediaSinkActivate();
			CASFMediaSinkActivate( const CASFMediaSinkActivate& );
			CASFMediaSinkActivate& operator = ( const CASFMediaSinkActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CActivationArray
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CActivationArray );
			
			CActivationArray( CAttributes& Attributes );
			~CActivationArray();

		protected:

			nsWinQAPI::COLE32& m_OLE32Library;
			nsWinQAPI::CMFAPI& m_MFLibrary;
			Cmp_unsigned__int32 m_ElementCount;
			IMFActivate** m_apMFActivate;

		private:

			CActivationArray();
			CActivationArray( const CActivationArray& );
			CActivationArray& operator = ( const CActivationArray& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CSampleGrabberSinkActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CSampleGrabberSinkActivate );

			CSampleGrabberSinkActivate( IMFMediaType* pIMFMediaType, IMFSampleGrabberSinkCallback* pIMFSampleGrabberSinkCallback );
			virtual ~CSampleGrabberSinkActivate();

		private:

			CSampleGrabberSinkActivate();
			CSampleGrabberSinkActivate( const CSampleGrabberSinkActivate& );
			CSampleGrabberSinkActivate& operator = ( const CSampleGrabberSinkActivate& );

		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CDeviceSourceActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CDeviceSourceActivate );

			CDeviceSourceActivate( IMFAttributes* pAttributes );
			virtual ~CDeviceSourceActivate();

		private:

			CDeviceSourceActivate( const CDeviceSourceActivate& );
			CDeviceSourceActivate& operator = ( const CDeviceSourceActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CTranscodeSinkActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CTranscodeSinkActivate );

			CTranscodeSinkActivate();
			virtual ~CTranscodeSinkActivate();

		private:
			
			CTranscodeSinkActivate( const CTranscodeSinkActivate& );
			CTranscodeSinkActivate& operator = ( const CTranscodeSinkActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CVideoRendererActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CVideoRendererActivate );

			CVideoRendererActivate( COSWindow::refType WndVideo );
			virtual ~CVideoRendererActivate();

		private:

			CVideoRendererActivate( const CVideoRendererActivate& );
			CVideoRendererActivate& operator = ( const CVideoRendererActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CWMAEncoderActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CWMAEncoderActivate );

			CWMAEncoderActivate( IMFMediaType* pMediaType, IPropertyStore* pEncodingConfigurationProperties );
			virtual ~CWMAEncoderActivate();

		private:

			CWMAEncoderActivate();
			CWMAEncoderActivate( const CWMAEncoderActivate& );
			CWMAEncoderActivate& operator = ( const CWMAEncoderActivate& );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CWMVEncoderActivate : public CActivate
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CWMVEncoderActivate );

			CWMVEncoderActivate( IMFMediaType* pMediaType, IPropertyStore* pEncodingConfigurationProperties );
			virtual ~CWMVEncoderActivate();

		private:

			CWMVEncoderActivate();
			CWMVEncoderActivate( const CWMVEncoderActivate& );
			CWMVEncoderActivate& operator = ( const CWMVEncoderActivate& );
		};

	}//nsMediaFoundation

}//nsWin32

#endif//WINQL_MEDIAFOUND_ACTIVATE_H_3

