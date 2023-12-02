/********* Include statements *********/

#include "VirtualFunctions.hpp"

/**************************************/

/********* Method definitions *********/

std::string VirtualFunctionsBase::Greeting(void)
{
    return "Hello there!";
}

std::string VirtualFunctionsBase::Talk(void)
{
    return "HELLO!";
}

VirtualFunctionsDerived::VirtualFunctionsDerived(const std::string& name_input)
{
    this->name = name_input;
}

std::string VirtualFunctionsDerived::Greeting(void)
{
    std::string ret = "Hi! My name is: " + this->name;
    return ret;
}

std::string VirtualFunctionsDerived::Talk(void)
{
    return "GOODBYE!";
}

/**************************************/
