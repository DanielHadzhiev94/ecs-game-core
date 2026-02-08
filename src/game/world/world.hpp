#pragma once

#include "../systems/render/render_system.hpp"
#include "ecs/registry/registry.hpp"
#include "manager/system_manager.hpp"
namespace engine::game
{
    class World
    {
    public:
        explicit World(ecs::Registry &registry, render::IRenderer &renderer);

        void tick(float dt);

    private:
        ecs::Registry registry;

        systems::RenderSystem render_system;
        core::manager::SystemManager system_manager;

        float accumulator = 0.0f;

        void render(float alpha);
    };
}
