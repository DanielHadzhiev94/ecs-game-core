#pragma once

#include "math/vec2.hpp"

namespace engine::game::components
{
    struct RigidBody
    {
        engine::math::Vec2 velocity{};
        bool grounded = false;
        bool is_static;
    };
}