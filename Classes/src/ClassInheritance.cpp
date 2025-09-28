/********* Include statements *********/

#include "ClassInheritance.hpp"

/**************************************/

/********* Method definitions *********/

void ClassInheritanceBase::Move(int x_input, int y_input)
{
    this->x += x_input;
    this->y += y_input;
}

void ClassInheritanceBase::PrintCoordinates(void)
{
    std::cout << "x: " << this->x << " y: " << this->y << std::endl;
}

void ClassInheritanceBase::Greeting(void)
{
    std::cout << "Hello! This is a base-class final method." << std::endl;
}

ClassInheritanceDerived::ClassInheritanceDerived(int x_input, int y_input, const char* name_input)
{
    this->x = x_input;
    this->y = y_input;
    this->name = name_input;
}

void ClassInheritanceDerived::PrintName(void)
{
    std::cout << "Name: \"" << this->name << "\"" << std::endl;
}

void ClassInheritanceFinal::Greeting(void) const
{
    std::cout << "This class cannot be inherited." << std::endl;
}

/**************************************/
