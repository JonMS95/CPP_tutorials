/********* Include statements *********/

#include "BasicExceptions.hpp"

/**************************************/

/******** Function prototypes *********/

void throwingBuiltInTypes(void)
{
    int x = 7;

    try
    {
        if((x % 2) != 0)
            throw -1;
    }
    catch(int e)
    {
        std::cout << "Exception caught (built-in type): " << e << std::endl;
    }
}

void throwStandardException(void)
{
    std::vector<int> vec = {1, 2, 3};

    try
    {
        vec.at(7);
    }
    catch(std::out_of_range e)
    {
        std::cout << "Caught out of range exception: " << e.what() << std::endl;
    }
}


/**************************************/