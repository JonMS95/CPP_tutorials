/********* Include statements *********/

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

/**************************************/

/******** Function definitions *********/

void throwingBuiltInTypes(void)
{
    int x = 7;

    try
    {
        if((x % 2) != 0)
            throw -1;
    }
    catch(int e)
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
    catch(std::out_of_range e)
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

/**************************************/
