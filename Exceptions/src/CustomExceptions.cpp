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
// Since the methods shown are public, they can be overridden on condition the qualifiers are mantained.
// An alternative (and popular) choice is to call the base constructor in the derived class constructor
// especially in those cases in which the base class constructor takes a string as input parameter.

/***** Private function prototypes ****/

/**************************************/

/******** Function definitions *********/

/**************************************/
