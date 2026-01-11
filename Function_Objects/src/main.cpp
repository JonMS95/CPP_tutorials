/********* Include statements *********/

#include <iostream>
#include "BasicFunctors.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_BASIC_FUNCTORS "Testing basic functors."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestBasicFunctors(void);

/**************************************/

/********** Global variables **********/

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestBasicFunctors(void)
{
    PrintTestHeader(MSG_TEST_BASIC_FUNCTORS);
    basic_functors::MinimalFunctorExample();
    basic_functors::FunctorWithState();
}

int main()
{
    TestBasicFunctors();

    return 0;
}

/**************************************/
