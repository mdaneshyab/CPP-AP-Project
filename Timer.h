#pragma once
#include <ctime>
#include <iostream>

class Timer
{
    std::clock_t b; // begin
    std::clock_t e; // end

public:
    void clear() { b = e = std::clock(); }
    void start() { b = std::clock(); }
    void stop() { e = std::clock(); }

    friend std::ostream& operator<< (std::ostream& o, const Timer& timer)
    {
        return o << timer.milliseconds();
    }

    // return time difference in milliseconds
    double milliseconds() const
    {
        if (e <= b)
            return 0.0;
        return 1000.0 * (e - b) / CLOCKS_PER_SEC;
    }
};
