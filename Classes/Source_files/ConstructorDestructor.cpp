/********* Include statements *********/

#include "ConstructorDestructor.hpp"

/**************************************/

/********* Method definitions *********/

void ConstructorDestructor::PrintCoordinates(void)
{
    std::cout << "x: " << this->x << " y: " << this->y << std::endl;
}

ConstructorDestructor::ConstructorDestructor(void)
{
    std::cout << "Using constructor with no input parameters, almost equivalent to default." << std::endl;
    this->x = 0;
    this->y = 0;
}

ConstructorDestructor::ConstructorDestructor(int x_input, int y_input)
{
    std::cout << "Using constructor with input parameters now." << std::endl;
    this->x = x_input;
    this->y = y_input;
}

ConstructorDestructor::~ConstructorDestructor(void)
{
    std::cout << "Destroying \"ConstructorDestructor\" type variable!" << std::endl; 
}

/**************************************/
