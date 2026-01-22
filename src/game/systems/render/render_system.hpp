#pragma once

#include "../../../core/render/IRenderer.hpp"
#include "ecs/registry/registry.hpp"

class RenderSystem {
public:
    explicit RenderSystem(engine::render::IRenderer &renderer);

    void render(engine::ecs::Registry &registry, float alpha);

private:
    engine::render::IRenderer &renderer;
};
