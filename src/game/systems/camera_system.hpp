#pragma once

#include "registry/registry.h"
#include "../components/camera.hpp"

class CameraSystem {
public:
    static void fixed_update(Registry &registry, Camera &camera);
};
