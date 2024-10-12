#include "BasicLambdaFunctions.hpp"

void basicLambdaFunctions(void)
{
/*
    Lambda functions are anonymous inline functions, it's to say , they are a special function type that needs no separated function declaration.
    They allow developers to capture variables from the surrounding scope, making them useful for short operations, such as callbacks.
    These functions are commonly used alongside standard library algorithms such as std::sort or std::for_each.

    Lambda functions are built by using the following syntax:
    
    [capture](parameters) -> return_type
    {
        function_body
    }
    
    Where:
        ·"capture" stands for any variables found within the surrounding scope will be accesible inside the lambda function.
        ·"parameters" are the input parameters for the lambda functions, same as in a common function declaration.
        ·"return_type" is the variable type that is meant to be returned. If omitted, the compiler will deduce it.
        ·"function_body" contains the code defining what the lambda function does, again, same as in a common function definition.

    Lambdas can also be assigned to an std::function type object, though it's strongly recommendable to use "auto" keyword.

    Let's see an example, by defining a lambda function that takes two numbers and returns the sum of them:
    */

    int a = 7;
    int b = 3;

    auto sum = [](int a, int b) -> int
    {
        return a + b;
    };

    // Let's see another example, now capturing a surrounding scope variable:
    auto mult_a_by_two = [a]()
    {
        return a * 2;
    };
    // Note that the example function above does not even tell the return variable type.

    // Lambda functions do allow also capturing variables by reference:
    auto div_b_by_two = [b](void) -> int
    {
        return b / 2;
    };

    // All variables found within the scope can be passed to the lambda functions by using "=":
    auto sum_a_b = [=]()
    {
        return a + b;
    };

    // Passing every variable as a reference instead of the variables "as is" is allowed as well by using "&":
    auto subtract_b_from_a = [&]
    {
        a -= b;
    };
    // Note as well that the lambda funcition allow does not even include opening and closing parentheses usually surrounding input parameters.

    // Note that different from common function declarations, lambda functions allow specifying input parameters by using "auto" keyword.
    auto get_str = [](auto a)
    {
        return std::to_string(a);
    };

    auto print_text = [](std::string text)
    {
        std::cout << text << std::endl;
    };

    // Lambda functions can call others, although it's necessary to include them in the variables-to-capture list beforehand.
    auto print_sum = [sum, print_text](int a, int b, std::string text) -> void
    {
        print_text(text + std::to_string(sum(a, b)));
    };

    print_text("a = " + std::to_string(a) + ", b = " + std::to_string(b));
    print_text(get_str(a) + " + " + get_str(b) + " = " + get_str(sum(a, b)));
    print_text(get_str(a) + " * 2 = " + get_str(mult_a_by_two()));
    print_text(get_str(b) + " / 2 = " + get_str(div_b_by_two()));
    print_text(get_str(a) + " + " + get_str(b) + " = " + get_str(sum_a_b()));
    subtract_b_from_a();
    print_text("After a -= b, a = " + get_str(a));
    print_sum(a, b, "This is a sum:");
}