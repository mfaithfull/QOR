//LIN_tftp.h

// Copyright Querysoft Limited 2015
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and prepare derivative works of the
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
// IMPLIED, INCLUDING BIT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE

#ifndef SYSTEMQOR_LIN_ARPA_TFTP_H_3
#define SYSTEMQOR_LIN_ARPA_TFTP_H_3

/*
#define SEGSIZE 512
#define RRQ 01
#define WRQ 02
#define DATA 03
#define ACK 04
#define ERROR 05
struct tftphdr {
	short th_opcode;
	union {
		unsigned short tu_block;
		short tu_code;
		char tu_stuff[1];
	} th_u;
	char th_data[1];
};
#define th_block th_u.tu_block
#define th_code th_u.tu_code
#define th_stuff th_u.tu_stuff
#define th_msg th_data
#define EUNDEF 0
#define ENOTFOUND 1
#define EACCESS 2
#define ENOSPACE 3
#define EBADOP 4
#define EBADID 5
#define EEXISTS 6
#define ENOUSER 7
*/

#endif//SYSTEMQOR_LIN_ARPA_TFTP_H_3