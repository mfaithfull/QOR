//ZFunctionPrototype.h

// Copyright Querysoft Limited 2015
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

// Calling convention and function argument handling.

#ifndef ARCHQOR_Z_HLASSEMBLER_FUNCTIONPROTOTYPE_H_1
#define ARCHQOR_Z_HLASSEMBLER_FUNCTIONPROTOTYPE_H_1

#include "CompilerQOR.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"
#include "CodeQOR/DataTypes/GUID.h"

//------------------------------------------------------------------------------
namespace nsArch
{
//------------------------------------------------------------------------------
namespace nsZ
{
	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __ARCHQOR ) CFunctionPrototype
	{
	public:

		__QOR_DECLARE_OCLASS_ID(CFunctionPrototype);

		CFunctionPrototype() __QCMP_THROW;
		~CFunctionPrototype() __QCMP_THROW;

		// --------------------------------------------------------------------------
		// Function argument location.
		struct Argument
		{
			Cmp_unsigned__int32 variableType;			// Variable type, see VARIABLE_TYPE.
			Cmp_unsigned__int32 registerIndex;			// Register index if argument is passed through register, otherwise INVALID_VALUE.
			Cmp__int32 stackOffset;						// Stack offset if argument is passed through stack, otherwise INVALID_VALUE.

			// Get whether the argument is assigned, for private use only.
			inline bool isAssigned() const __QCMP_THROW
			{
				return registerIndex != INVALID_VALUE || stackOffset != (Cmp__int32)INVALID_VALUE;
			}
		};

		// Set function prototype.
		// This will set function calling convention and setup arguments variables.
		// Note This function will allocate variables, it can be called only once.
		void setPrototype( Cmp_unsigned__int32 callingConvention, const Cmp_unsigned__int32* arguments, Cmp_unsigned__int32 argumentsCount, Cmp_unsigned__int32 returnValue ) __QCMP_THROW;

		// --------------------------------------------------------------------------
		// Get function calling convention, see CALL_CONV.
		inline Cmp_unsigned__int32 getCallingConvention() const __QCMP_THROW
		{
			return m_uiCallingConvention;
		}

		// --------------------------------------------------------------------------
		// Get whether the callee pops the stack.
		inline Cmp_unsigned__int32 getCalleePopsStack() const __QCMP_THROW
		{
			return m_uiCalleePopsStack;
		}

		// --------------------------------------------------------------------------
		// Get function arguments.
		inline Argument* getArguments() __QCMP_THROW
		{
			return m_Arguments;
		}

		// --------------------------------------------------------------------------
		// Get function arguments (const version).
		inline const Argument* getArguments() const __QCMP_THROW
		{
			return m_Arguments;
		}

		// --------------------------------------------------------------------------
		// Get count of arguments.
		inline Cmp_unsigned__int32 getArgumentsCount() const __QCMP_THROW
		{
			return m_uiArgumentsCount;
		}

		// --------------------------------------------------------------------------
		// Get function return value or INVALID_VALUE if it's void.
		inline Cmp_unsigned__int32 getReturnValue() const __QCMP_THROW
		{
			return m_uiReturnValue;
		}

		// --------------------------------------------------------------------------
		// Get direction of arguments passed on the stack.
		// Direction should be always ARGUMENT_DIR_RIGHT_TO_LEFT.
		//
		// Note This is related to used calling convention, it's not affected by
		// number of function arguments or their types.
		inline Cmp_unsigned__int32 getArgumentsDirection() const __QCMP_THROW
		{
			return m_uiArgumentsDirection;
		}

		// --------------------------------------------------------------------------
		// Get stack size needed for function arguments passed on the stack.
		inline Cmp_unsigned__int32 getArgumentsStackSize() const __QCMP_THROW
		{
			return m_uiArgumentsStackSize;
		}

		// --------------------------------------------------------------------------
		// Get registers used to pass first integer parameters by current
		// calling convention.
		//
		// Note This is related to used calling convention, it's not affected by
		// number of function arguments or their types.
		inline const Cmp_unsigned__int32* getArgumentsGPList() const __QCMP_THROW
		{
			return m_auiArgumentsGPList;
		}

		// --------------------------------------------------------------------------
		// Get registers used to pass first SP-FP or DP-FPparameters by
		// current calling convention.
		//
		// Note This is related to used calling convention, it's not affected by
		// number of function arguments or their types.
		inline const Cmp_unsigned__int32* getArgumentsXMMList() const __QCMP_THROW
		{
			return m_auiArgumentsXMMList;
		}

		// --------------------------------------------------------------------------
		// Get bitmask of GP registers which might be used for arguments.
		inline Cmp_unsigned__int32 getArgumentsGP() const __QCMP_THROW
		{
			return m_uiArgumentsGP;
		}

		// --------------------------------------------------------------------------
		// Get bitmask of MM registers which might be used for arguments.
		inline Cmp_unsigned__int32 getArgumentsMM() const __QCMP_THROW
		{
			return m_uiArgumentsMM;
		}

		// --------------------------------------------------------------------------
		// Get bitmask of XMM registers which might be used for arguments.
		inline Cmp_unsigned__int32 getArgumentsXMM() const __QCMP_THROW
		{
			return m_uiArgumentsXMM;
		}

		// --------------------------------------------------------------------------
		// Get bitmask of general purpose registers that's preserved (non-volatile).
		//
		// Note This is related to used calling convention, it's not affected by
		// number of function arguments or their types.
		inline Cmp_unsigned__int32 getPreservedGP() const __QCMP_THROW
		{
			return m_uiPreservedGP;
		}

		// --------------------------------------------------------------------------
		// Get bitmask of MM registers that's preserved (non-volatile).
		//
		// Note No standardized calling function is not preserving MM registers.
		// This member is here for extension writers who need for some reason custom
		// calling convention that can be called through code generated by ArchQOR
		// (or other runtime code generator).
		inline Cmp_unsigned__int32 getPreservedMM() const __QCMP_THROW
		{
			return m_uiPreservedMM;
		}

		// --------------------------------------------------------------------------
		// Return bitmask of XMM registers that's preserved (non-volatile).
		//
		// Note This is related to used calling convention, it's not affected by
		// number of function arguments or their types.
		inline Cmp_unsigned__int32 getPreservedXMM() const __QCMP_THROW
		{
			return m_uiPreservedXMM;
		}

		// --------------------------------------------------------------------------
		// Get mask of all GP registers used to pass function arguments.
		inline Cmp_unsigned__int32 getPassedGP() const __QCMP_THROW
		{
			return m_uiPassedGP;
		}

		// --------------------------------------------------------------------------
		// Get mask of all MM registers used to pass function arguments.
		inline Cmp_unsigned__int32 getPassedMM() const __QCMP_THROW
		{
			return m_uiPassedMM;
		}

		// --------------------------------------------------------------------------
		// Get mask of all XMM registers used to pass function arguments.
		inline Cmp_unsigned__int32 getPassedXMM() const __QCMP_THROW
		{
			return m_uiPassedXMM;
		}

		// Find argument (id) by the register code. Used mainly by ECall emittable.
		Cmp_unsigned__int32 findArgumentByRegisterCode( Cmp_unsigned__int32 regCode ) const __QCMP_THROW;

	protected:

		//void _clear() __QCMP_THROW;
		//void _setCallingConvention( Cmp_unsigned__int32 callingConvention ) __QCMP_THROW;
		//void _setPrototype( const Cmp_unsigned__int32* arguments, Cmp_unsigned__int32 argumentsCount, Cmp_unsigned__int32 returnValue ) __QCMP_THROW;
		//void _setReturnValue( Cmp_unsigned__int32 valueId ) __QCMP_THROW;

		Cmp_unsigned__int32 m_uiCallingConvention;		// Calling convention.
		Cmp_unsigned__int32 m_uiCalleePopsStack;		// Whether callee pops stack.

		Argument m_Arguments[ FUNC_MAX_ARGS ];			// List of arguments, their register codes or stack locations.

		Cmp_unsigned__int32 m_uiReturnValue;			// Function return value.

		Cmp_unsigned__int32 m_uiArgumentsCount;			// Count of arguments (in _argumentsList).
		Cmp_unsigned__int32 m_uiArgumentsDirection;		// Direction for arguments passed on the stack, see ARGUMENT_DIR.
		Cmp_unsigned__int32 m_uiArgumentsStackSize;		// Count of bytes consumed by arguments on the stack.

		Cmp_unsigned__int32 m_auiArgumentsGPList[ 16 ];	// List of registers that's used for first GP arguments.
		Cmp_unsigned__int32 m_auiArgumentsXMMList[ 16 ];// List of registers that's used for first XMM arguments.

		Cmp_unsigned__int32 m_uiArgumentsGP;			// Bitmask for GP arguments.
		Cmp_unsigned__int32 m_uiArgumentsMM;			// Bitmask for MM arguments.
		Cmp_unsigned__int32 m_uiArgumentsXMM;			// Bitmask for XMM arguments.

		Cmp_unsigned__int32 m_uiPreservedGP;			// Bitmask for preserved GP registers.
		Cmp_unsigned__int32 m_uiPreservedMM;			// Bitmask for preserved MM registers.
		Cmp_unsigned__int32 m_uiPreservedXMM;			// Bitmask for preserved XMM registers.

		// Set by _setPrototype().

		Cmp_unsigned__int32 m_uiPassedGP;				// Bitmask for GP registers used as function arguments.
		Cmp_unsigned__int32 m_uiPassedMM;				// Bitmask for MM registers used as function arguments.
		Cmp_unsigned__int32 m_uiPassedXMM;				// Bitmask for XMM registers used as function arguments.
	};

}//nsZ
}//nsArch

#endif//ARCHQOR_Z_HLASSEMBLER_FUNCTIONPROTOTYPE_H_1
