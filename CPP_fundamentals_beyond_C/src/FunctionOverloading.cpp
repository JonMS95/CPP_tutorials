#include "FunctionOverloading.hpp"

/*
Overloading is a C++ feature that allows us to create different function prototypes
with the same function name but with different input parameters each time. This way,
multiple implementations for different types can be implemented, such as addition
with both int and double types.

Also, default parameters can be added in a function's prototypes. This enables the
user not to necessarily provide an argument to a function, but assuming a default
value instead. Input parameters with default values should be placed last in the
function prototype. Note: always in keep in mind that default parameters values
can only exist in the function prototype (not in the source file) if separatedly
implemented.
*/

int add(const int& a, const int& b)
{
    return (a + b);
}

double add(const double& a, const double& b)
{
    return (a + b);
}

int mult(const int a, const int b, const int c)
{
    return (a * b * c);
}