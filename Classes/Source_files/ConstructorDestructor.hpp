#ifndef CONSTRUCTOR_DESTRUCTOR_HPP
#define CONSTRUCTOR_DESTRUCTOR_HPP

/********* Include statements *********/

#include <iostream>

/**************************************/

// If no class constructor method is defined, then no additional action will be taken when declaring an object
// (default constructor method will be used, same for the destructor method). 

// Therefore, class variables will have a value that wil be determined by whatever is found in the stack
// memory when initialized. In order to avoid that, a constructor can be defined. Its name must match the name
// of the class. More than one constructor method may be defined as long as their function signatures are
// not the same (they have different input parameters, regardless of their return variable type).
// It's worth mentioning that return type must not be specified when defining these methods.
// When a constructor with no input parameters is defined, it will substitute the default contructor method.

// When it comes to destructor methods, it can be said that the logic behind them is almost the same. Whenever
// a variable is destroyed (whether or not it is created in stack or heap memory), the destructor will be called.
// Unlike constructor methods, destructors must not take any input parameters whatsoever. In order to define a
// destructor method, a "tilde" symbol (~) must be used preceeding the destructor method name (which again, must
// be the same as the class name).
// Contrary to what intuition may suggest, destructor methods can be called manually, although this is considered
// to be quite weird, as it does not actually free any meory used by the class object instance.

/*********** Class prototype **********/

class ConstructorDestructor
{
private:
    int x;
    int y;
public:
    ConstructorDestructor(void);
    ConstructorDestructor(int x_input, int y_input);
    ~ConstructorDestructor(void);
    void PrintCoordinates(void);
};

/**************************************/

#endif