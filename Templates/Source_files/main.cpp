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

    std::cout << "3 + 4 = " << TemplateAdd(3, 4) << std::endl;
    std::cout << "2.3 + 4.9 = " << TemplateAdd(2.3, 4.9) << std::endl;
    std::cout << "Hello + World = " << TemplateAdd((std::string)"Hello", (std::string)"World") << std::endl;
}

int main()
{
    TestTemplates();

    return 0;
}

/**************************************/
