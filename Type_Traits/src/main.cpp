/********* Include statements *********/

#include <iostream>
#include "TypeTraitsIntro.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER             "*********************************"
#define MSG_TEST_TYPE_TRAITS_INTRO  "Testing basic type traits."

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TesttypeTraitsIntro(void)
{
    PrintTestHeader(MSG_TEST_TYPE_TRAITS_INTRO);

    demoBasicTypeTraits();
}

int main()
{
    TesttypeTraitsIntro();

    return 0;
}

/**************************************/
