#include "world.h"

void World::update(const float dt) {

}

void World::fixed_update(const float fixed_dt) {
    MovementSystem::fixed_update(registry, fixed_dt);
    LifetimeSystem::fixed_update(registry, fixed_dt);
    CameraSystem::fixed_update(registry, camera);
}

void World::render(const float alpha) {
    RenderSystem::render(registry, alpha);
}
