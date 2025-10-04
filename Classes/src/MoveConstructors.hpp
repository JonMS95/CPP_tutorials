#ifndef MOVE_CONSTRUCTORS_HPP
#define MOVE_CONSTRUCTORS_HPP

/********* Include statements *********/

#include <iostream>
#include <string>
#include <memory>

/**************************************/

// When it comes to copying classes, a memory-related problem arises: copies may end up being pretty expensive.
// As a reponse to this, move constructors exist. This type of constructors somehow steal resources from a
// temporary object (rvalue) instead of copying them (too heavy). Its syntax goes like follows:
// ClassName(ClassName&& other) noexcept;
// Where:
// ·&& is an rvalue reference, meaning that it can only bind to temporary object*, not regular lvalues.
// ·noexcept: prevents the method in question from throwing exceptions, making the program directly crash instead
//  in case any error happens.
//
// * "Temporary object" stands for values that do not come from variables which have already been defined.
//   These functions can, for instance, take "5" or "getNumber()" or "1.5f + my_var", but not solely "my_var".
//
// Move constructors do not apply to any type (it does not affect primitive types), but it can affect some
// well-known classes such as std::vector, std::unique_ptr, ...
// When using std::move over a variable like follows:
// std::unique_ptr<int> a = std::make_unique<int>(20);
// std::unique_ptr<int> b = std::move(a);
// "a" variable will remain empty afterwards (=nullptr) whereas "b" will point at the value originally referenced
// by variable "a".

/********** Class prototypes **********/

/************* Base class *************/

class DummyMoveClassBase
{
private:
    std::string name;
    std::unique_ptr<int> age_ptr;

protected:
    std::string BuildConstructorDestructorMessage(const std::string& action, const std::string& class_name) const;
    virtual void OutputConstructorDestructorMessage(const std::string& action) const = 0;

    DummyMoveClassBase(void) = delete;

    std::string getName(void) const;
    int getAge(void) const;
    void setAge(const int input_age);

    DummyMoveClassBase(const std::string input_name, const int age);
    DummyMoveClassBase(const DummyMoveClassBase& other);
    DummyMoveClassBase(DummyMoveClassBase&& other) noexcept;
    
    virtual ~DummyMoveClassBase(void);
};

/************* Copy class *************/

class DummyCopyConstructorClass : public DummyMoveClassBase
{
private:
    void OutputConstructorDestructorMessage(const std::string& action) const override;

public:
    DummyCopyConstructorClass(const std::string input_name, const int age);
    DummyCopyConstructorClass(const DummyCopyConstructorClass& other);
    DummyCopyConstructorClass& operator=(const DummyCopyConstructorClass& other);

    DummyCopyConstructorClass(DummyCopyConstructorClass&& other) = delete;
    
    ~DummyCopyConstructorClass(void) override;
};

/************* Move class *************/

class DummyMoveConstructorClass : public DummyMoveClassBase
{
private:
    void OutputConstructorDestructorMessage(const std::string& action) const override;

public:
    DummyMoveConstructorClass(const std::string input_name, const int age);
    DummyMoveConstructorClass(DummyMoveConstructorClass&& other) noexcept;

    DummyMoveConstructorClass(const DummyMoveConstructorClass& other) = delete;
    DummyMoveConstructorClass& operator=(const DummyMoveConstructorClass& other) = delete;
    
    ~DummyMoveConstructorClass(void) override;
};

/**************************************/

#endif
