/********* Include statements *********/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

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

/**************************************/

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

/**************************************/
