/********* Include statements *********/

#include <iostream>
#include <string>
#include <type_traits>

/**************************************/

// Type traits is a module that is pretty useful in those situations in which types have to be compared or the behaviour of 
// the program should depend on the type of a variable. Type familys can be compared, same as variable types against either
// built-in or custom types.
//
// All of this comparisons return values during compile time (they are qualified as constexpr). This concept will show up
// on the following lessons. For instance, it may be useful if the aim is to execute a template function differently
// depending on the input type.

/********* Define statements *********/

#define TYPE_SECTION_SEPARATOR "---------------------------------"

#define COMP_CHECK_TYPE(type)                               \
std::cout << TYPE_SECTION_SEPARATOR << std::endl <<         \
"Checking against " << #type << " type." << std::endl <<    \
TYPE_SECTION_SEPARATOR << std::endl

#define COMP_MACRO_BASE(type_A, type_B, op, txt_A)                  \
std::cout <<"Is "<< #type_A << txt_A << " equal to " << #type_B <<  \
" ? " << op << std::endl

#define COMP_FAMILY_TYPES(type_A, type_B, comp_fn)  COMP_MACRO_BASE(type_A, type_B, comp_fn<type_A>::value, "")
#define COMP_TYPES(type_A, type_B, comp_fn)         COMP_MACRO_BASE(type_A, type_B, (comp_fn<type_A, type_B>::value), " variable type")

/**************************************/

/***** Private function prototypes ****/

/**************************************/

/******** Function definitions *********/

void demoBasicTypeTraits(void)
{
    // Print true/false instead of 1/0.
    std::cout << std::boolalpha;

    // Some dummy variables and type definitions to be used later.
    int var_int = 1;
    int var_float = 1.1f;
    
    class myClass{};
    typedef struct{} myStruct;
    enum myEnum { A, B, C };
    union myUnion {int i; float f; };

    // Check integral types. std::is_integral will return true for all types in C++ that represent whole integer types.
    {
        COMP_CHECK_TYPE(integral);

        COMP_FAMILY_TYPES(int,                  integral, std::is_integral);
        COMP_FAMILY_TYPES(char,                 integral, std::is_integral);
        COMP_FAMILY_TYPES(double,               integral, std::is_integral);
        COMP_FAMILY_TYPES(std::string,          integral, std::is_integral);
        COMP_FAMILY_TYPES(decltype(var_int),    integral, std::is_integral);
        COMP_FAMILY_TYPES(decltype(var_float),  integral, std::is_integral);
    }
    // Check floating-point types. std::is_floating_point will return true for all types in C++ that represent floating-point numbers.
    {
        COMP_CHECK_TYPE(floating-point);

        COMP_FAMILY_TYPES(float,                floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(double,               floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(int,                  floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(std::string,          floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(decltype(var_int),    integral,       std::is_floating_point);
        COMP_FAMILY_TYPES(decltype(var_float),  integral,       std::is_floating_point);        
    }
    // It can also be checked whether a given variable is a pointer or not, regardless of the pointed variable's type. Use std::is_pointer.
    {
        COMP_CHECK_TYPE(pointer);

        COMP_FAMILY_TYPES(int*, int-pointer, std::is_pointer);
        COMP_FAMILY_TYPES(int,  int-pointer, std::is_pointer);
    }
    // Exact types can be checked as well: std::is_same<T, U>::value. Since C++17, std::is_same_v<T, U> can be used so as to avoid ::value field retrieval.
    // Use decltype alongside the variable in question to retrieve its type.
    {
        COMP_CHECK_TYPE(int);

        myClass dummy_class;
        myStruct dummy_struct;
        
        COMP_TYPES(decltype(var_int),       int,        std::is_same);
        COMP_TYPES(decltype(var_float),     int,        std::is_same);
        COMP_TYPES(decltype(dummy_class),   myClass,    std::is_same);
        COMP_TYPES(decltype(dummy_class),   myStruct,   std::is_same);
    }
}

/**************************************/
