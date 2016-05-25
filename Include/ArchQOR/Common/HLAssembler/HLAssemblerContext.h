//HLAssemblerContext.h

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

//The generic parts of the HLAssembler Context

#ifndef ARCHQOR_HLASMCONTEXT_H_2
#define ARCHQOR_HLASMCONTEXT_H_2

#include "CompilerQOR.h"
#include "ArchQOR/Common/Assembler/Assembler.h"
#include "CodeQOR/Macros/CodingMacros.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"
#include "CodeQOR/DataTypes/GUID.h"

//------------------------------------------------------------------------------
namespace nsArch
{
	//------------------------------------------------------------------------------	
	class __QOR_INTERFACE( __ARCHQOR ) CHLAssemblerContextBase
	{		
	public:

		__QOR_DECLARE_OCLASS_ID(CHLAssemblerContextBase);

		//------------------------------------------------------------------------------
		CHLAssemblerContextBase()
		{
		}

		//------------------------------------------------------------------------------
		virtual ~CHLAssemblerContextBase()
		{
		}

		//------------------------------------------------------------------------------
		CHLAssemblerContextBase( const CHLAssemblerContextBase& src )
		{
			*this = src;
		}

		//------------------------------------------------------------------------------
		CHLAssemblerContextBase& operator = ( const CHLAssemblerContextBase& src )
		{
			if( & src != this )
			{
				m_uiCurrentOffset = src.m_uiCurrentOffset;
			}
			return *this;
		}

		//------------------------------------------------------------------------------
		inline Cmp_unsigned__int32 GetCurrentOffset( void )
		{
			return m_uiCurrentOffset;
		}

		//------------------------------------------------------------------------------
		inline Cmp_unsigned__int32 IncrementCurrentOffset( Cmp_unsigned__int32 iAdd = 1 )
		{
			Cmp_unsigned__int32 uiResult = m_uiCurrentOffset; 
			m_uiCurrentOffset += iAdd;
			return uiResult;
		}

		//------------------------------------------------------------------------------
		inline void SetCurrentOffset( Cmp_unsigned__int32 iOffset )
		{
			m_uiCurrentOffset = iOffset;
		}

	protected:

		Cmp_unsigned__int32 m_uiCurrentOffset;		// Current offset, used in prepare() stage. Each emittable should increment it.
	};

}//nsArch

#endif//ARCHQOR_HLASMCONTEXT_H_2
