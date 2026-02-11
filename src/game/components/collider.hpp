#pragma once

#include "math/vec2.hpp"

namespace engine::game::components
{
    struct Collider
    {
        engine::math::Vec2 half_extends;
    };
}