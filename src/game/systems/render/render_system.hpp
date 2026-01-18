#pragma once

#include "IRenderer.hpp"
#include "registry/registry.hpp"

class RenderSystem {
public:
    explicit RenderSystem(IRenderer &renderer);

    void render(Registry &registry, float alpha);

private:
    IRenderer &renderer;
};
