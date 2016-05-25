//WinQLMediaSource.cpp

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

#include "WinQL/CodeServices/WinQLPolicy.h"
#include "WinQL/Application/Threading/WinQLCriticalSection.h"
#include "WinQL/MediaFoundation/MediaSource.h"
#include "WinQAPI/MedFoundAPI.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsMediaFoundation
	{
		__QOR_IMPLEMENT_OCLASS_LUID( CMediaSource );

		//--------------------------------------------------------------------------------
		CMediaSource::CMediaSource()
		{
			_WINQ_FCONTEXT( "CMediaSource::CMediaSource" );
			m_ulStatus = 0;
		}

		//--------------------------------------------------------------------------------
		CMediaSource::~CMediaSource()
		{
			_WINQ_FCONTEXT( "CMediaSource::~CMediaSource" );
		}


		__QOR_IMPLEMENT_OCLASS_LUID( CDeviceSource );

		//--------------------------------------------------------------------------------
		CDeviceSource::CDeviceSource( IMFAttributes* pAttributes ) : CMediaSource()
		{
			_WINQ_FCONTEXT( "CDeviceSource::CDeviceSource" );
			m_ulStatus = m_MFLibrary.MFCreateDeviceSource(
				reinterpret_cast< ::IMFAttributes* >( pAttributes ),
				reinterpret_cast< ::IMFMediaSource** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CDeviceSource::~CDeviceSource()
		{
			_WINQ_FCONTEXT( "CDeviceSource::~CDeviceSource" );
		}

		//--------------------------------------------------------------------------------

		__QOR_IMPLEMENT_OCLASS_LUID( CAggregateSource );

		//--------------------------------------------------------------------------------
		CAggregateSource::CAggregateSource( IMFCollection* pSourceCollection ) : CMediaSource()
		{
			_WINQ_FCONTEXT( "CAggregateSource::CAggregateSource" );
			m_ulStatus = m_MFLibrary.MFCreateAggregateSource(
				reinterpret_cast< ::IMFCollection* >( pSourceCollection ),
				reinterpret_cast< ::IMFMediaSource** >( &m_p ) );
		}

		//--------------------------------------------------------------------------------
		CAggregateSource::~CAggregateSource()
		{
			_WINQ_FCONTEXT( "CAggregateSource::~CAggregateSource" );
		}


		//--------------------------------------------------------------------------------
		__QOR_IMPLEMENT_OCLASS_LUID( CBaseCustomMediaSource );

		//--------------------------------------------------------------------------------
		CBaseCustomMediaSource::CBaseCustomMediaSource()
		{
			_WINQ_FCONTEXT( "CBaseCustomMediaSource::CBaseCustomMediaSource" );
		}

		//--------------------------------------------------------------------------------
		CBaseCustomMediaSource::CBaseCustomMediaSource( const CBaseCustomMediaSource& src )
		{
			_WINQ_FCONTEXT( "CBaseCustomMediaSource::CBaseCustomMediaSource" );
			*this = src;
		}

		//--------------------------------------------------------------------------------
		CBaseCustomMediaSource& CBaseCustomMediaSource::operator = ( const CBaseCustomMediaSource& src )
		{
			_WINQ_FCONTEXT( "CBaseCustomMediaSource::operator =" );
			if( &src != this )
			{
			}
			return *this;
		}

		//--------------------------------------------------------------------------------
		CBaseCustomMediaSource::~CBaseCustomMediaSource()
		{
			_WINQ_FCONTEXT( "CBaseCustomMediaSource::~CBaseCustomMediaSource" );
		}

	}//nsMediaFoundation

}//nsWin32
