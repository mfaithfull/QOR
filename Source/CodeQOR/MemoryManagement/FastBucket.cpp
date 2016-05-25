//FastBucket.cpp

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

#include "SystemQOR.h"
#include "CodeQOR/MemoryManagement/FastBucket.h"
#include "CodeQOR/MemoryManagement/ManagedAllocator.h"

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//--------------------------------------------------------------------------------
	CFastBucket::CFastBucket( Cmp_uint_ptr uiPageUnits ) : m_uiPageUnits( uiPageUnits )
	, m_uiItems( 0 )
	, m_uiPages( 0 )
	{
	}

	//--------------------------------------------------------------------------------
	CFastBucket::CFastBucket( unsigned char* pMemory, Cmp_uint_ptr uiPageUnits ) : m_uiPageUnits( uiPageUnits )
	, m_uiItems( 0 )
	, m_uiPages( 0 )
	{
	}

	//--------------------------------------------------------------------------------
	CFastBucket::~CFastBucket()
	{			
		CStackPage* pPage = m_pToSPage;
		while( pPage )
		{
			m_pToSPage = pPage->Prev();
			delete pPage;
			pPage = m_pToSPage;
		}
	}

	//--------------------------------------------------------------------------------
	Cmp_uint_ptr CFastBucket::PageSize( void )
	{
		Cmp_uint_ptr uiTotalSize = ( m_uiPageUnits * suiPageUnitSize );
		return uiTotalSize;
	}

	//--------------------------------------------------------------------------------
	Cmp_uint_ptr CFastBucket::AllocatedItems( void )
	{
		return m_uiItems;
	}

	//--------------------------------------------------------------------------------
	Cmp_uint_ptr CFastBucket::AllocatedPages( void )
	{
		return m_uiPages;
	}

	//--------------------------------------------------------------------------------
	Cmp_uint_ptr CFastBucket::AllocatedSpace( void )
	{
		Cmp_uint_ptr uiSpace = 0;
		CStackPage* pPage = m_pBasePage;
		while( pPage )
		{
			uiSpace += pPage->TotalSize();
			pPage = pPage->Next();
		}
		return uiSpace;
	}

	//--------------------------------------------------------------------------------
	void CFastBucket::SetSize( Cmp_uint_ptr uiPageUnits )
	{
		m_uiPageUnits = uiPageUnits;
	}

	//--------------------------------------------------------------------------------
	void CFastBucket::Initialise()
	{
		if( m_pToSPage == 0 )
		{
			m_pToSPage = m_pBasePage = new CStackPage( m_uiPageUnits );
			m_uiPages++;
		}
	}

	//--------------------------------------------------------------------------------
	void CFastBucket::PushPage( void )
	{
		m_pToSPage->SetNext( new CStackPage( m_uiPageUnits ) );
		m_pToSPage->Next()->SetPrev( m_pToSPage );
		m_pToSPage = m_pToSPage->Next();
		m_uiPages++;
	}

	//--------------------------------------------------------------------------------
	void CFastBucket::PopPage( void )
	{
		m_pToSPage = m_pToSPage->Prev();
		m_pToSPage->Next()->SetPrev( 0 );
		delete m_pToSPage->Next();
		m_pToSPage->SetNext( 0 );
		m_uiPages--;
	}

	//--------------------------------------------------------------------------------
	void* CFastBucket::Allocate( Cmp_uint_ptr uiByteCount, unsigned int uiLine, const char* pFile, Cmp_uint_ptr ulAllocIndex )
	{
		m_pToSPage->Initialise();
		void* pMem = m_pToSPage->Allocate( uiByteCount, uiLine, pFile, ulAllocIndex );

		if( pMem == 0 )
		{
			PushPage();
			m_pToSPage->Initialise();
			pMem = m_pToSPage->Allocate( uiByteCount, uiLine, pFile, ulAllocIndex );
		}

		m_uiItems++;
		return pMem;
	}

	//--------------------------------------------------------------------------------
	bool CFastBucket::Free( void* pMemory )
	{
		//Shortcut to page
		CStackPage::Info* pInfo = reinterpret_cast< CStackPage::Info* >( ( reinterpret_cast< unsigned char* >( pMemory ) ) - sizeof( CStackPage::Info ) );
		CStackPage* pPage = pInfo->m_pPage;

		while( pPage && !pPage->Free( pMemory ) )
		{
			pPage = pPage->Prev();
		}

		if( pPage && ( pPage->AllocatedItems() == 0 ) )
		{
			CStackPage* pPrev = pPage->Prev();
			CStackPage* pNext = pPage->Next();

			if( pPage && pPage == m_pToSPage )
			{
				m_pToSPage = m_pToSPage->Prev();
			}
			if( pPage && pPage == m_pBasePage )
			{
				m_pBasePage = m_pBasePage->Next();
			}
			if( pPrev )
			{
				pPrev->SetNext( pNext );
				pPage->SetPrev( 0 );
			}
			if( pNext )
			{
				pNext->SetPrev( pPrev );
				pPage->SetNext( 0 );
			}

			delete pPage;
			m_uiPages--;
			m_uiItems--;
			return true;
		}

		m_uiItems--;
		return ( pPage == 0 ) ? false : true;
	}

	//--------------------------------------------------------------------------------
	void CFastBucket::Analyse( void(*pTrace)(char*) )
	{
		if( m_uiItems > 0 )
		{
			CStackPage* pPage = m_pToSPage;

			while( pPage )
			{
				//pPage->Analyse( pTrace );
				pPage = pPage->Prev();
			}
		}
	}

}//nsCodeQOR
