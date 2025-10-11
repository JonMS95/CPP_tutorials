/********* Include statements *********/

#include <stdexcept>
#include <iostream>
#include <stack>
#include "Noexcept.hpp"

/**************************************/

// noexcept is a specifier taht tells the compiler and fellow developers whether a function guarantees not to
// throw any exception. Functions marked as noexcept must not throw: throwing from them leads to std::terminate.
// In other words, it's a way to tell that C++ exception mechanism is not allowed for a given function.

/***** Private function prototypes ****/

template <typename T>
static T getStackTop(std::stack<T> st)
{
    T ret = st.top();

    std::cout << "Stack top value is: " << ret << std::endl;

    return ret;
}

/**************************************/

/******** Function definitions ********/

// The funciton below cannot throw any exception whatsoever.

void sayHello(const char* input) noexcept
{
    // if(!input)
        // throw std::exception();
    
    // If lines above were not commented, a compilation error would happen.

    std::cout << input << std::endl;
}

// Now, what may happen if a function placed in a deeper stack frame throws an exception? In that case, any potential
// exception taht may be thrown in a deeper level will propagate towards shallower level until it is either caught by
// a catch block or it reaches a function marked as noexcept.

void exceptionPropagationWithNoexcept(void) noexcept
{
    std::stack<int> st;
    st.push(1);
   
    // If line above was commented, the exception wouldn't be propagated properly.

    getStackTop(st);
}

/**************************************/
