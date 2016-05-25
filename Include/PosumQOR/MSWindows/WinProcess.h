//WinProcess.h

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

//Posum Process for Windows

#ifndef POSUMQOR_WINPROCESS_H_3
#define POSUMQOR_WINPROCESS_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/DataTypes/GUID.h"
#include "CodeQOR/ClassReg/ClassRegEntry.h"

#include "PosumQOR/Process.h"


//--------------------------------------------------------------------------------
namespace nsWinPosum
{

	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __POSUMQOR ) CProcess : public nsPosum::CProcess
	{

	public:

		__QOR_DECLARE_OCLASS_ID( CProcess );

		CProcess();
		virtual ~CProcess();		

		virtual uid_t GetEffectiveUserID( void );									//Get the user Id of the process
		virtual pid_t GetID( void );												//Get Process ID
		virtual pid_t GetGroupID( pid_t ProcessID );								//Get Process Group ID
		virtual pid_t GetSessionLeaderID( pid_t ProcessID );						//Get Session Leader Process ID

	protected:

	private:
		
	};

}//nsWinPosum

#endif//POSUMQOR_WINPROCESS_H_3
