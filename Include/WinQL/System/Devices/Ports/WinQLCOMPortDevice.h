//WinQLCOMPortDevice.h

// Copyright Querysoft Limited 2013, 2017
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

//Win32 COM Port Device

#ifndef WINQL_DEVICE_COMPORT_H_3
#define WINQL_DEVICE_COMPORT_H_3

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterface.h"
#include "WinQL/System/Devices/WinQLIODevice.h"

__QOR_DECLARE_REF(nsWin32, __WINQL, CCOMPortDevice, CTExtRef);

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE( __WINQL ) CCOMPortDevice : public CDeviceInterface
	{
	public:

		__QOR_DECLARE_REF_TYPE(CCOMPortDevice);
		__QOR_DECLARE_OCLASS_ID( CCOMPortDevice );

		static nsCodeQOR::CTExternalRegEntry< CCOMPortDevice > RegEntry;

		CCOMPortDevice();
		virtual ~CCOMPortDevice();
		
	private:

		CCOMPortDevice( const CCOMPortDevice& src );
		CCOMPortDevice& operator = ( const CCOMPortDevice& src );
/*
case IOCTL_SERIAL_SET_BAUD_RATE : return "IOCTL_SERIAL_SET_BAUD_RATE";
case IOCTL_SERIAL_GET_BAUD_RATE: return "IOCTL_SERIAL_GET_BAUD_RATE";
case IOCTL_SERIAL_GET_MODEM_CONTROL: return "IOCTL_SERIAL_GET_MODEM_CONTROL";
case IOCTL_SERIAL_SET_MODEM_CONTROL: return "IOCTL_SERIAL_SET_MODEM_CONTROL";
case IOCTL_SERIAL_SET_FIFO_CONTROL: return "IOCTL_SERIAL_SET_FIFO_CONTROL";
case IOCTL_SERIAL_SET_LINE_CONTROL: return "IOCTL_SERIAL_SET_LINE_CONTROL";
case IOCTL_SERIAL_GET_LINE_CONTROL: return "IOCTL_SERIAL_GET_LINE_CONTROL";
case IOCTL_SERIAL_SET_TIMEOUTS: return "IOCTL_SERIAL_SET_TIMEOUTS";
case IOCTL_SERIAL_GET_TIMEOUTS: return "IOCTL_SERIAL_GET_TIMEOUTS";
case IOCTL_SERIAL_SET_CHARS: return "IOCTL_SERIAL_SET_CHARS";
case IOCTL_SERIAL_GET_CHARS: return "IOCTL_SERIAL_GET_CHARS";
case IOCTL_SERIAL_SET_DTR: return "IOCTL_SERIAL_SET_DTR";
case IOCTL_SERIAL_CLR_DTR: return "IOCTL_SERIAL_SET_DTR";
case IOCTL_SERIAL_RESET_DEVICE: return "IOCTL_SERIAL_RESET_DEVICE";
case IOCTL_SERIAL_SET_RTS: return "IOCTL_SERIAL_SET_RTS";
case IOCTL_SERIAL_CLR_RTS: return "IOCTL_SERIAL_CLR_RTS";
case IOCTL_SERIAL_SET_XOFF: return "IOCTL_SERIAL_SET_XOFF";
case IOCTL_SERIAL_SET_XON: return "IOCTL_SERIAL_SET_XON";
case IOCTL_SERIAL_SET_BREAK_ON: return "IOCTL_SERIAL_SET_BREAK_ON";
case IOCTL_SERIAL_SET_BREAK_OFF: return "IOCTL_SERIAL_SET_BREAK_OFF";
case IOCTL_SERIAL_SET_QUEUE_SIZE: return "IOCTL_SERIAL_SET_QUEUE_SIZE";
case IOCTL_SERIAL_GET_WAIT_MASK: return "IOCTL_SERIAL_GET_WAIT_MASK";
case IOCTL_SERIAL_SET_WAIT_MASK: return "IOCTL_SERIAL_SET_WAIT_MASK";
case IOCTL_SERIAL_WAIT_ON_MASK: return "IOCTL_SERIAL_WAIT_ON_MASK";
case IOCTL_SERIAL_IMMEDIATE_CHAR: return "IOCTL_SERIAL_IMMEDIATE_CHAR";
case IOCTL_SERIAL_PURGE: return "IOCTL_SERIAL_PURGE";
case IOCTL_SERIAL_GET_HANDFLOW: return "IOCTL_SERIAL_GET_HANDFLOW";
case IOCTL_SERIAL_SET_HANDFLOW: return "IOCTL_SERIAL_SET_HANDFLOW";
case IOCTL_SERIAL_GET_MODEMSTATUS: return "IOCTL_SERIAL_GET_MODEMSTATUS";
case IOCTL_SERIAL_GET_DTRRTS: return "IOCTL_SERIAL_GET_DTRRTS";
case IOCTL_SERIAL_GET_COMMSTATUS: return "IOCTL_SERIAL_GET_COMMSTATUS";
case IOCTL_SERIAL_GET_PROPERTIES: return "IOCTL_SERIAL_GET_PROPERTIES";
case IOCTL_SERIAL_XOFF_COUNTER: return "IOCTL_SERIAL_XOFF_COUNTER";
case IOCTL_SERIAL_LSRMST_INSERT: return "IOCTL_SERIAL_LSRMST_INSERT";
case IOCTL_SERIAL_CONFIG_SIZE: return "IOCTL_SERIAL_CONFIG_SIZE";
case IOCTL_SERIAL_GET_STATS: return "IOCTL_SERIAL_GET_STATS";
case IOCTL_SERIAL_CLEAR_STATS: return "IOCTL_SERIAL_CLEAR_STATS";
*/
	};

}//nsWin32

#endif//WINQL_DEVICE_COMPORT_H_3

