#pragma once

#include "render/IRenderer.hpp"
#include "core/system/interface/i_system_render.hpp"

namespace engine::ecs
{
    class Registry;
}

namespace engine::game::systems::render
{
    class RenderSystem : public engine::core::system::ISystemRender
    {
    public:
        explicit RenderSystem(engine::render::IRenderer &renderer);

        void render(ecs::Registry &registry, float alpha) override;

    private:
        engine::render::IRenderer &renderer;
    };
}
