//GPReg.h

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

#ifndef ARCHQOR_X86PC_ASSEMBLERGPREG_H_2
#define ARCHQOR_X86PC_ASSEMBLERGPREG_H_2

#include "BaseReg.h"

//------------------------------------------------------------------------------
namespace nsArch
{
//------------------------------------------------------------------------------
namespace nsx86
{
	//------------------------------------------------------------------------------
	// General purpose register.
	//This class is for all general purpose registers (64, 32, 16 and 8-bit).
	class __QOR_INTERFACE( __ARCHQOR ) CGPReg : public CBaseReg
	{
	public:

        virtual ~CGPReg() __QCMP_THROW;
		CGPReg() __QCMP_THROW;
		CGPReg( const CGPReg& other ) __QCMP_THROW;
		CGPReg( const nsCodeQOR::_DontInitialize& dontInitialize ) __QCMP_THROW;
		CGPReg( const nsCodeQOR::_Initialize&, Cmp_unsigned__int32 code ) __QCMP_THROW;
		bool isGPB() const __QCMP_THROW;
		bool isGPBLo() const __QCMP_THROW;
		bool isGPBHi() const __QCMP_THROW;
		bool isGPW() const __QCMP_THROW;
		bool isGPD() const __QCMP_THROW;
		bool isGPQ() const __QCMP_THROW;
		CGPReg& operator = ( const CGPReg& other ) __QCMP_THROW;
		bool operator == ( const CGPReg& other ) const __QCMP_THROW;
		bool operator != ( const CGPReg& other ) const __QCMP_THROW;

		virtual COperand* Clone( CZone& zone ) const;
	};

	//------------------------------------------------------------------------------
	// Get general purpose register of byte size.
	static inline CGPReg gpb_lo( Cmp_unsigned__int32 index ) __QCMP_THROW
	{
		return CGPReg( nsCodeQOR::_Initialize(), static_cast< Cmp_unsigned__int32 >( index | REG_TYPE_GPB_LO ) );
	}

	//------------------------------------------------------------------------------
	// Get general purpose register of byte size.
	static inline CGPReg gpb_hi( Cmp_unsigned__int32 index ) __QCMP_THROW
	{
		return CGPReg( nsCodeQOR::_Initialize(), static_cast< Cmp_unsigned__int32 >( index | REG_TYPE_GPB_HI ) );
	}

	//------------------------------------------------------------------------------
	// Get general purpose register of word size.
	static inline CGPReg gpw( Cmp_unsigned__int32 index ) __QCMP_THROW
	{
		return CGPReg( nsCodeQOR::_Initialize(), static_cast< Cmp_unsigned__int32 >( index | REG_TYPE_GPW ) );
	}

	//------------------------------------------------------------------------------
	// Get general purpose register of dword size.
	static inline CGPReg gpd( Cmp_unsigned__int32 index ) __QCMP_THROW
	{
		return CGPReg( nsCodeQOR::_Initialize(), static_cast< Cmp_unsigned__int32 >( index | REG_TYPE_GPD ) );
	}

	//------------------------------------------------------------------------------
#if ( QOR_ARCH_WORDSIZE == 64 )
	// Get general purpose register of qword size (64-bit only).
	static inline CGPReg gpq( Cmp_unsigned__int32 index ) __QCMP_THROW
	{
		return CGPReg( nsCodeQOR::_Initialize(), static_cast< Cmp_unsigned__int32 >( index | REG_TYPE_GPQ ) );
	}
#endif

	//------------------------------------------------------------------------------
	// Get general purpose dword/qword register (depending to architecture).
	static inline CGPReg gpn( Cmp_unsigned__int32 index ) __QCMP_THROW
	{
		return CGPReg( nsCodeQOR::_Initialize(), static_cast< Cmp_unsigned__int32 >( index | REG_TYPE_GPN ) );
	}

}//nsx86
}//nsArch

#endif//ARCHQOR_X86PC_ASSEMBLERGPREG_H_2
