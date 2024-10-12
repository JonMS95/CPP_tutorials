/********* Include statements *********/

#include <iostream>
#include <vector>
#include <string>
#include "BasicLambdaFunctions.hpp"
#include "DummyLambdaFunctionsClass.hpp"
#include "SortWithLambdaFunction.hpp"
#include "ForEachWithLambdaFunctions.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                             "*********************************"
#define MSG_TEST_LAMBDA_FUNCTIONS                   "Testing Lambda functions."
#define MSG_TEST_BASIC_LAMBDA_FUNCTIONS             "Testing basic Lambda functions."
#define MSG_TEST_CLASS_LAMBDA_FUNCTIONS             "Testing Lambda functions in classes."
#define MSG_TEST_SORT_WITH_LAMBDA_FUNCTIONS         "Testing standard library sorting algorithm with lambda functions."
#define MSG_TEST_FOR_EACH__WITH_LAMBDA_FUNCTIONS    "Testing standard library for_each algorithm with lambda functions."

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

auto print_vector = [](std::vector<int>& vec) -> void
{
    for(int n:vec)
        std::cout << n << " ";
    std::cout << std::endl;
};

auto print_text = [](std::string s) -> void
{
    std::cout << s << std::endl;
};

void TestSortWithLambdaFunctions()
{
    std::vector<int> vec = {255, 512, 8, 128, 2, 63, 32, 1024, 16, 4, 1};

    print_vector(vec);
    sortInAscendingOrder(vec);
    print_vector(vec);
    sortInDescendingOrder(vec);
    print_vector(vec);
    sortByOnesAsBinary(vec);
    print_vector(vec);
}

void TestForEachWithLambdaFunctions()
{
    auto print_text = [](std::string s) -> void
    {
        std::cout << s << std::endl;
    };

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    print_vector(vec);
    print_text("Sum of all elements in vector: " + std::to_string(getVectorSum(vec)));
    print_text("Vector of squared elements: ");
    std::vector<int> sq_vec = getVectorOfSquares(vec);
    print_vector(sq_vec);
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

    PrintTestHeader(MSG_TEST_FOR_EACH__WITH_LAMBDA_FUNCTIONS);
    TestForEachWithLambdaFunctions();
}

int main()
{
    TestLambdaFunctions();

    return 0;
}

/**************************************/
