//TFlyer.h

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

//The template for a flyer

#ifndef CODEQOR_TFLYER_H_1
#define CODEQOR_TFLYER_H_1

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "TFlyerRegEntry.h"

//------------------------------------------------------------------------------
namespace nsCodeQOR
{
	//------------------------------------------------------------------------------	
	template< class T, class Base >
	class __QOR_INTERFACE( __CODEQOR ) CTFlyer : public Base
	{

	protected:
		
		friend class CTFlyerRegEntry< T >;					//Give the registry entry access to the protected members here
		typedef Base _tBase;								//The registry entry needs to be able to determine the Base type so give it a typedef it can access
		Base* m_pPrevious;									//Every Flyer instance must record which instance it replaces

	public:
	
		static sTOB< CTFlyerRegEntry< T > > RegEntry;		//The one Registry entry for all Flyers of this type

		//------------------------------------------------------------------------------
		static sTOB< CTFlyerRegEntry< T > >& GetRegEntry( void )
		{
			sTOB< CTFlyerRegEntry< T > >& ref = CTFlyer< T, Base >::RegEntry;
			return ref;
		}

		//------------------------------------------------------------------------------	
		CTFlyer() : m_pPrevious( 0 )
		{			
			//When a Flyer is constructed configure the 
			//Registry entry to return this one as the
			//instance. Think of this as a Push			
			GetRegEntry()->Configure( (T*)this );
		}

		//------------------------------------------------------------------------------	
		virtual ~CTFlyer()
		{
			//When a Flyer is destructed configure the
			//Registry entry to return the previous
			//flyer instance. Think of this as a Pop			
			GetRegEntry()->Unconfigure( (T*)this );
		}
 
	};

}//nsCodeQOR

#endif//CODEQOR_TFLYER_H_1


