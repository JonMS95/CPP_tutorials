/********* Include statements *********/

#include <iostream>
#include "BasicThreads.hpp"
#include "Mutexes.hpp"
#include "Atomic.hpp"
#include "ConditionVariables.hpp"
#include "Semaphores.hpp"
#include "Latches.hpp"
#include "Barriers.hpp"
#include "JThreads.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_BASIC_THREADS  "Testing basic threads."
#define MSG_TEST_MUTEXES        "Testing mutexes."
#define MSG_TEST_ATOMIC         "Testing atomic variables."
#define MSG_TEST_CONDITIONS     "Testing conditions."
#define MSG_TEST_SEMAPHORES     "Testing semaphores."
#define MSG_TEST_LATCHES        "Testing latches."
#define MSG_TEST_BARRIERS       "Testing barriers."
#define MSG_TEST_JTHREADS       "Testing JThreads."

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestSimpleThreads(void)
{
    PrintTestHeader(MSG_TEST_BASIC_THREADS);

    simpleThreadCreation();
    threadsWithReferences();
    detachedThreads();
}

static void TestMutexes(void)
{
    PrintTestHeader(MSG_TEST_MUTEXES);

    countUntilNumberWithTwoThreads();
    incrementUnsafelyWithNThreads();
    incrementSafelyWithNThreads();
    incrementWithLockGuardAndNThreads();
    printMessageFromThreads();
    greetWithFromTwoThreads();
    runFibonacciRecursively();
    greetWithTimeout();
    readAndWriteMultipleThreads();
}

static void TestAtomic(void)
{
    PrintTestHeader(MSG_TEST_ATOMIC);

    incrementAtomicWithNThreads();
}

static void TestConditions(void)
{
    PrintTestHeader(MSG_TEST_CONDITIONS);

    conditionConsumerProducerExample();
}

static void TestSemaphores(void)
{
    PrintTestHeader(MSG_TEST_SEMAPHORES);

    accessLimitedresources();
}

static void TestLatches(void)
{
    PrintTestHeader(MSG_TEST_LATCHES);

    syncThreadsWithCheckpoint();
}

static void TestBarriers(void)
{
    PrintTestHeader(MSG_TEST_BARRIERS);

    syncThreadsInLoop();
}

static void TestJThreads(void)
{
    PrintTestHeader(MSG_TEST_JTHREADS);

    incrementCounterWithTwoJThreads();
}

int main()
{
    TestSimpleThreads();
    TestMutexes();
    TestAtomic();
    TestConditions();
    TestSemaphores();
    TestLatches();
    TestBarriers();
    TestJThreads();

    return 0;
}

/**************************************/
