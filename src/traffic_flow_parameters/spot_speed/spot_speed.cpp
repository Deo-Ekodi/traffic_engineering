#include "spot_speed.hpp"
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

namespace traffic
{
    double spot_speed()
    {
        double vi = 0;
        double t1, t2, d1, d2;

        std::cout << "enter time 1, time 2, distance 1, \
                distance 2 respectively"
             << std::endl;
        std::cin >> t1, t2, d1, d2;

        vi = (d2 - d1) / (t2 - t1);
        return vi;
    }
} // namespace traffic
