/********* Include statements *********/

#include <iostream>
#include <chrono>
#include <thread>
#include <condition_variable>
#include "ConditionVariables.hpp"

/**************************************/

/*
Same as in C's pthread library, a condition variable is a tool that lets one thread sleep
until another tells it to wake up.
*/

/**** Private function prototypes *****/

static void consumer(std::mutex& m, bool& ready, std::condition_variable& cv);
static void producer(std::mutex& m, bool& ready, std::condition_variable& cv);

/**************************************/

/******** Function definitions *********/

static void producer(std::mutex& m, bool& ready, std::condition_variable& cv)
{
    // Sleeps initially so as to let consumer thread go first.
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        // Within current scope, lock provided mutex and turn "ready" variable true (signalling condition variable).
        std::lock_guard<std::mutex> lock(m);
        ready = true;
        std::cout << "Producer says: data is ready." << std::endl;
    }

    // Tell waiting thread to wake up. Note that waking up does not mean going ahead, since a status variable
    // exists (ready).
    cv.notify_one();
}

static void consumer(std::mutex& m, bool& ready, std::condition_variable& cv)
{
    std::unique_lock<std::mutex> lock(m);

    std::cout << "Lock is acquired by consumer." << std::endl;

    // Mutex is unlcked since "ready" variable is initially false. It will steadily
    // keep waiting until producer thread tells it to wake up. Thread is slept wasting
    // no CPU cycles.
    cv.wait(lock, [&] {return ready;});

    // With mutex locked, print message below and exit (unlocking mutex on it's way,
    // as it's scoped).
    std::cout << "Consumer says: data-ready condition detected." << std::endl;
}

void conditionConsumerProducerExample(void)
{
    std::mutex m;
    bool r = false;
    std::condition_variable cv;

    std::thread t0(producer, std::ref(m), std::ref(r), std::ref(cv));
    std::thread t1(consumer, std::ref(m), std::ref(r), std::ref(cv));

    t0.join();
    t1.join();
}

/**************************************/
