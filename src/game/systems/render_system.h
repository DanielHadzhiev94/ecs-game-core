#pragma once

#include "registry/registry.h"
#include "camera_system.h"

class RenderSystem {
public:
    static void render(Registry &registry, const Camera &camera, float alpha);
};
