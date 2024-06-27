#include "space_mean_speed.hpp"
#include "utility/utility.hpp"
#include <iostream>

namespace traffic
{
    template <typename T>
    T sms_in_kph(std::pair<T&, int&> length, std::pair<T&, int> times, uint32_t number)
    {
        T _length, _times;
        _length = length.first;
        _times = times.first;
        if(length.second == UNIT_MTR)
        {
            /**
             * convert to kilometres
             */
            _length = convert_metres_to_kilometres(length.first);
        }
        if(times.second == UNIT_SEC)
        {
            /**
             * convert seconds to hours
             */
            _times = convert_seconds_to_hours(times.first);
        }

        return (_length * number) / _times;
    }
    template <typename T>
    T sms_in_mps(std::pair<T&, int&> length, std::pair<T&, int> times, uint32_t number)
    {
        T _length, _times;
        _length = length.first;
        _times = times.first;
        if(length.second == UNIT_KM)
        {
            /**
             * convert to kilometres
             */
            _length = convert_kilometres_to_metres(length.first);
        }
        if(times.second == UNIT_HR)
        {
            /**
             * convert seconds to hours
             */
            _times = convert_hours_to_seconds(times.first);
        }

        return (_length * number) / _times;
    }
    template <typename T>
    T space_mean_speed()
    {
        std::pair<T&, int&> length = get_length_of_road();
        uint32_t number = get_number_of_vehicles();
        std::pair<T&, int&> cummulative_time = get_duration_cummulative();

        std::cout << "space mean speed in [1] m/s or [2] km/h" << std::endl;
        int option;
        std::cin >> option ;

        try
        {
            if(option != 1 || option != 2)
            {
                throw std::invalid_argument("space_mean_speed() : invalid option");
            }
            switch (option)
            {
                case 1:
                    return sms_in_kph(length, cummulative_time, number);
                case 2:
                    return sms_in_mps(length, cummulative_time, number);
                default:
                    break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return 0;
    }
} // namespace traffic
