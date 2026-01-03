/********* Include statements *********/

#include <iostream>
#include <stdexcept>
#include "Generator.hpp"
#include "GeneratorIntro.hpp"

/**************************************/

/*
A generator is a function that produces values one at a time, pausing between
each generated value and resuming when the caller asks for the next one.
Generators are a common coroutine usecase. Same as views (both in C++ and SQL),
they are kind of expressions that do not hold all of the data in memory but
the data generator instead.

Different from common functions, generators keep their state so that they can
follow-up from the last checkpoint once resumed.

Generators introduce the idea of yielding, which stands for setting up a
checkpoint in which a value is generated and where to follow from on the next
generator call.

Note that once last co_yield within the generator is reached, the generator
won't go back to the first co_yield, but it will return nothing instead upon
completion.

Coroutine generators can be called with input values. However, they can only
take an input parameter once. Take into account that as lazy expressions,
values are returned on demand.
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

static generator<int> counterGenerator(const int diff)
{
    const int max_counter = 10;
    const int min_counter = -10;
    int counter = 0;

    while(true)
    {
        if(diff > 1 || diff < -1)
            throw std::range_error("Input difference can be equal to -1, 0 or 1, no other");
        
        if(counter <= min_counter || counter >= max_counter)
            co_return;

        counter += diff;
        co_yield counter;
    }
}

using p_gen_v = generator<int>(*)(void);

static inline void intGeneratorCaller(p_gen_v p_generator)
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

void counterGeneratorCaller(const bool increment)
{
    try
    {
        auto gen = counterGenerator((increment ? 1 : -1));
        auto it = gen.begin();

        while(it != gen.end())
        {
            std::cout << "Current counter value: " << *it << std::endl;
            ++it;
        }
    }
    catch(const std::range_error& re)
    {
        std::cerr << "Range error caught: " << re.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Generic error caught: " << e.what() << std::endl;
    }
}

}

/**************************************/
