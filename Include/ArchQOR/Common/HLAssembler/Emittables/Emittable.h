//Emittable.h

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

#ifndef ARCHQOR_COMMON_EMITTABLE_H_2
#define ARCHQOR_COMMON_EMITTABLE_H_2

#include "CompilerQOR.h"
#include "../BaseVarData.h"
#include "CodeQOR/DataTypes/GUID.h"
#include "CodeQOR/Macros/ClassIdentityMacros.h"

//------------------------------------------------------------------------------
namespace nsArch
{
	class __QOR_INTERFACE( __ARCHQOR ) CHighLevelAssemblerBase;
	class __QOR_INTERFACE( __ARCHQOR ) CHLAssemblerContextBase;

	//------------------------------------------------------------------------------
	// CEmittable is object that can emit single or more instructions. To
	// create your custom emittable it's needed to override the abstract virtual
	// method emit().
	//
	// When you are finished serializing instructions to the HLA and you
	// call make(), it will first call prepare() method for each
	// emittable in list, then translate(), emit() and post() is the last.
	// Prepare can be used to calculate something that can be only calculated when
	// emitting instructions is finished (for example Function uses prepare()
	// to relocate memory home for all memory/spilled variables). The emit() should 
	// be used to emit instruction or multiple instructions into Assembler stream,
	// and the post() is here to allow emitting embedded data (after function
	// declaration), etc.
	class __QOR_INTERFACE( __ARCHQOR ) CEmittable
	{
	public:

		__QOR_DECLARE_OCLASS_ID(CEmittable);

		// Create new emittable. Never create Emittable by new operator or on the stack, use newObject template to do that.
		CEmittable( nsArch::CHighLevelAssemblerBase* c, Cmp_unsigned__int32 type ) __QCMP_THROW;
		CEmittable( const CEmittable& src ) __QCMP_THROW;
		CEmittable& operator = ( const CEmittable& src ) __QCMP_THROW;

		// Destroy emittable.
		// Note Never destroy emittable using delete keyword, High Level Assembler
		// manages all emittables in internal memory pool and it will destroy all emittables after you destroy it.
		virtual ~CEmittable() __QCMP_THROW;

		//Emit and Helpers
		virtual void prepare( CHLAssemblerContextBase& cc ) __QCMP_THROW;			// Step 1. Extract emittable variables, update statistics, ...
		virtual CEmittable* translate( CHLAssemblerContextBase& cc ) __QCMP_THROW;	// Step 2. Translate instruction, alloc variables, ...
		virtual void emit( CHighLevelAssemblerBase& a ) __QCMP_THROW;				// Step 3. Emit to Assembler.
		virtual void post( CHighLevelAssemblerBase& a ) __QCMP_THROW;				// Step 4. Last post step (verify, add data, etc).
		
		virtual int getMaxSize() const __QCMP_THROW;								// Get maximum size in bytes of this emittable (in binary).		
		virtual bool tryUnuseVar( CommonVarData* v ) __QCMP_THROW;					// Try to unuse the variable. Returns true only if the variable will be unused by the instruction, otherwise false is returned.

		//------------------------------------------------------------------------------
		inline nsArch::CHighLevelAssemblerBase* getHLA() const __QCMP_THROW			// Get associated HLA instance.
		{ 
			return m_pHLAssembler; 
		}

		//------------------------------------------------------------------------------
		// Get emittable type, see EMITTABLE_TYPE.
		inline Cmp_unsigned__int32 getType() const __QCMP_THROW 
		{ 
			return m_ucType; 
		}

		//------------------------------------------------------------------------------
		// Get whether the emittable was translated.
		inline Cmp_unsigned__int8 isTranslated() const __QCMP_THROW 
		{ 
			return m_ucTranslated; 
		}

		//------------------------------------------------------------------------------
		// Get emittable offset in the stream
		// Emittable offset is not byte offset, each emittable increments offset by 1
		// and this value is then used by register allocator. Emittable offset is
		// set by compiler by the register allocator, don't use it in your code.
		inline Cmp_unsigned__int32 getOffset() const __QCMP_THROW 
		{ 
			return m_uiOffset; 
		}

		//------------------------------------------------------------------------------
		inline Cmp_unsigned__int32 setOffset( Cmp_unsigned__int32 uiOffset ) __QCMP_THROW
		{
			m_uiOffset = uiOffset;
			return m_uiOffset;
		}			

		//Emittables List

		//------------------------------------------------------------------------------
		// Get previous emittable in list.
		inline CEmittable* getPrev() const __QCMP_THROW 
		{ 
			return m_pPrev; 
		}

		//------------------------------------------------------------------------------
		inline void setPrev( CEmittable* pPrev ) __QCMP_THROW
		{
			m_pPrev = pPrev;
		}

		//------------------------------------------------------------------------------
		// Get next emittable in list.
		inline CEmittable* getNext() const __QCMP_THROW 
		{ 
			return m_pNext; 
		}

		//------------------------------------------------------------------------------
		inline void setNext( CEmittable* pNext ) __QCMP_THROW
		{
			m_pNext = pNext;
		}

		//------------------------------------------------------------------------------
		// Get comment string.
		inline const char* getComment() const __QCMP_THROW 
		{ 
			return m_szComment; 
		}

		void setComment( const char* str ) __QCMP_THROW;			// Set comment string to str.
		void setCommentF( const char* fmt, ... ) __QCMP_THROW;		// Format comment string using fmt string and variable argument list.

	protected:		

		//------------------------------------------------------------------------------
		// Mark emittable as translated and return next.
		inline CEmittable* translated() __QCMP_THROW
		{
			m_ucTranslated = true;
			return m_pNext;
		}

		nsArch::CHighLevelAssemblerBase* m_pHLAssembler;	// High Level Assembler where this emittable is connected to.
		Cmp_unsigned__int8 m_ucType;						// Type of emittable, see EMITTABLE_TYPE.
		Cmp_unsigned__int8 m_ucTranslated;					// Whether the emittable was translated, see translate().
		Cmp_unsigned__int8 m_ucReserved0;					// Reserved flags for future use.
		Cmp_unsigned__int8 m_ucReserved1;					// Reserved flags for future use.
		Cmp_unsigned__int32 m_uiOffset;						// Emittable offset.
		CEmittable* m_pPrev;								// Previous emittable.
		CEmittable* m_pNext;								// Next emittable.
		const char* m_szComment;							// Embedded comment string (also used by a Comment emittable).

	};

}//nsArch

#endif//ARCHQOR_COMMON_EMITTABLE_H_2