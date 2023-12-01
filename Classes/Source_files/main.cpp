// This is an attempt to grasp all the nuances when it comes to Classes in C++.
// Classes in C++ have already been studied, so this is more like brushing up on the topic rather than starting up from scratch for me.

/********* Include statements *********/

#include "StaticInClasses.hpp"
#include "ConstructorDestructor.hpp"
#include "ClassInheritance.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_STATIC_IN_CLASSES      "Testing StaticInClasses."
#define MSG_TEST_CONSTRUCTOR_DESTRUCTOR "Testing ConstructorDestructor."
#define MSG_TEST_CLASS_INHERITANCE      "Testing ClassInheritance."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << header << std::endl;
}

void TestStaticInClasses(void)
{
    PrintTestHeader(MSG_TEST_STATIC_IN_CLASSES);

    StaticInClasses s1;

    s1.SetX(1);
    s1.SetY(2);

    s1.PrintClassVars();

    s1.a = 3;
    s1.b = 4;

    s1.PrintStaticVars();

    StaticInClasses s2;
    
    s2.PrintClassVars();

    // As PrintStaticVars::a and PrintStaticVars::b are shared by any instance of PrintStaticVars,
    // the value of these variable could be modified by any of those instances.

    s2.a = 33;
    s2.b = 55;

    s2.PrintStaticVars();

    // Static methods are just as "orphan" functions, in the sense that they are not actually part
    // of a class. They are just built like that to give them a little bit more of context.
    // As seen below, no instance is required before calling those functions.

    StaticInClasses::Greeting();
}

void TestConstructorDestructor(void)
{
    PrintTestHeader(MSG_TEST_CONSTRUCTOR_DESTRUCTOR);

    ConstructorDestructor cd1;
    cd1.PrintCoordinates();

    ConstructorDestructor cd2(2, 3);
    cd2.PrintCoordinates();
}

void TestClassInheritance()
{
    PrintTestHeader(MSG_TEST_CLASS_INHERITANCE);

    ClassInheritanceDerived ci(1, 2, "Test instance");
    
    ci.Move(5, 4);
    ci.PrintCoordinates();
    ci.PrintName();
}

int main()
{
    TestStaticInClasses();
    TestConstructorDestructor();
    TestClassInheritance();

    return 0;
}

/**************************************/
