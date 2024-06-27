#pragma once

namespace traffic
{
    /**
     * FLOW_RATE
     * rate at which vehicles  
     * pass at a given point on the roadway
     * obtained as a function of:
     * 1. Time Taken
     * 2. Number of Vehicles
     */
    template <typename T>
    T flow_rate();
} // namespace traffic
