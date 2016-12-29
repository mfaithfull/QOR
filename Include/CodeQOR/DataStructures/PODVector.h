// PODVector.h

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

//Specialist vector container for Plain Old Data types

#ifndef CODEQOR_DATASTRUCTS_PODVECTOR_H_2
#define CODEQOR_DATASTRUCTS_PODVECTOR_H_2

#include "CompilerQOR.h"

#ifdef	__QCMP_OPTIMIZEINCLUDE
#pragma	__QCMP_OPTIMIZEINCLUDE
#endif//__QCMP_OPTIMIZEINCLUDE

#include "CodeQOR/Macros/codingmacros.h"

#if( __QCMP_COMPILER != __QCMP_CODEGEAR && __QCMP_COMPILER != __QCMP_BORLAND )
#	ifndef __QCMP_DECLS_MEMCPY
__QCMP_LINKAGE_C __QOR_INTERFACE( __CQOR ) void* __QCMP_CALLCON memcpy( void* __QCMP_RESTRICT s1, const void* __QCMP_RESTRICT s2, size_t n );
#	endif
__QCMP_LINKAGE_C __QOR_INTERFACE( __CQOR ) void* realloc( void* ptr, size_t size );
__QCMP_LINKAGE_C __QOR_INTERFACE( __CQOR ) void* malloc( size_t size );
#endif

//--------------------------------------------------------------------------------
namespace nsCodeQOR
{
	__QOR_INTERFACE( __CODEQOR ) void PodVector_Free( void* _data ) __QCMP_THROW;

	// Template used to store and manage array of POD data.
	//
	// This template has these adventages over other vector<> templates:
	// - Non-copyable (designed to be non-copyable, we want it)
	// - No copy-on-write (some implementations of stl can use it)
	// - Optimized for working only with POD types
	// - Uses ASMJIT_... memory management macros
	template <typename T>
	class PodVector
	{
	public:

		//--------------------------------------------------------------------------------
		// Create new instance of PodVector template. Data will not be allocated (will be 0).
		inline PodVector() __QCMP_THROW : _data(0), _length(0), _capacity(0)
		{
		}

		//--------------------------------------------------------------------------------
		// Destroy PodVector and free all data.
		~PodVector() __QCMP_THROW
		{
			PodVector_Free( _data );
		}

		// Data

		//--------------------------------------------------------------------------------
		// Get vector data.
		inline T* getData() __QCMP_THROW
		{
			return _data;
		}

		//--------------------------------------------------------------------------------
		inline const T* getData() const __QCMP_THROW
		{
			return _data;
		}

		//--------------------------------------------------------------------------------
		// Get vector length.
		inline Cmp_uint_ptr getLength() const __QCMP_THROW
		{
			return _length;
		}

		//--------------------------------------------------------------------------------
		// get vector capacity (allocation capacity).
		inline Cmp_uint_ptr getCapacity() const __QCMP_THROW
		{
			return _capacity;
		}

		// Manipulation

		//--------------------------------------------------------------------------------
		// Clear vector data, but not free internal buffer.
		void clear() __QCMP_THROW
		{
			_length = 0;
		}

		//--------------------------------------------------------------------------------
		// Clear vector data and free internal buffer.
		void free() __QCMP_THROW
		{
			if (_data)
			{
				PodVector_Free( _data );
				//::free/*ASMJIT_FREE*/(_data);
				_data = 0;
				_length = 0;
				_capacity = 0;
			}
		}

		//--------------------------------------------------------------------------------
		// Prepend item to vector.
		bool prepend( const T& item ) __QCMP_THROW
		{
			if( _length == _capacity && !_grow() )
			{
				return false;
			}

			memmove( _data + 1, _data, sizeof( T ) * _length );
			memcpy( _data, &item, sizeof( T ) );

			_length++;
			return true;
		}

		//--------------------------------------------------------------------------------
		// Insert an item at the index.
		bool insert( Cmp_uint_ptr index, const T& item ) __QCMP_THROW
		{
			//assert( index <= _length );
			if( _length == _capacity && !_grow() )
			{
				return false;
			}

			T* dst = _data + index;
			memmove( dst + 1, dst, _length - index );
			memcpy( dst, &item, sizeof( T ) );

			_length++;
			return true;
		}

		//--------------------------------------------------------------------------------
		// Append item to vector.
		bool append( const T& item ) __QCMP_THROW
		{
			if( _length == _capacity && !_grow() )
			{
				return false;
			}

			memcpy( _data + _length, &item, sizeof( T ) );

			_length++;
			return true;
		}

		//--------------------------------------------------------------------------------
		// Get index of val or (Cmp_uint_ptr)-1 if not found.
		Cmp_uint_ptr indexOf( const T& val ) const __QCMP_THROW
		{
			Cmp_uint_ptr i = 0, len = _length;
			for( i = 0; i < len; i++ )
			{
				if( _data[ i ] == val )
				{
					return i;
				}
			}
			return (Cmp_uint_ptr)-1;
		}

		//--------------------------------------------------------------------------------
		// Remove element at index i.
		void removeAt( Cmp_uint_ptr i ) __QCMP_THROW
		{
			//assert(i < _length);

			T* dst = _data + i;
			_length--;
			memmove( dst, dst + 1, _length - i );
		}

		//--------------------------------------------------------------------------------
		// Swap this pod-vector with other.
		void swap( PodVector< T >& other ) __QCMP_THROW
		{
			T* _tmp_data = _data;
			Cmp_uint_ptr _tmp_length = _length;
			Cmp_uint_ptr _tmp_capacity = _capacity;

			_data = other._data;
			_length = other._length;
			_capacity = other._capacity;

			other._data = _tmp_data;
			other._length = _tmp_length;
			other._capacity = _tmp_capacity;
		}

		//--------------------------------------------------------------------------------
		// Get item at position i.
		inline T& operator [] ( Cmp_uint_ptr i ) __QCMP_THROW
		{
			//assert(i < _length);
			return _data[i];
		}

		//--------------------------------------------------------------------------------
		// Get item at position i.
		inline const T& operator[](Cmp_uint_ptr i) const __QCMP_THROW
		{
			//assert(i < _length);
			return _data[i];
		}

		//--------------------------------------------------------------------------------
		// Append the item and return address so it can be initialized.
		T* newItem() __QCMP_THROW
		{
			if (_length == _capacity && !_grow()) return 0;
			return _data + (_length++);
		}

		//--------------------------------------------------------------------------------
		private:

		//--------------------------------------------------------------------------------
		// Called to grow internal array.
		bool _grow() __QCMP_THROW
		{
			return _realloc(_capacity < 16 ? 16 : _capacity * 2);
		}

		//--------------------------------------------------------------------------------
		// Realloc internal array to fit to items.
		bool _realloc(Cmp_uint_ptr to) __QCMP_THROW
		{
			//assert(to >= _length);

			T* p = reinterpret_cast<T*>(_data
			? ::realloc(_data, to * sizeof(T))
			: ::malloc(to * sizeof(T)));

			if( !p )
			{
				return false;
			}

			_data = p;
			_capacity = to;
			return true;
		}

		//--------------------------------------------------------------------------------
		// Members

		T* _data;					// Items data.
		Cmp_uint_ptr _length;		// Length of buffer (count of items in array).
		Cmp_uint_ptr _capacity;		// Capacity of buffer (maximum items that can fit to current array).

	private:

		__QCS_DECLARE_NONCOPYABLE( PodVector );
	};

}//nsCodeQOR

#endif//CODEQOR_DATASTRUCTS_PODVECTOR_H_2