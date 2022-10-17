#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <string>
#include <chrono>
#include <ctime>

class StopWatch
{
    public:
        void            Start();
        void            Stop();
        std::string     Duration();

    private:

        bool                                    m_isRunning{false};
        std::chrono::system_clock::time_point   m_start{};
        std::chrono::system_clock::time_point   m_stop{};
        std::chrono::system_clock::time_point   m_duration{};
                       




};

#endif