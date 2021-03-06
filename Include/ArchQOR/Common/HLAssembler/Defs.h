//Defs.h

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

//Fundamental definitions for generic high level assemblers

#ifndef ARCHQOR_COMMON_DEFS_H_2
#define ARCHQOR_COMMON_DEFS_H_2

//------------------------------------------------------------------------------
namespace nsArch
{

	//------------------------------------------------------------------------------
	// Types of allocation used by MemoryManager::alloc() method.
	enum MEMORY_ALLOC_TYPE
	{	  
		MEMORY_ALLOC_FREEABLE = 0,		// Allocate memory that can be freed by MemoryManager::free() method.	  
		MEMORY_ALLOC_PERMANENT = 1		// Allocate permanent memory that will be never freed.
	};

	//------------------------------------------------------------------------------
	// Assembler error codes.
	enum ERROR_CODE
	{		
		ERROR_NONE = 0,						// No error (success). This is default state and state you want.		
		ERROR_NO_HEAP_MEMORY = 1,			// Memory allocation error (ASMJIT_MALLOC returned NULL).
		ERROR_NO_VIRTUAL_MEMORY = 2,		// Virtual memory allocation error (VirtualMemory returned NULL).
		ERROR_UNKNOWN_INSTRUCTION = 3,		// Unknown instruction. This happens only if instruction code is out of bounds. Shouldn't happen.
		// Illegal instruction, usually generated by nsX86::Cx86CPUCore
		//class when emitting instruction opcode. If this error is generated the
		//target buffer is not affected by this invalid instruction.
		//
		//You can also get this error code if you are under x64 (64-bit x86) and
		//you tried to decode instruction using AH, BH, CH or DH register with REX
		//prefix. These registers can't be accessed if REX prefix is used and assembler
		//didn't check for this situation in intrinsics (Compiler takes care of
		//this and rearrange registers if needed).
		//
		//Examples that will raise ERROR_ILLEGAL_INSTRUCTION error (a is Assembler instance):
		//
		//a.mov(dword_ptr(eax), al); // Invalid address size.
		//a.mov(byte_ptr(r10), ah);  // Undecodable instruction (AH used with r10 which can be encoded only using REX prefix)
		//
		//Note In debug mode you get assertion failure instead of setting error code.
		ERROR_ILLEGAL_INSTRUCTION = 4,		
		ERROR_ILLEGAL_ADDRESING = 5,				// Illegal addressing used (unencodable).
		ERROR_ILLEGAL_SHORT_JUMP = 6,				// Short jump instruction used, but displacement is out of bounds.
		ERROR_NO_FUNCTION = 7,						// No function defined.
		ERROR_INCOMPLETE_FUNCTION = 8,				// Function generation is not finished by using HLA::endFunction() or something bad happened during generation related to function. This can be missing emittable, etc...		
		ERROR_NOT_ENOUGH_REGISTERS = 9,				// Compiler can't allocate registers, because all of them are used. Note Assembler is able to spill registers so this error really shouldn't happen unless all registers have priority 0 (which means never spill).		
		ERROR_REGISTERS_OVERLAP = 10,				// Compiler can't allocate one register to multiple destinations. This error can only happen using special instructions like cmpxchg8b and others where there are more destination operands (implicit).
		ERROR_INCOMPATIBLE_ARGUMENT = 11,			// Tried to call function using incompatible argument.
		ERROR_INCOMPATIBLE_RETURN_VALUE = 12,		// Incompatible return value.
		_ERROR_COUNT								// Count of error codes. Can grow in future.
	};

