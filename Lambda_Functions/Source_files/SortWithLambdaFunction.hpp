#ifndef SORT_WITH_LAMBDA_FUNCTION
#define SORT_WITH_LAMBDA_FUNCTION

#include <algorithm>

template <typename T>
void sortInAscendingOrder(std::vector<T>& vec)
{
    std::sort(vec.begin(), vec.end(), [](T a, T b) -> bool {return a < b;});
}

template <typename T>
void sortInDescendingOrder(std::vector<T>& vec)
{
    std::sort(vec.begin(), vec.end(), [](T a, T b) -> bool {return a > b;});
}

#endif