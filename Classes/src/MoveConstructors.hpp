#ifndef MOVE_CONSTRUCTORS_HPP
#define MOVE_CONSTRUCTORS_HPP

/********* Include statements *********/

#include <iostream>
#include <string>
#include <memory>

/**************************************/

// When it comes to copying classes, a memory-related problem arises: copies may end up being pretty expensive.

/********** Class prototypes **********/

class DummyMoveClassBase
{
private:
    const std::string name;
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
    DummyMoveClassBase(DummyMoveClassBase&& other) = default;
    
    virtual ~DummyMoveClassBase(void);
};

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

/**************************************/

#endif
