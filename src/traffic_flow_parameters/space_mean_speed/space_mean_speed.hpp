#pragma once

namespace traffic
{
    /**
     * SPACE_MEAN_SPEED
     * Harmonic mean of Spot Speeds
     * obtained as a function of:
     * 1. Length of Stretch
     * 2. Number of Vehicles
     * 3. Time used to traverse stretch (cummulative)
     * Theoretically TIME_MESN_SPEED >= SPACE_MEAN_SPEED
     */
    template<typename T>
    T space_mean_speed();
} // namespace traffic
