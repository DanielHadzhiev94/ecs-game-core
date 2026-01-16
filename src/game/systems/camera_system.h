#pragma once

#include "registry/registry.h"
#include "../components/camera.h"

class CameraSystem {
public:
    static void fixed_update(Registry &registry, Camera &camera);
};
