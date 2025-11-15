#ifndef MUTEXES_HPP
#define MUTEXES_HPP

/******** Function prototypes *********/

void countUntilNumberWithTwoThreads(void);
void incrementUnsafelyWithNThreads(const int n = 2);
void incrementSafelyWithNThreads(const int n = 2);
void incrementWithLockGuardAndNThreads(const int n = 2);
void printMessageFromThreads(void);
void greetWithFromTwoThreads(void);
void runFibonacciRecursively(const int num_idx = 10);

/**************************************/

#endif