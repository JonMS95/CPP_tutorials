/********* Include statements *********/

#include <iostream>
#include "BasicLambdaFunctions.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_LAMBDA_FUNCTIONS       "Testing Lambda functions."
#define MSG_TEST_BASIC_LAMBDA_FUNCTIONS "Testing basic Lambda functions."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestLambdaFunctions()
{
    PrintTestHeader(MSG_TEST_LAMBDA_FUNCTIONS);
    PrintTestHeader(MSG_TEST_BASIC_LAMBDA_FUNCTIONS);

    basicLambdaFunctions();
}

int main()
{
    TestLambdaFunctions();

    return 0;
}

/**************************************/
