/********* Include statements *********/

#include "StaticInClasses.hpp"

/**************************************/

/******* Class static variables *******/

int StaticInClasses::a;
int StaticInClasses::b;

/**************************************/

/******** Class static methods ********/

void StaticInClasses::Greeting(void)
{
    std::cout << "Hi there! How is it going?" << std::endl;
}

/**************************************/

/********* Method definitions *********/

void StaticInClasses::SetX(int x_input)
{
    this->x = x_input;
}

int StaticInClasses::GetX(void)
{
    return this->x;
}

void StaticInClasses::SetY(int y_input)
{
    this->y = y_input;
}

int StaticInClasses::GetY(void)
{
    return this->y;
}

void StaticInClasses::PrintClassVars(void)
{
    std::cout << "x: " << this->x << " y: " << this->y << std::endl;
}

void StaticInClasses::PrintStaticVars(void)
{
    std::cout << "a: " << this->a << " b: " << this->b << std::endl;
}

static void Greeting(void);

/**************************************/
