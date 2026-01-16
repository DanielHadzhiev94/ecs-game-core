#pragma once

#include "../../core/registry/registry.hpp"
#include "../systems/gameplay/lifetime_system.hpp"
#include "../systems/movement_system.hpp"
#include "../systems/render/render_system.hpp"

class World {
public:
    World() = delete;

    void fixed_update(float fixed_dt);

    void update(float dt);

    void render(float alpha);

private:
    Registry registry;
    Camera camera;

    RenderSystem render_system;
    CameraSystem camera_system;
    MovementSystem movement_system;
    LifetimeSystem lifetime_system;
};
