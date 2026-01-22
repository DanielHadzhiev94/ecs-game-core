#pragma once

#include "../systems/gameplay/lifetime_system.hpp"
#include "../systems/gameplay/movement_system.hpp"
#include "../systems/camera/camera_system.hpp"
#include "../systems/render/render_system.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::game {
    class World {
    public:
        explicit World(ecs::Registry &registry, render::IRenderer &renderer);

        void tick(float dt);

    private:
        ecs::Registry registry;

        systems::RenderSystem render_system;
        systems::CameraSystem camera_system;
        systems::MovementSystem movement_system;
        systems::LifetimeSystem lifetime_system;

        float accumulator = 0.0f;

        void fixed_update(float fixed_dt);

        void update(float dt);

        void render(float alpha);
    };
}
