#include "utility.hpp"
#include <iostream>


namespace traffic
{
    template <typename T>
    T convert_kilometres_to_metres(T& distance)
    {
        return distance * METRES_PER_KILOMETRE;
    }

    template <typename T>
    T convert_metres_to_kilometres(T& distance)
    {
        return distance / METRES_PER_KILOMETRE;
    }

    template <typename T>
    T convert_metres_per_second_to_kilometres_per_hour(T& vel)
    {
        return (vel * (SECONDS_PER_HOUR / METRES_PER_KILOMETRE));
    }

    template <typename T>
    T convert_kilometres_per_hour_to_metres_per_second(T& vel)
    {
        return (vel * (METRES_PER_KILOMETRE / SECONDS_PER_HOUR));
    }

    template <typename T>
    T convert_hours_to_seconds(T& _time)
    {
        return _time.hrs * SECONDS_PER_HOUR;
    }

    template <typename T>
    T convert_seconds_to_hours(T& _time)
    {
        return _time.sec / SECONDS_PER_HOUR;
    }

    template <typename T>
    _distance<T> get_distance()
    {
        _distance<T> distance;
        
        int option = 0;
        std::cout << "enter [1] for distance in kilometres" << std::endl;
        std::cout << "enter [2] for distance in metres" << std::endl;
        
        std::cin >> option;

        try
        {
            // assert option
            if(option != 1 || option != 2)
            {
                throw invalid_argument("get_distance() : option selected must be between [1] or [2]");
            }
            
            T dist;
            std::cout << "enter distance" << std::endl;
            std::cin >> dist;

            // assert distance
            if(!isdigit(dist) || !is_unsigned(dist))
            {
                throw invalid_argument("get_distance() : invalid distance entered");
            }
            // if okay
            switch (option)
            {
            case 1:
                distance.set_km(dist);
                return distance;
                break;
            case 2:
                distance.set_mtr(dist);
                return distance;
                break;
            default:
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        return distance;
        
    }

    template <typename T>
    _velocity<T> get_velocity()
    {
        _velocity<T> velocity;
        int option = 0;
        std::cout << "enter [1] for velocity in kilometres per hour" << std::endl;
        std::cout << "enter [2] for velocity in metres per second" << std::endl;
        
        std::cin >> option;
        try
        {
            // assert option
            if(option != 1 || option != 2)
            {
                throw invalid_argument("get_velocity() : option selected must be between [1] or [2]");
            }
            
            T vel;
            std::cout << "enter velocity" << std::endl;
            std::cin >> vel;

            // assert distance
            if(!isdigit(dist) || !is_unsigned(dist))
            {
                throw invalid_argument("get_velocity() : invalid velocity entered");
            }
            // if okay
            switch (option)
            {
            case 1:
                velocity.set_kph(vel);
                return vel;
                break;
            case 2:
                velocity.set_mps(vel);
                return velocity;
                break;
            default:
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    template <typename T>
    _time<T> get_duration()
    {
        _time<T> _duration;
        int option = 0;
        std::cout << "enter [1] for duration in hours" << std::endl;
        std::cout << "enter [2] for duration in seconds" << std::endl;
        
        std::cin >> option;
        try
        {
            // assert option
            if(option != 1 || option != 2)
            {
                throw invalid_argument("get_duration() : option selected must be between [1] or [2]");
            }
            
            T dur;
            std::cout << "enter time" << std::endl;
            std::cin >> dur;

            // assert distance
            if(!isdigit(dur) || !is_unsigned(dur))
            {
                throw invalid_argument("get_duration() : invalid duration entered");
            }
            // if okay
            switch (option)
            {
            case 1:
                _duration.set_hrs(dur);
                return _duration;
                break;
            case 2:
                _duration.set_sec(dur);
                return _duration;
                break;
            default:
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return _duration;
    }

    template<typename T>
    T get_length_of_road()
    {
        std::cout << "whats the length of the stretch?" << std::endl;
        T length;
        std::cin >> length;
        try
        {
            if(length <= 0)
            {
                throw std::invalid_argument("get_length_of_road() : invalid length entered");
            }
            return length;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        return length;
    }

    template<typename T = uint32_t>
    T get_number_of_vehicles()
    {
        std::cout << "whats the number of vehicles?" << std::endl;
        T number;
        std::cin >> number;

        try
        {
            if(number <= 0)
            {
                throw std::invalid_argument("get_number_of_vehivles() : invalid number of vehicles");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        return number;
    }

} // namespace traffic
