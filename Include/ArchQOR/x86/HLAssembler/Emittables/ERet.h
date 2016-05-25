//ERet.h

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

// Function return.

#ifndef ARCHQOR_X86PC_HLASSEMBLER_ERET_H_2
#define ARCHQOR_X86PC_HLASSEMBLER_ERET_H_2

#include "CompilerQOR.h"
#include "ArchQOR/Common/HLAssembler/Emittables/Emittable.h"
#include "EFunction.h"

//------------------------------------------------------------------------------
namespace nsArch
{
//------------------------------------------------------------------------------
namespace nsx86
{		
	//------------------------------------------------------------------------------	
	class __QOR_INTERFACE( __ARCHQOR ) CERet : public nsArch::CEmittable
	{
	public:
		
		CERet( nsArch::CHighLevelAssemblerBase* c, CEFunction* function, const COperand* first, const COperand* second ) __QCMP_THROW;
		virtual ~CERet() __QCMP_THROW;																				

		virtual void prepare( CHLAssemblerContextBase& cc ) __QCMP_THROW;
		virtual nsArch::CEmittable* translate( CHLAssemblerContextBase& cc ) __QCMP_THROW;
		virtual void emit( CHighLevelAssemblerBase& a ) __QCMP_THROW;
		virtual int getMaxSize() const __QCMP_THROW;

		//------------------------------------------------------------------------------
		inline CEFunction* getFunction() __QCMP_THROW 
		{ 
			return m_pFunction; 
		}

		//------------------------------------------------------------------------------
		inline COperand* getFirst() __QCMP_THROW 
		{ 
			return m_apRet[ 0 ]; 
		}

		//------------------------------------------------------------------------------
		inline COperand* getSecond() __QCMP_THROW 
		{ 
			return m_apRet[ 1 ]; 
		}

		//------------------------------------------------------------------------------
		inline const COperand* getFirst() const __QCMP_THROW 
		{ 
			return m_apRet[ 0 ]; 
		}

		//------------------------------------------------------------------------------
		inline const COperand* getSecond() const __QCMP_THROW 
		{ 
			return m_apRet[ 1 ]; 
		}
	
		bool shouldEmitJumpToEpilog() const __QCMP_THROW;				// Get whether jump to epilog have to be emitted.

	protected:
		
		CEFunction* m_pFunction;					// Function.
		COperand* m_apRet[ 2 ];						// Return value (operands)

	};
	
}//nsx86
}//nsArch

#endif//ARCHQOR_X86PC_HLASSEMBLER_ERET_H_2
