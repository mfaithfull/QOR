//trace.h

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

#ifndef	QOR_TRACE_H_3
#define QOR_TRACE_H_3

#include "SystemQOR.h"
#include QOR_SYS_PLATFORMTYPES(trace)

typedef nsPlatform::timespec timespec;
typedef nsPlatform::pid_t pid_t;
typedef nsPlatform::posix_trace_event_info posix_trace_event_info;
typedef nsPlatform::posix_trace_status_info posix_trace_status_info;

#define POSIX_TRACE_ALL_EVENTS			( nsPlatform::PosixTraceAllEvents )
#define POSIX_TRACE_APPEND				( nsPlatform::PosixTraceAppend )
#define POSIX_TRACE_CLOSE_FOR_CHILD		( nsPlatform::PosixTraceCloseForChild )
#define POSIX_TRACE_FILTER				( nsPlatform::PosixTraceFilter )
#define POSIX_TRACE_FLUSH				( nsPlatform::PosixTraceFlush )
#define POSIX_TRACE_FLUSH_START			( nsPlatform::PosixTraceFlushStart )
#define POSIX_TRACE_FLUSH_STOP			( nsPlatform::PosixTraceFlushStop )
#define POSIX_TRACE_FLUSHING			( nsPlatform::PosixTraceFlushing )
#define POSIX_TRACE_FULL				( nsPlatform::PosixTraceFull )
#define POSIX_TRACE_LOOP				( nsPlatform::PosixTraceLoop )
#define POSIX_TRACE_NO_OVERRUN			( nsPlatform::PosixTraceNoOverrun )
#define POSIX_TRACE_NOT_FLUSHING		( nsPlatform::PosixTraceNotFlushing )
#define POSIX_TRACE_NOT_FULL			( nsPlatform::PosixTraceNotFull )
#define POSIX_TRACE_INHERITED			( nsPlatform::PosixTraceInherited )
#define POSIX_TRACE_NOT_TRUNCATED		( nsPlatform::PosixTraceNotTruncated )
#define POSIX_TRACE_OVERFLOW			( nsPlatform::PosixTraceOverflow )
#define POSIX_TRACE_OVERRUN				( nsPlatform::PosixTraceOverrun )
#define POSIX_TRACE_RESUME				( nsPlatform::PosixTraceResume )
#define POSIX_TRACE_RUNNING				( nsPlatform::PosixTraceRunning )
#define POSIX_TRACE_START				( nsPlatform::PosixTraceStart )
#define POSIX_TRACE_STOP				( nsPlatform::PosixTraceStop )
#define POSIX_TRACE_SUSPENDED			( nsPlatform::PosixTraceSuspend )
#define POSIX_TRACE_SYSTEM_EVENTS		( nsPlatform::PosixTraceSystemEvents )
#define POSIX_TRACE_TRUNCATED_READ		( nsPlatform::PosixTraceTruncatedRead )
#define POSIX_TRACE_TRUNCATED_RECORD	( nsPlatform::PosixTraceTruncatedRecord )
#define POSIX_TRACE_UNNAMED_USER_EVENT	( nsPlatform::PosixTraceUnnamedUserEvent )
#define POSIX_TRACE_UNTIL_FULL			( nsPlatform::PosixTraceUntilFull )
#define POSIX_TRACE_WOPID_EVENTS		( nsPlatform::PosixTraceWoPIDEvents )

//typedef nsPlatform::size_t size_t;
typedef nsPlatform::trace_attr_t trace_attr_t;
typedef nsPlatform::trace_event_id_t trace_event_id_t;
typedef nsPlatform::trace_event_set_t trace_event_set_t;
typedef nsPlatform::trace_id_t trace_id_t;

__QCMP_STARTLINKAGE_C

	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_destroy( ::trace_attr_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getclockres( const ::trace_attr_t*, ::timespec* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getcreatetime( const ::trace_attr_t*, ::timespec* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getgenversion( const ::trace_attr_t*, char* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getinherited( const ::trace_attr_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getlogfullpolicy( const ::trace_attr_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getlogsize( const ::trace_attr_t* __QCMP_RESTRICT, size_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getmaxdatasize( const ::trace_attr_t* __QCMP_RESTRICT, size_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getmaxsystemeventsize( const ::trace_attr_t* __QCMP_RESTRICT, size_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getmaxusereventsize( const ::trace_attr_t* __QCMP_RESTRICT, size_t, size_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getname( const ::trace_attr_t*, char* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getstreamfullpolicy( const ::trace_attr_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_getstreamsize( const ::trace_attr_t* __QCMP_RESTRICT, size_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_init( ::trace_attr_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setinherited( ::trace_attr_t*, int );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setlogfullpolicy( ::trace_attr_t*, int );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setlogsize( ::trace_attr_t*, size_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setmaxdatasize( ::trace_attr_t*, size_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setname( ::trace_attr_t*, const char* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setstreamfullpolicy( ::trace_attr_t*, int );
	__QOR_INTERFACE( __CQOR ) int posix_trace_attr_setstreamsize( ::trace_attr_t*, size_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_clear( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_close( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_create( ::pid_t, const ::trace_attr_t* __QCMP_RESTRICT, ::trace_id_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_create_withlog( ::pid_t, const ::trace_attr_t* __QCMP_RESTRICT, int, ::trace_id_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) void posix_trace_event( ::trace_event_id_t, const void* __QCMP_RESTRICT, size_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventid_equal( ::trace_id_t, ::trace_event_id_t, ::trace_event_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventid_get_name( ::trace_id_t, ::trace_event_id_t, char* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventid_open( const char* __QCMP_RESTRICT, ::trace_event_id_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventset_add( ::trace_event_id_t, ::trace_event_set_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventset_del( ::trace_event_id_t, ::trace_event_set_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventset_empty( ::trace_event_set_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventset_fill( ::trace_event_set_t*, int );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventset_ismember( ::trace_event_id_t, const ::trace_event_set_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventtypelist_getnext_id( ::trace_id_t, ::trace_event_id_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_eventtypelist_rewind( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_flush( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_get_attr( ::trace_id_t, ::trace_attr_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_get_filter( ::trace_id_t, ::trace_event_set_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_get_status( ::trace_id_t, ::posix_trace_status_info* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_getnext_event( ::trace_id_t, ::posix_trace_event_info* __QCMP_RESTRICT, void* __QCMP_RESTRICT, size_t, size_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_open( int, ::trace_id_t* );
	__QOR_INTERFACE( __CQOR ) int posix_trace_rewind( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_set_filter( ::trace_id_t, const ::trace_event_set_t*, int );
	__QOR_INTERFACE( __CQOR ) int posix_trace_shutdown( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_start( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_stop( ::trace_id_t );
	__QOR_INTERFACE( __CQOR ) int posix_trace_timedgetnext_event( ::trace_id_t, ::posix_trace_event_info* __QCMP_RESTRICT, void* __QCMP_RESTRICT, size_t, size_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT, const ::timespec* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_trid_eventid_open( ::trace_id_t, const char* __QCMP_RESTRICT, ::trace_event_id_t* __QCMP_RESTRICT );
	__QOR_INTERFACE( __CQOR ) int posix_trace_trygetnext_event( ::trace_id_t, ::posix_trace_event_info* __QCMP_RESTRICT, void* __QCMP_RESTRICT, size_t, size_t* __QCMP_RESTRICT, int* __QCMP_RESTRICT );

__QCMP_ENDLINKAGE_C

#endif//QOR_TRACE_H_3
