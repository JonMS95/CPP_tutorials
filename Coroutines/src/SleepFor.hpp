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

    bool await_ready() const noexcept { return false; } // always suspend
    void await_suspend(std::coroutine_handle<> h) const {
        std::thread([h, d = duration]() {
            std::this_thread::sleep_for(d);
            h.resume();  // resume coroutine after sleep
        }).detach();
    }
    void await_resume() const noexcept {}
};


#endif