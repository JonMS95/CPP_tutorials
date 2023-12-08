/********* Include statements *********/

#include <iostream>
#include <string>
#include "Templates.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER     "*********************************"
#define MSG_TEST_TEMPLATES  "Testing Templates."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestTemplates()
{
    PrintTestHeader(MSG_TEST_TEMPLATES);

    std::cout << "3 + 4 = " << TemplateAdd(3, 4) << std::endl;
    std::cout << "2.3 + 4.9 = " << TemplateAdd(2.3, 4.9) << std::endl;

// If it is not specified anywhere which the target type to be treated is, then it will be implicitly
// casted by the template function. Nevertheless, it can be explicitly told by using triangular brackets,
// same as it is done when declaring the type a vector will contain (such as std::vector<int> for integers).
// In the case shown below, it is necessary to tell that the target type is std::string. Otherwise,
// const char* will be assumed, which is a type that does not admit the "+" operator overloading operation.

    std::cout << "Hello + World = " << TemplateAdd<std::string>("Hello", "World") << std::endl;

    TemplatePrintInt<7>();

    TemplateArray<std::string, 3> template_array_0;
    TemplateArray<int, 4> template_array_1("Jon");

    std::cout << "template_array_0.GetName() = " << template_array_0.GetName() << std::endl;
    std::cout << "template_array_1.GetName() = " << template_array_1.GetName() << std::endl;

    template_array_0[0] = "Hello";
    template_array_0[1] = ", ";
    template_array_0[2] = "World!";

    template_array_1[0] = 1;
    template_array_1[1] = 9;
    template_array_1[2] = 9;
    template_array_1[3] = 5;

    std::cout << ( template_array_0[0] + template_array_0[1] + template_array_0[2] ) << std::endl;
    std::cout << "Birth date: " << template_array_1[0] << template_array_1[1] << template_array_1[2] << template_array_1[3] << std::endl;
}

int main()
{
    TestTemplates();

    return 0;
}

/**************************************/
