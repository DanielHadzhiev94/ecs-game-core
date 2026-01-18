#pragma once

#include "registry/registry.hpp"

class CameraSystem {
public:
    void fixed_update(Registry &registry, float fixed_dt);
};
