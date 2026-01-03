#ifndef SLEEP_FOR_HPP
#define SLEEP_FOR_HPP

/*
This file contains a simple implementation for an awaitable type, which complies with
the well known awaitable interface (await_ready, await_suspend, await_resume).
*/

#include <chrono>
#include <coroutine>
#include <thread>

struct SleepFor {
    std::chrono::milliseconds duration;

    bool await_ready() const noexcept { return false; }
    void await_suspend(std::coroutine_handle<> h) const {
        std::this_thread::sleep_for(duration);
        h.resume();
    }
    void await_resume() const noexcept {}
};


#endif