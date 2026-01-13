#include "world.h"

void World::update(const float dt) {
    movement_system.update(registry, dt);
}
