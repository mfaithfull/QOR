//ObexHeader.cpp

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

//Implementation of OBEX Header classes

#include "CompilerQOR.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"
#include "BluefootQOR/Protocols/OBEX/ObexHeader.h"
#include "arpa/inet.h"

//------------------------------------------------------------------------------
namespace nsOBEX
{
	__QOR_IMPLEMENT_OCLASS_LUID(CHeader);

	//------------------------------------------------------------------------------
	CHeader::CHeader() : m_ID(HDR_ID_INVALID), m_Type(HDR_TYPE_INVALID)
	{
		__QCS_MEMBER_FCONTEXT("CHeader::CHeader");
	}

	//------------------------------------------------------------------------------
	CHeader::CHeader(obex_headerdata_t& header_data) : m_ID(header_data.id), m_Type(header_data.type)
	{
		__QCS_MEMBER_FCONTEXT("CHeader::CHeader");
	}


	__QOR_IMPLEMENT_OCLASS_LUID(CConnectHeader);

	//------------------------------------------------------------------------------
	CConnectHeader::CConnectHeader(uint8_t Version, uint8_t Flags, uint16_t MTU) : m_Version(Version)
		, m_Flags(Flags)
		, m_MTU(htons(MTU))
	{
	}



	//------------------------------------------------------------------------------
	CDescriptionHeader::CDescriptionHeader(obex_headerdata_t& header_data, nsCodeQOR::CUCS2String& Description) : CHeader(header_data)
		, m_strDescription(Description)
	{
		__QCS_MEMBER_FCONTEXT("CDescriptionHeader::CDescriptionHeader");
	}


	//------------------------------------------------------------------------------
	CCountHeader::CCountHeader(obex_headerdata_t& header_data, uint32_t Count) : CHeader(header_data)
		, m_Count(Count)
	{
		__QCS_MEMBER_FCONTEXT("CCountHeader::CCountHeader");
	}


	//------------------------------------------------------------------------------
	CLengthHeader::CLengthHeader(obex_headerdata_t& header_data, uint32_t Length) : CHeader(header_data)
		, m_Length(Length)
	{
		__QCS_MEMBER_FCONTEXT("CLengthHeader::CLengthHeader");
	}


	//------------------------------------------------------------------------------
	CConnectionIDHeader::CConnectionIDHeader(obex_headerdata_t& header_data, uint32_t ConnectionID) : CHeader(header_data)
		, m_ConnectionID(ConnectionID)
	{
		__QCS_MEMBER_FCONTEXT("CConnectionIDHeader::CConnectionIDHeader");
	}


}//nsOBEX
