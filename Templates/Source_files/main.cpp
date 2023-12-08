// This is an attempt to grasp all the nuances when it comes to Classes in C++.
// Classes in C++ have already been studied, so this is more like brushing up on the topic rather than starting up from scratch for me.

/********* Include statements *********/

#include <iostream>
#include "Templates.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER     "*********************************"
#define MSG_TEST_TEMPLATES  "Testing Templates."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestTemplates()
{
    PrintTestHeader(MSG_TEST_TEMPLATES);
}

int main()
{
    TestTemplates();

    return 0;
}

/**************************************/
