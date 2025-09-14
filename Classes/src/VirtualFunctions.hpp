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

// Since C++ 11, "override" keyword can be used to mark functions to be overriden in derived class.
// It is not really mandatory, however it is still strongly recommendable in order to make the code
// more readable as well as bug-proof. 

/********** Class prototypes **********/

class VirtualFunctionsBase
{
public:
    std::string Greeting(void);
    virtual std::string Talk(void);
};

class VirtualFunctionsDerived : public VirtualFunctionsBase
{
private:
    std::string name;
public:
    VirtualFunctionsDerived(const std::string& name_input);
    std::string Greeting(void);
    std::string Talk(void) override;
};

/**************************************/

#endif