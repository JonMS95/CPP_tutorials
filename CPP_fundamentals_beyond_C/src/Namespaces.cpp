#include <iostream>
#include "Namespaces.hpp"

/*
In pure C language, function definitions are sometimes defined as follows:

int math_init(int a);

(and then, in another file from our codebase)

int sys_init(int a);

So they have a prefix (math/sys) so as to avoid name collisions, it's to say,
to prevent those functions to be called the same way. Namespaces are a simple
C++ tool that makes name-prefixing way easier. To call/use functions in a
given namespace, just use:

namespace_name::function()

Also, we can prevent other translation units from accessing a given namespace
at all costs. When declaring a namespace, jus don't give a name to it and
it will not be visible for other cpp files unless strictly included hpp file.
This is pretty similar to how static keyword behaves in C.
*/

namespace
{
    void debugMessage(const char* msg)
    {
        std::cout << "[DEBUG] " << msg << std::endl;
    }
}

int Math::add(int a, int b)
{
    debugMessage("a + b");
    return a + b;
}

int Math::mult(int a, int b)
{
    return a * b;
}
