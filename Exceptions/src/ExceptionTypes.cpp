/********* Include statements *********/

#include <stdexcept>
#include <vector>
#include <iostream>
#include <limits>
#include <string>
#include "BasicExceptions.hpp"

/**************************************/

/********* Define statements *********/

#define SIMPLE_TRY_CATCH_BLOCK(function_call, exception_type)   \
do                                                              \
{                                                               \
    try                                                         \
    {                                                           \
        function_call;                                          \
    }                                                           \
    catch(const exception_type& et)                             \
    {                                                           \
        std::cerr << et.what() << std::endl;                    \
    }                                                           \
    catch(const std::exception& e)                              \
    {                                                           \
        std::cerr << e.what() << std::endl;                     \
    }                                                           \
    catch(...)                                                  \
    {                                                           \
        std::cerr << "Generic excepion caught" << std::endl;    \
    }                                                           \
}                                                               \
while(0);

/**************************************/

/***** Private function prototypes ****/

template <typename T>
static T getElementFromVector(const std::vector<T>& vec, const int idx = 0)
{
    if(idx >= vec.size())
        throw std::range_error(("Provided index was out of bounds (" + std::to_string(idx) + ")"));
    
    return vec[idx];
}

static void throwRuntimeErrorException(void);
static int plusOne(const int input);
static double safeMultiply(const double x, const double y);

/**************************************/

// C++ provides a hierarchy of exception classes under <stdexcept> and <exception> that may help to distinguish
// between logical errors and runtime errors.
//
// std::exception
//  ├── std::logic_error           // Programming errors, detectable before runtime
//  │    ├── std::invalid_argument
//  │    ├── std::domain_error
//  │    ├── std::length_error
//  │    └── std::out_of_range
//  └── std::runtime_error         // Errors detected during runtime
//       ├── std::range_error
//       ├── std::overflow_error
//       ├── std::underflow_error
//       └── std::runtime_error (generic)
//
// ·std::exception is a base class, which provides the virtual what() method (tells what happened for the exception to be caused).
// ·logic_error: represents bugs in program logic (invalid arguments, out of range access and so on).
// ·runtime_error: represents runtime problems, such as trying to divide between a provided number, being such number equal to zero.
// Same as explained in the previous lesson (BasicExceptions), the diagram above represents the exceptions hierarchy (from the most
// specific to the least).

/******** Function definitions *********/

static void throwRuntimeErrorException(void)
{
    throw std::runtime_error("Generic runtime exception");
}

void causeGenericRuntimeException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(throwRuntimeErrorException(), std::runtime_error);
}

void causeRangeErrorException(void)
{
    const std::vector<int> test_vec = {1, 3, 5, 7};

    SIMPLE_TRY_CATCH_BLOCK(getElementFromVector(test_vec, test_vec.size()), std::range_error);
}

static int plusOne(const int input)
{
    if(input == std::numeric_limits<int>::max())
        throw std::overflow_error(("Cannot increment " + std::to_string(input) + " without causing an overflow"));
    return (input + 1);
}

void causeOverflowException(void)
{
    int num = std::numeric_limits<int>::max();
    
    SIMPLE_TRY_CATCH_BLOCK(plusOne(num), std::overflow_error);
}

static double safeMultiply(const double x, const double y)
{
    double result = x * y;
    
    // if (result != 0 && std::abs(result) < std::numeric_limits<double>::min())
    if(x < 0.001 && y < 0.001)
        throw std::underflow_error("Underflow detected: result too small");
    
    return result;
}

void causeUnderflowException(void)
{
    double tiny = std::numeric_limits<double>::min();

    SIMPLE_TRY_CATCH_BLOCK(safeMultiply(tiny, tiny), std::underflow_error);
}

/**************************************/
