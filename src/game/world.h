#pragma once


#include "../core/registry/registry.h"
#include "systems/movement_system.h"


class World {
public:
    ~World() = default;

    void update(float dt);

private:
    Registry registry;
    MovementSystem movement_system;
};

inline void World::update(const float dt) {
    movement_system.update(registry, dt);
}
