//i186CPU.h

// Copyright (c) 2008-2010, Petr Kobalicek <kobalicek.petr@gmail.com>
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

//Not really an 80186 16bit target, just the 80186 inherited instructions for 32 and 64 bit x86 targets.
//Breaks up x86 classes that would otherwise be too large.

#ifndef ARCHQOR_X86PC_I186CPU_H_2
#define ARCHQOR_X86PC_I186CPU_H_2

#include "i086CPU.h"

//------------------------------------------------------------------------------
namespace nsArch
{
//------------------------------------------------------------------------------
namespace nsx86
{
	//------------------------------------------------------------------------------
	//80186
	class __QOR_INTERFACE( __ARCHQOR ) Ci186CPU : public Ci086CPU
	{
	public:

		//------------------------------------------------------------------------------
		inline Ci186CPU( CCodeGeneratorBase* codeGenerator ) __QCMP_THROW : Ci086CPU( codeGenerator )
		{
		}

		//------------------------------------------------------------------------------
		inline virtual ~Ci186CPU() __QCMP_THROW
		{
		}

		//ENTER

		//------------------------------------------------------------------------------
		//Make Stack Frame for Procedure Parameters.
		inline void enter( const CImm& imm16, const CImm& imm8 )
		{
			_emitInstruction( INST_ENTER, &imm16, &imm8 );
		}

		//LEAVE

		//------------------------------------------------------------------------------
		//High Level Procedure Exit.
		inline void leave()
		{
			_emitInstruction( INST_LEAVE );
		}

	private:

		Ci186CPU( const Ci186CPU& src );//no copy constructor
		Ci186CPU& operator = ( const Ci186CPU& src );//no assignment
/*
BOUND		Check array index against bounds, raises software interrupt 5 if test fails
INS			Input from port to string, equivalent to IN (E)AX, DX; MOV ES:[(E)DI], (E)AX; adjust (E)DI according to operand size and DF
OUTS		Output string to port, equivalent to MOV (E)AX, DS:[(E)SI]; OUT DX, (E)AX; adjust (E)SI according to operand size and DF
*/

	};
}//nsx86
}//nsArch

#endif//ARCHQOR_X86PC_I186CPU_H_2
