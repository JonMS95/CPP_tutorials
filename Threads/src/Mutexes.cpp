/********* Include statements *********/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <string>
#include <stdexcept>
#include <shared_mutex>
#include "Mutexes.hpp"

/**************************************/

/*
A thread can be created in C++ using std::thread by passing a callable (function, lambda or functor)
to be executed during threads lifetime.

Calling and using it is way simpler than in pure C: just create a thread by passing the callable +
callable's input parameters.

If the aim is to pass those inputs by references, use std::ref (or std::cref if const references are
wanted).

Functions (or more accurately, callables) should return void. Actually, return types are allowed but
they are ignored so there's no point in returning anything.

So as to make mutex usage safer, lock_guard can be used, ensuring it will be unlocked afterwards.
unique_lock is algo a good choice: it provides safety as well as recursive locks, try-locks and
condition variables.
*/

/********* Define statements **********/



/**************************************/

/********* Using statements ***********/



/**************************************/

/********* Private variables **********/

/**************************************/

/**** Private function prototypes *****/

static void countToNum(const int n = 10000);
static void incrementNTimesUnsafely(unsigned long long& x, const unsigned long long n = 10000);
static void incrementNTimesSafely(unsigned long long& x, const unsigned long long n, std::mutex& m);
static void incrementNTimesWithLockGuard(unsigned long long& x, const unsigned long long n, std::mutex& m);
static void printMessage(const std::string& msg, std::mutex& m);
static void greetWithDoubleMutex(const std::string& msg, std::mutex& m0, std::mutex& m1);
static int  recursiveFibonacci(const int n, std::recursive_mutex& m);
static void tryToGreetWithForGivenTime(const std::string& msg, std::timed_mutex& m, const int seconds);
static void readerTask(const int& x, std::shared_mutex& sm);
static void writerTask(int& x, std::mutex& m);

/**************************************/

/******** Function definitions *********/

static void countToNum(const int n)
{
    int dummy = 0;
    for(int i = 0; i < n; i++)
        ++dummy;
}

static void incrementNTimesUnsafely(unsigned long long& x, const unsigned long long n)
{
    for(unsigned long long i = 0; i < n; i++)
        ++x;
}

// Different from the function above, the referenced variable can only be accessed if provided mutex is acquired beforehand.
static void incrementNTimesSafely(unsigned long long& x, const unsigned long long n, std::mutex& m)
{
    for(unsigned long long i = 0; i < n; i++)
    {
        m.lock();
        ++x;
        m.unlock();
    }
}

// This version uses lock guard. This method unlocks the mutex by itself when exiting the scope.
static void incrementNTimesWithLockGuard(unsigned long long& x, const unsigned long long n, std::mutex& m)
{
    for(unsigned long long i = 0; i < n; i++)
    {
        std::lock_guard<std::mutex> lock(m);
        ++x;
    }
}

// Try-lock tries to acquire target mutex. Using common lock techniques would lead to a deadlock while executing the function below.
static void printMessage(const std::string& msg, std::mutex& m)
{
    // If mutex was successfully acquired, then go ahead and print provided message.
    if(m.try_lock())
    {
        std::cout << msg << std::endl;
        // Take a nap so that other threads trying to acquire provided lock cannot do so.
        std::this_thread::sleep_for(std::chrono::seconds(1));
        m.unlock();
    }
    else
    {
        std::cout << "Could not aquire mutex lock." << std::endl;
    }
}

static void greetWithDoubleMutex(const std::string& msg, std::mutex& m0, std::mutex& m1)
{
    // Lock them simultaneously as the function is entered.
    std::lock(m0, m1);

    // Make lock guards responsible of those mutexes (does not lock them, but makes them unlock later).
    std::lock_guard<std::mutex> lg0(m0, std::adopt_lock);
    std::lock_guard<std::mutex> lg1(m1, std::adopt_lock);

    std::cout << msg << std::endl;
}

static int recursiveFibonacci(const int n, std::recursive_mutex& m)
{
    if(n < 0)
        throw std::invalid_argument("Cannot calculate fibonacci number for negative values");

    if( (!n) || (n == 1) )
        return n;
    
    std::lock_guard<std::recursive_mutex> lock(m);
    return recursiveFibonacci(n - 1, m) + recursiveFibonacci(n - 2, m);
}

static void tryToGreetWithForGivenTime(const std::string& msg, std::timed_mutex& m, const int seconds)
{
    // Tries to lock for a given time span. Alternatively, 
    if(m.try_lock_for(std::chrono::seconds(seconds)))
    {
        std::cout << msg << std::endl;
        
        // Wait for some more time for 
        std::this_thread::sleep_for(std::chrono::seconds(seconds + 1));

        m.unlock();
    }
    else
    {
        std::cout << "Could not acquire mutex, timeout elapsed." << std::endl;
    }
}

