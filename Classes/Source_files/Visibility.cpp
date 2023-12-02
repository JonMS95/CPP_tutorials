/********* Include statements *********/

#include "Visibility.hpp"

/**************************************/

/********* Method definitions *********/

std::vector<int> VisibilityBase::GetCoordinatesAsVector(void)
{
    std::vector<int> ret = {this->x, this->y};
    return ret;
}

void VisibilityBase::PrintCoordinates(void)
{
    std::vector<int> coordinates = this->GetCoordinatesAsVector();
    std::cout << "x: " << coordinates[0] << " y: " << coordinates[1] << std::endl;
}

VisibilityBase::VisibilityBase(int x_input, int y_input)
{
    this->x = x_input;
    this->y = y_input;
}

/**************************************/

/******** Function definitions ********/

/**************************************/
