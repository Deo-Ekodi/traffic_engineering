#include "utility.hpp"
#include <iostream>


using namespace std;

namespace traffic
{
    static double convert_metres_to_kilometres(double& distance)
    {
        return distance / METRES_PER_KILOMETRE;
    }

    static double convert_kilometres_to_metres(double& distance)
    {
        return distance * METRES_PER_KILOMETRE;
    }

    static double convert_hours_to_seconds(double& time)
    {
        return time * SECONDS_PER_HOUR;
    }

    static double convert_seconds_to_hours(double& time)
    {
        return time / SECONDS_PER_HOUR;
    }

    double get_distance()
    {
        double distance;
        cout <<"Enter Distance travelled: " << endl;
        cin >> distance;

        cout << "select units" << endl;
        cout << "[1] metres" << endl;
        cout << "[2] kilometres" << endl;

        int unit;
        cin >> unit;
        switch (unit)
        {
        case 1:
            distance = convert_metres_to_kilometres(distance);
            break;
        case 2:
            distance = convert_kilometres_to_metres(distance);
            break;
        default:
            break;
        }
        return distance;
    }

    static double mps_to_kph(double& velocity)
    {
        return (velocity * SECONDS_PER_HOUR) / METRES_PER_KILOMETRE;
    }
    static double kph_to_mps(double& velocity)
    {
        return (velocity * METRES_PER_KILOMETRE) / SECONDS_PER_HOUR;
    }
    double get_velocity()
    {
        double velocity;
        cout <<"Enter velocity: " << endl;
        cin >> velocity;

        cout << "select units" << endl;
        cout << "[1] metres per second" << endl;
        cout << "[2] kilometres per hour" << endl;

        int unit;
        cin >> unit;
        switch (unit)
        {
        case 1:
            velocity = mps_to_kph(velocity);
            break;
        case 2:
            velocity = kph_to_mps(velocity);
            break;
        default:
            break;
        }
        return velocity;
    }

    static double seconds_to_hours(double& time)
    {
        return time / SECONDS_PER_HOUR;
    }
    static double hours_to_seconds(double& time)
    {
        return time * SECONDS_PER_HOUR;
    }
    double get_time()
    {
        double time;
        cout <<"Enter time taken: " << endl;
        cin >> time;

        cout << "select units" << endl;
        cout << "[1] seconds" << endl;
        cout << "[2] hours" << endl;

        int unit;
        cin >> unit;
        switch (unit)
        {
        case 1:
            time = seconds_to_hours(time);
            break;
        case 2:
            time = hours_to_seconds(time);
            break;
        default:
            break;
        }
        return time;
    }

    template<typename T>
    T length_of_road()
    {
        cout << "whats the length of the stretch?" << endl;
        T length;
        cin >> length;
        if(length <= 0)
        {
            /**
             * recursive loop incase of error
             */
            cout << "Invalid parameter" << endl;
            return length_of_road();
        }
        return T;
    }

    template<typename T = int>
    T number_of_vehicles()
    {
        cout << "whats the number of vehicles?" << endl;
        T number;
        cin >> number;
        if(number <= 0)
        {
            cout << "invalid_parameter" << endl;
            retun number_of_vehicles();
        }
        return number;
    }

    template <typename T>
    T get_duration()
    {
        T duration = 0;
        cout << "Enter duration of observation";
        cin >> duration;
    }
} // namespace traffic
