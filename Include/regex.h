//regex.h

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

#ifndef	QOR_REGEX_H_3
#define QOR_REGEX_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(regex)

typedef nsPlatform::regex_t regex_t;
typedef nsPlatform::regoff_t regoff_t;
typedef nsPlatform::regmatch_t regmatch_t;

//The <regex.h> header shall define the following symbolic constants for the cflags parameter to the regcomp() function:
#define REG_EXTENDED			( nsPlatform::RegExtended )			//Use Extended Regular Expressions. 
#define REG_ICASE				( nsPlatform::RegICase )			//Ignore case in match. 
#define REG_NOSUB				( nsPlatform::RegNoSub )			//Report only success or fail in regexec(). 
#define REG_NEWLINE				( nsPlatform::RegNewLine )			//Change the handling of <newline>. 

//The <regex.h> header shall define the following symbolic constants for the eflags parameter to the regexec() function:
#define REG_NOTBOL				( nsPlatform::RegNotBOL )			//The <circumflex> character ( '^' ), when taken as a special character, does not match the beginning of string. 
#define REG_NOTEOL				( nsPlatform::RegNotEOL )			//The <dollar-sign> ( '$' ), when taken as a special character, does not match the end of string. 

//The <regex.h> header shall define the following symbolic constants as error return values:

#define REG_NOMATCH				( nsPlatform::RegNoMatch )			//regexec() failed to match. 
#define REG_BADPAT				( nsPlatform::RegBadPat )			//Invalid regular expression. 
#define REG_ECOLLATE			( nsPlatform::RegECollate )			//Invalid collating element referenced. 
#define REG_ECTYPE				( nsPlatform::RegECType )			//Invalid character class type referenced. 
#define REG_EESCAPE				( nsPlatform::RegEEscape )			//Trailing <backslash> character in pattern. 
#define REG_ESUBREG				( nsPlatform::RegESubReg )			//Number in \digit invalid or in error. 
#define REG_EBRACK				( nsPlatform::RegEBRack )			//"[]" imbalance. 
#define REG_EPAREN				( nsPlatform::RegEParen )			//"\(\)" or "()" imbalance. 
#define REG_EBRACE				( nsPlatform::RegEBrace )			//"\{\}" imbalance. 
#define REG_BADBR				( nsPlatform::RegBadBr )			//Content of "\{\}" invalid: not a number, number too large, more than two numbers, first larger than second. 
#define REG_ERANGE				( nsPlatform::RegERange )			//Invalid endpoint in range expression. 
#define REG_ESPACE				( nsPlatform::RegESpace )			//Out of memory. 
#define REG_BADRPT				( nsPlatform::RegBadRpt )			//'?' , '*' , or '+' not preceded by valid regular expression. 

__QCMP_STARTLINKAGE_C

	__QOR_INTERFACE( __CQOR ) int regcomp( regex_t* __QCMP_RESTRICT, const char* __QCMP_RESTRICT, int );
	__QOR_INTERFACE( __CQOR ) size_t regerror( int, const regex_t* __QCMP_RESTRICT, char* __QCMP_RESTRICT, size_t );
	__QOR_INTERFACE( __CQOR ) int regexec( const regex_t* __QCMP_RESTRICT, const char* __QCMP_RESTRICT, size_t, regmatch_t [/*__QCMP_RESTRICT*/], int );
	__QOR_INTERFACE( __CQOR ) void regfree( regex_t* );

__QCMP_ENDLINKAGE_C

#endif//QOR_REGEX_H_3
