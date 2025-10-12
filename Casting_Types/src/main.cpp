/********* Include statements *********/

#include <iostream>
#include "CastingTypesBaseClass.hpp"
#include "CastingTypesDerivedClass.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER            "*********************************"
#define MSG_TEST_STATIC_CAST       "Testing static casting."
#define MSG_TEST_DYNAMIC_CAST      "Testing dynamic casting."
#define MSG_TEST_CONST_CAST        "Testing const casting."
#define MSG_TEST_REINTERPRET_CAST  "Testing reinterpret casting."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

/*
Static cast is arguably the safest type of C++ casting. It checks cast's suitability during compilation time.
It is strongly recommended when casting between basic types (such as casting an integer to a float or vice versa)
as well as pointer to those basic types.
Casting from a custom class to other is also allowed, although it's not recommended for downcasting (but it is
for upcasting). The reason for this is that upcasting is always safe since the existence of a base class pointer
is guaranteed by nature. Dyanumc casting should be used for downcasting.
*/

void TestStaticCast(void)
{
    PrintTestHeader(MSG_TEST_STATIC_CAST);

    float f = 1.5f;
    int i   = static_cast<int>(f);

    std::cout << "float f = " << f << ",\tint i = static_cast<int>(f) = " << i << std::endl;

    double d    = 3.3;
    long l      = static_cast<long>(d);

    std::cout << "double d = " << d << ",\tlong l = static_cast<long>(l) = " << l << std::endl;

    CastingTypesDerivedClass ctdc(10);

    std::cout << "ctdc.getCounter() = " << ctdc.getCounter() << std::endl;

    CastingTypesBaseClass* ctbc = static_cast<CastingTypesBaseClass*>(&ctdc);

    std::cout << "ctdc.getCounter() = " << ctdc.getCounter() << std::endl;
    std::cout << "ctbc->getCounter() = " << ctbc->getCounter() << std::endl;
}

/*
As stated before, dynamic_cast is strongly recommended for downcasting when trying to perform a cast between
different types of classes within the same hierarchy. It checks whether the cast is suitable or not during
runtime, returning nullptr is casting fails.
Note that the pointer to be casted should exist: dynamic_cast<Target_Class*>(&base_class_obj) won't work since
a casting to the address will be tried to be performed.
*/

void TestDynamicCast(void)
{
    PrintTestHeader(MSG_TEST_DYNAMIC_CAST);

    CastingTypesDerivedClass ctdc(25);
    CastingTypesDerivedClass* ptr_ctdc = &ctdc;
    CastingTypesBaseClass* ptr_ctbc = dynamic_cast<CastingTypesBaseClass*>(ptr_ctbc);

    std::cout << "ptr_ctdc->getCounter() = " << ptr_ctdc->getCounter() << std::endl;
    std::cout << "ptr_ctbc->getCounter() = " << ptr_ctbc->getCounter() << std::endl;
}

/*
Const cast is used to add or remove const / volatile qualifiers. It's considered to be dangerous by nature.
Note that this will not work if passing explicit variables. Use always references or pointer at least on
destination side. This cast type may cause undefined behaviours or runtime crashes if source and destination
types are the same.
*/

void TestConstCast(void)
{
    PrintTestHeader(MSG_TEST_CONST_CAST);

    const int a = 1;
    int& b = const_cast<int&>(a);

    int c_var = 1;
    int* c = &c_var;
    const int* d = const_cast<const int*>(c);

    std::cout << "const int a = " << a << std::endl;
    std::cout << "int& b = const_cast<int&>(a) = " << b << std::endl;

    std::cout << "int* c -> " << *c << std::endl;
    std::cout << "const int* d = const_cast<const int*>(c) = " << *d << std::endl;
}

/*
Reinterpret cast just it's a raw type of casting. In this type of casting, the bits of the variable
in question are nor reorganized nor analyzed at all. Instead, the bits of the target variable should
be interpreted as the new type of variable. For instance, if a pointer to an integer conatins the
address in which a variable is stored, then reinterpret cast will simply make the destination variable
store the same bits but interpreting them as an integer "as is".
Beware of the variable sizes. If destination variable type size does not match source's (or it's
smaller), the code may not compile at all.
*/

void TestReinterpretCast(void)
{
    PrintTestHeader(MSG_TEST_REINTERPRET_CAST);

    std::unique_ptr<int> ptr_a = std::make_unique<int>(1);
    size_t a = reinterpret_cast<size_t>(ptr_a.get());

    std::cout << "int a = reinterpret_cast<int>(ptr_a.get()) = " << a << std::endl;
}

/*
C-style cast may be used as well, but it's not recommended. It's not dangerous by nature, it's 
just that safer options exist in C++. Ordered by descending safety:
·static_cast (safest)
·dynamic_cast (safe but slower)
·const_cast (potentially dangerous)
·reinterpret_cast (just reinterprets raw bits as another type)
·C-style cast (hiddes the aim, use only if you know the platform)
*/

int main()
{
    TestStaticCast();
    TestDynamicCast();
    TestConstCast();
    TestReinterpretCast();

    return 0;
}

/**************************************/
