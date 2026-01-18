#include "world.hpp"

constexpr float FIXED_DT = 1.0f / 60.0f;

World::World(Registry &registry, IRenderer &renderer)
    : registry(registry), render_system(renderer) {
}

void World::tick(float dt) {
    accumulator += dt;

    while (accumulator >= FIXED_DT) {
        fixed_update(FIXED_DT);
        accumulator -= FIXED_DT;
    }

    const float alpha = accumulator / FIXED_DT;
    update(dt);
    render(alpha);
}

void World::fixed_update(float fixed_dt) {
    movement_system.fixed_update(registry, fixed_dt);
    lifetime_system.fixed_update(registry, fixed_dt);
    camera_system.fixed_update(registry, fixed_dt);
}

void World::update(float dt) {
}

void World::render(float alpha) {
    render_system.render(registry, alpha);
}
