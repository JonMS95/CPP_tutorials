#ifndef DUMMY_LAMBDA_FUNCTIONS_CLASS
#define DUMMY_LAMBDA_FUNCTIONS_CLASS

#include <iostream>
#include <string>

class Dummy
{
private:
    unsigned int age;
    const std::string name;

public:
    Dummy(unsigned int age_input, const std::string name_input);
    Dummy(Dummy& obj);
    
    void updateAge(unsigned int age_new_input);
};

#endif