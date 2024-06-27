#include <iostream>

#include "spot_speed/spot_speed.hpp"
#include "utility/utility.hpp"

using namespace std;

namespace traffic
{
    template <typename T>
    T time_mean_speed()
    {
        T tms;
        uint32_t n = get_number_of_vehicles();
        uint32_t i{0};

        while (i < n)
        {
            tms += spot_speed();
            ++i;
        }
        return tms / n;
    }
} // namespace traffic
