#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

/********* Include statements *********/

#include <iostream>
#include <string>

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
// the reason behind this is that linker should find the proper implementation for the instantiated types. In fact,
// the implementation of these template function will depend on the usage it is done of them.

// Appart from functions, template classes can be defined as well, which is, by the way, how most of the classes in
// the STL (Standard Template Library) are implemented, as the name suggests.

// In the template class example shown below, a custom array class is described. It will take two template arguments:
// firstly, the type of which the array will be, as it should be composed by different variable types, such as strings,
// integers, floating point numbers or whatever. Secondly, the size of the target array should be passed between
// triangular brackets. This way, it can be guaranteed that the array will be created in stack memory (same as it
// happens in std::array template class).

// Same as it happens with template fuctions, template classes should be fully defined within the header files, as the
// linker, again, should know which specific function is meant to be implemented depending on the type that is being used.

/********** Class prototypes **********/

template<typename T, int size> class TemplateArray
{
private:
    T m_template_array[size]; // This stands for an array of class "T" and size "size".
    std::string m_name;
    const int m_size = size;

public:
    TemplateArray(void):m_name("DEFAULT_NAME"){}
    
    TemplateArray(std::string name_input):
        m_name(name_input){}
    
    std::string GetName(void) { return this->m_name; }

    T& operator[](int index)
    {
        if(index < 0 || index > size)
        {
            return this->m_template_array[0];
        }

        return this->m_template_array[index];
    }
};

/**************************************/

/********* Function prototypes ********/

// In the context of the function defined below, T is the variable of any type. Therefore, if the function returns a
// "T" type object, it means that it will return a variable of the T type. Same goes for input parameters.
template<typename T> T TemplateAdd(T a, T b)
{
    return a + b;
}

// The explicit type the template function should work with can also be explicitly told, instead of using typename
// variables, which make the function usable with (almost) any variable type. This does not make much sense, but it
// just can exist.
template<int number> void TemplatePrintInt()
{
    std::cout << number << std::endl;
}

/**************************************/

#endif