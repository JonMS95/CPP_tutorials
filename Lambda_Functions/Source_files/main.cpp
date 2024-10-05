/********* Include statements *********/

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "BasicLambdaFunctions.hpp"
#include "DummyLambdaFunctionsClass.hpp"
#include "SortWithLambdaFunction.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                     "*********************************"
#define MSG_TEST_LAMBDA_FUNCTIONS           "Testing Lambda functions."
#define MSG_TEST_BASIC_LAMBDA_FUNCTIONS     "Testing basic Lambda functions."
#define MSG_TEST_CLASS_LAMBDA_FUNCTIONS     "Testing Lambda functions in classes."
#define MSG_TEST_SORT_WITH_LAMBDA_FUNCTIONS "Testing standard library sorting algorithm with lambda functions."

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

void TestSortWithLambdaFunctions()
{
    std::vector<int> vec1;
    srand (time(NULL));

    for(int i = 0; i < 10; i++)
    {
        vec1.emplace_back(rand() % 100 + 1);
    }

    std::vector<int> vec2 = vec1;

    auto print_vector = [](std::vector<int>& vec) -> void
    {
        for(int n:vec)
            std::cout << n << " ";
        std::cout << std::endl;
    };

    sortInAscendingOrder(vec1);
    sortInDescendingOrder(vec2);

    print_vector(vec1);
    print_vector(vec2);
}

void TestLambdaFunctions()
{
    PrintTestHeader(MSG_TEST_LAMBDA_FUNCTIONS);

    PrintTestHeader(MSG_TEST_BASIC_LAMBDA_FUNCTIONS);
    TestBasicLambdaFunctions();

    PrintTestHeader(MSG_TEST_CLASS_LAMBDA_FUNCTIONS);
    TestLambdaFunctionsInClasses();

    PrintTestHeader(MSG_TEST_SORT_WITH_LAMBDA_FUNCTIONS);
    TestSortWithLambdaFunctions();
}

int main()
{
    TestLambdaFunctions();

    return 0;
}

/**************************************/
