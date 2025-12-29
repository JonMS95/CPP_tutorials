/********* Include statements *********/

#include <iostream>
#include <ranges>
#include <vector>
#include <list>
#include <string>
#include "BasicRanges.hpp"

/**************************************/

/*
Ranges in C++ are all  of those object that can be iterated over (by using .begin() and .end()).
Therefore, all container classes are ranges (vector, list, string...).  Conceptually, they may seem
to be syntax sugar but they make up a standardized interface for different class objects to be
iterated.
*/

/******** Function definitions *********/

namespace range_basics
{

void iterateVector(const std::vector<int>& vec)
{
    std::cout << "Vector: ";

    for(int v: vec)
        std::cout << v << " ";

    std::cout << std::endl;
}

void iterateList(const std::list<std::string>& words)
{
    std::cout << "List: ";

    for(const std::string& word : words)
        std::cout << word << " ";
    std::cout << std::endl;
}

void iterateString(const std::string& str)
{
    std::cout << "String: ";

    for(const char& c : str)
        std::cout << c << " ";
    
    std::cout << std::endl;
}

// iota comes from Greek letter's name, meaning "small" or "incremental". It generates a sequence
// of incrementing values within a well-defined range.
void iterateTemporaryRange(const int start, const int end)
{
    std::cout << "Temporary range: ";

    for(int i : std::views::iota(start, end))
        std::cout << i << " ";

    std::cout << std::endl;
}

}

/**************************************/
