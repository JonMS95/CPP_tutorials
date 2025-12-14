/********* Include statements *********/

#include <iostream>
#include <thread>
#include <vector>
#include <latch>
#include "Latches.hpp"

/**************************************/

/*
Similar to C's barriers, a latch is a mechanism that works as a synchronization point for multiple threads.
It's one-shot mechanism, so it does only work once. Basically, latches work as a counter that let all waiting
threads go ahead solely when such counter has arrived to zero.
*/

/**** Private function prototypes *****/

static void dummyTask(std::latch& l, int& s);

/**************************************/

/******** Function definitions *********/

static void dummyTask(std::latch& l, int& s)
{
    std::this_thread::sleep_for(std::chrono::seconds(s));

    std::cout << "thread with id: " << std::this_thread::get_id() << " arrived." << std::endl;

    l.arrive_and_wait();
}

void syncThreadsWithCheckpoint(void)
{
    const int num_of_th = 3;
    std::vector<std::thread> threads(num_of_th);
    std::latch l(num_of_th);

    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i] = std::thread(dummyTask, std::ref(l), std::ref(i));
    
    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i].join();
}

/**************************************/
