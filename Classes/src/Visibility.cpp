/********* Include statements *********/

#include "Visibility.hpp"

/**************************************/

/********* Method definitions *********/

std::vector<int> VisibilityBase::GetCoordinatesAsVector(void)
{
    return {this->x, this->y};
}

void VisibilityBase::SetCoordinates(int x_input, int y_input)
{
    this->x = x_input;
    this->y = y_input;
}

void VisibilityBase::PrintCoordinates(void)
{
    std::vector<int> coordinates = this->GetCoordinatesAsVector();
    std::cout << "x: " << coordinates[0] << " y: " << coordinates[1] << std::endl;
}

VisibilityBase::VisibilityBase(void)
{
    std::cout << "Creating VisibilityBase class instance with [0, 0] coordinates." << std::endl; 
    this->x = 0;
    this->y = 0;
}

VisibilityBase::VisibilityBase(int x_input, int y_input)
{
    this->x = x_input;
    this->y = y_input;
}

VisibilityDerived::VisibilityDerived(int x_input, int y_input)
{
    std::cout << "Creating VisibilityDerived class instance with [" << x_input << ", " << y_input << "] coordinates." << std::endl;
    this->SetCoordinates(x_input, y_input);
}

void VisibilityDerived::DoubleCoordinates(void)
{
    std::vector<int> coordinates = this->GetCoordinatesAsVector();
    this->SetCoordinates(coordinates[0] * 2, coordinates[1] * 2);
}

/**************************************/

/******** Function definitions ********/

void ShowCoordinatesFromTheOutside(VisibilityBase& obj)
{
    std::cout << "Object coordinates using friend function. x: " << obj.x << " y: " << obj.y << std::endl; 
}

void SetCoordinatesFromTheOutside(VisibilityBase& obj, int x_input, int y_input)
{
    obj.x = x_input;
    obj.y = y_input;
}

/**************************************/
