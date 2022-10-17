#include "StopWatch.h"
#include <iostream>



void StopWatch::Start()
{
    if(!m_isRunning)
       {
         m_start = std::chrono::system_clock::now();
         m_isRunning = true;
       }
}


void StopWatch::Stop()
{
    if(m_isRunning)
    {
        m_stop = std::chrono::system_clock::now();
        m_isRunning = false;
    }

}


std::string  StopWatch::Duration()
{
    if(!m_isRunning)
        {
            std::chrono::duration<double> dur = m_stop - m_start;
            auto x = std::chrono::duration_cast<std::chrono::seconds>(dur);
            return std::to_string(x.count()) + " seconds.";
        }

    return "0";
}