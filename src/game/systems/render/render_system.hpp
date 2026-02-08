#pragma once

#include "render/IRenderer.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::game::systems::render
{
    class RenderSystem
    {
    public:
        explicit RenderSystem(engine::render::IRenderer &renderer);

        void render(ecs::Registry &registry, float alpha);

    private:
        engine::render::IRenderer &renderer;
    };
}
