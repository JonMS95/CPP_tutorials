/********* Include statements *********/

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include "Atomic.hpp"

/**************************************/

/*
C++11 introduced atomic keyword. std::atomic<T> is a template that forces compiler to use single-step instructions
such as XADD, XCHG among others (that's why it's called "atomic"). Those operations guarantee atomicity, preventing
different threads from interacting with simple variables at the same time.

A common example is the one in which two different threads increment a variable multiple times. Internally, the
variable is stored in a register, incremented and finally the result is stored in the original memory address again.
Using atomic instructions avoid this.

This type of operations cannot be used alongside callables, but it's strongly recommended with basic types in multi-
threaded environments.

Note that the only thing it can guarantee is that a variable (a single one) is written/read at a time by a thread, not
that a sequence is executed a time by each thread. For instance, if a task meant to be executed by different thread
implies incrementing two counters (let's say, A and B respectively), each of them is incremented atomically, by a
single thread, but ensuring each set of instructions is executed by each thread then by another is simply not possible.
*/

/********* Using statements ***********/

using ull = unsigned long long;

/**************************************/

/**** Private function prototypes *****/

static void incrementCounter(std::atomic<ull>& x, ull times = 1000000);

/**************************************/

/******** Function definitions *********/

static void incrementCounter(std::atomic<ull>& x, ull times)
{
    for(ull i = 0; i < times; i++)
        ++x;
}

void incrementAtomicWithNThreads(int thread_num)
{
    std::atomic<ull> x;
    constexpr ull inc_num = 10^6;

    std::vector<std::thread> threads(thread_num);

    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i] = std::thread(incrementCounter, std::ref(x), inc_num);
    
    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i].join();
    
    std::cout << "x (atomic variable) after being incremented by " << thread_num << " " << inc_num << " times: " << x << std::endl;
}

/**************************************/
