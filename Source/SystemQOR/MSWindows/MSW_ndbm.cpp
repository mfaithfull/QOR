//MSW_ndbm.cpp

// Copyright Querysoft Limited 2013
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

#if		(QOR_SYS_OS == QOR_SYS_MSW)

#include "SystemQOR/MSWindows/MSW_ndbm.h"
#include "CodeQOR/Tracing/FunctionContextBase.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	Cndbm::Cndbm()
	{
		__QCS_MEMBER_FCONTEXT( "Cndbm::Cndbm" );
	}

	//--------------------------------------------------------------------------------
	Cndbm::~Cndbm()
	{
		__QCS_MEMBER_FCONTEXT( "Cndbm::~Cndbm" );
	}

	//--------------------------------------------------------------------------------
	int Cndbm::dbm_clearerr( DBM* )
	{
		//TODO:
		int iResult = -1;
		return iResult;
	}

	//--------------------------------------------------------------------------------
	void Cndbm::dbm_close( DBM* )
	{
		//TODO:
	}

	//--------------------------------------------------------------------------------
	int Cndbm::dbm_delete( DBM*, datum )
	{
		//TODO:
		int iResult = -1;
		return iResult;
	}

	//--------------------------------------------------------------------------------
	int Cndbm::dbm_error( DBM* )
	{
		//TODO:
		int iResult = -1;
		return iResult;
	}

	//--------------------------------------------------------------------------------
	datum Cndbm::dbm_fetch( DBM*, datum )
	{
		//TODO:
		datum Result;
		return Result;
	}

	//--------------------------------------------------------------------------------
	datum Cndbm::dbm_firstkey( DBM* )
	{
		//TODO:
		datum Result;
		return Result;
	}

	//--------------------------------------------------------------------------------
	datum Cndbm::dbm_nextkey( DBM* )
	{
		//TODO:
		datum Result;
		return Result;
	}

	//--------------------------------------------------------------------------------
	DBM* Cndbm::dbm_open( const char *, int, mode_t )
	{
		//TODO:
		DBM* pResult = 0;
		return pResult;
	}

	//--------------------------------------------------------------------------------
	int Cndbm::dbm_store( DBM*, datum, datum, int )
	{
		//TODO:
		int iResult = -1;
		return iResult;
	}

}//nsWin32

#endif	//(QOR_SYS_OS == QOR_SYS_MSW)
