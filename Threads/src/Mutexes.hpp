#ifndef MUTEXES_HPP
#define MUTEXES_HPP

/******** Function prototypes *********/

void countUntilNumberWithTwoThreads(void);
void incrementUnsafelyWithTwoThreads(const int n = 2);
void incrementSafelyWithTwoThreads(const int n = 2);

/**************************************/

#endif