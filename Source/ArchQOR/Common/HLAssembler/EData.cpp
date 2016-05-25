//EData.cpp

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

//Implement generic embedded data emittable

#include "ArchQOR.h"
#include "ArchQOR/Common/HLAssembler/Emittables/EData.h"
#include "ArchQOR/Common/HLAssembler/Emittables/Emittable.h"
#include <string.h>
#include "CodeQOR/Tracing/FunctionContextBase.h"

//------------------------------------------------------------------------------
namespace nsArch
{
	//------------------------------------------------------------------------------
	__QOR_IMPLEMENT_OCLASS_LUID(CEData);

	//------------------------------------------------------------------------------
	CEData::CEData( nsArch::CHighLevelAssemblerBase* c, const void* data, Cmp_int_ptr length ) __QCMP_THROW : CEmittable( c, EMITTABLE_EMBEDDED_DATA )
	{
		__QCS_MEMBER_FCONTEXT("CEData::CEData");
		m_length = length;
		memcpy( m_data, data, length );
	}

	//------------------------------------------------------------------------------
	CEData::CEData( const CEData& src ) __QCMP_THROW : CEmittable( src )
	{
		__QCS_MEMBER_FCONTEXT("CEData::CEData");
		m_length = src.m_length;
		memcpy( m_data, src.m_data, m_length );
	}

	//------------------------------------------------------------------------------
	CEData& CEData::operator = ( const CEData& src ) __QCMP_THROW
	{
		__QCS_MEMBER_FCONTEXT("CEData::operator =");
		if( &src != this )
		{
			m_length = src.m_length;
			memcpy( m_data, src.m_data, m_length );
			CEmittable::operator=( src );
		}
		return *this;
	}

	//------------------------------------------------------------------------------
	CEData::~CEData() __QCMP_THROW
	{
		__QCS_MEMBER_FCONTEXT("CEData::~CEData");
	}

	//------------------------------------------------------------------------------
	void CEData::emit( CHighLevelAssemblerBase& a ) __QCMP_THROW
	{
		__QCS_MEMBER_FCONTEXT("CEData::emit");
		a.getAssembler()->embed( m_data, m_length );
	}

	//------------------------------------------------------------------------------
	int CEData::getMaxSize() const __QCMP_THROW
	{
		__QCS_MEMBER_FCONTEXT("CEData::getMaxSize");
		return static_cast< int >( m_length );
	}

}//nsArch
