#include "concentration.hpp"
#include "utility/utility.hpp"

#include <iostream>



namespace traffic
{
    template <typename T>
    static inline T concentration_generic()
    {
        std::pair<_time<T>&, int&> duration = get_duration();
        std::pair<T&, int&> cummulatve_duration = get_duration_cummulative();
        std::pair<T&, int&> length = get_length_of_road();
        T _length, _duration, _cumm_duration;

        _duration = duration.first;
        _length = length.first;
        _cumm_duration = cummulatve_duration.first;
        if(duration.second == UNIT_SEC)
        {
            _duration = convert_seconds_to_hours(duration.first);
        }
        if(cummulatve_duration.second == UNIT_SEC)
        {
            _cumm_duration = convert_seconds_to_hours(cummulatve_duration.first);
        }
        if(length.second == UNIT_MTR)
        {
            _length = convert_metres_to_kilometres(length.first);
        }
        return _cumm_duration / (_duration * _length);
    }

    template <typename T>
    T concentration()
    {
        return concentration_generic();
    }
}   //  namespace traffic