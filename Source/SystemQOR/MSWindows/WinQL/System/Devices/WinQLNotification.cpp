//WinQLNotification.cpp

// Copyright Querysoft Limited 2013, 2017
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
#include "WinQL/Application/ErrorSystem/WinQLError.h"
#include "WinQL/CodeServices/Handles/WinQLHandle.h"
#include "WinQL/System/Devices/WinQLNotification.h"
#include "WinQL/Application/Threading/WinQLThread.h"
#include "WinQL/Application/Resources/WinQLResourceManager.h"
#include "WinQAPI/User32.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	using namespace nsWinQAPI;

	__QOR_IMPLEMENT_OCLASS_LUID( CDeviceNotification );

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __WINQL ) CDeviceNotification::ref_type CreateWindowDeviceNotification( CHandle& Handle, CNotificationFilter& Filter )
	{
		return new_shared_ref<CDeviceNotification>( Handle, Filter, DEVICE_NOTIFY_WINDOW_HANDLE );
	}

	//--------------------------------------------------------------------------------
	__QOR_INTERFACE( __WINQL ) CDeviceNotification::ref_type CreateServiceDeviceNotification( CHandle& Handle, CNotificationFilter& Filter )
	{
		return new_shared_ref<CDeviceNotification>( Handle, Filter, DEVICE_NOTIFY_SERVICE_HANDLE );
	}

	//--------------------------------------------------------------------------------
	CDeviceNotification::CDeviceNotification( CHandle& hRecipient, CNotificationFilter& Filter, unsigned long Flags ) : m_Library( CUser32::Instance() )
	{
		_WINQ_FCONTEXT( "CDeviceNotification::CDeviceNotification" );
		__QOR_PROTECT
		{
			switch( Filter.NotifyType() )
			{
			case CNotificationFilter::eNotifyInterface:
			{
				std::vector< sDeviceBroadcastDeviceInterace >::iterator it = Filter.InterfaceFilters().begin();
				while( it != Filter.InterfaceFilters().end() )
				{
					CHandle NotifyHandle = m_Library.RegisterDeviceNotification( hRecipient.Use(), &(*it), Filter.GetAllClasses() ? DEVICE_NOTIFY_ALL_INTERFACE_CLASSES | Flags : Flags );
					m_VecNotifyHandles.push_back( NotifyHandle );
					it++;
				}
			}
			break;
			case CNotificationFilter::eNotifyHandle:
			{
				std::vector< sDeviceBroadcastHandle >::iterator it = Filter.HandleFilters().begin();
				while( it != Filter.HandleFilters().end() )
				{
					CHandle NotifyHandle = m_Library.RegisterDeviceNotification( hRecipient.Use(), &(*it), Flags );
					m_VecNotifyHandles.push_back( NotifyHandle );
					it++;
				}
			}
			break;
			}
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	CDeviceNotification::~CDeviceNotification()
	{
		_WINQ_FCONTEXT( "CDeviceNotification::~CDeviceNotification" );
		__QOR_PROTECT
		{
			std::vector< CHandle >::iterator it = m_VecNotifyHandles.begin();
			while( it != m_VecNotifyHandles.end() )
			{
				m_Library.UnregisterDeviceNotification( (*it).Use() );			
				it++;
			}
		}__QOR_ENDPROTECT
	}

	//--------------------------------------------------------------------------------
	std::vector< CHandle >& CDeviceNotification::Handles( void )
	{
		_WINQ_FCONTEXT( "CDeviceNotification::Handles" );
		return m_VecNotifyHandles;
	}

}//nsWin32
