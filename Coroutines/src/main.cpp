/********* Include statements *********/

#include <iostream>
#include "GeneratorIntro.hpp"
#include "AsyncTasks.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER             "*********************************"
#define MSG_TEST_BASIC_GENERATORS   "Testing basic coroutine generators."
#define MSG_TEST_ASYNC_TASKS        "Testing asynchronous tasks."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestGeneratorIntro(void);
static void TestAsynchronousTasks(void);

/**************************************/

/********** Global variables **********/

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestGeneratorIntro(void)
{
    PrintTestHeader(MSG_TEST_BASIC_GENERATORS);
    generator_intro::numbersGeneratorCaller();
    generator_intro::squaresGeneratorCaller();
    generator_intro::counterGeneratorCaller();
    generator_intro::counterGeneratorCaller(false);
}

static void TestAsynchronousTasks(void)
{
    PrintTestHeader(MSG_TEST_ASYNC_TASKS);
    async_coroutines::dummyTaskCaller();
}

int main()
{
    TestGeneratorIntro();
    TestAsynchronousTasks();

    return 0;
}

/**************************************/
