#pragma once

#include "math/vec2.hpp"

namespace engine::game::components
{
    struct RigidBody
    {
            math::Vec2 velocity{};
        bool grounded = false;
        bool is_static;
    };
}