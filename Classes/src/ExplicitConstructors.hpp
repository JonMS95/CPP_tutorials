#ifndef EXPLICIT_CONSTRUCTORS_HPP
#define EXPLICIT_CONSTRUCTORS_HPP

/********* Include statements *********/

#include <string>

/**************************************/

//  In C++, implicit conversions can be performed when assigning a known variable or rvalue to a new object
//  For example, if we had a class which constructor had jsust a single input parameter (such as an integer),
//  something like the following could be done:
//
//  MyClass_A obj_a = 0;
//
//  The situation described above could be equivalent to calling a constructor like the one below:
//
//  MyClass_A(const int input_value):
//  value(input_value)
//  {
//      std::cout << "Created instance with value; " << this->value << std::endl;
//  }
//
//  By default, every constructor in a C++ class is a conversion constructor as long as there is a
//  possibility to be called by just passing a single input parameter to it. For instance, if the constructor
//  looked like follows:
//
//  MyClass_B(const int input_value, const std::string& input_name = "Default"):
//  value(input_value), name(input_name) 
//  {
//      std::cout << "Created instance with value; " << this->value <<
//      " and name: " << this->name << "." << std::endl;
//  }
//
//  Then a single input parameter could be provided so the situation below:
//
//  MyClass_B obj_b = 1;
//
//  May still lead to calling a conversion constructor since both constructor's input parameter would be
//  already provided.
//
//  So as to avoid these situations, explicit keyword could be used preceding a constructor's definition.
//  In such case, there would be no "=" operator usage (could still be for assignment as an operator
//  overload but not for constructors anymore).

/********** Class prototypes **********/

class ImplicitOneParameter
{
private:
     const int user_ID; 

public:
    ImplicitOneParameter(void) = delete;
    
    ImplicitOneParameter(const int input_user_ID);
    virtual ~ImplicitOneParameter(void) = default;

    int getUserID(void);
};

class ImplicitTwoParameters : public ImplicitOneParameter
{
private:
    const std::string user_name;

public:
    ImplicitTwoParameters(void) = delete;

    ImplicitTwoParameters(const int input_user_ID, const std::string& input_user_name = "DEFAULT");
    ~ImplicitTwoParameters(void) = default;
};

class ImplicitTwoParametersNoDefault : public ImplicitOneParameter
{
private:
    const std::string user_name;

public:
    ImplicitTwoParametersNoDefault(void) = delete;

    ImplicitTwoParametersNoDefault(const int input_user_ID, const std::string& input_user_name);
    ~ImplicitTwoParametersNoDefault(void) = default;
};

class ExplicitClass
{
private:
     const std::string task; 

public:
    ExplicitClass(void) = delete;
    
    explicit ExplicitClass(const std::string& input_task);
    virtual ~ExplicitClass(void) = default;
};

/**************************************/

#endif
