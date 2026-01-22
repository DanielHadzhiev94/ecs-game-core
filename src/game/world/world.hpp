#pragma once

#include "../systems/gameplay/lifetime_system.hpp"
#include "../systems/gameplay/movement_system.hpp"
#include "../systems/camera/camera_system.hpp"
#include "../systems/render/render_system.hpp"
#include "ecs/registry/registry.hpp"

class World {
public:
    explicit World(engine::ecs::Registry &registry, engine::render::IRenderer &renderer);

    void tick(float dt);

private:
    engine::ecs::Registry registry;

    RenderSystem render_system;
    CameraSystem camera_system;
    MovementSystem movement_system;
    LifetimeSystem lifetime_system;

    float accumulator = 0.0f;

    void fixed_update(float fixed_dt);

    void update(float dt);

    void render(float alpha);
};
