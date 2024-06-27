#include "flow_rate.hpp"
#include "utility/utility.hpp"


namespace traffic
{
    template <typename T>
    T flow_rate()
    {
        return get_number_of_vehicles() / get_duration();
    }
} // namespace traffic
