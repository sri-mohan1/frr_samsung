/*
 * Zebra-specific error messages.
 * Copyright (C) 2018  Cumulus Networks, Inc.
 *                     Quentin Young
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; see the file COPYING; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __EC_ZEBRAORS_H__
#define __EC_ZEBRAORS_H__

#include "lib/ferr.h"

#ifdef __cplusplus
extern "C" {
#endif

enum zebra_log_refs {
	EC_ZEBRA_LM_RESPONSE = ZEBRA_FERR_START,
	EC_ZEBRA_LM_NO_SUCH_CLIENT,
	EC_ZEBRA_LM_RELAY_FAILED,
	EC_ZEBRA_LM_NO_SOCKET,
	EC_ZEBRA_LM_BAD_INSTANCE,
	EC_ZEBRA_LM_RELAY_REQUEST_FAILED,
	EC_ZEBRA_LM_CLIENT_CONNECTION_FAILED,
	EC_ZEBRA_LM_EXHAUSTED_LABELS,
	EC_ZEBRA_LM_DAEMON_MISMATCH,
	EC_ZEBRA_LM_UNRELEASED_CHUNK,
	EC_ZEBRA_DP_INVALID_RC,
	EC_ZEBRA_WQ_NONEXISTENT,
	EC_ZEBRA_FEC_ADD_FAILED,
	EC_ZEBRA_FEC_LABEL_INDEX_LABEL_CONFLICT,
	EC_ZEBRA_FEC_RM_FAILED,
	EC_ZEBRA_IRDP_LEN_MISMATCH,
	EC_ZEBRA_RNH_UNKNOWN_FAMILY,
	EC_ZEBRA_DP_INSTALL_FAIL,
	EC_ZEBRA_DP_DELETE_FAIL,
	EC_ZEBRA_TABLE_LOOKUP_FAILED,
	EC_ZEBRA_NETLINK_NOT_AVAILABLE,
	EC_ZEBRA_PROTOBUF_NOT_AVAILABLE,
	EC_ZEBRA_TM_EXHAUSTED_IDS,
	EC_ZEBRA_TM_DAEMON_MISMATCH,
	EC_ZEBRA_TM_UNRELEASED_CHUNK,
	EC_ZEBRA_UNKNOWN_FAMILY,
	EC_ZEBRA_TM_WRONG_PROTO,
	EC_ZEBRA_PROTO_OR_INSTANCE_MISMATCH,
	EC_ZEBRA_LM_CANNOT_ASSIGN_CHUNK,
	EC_ZEBRA_LM_ALIENS,
	EC_ZEBRA_TM_CANNOT_ASSIGN_CHUNK,
	EC_ZEBRA_TM_ALIENS,
	EC_ZEBRA_RECVBUF,
	EC_ZEBRA_UNKNOWN_NLMSG,
	EC_ZEBRA_RECVMSG_OVERRUN,
	EC_ZEBRA_NETLINK_LENGTH_ERROR,
	EC_ZEBRA_UNEXPECTED_MESSAGE,
	EC_ZEBRA_NETLINK_BAD_SEQUENCE,
	EC_ZEBRA_BAD_MULTIPATH_NUM,
	EC_ZEBRA_PREFIX_PARSE_ERROR,
	EC_ZEBRA_MAC_ADD_FAILED,
	EC_ZEBRA_VNI_DEL_FAILED,
	EC_ZEBRA_VTEP_ADD_FAILED,
	EC_ZEBRA_VNI_ADD_FAILED,
	/* warnings */
	EC_ZEBRA_NS_NOTIFY_READ,
	EC_ZEBRAING_LM_PROTO_MISMATCH,
	EC_ZEBRA_LSP_INSTALL_FAILURE,
	EC_ZEBRA_LSP_DELETE_FAILURE,
	EC_ZEBRA_MPLS_SUPPORT_DISABLED,
	EC_ZEBRA_SYSCTL_FAILED,
	EC_ZEBRA_CONVERT_TO_DEBUG,
	EC_ZEBRA_NS_VRF_CREATION_FAILED,
	EC_ZEBRA_NS_DELETION_FAILED_NO_VRF,
	EC_ZEBRA_IRDP_BAD_CHECKSUM,
	EC_ZEBRA_IRDP_BAD_TYPE_CODE,
	EC_ZEBRA_IRDP_BAD_RX_FLAGS,
	EC_ZEBRA_IRDP_BAD_TYPE,
	EC_ZEBRA_RNH_NO_TABLE,
	EC_ZEBRA_IFLIST_FAILED,
	EC_ZEBRA_FPM_FORMAT_UNKNOWN,
	EC_ZEBRA_CLIENT_IO_ERROR,
	EC_ZEBRA_CLIENT_WRITE_FAILED,
	EC_ZEBRA_NETLINK_INVALID_AF,
	EC_ZEBRA_REMOVE_ADDR_UNKNOWN_SUBNET,
	EC_ZEBRA_REMOVE_UNREGISTERED_ADDR,
	EC_ZEBRA_PTM_NOT_READY,
	EC_ZEBRA_UNSUPPORTED_V4_SRCDEST,
	EC_ZEBRA_UNKNOWN_INTERFACE,
	EC_ZEBRA_VRF_NOT_FOUND,
	EC_ZEBRA_MORE_NH_THAN_MULTIPATH,
	EC_ZEBRA_NEXTHOP_CREATION_FAILED,
	EC_ZEBRA_RX_ROUTE_NO_NEXTHOPS,
	EC_ZEBRA_RX_SRCDEST_WRONG_AFI,
	EC_ZEBRA_PSEUDOWIRE_EXISTS,
	EC_ZEBRA_PSEUDOWIRE_UNINSTALL_NOT_FOUND,
	EC_ZEBRA_PSEUDOWIRE_NONEXISTENT,
	EC_ZEBRA_NO_IFACE_ADDR,
	EC_ZEBRA_IFACE_ADDR_ADD_FAILED,
	EC_ZEBRA_IRDP_CANNOT_ACTIVATE_IFACE,
	EC_ZEBRA_IRDP_IFACE_DOWN,
	EC_ZEBRA_IRDP_IFACE_MCAST_DISABLED,
	EC_ZEBRA_NETLINK_EXTENDED_WARNING,
	EC_ZEBRA_NAMESPACE_DIR_INACCESSIBLE,
	EC_ZEBRA_CONNECTED_AFI_UNKNOWN,
	EC_ZEBRA_IFACE_SAME_LOCAL_AS_PEER,
	EC_ZEBRA_BCAST_ADDR_MISMATCH,
	EC_ZEBRA_REDISTRIBUTE_UNKNOWN_AF,
	EC_ZEBRA_ADVERTISING_UNUSABLE_ADDR,
	EC_ZEBRA_RA_PARAM_MISMATCH,
	EC_ZEBRA_RTM_VERSION_MISMATCH,
	EC_ZEBRA_RTM_NO_GATEWAY,
	EC_ZEBRA_MAX_LABELS_PUSH,
	EC_ZEBRA_STICKY_MAC_ALREADY_LEARNT,
	EC_ZEBRA_UNSUPPORTED_V6_SRCDEST,
	EC_ZEBRA_DUP_MAC_DETECTED,
	EC_ZEBRA_DUP_IP_INHERIT_DETECTED,
	EC_ZEBRA_DUP_IP_DETECTED,
};

void zebra_error_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __EC_ZEBRAORS_H__ */
