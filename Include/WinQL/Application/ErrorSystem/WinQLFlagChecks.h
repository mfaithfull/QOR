//WinQLFlagChecks.h

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

#ifndef WINQL_CS_ERR_FLAGCHECKS_H_2
#define WINQL_CS_ERR_FLAGCHECKS_H_2

//--------------------------------------------------------------------------------
namespace nsParamChecking
{
	/*
	//--------------------------------------------------------------------------------
	class CRangeCheck
	{
	public:
		static void Check( unsigned long dwVal, unsigned long dwMin, unsigned long dwMax );
	};
	*/
};//namespace nsParamChecking

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	namespace nsParamCheck
	{
		//--------------------------------------------------------------------------------
		//No additional checking is needed
		class __QOR_INTERFACE( __WINQL ) CNoCheck
		{
		public:
			template< typename tchk >
			static void Check( tchk /*TODO: t*/ ){ }
		};

		//--------------------------------------------------------------------------------		
		class __QOR_INTERFACE( __WINQL ) CEventFlagsCheck
		{
		public:	
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------		
		class __QOR_INTERFACE( __WINQL ) CEventSyncAccessFlagsCheck
		{
		public:	
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CMutexAccessFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CSemaphoreAccessFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CTQTCreateFlagsCheck
		{
		public:
			static void Check( unsigned long ulFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CWaitTmrCreateFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CSybcObjAccessFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CCritSecCreateFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CInitOnceBeginFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CInitOnceCompleteFlagsCheck
		{
		public:
			static void Check( unsigned long dwFlags );
		};

		//--------------------------------------------------------------------------------
		class __QOR_INTERFACE( __WINQL ) CRgstrWaitFlagsCheck
		{
		public:
			static void Check( unsigned long ulFlags );
		};	

	}//nsParamCheck

}//nsWin32

#endif//WINQL_CS_ERR_FLAGCHECKS_H_2
