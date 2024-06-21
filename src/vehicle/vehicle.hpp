#pragma once

#include <cstdint>

namespace traffic
{
    class vehicle
    {
    public:
        double length;
        double velocity;
    public:
        vehicle(/* args */) = default;
        void set_velocity(double&);
        double get_velocity()const;
        void set_length(double&);
        double get_length()const;
    };    
} // namespace traffic
