/********* Include statements *********/

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>

/**************************************/

/*
Disclaimer: if not having gone through lesson about futures and promises yet, it's strongly recommended
doing so as concepts explained in such chapter may be required so as to have a better understanding.

std::async is a very high-level mechanism to run a function asynchronously and get an std::future back.
Unlike std::thread, there's no need to manually deal with joins, stop tokens, lifetime management and
so on. Instead, std::async manages it for you. In fact, three of the main manually managed threads are
solved automatically:
·Result retrieval: the function to be executed directly retrieves a value, which the caller can get by
simply calling future.get().
·Exceptions are preserved: if the async task throws, then the exception is rethrown when calling
future.get().
·Automatic thread cleanup: you never call .join(), as the future handles it when destroyed.

Common usage example syntax:
Launch thread with:
auto fut = std::async(std::launch::async, targetFunction, input_parameter);
This will start a new thread running immediately on the background, then it will give you an
std::future<T> object, being T targetFunction's return type.

Retrieve value as follows:
auto result = fut.get();
*/

/**** Private function prototypes *****/

static int computeSquare(const int x);
static void oddCharsToUppercase(std::string& s);
static void asyncWithReference(std::string& s);

/**************************************/

/******** Function definitions *********/

static int computeSquare(const int x)
{
    std::cout << "Calculating " << x <<"'s square (thread id: " << std::this_thread::get_id() << ")." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return (x * x);
}

static void oddCharsToUppercase(std::string& s)
{
    if(!s.size())
        throw std::length_error("Provided string's length cannot be zero.");

    for(int i = 0; i < static_cast<int>(s.size()); i += 2)
        if(isalpha(s[i]))
            s[i] = toupper(s[i]);
}

static void asyncWithReference(std::string& s)
{
    std::cout << "Turn odd-indexed characters within a string uppercase (target string: \"" << s << "\")." << std::endl;

    std::future<void> fut = std::async(std::launch::async, oddCharsToUppercase, std::ref(s));

    try
    {
        fut.get();

        std::cout << "Modified string: \"" << s << "\"." << std::endl;
    }
    catch(const std::length_error& le)
    {
        std::cerr << "Length error exception caught: " << le.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Generic exception caught: " << e.what() << std::endl;
    }
}

void asyncExample(void)
{
    std::cout << "Before calling async from main thread (thread id: " << std::this_thread::get_id() << ")." << std::endl;

    int number = 12;

    auto future_result = std::async(std::launch::async, computeSquare, number);
    
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "After async thread's launch from main thread (thread id: " << std::this_thread::get_id() << ")." << std::endl;

    int result = future_result.get();

    std::cout << number << " ^ 2 = " << result << std::endl;
}

void asyncExampleWithManyNumbers(void)
{
    std::cout << "Calculating many squares from main thread (thread id: " << std::this_thread::get_id() << ")." << std::endl;

    const int number_of_squares = 10;

    std::vector<std::future<int>> futures(number_of_squares);

    for(int i = 1; i <= number_of_squares; i++)
        futures[i - 1] = std::async(std::launch::async, computeSquare, i);
    
    // Wait for all threads to come to an end.
    for(int i = 1; i <= number_of_squares; i++)
        futures[i - 1].wait();

    // For each future, check whether it's valid and print it's retrievable value if so.
    for(int i = 1; i <= number_of_squares; i++)
        if(futures[i - 1].valid())
            std::cout << i << " ^ 2 = " << futures[i - 1].get() << std::endl;
}

void asyncExampleWithReference(void)
{
    std::string test_string = "The quick brown fox jumps over the lazy dog.";
    
    asyncWithReference(test_string);
}

void asyncExampleWithException(void)
{
    std::string empty_string = "";

    asyncWithReference(empty_string);
}

/**************************************/
