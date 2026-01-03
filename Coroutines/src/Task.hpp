#ifndef TASK_HPP
#define TASK_HPP

/*
The struct below is just some common, well-known boilerplate that's pretty useful when
it comes to using coroutines' co_await concept.

Tasks are a concept that represent a procedure to be fulfilled, but that different from
generators, they will solely produce a value upon completion (instead of generating them
on demand).
*/

#include <exception>
#include <coroutine>

template<typename T>
struct task {
    struct promise_type {
        T value;
        std::exception_ptr exception;

        // Return the task object to the caller
        task get_return_object() {
            return task{
                std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }

        // Start immediately (optional: could use suspend_always if you want manual start)
        std::suspend_never initial_suspend() { return {}; }

        // Suspend at the end so the frame is still valid until task is destroyed
        std::suspend_always final_suspend() noexcept { return {}; }

        void return_value(T v) { value = v; }
        void unhandled_exception() { exception = std::current_exception(); }
    };

    std::coroutine_handle<promise_type> handle;

    explicit task(std::coroutine_handle<promise_type> h) : handle(h) {}
    
    ~task() {
        if (handle)
            handle.destroy();
    }

    // Get the result; rethrows exception if one occurred
    T get() {
        if (handle.promise().exception)
            std::rethrow_exception(handle.promise().exception);
        return handle.promise().value;
    }

    // Disable copy, enable move
    task(const task&) = delete;
    task& operator=(const task&) = delete;

    task(task&& other) noexcept : handle(other.handle) {
        other.handle = nullptr;
    }

    task& operator=(task&& other) noexcept {
        if (handle) handle.destroy();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }
};

#endif
