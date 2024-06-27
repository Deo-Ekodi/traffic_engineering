#include <iostream>

#include "time_mean_speed.hpp"
#include "spot_speed/spot_speed.hpp"

using namespace std;

namespace traffic
{
    template <typename T, typename N = int>
    T time_mean_speed()
    {
        T tms;
        N i{0};

        std::cout << "how many vehicles are you  \
                 dealing with?"
        std::cout << std::endl;

        N n;
        std::cin >> n;

        while (i < n)
        {
            tms += spot_speed();
            ++i;
        }
        return tms / n;
    }
} // namespace traffic
