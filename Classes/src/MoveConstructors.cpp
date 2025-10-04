/********* Include statements *********/

#include <iostream>
#include <string>
#include <memory>
#include "MoveConstructors.hpp"

/**************************************/

/********* Method definitions *********/

std::string DummyMoveClassBase::BuildConstructorDestructorMessage(const std::string& action, const std::string& class_name = "DummyMoveClassBase") const
{
    return (action + " " + class_name + " instance with name: " + this->name + " and age: " + std::to_string(*(this->age_ptr)));
}

std::string DummyMoveClassBase::getName(void) const
{
    return this->name;
}

int DummyMoveClassBase::getAge(void) const
{
    return *(this->age_ptr);
}

void DummyMoveClassBase::setAge(const int input_age)
{
    *(this->age_ptr) = input_age;
}

DummyMoveClassBase::DummyMoveClassBase(const std::string input_name, const int input_age):
name(input_name), age_ptr(std::make_unique<int>(input_age))
{}

DummyMoveClassBase::~DummyMoveClassBase(void)
{}

DummyMoveClassBase::DummyMoveClassBase(const DummyMoveClassBase& other):
name(other.getName()), age_ptr(std::make_unique<int>(other.getAge()))
{}

void DummyCopyConstructorClass::OutputConstructorDestructorMessage(const std::string& action) const
{
    std::cout << DummyMoveClassBase::BuildConstructorDestructorMessage(action, "DummyCopyConstructorClass") << std::endl;
}

DummyCopyConstructorClass::DummyCopyConstructorClass(const std::string input_name, const int age):
DummyMoveClassBase(input_name, age)
{
    this->OutputConstructorDestructorMessage("Created");
}

DummyCopyConstructorClass::DummyCopyConstructorClass(const DummyCopyConstructorClass& other):
DummyMoveClassBase(other)
{
    this->OutputConstructorDestructorMessage("Copied");
}

DummyCopyConstructorClass& DummyCopyConstructorClass::operator=(const DummyCopyConstructorClass& other)
{
    if(this == &other)
        return *this;
    
    this->setAge(other.getAge());

    return *this;
}
    
DummyCopyConstructorClass::~DummyCopyConstructorClass(void)
{
    this->OutputConstructorDestructorMessage("Destroyed");
}

/**************************************/
