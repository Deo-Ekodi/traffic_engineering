#include "speed.hpp"

namespace traffic
{
    double speed(vehicle* veh)
    {
        return veh->velocity;
    }
    double speed(double& time, double& distance)
    {
        return distance / time;
    }
} // namespace traffic