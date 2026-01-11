/********* Include statements *********/

#include <iostream>

/**************************************/

/*
A function object (often called a functor) is an object that can be called like a function
because it overloads parentheses operator (operator()).

Unlike common functions or function pointers, functions can store a state.
*/

/******** Function definitions *********/

namespace basic_functors
{

struct Printer
{
    void operator()() const
    {
        std::cout << "Hello from a function object." << std::endl;
    }
};

void MinimalFunctorExample(void)
{
    Printer p;
    p();    // Previously created object instance can be actually called as it's a callable
            // since "()" operator has been overloaded.
}

class Multiplier
{
private:
    const int factor;

public:
    explicit Multiplier(const int f): factor(f)
    {
        std::cout << "Created Multiplier instance with factor: " << this->factor << std::endl;
    }

    int operator()(const int x) const
    {
        return x * this->factor;
    }
};

void FunctorWithState(void)
{
    Multiplier m0 = Multiplier(2);
    Multiplier m1 = Multiplier(10);

    std::cout << "m0(4) = " << m0(4) << std::endl;
    std::cout << "m1(5) = " << m1(5) << std::endl;
}

}

/**************************************/
