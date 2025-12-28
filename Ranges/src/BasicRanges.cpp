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

void iterateVector(void)
{
    std::vector<int> vec{1, 4, 6, 8, 10};

    std::cout << "Vector: ";

    for(int v: vec)
        std::cout << v << " ";

    std::cout << std::endl;
}

void iterateList(void)
{
    std::list<std::string> words{"Hello", "world", "of", "ranges"};

    std::cout << "List: ";

    for(const std::string& word : words)
        std::cout << word << " ";
    std::cout << std::endl;
}

void iterateString(void)
{
    std::string s = "abc";

    std::cout << "String: ";

    for(const char& c : s)
        std::cout << c << " ";
    
    std::cout << std::endl;
}

// iota comes from Greek letter's name, meaning "small" or "incremental". It generates a sequence
// of incrementing values within a well-defined range.
void iterateTemporaryRange(void)
{
    std::cout << "Temporary range: ";

    for(int i : std::views::iota(1, 10))
        std::cout << i << " ";

    std::cout << std::endl;
}

}

/**************************************/
