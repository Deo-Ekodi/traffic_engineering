#pragma once

#include "vehicle/vehicle.hpp"

namespace traffic
{
    /**
     * speed of vehicle
     */
    double speed(vehicle*);
    /**
     * distance / time
     * params (time, distance)
     */
    double speed(double& time, double& distance);
} // namespace traffic
