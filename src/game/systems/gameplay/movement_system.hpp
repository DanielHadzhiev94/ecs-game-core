#pragma once
#include "registry/registry.hpp"

class MovementSystem {
public:
    static void fixed_update(Registry &registry, float fixed_dt);
};
