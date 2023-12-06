#ifndef OPERATOR_OVERLOADING_HPP
#define OPERATOR_OVERLOADING_HPP

/********* Include statements *********/

#include <iostream>
#include <vector>
#include <string>

/**************************************/

// In C/C++, there is a handful of operators that can have a special meaning and can be replicated through
// functions. For example, "++" operator adds 1 to an integer. Luckily, the same can done in C++ arbitrarily,
// it's to say, given a class, the behaviour of a specific operator can be defined thanks to a concept
// known as "operator overloading". For example, if we had an object of a class defined by ourselves, and we
// wanted to know if they were equal to another object of the same class (by comparing each of its member, for
// example), it could be defined a "==" operator overload in order to do so without having to call any function.

// The common syntax for operator overloading is: <return_type> operator<operator_symbol>(args) const {<function_body>}
// Actually, const keyword at the end of the function prototype is not mandatory, although it is common. What it
// means is just that the object from which the overloaded operator is called is not meant to be changed whatsoever.
// However, we may want to change the calling object, for instance, if we want to add values to it.

/********** Class prototypes **********/

class OperatorOverloading
{
private:
    int x;
    int y;
    std::string name;
public:
    OperatorOverloading();
    OperatorOverloading(int x_input, int y_input, std::string name_input);
    bool operator==(const OperatorOverloading& obj) const;
    OperatorOverloading operator+(const OperatorOverloading& obj) const;
    friend void ShowCoordinatesAsVector(OperatorOverloading& obj);
};

/**************************************/

#endif