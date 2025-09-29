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
#include "CopyConstructors.hpp"

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
#define MSG_TEST_COPY_CONSTRUCTORS      "Testing CopyConstructors."

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
    ci.Greeting();
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

    pvf2->SayBye();
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

    FriendClass fc("Joey");
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

void TestCopyConstructors()
{
    PrintTestHeader(MSG_TEST_COPY_CONSTRUCTORS);

    CopyConstructors cc1("Hello!");
    CopyConstructors cc2 = cc1;

    cc2[1] = 'a';

    std::cout << cc1 << std::endl;
    std::cout << cc2 << std::endl;

    // The couple of instances above have been copied "as is", it's to say, cc2 is just a shallow copy of cc1.
    // This way, the pointers within the class have been copied without replicating their content. This means
    // that pointers in both instances contain the same memory addresses. Therefore, if any of the strings
    // stored in m_buffer is modified, it will be changed for both instances. What we have used above in
    // "cc2 = cc1" is the default constructor. However, if we were to create a new string (with the same content
    // as the one in the original variable, but pointing at a new memory address), we would have to write a
    // copy constructor, which would perform a "deep copy". Problems may be found when executing the destructor
    // method as well, as the memory address would be freed twice.

    std::cout << std::endl << "Using dummy print string friend function, which creates a copy of the given \"CopyConstructors\" variable." << std::endl;
    DummyPrintString(cc1);
    DummyPrintString(cc2);

    std::cout << std::endl << "Using dummy print string friend function, which takes a reference of the given \"CopyConstructors\" variable." << std::endl;
    SmartPrintString(cc1);
    SmartPrintString(cc2);
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
    TestCopyConstructors();

    return 0;
}

/**************************************/
