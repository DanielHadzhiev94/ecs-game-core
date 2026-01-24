#pragma once
#include <cstdint>
#include <unordered_map>
#include "input_action.hpp"

namespace engine::input {
    using KeyCode = std::uint32_t;

    class InputContext {
    public:
        void bind(InputAction action, KeyCode key_code);

        KeyCode key_for(InputAction action) const;

    private:
        std::unordered_map<InputAction, KeyCode> bindings;
    };
}
