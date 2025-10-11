/********* Include statements *********/

#include <stdexcept>
#include <vector>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <cctype>
#include "Common.hpp"
#include "ExceptionTypes.hpp"

/**************************************/

/********* Define statements *********/

#define MAX_INPUT_STR_LEN   10

/**************************************/

/***** Private function prototypes ****/

static void throwLogicErrorException(void);
static double safeDivision(const double a, const double b);
template <typename T>
static T getElementFromVector(const std::vector<T>& vec, const int idx = 0)
{
    if(idx >= vec.size())
        throw std::out_of_range(("Out of range exception: Provided index was out of bounds (" + std::to_string(idx) + ")"));
    
    return vec[idx];
}
static double safeSquareRoot(const double x);
static void toUppercaseString(std::string& s);

static void throwRuntimeErrorException(void);
static bool isAccessGranted(const int age);
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

/******* Logic error exceptions ********/

static void throwLogicErrorException(void)
{
    throw std::logic_error("Generic logic error exception");
}

void causeGenericLogicErrorException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(throwLogicErrorException(), std::logic_error);
}

static double safeDivision(const double a, const double b)
{
    if(b == 0.0)
        throw std::invalid_argument("Invalid argument: Division by zero is not allowed");

    return (a / b);
}

void causeInvalidArgumentException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(safeDivision(1, 0), std::invalid_argument);
}

void causeOutOfRangeException(void)
{
    const std::vector<int> test_vec = {1, 3, 5, 7};

    SIMPLE_TRY_CATCH_BLOCK(getElementFromVector(test_vec, test_vec.size()), std::out_of_range);
}

static double safeSquareRoot(const double x)
{
    if(x < 0)
        throw std::domain_error("Domain error: Square root of negative number is not allowed");

    return std::sqrt(x);
}

void causeDomainErrorException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(safeSquareRoot(-4.5), std::domain_error);
}

static void toUppercaseString(std::string& s)
{
    if(s.size() >= MAX_INPUT_STR_LEN)
        throw std::length_error(("Length error: string size (" + std::to_string(s.size()) + ") >= " + std::to_string(MAX_INPUT_STR_LEN)));

    for(char& c : s)
        c = std::toupper(c);
}

void causeLengthErrorException(void)
{
    std::string test_str = "Halellujah!";

    SIMPLE_TRY_CATCH_BLOCK(toUppercaseString(test_str), std::length_error);
}

/****** Runtime error exceptions *******/

static void throwRuntimeErrorException(void)
{
    throw std::runtime_error("Generic runtime error exception");
}

void causeGenericRuntimeException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(throwRuntimeErrorException(), std::runtime_error);
}

static bool isAccessGranted(const int age)
{
    if(age < 0)
        throw std::range_error("Range error: age cannot be negative");

    return (age >= 18);
}

void causeRangeErrorException()
{
    SIMPLE_TRY_CATCH_BLOCK(isAccessGranted(-1), std::range_error);
}

static int plusOne(const int input)
{
    if(input == std::numeric_limits<int>::max())
        throw std::overflow_error(("Overflow error: cannot increment " + std::to_string(input) + " without causing an overflow"));

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
        throw std::underflow_error("Underflow error: result too small");
    
    return result;
}

void causeUnderflowException(void)
{
    double tiny = std::numeric_limits<double>::min();

    SIMPLE_TRY_CATCH_BLOCK(safeMultiply(tiny, tiny), std::underflow_error);
}

/**************************************/
