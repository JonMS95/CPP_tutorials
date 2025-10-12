#ifndef COMPILE_TIME_DECISIONS_HPP
#define COMPILE_TIME_DECISIONS_HPP

/********* Include statements *********/

#include <stdexcept>
#include <vector>
#include <type_traits>

/**************************************/

// When using templates, it may happen that no function overloading is required since many input types are compatible.
// However, it may also occur that some of the types are not compatible with the operation in question. In such cases,
// we may want to throw an exception, exit the function or whatever.
//
// As mentioned in the basic type traits tutorial, all of these type traits operations are performed during compile-time
// (they are marked as constexpr). This way, multiple branches may exist on different function instances depending on
// the input variable type it's being called with.

/***** Extended class definitions *****/

class InvalidTypeException : public std::invalid_argument
{
private:
    const std::string message;

public:
    InvalidTypeException(const std::string& msg):
        std::invalid_argument(""), message(msg) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

/**************************************/

/******** Function prototypes *********/

void testVectorSum(void);

/**************************************/

/******** Function templates **********/

template <typename T>
T getVectorSum(std::vector<T>& vec)
{
    if constexpr (!std::is_integral_v<T> && !std::is_floating_point_v<T>)
        throw InvalidTypeException("Can only get vector sum for integral or floating-point types");

    T ret = 0;

    for(T v : vec)
        ret += v;
    
    return ret;
}

/**************************************/

#endif
