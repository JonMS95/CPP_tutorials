/********* Include statements *********/

#include <iostream>
#include "References.hpp"

#define MSG_TEST_HEADER     "*********************************"
#define MSG_TEST_REFERENCES "Testing References."

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

int main()
{
    TestReferences();

    return 0;
}

/**************************************/
