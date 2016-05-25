//LIN_ip6.h

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

#ifndef SYSTEMQOR_LIN_NETINET_IP6_H_3
#define SYSTEMQOR_LIN_NETINET_IP6_H_3

#include <stdint.h>
#include <netinet/in.h>
#include <endian.h>

/*

struct ip6_hdr {
	union {
		struct ip6_hdrctl {
			uint32_t ip6_un1_flow;
			uint16_t ip6_un1_plen;
			uint8_t  ip6_un1_nxt;
			uint8_t  ip6_un1_hlim;
		} ip6_un1;
		uint8_t ip6_un2_vfc;
	} ip6_ctlun;
	struct in6_addr ip6_src;
	struct in6_addr ip6_dst;
};

#define ip6_vfc   ip6_ctlun.ip6_un2_vfc
#define ip6_flow  ip6_ctlun.ip6_un1.ip6_un1_flow
#define ip6_plen  ip6_ctlun.ip6_un1.ip6_un1_plen
#define ip6_nxt   ip6_ctlun.ip6_un1.ip6_un1_nxt
#define ip6_hlim  ip6_ctlun.ip6_un1.ip6_un1_hlim
#define ip6_hops  ip6_ctlun.ip6_un1.ip6_un1_hlim

struct ip6_ext {
	uint8_t  ip6e_nxt;
	uint8_t  ip6e_len;
};

struct ip6_hbh {
	uint8_t  ip6h_nxt;
	uint8_t  ip6h_len;
};

struct ip6_dest {
	uint8_t  ip6d_nxt;
	uint8_t  ip6d_len;
};

struct ip6_rthdr {
	uint8_t  ip6r_nxt;
	uint8_t  ip6r_len;
	uint8_t  ip6r_type;
	uint8_t  ip6r_segleft;
};

struct ip6_rthdr0 {
	uint8_t  ip6r0_nxt;
	uint8_t  ip6r0_len;
	uint8_t  ip6r0_type;
	uint8_t  ip6r0_segleft;
	uint8_t  ip6r0_reserved;
	uint8_t  ip6r0_slmap[3];
	struct in6_addr ip6r0_addr[];
};

struct ip6_frag {
	uint8_t   ip6f_nxt;
	uint8_t   ip6f_reserved;
	uint16_t  ip6f_offlg;
	uint32_t  ip6f_ident;
};

#if __BYTE_ORDER == __BIG_ENDIAN
#define IP6F_OFF_MASK       0xfff8
#define IP6F_RESERVED_MASK  0x0006
#define IP6F_MORE_FRAG      0x0001
#else
#define IP6F_OFF_MASK       0xf8ff
#define IP6F_RESERVED_MASK  0x0600
#define IP6F_MORE_FRAG      0x0100
#endif

struct ip6_opt {
	uint8_t  ip6o_type;
	uint8_t  ip6o_len;
};

#define IP6OPT_TYPE(o)		((o) & 0xc0)
#define IP6OPT_TYPE_SKIP	0x00
#define IP6OPT_TYPE_DISCARD	0x40
#define IP6OPT_TYPE_FORCEICMP	0x80
#define IP6OPT_TYPE_ICMP	0xc0
#define IP6OPT_TYPE_MUTABLE	0x20

#define IP6OPT_PAD1	0
#define IP6OPT_PADN	1

#define IP6OPT_JUMBO		0xc2
#define IP6OPT_NSAP_ADDR	0xc3
#define IP6OPT_TUNNEL_LIMIT	0x04
#define IP6OPT_ROUTER_ALERT	0x05

struct ip6_opt_jumbo {
	uint8_t  ip6oj_type;
	uint8_t  ip6oj_len;
	uint8_t  ip6oj_jumbo_len[4];
};
#define IP6OPT_JUMBO_LEN	6

struct ip6_opt_nsap {
	uint8_t  ip6on_type;
	uint8_t  ip6on_len;
	uint8_t  ip6on_src_nsap_len;
	uint8_t  ip6on_dst_nsap_len;
};

struct ip6_opt_tunnel {
	uint8_t  ip6ot_type;
	uint8_t  ip6ot_len;
	uint8_t  ip6ot_encap_limit;
};

struct ip6_opt_router {
	uint8_t  ip6or_type;
	uint8_t  ip6or_len;
	uint8_t  ip6or_value[2];
};

#if __BYTE_ORDER == __BIG_ENDIAN
#define IP6_ALERT_MLD	0x0000
#define IP6_ALERT_RSVP	0x0001
#define IP6_ALERT_AN	0x0002
#else
#define IP6_ALERT_MLD	0x0000
#define IP6_ALERT_RSVP	0x0100
#define IP6_ALERT_AN	0x0200
#endif
*/

#endif//SYSTEMQOR_LIN_NETINET_IP6_H_3
