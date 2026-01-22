#pragma once

#include "math/vec2.hpp"

struct Camera {
    engine::math::Vec2 previous;
    engine::math::Vec2 current;
};
