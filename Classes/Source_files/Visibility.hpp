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

/********** Class prototypes **********/

class VisibilityBase
{
private:
    int x, y;
    std::vector<int> GetCoordinatesAsVector(void);
public:
    void PrintCoordinates(void);
    VisibilityBase(int x_input, int y_input);
};

class VisibilityDerived : public VisibilityBase
{
public:

};

/**************************************/

/********* Function prototypes ********/

/**************************************/

#endif