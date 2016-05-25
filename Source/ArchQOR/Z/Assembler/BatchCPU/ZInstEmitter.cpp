//ZInstEmitter.cpp

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

//Implements low level instruction emitter for Z virtual processor

#include "ArchQOR.h"

#if		( QOR_ARCH == QOR_ARCH_Z )

#include "ArchQOR/Zarch/Assembler/BatchCPU/ZCPUCore.h"
#include "ArchQOR/Zarch/Assembler/Operands/Registers/ZBaseReg.h"
#include "ArchQOR/Common/Assembler/CodeGenerator.h"
#include "ArchQOR/Common/Assembler/Logger.h"
#include "ArchQOR/Zarch/Assembler/Operands/ZOperand.h"
#include "ArchQOR/Zarch/ZCPUInfo.h"
#include "ArchQOR/Zarch/Assembler/BatchCPU/InstEmitter.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

//------------------------------------------------------------------------------
namespace nsArch
{
	//------------------------------------------------------------------------------
	namespace nsZ
	{
		//------------------------------------------------------------------------------
		CInstEmitter::CInstEmitter( CZCPUCore& CPUParam, Cmp_unsigned__int32 codeParam ) __QCMP_THROW : m_CPU( CPUParam )
		{
		}


	}//nsZ
}//nsArch

#endif//( QOR_ARCH == QOR_ARCH_Z )
