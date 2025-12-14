/********* Include statements *********/

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <semaphore>
#include "Semaphores.hpp"

/**************************************/

/*
Same as C, C++ included semaphores in C++20. A semaphore is a synchronization primitive that manages access
to a limited number of resources/slots. It works as a counter, keeping track of the free slots.

Two main types exist in C++:
·std::counting_semaphore<N>: counts up to N, allowing multiple threads to proceed.
·std::binary_semaphore: counter is 0 or 1, acting same as a mutex.

Common usage example: limiting number of threads trying to connect with a server (we may know number of
requests) server can handle at the same time.

Typical syntax:
std::counting_semaphore<max_num> sem(initial_num);
Where max_num is the maximum number the semaphore can hold and initial_num is its initial value.
Use the .acquire/release methods when trying to use a semaphore.
Different methods are available too (such as .try_* methods or .max).

Note that each time a semaphore slot is acquired, its internal counter diminishes by one, so it should
never have 0 as intial value (it will simply be impossible to get a free slot).
*/

/******** Function definitions *********/

template<int max_sem_val>
static void simulateClientCall(std::counting_semaphore<max_sem_val>& sem)
{
    // Try to acquire a slot from the provided semaphore.
    sem.acquire();
    std::cout << "Semaphore's slot acquired by " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sem.release();
}

void accessLimitedresources(void)
{
    const int num_of_th     = 5;
    const int max_sem_val   = 3;
    const int ini_sem_val   = max_sem_val;

    std::vector<std::thread> threads(num_of_th);

    std::counting_semaphore<max_sem_val> sem(ini_sem_val);

    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i] = std::thread(simulateClientCall<max_sem_val>, std::ref(sem));
    
    for(int i = 0; i < static_cast<int>(threads.size()); i++)
        threads[i].join();
}

/**************************************/
