#pragma once

#include "math/vec2.hpp"

namespace engine::game::components {
    struct Camera {
        math::Vec2 previous;
        math::Vec2 current;
    };
}
