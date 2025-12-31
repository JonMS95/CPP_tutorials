/********* Include statements *********/

#include <iostream>
#include "GeneratorIntro.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER             "*********************************"
#define MSG_TEST_BASIC_GENERATORS   "Testing basic coroutine generators."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestGeneratorIntro(void);

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
    generator_intro::generateNumbersCaller();
}

int main()
{
    TestGeneratorIntro();

    return 0;
}

/**************************************/
