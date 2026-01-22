#pragma once

#include "ecs/registry/registry.hpp"

class CameraSystem {
public:
    void fixed_update(engine::ecs::Registry &registry, float fixed_dt);
};
