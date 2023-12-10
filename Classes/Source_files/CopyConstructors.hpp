#ifndef COPY_CONSTRUCTORS_HPP
#define COPY_CONSTRUCTORS_HPP

/********* Include statements *********/

#include <iostream>
#include <cstring>

/**************************************/

// Same as it happens in pure C code, when two variables of the same type are declared (let's say, a and b) and the value of "a" is
// assigned to "b", then the value of "a" is stored in "b" as well, but each of those variables lie in different memory addresses.
// Therefore, if the value of "b" is changed, nothing happens in "a" since the memory addresses are different as stated before.

// This behaviour is not exclusive of primitive type variables, but it also applies for classes or any other user-made data type.

// Again, C++ behaves exactly the same way as pure C code does, as using pointers which store the same memory address imply that
// any of them may modify the content of the variable they are pointing at (with the exception of references: keep in mind that
// references in C++ are nothing but aliases to already existing variables).

// in this case, we are going to explain and prove the concept of copy constructor by creating a class that is meant to emulate the
// C++ std::string class.

// In C++, a default constructor is provided, which performs a "shallow copy". A shallow copy does not take into account whether or
// not are pointer variables pointing at the same memory address, so if doing "variable_of_class_X_1 = variable_of_class_X_0", we
// will not allocate a new amount of memory in heap, but we will just copy them into the new object instead. In other words, C++
// just performs a memcpy of the original object instance.

// The syntax of a copy constructor prototype is pretty simple: Class_Name(const Class_Name& other_instance)
// It makes sense indeed, since the object instance to be copied is required when performing the
// "variable_of_class_X_1 = variable_of_class_X_0" statement.

// Copy constructor is also used in functions that take input parameters of a given class type. If a reference is passed to the
// function (see "SmartPrintString" friend function below), then nothing special will happen, as it takes a reference as input
// argument. But if the variable itself is provided, then a copy of the input variable is created (which, as we already know, will
// just exist locally, within the scope of that function), as it happens in the "DummyPrintString" function. Obviously, the destructor
// method is called as well when exiting the function, but as copy constructor performs a deep copy, there's nothing we should be
// worried about ;) .

/********** Class prototypes **********/

class CopyConstructors
{
private:
    char* m_buffer;
    unsigned int m_size;

public:
    CopyConstructors(const char* string_input);
    ~CopyConstructors(void);
    CopyConstructors(const CopyConstructors& other);
    char& operator[](unsigned int index);
    friend std::ostream& operator<<(std::ostream& stream, const CopyConstructors& copy_constructors);
    friend void DummyPrintString(CopyConstructors other);
    friend void SmartPrintString(CopyConstructors& other);
};

/**************************************/

/********* Function prototypes ********/

/**************************************/

#endif