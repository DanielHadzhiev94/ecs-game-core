#pragma once

#include "../core/registry/registry.h"
#include "systems/movement_system.h"

class World {
public:
    World() = default;

    void update(float dt);

private:
    Registry registry;
    MovementSystem movement_system;
};

