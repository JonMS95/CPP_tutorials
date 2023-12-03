#ifndef OPERATOR_OVERLOADING_HPP
#define OPERATOR_OVERLOADING_HPP

/********* Include statements *********/

#include <iostream>
#include <vector>

/**************************************/

// In C/C++, there is a handful of operators that can have a special meaning and can be replicated through
// functions. For example, "++" operator adds 1 to an integer. Luckily, the same can done in C++ arbitrarily,
// it's to say, given a class, the behaviour of a specific operator can be defined thanks to a concept
// known as "operator overloading". For example, if we had an object of a class defined by ourselves, and we
// wanted to know if they were equal to another object of the same class (by comparing each of its member, for
// example), it could be defined a "==" operator overload in order to do so without having to call any function.

// The common syntax for operator overloading is: <return_type> operator<operator_symbol>(args) const {<function_body>}

/********** Class prototypes **********/

class OperatorOverloading
{
private:
    int x;
    int y;
public:
    OperatorOverloading(int x_input, int y_input);
    bool operator==(const OperatorOverloading& obj) const;
    friend void ShowCoordinatesAsVector(OperatorOverloading& obj);
};

/**************************************/

#endif