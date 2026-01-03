/********* Include statements *********/

#include <iostream>
#include <coroutine>
#include "AsyncTasks.hpp"
#include "task.hpp"

/**************************************/

/*
Before starting, let's make a recap about yield, return and await in the context of coroutines:
·co_yield: pauses coroutine's execution, holding its state and returning a value at a time.
·co_return: ends coroutine's execution forcefully.
·co_await: waits for an event to happen out of the coroutine's context.

It's worth pointing out that a coroutine does not generate nor provide anything when calling
co_await, but wait for something to happen externally. After co_await, any "awaitable"
expression can exist.

An awaitable is something that the compiler knows how to suspend and resume with. Now the
question arises naturally: what can (or cannot) be "co_await-ed"? Well, it should be something
that implements the "awaitable interface":
·await_ready(): returns true (go ahead) or false (suspend).
·await_suspend(coroutine_handle): calle if await_ready was false. Can schedule when the
coroutine resumes.
·await_resume(): provides the value returned by co_await or throws if an execption turned up.

Similar to generators, there is a code concept that's used alongside co_await: tasks. In the
same fashion, there's a structure that should be created for such purpose (task.hpp).

However, there are differences between generators and tasks: while generators are meant to
represent a series of values generated on demand, tasks will only provide output values upon
completion.
*/

/******** Function definitions *********/

namespace async_coroutines
{

static task<int> dummyTask(void)
{
    co_return 1;
}

void dummyTaskCaller(void)
{
    auto d = dummyTask();
    
    std::cout << d.get() << std::endl;
}

}

/**************************************/
