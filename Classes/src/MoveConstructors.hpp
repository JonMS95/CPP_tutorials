#ifndef CLASS_INHERITANCE_HPP
#define CLASS_INHERITANCE_HPP

/********* Include statements *********/

#include <iostream>
#include <string>
#include <memory>

/**************************************/

// When it comes to copying classes, a memory-related problem arises: copies may end up being pretty expensive.

/********** Class prototypes **********/

class DummyCopyConstructorClass
{
private:
    const std::string name;
    std::unique_ptr<int> age_ptr;
public:
    DummyCopyConstructorClass(void) = delete;
    DummyCopyConstructorClass(const std::string input_name, const int age);
    DummyCopyConstructorClass(const DummyCopyConstructorClass& other);
    DummyCopyConstructorClass(const DummyCopyConstructorClass&& other) = delete;
    virtual ~DummyCopyConstructorClass(void);
};

/**************************************/

#endif
