//PosumMemoryManager.h

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

//Posum Memory Manager object

#ifndef POSUMQOR_MEMORY_H_3
#define POSUMQOR_MEMORY_H_3

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma __QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

//--------------------------------------------------------------------------------
namespace nsPosum
{
	//--------------------------------------------------------------------------------
	class CMemoryManager
	{
	public:

		//--------------------------------------------------------------------------------
		CMemoryManager()
		{
		}

		//--------------------------------------------------------------------------------
		virtual ~CMemoryManager()
		{
		}

		//malloc
		//free
		//realloc
		//sysv shared memory and memory protection

		/*
    __QOR_INTERFACE( __CQOR ) int mlock( const void*, size_t );
    __QOR_INTERFACE( __CQOR ) int mlockall( int );
    __QOR_INTERFACE( __CQOR ) void* mmap( void*, size_t, int, int, int, ::off_t );
    __QOR_INTERFACE( __CQOR ) int mprotect( void*, size_t, int );
    __QOR_INTERFACE( __CQOR ) int msync( void*, size_t, int );
    __QOR_INTERFACE( __CQOR ) int munlock( const void*, size_t );
    __QOR_INTERFACE( __CQOR ) int munlockall( void );
    __QOR_INTERFACE( __CQOR ) int munmap( void*, size_t );
    __QOR_INTERFACE( __CQOR ) int posix_madvise( void*, size_t, int );
    __QOR_INTERFACE( __CQOR ) int posix_mem_offset( const void* __QCMP_RESTRICT, size_t, ::off_t* __QCMP_RESTRICT, size_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
    __QOR_INTERFACE( __CQOR ) int posix_typed_mem_get_info( int, ::posix_typed_mem_info* );
    __QOR_INTERFACE( __CQOR ) int posix_typed_mem_open( const char*, int, int );
    __QOR_INTERFACE( __CQOR ) int shm_open( const char*, int, ::mode_t );
    __QOR_INTERFACE( __CQOR ) int shm_unlink( const char* );
*/
	};

}//nsPosum

#endif//POSUMQOR_MEMORY_H_3
