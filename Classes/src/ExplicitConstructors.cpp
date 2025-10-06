/********* Include statements *********/

#include <string>
#include <iostream>
#include "ExplicitConstructors.hpp"

/**************************************/

/********* Method definitions *********/

int ImplicitOneParameter::getUserID(void)
{
    return this->user_ID;
}

ImplicitOneParameter::ImplicitOneParameter(const int input_user_ID):
user_ID(input_user_ID)
{
    std::cout << "Created a new ImplicitOneParameter object with user_ID: " << this->user_ID << "." << std::endl; 
}

ImplicitTwoParameters::ImplicitTwoParameters(const int input_user_ID, const std::string& input_user_name):
ImplicitOneParameter(input_user_ID), user_name(input_user_name)
{
    std::cout << "Created a new ImplicitTwoParameters object with user_ID: " << this->getUserID() << 
    " and user_name: " << this->user_name << "." << std::endl; 
}

ImplicitTwoParametersNoDefault::ImplicitTwoParametersNoDefault(const int input_user_ID, const std::string& input_user_name) :
ImplicitOneParameter(input_user_ID), user_name(input_user_name)
{
    std::cout << "Created a new ImplicitTwoParametersNoDefault object with user_ID: " << this->getUserID() << 
    " and user_name: " << this->user_name << "." << std::endl; 
}

ExplicitClass::ExplicitClass(const std::string& input_task):
task(input_task)
{
    std::cout << "Created a new ExplicitClass object with user_ID: " << this->task << "." << std::endl; 
}

/**************************************/
