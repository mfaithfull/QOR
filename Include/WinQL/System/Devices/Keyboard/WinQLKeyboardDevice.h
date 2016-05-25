//WinQLKeyboardDevice.h

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

//Win32 Keyboard Device

#ifndef WINQL_DEVICE_KEYBOARD_H_3
#define WINQL_DEVICE_KEYBOARD_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "WinQL/System/Devices/Interfaces/WinQLDeviceInterface.h"
#include "WinQL/System/Devices/WinQLIODevice.h"
#include "WinQL/System/Devices/Instances/WinQLDeviceInstance.h"
#include "WinQL/System/Devices/Keyboard/WinQLKeyboardInput.h"
#include "WinQL/CodeServices/WinQLSharedRef.h"

//--------------------------------------------------------------------------------
namespace nsWin32
{
	//--------------------------------------------------------------------------------
	class __QOR_INTERFACE(__WINQL) CKeyboard : public CDeviceInterface
	{

		QOR_PP_WINQL_SHARED;

	public:
		
		typedef CSharedRef< CKeyboard > refType;

		__QOR_DECLARE_OCLASS_ID( CKeyboard );

		static nsCodeQOR::CTExternalRegEntry< CKeyboard > RegEntry;

		//--------------------------------------------------------------------------------
		enum eKeyboardFunctions
		{
			Query_Attributes = 0x00,
			Query_Indicators = 0x10,
		};

		//--------------------------------------------------------------------------------
		struct Keyboard_ID
		{
			unsigned char Type;       // Keyboard type
			unsigned char Subtype;    // Keyboard subtype (OEM-dependent value)
		};

		//--------------------------------------------------------------------------------
		struct Keyboard_Typematic_Parameters
		{
			unsigned short m_UnitId;	// Unit identifier.  Specifies the device unit for which this request is intended.
			unsigned short m_Rate;		// Typematic rate, in repeats per second.
			unsigned short Delay;		// Typematic delay, in milliseconds.

		};

		//--------------------------------------------------------------------------------
		struct Keyboard_Attributes
		{
			Keyboard_ID m_KeyboardIdentifier;		// Keyboard ID value.  Used to distinguish between keyboard types.
			unsigned short KeyboardMode;			// Scan code mode.
			unsigned short NumberOfFunctionKeys;	// Number of function keys located on the keyboard.
			unsigned short NumberOfIndicators;		// Number of LEDs located on the keyboard.
			unsigned short NumberOfKeysTotal;		// Total number of keys located on the keyboard.
			unsigned long InputDataQueueLength;		// Length of the typeahead buffer, in bytes.
			Keyboard_Typematic_Parameters KeyRepeatMinimum;	// Minimum allowable values of keyboard typematic rate and delay.
			Keyboard_Typematic_Parameters KeyRepeatMaximum;	// Maximum allowable values of keyboard typematic rate and delay.
		};

		//--------------------------------------------------------------------------------
		struct Keyboard_Indicators
		{
			unsigned short UnitId;			// Unit identifier.  Specifies the device unit for which this request is intended.
			unsigned short LedFlags;		// LED indicator state.

		};

		__QCMP_STATIC_CONSTANT(unsigned long, File_Device_Keyboard = 0x0000000b);

		//Virtual Keys
		__QCMP_STATIC_CONSTANT(int, vkLBUTTON = 0x01);

		__QCMP_STATIC_CONSTANT(int, vkRBUTTON = 0x02);
		__QCMP_STATIC_CONSTANT(int, vkCANCEL = 0x03);
		__QCMP_STATIC_CONSTANT(int, vkMBUTTON = 0x04);    // NOT contiguous with L & RBUTTON

#if(_WIN32_WINNT >= 0x0500)
		__QCMP_STATIC_CONSTANT(int, vkXBUTTON1 = 0x05);    // NOT contiguous with L & RBUTTON
		__QCMP_STATIC_CONSTANT(int, vkXBUTTON2 = 0x06);    // NOT contiguous with L & RBUTTON
#endif /* _WIN32_WINNT >= 0x0500 */

		//0x07 : unassigned

