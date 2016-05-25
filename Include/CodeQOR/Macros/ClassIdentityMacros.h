//ClassIdentityMacros.h

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

//Macros to make class registration and factories easy

#ifndef CODEQOR_CLASSIDENTITYMACROS_H_1
#define CODEQOR_CLASSIDENTITYMACROS_H_1


	//--------------------------------------------------------------------------------
	//Declare a class unique identifier
#	define __QOR_DECLARE_OCLASS_ID( myClass )										\
																					\
	static const nsCodeQOR::mxGUID* ClassID(void);									\
	static const char* TypeName(void)

	//--------------------------------------------------------------------------------
	//Implementation to provide locally unique class id
#	define __QOR_IMPLEMENT_OCLASS_LUID( myClass )									\
																					\
    const nsCodeQOR::mxGUID* myClass::ClassID()										\
	{																				\
        static const nsCodeQOR::mxGUID classID = { 0x0000, 0x00,					\
		0x00, { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0								\
													} };							\
        return &classID;															\
    }																				\
																					\
	const char* myClass::TypeName()													\
	{																				\
		return #myClass ;															\
	}

	//--------------------------------------------------------------------------------
	//Implementation to provide 'globally' unique class id
#	define __QOR_IMPLEMENT_OCLASS_GUID(												\
	myClass, _G1, _G2, _G3,															\
	_G41, _G42, _G43, _G44, _G45, _G46, _G47, _G48)									\
																					\
    const nsCodeQOR::mxGUID* myClass::ClassID()										\
	{																				\
        static const nsCodeQOR::mxGUID classID = {_G1, _G2, _G3,					\
	{_G41, _G42, _G43, _G44, _G45, _G46, _G47, _G48} };								\
        return &classID;															\
    }																				\
																					\
	const char* myClass::TypeName()													\
	{																				\
		return #myClass ;															\
	}

	//Add __QOR_DECLARE_OCLASS_GUID( classname ); to a class declaration and
	//__QOR_IMPLEMENT_OCLASS_GUID(classname); to the .cpp file to give the class a
	//locally unique identifier based on the code address in memory and optionally a globally unique identifier

	//--------------------------------------------------------------------------------
	//Declare a class to be factory creatable
#	define __QOR_DECLARE_CLASS_FACTORY( myClass )									\
																					\
	public:																			\
		__QOR_DECLARE_OCLASS_ID( myClass );											\
		static nsCodeQOR::CTClassRegEntry< myClass > RegEntry

	//--------------------------------------------------------------------------------
	//Implementation to provide a factory configured to create class instances
#	define __QOR_IMPLEMENT_CLASS_FACTORY( myClass )									\
																					\
	__QOR_IMPLEMENT_OCLASS_LUID( myClass );											\
	nsCodeQOR::CTClassRegEntry< myClass > myClass::RegEntry

	//Add __QOR_DECLARE_CLASS_FACTORY(classname); to a class declaration and
	//__QOR_IMPLEMENT_CLASS_FACTORY(classname); to the .cpp file to create and register a
	//class instance factory object that can create instances of myClass

	//--------------------------------------------------------------------------------
	//Declare a class to be factory creatable
#	define __QOR_DECLARE_CUSTOM_FACTORY( myClass, _FACTORY_CLASS_ )					\
																					\
	public:																			\
		__QOR_DECLARE_OCLASS_ID( myClass );											\
		static _FACTORY_CLASS_ RegEntry

	//--------------------------------------------------------------------------------
	//Implementation to provide a factory configured to create class instances
#	define __QOR_IMPLEMENT_CUSTOM_FACTORY( myClass, _FACTORY_CLASS_ )				\
																					\
	__QOR_IMPLEMENT_OCLASS_LUID( myClass );											\
	_FACTORY_CLASS_ myClass::RegEntry


#endif//CODEQOR_CLASSIDENTITYMACROS_H_1
