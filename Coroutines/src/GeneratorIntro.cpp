/********* Include statements *********/

#include <iostream>
#include <generator>
#include "GeneratorIntro.hpp"

/**************************************/

/*
A generator is a function that produces values one at a time, pausing between
each generated value and resuming when the caller asks for the next one.

Different from common functions, generators keep their state so that they can
follow-up from the last checkpoint once resumed.

Generators introduce the idea of yielding, which stands for setting up a
checkpoint in which a value is generated and where to follow from on the next
generator call.

Note that once last co_yield within the generator is reached, the generator
won't go back to the first co_yield, but it will return nothing instead upon
completion. 
*/

/******** Function definitions *********/

namespace generator_intro
{

static std::generator<int> numbersGenerator(void)
{
    co_yield 1;
    co_yield 4;
    co_yield 9;
}

void generateNumbersCaller(void)
{
    for(int number : numbersGenerator())
        std::cout << number << std::endl;
}

}

/**************************************/
