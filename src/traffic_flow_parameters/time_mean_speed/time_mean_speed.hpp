#pragma once

namespace traffic
{
    /**
     * TIME_MEAN_SPEED
     * obtained as a function of
     * 1. spot speeds
     * 2. N - number of vehicles
     * 
     * Vt = (summation of spot speeds) / (number of vehicles)
     */
    template<typename T, typename N = int>
    T time_mean_speed();
} // namespace traffic
