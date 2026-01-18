#pragma once

#include "registry/registry.hpp"

class RenderSystem {
public:
    static void render(Registry &registry, const Camera &camera, float alpha);
};
