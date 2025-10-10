/********* Include statements *********/

#include <stdexcept>
#include "CustomExceptions.hpp"

/**************************************/

/********* Define statements *********/

/**************************************/

// This is how base class exception is defined (more or less):
//
//  class exception
// {
//   public:
//     exception() noexcept { }
//     virtual ~exception() noexcept;
//
//     // Default copy constructor, assignment operator overload, move constructor here.
//
//     virtual const char* what() const noexcept;
// };
//
// Since the methods shown are public, they can be overridden on condition the qualifiers are mantained
// (except possibly virtual but override instead, in case it's not meant to be derived anymore).
// An alternative (and popular) choice is to call the base constructor in the derived class constructor
// especially in those cases in which the base class constructor takes a string as input parameter.
//
// Typical derived class' what() method prototype should look like follows:
//
// const char* what() const noexcept override
//
// Let's split it into pieces:
// ·const char*: returns a constant character string (C-style).
// ·const: since the method modifies nothing, const qualifier should be used.
// ·noexcept: the method should not throw any exception.
// ·override: as the base class method is virtual, it should be overriden in the derived class.

/***** Private function prototypes ****/

/**************************************/

/******** Function definitions *********/

class MyException : public std::exception
{
public:
    const char* what() const noexcept override
    {

    }
};

/**************************************/
