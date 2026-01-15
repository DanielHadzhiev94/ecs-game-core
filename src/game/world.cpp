#include "world.h"

void World::update(const float dt) {
 // Input System for example
}

void World::fixed_update(const float fixed_dt) {
    MovementSystem::fixed_update(registry, fixed_dt);
    LifetimeSystem::fixed_update(registry, fixed_dt);
}
