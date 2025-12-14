/********* Include statements *********/

#include <iostream>
#include <thread>
#include <chrono>
#include "BasicThreads.hpp"

/**************************************/

/*
A thread can be created in C++ using std::thread by passing a callable (function, lambda or functor)
to be executed during threads lifetime.

Calling and using it is way simpler than in pure C: just create a thread by passing the callable +
callable's input parameters.

If the aim is to pass those inputs by references, use std::ref (or std::cref if const references are
wanted).

Functions (or more accurately, callables) should return void. Actually, return types are allowed but
they are ignored so there's no point in returning anything.
*/

/**** Private function prototypes *****/

static void printMessageNTimes(const std::string& msg, const int count = 10);
static inline void increment(int& x);
static void forceWait(const int& sleep_seconds);

/**************************************/

/******** Function definitions *********/

static void printMessageNTimes(const std::string& msg, const int count)
{
    for(int i = 0; i < count; i++)
        std::cout << msg << std::endl;
}

static inline void increment(int& x){ ++x; }

static void forceWait(const int& sleep_seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(sleep_seconds));
    std::cout << __func__ << "'s execution ended." << std::endl;
}

void simpleThreadCreation(void)
{
    // Create a thread that runs printMessageNTimes: pass function's name (pointer to function) and its input parameters.
    std::thread t(printMessageNTimes, "Hello from thread!", 5);

    // Wait for t1 to finish.
    t.join();

    std::cout << "Main thread finished (" << __func__ << ")." << std::endl;
}

void threadsWithReferences(void)
{
    int x = 0;

    std::cout << "x: " << x << " (before)." << std::endl;

    // As x is going to be passed as a reference (using std::ref), its value will remain modified afterwards. 
    std::thread t(increment, std::ref(x));
    t.join();

    std::cout << "x: " << x << " (after)." << std::endl;
}

void detachedThreads(void)
{
    const int delay_seconds = 2;

    std::thread t(forceWait, std::cref(delay_seconds));
    t.detach();

    std::cout << "Thread has been detached in "<< __func__ << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

/**************************************/
