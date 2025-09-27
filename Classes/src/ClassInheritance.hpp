#ifndef CLASS_INHERITANCE_HPP
#define CLASS_INHERITANCE_HPP

/********* Include statements *********/

#include <iostream>
#include <string>

/**************************************/

// One of the most powerful features in the object oriented programming paradigm is inheritance.
// It allows the developer to branch off a class so that code repetition is avoided as much as
// possible. For example, a base class may be defined with some commonly used methods within it,
// and if other classes that extend the functionality of the base class have to be written, then
// those inheritor classes do not have to define again the base class methods again.

// In this file, a base class as a derived class will be defined. This one will represent a
// movable entity in a videogame.

// On the other hand, a derived class will be defined as well, which will define a player. Thus,
// a name should be provided for it additionally to those methods and variables that are already
// included within the base class. Derived class will always be a superset of the base class,
// it's t say, it will always have all of the methods and variables that are found within the base
// class plus (possibly) something else. Keep in mind that members/methods tagged as private are
// also inherited despite them not being accessible for the inheritor class.

/********** Class prototypes **********/

class ClassInheritanceBase
{
public:
    int x;
    int y;
    void Move(int x_input, int y_input);
    void PrintCoordinates(void);
};

// In order to define the derived class, a colon should be placed after the class name, and then
// the base class name.

class ClassInheritanceDerived : public ClassInheritanceBase
{
public:
    std::string name;
    ClassInheritanceDerived(int x_input, int y_input, const char* name);
    void PrintName(void);
};

/**************************************/

#endif
