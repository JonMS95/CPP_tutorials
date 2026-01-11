/********* Include statements *********/

#include <iostream>
#include "BasicFunctors.hpp"
#include "StdFunctionBasics.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_BASIC_FUNCTORS         "Testing basic functors."
#define MSG_TEST_STD_FUNCTION_BASICS    "Testing STD function basics."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestBasicFunctors(void);
static void TestStdFunctionsBasics(void);

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

static void TestStdFunctionsBasics(void)
{
    PrintTestHeader(MSG_TEST_STD_FUNCTION_BASICS);
    std_function_basics::runStdFunctionBasics();
}

int main()
{
    TestBasicFunctors();
    TestStdFunctionsBasics();

    return 0;
}

/**************************************/
