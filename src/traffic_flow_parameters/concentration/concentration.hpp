#pragma once

#include "utility/utility.hpp"


namespace traffic
{
    /**
     * CONCENTRATION a.k.a DENSITY
     * This is Number of vehicles present 
     * on a section of a roadway for a given 
     * period of time
     * 
     * HIGH_DENSITY -> Vehicles close to each other
     * LOW_DENSITY  -> Vehicles far apart
     */
    template <typename T>
    T concentration();
} // namespace traffic
