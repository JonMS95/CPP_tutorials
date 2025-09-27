#include "ConstRelatedKeywords.hpp"

/*
The aim of this lesson is to learn about modern const related keywords:

·constexpr: similar to inline in C, it can lead the variable / function
    tagged as constexpr to be evaluated during compile-time as long as
    inputs are known. It may fall back to runtime otherwise. Variables
    are not modifiable afterwards.
·consteval: unlike constexpr, this forces compile-time evaluation. If
    the argument is unknown, it leads to compilation error.
·constinit: ensures a variable with static storage is initialized at
    compile time but allowing the variable in question to change later
    if needed.
·mutable:   makes object within const object modifiable (for example,
    a class member inside a given class instance).
*/

// If x unavailable -> compilation error.
// consteval int squareConstEval(int x)
// {
//     return (x * x);
// }

// Variable is forced to be initialized during compilation, but it's still modifiable afterwards.
constinit int globalCounter = 0;

// const as part of a class method declaration means that the method in question can't modify a
// class member (unless mutable). Can't be done with free functions.
void ConstKeywordsDummyClass::incrementCounter(void) const
{
    this->counter++;
}

const int ConstKeywordsDummyClass::getCounter(void) const
{
    return this->counter;
}