/********* Include statements *********/

#include <iostream>
#include <ranges>
#include <vector>
#include <stdexcept>
#include "SubrangesAndSlicing.hpp"

/**************************************/

/*
A subrange is a view of part of a range (without copying elements). Views like take and drop can be
pretty useful when it comes to retrieving solely part of the target range.
*/

/******** Function definitions *********/

namespace subranges_and_slicing
{

std::vector<int> getFirstNIntegers(const std::vector<int>& vec, const int n)
{
    if(n > static_cast<int>(vec.size()))
        throw std::range_error("Number of integers to be retrieved is greater than provided vector\'s length.");
    
    auto view = vec | std::views::take(n);
    
    return std::vector<int>(view.begin(), view.end());
}

std::vector<int> getAllIntegersExceptFirstN(const std::vector<int>& vec, const int n)
{
    if(n > static_cast<int>(vec.size()))
        throw std::range_error("Number of integers to be skipped is greater than provided vector\'s length.");

    auto view = vec | std::views::drop(n);

    std::vector<int> ret;

    return std::vector<int>(view.begin(), view.end());
}

}

/**************************************/
