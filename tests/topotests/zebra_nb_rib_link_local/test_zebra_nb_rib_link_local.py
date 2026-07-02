#!/usr/bin/env python
# SPDX-License-Identifier: ISC
#
# test_zebra_nb_rib_link_local.py
#
# Copyright (c) 2026 by Samsung Research
# Sri.Mohan
#
"""
test_zebra_nb_rib_link_local.py: Test that link-local IPv6 routes are
visible through the northbound RIB API, consistent with the CLI
("show ipv6 route").

This test verifies the fix for GitHub issue #22535, where the
lib_vrf_zebra_ribs_rib_route_get_next() callback skipped link-local
IPv6 routes from the northbound RIB iteration.
"""

import os
import sys
import json

import pytest

# Save the Current Working Directory to find configuration files.
CWD = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(CWD, "../"))

# pylint: disable=C0413
# Import topogen and topotest helpers
from lib import topotest
from lib.topogen import Topogen, get_topogen
from lib.topolog import logger


pytestmark = [pytest.mark.mgmtd]


def setup_module(mod):
    "Sets up the pytest environment"
    topodef = {"s1": ("r1",), "s2": ("r1",)}
    tgen = Topogen(topodef, mod.__name__)
    tgen.start_topology()

    router_list = tgen.routers()
    for rname, router in router_list.items():
        router.load_frr_config()

    tgen.start_router()


def teardown_module():
    "Teardown the pytest environment"
    tgen = get_topogen()
    tgen.stop_topology()


def test_link_local_routes_visible_in_nb_rib():
    """
    Verify that link-local IPv6 routes (e.g. fe80::/64) are returned by
    the northbound RIB API, matching what the CLI "show ipv6 route" displays.
    """
    tgen = get_topogen()
    if tgen.routers_have_failure():
        pytest.skip("skipped because of router(s) failure")

    r1 = tgen.gears["r1"]

    #
    # 1) Confirm the CLI shows link-local routes.
    #
    def cli_has_link_local():
        output = r1.vtysh_cmd("show ipv6 route json", isjson=True)
        if not output:
            return False
        # Look for any fe80:: prefix key
        for prefix in output:
            if prefix.lower().startswith("fe80::"):
                return True
        return False

    _, result = topotest.run_and_expect(cli_has_link_local, True, count=30, wait=1)
    assert result is True, (
        "CLI 'show ipv6 route' does not show any link-local routes; "
        "expected at least one fe80::/64 connected route"
    )

    #
    # 2) Confirm the northbound RIB API also returns link-local routes.
    #
    def nb_rib_has_link_local():
        output = json.loads(
            r1.vtysh_cmd(
                "show mgmt get-data "
                "/frr-vrf:lib/vrf/frr-zebra:zebra/ribs/rib/route"
            )
        )

        # Navigate the YANG tree to the route list.  The structure is:
        #   frr-vrf:lib -> vrf[] -> frr-zebra:zebra -> ribs -> rib[] -> route[]
        try:
            lib = output["frr-vrf:lib"]
            vrfs = lib.get("vrf", [])
            for vrf in vrfs:
                zebra = vrf.get("frr-zebra:zebra", {})
                ribs = zebra.get("ribs", {}).get("rib", [])
                for rib in ribs:
                    routes = rib.get("route", [])
                    for route in routes:
                        prefix = route.get("prefix", "")
                        if prefix.lower().startswith("fe80::"):
                            return True
        except (KeyError, TypeError):
            pass
        return False

    _, result = topotest.run_and_expect(
        nb_rib_has_link_local, True, count=30, wait=1
    )
    assert result is True, (
        "Northbound RIB API does not return any link-local routes; "
        "expected at least one fe80::/64 route to be visible via "
        "'show mgmt get-data /frr-vrf:lib/vrf/frr-zebra:zebra/ribs/rib/route'"
    )

    logger.info(
        "Link-local routes are visible in both the CLI and the northbound RIB API"
    )


if __name__ == "__main__":
    args = ["-s"] + sys.argv[1:]
    sys.exit(pytest.main(args))
