//Library.h

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

#ifndef WINQAPI_LIB_H_1
#define WINQAPI_LIB_H_1

#include "CodeQOR/ErrorSystem/Error.h"
#include "../SystemQOR/MSWindows/WinQAPI/include/ErrorDomain.h"

//------------------------------------------------------------------------------
__QCMP_WARNING_PUSH
__QCMP_WARNING_DISABLE( __QCMP_WARN_UNINIT_LOCAL_VAR_USED, "Warning suppressed because we will raise a runtime error before it becomes relevant." )

namespace nsWinQAPI
{

	//------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQAPI ) CLibrary
	{
	public:

		typedef int( *DefProc )( void );//Default procedure pointer type

		//------------------------------------------------------------------------------
		template< typename ret >
		ret Call( const DefProc pProc ) const
		{
			typedef ret( *fPtr )(void);

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)();
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_SERIOUS );
			}
		}

		//------------------------------------------------------------------------------
		void voidCallvoid( const DefProc pProc ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( void );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)();
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename param1 >
		void voidCall( const DefProc pProc, param1 P1 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1 >
		ret Call( const DefProc pProc, param1 P1 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename param1, typename param2 >
		void voidCall( const DefProc pProc, param1 P1, param2 P2 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1, P2 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2 >
		ret Call( const DefProc pProc, param1 P1, param2 P2 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename param1, typename param2, typename param3 >
		void voidCall( const DefProc pProc, param1 P1, param2 P2, param3 P3 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1, P2, P3 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename param1, typename param2, typename param3, typename param4 >
		void voidCall( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1, P2, P3, P4 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename param1, typename param2, typename param3, typename param4, typename param5 >
		void voidCall( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1, P2, P3, P4, P5 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename param1, typename param2, typename param3, typename param4, typename param5, typename param6 >
		void voidCall( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1, P2, P3, P4, P5, P6 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7 >
		void voidCall( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7 ) const
		{
			typedef void( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				(FP)( P1, P2, P3, P4, P5, P6, P7 );
			}
			else
			{
				nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );
			}
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11, typename param12 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11, param12 P12 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11, typename param12, typename param13 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11, param12 P12, param13 P13 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12, param13 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11, typename param12, typename param13, typename param14 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11, param12 P12, param13 P13, param14 P14 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12, param13, param14 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11, typename param12, typename param13, typename param14, typename param15 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11, param12 P12, param13 P13, param14 P14, param15 P15 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12, param13, param14, param15 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11, typename param12, typename param13, typename param14, typename param15 , typename param16 >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11, param12 P12, param13 P13, param14 P14, param15 P15 , param16 P16 ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12, param13, param14, param15, param16 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

		//------------------------------------------------------------------------------
		template< typename ret, typename param1, typename param2, typename param3, typename param4, typename param5, typename param6, typename param7, typename param8, typename param9, typename param10, typename param11, typename param12, typename param13, typename param14, typename param15, typename param16, typename param17  >
		ret Call( const DefProc pProc, param1 P1, param2 P2, param3 P3, param4 P4, param5 P5, param6 P6, param7 P7, param8 P8, param9 P9, param10 P10, param11 P11, param12 P12, param13 P13, param14 P14, param15 P15, param16 P16, param17 P17  ) const
		{
			typedef ret( __QCMP_STDCALLCONVENTION *fPtr )( param1, param2, param3, param4, param5, param6, param7, param8, param9, param10, param11, param12, param13, param14, param15, param16, param17 );

			fPtr FP = reinterpret_cast< fPtr >( pProc );

			if( FP != 0 )
			{
				return (FP)( P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17 );
			}

			nsCodeQOR::CError::Raise( nsWinQAPI::MISSING_LIBRARY_FUNCTION, nsWinQAPI::ErrorDomainPtr(), nsCodeQOR::CError::ERR_LVL_CONTINUE );

			ret R1;
			return R1;
		}

	};

__QCMP_WARNING_POP

}//nsWinQAPI

#endif//WINQAPI_LIB_H_1
