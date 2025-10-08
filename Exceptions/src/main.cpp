/********* Include statements *********/

#include <iostream>
#include "BasicExceptions.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_BASIC_EXCEPTIONS       "Testing basic exceptions."
#define MSG_TEST_EXCEPTION_TYPES        "Testing exception types."
#define MSG_TEST_FILE_IO_EXCEPTIONS     "Testing file I/O exceptions."
#define MSG_TEST_CUSTOM_EXCEPTIONS      "Testing custom exceptions."

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestBasicExceptions(void)
{
    PrintTestHeader(MSG_TEST_BASIC_EXCEPTIONS);

    throwingBuiltInTypes();
    throwStandardException();
    try2divide();
    exceptionHierarchy();
}

static void TestExceptionTypes(void)
{
    PrintTestHeader(MSG_TEST_EXCEPTION_TYPES);
}

static void TestFileIOExceptions(void)
{
    PrintTestHeader(MSG_TEST_FILE_IO_EXCEPTIONS);
}

static void TestCustomExceptions(void)
{
    PrintTestHeader(MSG_TEST_CUSTOM_EXCEPTIONS);
}

int main()
{
    TestBasicExceptions();
    TestExceptionTypes();
    TestFileIOExceptions();
    TestCustomExceptions();

    return 0;
}

/**************************************/
