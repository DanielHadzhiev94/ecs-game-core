#pragma once

#include "../components/camera.h"
#include "../../core/registry/registry.h"

#include "../systems/camera_system.h"
#include "../systems/lifetime_system.h"
#include "../systems/movement_system.h"
#include "../systems/render_system.h"

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