	//------------------------------------------------------------------------------
	// Emmitable type. The things the HLA can emit into its buffer
	//For each emittable that is used by High Level Assembler its type must be defined.
	//HLA can optimize instruction stream by analyzing emittables and each
	//type is hint for it. The most used emittables are instructions
	enum EMITTABLE_TYPE
	{		
		EMITTABLE_NONE = 0,				// Emittable is invalid (can't be used).
		EMITTABLE_DUMMY,				// Emittable is dummy (used as a mark)
		EMITTABLE_COMMENT,				// Emittable is comment (no code)
		EMITTABLE_EMBEDDED_DATA,		// Emittable is embedded data
		EMITTABLE_ALIGN,				// Emittable is .align directive
		EMITTABLE_VARIABLE_HINT,		// Emittable is variable hint (alloc, spill, use, unuse, ...)
		EMITTABLE_INSTRUCTION,			// Emittable is single instruction
		EMITTABLE_BLOCK,				// Emittable is block of instructions.
		EMITTABLE_FUNCTION,				// Emittable is function declaration
		EMITTABLE_PROLOG,				// Emittable is function prolog
		EMITTABLE_EPILOG,				// Emittable is function epilog
		EMITTABLE_FUNCTION_END,			// Emittable is end of function
		EMITTABLE_TARGET,				// Emittable is target (bound label).
		EMITTABLE_JUMP_TABLE,			// Emittable is jump table
		EMITTABLE_CALL,					// Emittable is function call
		EMITTABLE_RET					// Emittable is return
	};

	//------------------------------------------------------------------------------
	//Constants
	enum 
	{	  
		INVALID_VALUE = 0xFFFFFFFF,				// Invalid operand identifier.
		OPERAND_ID_VALUE_MASK = 0x3FFFFFFF,		// Operand id value mask (part used for IDs).
		OPERAND_ID_TYPE_MASK  = 0xC0000000,		// Operand id type mask (part used for operand type).
		OPERAND_ID_TYPE_LABEL = 0x40000000,		// Label operand mark id.	  
		OPERAND_ID_TYPE_VAR   = 0x80000000,		// Variable operand mark id.
	};

	//------------------------------------------------------------------------------
	enum 
	{  
		FUNC_MAX_ARGS = 32		// Maximum allowed arguments per function declaration / call.
	};

	//------------------------------------------------------------------------------
	// State of variable.
	// Note State of variable is used only during make process and it's not visible to the developer.
	enum VARIABLE_STATE
	{		
		VARIABLE_STATE_UNUSED = 0,			//Variable is currently not used.
		VARIABLE_STATE_REGISTER = 1,		//Variable is currently allocated in register.		
		VARIABLE_STATE_MEMORY = 2			//Variable was spilled from register to memory or variable is used for memory only storage.
	};

	//------------------------------------------------------------------------------
	// Variable alloc mode.
	enum VARIABLE_ALLOC
	{
		// Allocating variable to read only.
		//
		//Read only variables are used to optimize variable spilling. If variable
		//is some time ago deallocated and it's not marked as changed (so it was
		//all the life time read only) then spill is simply NOP (no mov instruction
		//is generated to move it to it's home memory location).
		VARIABLE_ALLOC_READ = 0x01,

		// Allocating variable to write only (overwrite).
		//
		//Overwriting means that if variable is in memory, there is no generated
		//instruction to move variable from memory to register, because that
		//register will be overwritten by next instruction. This is used as a
		//simple optimization to improve generated code by HLA.
		VARIABLE_ALLOC_WRITE = 0x02,

		// Allocating variable to read / write.
		//
		//Variable allocated for read / write is marked as changed. This means that
		//if variable must be later spilled into memory, mov (or similar)
		//instruction will be generated.
		VARIABLE_ALLOC_READWRITE = 0x03,
		VARIABLE_ALLOC_REGISTER = 0x04,				// Variable can be allocated in register.
		VARIABLE_ALLOC_MEMORY = 0x08,				// Variable can be allocated in memory.
		VARIABLE_ALLOC_UNUSE_AFTER_USE = 0x10,		// Unuse the variable after use.
		VARIABLE_ALLOC_SPECIAL = 0x20				// Variable can be allocated only to one register (special allocation).
	};

	//------------------------------------------------------------------------------
	// Variable allocation policy.
	//
	//Variable allocation method is used by HLA and it means if HLA
	//should first allocate preserved registers or not. Preserved registers are
	//registers that must be saved / restored by generated function.
	//
	//This option is for people who are calling C/C++ functions from JIT code so
	//Compiler can recude generating push/pop sequences before and after call,
	//respectively.
	enum VARIABLE_ALLOC_POLICY
	{
		VARIABLE_ALLOC_PRESERVED_FIRST = 0,		// Allocate preserved registers first.		
		VARIABLE_ALLOC_PRESERVED_LAST = 1		// Allocate preserved registers last (default).
	};

