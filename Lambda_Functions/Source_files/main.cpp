/********* Include statements *********/

#include <iostream>
#include "BasicLambdaFunctions.hpp"
#include "DummyLambdaFunctionsClass.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_LAMBDA_FUNCTIONS       "Testing Lambda functions."
#define MSG_TEST_BASIC_LAMBDA_FUNCTIONS "Testing basic Lambda functions."
#define MSG_TEST_CLASS_LAMBDA_FUNCTIONS "Testing Lambda functions in classes."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestBasicLambdaFunctions()
{
    basicLambdaFunctions();
}

void TestLambdaFunctionsInClasses()
{
    Dummy d1(24, "Fernando");
    Dummy d2 = d1;
    d1.updateAge(43);
}

void TestLambdaFunctions()
{
    PrintTestHeader(MSG_TEST_LAMBDA_FUNCTIONS);

    PrintTestHeader(MSG_TEST_BASIC_LAMBDA_FUNCTIONS);
    TestBasicLambdaFunctions();

    PrintTestHeader(MSG_TEST_CLASS_LAMBDA_FUNCTIONS);
    TestLambdaFunctionsInClasses();
}

int main()
{
    TestLambdaFunctions();

    return 0;
}

/**************************************/
