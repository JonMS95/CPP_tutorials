/********* Include statements *********/

#include <iostream>
#include <ranges>
#include <vector>
#include "Views.hpp"

/**************************************/

/*
The concept of views in C++ is pretty much similar to SQL views. They are not ranges nor any type of ranges at all,
instead, they are just the recipe to get some ranges from others without explicitly storing the result (they are
lazily evaluated).

There are two types of views that stand out: filters and transformers. The main difference between them is that the
prior removes elements that do not match specified criteria from the resulting range whereas the latter don't (every
element gets modified, but every element is kept).

A common practise is to use lambda functions when using views, however, common function pointers are also allowed.
*/

/******** Function definitions *********/

namespace views
{

std::vector<int> getEvenNumbers(const std::vector<int>& vec)
{
    std::vector<int> ret;
    
    auto even_nums_view =  vec | std::views::filter([](const int x) -> bool {return (x % 2) == 0;});

    for(int n: even_nums_view)
        ret.emplace_back(n);
    
    return ret;
}

std::string toUppercase(const std::string& str)
{
    auto char_to_uppercase = [](const char& c) -> char
    {
        if(c >= 'a' && c <= 'z')
            return (c - 'a' + 'A');
        
        return c;
    };

    auto to_uppercase_view = str | std::views::transform(char_to_uppercase);

    // View results can be returned by simply "specifying the interval in question" as shown below.
    return std::string(to_uppercase_view.begin(), to_uppercase_view.end());
}

// Transforms and filters can easily be combined by using pipe operator.
std::vector<int> getDoubledOddNumbers(const std::vector<int>& vec)
{
    auto doubled_odd_numbers = vec | std::views::filter([](const int& x) -> bool {return (x % 2);}) | std::views::transform([](int x) -> int {return x *= 2;});
    return std::vector<int>(doubled_odd_numbers.begin(), doubled_odd_numbers.end());
}

}

/**************************************/
