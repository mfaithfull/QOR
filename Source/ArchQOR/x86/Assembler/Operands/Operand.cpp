//Operand.cpp

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

//The base operand for x86 assembler

#include "ArchQOR.h"

#if		( QOR_ARCH == QOR_ARCH_X86_32 || QOR_ARCH == QOR_ARCH_X86_64 )

#include "ArchQOR/x86/Assembler/Operands/Operand.h"
#include "ArchQOR/x86/Assembler/Operands/Registers/GPReg.h"
#include <string.h>
#include <new>
//------------------------------------------------------------------------------
namespace nsArch
{
	//------------------------------------------------------------------------------
	namespace nsx86
	{

		//------------------------------------------------------------------------------
		COperand::COperand() __QCMP_THROW								//Create an uninitialized operand.
		{
			m_Op = 0;
			m_Size = 0;
			m_Id = static_cast< Cmp_unsigned__int32 >( INVALID_VALUE );
		}

		//------------------------------------------------------------------------------
		COperand::COperand( const COperand& other ) __QCMP_THROW
		{
			Init( other );
		}

		//------------------------------------------------------------------------------
		COperand::COperand( const nsCodeQOR::_DontInitialize& ) __QCMP_THROW
		{
		}

        //------------------------------------------------------------------------------
        COperand::~COperand() __QCMP_THROW
        {

        }

		//------------------------------------------------------------------------------
		// Get type of operand, see OPERAND_TYPE.
		Cmp_unsigned__int32 COperand::getType() const __QCMP_THROW
		{
			return m_Op;
		}

		//------------------------------------------------------------------------------
		// Get whether operand is none (OPERAND_NONE).
		bool COperand::isNone() const __QCMP_THROW
		{
			return ( m_Op == EOPERAND_NONE );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is any (general purpose, mmx or sse) register (OPERAND_REG).
		bool COperand::isReg() const __QCMP_THROW
		{
			return ( m_Op == EOPERAND_REG );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is memory address (OPERAND_MEM).
		bool COperand::isMem() const __QCMP_THROW
		{
			return ( m_Op == EOPERAND_MEM );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is immediate (OPERAND_IMM).
		bool COperand::isImm() const __QCMP_THROW
		{
			return ( m_Op == EOPERAND_IMM );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is label (OPERAND_LABEL).
		bool COperand::isLabel() const __QCMP_THROW
		{
			return ( m_Op == EOPERAND_LABEL );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is variable (OPERAND_VAR).
		bool COperand::isVar() const __QCMP_THROW
		{
			return ( m_Op == EOPERAND_VAR );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is variable or memory.
		bool COperand::isVarMem() const __QCMP_THROW
		{
			return ( ( m_Op & ( EOPERAND_VAR | EOPERAND_MEM ) ) != 0 );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is register and type of register is regType.
		bool COperand::isRegType( Cmp_unsigned__int32 regType ) const __QCMP_THROW
		{
			return false;
		}

		//------------------------------------------------------------------------------
		// Get whether operand is register and code of register is regCode.
		bool COperand::isRegCode( Cmp_unsigned__int32 regCode ) const __QCMP_THROW
		{
			return false;
		}

		//------------------------------------------------------------------------------
		// Get whether operand is register and index of register is regIndex.
		bool COperand::isRegIndex( Cmp_unsigned__int32 regIndex ) const __QCMP_THROW
		{
			return false;
		}

		//------------------------------------------------------------------------------
		// Get whether operand is any register or memory.
		bool COperand::isRegMem() const __QCMP_THROW
		{
			return ( ( m_Op & ( EOPERAND_REG | EOPERAND_MEM ) ) != 0 );
		}

		//------------------------------------------------------------------------------
		// Get whether operand is register of regType type or memory.
		bool COperand::isRegTypeMem( Cmp_unsigned__int32 regType ) const __QCMP_THROW
		{
			return false;
		}

		//------------------------------------------------------------------------------
		// Return size of operand in bytes.
		Cmp_unsigned__int32 COperand::getSize() const __QCMP_THROW
		{
			return m_Size;
		}

		//------------------------------------------------------------------------------
		void COperand::setSize( Cmp_unsigned__int32 uiSize ) __QCMP_THROW
		{
			m_Size = static_cast< Cmp_unsigned__int8 >( uiSize );
		}

		//------------------------------------------------------------------------------
		// Return operand Id (Operand Id's are used internally by Assembler and HLAssembler classes).
		Cmp_unsigned__int32 COperand::getId() const __QCMP_THROW
		{
			return m_Id;
		}

		//------------------------------------------------------------------------------
		void COperand::setId( Cmp_unsigned__int32 uiId ) __QCMP_THROW
		{
			m_Id = uiId;
		}

		//------------------------------------------------------------------------------
		// Get whether the extended register (additional eight registers introduced by 64-bit mode) is used.
		bool COperand::isExtendedRegisterUsed() const __QCMP_THROW
		{
			return false;
		}

		//------------------------------------------------------------------------------
		void COperand::Init( const COperand& other ) __QCMP_THROW		// Initialize operand to another (used by constructors and assigment operators).
		{
			m_Op = other.m_Op;
			m_Size = other.m_Size;
			m_Id = other.m_Id;
		}

		//------------------------------------------------------------------------------
		COperand* COperand::Clone( CZone& zone ) const					//Clone this operand into Zone memory
		{
			COperand* pNewOperand = new( zone.zalloc( sizeof( COperand ) ) ) COperand;
			if (pNewOperand)
			{
				*pNewOperand = *this;
			}
			return pNewOperand;
		}

	}//nsx86
}//nsArch

#endif//( QOR_ARCH == QOR_ARCH_X86_32 || QOR_ARCH == QOR_ARCH_X86_64 )
