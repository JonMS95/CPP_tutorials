/********* Include statements *********/

#include <iostream>
#include <string>
#include <type_traits>

/**************************************/

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

    // Check integral types. std::is_integral will return true for all types in C++ that represent whole integer types.
    {
        COMP_CHECK_TYPE(integral);
        COMP_FAMILY_TYPES(int,         integral, std::is_integral);
        COMP_FAMILY_TYPES(char,        integral, std::is_integral);
        COMP_FAMILY_TYPES(double,      integral, std::is_integral);
        COMP_FAMILY_TYPES(std::string, integral, std::is_integral);
        int var_int = 1;
        int var_float = 1.1f;
        COMP_FAMILY_TYPES(decltype(var_int),   integral, std::is_integral);
        COMP_FAMILY_TYPES(decltype(var_float), integral, std::is_integral);
    }
    // Check floating-point types. std::is_floating_point will return true for all types in C++ that represent floating-point numbers.
    {
        COMP_CHECK_TYPE(floating-point);
        COMP_FAMILY_TYPES(float, floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(double, floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(int, floating-point, std::is_floating_point);
        COMP_FAMILY_TYPES(std::string, floating-point, std::is_floating_point);
        int var_int = 1;
        int var_float = 1.1f;
        COMP_FAMILY_TYPES(decltype(var_int),   integral, std::is_floating_point);
        COMP_FAMILY_TYPES(decltype(var_float), integral, std::is_floating_point);
    }
    // It can also be checked whether a given variable is a pointer or not, regardless of the pointed variable's type. Use std::is_pointer.
    {
        COMP_CHECK_TYPE(pointer);
        COMP_FAMILY_TYPES(int*, int-pointer, std::is_pointer);
        COMP_FAMILY_TYPES(int, int-pointer, std::is_pointer);
    }
    // Exact types can be checked as well: std::is_same<T, U>::value. Since C++17, std::is_same_v<T, U> can be used so as to avoid ::value field retrieval.
    {
        COMP_CHECK_TYPE(int);
        int var_int = 1;
        int var_float = 1.1f;
        COMP_TYPES(decltype(var_int), int, std::is_same);
        COMP_TYPES(decltype(var_int), float, std::is_same);
    }
}

/**************************************/
