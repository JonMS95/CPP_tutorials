#include "ForEachWithLambdaFunctions.hpp"

/*
Apart from the sort function found in algorithm library, lambda functions are commonly used as well with std::for_each function.
Different from std::sort, this built-in function has no parameter overloading and passing a unary function as input parameter is
mandatory. This function will decide what to do with each element in the interval to traverse.

The so-called unary function to be passed does not require nor use any return value, so it will be typically void. When it comes to
input parameters, it should take a variable of the same type as each element within the interval or vector.

The example below shows a function that takes an integer from it's surroundng scope and use it to store the total sum of the numbers
in a vector:
*/

int getVectorSum(std::vector<int>& vec)
{
    int sum = 0;

    std::for_each(vec.begin(), vec.end(), [&sum](int n)-> void {sum += n;});

    return sum;
}

std::vector<int> getVectorOfSquares(std::vector<int>& vec)
{
    std::vector<int> ret(vec.size());
    int index = 0;

    auto getSquare = [&ret, &index](int elem) -> void
    {
        ret[index++] = elem*elem;
    };

    std::for_each(vec.begin(), vec.end(), getSquare);

    return ret;
}
