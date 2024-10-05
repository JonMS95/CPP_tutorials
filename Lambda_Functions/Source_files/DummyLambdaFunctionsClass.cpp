#include "DummyLambdaFunctionsClass.hpp"

Dummy::Dummy(unsigned int age_input, const std::string name_input): age(age_input), name(name_input)
{
    auto print_attr = [this]()
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Age: " << this->age << std::endl;
    };

    print_attr();
};

Dummy::Dummy(Dummy& obj): name(obj.name), age(obj.age)
{
    auto print_both_attr = [this](Dummy& obj)
    {
        std::cout << "this->name: " << this->name << std::endl;
        std::cout << "this->age: " << this->age << std::endl;

        std::cout << "obj.name: " << obj.name << std::endl;
        std::cout << "obj.age: " << obj.age << std::endl;
    };

    print_both_attr(obj);
}

void Dummy::updateAge(unsigned int age_new_input)
{
    auto print_age = [this](bool before = true)
    {
        std::cout << "("<< (before ? "Before" : "After") << ") this->age: " << this->age << std::endl;
    };

    auto update_age = [this](int new_age)
    {
        this->age = new_age;
    };

    print_age();
    update_age(age_new_input);
    print_age(false);
}