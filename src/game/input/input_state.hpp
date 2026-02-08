#pragma once
#include <array>

#include "input_action.hpp"

namespace engine::game::input
{
    struct InputState
    {
        bool is_pressed(InputAction action) const
        {
            return pressed[static_cast<size_t>(action)];
        }

        void set_pressed(InputAction action, bool value)
        {
            pressed[static_cast<size_t>(action)] = value;
        }

    private:
        std::array<bool, static_cast<size_t>(InputAction::Count)> pressed{};
    };
}
