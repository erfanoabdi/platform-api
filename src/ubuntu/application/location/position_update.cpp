/*
 * Copyright (C) 2013 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voss <thomas.voss@canonical.com>
 */

#include "ubuntu/application/location/position_update.h"

#include "position_update_p.h"

#include <com/ubuntu/location/position.h>
#include <com/ubuntu/location/update.h>

namespace cul = com::ubuntu::location;

void
ua_location_position_update_ref(
    UALocationPositionUpdate *update)
{
    (void) update;
}

void
ua_location_position_update_unref(
    UALocationPositionUpdate *update)
{
    (void) update;
}

uint64_t
ua_location_position_update_get_timestamp(
    UALocationPositionUpdate *update)
{
    auto u = static_cast<UbuntuApplicationLocationPositionUpdate*>(update);

    if (!u)
        return 0;

    return std::chrono::duration_cast<std::chrono::microseconds>(
        u->update.when.time_since_epoch()).count();
}

double
ua_location_position_update_get_latitude_in_degree(
    UALocationPositionUpdate *update)
{
    auto u = static_cast<UbuntuApplicationLocationPositionUpdate*>(update);

    if (!u)
        return 0; // TODO return invalid value here.

    return u->update.value.latitude().value.value();
}

double
ua_location_position_update_get_longitude_in_degree(
    UALocationPositionUpdate *update)
{
    auto u = static_cast<UbuntuApplicationLocationPositionUpdate*>(update);

    if (!u)
        return 0; // TODO return invalid value here.

    return u->update.value.longitude().value.value();
}

bool
ua_location_position_update_has_altitude(
    UALocationPositionUpdate *update)
{
    auto u = static_cast<UbuntuApplicationLocationPositionUpdate*>(update);

    if (!u)
        return false;

    return u->update.value.has_altitude();
}

double
ua_location_position_update_get_altitude_in_meter(
    UALocationPositionUpdate *update)
{
    auto u = static_cast<UbuntuApplicationLocationPositionUpdate*>(update);

    if (!u)
        return 0; // TODO return invalid value here.

    return u->update.value.altitude().value.value();
}
