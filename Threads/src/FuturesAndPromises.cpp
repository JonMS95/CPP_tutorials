/********* Include statements *********/

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include "FuturesAndPromises.hpp"

/**************************************/

/*
From a "human-friendly" perspective, futures and promises can be explained as follows:
·A promise is an object that tells that it will produce a value somewhere in a near future.
·A future is an object that says: "I will eventually receive that value".

Thus, it can be said that they work together as a producer-consumer pair:
·Promise -> sets the value (producer).
·Future  -> gets the value (consumer).
Between both ends, threads can communicate single results safely.

Promises cannot be copied. Use move operator.
*/

/**** Private function prototypes *****/

static int computeSquare(const int x);

/**************************************/

/******** Function definitions *********/

static int computeSquare(const int x)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return (x * x);
}

void exampleUsingFutureAndPromise(void)
{
    // Set a promise. Note that it conveys the type that will be eventually produced.
    std::promise<int> prom;
    // Get a future linked to the promise above. Note the type: it's the same as the promise above.
    std::future<int> fut = prom.get_future();

    // There's no actual need to use lambda functions with promises. I just did this because why not?
    // Note that again, promises are not copiable, thus lambda should catch all values by reference
    // (&) instead of value (=) or a refrence just to the target promise (&prom).
    auto worker_fn = [&prom] (const int value) -> void
    {
        try
        {
            int result = computeSquare(value);
            prom.set_value(result); // deliver result to future
        } catch(...)
        {
            prom.set_exception(std::current_exception()); // deliver exception to future
        }
    };

    std::jthread worker(worker_fn, 12);

    std::cout << "Waiting in main thread..." << std::endl;
    // Current thread waits for future to arrive (wastes no CPU cycles same as with condition variables).
    int value = fut.get();
    std::cout << "Got result: " << value << std::endl;
}

/**************************************/
