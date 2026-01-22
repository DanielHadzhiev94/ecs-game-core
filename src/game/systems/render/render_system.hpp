#pragma once

#include "../../../core/render/IRenderer.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::game::systems {
    class RenderSystem {
    public:
        explicit RenderSystem(render::IRenderer &renderer);

        void render(ecs::Registry &registry, float alpha);

    private:
        render::IRenderer &renderer;
    };
}
