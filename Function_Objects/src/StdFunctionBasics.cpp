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

std::function does not hold a function pointer. It holds an objects, and a way to
call that object, without knowing its type whatsoever. It's a "type-erased wrapper".
Different from function pointers, the elements std::function can reference do not
limit to free functions or static class member functions, but also to lambdas,
functors with state (aka classes/structs with "()" operator overload) and member
functions bound to an object.
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

static inline int tripler(const int x)
{
    return (x * 3);
}

class Quintupler
{
public:
    static int multiply(const int x)
    {
        return (x * 5);
    }
};

class Multiplier
{
private:
    const int mult;

public:
    explicit Multiplier(const int mult_base): mult(mult_base)
    {
        std::cout << "Created Multiplier instance with base: " << this->mult << std::endl;
    }

    int multiply(const int x) const
    {
        return (x * this->mult);
    }
};

void runStdFunctionBasics(void)
{
    const int x = 3;
    const Doubler doubler;
    const Multiplier sextupler = Multiplier(6);

    std::function<int(const int)> f = doubler;
    
    std::cout << "doubler(" << x << ") = " << f(x) << std::endl;

    f = tripler;
    
    std::cout << "tripler(" << x << ") = " << f(x) << std::endl;

    auto quadrupler = [](const int x) -> int { return (x * 4); };

    f = quadrupler;

    std::cout << "quadrupler(" << x << ") = " << f(x) << std::endl;

    f = Quintupler::multiply;

    std::cout << "quintupler(" << x << ") = " << f(x) << std::endl;

    f = std::bind(&Multiplier::multiply, &sextupler, std::placeholders::_1);

    std::cout << "sextupler(" << x << ") = " << f(x) << std::endl;
}

}

/**************************************/
