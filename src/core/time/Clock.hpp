#pragma once

#include <chrono>

namespace engine::time {
    class Clock {
    public:
        float restart();

        void set_initial_frame();

    private:
        std::chrono::steady_clock::time_point last_frame;
    };
}
