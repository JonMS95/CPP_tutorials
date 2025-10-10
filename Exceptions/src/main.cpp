/********* Include statements *********/

#include <iostream>
#include "BasicExceptions.hpp"
#include "ExceptionTypes.hpp"
#include "IOExceptions.hpp"
#include "CustomExceptions.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_BASIC_EXCEPTIONS       "Testing basic exceptions."
#define MSG_TEST_EXCEPTION_TYPES        "Testing exception types."
#define MSG_TEST_FILE_IO_EXCEPTIONS     "Testing file I/O exceptions."
#define MSG_TEST_CUSTOM_EXCEPTIONS      "Testing custom exceptions."
#define MSG_TEST_NOEXCEPT_KEYWORD       "Testing noexcept keyword."

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

    causeGenericLogicErrorException();
    causeInvalidArgumentException();
    causeOutOfRangeException();
    causeDomainErrorException();
    causeLengthErrorException();

    causeGenericRuntimeException();
    causeRangeErrorException();
    causeOverflowException();
    causeUnderflowException();
}

static void TestFileIOExceptions(void)
{
    PrintTestHeader(MSG_TEST_FILE_IO_EXCEPTIONS);

    printFileContent();
}

static void TestCustomExceptions(void)
{
    PrintTestHeader(MSG_TEST_CUSTOM_EXCEPTIONS);

    causeCustomException();
    causeFileNotFoundException();
}

static void TestNoexceptkeyword(void)
{
    PrintTestHeader(MSG_TEST_NOEXCEPT_KEYWORD);
}

int main()
{
    TestBasicExceptions();
    TestExceptionTypes();
    TestFileIOExceptions();
    TestCustomExceptions();
    TestNoexceptkeyword();

    return 0;
}

/**************************************/
