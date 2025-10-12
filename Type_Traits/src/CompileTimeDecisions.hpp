#ifndef COMPILE_TIME_DECISIONS_HPP
#define COMPILE_TIME_DECISIONS_HPP

/********* Include statements *********/

#include <stdexcept>
#include <vector>
#include <type_traits>

/**************************************/

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
