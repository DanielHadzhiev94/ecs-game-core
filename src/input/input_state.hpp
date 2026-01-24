#pragma once
#include <array>

#include "input_action.hpp"

namespace engine::input {
    struct InputState {
        std::array<bool, static_cast<size_t>(InputAction::Count)> pressed{};

        bool is_pressed(InputAction action) {
            return pressed[static_cast<size_t>(action)];
        }

        void set_pressed(InputAction action, bool value) {
            pressed[static_cast<size_t>(action)] = value;
        }
    };
}
