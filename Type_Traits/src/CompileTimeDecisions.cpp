/********* Include statements *********/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "CompileTimeDecisions.hpp"

/**************************************/

/********* Define statements **********/

#define TRY_GET_VECTOR_SUM(vec_var)         \
do                                          \
{                                           \
    try                                     \
    {                                       \
        std::cout << "getVectorSum(" <<     \
        #vec_var << ") = " <<               \
        getVectorSum(vec_var) << std::endl; \
    }                                       \
    catch(const std::exception& e)          \
    {                                       \
        std::cerr << e.what() << std::endl; \
    }                                       \
}while(0)

/**************************************/

/********* Using statements ***********/

using vec_int = std::vector<int>;
using vec_str = std::vector<std::string>;

/**************************************/

/***** Private function prototypes ****/

/**************************************/

/******** Function definitions *********/

void testVectorSum(void)
{
    vec_int v_i = {1, 4, 7, 2, 8, 6, 3};
    vec_str v_s = {"Hello", "Hallo", "Hola", "Kaixo"};

    TRY_GET_VECTOR_SUM(v_i);
    TRY_GET_VECTOR_SUM(v_s);
}

/**************************************/
