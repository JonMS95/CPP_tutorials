#ifndef SUBRANGES_AND_SLICING_HPP
#define SUBRANGES_AND_SLICING_HPP

/********* Include statements *********/

#include <vector>
#include <stdexcept>
#include <ranges>

/**************************************/

/******** Function prototypes *********/

namespace subranges_and_slicing
{

std::vector<int> getFirstNIntegers(const std::vector<int>& vec, const int n);
std::vector<int> getAllIntegersExceptFirstN(const std::vector<int>& vec, const int n);
template<typename T> std::vector<T> getTrimmedVector(const std::vector<T>& vec, const int trim_left, const int trim_right)
{
    if((trim_left + trim_right) > static_cast<int>(vec.size()))
        throw std::range_error("Number of elements to be trimmed exceed vector\'s length");

    auto view = vec
        | std::views::drop(trim_left)
        | std::views::take(vec.size() - trim_left - trim_right);

    return std::vector<T>(view.begin(), view.end());
}
template<typename T> std::vector<T> getRevertedVector(const std::vector<T>& vec)
{
    auto view = vec | std::views::reverse;
    
    return std::vector<T>(view.begin(), view.end());
}

}

/**************************************/

#endif