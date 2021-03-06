//EComment.h

// Copyright (c) 2008-2010, Petr Kobalicek <kobalicek.petr@gmail.com>
// Copyright (c) Querysoft Limited 2012
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

// Emittable used to emit comment into Assembler logger.

#ifndef ARCHQOR_COMMON_ECOMMENT_H_2
#define ARCHQOR_COMMON_ECOMMENT_H_2

#include "CompilerQOR.h"
#include "Emittable.h"
#include "CodeQOR/DataTypes/GUID.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"

//------------------------------------------------------------------------------
namespace nsArch
{
	// Comments allows to comment your assembler stream for better debugging
	// and visualization what's happening. Comments are ignored if logger is not set.
	// Comment string can't be modified after comment was created.
	class __QOR_INTERFACE( __ARCHQOR ) CEComment : public CEmittable
	{

	public:

		__QOR_DECLARE_OCLASS_ID(CEComment);

		CEComment( nsArch::CHighLevelAssemblerBase* c, const char* comment ) __QCMP_THROW;
		CEComment( const CEComment& src ) __QCMP_THROW;
		CEComment& operator = ( const CEComment& src ) __QCMP_THROW;

		virtual ~CEComment() __QCMP_THROW;
		virtual void emit( CHighLevelAssemblerBase& a ) __QCMP_THROW;
		virtual int getMaxSize() const __QCMP_THROW;

	private:

		CEComment();
	};

}//nsArch

#endif//ARCHQOR_COMMON_ECOMMENT_H_2
