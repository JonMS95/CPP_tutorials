/********* Include statements *********/

#include "OperatorOverloading.hpp"

/**************************************/

/********* Method definitions *********/

OperatorOverloading::OperatorOverloading():
    x(0), y(0){}

OperatorOverloading::OperatorOverloading(int x_input, int y_input, std::string name_input):
    x(x_input), y(y_input), name(name_input){}

bool OperatorOverloading::operator==(const OperatorOverloading& obj) const
{
    return ( (this->x == obj.x) && (this->y == obj.y) );
}

OperatorOverloading OperatorOverloading::operator+(const OperatorOverloading& obj) const
{
    OperatorOverloading oo(this->x + obj.x, this->y + obj.y, (this->name + " + " + obj.name));
    return oo;
}

/**************************************/

/******** Function definitions ********/

void ShowCoordinatesAsVector(OperatorOverloading& obj)
{
    std::cout << obj.name << " == {" << obj.x << ", " << obj.y << "}" << std::endl;
}

/**************************************/
