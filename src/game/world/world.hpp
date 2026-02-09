#pragma once

#include "game/systems/render/render_system.hpp"
#include "ecs/registry/registry.hpp"
#include "core/system/system_manager.hpp"

namespace engine::game
{
    class World
    {
    public:
        explicit World(ecs::Registry &registry, engine::render::IRenderer &renderer);

        void tick(float dt);

    private:
        ecs::Registry &registry;

        systems::render::RenderSystem render_system;
        core::system::SystemManager system_manager;

        float accumulator = 0.0f;

        void render(float alpha);
    };
}
