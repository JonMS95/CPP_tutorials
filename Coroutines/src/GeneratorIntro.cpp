/********* Include statements *********/

#include <iostream>
#include "generator.hpp"
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

static generator<int> numbersGenerator(void)
{
    std::cout << "Generating numbers..." << std::endl;
    
    co_yield 1;
    co_yield 4;
    co_yield 9;
}

static generator<int> squaresGenerator(void)
{
    const int num_max = 10;
    int num = 0;

    std::cout << "Generating square numbers..." << std::endl;

    while(num <= num_max)
    {
        co_yield (num * num);
        ++num;
    }

    co_return;
}

using p_gen = generator<int>(*)(void);

static inline void intGeneratorCaller(p_gen p_generator)
{
    for(int num : p_generator())
        std::cout << num << std::endl;
}

void numbersGeneratorCaller(void)
{
    intGeneratorCaller(numbersGenerator);
}

void squaresGeneratorCaller(void)
{
    intGeneratorCaller(squaresGenerator);
}

}

/**************************************/
