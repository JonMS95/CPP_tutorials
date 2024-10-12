#include "SortWithLambdaFunction.hpp"

// Let's see a bit more complex example now. The sorting criteria will be the number of 1's in the binary representation of each number.
// If two numbers have the same number of 1's, then sort them in descending order. It's guaranteed that the provided vector includes solely integers.
void sortByOnesAsBinary(std::vector<int>& vec)
{
    auto count_ones = [](int& n) -> int
    {
        int ones = 0;
        
        for(int i = 0; i < sizeof(int) * 8; i++)
            if((1 << i) & n)
                ++ones;
        
        return ones;
    };

    // Of course, __builtin_popcount() could have been used, just trying to make the showcase insightful by showing an example in which another
    // lambda function should be captured.

    auto sorting_criterion = [count_ones](int& a, int& b) -> bool
    {
        if(count_ones(a) == count_ones(b))
            return a > b;
        
        return count_ones(a) < count_ones(b);
    };

    std::sort(vec.begin(), vec.end(), sorting_criterion);
}
