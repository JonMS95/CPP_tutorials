/********* Include statements *********/

#include "AsyncCoroutines.hpp"

/**************************************/

/*
Before starting, let's make a recap about yield, return and await in the context of coroutines:
·co_yield: pauses coroutine's execution, holding its state and returning a value at a time.
·co_return: ends coroutine's execution forcefully.
·co_await: waits for an event to happen out of the coroutine's context.

It's worth pointing out that a coroutine does not generate nor provide anything when calling
co_await, but wait for something to happen externally.
*/

/******** Function definitions *********/

namespace async_coroutines
{



}

/**************************************/
