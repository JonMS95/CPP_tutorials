/********* Include statements *********/

#include <iostream>
#include <string>
#include <memory>
#include "MoveConstructors.hpp"

/**************************************/

/********* Method definitions *********/

std::string DummyCopyConstructorClass::getName(void) const
{
    return this->name;
}

int DummyCopyConstructorClass::getAge(void) const
{
    return *age_ptr;
}

DummyCopyConstructorClass::DummyCopyConstructorClass(const std::string input_name, const int input_age):
name(input_name), age_ptr(std::make_unique<int>(input_age))
{
    std::cout << "Created DummyCopyConstructorClass instance with name: " << this->name << " and age: " << *(this->age_ptr.get()) << std::endl;
}

DummyCopyConstructorClass::DummyCopyConstructorClass(const DummyCopyConstructorClass& other):
name(other.getName()), age_ptr(std::make_unique<int>(other.getAge()))
{
    std::cout << "Copied DummyCopyConstructorClass instance with name: " << this->name << " and age: " << *(this->age_ptr.get()) << std::endl;
}

DummyCopyConstructorClass::~DummyCopyConstructorClass(void)
{
    std::cout << "Destroyed DummyCopyConstructorClass instance with name: " << this->name << " and age: " << *(this->age_ptr.get()) << std::endl;
}

/**************************************/
