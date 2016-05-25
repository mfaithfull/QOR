//WinQLThreadImpl.h

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

//Microsoft Windows compatible implementation of generic Thread class

#ifndef WINQL_CS_THREADIMPL_H_1
#define WINQL_CS_THREADIMPL_H_1

#include "SystemQOR.h"
#include "CodeQOR/Threading/ThreadContext.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CThreadImpl : public nsCodeQOR::CThreadContextBase
	{
	public:

		CThreadImpl();
		virtual ~CThreadImpl();

#if     ( ( __QCMP_COMPILER != __QCMP_MSVC ) && ( __QCMP_COMPILER != __QCMP_INTEL ) )
		virtual void* CurrentException( void );
#else
		virtual nsCompiler::EH::ExceptData& CurrentException( void );
#endif//__MINGW32__

		virtual int& ProcessingThrow( void );
		virtual void*& FrameInfoChain( void );

	private:

#if     ( __QCMP_COMPILER == __QCMP_MSVC || __QCMP_COMPILER == __QCMP_INTEL )
		nsCompiler::EH::ExceptData m_ExceptData;
#endif//( __QCMP_COMPILER == __QCMP_MSVC )

		int m_iProcessingThrow;
		void* m_pFrameInfoChain;
		void* m_pImpl;
	};

}//nswin32

#endif//WINQL_CS_THREADIMPL_H_1
