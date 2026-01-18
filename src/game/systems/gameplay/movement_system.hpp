#pragma once
#include "registry/registry.hpp"

class MovementSystem {
public:
    void fixed_update(Registry &registry, float fixed_dt);
};
