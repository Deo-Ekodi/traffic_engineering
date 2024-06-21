#include "flow_rate.hpp"
#include "utility/utility.hpp"

#include <iostream>
using namespace std;

namespace traffic
{
    template <typename T>
    T flow_rate()
    {
        return number_of_vehicles() / get_time();
    }
} // namespace traffic
