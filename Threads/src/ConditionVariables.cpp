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
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lock(m);
        ready = true;
        std::cout << "Producer says: data is ready." << std::endl;
    }

    // Tell waiting thread to wake up.
    cv.notify_one();
}

static void consumer(std::mutex& m, bool& ready, std::condition_variable& cv)
{
    std::unique_lock<std::mutex> lock(m);

    cv.wait(lock, [&] {return ready;});

    std::cout << "Consumer says: data-ready condition detected." << std::endl;
}

void conditionConsumerProducerExample(void)
{
    std::mutex m;
    bool r;
    std::condition_variable cv;

    std::thread t0(producer, std::ref(m), std::ref(r), std::ref(cv));
    std::thread t1(consumer, std::ref(m), std::ref(r), std::ref(cv));

    t0.join();
    t1.join();
}

/**************************************/
