#pragma once
#include <chrono>
#include <thread>
#include <iostream>
class Timer
{
    // make things readable
    using clk = std::chrono::steady_clock;

    clk::time_point b; // begin
    clk::time_point e; // end

public:
    void clear() { b = e = clk::now(); }
    void start() { b = clk::now(); }
    void stop() { e = clk::now(); }

    friend std::ostream& operator<< (std::ostream& o, const Timer& timer)
    {
        return o << timer.milliseconds();
    }

    // return time difference in milliseconds
    double milliseconds() const
    {
        if (e <= b)
            return 0.0;
        auto d = std::chrono::duration_cast<std::chrono::milliseconds>(e - b);
        return d.count();
    }
};