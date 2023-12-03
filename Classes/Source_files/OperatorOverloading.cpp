/********* Include statements *********/

#include "OperatorOverloading.hpp"

/**************************************/

/********* Method definitions *********/

OperatorOverloading::OperatorOverloading(int x_input, int y_input):
    x(x_input), y(y_input){}

bool OperatorOverloading::operator==(const OperatorOverloading& obj) const
{
    return ( (this->x == obj.x) && (this->y == obj.y) );
}

/**************************************/

/******** Function definitions ********/

void ShowCoordinatesAsVector(OperatorOverloading& obj)
{
    std::cout << "oo1 == {" << obj.x << ", " << obj.y << "}" << std::endl;
}

/**************************************/
