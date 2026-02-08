#include "clock.hpp"

using namespace std::chrono;

namespace engine::time
{
    float Clock::restart()
    {
        auto current_frame = steady_clock::now();
        auto delta = current_frame - last_frame;

        last_frame = current_frame;

        return duration_cast<duration<float>>(delta).count();
    }

    void Clock::set_initial_frame()
    {
        last_frame = steady_clock::now();
    }
}
