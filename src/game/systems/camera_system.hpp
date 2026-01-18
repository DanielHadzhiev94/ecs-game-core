#pragma once

#include "registry/registry.hpp"
#include "../components/camera.hpp"

class CameraSystem {
public:
    void fixed_update(Registry &registry, Camera &camera);
};
