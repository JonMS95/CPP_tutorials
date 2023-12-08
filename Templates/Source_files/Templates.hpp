#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

/********* Include statements *********/

/**************************************/

// The concept of template in C++ imay be applied both for functions and classes. Templates in C++ are basically
// a blueprint that lets the class or function work with multiple data types without having to declare those types
// explicitly.

// For example, if we were to write a function that adds two numbers, we could have to redefine it again for each
// of the data types we wanted to work with by defining a function overload for each of them.
// However, there is no need to do so as templates can define the function for whatever the target data type may be.
// The syntax for these is always the same:
// template<typename T> T TemplateFunction(T a, int b, float c, ...)
//{
//  return (whatever)
//}

// Something that is worth pointing out is that templates must be defined within header files instead of cpp files.
// the reason behind this is that linker should find the proper implementation for the instantiated types.

/********** Class prototypes **********/

/**************************************/

/********* Function prototypes ********/

// In the context of the function defined below, T is the variable of any type. Therefore, if the function returns a
// "T" type object, it means that it will return a variable of the T type. Same goes for input parameters.
template<typename T> T TemplateAdd(T a, T b)
{
    return a + b;
}

/**************************************/

#endif