/********* Include statements *********/

#include <iostream>
#include <memory>
#include "SmartPointersDummyClass.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_SMART_POINTERS "Testing Smart Pointers."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestSmartPointers()
{
    PrintTestHeader(MSG_TEST_SMART_POINTERS);
}

int main()
{
    TestSmartPointers();

    // Smart pointers are a safer way to allocate and deallocate heap memory than using "new" and "delete" keywords, since
    // memory is freed automatically when it is no longer used. Essentially, smart pointers are just a kind of wrappers
    // around raw pointers, thus, new and delete are implicitly called when using smart pointers. As of 2023, there are 4
    // types of smart pointers:
    // ·Unique pointers:    also known as "scope pointers", they only exist within the scope in which they were previously
    //                      created. As the name suggests, just a single pointer to a specificied memory address may exist.
    // ·Shared pointers:    
    // ·Weak pointers:      
    // ·Auto pointers:      deprecated from C++11 onwards, replaced by unique pointers which provide improved safety.  

    /*********** Unique pointer ***********/

    {
        std::unique_ptr<Dummy<float, 2>> pDummy0 = std::make_unique<Dummy<float, 2>>("Float dummy");
        std::unique_ptr<Dummy<int, 3>> pDummy1(new Dummy<int, 3>("Integer dummy", {3, 4, 5}));
        pDummy0->PrintElements();
        pDummy1->PrintElements();
    }

    // Dummy<float, 5> d("Name", {1.1, 2.2, 3.3, 4.4, 5.5});
    // d.PrintElements();
    // d = {1.2, 2.3, 3.4, 4.5, 5.6};
    // d.PrintElements();

    // Dummy d2 = d;
    // d2.PrintElements();

    return 0;
}

/**************************************/
