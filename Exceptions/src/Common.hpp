#ifndef COMMON_HPP
#define COMMON_HPP

/********* Include statements *********/

#include <iostream>
#include <stdexcept>

/**************************************/

/********* Define statements *********/

#define MSG_GEN_EXC "Generic exception caught: "
#define MSG_UNK_EXC "Unknown exception caught"

#define SIMPLE_TRY_CATCH_BLOCK(function_call, exception_type)   \
do                                                              \
{                                                               \
    try                                                         \
    {                                                           \
        function_call;                                          \
    }                                                           \
    catch(const exception_type& et)                             \
    {                                                           \
        std::cerr << et.what() << std::endl;                    \
    }                                                           \
    catch(const std::exception& e)                              \
    {                                                           \
        std::cerr << MSG_GEN_EXC << e.what() << std::endl;      \
    }                                                           \
    catch(...)                                                  \
    {                                                           \
        std::cerr << MSG_UNK_EXC << std::endl;                  \
    }                                                           \
}                                                               \
while(0)

/**************************************/

#endif
