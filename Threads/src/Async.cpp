/********* Include statements *********/

#include <iostream>
#include <thread>
#include <chrono>
#include <future>

/**************************************/

/*

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

void asyncExample(void)
{

}

/**************************************/
