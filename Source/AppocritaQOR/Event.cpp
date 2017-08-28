//Event.cpp

// Copyright Querysoft Limited 2016
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

#include "CodeQOR/Instancing/TInstancePtr.h"
#include "AppocritaQOR/AppocritaQOR.h"
#include "AppocritaQOR/Event.h"
#include "AppocritaQOR/Application.h"
#include "AppocritaQOR/SubSystems/Thread.h"

//------------------------------------------------------------------------------
namespace nsQOR
{

	//------------------------------------------------------------------------------
	CEvent::CEvent( IApplication& Application ) : m_Application( Application )
	{
		__QCS_FCONTEXT( "CEvent::CEvent" );
		IRole::ref_type Role = m_Application.GetRole();
		if( !Role.IsNull() )
		{
			m_Context = CThread::GetCurrent();
			if( !m_Context.IsNull() )
			{
				m_Context().LocalEventManager().Publish( Ref() );
			}
		}
	}

	//------------------------------------------------------------------------------
	CEvent::CEvent() : CEvent(TheApplication()())//chaining constructor
	{
	}

	//------------------------------------------------------------------------------
	void CEvent::Signal()
	{
		OnSignaled();
	}

	//------------------------------------------------------------------------------
	void CEvent::OnSignaled()
	{
		__QCS_FCONTEXT( "CEvent::OnSignaled" );
		m_Context().LocalEventManager().Raise( Ref() );
		m_Application.EnqueueEvent( this );
	}

	//------------------------------------------------------------------------------
	CEvent::~CEvent()
	{
		m_Context().LocalEventManager().Revoke( Ref() );
	}



	//--------------------------------------------------------------------------------
	CEventSink::CEventSink( CEvent::ref_type pEvent ) : IEventHandler(), m_pEvent( nullptr )
	{
		if( pEvent )
		{
			Connect( pEvent );
		}
	}

	//--------------------------------------------------------------------------------
	CEventSink::~CEventSink()
	{
		Disconnect();
	}

	//--------------------------------------------------------------------------------
	bool CEventSink::Connect( CEvent::ref_type pEvent )
	{
		bool bResult = false;
		if( !Connected() )
		{
			m_pEvent = pEvent;
			IThread::ref_type pThread = CThread::GetCurrent();
			if( pThread )
			{
				bResult = pThread->LocalEventManager().Subscribe( Ref(), m_pEvent );
			}
		}

		if( !bResult )
		{
			m_pEvent = nullptr;
		}
		return bResult;
	}

	//--------------------------------------------------------------------------------
	void CEventSink::Disconnect()
	{
		if( Connected() )
		{
			IThread::ref_type pThread = CThread::GetCurrent();
			if( pThread )
			{
				pThread->LocalEventManager().Unsubscribe( Ref(), m_pEvent );
			}
			m_pEvent = nullptr;
		}
	}

	//--------------------------------------------------------------------------------
	bool CEventSink::Connected()
	{
		return m_pEvent.IsNull() ? false : true;
	}

	//--------------------------------------------------------------------------------
	CEventManager::CEventManager()
	{
	}

	//--------------------------------------------------------------------------------
	CEventManager::~CEventManager()
	{
	}

	//--------------------------------------------------------------------------------
	void CEventManager::Publish( CEvent::ref_type Event )
	{
		IEvent* pEvent = Event;
		auto it = m_EventSubscriberMap.find( pEvent );		
		
		if( it == m_EventSubscriberMap.end() )
		{
			m_EventSubscriberMap.insert( std::make_pair( pEvent, new std::vector< std::pair< IEventHandler*, int > >() ) );
		}
	}

	//--------------------------------------------------------------------------------
	void CEventManager::Revoke( CEvent::ref_type pEvent )
	{		
		auto it = m_EventSubscriberMap.find( pEvent.operator->() );
		if( it != m_EventSubscriberMap.end() )
		{
			m_EventSubscriberMap.erase( it );
		}		
	}

	//--------------------------------------------------------------------------------
	void CEventManager::Raise( CEvent::ref_type pEvent )
	{
		auto pSubscriberList = m_EventSubscriberMap.at( pEvent.operator->() );
		if( pSubscriberList )
		{
			for( std::pair<IEventHandler*, int> pHandlerPair: *pSubscriberList )
			{
				(*pHandlerPair.first)(pEvent, pHandlerPair.second);
			}
		}
	}

	//--------------------------------------------------------------------------------
	bool CEventManager::Subscribe( IEventHandler::ref_type pSink, CEvent::ref_type pEvent, int iCookie )
	{
		bool bResult = false;

		auto pSubscriberList = m_EventSubscriberMap.at( pEvent.operator->() );
		if( pSubscriberList )
		{
			pSubscriberList->push_back( std::make_pair( pSink.operator->(), iCookie ) );
			bResult = true;
		}
		return bResult;
	}

	//--------------------------------------------------------------------------------
	bool CEventManager::Unsubscribe(IEventHandler::ref_type pSink, CEvent::ref_type pEvent )
	{
		bool bResult = false;

		auto pSubscriberList = m_EventSubscriberMap.at( pEvent.operator->() );

		if( pSubscriberList )
		{
			for( auto it = pSubscriberList->begin(); it != pSubscriberList->end(); it++ )
			{
				if( (*it).first == pSink.operator->() )
				{
					pSubscriberList->erase( it );
					bResult = true;
					break;
				}
			}
		}
		
		return bResult;
	}

}//nsQOR
