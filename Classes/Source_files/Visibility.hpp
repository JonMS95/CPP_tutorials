#ifndef VISIBILITY_HPP
#define VISIBILITY_HPP

/********* Include statements *********/

#include <iostream>
#include <string>
#include <vector>

/**************************************/

// Visibility modifiers are, as the name suggests, some modifiers that allow or forbid them to be visible from the outside.
// they do not affect the performance of the code whatsoever, so their purpose is to organize your code better.

// When it comes to structs, all of the members inside them are public by default for retro-compatibility matters.
// However, they are quite useful when used in classes.

// In C++, there are 3 visibility modifiers: private, public and protected. Here is what each of them mean:
// ·public:     members are accesible from outside the class.
// ·private:    members cannot be accessed or viewed from outside the class.
// ·protected:  members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

// In the example below, we are creating a base class with a couple of private variables. Therefore, these two cannot
// be accessed from the derived class directly, but using the "SetCoordinates" method instead.

// Note that the base class constructor is called when the derived class constructor is executed, as a new base class
// object instance is being actually created.

// Okay, that's fine, but it's still worth pointing out that there are some special type of functions that can actually
// access a class' private members and methods: friend functions. The prototype of these functions should be stated
// somewhere within the target class definition, although the definition of the function itself must be as if it was
// a common function.

/********** Class prototypes **********/

class VisibilityBase
{
private:
    int x, y;
protected:
    std::vector<int> GetCoordinatesAsVector(void);
    void SetCoordinates(int x_input, int y_input);
public:
    void PrintCoordinates(void);
    VisibilityBase(void);
    VisibilityBase(int x_input, int y_input);
    friend void ShowCoordinatesFromTheOutside(VisibilityBase& obj);
    friend void SetCoordinatesFromTheOutside(VisibilityBase& obj, int x_input, int y_input);
};

class VisibilityDerived : public VisibilityBase
{
public:
    VisibilityDerived(int x_input, int y_input);
    void DoubleCoordinates(void);
};

/**************************************/

/********* Function prototypes ********/

/**************************************/

#endif