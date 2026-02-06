#pragma once
#include "input_state.hpp"

namespace engine::input {
    class IInputDevice {
    public:
        virtual ~IInputDevice() = default;

        virtual void poll(InputState &) = 0;
    };
}
