/********* Include statements *********/

#include "ConstructorInitializerList.hpp"

/**************************************/

/********* Method definitions *********/

// Commented constructor methods are those that are written in the usual way.

// ConstructorInitializerList::ConstructorInitializerList()
// {
//     this->name  = "DEFAULT_NAME";
//     this->age   = 33;
// }

ConstructorInitializerList::ConstructorInitializerList():
    name("DEFAULT_NAME"), age(33)
{
    std::cout << "Using default constructor." << std::endl;
}

// ConstructorInitializerList::ConstructorInitializerList(const std::string name_input, int age_input):
// {
//     this->name  = name_input;
//     this->age   = age_input;
// }

ConstructorInitializerList::ConstructorInitializerList(const std::string name_input, int age_input):
    name(name_input), age(age_input)
{
    std::cout << "Using constructor with input paremeters." << std::endl;
}

void ConstructorInitializerList::PrintName(void)
{
    std::cout << "Name: " << this->name << std::endl;
}

/**************************************/
