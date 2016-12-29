//FunctionDefinition.cpp

// Copyright (c) 2008-2010, Petr Kobalicek <kobalicek.petr@gmail.com>
// Copyright (c) Querysoft Limited 2012, 2015
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

//Implement Function Definition class

#include "ArchQOR.h"
#include "ArchQOR/Common/HLAssembler/FunctionDefinition.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"

//------------------------------------------------------------------------------
namespace nsArch
{
	//------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID(CFunctionDefinition);

	//------------------------------------------------------------------------------
	CFunctionDefinition::CFunctionDefinition()
	{
		__QCS_MEMBER_FCONTEXT("CFunctionDefinition::CFunctionDefinition");
		m_parguments = 0;
		m_uiArgumentsCount = 0;
		m_uiReturnValue = static_cast< Cmp_unsigned__int32 >( INVALID_VALUE );
	}

	//------------------------------------------------------------------------------
	CFunctionDefinition::~CFunctionDefinition()
	{
		__QCS_MEMBER_FCONTEXT("CFunctionDefinition::~CFunctionDefinition");
	}

	//------------------------------------------------------------------------------
	CFunctionDefinition::CFunctionDefinition( const CFunctionDefinition& src )
	{
		__QCS_MEMBER_FCONTEXT("CFunctionDefinition::CFunctionDefinition");
		*this = src;
	}

	//------------------------------------------------------------------------------
	CFunctionDefinition& CFunctionDefinition::operator = ( const CFunctionDefinition& src )
	{
		__QCS_MEMBER_FCONTEXT("CFunctionDefinition::operator =");
		if( &src != this )
		{
			m_parguments = src.m_parguments;
			m_uiArgumentsCount = src.m_uiArgumentsCount;
			m_uiReturnValue = src.m_uiReturnValue;
		}
		return *this;
	}

}//nsArch