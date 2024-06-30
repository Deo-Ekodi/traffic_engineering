#include "utility.hpp"
#include <iostream>
#include <stdexcept>


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
    std::pair<_velocity<T>&, int&> get_velocity()
    {
        _velocity<T> velocity;
        int option = 0;
        std::cout << "enter [1] for velocity in kilometres per hour" << std::endl;
        std::cout << "enter [2] for velocity in metres per second" << std::endl;
        
        std::pair<_velocity<T>&, int&> pr;
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
                pr.second = UNIT_KPH;
                break;
            case 2:
                velocity.set_mps(vel);
                pr.second = UNIT_MPS;
                break;
            default:
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        pr.first = velocity;
        return pr;
    }

    template <typename T>
    static inline T get_cummulative_velocity()
    {
        T vel;
        uint32_t num = get_number_of_vehicles();
        std::cout << "Enter number of vehicles" << std::endl;
        std::cin >> num;
        std::cout << "enter respective velocities" << std::end;
        uint32_t i{0};
        while(i < num)
        {
            std::cout << "vehicle[" << i << "]: ";
            std::cin >> vel;
            std::cout << endl;
            ++i;
        }
        return vel;
    }

    template <typename T>
    std::pair<T&, int&> get_velocity_cummulative()
    {
        T velocity;
        std::cout << "enter [1] for Km/h" << std::cndl;
        std::cout << "enter [2] for m/s" << std::endl;
        std::pair<velocity&, UNIT> pr;
        int option{0};
        cin >> option;
        switch (option)
        {
        case 1:
            pr.first = get_cummulative_velocity();
            pr.second = UNIT_KM;
            break;
        case 2:
            pr.first = get_cummulative_velocity();
            pr.second = UNIT_MTR;
        
        default:
            break;
        }
        return pr;
    }

    template <typename T>
    std::pair<_time<T>&, int&> get_duration()
    {
        _time<T> _duration;
        int option = 0;
        std::cout << "enter [1] for duration in hours" << std::endl;
        std::cout << "enter [2] for duration in seconds" << std::endl;
        
        std::pair<_time<T>&, int&> pr;
        pr.second = UNIT;
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
                pr.first = _duration;
                pr.second = UNIT_HR;
                break;
            case 2:
                _duration.set_sec(dur);
                pr.first = _duration;
                pr.second = UNIT_SEC;
                break;
            default:
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return pr;
    }

    /**
     * provides cummulative durarions regardless of hours or minutes
     */
    template <typename T>
    static inline T get_cummulative_durations()
    {
        T cummulatives = 0.0, res = 0.0;
        uint32_t  num{0}, i{0};
        std::cout << "how many vehicles observed?" << std::endl;
        std::cin >> num;
        std::cout << "enter durations" << std::endl;
        while (i < num)
        {
            cin >> cummmuatives;
            res += cummulatives;
            ++i;
        }
        
        return res;
    }

    template <typename T>
    std::pair<T&, int&> get_duration_cummulative()
    {
        T cummulative{0.0};
        int option = 0;
        std::cout << "enter [1] for cummulative duration in hours" << std::endl;
        std::cout << "enter [2] for cummulative duration in seconds" << std::endl;

        std::pair<T&, int&> pr;
        
        try
        {
            if(option != 1 || option != 2)
            {
                throw std::invalid_argument("get_diration_cummulative() : invalid parameter");
            }

            switch (option)
            {
                std::cout << "enter duration" << std::endl;
            // duration in hours
            case 1:
                pr.first = get_cummulative_durations();
                pr.second = UNIT_HR;
                break;
            case 2:
                pr.first  get_cummulative_durations();
                pr.second = UNIT_SEC;
                break;
            
            default:
                break;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        return pr;
    }

    template<typename T>
    std::pair<T&, int&> get_length_of_road()
    {
        std::pair<T&, int&> pr;
        std::cout << "whats the length of the stretch?" << std::endl;
        T length;
        int units;
        std::cin >> length;
        std::cout << "selects units [1] - kilometres, [2] - metres" << std::endl;
        std::cin >> units;
        try
        {
            if(length <= 0)
            {
                throw std::invalid_argument("get_length_of_road() : invalid length entered");
            }
            if(units != 1 || units != 2)
            {
                throw std::invalid_argument("get_length_of_road() : invalid unit argument");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        pr.first = length;
        if(units == 1)
            pr.second = UNIT_KM;
        if(units == 2)
            pr.second = UNIT_MTR;
        
        return pr;
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
