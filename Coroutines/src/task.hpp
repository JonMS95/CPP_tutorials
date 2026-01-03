#ifndef TASK_HPP
#define TASK_HPP

/*
The struct below is just some common, well-known boilerplate that's pretty useful when
it comes to using coroutines' co_await concept.
*/

#include <exception>

template<typename T>
struct task {
    struct promise_type {
        T value;
        std::exception_ptr exception;

        task get_return_object() {
            return task{
                std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }

        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }

        void return_value(T v) { value = v; }
        void unhandled_exception() { exception = std::current_exception(); }
    };

    std::coroutine_handle<promise_type> handle;

    explicit task(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~task() { handle.destroy(); }

    T get() {
        if (handle.promise().exception)
            std::rethrow_exception(handle.promise().exception);
        return handle.promise().value;
    }
};

#endif
