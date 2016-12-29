//BaseReg.cpp

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

#include "ArchQOR.h"

#if		( QOR_ARCH == QOR_ARCH_X86_32 || QOR_ARCH == QOR_ARCH_X86_64 )

#include "ArchQOR/x86/Assembler/Operands/Registers/BaseReg.h"
#include <new>

//------------------------------------------------------------------------------
namespace nsArch
{
	namespace nsx86
	{
	    //------------------------------------------------------------------------------
	    CBaseReg::~CBaseReg() __QCMP_THROW
	    {

	    }

		//------------------------------------------------------------------------------
		// Create a new base register.
		CBaseReg::CBaseReg( Cmp_unsigned__int32 code, Cmp_unsigned__int32 size ) __QCMP_THROW : COperand( nsCodeQOR::_DontInitialize() )
		{
			m_Op = EOPERAND_REG;
			m_Size = static_cast< Cmp_unsigned__int8 >( size );
			m_Id = static_cast< Cmp_unsigned__int32 >( INVALID_VALUE );
			m_Code = code;
		}

		//------------------------------------------------------------------------------
		// Create a new reference to other.
		CBaseReg::CBaseReg( const CBaseReg& other ) __QCMP_THROW : COperand( other )
		{
			m_Code = other.m_Code;
		}

		//------------------------------------------------------------------------------
		CBaseReg::CBaseReg( const nsCodeQOR::_DontInitialize& dontInitialize ) __QCMP_THROW : COperand( dontInitialize )
		{
		}

		//------------------------------------------------------------------------------
		void CBaseReg::Init( const CBaseReg& other ) __QCMP_THROW		// Initialize operand to another (used by constructors and assigment operators).
		{
			m_Op = other.m_Op;
			m_Size = other.m_Size;
			m_Id = other.m_Id;
			m_Code = other.m_Code;
		}

		//------------------------------------------------------------------------------
		COperand* CBaseReg::Clone( CZone& zone ) const
		{
			CBaseReg* pNewOperand = new( zone.zalloc( sizeof( CBaseReg ) ) ) CBaseReg( nsCodeQOR::_DontInitialize() );
			if (pNewOperand)
			{
				*pNewOperand = *this;
			}
			return pNewOperand;
		}

		//------------------------------------------------------------------------------
		// Get register code, see REG.
		Cmp_unsigned__int32 CBaseReg::getRegCode() const __QCMP_THROW
		{
			return static_cast< Cmp_unsigned__int32 >( m_Code );
		}

		//------------------------------------------------------------------------------
		// Get register type, see REG.
		Cmp_unsigned__int32 CBaseReg::getRegType() const __QCMP_THROW
		{
			return static_cast< Cmp_unsigned__int32 >( m_Code & REG_TYPE_MASK );
		}

		//------------------------------------------------------------------------------
		// Get register index (value from 0 to 7/15).
		Cmp_unsigned__int32 CBaseReg::getRegIndex() const __QCMP_THROW
		{
			return static_cast< Cmp_unsigned__int32 >( m_Code & REG_INDEX_MASK );
		}

		//------------------------------------------------------------------------------
		// Get whether register code is equal to code.
		bool CBaseReg::isRegCode( Cmp_unsigned__int32 code ) const __QCMP_THROW
		{
			return m_Code == code;
		}

		//------------------------------------------------------------------------------
		// Get whether register code is equal to type.
		bool CBaseReg::isRegType( Cmp_unsigned__int32 type ) const __QCMP_THROW
		{
			return static_cast< Cmp_unsigned__int32 >( m_Code & REG_TYPE_MASK ) == type;
		}

		//------------------------------------------------------------------------------
		// Get whether operand is register of regType type or memory.
		bool CBaseReg::isRegTypeMem( Cmp_unsigned__int32 regType ) const __QCMP_THROW
		{
			return ( ( m_Op == EOPERAND_REG ) & ( ( m_Code & REG_TYPE_MASK ) == regType ) ) | ( m_Op == EOPERAND_MEM );
		}

		//------------------------------------------------------------------------------
		// Get whether register index is equal to index.
		bool CBaseReg::isRegIndex( Cmp_unsigned__int32 index ) const __QCMP_THROW
		{
			return (Cmp_unsigned__int32)( m_Code & REG_INDEX_MASK ) == index;
		}

		//------------------------------------------------------------------------------
		// Set register code to code.
		void CBaseReg::setCode( Cmp_unsigned__int32 code ) __QCMP_THROW
		{
			m_Code = code;
		}

		//------------------------------------------------------------------------------
		// Set register size to size.
		void CBaseReg::setSize( Cmp_unsigned__int32 size ) __QCMP_THROW
		{
			m_Size = (Cmp_unsigned__int8)size;
		}

		// --------------------------------------------------------------------------
		CBaseReg& CBaseReg::operator = ( const CBaseReg& other ) __QCMP_THROW
		{
			Init( other );
			return *this;
		}

		//------------------------------------------------------------------------------
		bool CBaseReg::operator == ( const CBaseReg& other ) const __QCMP_THROW
		{
			return getRegCode() == other.getRegCode();
		}

		//------------------------------------------------------------------------------
		bool CBaseReg::operator != ( const CBaseReg& other ) const __QCMP_THROW
		{
			return getRegCode() != other.getRegCode();
		}

		//------------------------------------------------------------------------------
		// Get whether the extended register (additional eight registers introduced by 64-bit mode) is used.
		bool CBaseReg::isExtendedRegisterUsed() const __QCMP_THROW
		{
			// Hacky, but correct.
			// - If operand type is register then extended register is register with index 8 and greater (8 to 15 inclusive).
			// - If operand type is memory operand then we need to take care about label (in m_Base) and INVALID_VALUE, we just decrement the value
			//   by 8 and check if it's at interval 0 to 7 inclusive (if it's there then it's extended register ).
			return ( isReg() && ( m_Code & REG_INDEX_MASK )  >= 8 );
		}

	}//nsx86
}//nsArch

#endif	( QOR_ARCH == QOR_ARCH_X86_32 || QOR_ARCH == QOR_ARCH_X86_64 )