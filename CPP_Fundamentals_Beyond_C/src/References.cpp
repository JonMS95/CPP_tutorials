#include <iostream>
#include "References.hpp"

/*
References are a C++ feature that make developer's lives easier was far as pointer handling is
concerned.
When passing a pointer to a function in C++, a reference can be passed instead making al the
pointer reference/dereference processes easier.
Referenced values can be treated just as if they were no references at all. Same as with pointed
variables, their values remain after a function call.
Newly created references cannot be returned from within a function. As an example, if a variable
is created into a given function's scope, returning a reference to such variable would not be
safe at all.

Key takeaways:

References (T&) are aliases, safer than pointers:
    ·Cannot be null
    ·Must always refer to something

Const references (const T&) let you:
    ·Avoid copies for large objects
    ·Pass temporaries safely
    ·Enforce immutability in functions

Returning references avoids copies, but you must ensure lifetime safety.
*/

// References allow us to modify the caller's variable directly.
// However, the variable is not being copied, so it will retain its value after the function call.
void increment(int& x)
{
    x += 1;
}

// Const references allow passing large objects without copying and guarantee that the variable will
// not be modified.
void printConstRef(const int& x)
{
    std::cout << "Value (const ref): " << x << std::endl;

    // Cannot do x += 1 as in increment since const renders the references variable untouchable.
}

// A reference can be returned by a function. Returned reference's validity should be ensured.
int& getElement(int arr[], int index)
{
    return arr[index];
}
