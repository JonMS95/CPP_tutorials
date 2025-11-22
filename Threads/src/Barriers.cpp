/********* Include statements *********/

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <barrier>
#include "Barriers.hpp"

/**************************************/

/*
Barriers work in the same way as latches but multiple times (same as in C). Different from latches,
barriers can be initialized with a lambda completion function, that will be executed once its internal
counter reaches zero.
*/

/**** Private function prototypes *****/

static void syncPointFunction(std::barrier<>& bar);
static void createThreadsAndWaitInBarrier(std::barrier<>& bar, const int number_of_threads = 3);

/**************************************/

/******** Function definitions *********/

static void syncPointFunction(std::barrier<>& bar)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread with id: " << std::this_thread::get_id() << " has just arrived at sync point." << std::endl;
    bar.arrive_and_wait();
}

static void createThreadsAndWaitInBarrier(std::barrier<>& bar, const int number_of_threads)
{
    std::vector<std::thread> threads(number_of_threads);

    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i] = std::thread(syncPointFunction, std::ref(bar));
    
    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i].join();
}

void syncThreadsInLoop(void)
{
    const int num_of_th = 3;
    const int num_of_loops = 2;

    std::barrier b(num_of_th);

    for(int i = 0; i < num_of_loops; i++)
        createThreadsAndWaitInBarrier(b);
}

/**************************************/
