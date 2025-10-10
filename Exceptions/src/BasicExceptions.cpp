/********* Include statements *********/

#include <iostream>
#include <stdexcept>
#include <vector>
#include "BasicExceptions.hpp"

/**************************************/

// Exceptions are special events that interrupts the normal flow of a program whenever something unexpected happens.
// In C++, an exception is an object that is thrown by one àrt of the ptogram and that can be caught by another
//
// Without exceptions, error codes have to be manually handled, which apart from leading to terrible headaches when
// handling those or mantaining them, the context is usually lost, especially in nested function calls.
//
// Core syntax:
// ·throw:  signals that something went wrong.
// ·try:    mark a block of code that may throw an exception.
// ·catch:  handle an exception (if any).

/***** Private function prototypes ****/

static int divideIntegers(const int a, const int b);
static void deepStep(void);
static void shallowStep(void);

/**************************************/

/******** Function definitions *********/

// Exception can throw any type, however the most common practice is to use types defined in std::exception
// since they can be taught generically and integrate with the standard error handling system. In the example
// shown below, it throws an integer.

void throwingBuiltInTypes(void)
{
    int x = 7;

    try
    {
        if((x % 2) != 0)
            throw -1;
    }
    catch(const int& e)
    {
        std::cout << "Exception caught (built-in type): " << e << std::endl;
    }
}

void throwStandardException(void)
{
    std::vector<int> vec = {1, 2, 3};

    try
    {
        vec.at(7);
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Caught out of range exception: " << e.what() << std::endl;
    }
}

// Examples above are pretty good, but still doesn't show the optimal/preferred code structure. A simple producer-consumer
// structure is usually preferred: a function potentially throws exceptions, the consumer function tries within try block
// to execute it, going through catch block in case any exception happens:

static int divideIntegers(const int a, const int b)
{
    if(b == 0)
        throw std::runtime_error("Division by zero");
    
    return a / b;
}

void try2divide(void)
{
    try
    {
        divideIntegers(7, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

// What happens under the hood?
// 1 - The code tries to run normally.
// 2 - If no error happens, then the program skips every catch blocks.
// 3 - If throw is executed, then:
//     ·The function stops executing immediately.
//     ·Control jumps up the call stack looking for a matching catch.
//     ·If not found, then the program terminates with std::terminate.

static void deepStep(void)
{
    std::cout << "Inside of firstStep" << std::endl;
    throw std::runtime_error("Error within firstStep");
}

static void shallowStep(void)
{
    std::cout << "Inside of secondStep" << std::endl;

    deepStep();

    std::cout << "This is never going to be printed" << std::endl;
}

// When catching an exception, it's strongly recommended to do it in a hierarchic way (from the most specific to the least).
// This way, no catch block is ignored. Usually the couple shown below are the most common catch blocks after a try:
// catch(const std::exception& e)   // Capture a generic exception (std::exception is a base class).
// catch(...)                       // Capture any exception, either known or not.
// These two are usually preceeded by even more generic catch statements.

void exceptionHierarchy(void)
{
    try
    {
        shallowStep();
    }
    catch(const std::runtime_error& re)
    {
        std::cerr << "Runtime error caught!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Generic exception caught!" << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unkown exception caught!" << std::endl;
    }
}

// Finally, it's worth pointing out that if no catch block ever gets a previously thrown exception,
// then the program in question will simply terminate by using std::terminate. Note that exceptions
// cannot replace memory safety, but they report any potential conflict instead.
//
// For instance, trying
// to dereference a null pointer may cause a segmentation fault, which may also be reported as an
// std::runtime_exception, but the existence of an exception will not prevent the forbidden memory
// access from ever happening.

/**************************************/
