#include "spot_speed.hpp"
#include "utility/utility.hpp"

using namespace std;

namespace traffic

{
    /**
     * generic function for calculating spot speed
     */
    template <typename T>
    static inline T v1_v2()
    {
        _distance<T> d1, d2;
        d1 = get_distance();
        d2 = get_distance();

        _time<T> t1, t2;
        t1 = get_duration();
        t2 = get_duration();

        std::cout << "[1] spot speed in km/h" << std::endl;
        std::cout << "[2] spot sped in m/s" << std::endl;

        int option{0};
        std::cin >> option;
        
        switch (option)
        {
        case 1:
            return (d1.get_km() - d2.get_km()) / (t1.get_hrs - t2.get_hrs());
        case 2:
            return (d1.get_mtr() - d2.get_mtr()) / (t1.get_sec() - t2.get_sec());
        default:
            break;
        }
    return 0.0;
    }
    
    template <typename T>
    T spot_speed()
    {
        return v1_v2();
    }
} // namespace traffic