	//------------------------------------------------------------------------------
	// Function hints.
	enum FUNCTION_HINT
	{		
		FUNCTION_HINT_PUSH_POP_SEQUENCE = 0,		// Use push/pop sequences instead of mov sequences in function prolog and epilog.
		FUNCTION_HINT_NAKED = 1,					// Make naked function (without using ebp/erp in prolog / epilog).
		FUNCTION_HINT_EMMS = 2,						// Add emms instruction to the function epilog.
		FUNCTION_HINT_SFENCE = 3,					// Add sfence instruction to the function epilog.
		FUNCTION_HINT_LFENCE = 4					// Add lfence instruction to the function epilog.
	};

	//------------------------------------------------------------------------------
	// Variable hint
	enum VARIABLE_HINT
	{
		VARIABLE_HINT_ALLOC = 0,				// Alloc variable.		
		VARIABLE_HINT_SPILL = 1,				// Spill variable.
		VARIABLE_HINT_SAVE = 2,					// Save variable if modified.
		VARIABLE_HINT_SAVE_AND_UNUSE = 3,		// Save variable if modified and mark it as unused.
		VARIABLE_HINT_UNUSE = 4					// Mark variable as unused.
	};

	//------------------------------------------------------------------------------
	// Variable type.
	enum VARIABLE_TYPE
	{
		VARIABLE_TYPE_GPD = 0,			// Variable is 32-bit general purpose register.
		VARIABLE_TYPE_GPQ = 1,			// Variable is 64-bit general purpose register.
		
#if	( QOR_ARCH_WORDSIZE == 32 )			// Variable is system wide general purpose register (32-bit or 64-bit).
		VARIABLE_TYPE_GPN = VARIABLE_TYPE_GPD,		
#else
		VARIABLE_TYPE_GPN = VARIABLE_TYPE_GPQ,
#endif
	
		//x86 specific variable types

		VARIABLE_TYPE_X87 = 2,			// Variable is X87 (FPU).		
		VARIABLE_TYPE_X87_1F = 3,		// Variable is X87 (FPU) SP-FP number (float).		
		VARIABLE_TYPE_X87_1D = 4,		// Variable is X87 (FPU) DP-FP number (double).
		VARIABLE_TYPE_MM = 5,			// Variable is MM register / memory location.
		VARIABLE_TYPE_XMM = 6,			// Variable is XMM register / memory location.
		VARIABLE_TYPE_XMM_1F = 7,		// Variable is SSE scalar SP-FP number.
		VARIABLE_TYPE_XMM_4F = 8,		// Variable is SSE packed SP-FP number (4 floats).
		VARIABLE_TYPE_XMM_1D = 9,		// Variable is SSE2 scalar DP-FP number.
		VARIABLE_TYPE_XMM_2D = 10,		// Variable is SSE2 packed DP-FP number (2 doubles).
		_VARIABLE_TYPE_COUNT = 11,		// Count of variable types.

		VARIABLE_TYPE_INT32 = VARIABLE_TYPE_GPD,		// Variable is 32-bit integer.
		VARIABLE_TYPE_INT64 = VARIABLE_TYPE_GPQ,		// Variable is 64-bit integer.
		VARIABLE_TYPE_INTPTR = VARIABLE_TYPE_GPN,		// Variable is system dependent integer / pointer.

#	if	( QOR_ARCH_WORDSIZE == 32 )
		VARIABLE_TYPE_FLOAT = VARIABLE_TYPE_X87_1F,		// Variable is SP-FP (x87 or xmm).
		VARIABLE_TYPE_DOUBLE = VARIABLE_TYPE_X87_1D		// Variable is DP-FP (x87 or xmm).
#	else
		VARIABLE_TYPE_FLOAT = VARIABLE_TYPE_XMM_1F,
		VARIABLE_TYPE_DOUBLE = VARIABLE_TYPE_XMM_1D
#	endif

	};

}//nsArch

#endif//ARCHQOR_COMMON_DEFS_H_2
