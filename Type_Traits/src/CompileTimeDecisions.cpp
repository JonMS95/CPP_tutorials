/********* Include statements *********/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "CompileTimeDecisions.hpp"

/**************************************/

/********* Define statements **********/

#define TRY_GET_VECTOR_OP_BASE(vec_var, fn) \
do                                          \
{                                           \
    try                                     \
    {                                       \
        std::cout << #fn << "(" <<          \
        #vec_var << ") = " <<               \
        fn(vec_var) << std::endl;           \
    }                                       \
    catch(const std::exception& e)          \
    {                                       \
        std::cerr << e.what() << std::endl; \
    }                                       \
}while(0)

#define TRY_GET_VECTOR_SUM(vec_var) TRY_GET_VECTOR_OP_BASE(vec_var, getVectorSum)
#define TRY_GET_VECTOR_AVG(vec_var) TRY_GET_VECTOR_OP_BASE(vec_var, getVectorAverage)

/**************************************/

/********* Using statements ***********/

using vec_int = std::vector<int>;
using vec_str = std::vector<std::string>;

/**************************************/

/********* Private variables **********/

vec_int v_i = {1, 4, 7, 2, 8, 6, 3};
vec_str v_s = {"Hello", "Hallo", "Hola", "Kaixo"};

/**************************************/

/******** Function definitions *********/

void testVectorSum(void)
{
    TRY_GET_VECTOR_SUM(v_i);
    TRY_GET_VECTOR_SUM(v_s);
}

void testVectorAvg(void)
{
    TRY_GET_VECTOR_AVG(v_i);
    // TRY_GET_VECTOR_AVG(v_s);
    // If the line above is uncommented, then the program will not compile since std::string
    // is not an arithmetic type.
}

/**************************************/
