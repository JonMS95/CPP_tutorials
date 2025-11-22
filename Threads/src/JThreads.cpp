/********* Include statements *********/

#include <iostream>
#include <thread>
#include <mutex>
#include "JThreads.hpp"

/**************************************/

/*
JThreads are same as common threads, but with no need to be joined explicitly (they will do so by themselves).
*/

/********* Using statements ***********/

using ull = unsigned long long;

/**************************************/

/**** Private function prototypes *****/

static void incrementCounterNTimes(ull& counter, const ull& times, std::mutex& m);

/**************************************/

/******** Function definitions *********/

static void incrementCounterNTimes(ull& counter, const ull& times, std::mutex& m)
{
    for(ull i = 0; i < times; i++)
    {
        std::unique_lock<std::mutex> lock(m);
        ++counter;
    }
}

void incrementCounterWithTwoJThreads(void)
{
    ull counter = 0;
    const ull times = 100000;
    std::mutex m;

    // A scoped is initialized here so as to make sure that the counter has been fully incremented by the point it's meant to be printed.
    {
        std::jthread t0(incrementCounterNTimes, std::ref(counter), std::cref(times), std::ref(m));
        std::jthread t1(incrementCounterNTimes, std::ref(counter), std::cref(times), std::ref(m));
    }

    std::cout << "Counter value after having been incremented " << times << " times: " << counter << std::endl;
}

/**************************************/
