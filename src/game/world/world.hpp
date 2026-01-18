#pragma once

#include "../systems/gameplay/lifetime_system.hpp"
#include "../systems/gameplay/movement_system.hpp"
#include "../systems/camera_system.hpp"
#include "../systems/render/render_system.hpp"
#include "../../core/registry/registry.hpp"

class World {
public:
    void tick(float dt);

private:
    Registry registry;

    RenderSystem render_system;
    CameraSystem camera_system;
    MovementSystem movement_system;
    LifetimeSystem lifetime_system;

    float accumulator = 0.0f;

    void fixed_update(float fixed_dt);

    void update(float dt);

    void render(float alpha);
};