		__QCMP_STATIC_CONSTANT(int, vkBACK = 0x08);
		__QCMP_STATIC_CONSTANT(int, vkTAB = 0x09);

		//0x0A - 0x0B : reserved

		__QCMP_STATIC_CONSTANT(int, vkCLEAR = 0x0C);
		__QCMP_STATIC_CONSTANT(int, vkRETURN = 0x0D);

		__QCMP_STATIC_CONSTANT(int, vkSHIFT = 0x10);
		__QCMP_STATIC_CONSTANT(int, vkCONTROL = 0x11);
		__QCMP_STATIC_CONSTANT(int, vkMENU = 0x12);
		__QCMP_STATIC_CONSTANT(int, vkPAUSE = 0x13);
		__QCMP_STATIC_CONSTANT(int, vkCAPITAL = 0x14);

		__QCMP_STATIC_CONSTANT(int, vkKANA = 0x15);
		__QCMP_STATIC_CONSTANT(int, vkHANGEUL = 0x15); // old name for compatibility
		__QCMP_STATIC_CONSTANT(int, vkHANGUL = 0x15);
		__QCMP_STATIC_CONSTANT(int, vkJUNJA = 0x17);
		__QCMP_STATIC_CONSTANT(int, vkFINAL = 0x18);
		__QCMP_STATIC_CONSTANT(int, vkHANJA = 0x19);
		__QCMP_STATIC_CONSTANT(int, vkKANJI = 0x19);

		__QCMP_STATIC_CONSTANT(int, vkESCAPE = 0x1B);

		__QCMP_STATIC_CONSTANT(int, vkCONVERT = 0x1C);
		__QCMP_STATIC_CONSTANT(int, vkNONCONVERT = 0x1D);
		__QCMP_STATIC_CONSTANT(int, vkACCEPT = 0x1E);
		__QCMP_STATIC_CONSTANT(int, vkMODECHANGE = 0x1F);

		__QCMP_STATIC_CONSTANT(int, vkSPACE = 0x20);
		__QCMP_STATIC_CONSTANT(int, vkPRIOR = 0x21);
		__QCMP_STATIC_CONSTANT(int, vkNEXT = 0x22);
		__QCMP_STATIC_CONSTANT(int, vkEND = 0x23);
		__QCMP_STATIC_CONSTANT(int, vkHOME = 0x24);
		__QCMP_STATIC_CONSTANT(int, vkLEFT = 0x25);
		__QCMP_STATIC_CONSTANT(int, vkUP = 0x26);
		__QCMP_STATIC_CONSTANT(int, vkRIGHT = 0x27);
		__QCMP_STATIC_CONSTANT(int, vkDOWN = 0x28);
		__QCMP_STATIC_CONSTANT(int, vkSELECT = 0x29);
		__QCMP_STATIC_CONSTANT(int, vkPRINT = 0x2A);
		__QCMP_STATIC_CONSTANT(int, vkEXECUTE = 0x2B);
		__QCMP_STATIC_CONSTANT(int, vkSNAPSHOT = 0x2C);
		__QCMP_STATIC_CONSTANT(int, vkINSERT = 0x2D);
		__QCMP_STATIC_CONSTANT(int, vkDELETE = 0x2E);
		__QCMP_STATIC_CONSTANT(int, vkHELP = 0x2F);

		/* vk0 - vk9 are the same as ASCII '0' - '9' (0x30 - 0x39)
		* 0x40 : unassigned
		* vkA - vkZ are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
		*/

		__QCMP_STATIC_CONSTANT(int, vkLWIN = 0x5B);
		__QCMP_STATIC_CONSTANT(int, vkRWIN = 0x5C);
		__QCMP_STATIC_CONSTANT(int, vkAPPS = 0x5D);

		//0x5E : reserved

		__QCMP_STATIC_CONSTANT(int, vkSLEEP = 0x5F);

