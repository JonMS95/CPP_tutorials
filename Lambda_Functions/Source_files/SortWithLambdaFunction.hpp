#ifndef SORT_WITH_LAMBDA_FUNCTION
#define SORT_WITH_LAMBDA_FUNCTION

#include <algorithm>
#include <vector>

/*
When using sorting built-in functions, an overloaded parameter can be passed instead of solely providing the range to be sorted.
This extra parameter is meant to be a sorting criterion which can be defined as follows:

template <typename T>
bool sorting_criterion(const& T a, const& T b)
{
    # Do whatever here
    
    return bool
}

If true is returned, it means that "a" input variable should be placed before "b" while sorting.

By default, the function above is implemented as shown below (or in an equivalent way, probably not the same):

template <typename T>
bool sorting_criterion(const& T a, const& T b)
{
    return a < b;
}

Therefore, true will be returned if a is lower than b, placing a before b in the interval meant to be sorted, thus sorting the interval in ascending order.
*/

// Sort in ascending order
template <typename T>
void sortInAscendingOrder(std::vector<T>& vec)
{
    std::sort(vec.begin(), vec.end(), [](T a, T b) -> bool {return a < b;});
}
// The implementation above would be equivalent to using std::sort(vec.begin(), vec.end());

// Sort in descending order
template <typename T>
void sortInDescendingOrder(std::vector<T>& vec)
{
    std::sort(vec.begin(), vec.end(), [](T a, T b) -> bool {return a > b;});
}

void sortByOnesAsBinary(std::vector<int>& vec);

#endif