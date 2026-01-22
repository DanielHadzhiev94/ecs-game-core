#pragma once
#include "math/vec2.hpp"

namespace engine::game::components {
    struct Position {
        math::Vec2 current;
        math::Vec2 previous;
    };
}
