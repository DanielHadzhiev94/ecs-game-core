#pragma once

#include "../../core/registry/registry.h"
#include "../systems/lifetime_System.h"
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

    RenderSystem render_system;
    MovementSystem movement_system;
    LifetimeSystem lifetime_system;
};
