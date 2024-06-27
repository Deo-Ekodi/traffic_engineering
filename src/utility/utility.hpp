#pragma once

#include "vehicle/vehicle.hpp"


namespace traffic
{
    #define SECONDS_PER_HOUR    3600
    #define SECONDS_PER_MINUTE  60
    #define MINUTES_PER_HOUR    60
    #define METRES_PER_KILOMETRE  1000
    // #define

    /**
     * invalid parameter
     */
    #define EINVAL  1

    /**
     * distance in kilometres to metres
     */
    template <typename T>
    T convert_kilometres_to_metres(T& distance);

    /**
     * distance in metres to kilometres
     */
    template <typename T>
    T convert_metres_to_kilometres(T& distance);

    /**
     * speed in kph to mps
     */
    template <typename T>
    T convert_kilometres_per_hour_to_metres_per_second(T& vel);

    /**
     * speed in mps to kph
     */
    template <typename T>
    T convert_metres_per_second_to_kilometres_per_hour(T& vel);

    /**
     * hours to seconds
     */
    template <typename T>
    T convert_hours_to_seconds(T& _time);

    /**
     * sec to hr
     */
    template <typename T>
    T convert_seconds_to_hours(T& _time);


    /**
     * number of vehicles counted
     */
    template<typename T = uint32_t>
    T get_number_of_vehicles();

    /**
     * length of road under analysis
     */
    template<typename T>
    T get_length_of_road();

    /**
     * GET_DURATION
     * duration of observation
     * #donotCONFUSE with get_time()
     */
    template <typename T>
    _time<T> get_duration();

    // /**
    //  * duration of a specific event
    //  */
    // template <typename T>
    // T get_duration();

    /**
     * get velocity of vehicle
     */
    template <typename T>
    _velocity<T> get_velocity();

    /**
     * get distance traversed
     */
    template <typename T>
    _distance<T> get_distance();

/**
 * _VELOCITY
 * Infers rate of traversing a stretch
 * Can be expressed as:
 * 1. m/s
 * 2. km/h
 */
    template<typename T>
    class _velocity
    {
    private:
        /**
         * velocity in meters per second
         */
        T mps;
        /**
         * velocity in kilometres per hour
         */
        T kph;
    public:
        _velocity(/* args */)
        {
            mps = 0.0;
            kph = 0.0;
        }

        void set_mps(T& mps)
        {
            this->mps = mps;
            this->kph = convert_metres_per_seconnd_to_kilometres_per_hour(mps);
        }
        void set_kph(T& kph)
        {
            this->kph = kph;
            this->mps = convert_kilometres_per_hour_to_metres_per_second(kph);
        }
        /**
         * speed in kilometres_per_hour
         */
        T get_kph()const noexcept
        {
            return this->kph;
        }
        /**
         * speed in metres per second
         */
        T get_mps()const noexcept
        {
            return this->mps;
        }
    };

    /**
     * _TIME
     * Infers measure of duration of an event
     * can be espressed as:
     * 1. hours
     * 2. minutes (not supported currently)
     * 3. seconds
     */
    template <typename T>
    class _time
    {
    private:
        /**
         * time in seconds
         */
        T sec;
        /**
         * time in hours
         */
        T hrs;
    public:
        _time(/* args */)
        {
            sec = 0.0;
            hrs = 0.0;
        }

        void set_sec(T& sec)
        {
            this->sec = sec;
            this->hrs = convert_seconds_to_hours(sec);
        }
        void set_hrs(T& hrs)
        {
            this->hrs = hrs;
            this->sec = convert_hours_to_seconds(hrs);
        }
        /**
         * time in seconds
         */
        T get_sec()const noexcept
        {
            return this->sec;
        }
        /**
         * time in hours
         */
        T get_hrs()const noexcept
        {
            return this->hrs;
        }
    };

    /**
     * _DISTANCE
     * Infers the spatial coponent of displacement
     * can be expressed in:
     * 1. metres
     * 2. kilometres
     */
    template <typename T>
    class _distance
    {
    private:
        /**
         * distance in metres
         */
        T mtr;
        /**
         * distance in kilmetres
         */
        T km;
    public:
        _distance(/* args */)
        {
            mtr = 0.0;
            km = 0.0;
        }

        void set_km(T& km)noexcept
        {
            this->km = km;
            this->mtr = convert_kilometres_to_metres(km);
        }
        void set_mtr(T& mtr)noexcept
        {
            this->mtr = mtr;
            this->km = convert_metres_to_kilometres(mtr);
        }
        /**
         * distance in metres
         */
        T get_mtr()const noexcept
        {
            return this->mtr;
        }
        /**
         * distance in kilometres
         */
        T get_km()const noexcept
        {
            return this->km;
        }
    };

} // namespace traffic
