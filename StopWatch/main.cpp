
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
#include <algorithm>
#include "StopWatch.h"


int main(int argc, char* argv[])
{

    StopWatch watch;

    watch.Start();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    watch.Stop();
    std::cout << watch.Duration() << std::endl;


    watch.Start();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    watch.Stop();
    std::cout << watch.Duration() << std::endl;


    return 0;
}