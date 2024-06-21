#pragma once

#include "vehicle/vehicle.hpp"


namespace traffic
{
    #define SECONDS_PER_HOUR    3600
    #define SECONDS_PER_MINUTE  60
    #define MINUTES_PER_HOUR    60
    #define METRES_PER_KILOMETRE  1000
    // #define 

    #define EINVALID_PARAMETER  1

    double get_distance();
    double get_velocity();
    double get_time();

    /**
     * returns length of stretch traversed by vehicle
     * 
     */
    template<typename T>
    T length_of_road();

    /**
     * get actual number of vehicles on stretch
     */
    template<typename T>
    T number_of_vehicles();
    // double convert_metres_to_kilometres(double&);
    // double convert_kilometres_to_metres(double& distance);
    // double convert_seconds_to_hours(double& time);
    // double convert_hours_to_seconds(double& time);
} // namespace traffic
