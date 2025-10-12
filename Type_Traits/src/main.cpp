/********* Include statements *********/

#include <iostream>
#include "TypeTraitsIntro.hpp"
#include "CompileTimeDecisions.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_TYPE_TRAITS_INTRO      "Testing basic type traits."
#define MSG_TEST_COMPILE_TIME_DECISIONS "Testing compile time decisions."

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestTypeTraitsIntro(void)
{
    PrintTestHeader(MSG_TEST_TYPE_TRAITS_INTRO);

    demoBasicTypeTraits();
}

static void TestCompileTimeDecisions(void)
{
    PrintTestHeader(MSG_TEST_COMPILE_TIME_DECISIONS);

    testVectorSum();
}

int main()
{
    TestTypeTraitsIntro();
    TestCompileTimeDecisions();

    return 0;
}

/**************************************/