		__QCMP_STATIC_CONSTANT(int, vkNUMPAD0 = 0x60);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD1 = 0x61);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD2 = 0x62);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD3 = 0x63);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD4 = 0x64);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD5 = 0x65);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD6 = 0x66);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD7 = 0x67);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD8 = 0x68);
		__QCMP_STATIC_CONSTANT(int, vkNUMPAD9 = 0x69);
		__QCMP_STATIC_CONSTANT(int, vkMULTIPLY = 0x6A);
		__QCMP_STATIC_CONSTANT(int, vkADD = 0x6B);
		__QCMP_STATIC_CONSTANT(int, vkSEPARATOR = 0x6C);
		__QCMP_STATIC_CONSTANT(int, vkSUBTRACT = 0x6D);
		__QCMP_STATIC_CONSTANT(int, vkDECIMAL = 0x6E);
		__QCMP_STATIC_CONSTANT(int, vkDIVIDE = 0x6F);
		__QCMP_STATIC_CONSTANT(int, vkF1 = 0x70);
		__QCMP_STATIC_CONSTANT(int, vkF2 = 0x71);
		__QCMP_STATIC_CONSTANT(int, vkF3 = 0x72);
		__QCMP_STATIC_CONSTANT(int, vkF4 = 0x73);
		__QCMP_STATIC_CONSTANT(int, vkF5 = 0x74);
		__QCMP_STATIC_CONSTANT(int, vkF6 = 0x75);
		__QCMP_STATIC_CONSTANT(int, vkF7 = 0x76);
		__QCMP_STATIC_CONSTANT(int, vkF8 = 0x77);
		__QCMP_STATIC_CONSTANT(int, vkF9 = 0x78);
		__QCMP_STATIC_CONSTANT(int, vkF10 = 0x79);
		__QCMP_STATIC_CONSTANT(int, vkF11 = 0x7A);
		__QCMP_STATIC_CONSTANT(int, vkF12 = 0x7B);
		__QCMP_STATIC_CONSTANT(int, vkF13 = 0x7C);
		__QCMP_STATIC_CONSTANT(int, vkF14 = 0x7D);
		__QCMP_STATIC_CONSTANT(int, vkF15 = 0x7E);
		__QCMP_STATIC_CONSTANT(int, vkF16 = 0x7F);
		__QCMP_STATIC_CONSTANT(int, vkF17 = 0x80);
		__QCMP_STATIC_CONSTANT(int, vkF18 = 0x81);
		__QCMP_STATIC_CONSTANT(int, vkF19 = 0x82);
		__QCMP_STATIC_CONSTANT(int, vkF20 = 0x83);
		__QCMP_STATIC_CONSTANT(int, vkF21 = 0x84);
		__QCMP_STATIC_CONSTANT(int, vkF22 = 0x85);
		__QCMP_STATIC_CONSTANT(int, vkF23 = 0x86);
		__QCMP_STATIC_CONSTANT(int, vkF24 = 0x87);

		//0x88 - 0x8F : unassigned

		__QCMP_STATIC_CONSTANT(int, vkNUMLOCK = 0x90);
		__QCMP_STATIC_CONSTANT(int, vkSCROLL = 0x91);

		//NEC PC-9800 kbd definitions

		__QCMP_STATIC_CONSTANT(int, vkOEM_NEC_EQUAL = 0x92);  // '=' key on numpad

		//Fujitsu/OASYS kbd definitions

		__QCMP_STATIC_CONSTANT(int, vkOEM_FJ_JISHO = 0x92);  // 'Dictionary' key
		__QCMP_STATIC_CONSTANT(int, vkOEM_FJ_MASSHOU = 0x93);  // 'Unregister word' key
		__QCMP_STATIC_CONSTANT(int, vkOEM_FJ_TOUROKU = 0x94);  // 'Register word' key
		__QCMP_STATIC_CONSTANT(int, vkOEM_FJ_LOYA = 0x95);  // 'Left OYAYUBI' key
		__QCMP_STATIC_CONSTANT(int, vkOEM_FJ_ROYA = 0x96);  // 'Right OYAYUBI' key

		//0x97 - 0x9F : unassigned

		/* vkL* & vkR* - left and right Alt, Ctrl and Shift virtual keys.
		* Used only as parameters to GetAsyncKeyState() and GetKeyState().
		* No other API or message will distinguish left and right keys in this way.
		*/
		__QCMP_STATIC_CONSTANT(int, vkLSHIFT = 0xA0);
		__QCMP_STATIC_CONSTANT(int, vkRSHIFT = 0xA1);
		__QCMP_STATIC_CONSTANT(int, vkLCONTROL = 0xA2);
		__QCMP_STATIC_CONSTANT(int, vkRCONTROL = 0xA3);
		__QCMP_STATIC_CONSTANT(int, vkLMENU = 0xA4);
		__QCMP_STATIC_CONSTANT(int, vkRMENU = 0xA5);

