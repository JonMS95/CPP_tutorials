// This is an attempt to grasp all the nuances when it comes to Classes in C++.
// Classes in C++ have already been studied, so this is more like brushing up on the topic rather than starting up from scratch for me.

/********* Include statements *********/

#include <iostream>
#include "StaticInClasses.hpp"
#include "ConstructorDestructor.hpp"
#include "ClassInheritance.hpp"
#include "VirtualFunctions.hpp"
#include "Interfaces.hpp"
#include "Visibility.hpp"
#include "ConstructorInitializerList.hpp"
#include "OperatorOverloading.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_STATIC_IN_CLASSES      "Testing StaticInClasses."
#define MSG_TEST_CONSTRUCTOR_DESTRUCTOR "Testing ConstructorDestructor."
#define MSG_TEST_CLASS_INHERITANCE      "Testing ClassInheritance."
#define MSG_TEST_VIRTUAL_FUNCTIONS      "Testing VirtualFunctions."
#define MSG_TEST_INTERFACES             "Testing Interfaces."
#define MSG_TEST_VISIBILITY             "Tetsing Visibility."
#define MSG_TEST_CONSTRUCTOR_INIT_LIST  "Testing ConstructorInitializerList."
#define MSG_TEST_OPERATOR_OVERLOADING   "Testing OperatorOverloading."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
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

void TestVirtualFunctions()
{
    PrintTestHeader(MSG_TEST_VIRTUAL_FUNCTIONS);

    VirtualFunctionsBase vf1;
    VirtualFunctionsBase* pvf1 = &vf1;

    VirtualFunctionsDerived vf2("JON");
    VirtualFunctionsDerived* pvf2 = &vf2;
    VirtualFunctionsBase* pvf3 = &vf2;

    // If the function to be called is not marked as virtual, then the function will be called depending on the
    // type of the variable (it may be casted) or the type of the pointer that is used to point at the instance.
    std::cout << pvf1->Greeting() << std::endl;
    std::cout << pvf2->Greeting() << std::endl;
    std::cout << pvf3->Greeting() << std::endl;
    
    // If the base class function is marked as virtual, then the compiler will have a clue about which function
    // should it be calling at runtime whether it is the one in the base or the derived class.
    std::cout << pvf1->Talk() << std::endl;
    std::cout << pvf2->Talk() << std::endl;
    std::cout << pvf3->Talk() << std::endl;

    VirtualFunctionsDerived vf4("JON");
    VirtualFunctionsBase vf5 = VirtualFunctionsDerived("JMS");
    std::cout << vf5.Greeting() << std::endl;
}

void TestInterfaces()
{
    PrintTestHeader(MSG_TEST_INTERFACES);

    // An InterfacesBase object cannot be instantiated as it includes an interface between itself,
    // which could not be called due to the fact that it has actually no implementation.
    // Same would happen if no implementation was provided within the derived class.

    // InterfacesBase if1;
    InterfacesDerived if2;
    if2.Hello();
    std::cout << if2.Greeting() << std::endl;

    std::cout << "Calling it from PrintInterfaceGreeting function: " << PrintInterfaceGreeting(&if2) << std::endl;
}

void TestVisibility()
{
    PrintTestHeader(MSG_TEST_VISIBILITY);

    VisibilityDerived v1(1, 2);

    v1.DoubleCoordinates();
    v1.PrintCoordinates();
    
    // v1.SetCoordinates(3, 4);

    // "SetCoordinates" function call above is not compilable, as it is protected. This means that it cannot be
    // accessed from the outside in contrast with public methods / variables. Instead, a public function
    // should be used to indirectly access the function. Thus, it's accessible only from the derived class'
    // context. However, we have provided a couple of friend functions within the base class.

    SetCoordinatesFromTheOutside(v1, 8, 9);
    ShowCoordinatesFromTheOutside(v1);
}

void TestConstructorInitializerList()
{
    PrintTestHeader(MSG_TEST_CONSTRUCTOR_INIT_LIST);

    ConstructorInitializerList cil1;
    ConstructorInitializerList cil2("JON", 28);

    cil1.PrintName();
    cil2.PrintName();
}

void TestOperatorOverloading()
{
    PrintTestHeader(MSG_TEST_OPERATOR_OVERLOADING);

    OperatorOverloading oo1(1, 2, "oo1");
    OperatorOverloading oo2(3, 4, "oo2");
    OperatorOverloading oo3(1, 2, "oo3");

    ShowCoordinatesAsVector(oo1);
    ShowCoordinatesAsVector(oo2);
    ShowCoordinatesAsVector(oo3);
    
    std::cout << "(oo1 == oo2) returns: " << (oo1 == oo2) << std::endl;
    std::cout << "(oo1 == oo3) returns: " << (oo1 == oo3) << std::endl;

    OperatorOverloading oo4(2, 2, "oo4");
    OperatorOverloading oo5(4, 7, "oo5");
    OperatorOverloading oo6 = oo4 + oo5;

    ShowCoordinatesAsVector(oo4);
    ShowCoordinatesAsVector(oo5);
    std::cout << "oo4 + oo5 = oo6" << std::endl;
    ShowCoordinatesAsVector(oo6);
}

int main()
{
    TestStaticInClasses();
    TestConstructorDestructor();
    TestClassInheritance();
    TestVirtualFunctions();
    TestInterfaces();
    TestVisibility();
    TestConstructorInitializerList();
    TestOperatorOverloading();

    return 0;
}

/**************************************/
