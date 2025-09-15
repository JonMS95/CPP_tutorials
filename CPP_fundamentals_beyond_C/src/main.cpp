/********* Include statements *********/

#include <iostream>
#include "References.hpp"
#include "FunctionOverloading.hpp"
#include "Namespaces.hpp"

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_REFERENCES             "Testing references."
#define MSG_TEST_FUNCTION_OVERLOADING   "Testing function overloading."
#define MSG_TEST_NAMESPACES             "Testing namespaces."

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestReferences(void)
{
    PrintTestHeader(MSG_TEST_REFERENCES);

    int x = 0;
    int y = x;
    increment(y);
    std::cout << "x: " << x << ", y: " << y << std::endl;

    printConstRef(x);

    int arr[] = {1, 2, 3, 4};
    int& ref = getElement(arr, 2);

    std::cout << "ref: " << ref << std::endl;
}

void TestFunctionOverloading(void)
{
    PrintTestHeader(MSG_TEST_FUNCTION_OVERLOADING);

    std::cout << "add(1, 2): " << add(1, 2) << std::endl;
    std::cout << "add(1.2, 3.4): " << add(1.2, 3.4) << std::endl;
    std::cout << "mult(3, 2) (c == 1 by default): " << mult(3, 2) << std::endl;
}

void TestNamespaces(void)
{
    PrintTestHeader(MSG_TEST_NAMESPACES);

    std::cout << "Math::add(1, 2): " << Math::add(1, 2) << std::endl;
    std::cout << "Math::mult(3, 2): " << Math::mult(3, 2) << std::endl;
}

int main()
{
    TestReferences();
    TestFunctionOverloading();
    TestNamespaces();

    return 0;
}

/**************************************/
