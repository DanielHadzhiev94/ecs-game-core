#pragma once
#include <cstdint>

namespace engine::game::input
{
    enum class InputAction : std::uint8_t
    {
        MoveLeft,
        MoveRight,
        Jump,
        Count
    };
}
