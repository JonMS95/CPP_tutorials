/********* Include statements *********/

#include <iostream>
#include "BasicRanges.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_BASIC_RANGES   "Testing basic ranges."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestBasicRanges(void);

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestBasicRanges(void)
{
    PrintTestHeader(MSG_TEST_BASIC_RANGES);

    range_basics::iterateVector();
    range_basics::iterateList();
    range_basics::iterateString();
    range_basics::iterateTemporaryRange();
}

int main()
{
    TestBasicRanges();

    return 0;
}

/**************************************/