#if(_WIN32_WINNT >= 0x0500)
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_BACK = 0xA6);
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_FORWARD = 0xA7);
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_REFRESH = 0xA8);
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_STOP = 0xA9);
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_SEARCH = 0xAA);
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_FAVORITES = 0xAB);
		__QCMP_STATIC_CONSTANT(int, vkBROWSER_HOME = 0xAC);

		__QCMP_STATIC_CONSTANT(int, vkVOLUME_MUTE = 0xAD);
		__QCMP_STATIC_CONSTANT(int, vkVOLUME_DOWN = 0xAE);
		__QCMP_STATIC_CONSTANT(int, vkVOLUME_UP = 0xAF);
		__QCMP_STATIC_CONSTANT(int, vkMEDIA_NEXT_TRACK = 0xB0);
		__QCMP_STATIC_CONSTANT(int, vkMEDIA_PREV_TRACK = 0xB1);
		__QCMP_STATIC_CONSTANT(int, vkMEDIA_STOP = 0xB2);
		__QCMP_STATIC_CONSTANT(int, vkMEDIA_PLAY_PAUSE = 0xB3);
		__QCMP_STATIC_CONSTANT(int, vkLAUNCH_MAIL = 0xB4);
		__QCMP_STATIC_CONSTANT(int, vkLAUNCH_MEDIA_SELECT = 0xB5);
		__QCMP_STATIC_CONSTANT(int, vkLAUNCH_APP1 = 0xB6);
		__QCMP_STATIC_CONSTANT(int, vkLAUNCH_APP2 = 0xB7);

#endif /* _WIN32_WINNT >= 0x0500 */

		//0xB8 - 0xB9 : reserved

		__QCMP_STATIC_CONSTANT(int, vkOEM_1 = 0xBA);  // ';:' for US
		__QCMP_STATIC_CONSTANT(int, vkOEM_PLUS = 0xBB);  // '+' any country
		__QCMP_STATIC_CONSTANT(int, vkOEM_COMMA = 0xBC);  // ',' any country
		__QCMP_STATIC_CONSTANT(int, vkOEM_MINUS = 0xBD);  // '-' any country
		__QCMP_STATIC_CONSTANT(int, vkOEM_PERIOD = 0xBE);  // '.' any country
		__QCMP_STATIC_CONSTANT(int, vkOEM_2 = 0xBF);  // '/?' for US
		__QCMP_STATIC_CONSTANT(int, vkOEM_3 = 0xC0);  // '`~' for US

		//0xC1 - 0xD7 : reserved
		//0xD8 - 0xDA : unassigned

		__QCMP_STATIC_CONSTANT(int, vkOEM_4 = 0xDB); //  '[{' for US
		__QCMP_STATIC_CONSTANT(int, vkOEM_5 = 0xDC); //  '\|' for US
		__QCMP_STATIC_CONSTANT(int, vkOEM_6 = 0xDD); //  ']}' for US
		__QCMP_STATIC_CONSTANT(int, vkOEM_7 = 0xDE); //  ''"' for US
		__QCMP_STATIC_CONSTANT(int, vkOEM_8 = 0xDF);

		//0xE0 : reserved

		//Various extended or enhanced keyboards

		__QCMP_STATIC_CONSTANT(int, vkOEM_AX = 0xE1);	//  'AX' key on Japanese AX kbd
		__QCMP_STATIC_CONSTANT(int, vkOEM_102 = 0xE2);	//  "<>" or "\|" on RT 102-key kbd.
		__QCMP_STATIC_CONSTANT(int, vkICO_HELP = 0xE3);	//  Help key on ICO
		__QCMP_STATIC_CONSTANT(int, vkICO_00 = 0xE4);	//  00 key on ICO