// Shared mutexes allow more than a single thread to access restricted code section.
static void readerTask(const int& x, std::shared_mutex& sm)
{
    // Notice how shared mutexes needn't be unlocked afterwards (it does so by itself when exiting current scope).
    std::shared_lock lock(sm);
    std::cout << "Reader sees: " << x << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Mutexes locked as unique lead to code sections to be accesible solely by a single thread. Same as shared locks, they are unlocked by themselves.
static void writerTask(int& x, std::mutex& m)
{
    std::unique_lock lock(m);
    ++x;
    std::cout << "Writer writes: " << x << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void countUntilNumberWithTwoThreads(void)
{
    int n = 1000;
    std::thread t_0(countToNum, n);
    std::thread t_1(countToNum, n);

    t_0.join();
    t_1.join();
}

// Passing a reference or global variables to two different threads may be dangerous since it
// may lead a single memory address to be accessed by those threads simultaneously.
void incrementUnsafelyWithNThreads(const int n)
{
    std::vector<std::thread> vec_th(n);

    unsigned long long x = 0;
    unsigned long long limit = 1000000;

    // Note that all arguments should be provided to the thread.
    for(int i = 0; i < static_cast<int>(vec_th.size()); i++)
        vec_th[i] = std::thread(incrementNTimesUnsafely, std::ref(x), limit);
    
    for(int i = 0; i < static_cast<int>(vec_th.size()); i++)
        vec_th[i].join();

    std::cout << "(" << __func__ << ") after having counted up to " << limit << " " << n << " times, x: " << x << "." << std::endl;
}

void incrementSafelyWithNThreads(const int n)
{
    std::vector<std::thread> vec_th(n);

    unsigned long long x = 0;
    unsigned long long limit = 1000000;
    std::mutex m;
    // Mutex handling is simpler in C++ (it does not need any explicit initialization as in C due to it being a class instance).

    for(int i = 0; i < static_cast<int>(vec_th.size()); i++)
        vec_th[i] = std::thread(incrementNTimesSafely, std::ref(x), limit, std::ref(m));
    
    for(int i = 0; i < static_cast<int>(vec_th.size()); i++)
        vec_th[i].join();

    std::cout << "(" << __func__ << ") after having counted up to " << limit << " " << n << " times, x: " << x << "." << std::endl;
}

void incrementWithLockGuardAndNThreads(const int n)
{
    unsigned long long x = 0;
    unsigned long long limit = 1000000;
    std::mutex m;

    // Cannot do this since it impies copying threads while threads can only be copied.
    // std::vector<std::thread> vec_th(n, std::thread(incrementNTimesWithLockGuard, std::ref(x), limit, std::ref(m)));

    std::vector<std::thread> vec_th(n);
    for(int i = 0; i < static_cast<int>(vec_th.size()); i++)
        vec_th[i] = std::thread(incrementNTimesSafely, std::ref(x), limit, std::ref(m));
    
    for(int i = 0; i < static_cast<int>(vec_th.size()); i++)
        vec_th[i].join();

    std::cout << "(" << __func__ << ") after having counted up to " << limit << " " << n << " times, x: " << x << "." << std::endl;
}

void printMessageFromThreads(void)
{
    std::mutex m;
    std::thread t_0(printMessage, "Hello from t_0!", std::ref(m));
    std::thread t_1(printMessage, "Hello from t_1!", std::ref(m));

    t_0.join();
    t_1.join();
}

void greetWithFromTwoThreads(void)
{
    std::mutex m_0, m_1;

    std::thread t_0(greetWithDoubleMutex, "Greeting from t0", std::ref(m_0), std::ref(m_1));
    std::thread t_1(greetWithDoubleMutex, "Greeting from t1", std::ref(m_0), std::ref(m_1));

    t_0.join();
    t_1.join();
}

void runFibonacciRecursively(const int num_idx)
{
    std::recursive_mutex m;
    std::thread t(recursiveFibonacci, num_idx, std::ref(m));
    t.join();
}

void greetWithTimeout(void)
{
    std::timed_mutex tm;
    
    std::thread t0(tryToGreetWithForGivenTime, "Try to lock from thread t0", std::ref(tm), 1);
    std::thread t1(tryToGreetWithForGivenTime, "Try to lock from thread t1", std::ref(tm), 1);
    
    t0.join();
    t1.join();
}

void readAndWriteMultipleThreads(void)
{
    int x = 0;
    std::shared_mutex sm;
    std::mutex m;
    std::thread t0(readerTask, std::cref(x), std::ref(sm));
    std::thread t1(readerTask, std::cref(x), std::ref(sm));
    std::thread t2(writerTask, std::ref(x), std::ref(m));
    std::thread t3(writerTask, std::ref(x), std::ref(m));
    std::thread t4(readerTask, std::cref(x), std::ref(sm));

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

/**************************************/
