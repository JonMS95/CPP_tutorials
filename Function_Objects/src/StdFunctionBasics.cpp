/********* Include statements *********/

#include <iostream>
#include <functional>
#include "StdFunctionBasics.hpp"

/**************************************/

/*
Different from classes / structs in which operator() has been defined, std::function
provides a standard interface which relies on dynamic polymorphism (compile time).

This way, the same std::function type variable may point to different functions/
callables as long as their interface is the same.
*/

/******** Function definitions *********/

namespace std_function_basics
{

struct Doubler
{
    int operator()(const int x) const
    {
        return (x * 2);
    }
};

static inline int Tripler(const int x)
{
    return (x * 3);
}

void runStdFunctionBasics(void)
{
    const int x = 3;
    std::function<int(int)> f = Doubler{};
    
    std::cout << "Doubler(" << x << ") = " << f(x) << std::endl;
}

}

/**************************************/
