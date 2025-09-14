#ifndef INTERFACES_HPP
#define INTERFACES_HPP

/********* Include statements *********/

#include <iostream>
#include <string>

/**************************************/

// An interface, also known as "pure virtual function" or "abstract method" in other languages such as Java
// is a type of function which is part of a base class but has no definition (it's to say, it has no body but
// just a prototype).

// Basically, the aim of these type of functions is to force subclasses to implement the method.

// In ths case, we will define a base class with a virtual method. As a reminder, a virtual method is a special
// type of method that can be overriden by the derived class, but which makes the compiler know which of the
// methods (either the base class or the derived class method) is the one to be called if any type of casting
// has been previously performed during the program.

// In order to turn virtual methods into interfaces, function prototype within base class must be equaled to
// zero.

// Aditionally, functions that take interface classes as input parameters may exist. Although it is not allowed
// to instantiate an object of an interface class, it may exist a function that takes an interface class that
// guarantees the method of an interface class to be called within it.

/********** Class prototypes **********/

class InterfacesBase
{
public:
    void Hello();
    virtual std::string Greeting(void) = 0;
};

class InterfacesDerived : public InterfacesBase
{
public:
    std::string Greeting(void) override;
};

/**************************************/

/********* Function prototypes ********/

std::string PrintInterfaceGreeting(InterfacesBase* pIfaceClass);

/**************************************/

#endif