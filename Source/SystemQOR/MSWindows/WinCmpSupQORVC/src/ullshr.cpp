//ullshr.cpp

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

#include "CompilerQOR.h"
#include "CodeQOR/Macros/CodingMacros.h"
#include "ArchQOR/Common/Machine.h"
#include "ArchQOR/Common/HLAssembler/JITFunctor.h"

//To Generate assembler function for aullshr - unsigned long shift right

//------------------------------------------------------------------------------
class CJITaullshr : public nsArch::CJITFunctor0< int >
{
public:

	//------------------------------------------------------------------------------
	CJITaullshr( nsArch::CHighLevelAssemblerBase* pHLA, byte* pLaunchPad = 0 ) : CJITFunctor0( pHLA, pLaunchPad )
	{
		if (m_pLaunchPad != 0)
		{
			Generate();
		}
	}

protected:

	//------------------------------------------------------------------------------
	virtual FP Generate()
	{
		nsArch::nsx86::Cx86HLAIntrinsics& HLA = (*(dynamic_cast< nsArch::nsx86::Cx86HLAIntrinsics* >(m_pHLA)));
		nsArch::nsx86::CCPU& CPU = *(dynamic_cast< nsArch::nsx86::CCPU* >(HLA.getAssembler()));

		CPU.clear();

		nsArch::nsx86::CLabel Label1 = CPU.newLabel();
		nsArch::nsx86::CLabel Label2 = CPU.newLabel();
		nsArch::nsx86::CLabel Label3 = CPU.newLabel();
		nsArch::nsx86::CLabel Label4 = CPU.newLabel();
		nsArch::nsx86::CLabel Label5 = CPU.newLabel();

		/*
		; Purpose:
		;       Does a unsigned Long Shift Right
		;       Shifts a long right any number of bits.
		;
		; Entry:
		;       EDX:EAX - long value to be shifted
		;       CL      - number of bits to shift by
		;
		; Exit:
		;       EDX:EAX - shifted value
		;
		; Uses:
		;       CL is destroyed.
		*/


		/*
		; Handle shifts of 64 bits or more (if shifting 64 bits or more, the result
		; depends only on the high order bit of edx).
		*/
		//cmp     cl,64
		CPU.cmp(CPU.reg_cl(), nsArch::nsx86::CImm(64));
		//jae     short RETZERO
		CPU.short_jae(Label1);

		/*
		; Handle shifts of between 0 and 31 bits
		*/
		//cmp     cl, 32
		CPU.cmp(CPU.reg_cl(), nsArch::nsx86::CImm(32));
		//jae     short MORE32
		CPU.short_jae(Label2);
		//shrd    eax, edx, cl
		CPU.shrd(CPU.reg_eax(), CPU.reg_edx(), CPU.reg_cl());
		//shr     edx, cl
		CPU.shr(CPU.reg_edx(), CPU.reg_cl());
		//ret
		CPU.ret();

		/*
		; Handle shifts of between 32 and 63 bits
		*/
		//MORE32:
		CPU.bind(Label2);
		//mov     eax, edx
		CPU.mov(CPU.reg_eax(), CPU.reg_edx());
		//xor     edx, edx
		CPU.xor_(CPU.reg_edx(), CPU.reg_edx());
		//and     cl, 31
		CPU.and_(CPU.reg_cl(), nsArch::nsx86::CImm(31));
		//shr     eax, cl
		CPU.shr(CPU.reg_eax(), CPU.reg_cl());
		//ret
		CPU.ret();

		/*
		; return 0 in edx:eax
		*/
		//RETZERO:
		CPU.bind(Label1);
		//xor     eax, eax
		CPU.xor_(CPU.reg_eax(), CPU.reg_eax());
		//xor     edx, edx
		CPU.xor_(CPU.reg_edx(), CPU.reg_edx());
		//ret
		CPU.ret();

		// Make JIT function.
		FP fn = reinterpret_cast< FP >(CPU.make());

		// Ensure that everything is ok and write the launchpad
		if (fn)
		{
			m_bGenerated = true;
			if (m_pLaunchPad)
			{
				HLA.WriteLaunchPad((byte*)fn, m_pLaunchPad);
			}
		}

		return fn;
	}
};

__QCMP_STARTLINKAGE_C

#pragma section( ".jit", execute )

__declspec(allocate(".jit")) byte _aullshr[16];

#pragma comment( linker, "/SECTION:.jit,ERW" )

__QCMP_ENDLINKAGE_C

CJITaullshr aullshrJIT( &TheMachine()->HLAssembler(), _aullshr );

