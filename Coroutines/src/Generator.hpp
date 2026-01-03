#ifndef GENERATOR_HPP
#define GENERATOR_HPP

/*
Although many modern libraries (cppcoro, or the ones included in latest C++ versions) do include generators,
we have chosen to use the one in the current file. We have not come up with it, it's a well-known example that
can be easily found on the internet.
*/

#include <coroutine>
#include <optional>

template<typename T>
struct generator {
    struct promise_type {
        T value;
        std::suspend_always yield_value(T v) {
            value = v;
            return {};
        }
        generator get_return_object() { return generator{ std::coroutine_handle<promise_type>::from_promise(*this) }; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    std::coroutine_handle<promise_type> handle;

    generator(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~generator() { if (handle) handle.destroy(); }

    struct iterator {
        std::coroutine_handle<promise_type> h;
        bool done;

        iterator(std::coroutine_handle<promise_type> h_) : h(h_), done(!h || h.done()) {}
        iterator& operator++() { h.resume(); done = h.done(); return *this; }
        T operator*() const { return h.promise().value; }
        bool operator!=(const iterator& other) const { return done != other.done; }
    };

    iterator begin() { handle.resume(); return iterator{handle}; }
    iterator end() { return iterator{nullptr}; }
};

#endif