#if(WINVER >= 0x0400)
		__QCMP_STATIC_CONSTANT(int, vkPROCESSKEY = 0xE5);
#endif /* WINVER >= 0x0400 */

		__QCMP_STATIC_CONSTANT(int, vkICO_CLEAR = 0xE6);


#if(_WIN32_WINNT >= 0x0500)
		__QCMP_STATIC_CONSTANT(int, vkPACKET = 0xE7);
#endif /* _WIN32_WINNT >= 0x0500 */

		//0xE8 : unassigned

		//Nokia/Ericsson definitions

		__QCMP_STATIC_CONSTANT(int, vkOEM_RESET = 0xE9);
		__QCMP_STATIC_CONSTANT(int, vkOEM_JUMP = 0xEA);
		__QCMP_STATIC_CONSTANT(int, vkOEM_PA1 = 0xEB);
		__QCMP_STATIC_CONSTANT(int, vkOEM_PA2 = 0xEC);
		__QCMP_STATIC_CONSTANT(int, vkOEM_PA3 = 0xED);
		__QCMP_STATIC_CONSTANT(int, vkOEM_WSCTRL = 0xEE);
		__QCMP_STATIC_CONSTANT(int, vkOEM_CUSEL = 0xEF);
		__QCMP_STATIC_CONSTANT(int, vkOEM_ATTN = 0xF0);
		__QCMP_STATIC_CONSTANT(int, vkOEM_FINISH = 0xF1);
		__QCMP_STATIC_CONSTANT(int, vkOEM_COPY = 0xF2);
		__QCMP_STATIC_CONSTANT(int, vkOEM_AUTO = 0xF3);
		__QCMP_STATIC_CONSTANT(int, vkOEM_ENLW = 0xF4);
		__QCMP_STATIC_CONSTANT(int, vkOEM_BACKTAB = 0xF5);

		__QCMP_STATIC_CONSTANT(int, vkATTN = 0xF6);
		__QCMP_STATIC_CONSTANT(int, vkCRSEL = 0xF7);
		__QCMP_STATIC_CONSTANT(int, vkEXSEL = 0xF8);
		__QCMP_STATIC_CONSTANT(int, vkEREOF = 0xF9);
		__QCMP_STATIC_CONSTANT(int, vkPLAY = 0xFA);
		__QCMP_STATIC_CONSTANT(int, vkZOOM = 0xFB);
		__QCMP_STATIC_CONSTANT(int, vkNONAME = 0xFC);
		__QCMP_STATIC_CONSTANT(int, vkPA1 = 0xFD);
		__QCMP_STATIC_CONSTANT(int, vkOEM_CLEAR = 0xFE);

		//0xFF : reserved

		CKeyboard();
		virtual ~CKeyboard();
		
		refType Ref(void);

		void ActivateLayout( CKeyboardLayout& KeyboardLayout, unsigned int Flags );
		bool BlockInput( bool fBlockIt );
		bool EnableWindow( COSWindow::refType Wnd, bool bEnable );
		COSWindow::refType GetActiveWindow( void );
		short GetAsyncKeyState( int vKey );
		COSWindow::refType GetFocus( void );
		unsigned int GetCodePage( void );
		short GetKeyState( int nVirtKey );
		unsigned int MapVKey( unsigned int uCode, unsigned uMapType );

		CKeyboardLayouts Layouts;
		CHotKeys HotKeys;

	protected:

		nsWinQAPI::CUser32& m_Library;

	private:

		void QueryAttributes(void);
		void QueryIndicators(void);
		void Open(void);

		__QCS_DECLARE_NONCOPYABLE(CKeyboard);

		Keyboard_Attributes m_Attributes;
		Keyboard_Indicators m_Indicators;
		bool m_bOpen;
	};

}//nsWin32

#endif//WINQL_DEVICE_KEYBOARD_H_3
