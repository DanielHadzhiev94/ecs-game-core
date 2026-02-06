#pragma once
#include <cstdint>

namespace engine::input {
    enum class InputAction : std::uint8_t {
        MoveLeft,
        MoveRight,
        Jump,
        Count
    };
}
