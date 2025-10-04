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

// Three types of privacy qualifiers exist in C++ classes:
// ·private: only visible by the current class, access is not allowed from the outside. Variables
//  and methods tagged as private cannot be called outside the class.
// ·protected: only visible for the current class as well as any inheritor class. Cannot be called
//  outside the class nor any or the inheritor classes. Derived classes have access to these
//  variables / methods.
// ·pubic: visible from anywhere. Can be called from in or out of the class or by any inheritor class.

// Upper (base) class methods or variables can be called by using base class' name. For instance, if
// we had "derived" and "base" classes, and we shadowed a method within derived, we could still use
// base::myMethod to call the base class method within the derived class.

// There's a keyword that prevents derived class from inheriting: final. If used in a base class,
// any of the derived class objects will not be able to shadow / override it. This may be useful in
// terms of performance apart from being a hint to fellow developers since it may prevent derived
// classes from creating v-tables. "final" keyword can also be used for classes, meaning that the
// final class can no longer be inherited.

// When it comes to methods, "final".methods do inherit the method in question but cannot override it.

/********** Class prototypes **********/

class ClassInheritanceBase
{
public:
    int x;
    int y;
    void Move(int x_input, int y_input);
    void PrintCoordinates(void);
    virtual void Greeting(void) final;
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

// Same as mentioned before, classes marked as "final" cannot inherited. The creation of a
// hypothetical class as follows:
// class DerivedAttempt : public MyFinalClass
// (Where MyFinalClass is a final-qualified class definition) will lead to a compilation error.

class ClassInheritanceFinal final
{
public:
    void Greeting(void) const;
};

// Even code hinters such as intellisense will tell tell the mistake below even without having
// compiled.

// class InheritanceAttempt : public ClassInheritanceFinal
// {
// public:
//     void Greeting(void) const;
// };

/**************************************/

#endif
