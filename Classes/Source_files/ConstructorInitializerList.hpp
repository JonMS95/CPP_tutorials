#ifndef CONSTRUCTOR_INITIALIZER_LIST_HPP
#define CONSTRUCTOR_INITIALIZER_LIST_HPP

/********* Include statements *********/

#include <iostream>
#include <string>

/**************************************/

// If a constructor was to be written, which initialized class member variables, the usual way to do so
// would be by taking one or more variables as input parameters, then assigning those values to the
// class members.

// However, there is another way to achive it in C++, which is known as constructor initializer list.
// Its syntax is: ClassName(input_args) : member_1(target_value_1), member_2(target_value_2), ... member_n(target_value_n)
// Keep in mind that because of the way this works underneath, members should be passed in order, it's to say,
// if member_a appears first in the class, then it should go first, and so on.

// The main purpose to initialize class membersthis way is not style but rather performance. If members are initialized
// the usual way, every member within the instance would be initialized twice. On top of that, const members cannot be
// initialized within the function's body, as they are meant to be constants. And yes, they can provide such a remarkable
// aesthetic upgrade to our code.

/********** Class prototypes **********/

class ConstructorInitializerList
{
private:
    std::string name;
    int age;
public:
    ConstructorInitializerList();
    ConstructorInitializerList(const std::string name_input, int age_input);
    void PrintName(void);
};

/**************************************/

/********* Function prototypes ********/

/**************************************/

#endif