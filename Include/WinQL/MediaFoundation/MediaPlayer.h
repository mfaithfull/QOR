//MediaPlayer.h

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

#ifndef WINQL_MEDIAFOUND_MEDIAPLAYER_H_3
#define WINQL_MEDIAFOUND_MEDIAPLAYER_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/MediaFoundation/MediaFoundation.h"
#include "WinQL/GUI/Window.h"

#define __MFP_CAST_EVENT( pHdr, Tag )                                   ( ( (pHdr)->eEventType == nsWin32::MFP_EVENT_TYPE_##Tag ) ? (nsWin32::MFP_##Tag##_EVENT*)(pHdr) : NULL )
#define MFP_GET_PLAY_EVENT( pHdr )                                      __MFP_CAST_EVENT( pHdr, PLAY )
#define MFP_GET_PAUSE_EVENT( pHdr )                                     __MFP_CAST_EVENT( pHdr, PAUSE )
#define MFP_GET_STOP_EVENT( pHdr )                                      __MFP_CAST_EVENT( pHdr, STOP )
#define MFP_GET_POSITION_SET_EVENT( pHdr )                              __MFP_CAST_EVENT( pHdr, POSITION_SET )
#define MFP_GET_RATE_SET_EVENT( pHdr )                                  __MFP_CAST_EVENT( pHdr, RATE_SET )
#define MFP_GET_MEDIAITEM_CREATED_EVENT( pHdr )                         __MFP_CAST_EVENT( pHdr, MEDIAITEM_CREATED )
#define MFP_GET_MEDIAITEM_SET_EVENT( pHdr )                             __MFP_CAST_EVENT( pHdr, MEDIAITEM_SET )
#define MFP_GET_FRAME_STEP_EVENT( pHdr )                                __MFP_CAST_EVENT( pHdr, FRAME_STEP )
#define MFP_GET_MEDIAITEM_CLEARED_EVENT( pHdr )                         __MFP_CAST_EVENT( pHdr, MEDIAITEM_CLEARED )
#define MFP_GET_MF_EVENT( pHdr )                                        __MFP_CAST_EVENT( pHdr, MF )
#define MFP_GET_ERROR_EVENT( pHdr )                                     __MFP_CAST_EVENT( pHdr, ERROR )
#define MFP_GET_PLAYBACK_ENDED_EVENT( pHdr )                            __MFP_CAST_EVENT( pHdr, PLAYBACK_ENDED )
#define MFP_GET_ACQUIRE_USER_CREDENTIAL_EVENT( pHdr )                   __MFP_CAST_EVENT( pHdr, ACQUIRE_USER_CREDENTIAL )
#undef __MFP_CAST_EVENT

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsMediaFoundation
	{
		//--------------------------------------------------------------------------------
		enum MFP_EVENT_TYPE
		{	
			MFP_EVENT_TYPE_PLAY	= 0,
			MFP_EVENT_TYPE_PAUSE	= 1,
			MFP_EVENT_TYPE_STOP	= 2,
			MFP_EVENT_TYPE_POSITION_SET	= 3,
			MFP_EVENT_TYPE_RATE_SET	= 4,
			MFP_EVENT_TYPE_MEDIAITEM_CREATED	= 5,
			MFP_EVENT_TYPE_MEDIAITEM_SET	= 6,
			MFP_EVENT_TYPE_FRAME_STEP	= 7,
			MFP_EVENT_TYPE_MEDIAITEM_CLEARED	= 8,
			MFP_EVENT_TYPE_MF	= 9,
			MFP_EVENT_TYPE_ERROR	= 10,
			MFP_EVENT_TYPE_PLAYBACK_ENDED	= 11,
			MFP_EVENT_TYPE_ACQUIRE_USER_CREDENTIAL	= 12
		};
		
		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CMediaPlayer : public CComPtr< IMFPMediaPlayer >
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CMediaPlayer );

			CMediaPlayer( const wchar_t* pwszURL, int fStartPlayback, Cmp_unsigned__int32 creationOptions, IMFPMediaPlayerCallback* pCallback, COSWindow::refType Wnd );
			virtual ~CMediaPlayer();

		protected:

			nsWinQAPI::CMFPlay& m_MFPlay;
			unsigned long m_ulStatus;

		private:

			CMediaPlayer();
			CMediaPlayer( const CMediaPlayer& );
			CMediaPlayer& operator = ( const CMediaPlayer& );
		};
		
		
		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE(__WINQL_MEDIA) CMediaPlayerCallbackHandler : public CServerObjectBase< IMFPMediaPlayerCallback >
		{
		public:

			__QOR_DECLARE_OCLASS_ID( CMediaPlayerCallbackHandler );

			//--------------------------------------------------------------------------------
			CMediaPlayerCallbackHandler(){}
			//--------------------------------------------------------------------------------
			virtual ~CMediaPlayerCallbackHandler(){}
			//--------------------------------------------------------------------------------
			virtual void OnPlayEvent( MFP_PLAY_EVENT* pPlayEvent ){}
			//--------------------------------------------------------------------------------
			virtual void OnPauseEvent( MFP_PAUSE_EVENT* pPauseEvent ){}
			//--------------------------------------------------------------------------------
			virtual void OnStopEvent( MFP_STOP_EVENT* pStopEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnPositionSetEvent( MFP_POSITION_SET_EVENT* pPositionSetEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnRateSetEvent( MFP_RATE_SET_EVENT* pRateSetEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnMediaItemCreatedEvent( MFP_MEDIAITEM_CREATED_EVENT* pMediaItemCreatedEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnMediaItemSetEvent( MFP_MEDIAITEM_SET_EVENT* pMediaItemSetEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnFrameStepEvent( MFP_FRAME_STEP_EVENT* pFrameStepEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnMediaItemCleared( MFP_MEDIAITEM_CLEARED_EVENT* pMediaItemCleared ){};
			//--------------------------------------------------------------------------------
			virtual void OnMFEvent( MFP_MF_EVENT* pMFEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnErrorEvent( MFP_ERROR_EVENT* pErrorEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnPlaybackEndedEvent( MFP_PLAYBACK_ENDED_EVENT* pPlaybackEndedEvent ){};
			//--------------------------------------------------------------------------------
			virtual void OnAcquireUserCredentialEvent( MFP_ACQUIRE_USER_CREDENTIAL_EVENT* pAcquireUserCredentialEvent ){};
			//--------------------------------------------------------------------------------
			virtual void __QCMP_STDCALLCONVENTION OnMediaPlayerEvent( MFP_EVENT_HEADER* pEventHeader );
			
		};
		
	}//nsMediaFoundation

}//nsWin32

#endif//WINQL_MEDIAFOUND_MEDIAPLAYER_H_3
