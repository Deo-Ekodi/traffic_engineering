#include "space_mean_speed.hpp"
#include "utility/utility.hpp"

#include <iostream>
using namespace std;

namespace traffic
{
    template <typename T>
    T space_mean_speed()
    {
        T length = length_of_road();
        int number = number_of_vehicles();
        int i{0};
        T time{0};

        while(i < number)
        {
            /**
             * cummulative time
             */
            time += get_time();
        }
        return (length * number) / time;
    }
} // namespace traffic
