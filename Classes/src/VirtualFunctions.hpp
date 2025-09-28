#ifndef VIRTUAL_FUNCTIONS_HPP
#define VIRTUAL_FUNCTIONS_HPP

/********* Include statements *********/

#include <iostream>
#include <string>

/**************************************/

// Virtual functions allow us to override method in subclasses. Thus, if a class defines a method,
// it can be redefined again in the derived class so it does something else.

// Now let's define a couple of classes, one derived from the other. In each of them, a method called
// "Greeting" is going to be defined. Therefore, an instance of each class will return different values
// when the method called "Greeting" is called.

// However, different values will be returned if some type of casting is done. If a pointer of type
// VirtualFunctionsBase is used to point to an instance of VirtualFunctionsDerived class, then the
// method of the base class will be used. This is what is commonly known as "polymorphism".
// This property does not appear only if instances of different classes are used, but also when pointers
// of different types are used.

// If we want to somehow make the compiler realize that the proper function to be executed is not the
// base class but actually the one that is found in the derived class, then virtual functions have to be used.
// The "virtual" keyword must be used in the base class, so that derived class do actually override those.
// what this does behind the scenes is a v-table, which tells the compiler to point at the proper function
// at runtime. Keep in mind that this implies a performance penalty toll, so it should be used with care.

// The point above has subtle nuances. Just to make it simpler: if a pointer is used to point at a derived
// class object, but the pointer's type is the same as the base class', then:
//  ·If called method is non-virtual, the base class method will be called.
//  ·Otherwise, it will call the method belonging to the derived class (which has been overwritten in such
//  derived class) even if the type of the pointer in question is the same as the base class instead of the
//  derived one.

// Using virtual in base classes for destructor methods(as long as they are meant to be extended by any
// derived classes) is crucial since it may lead only base class destructors to be called.
// In case no explicit destructor is defined within the base class, "default" keyword may be used alongside
// virtual for such purpose (see VirtualFunctionsBase class definition below).

// Accessible elements can be explicitly called from inheritor class by using the "::" operator. This way,
// there's no need to rewrite the whole base class method again if the aim is to add something to the base
// method.

// Since C++ 11, "override" keyword can be used to mark functions to be overriden in derived class.
// It is not really mandatory, however it is still strongly recommendable in order to make the code
// more readable as well as bug-proof. 

// Function shadowing (replacing base class functions by others in derived classes) is considered to be
// compile time polymorphism since it's always known which method to be called. Overriding, in contrast,
// is knwon as runtime polymorphism as the v-table (something like a table to the base class function
// pointers) should be created once the program is being executed (it cannot be done beforehand).

/********** Class prototypes **********/

class VirtualFunctionsBase
{
public:
    std::string Greeting(void);
    virtual std::string Talk(void);
    virtual ~VirtualFunctionsBase() = default;
    virtual void SayBye(void);
};

class VirtualFunctionsDerived : public VirtualFunctionsBase
{
private:
    std::string name;
public:
    VirtualFunctionsDerived(const std::string& name_input);
    std::string Greeting(void);
    std::string Talk(void) override;
    void SayBye(void) override;
};

/**************************************/

#endif
