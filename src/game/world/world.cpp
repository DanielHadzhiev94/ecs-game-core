#include "world.hpp"

namespace engine::game
{
    constexpr float FIXED_DT = 1.0f / 60.0f;

    World::World(ecs::Registry &registry, engine::render::IRenderer &renderer)
        : registry(registry), render_system(renderer)
    {
    }

    void World::tick(float dt)
    {
        accumulator += dt;

        while (accumulator >= FIXED_DT)
        {
            system_manager.fixed_update(registry, FIXED_DT);
            accumulator -= FIXED_DT;
        }

        const float alpha = accumulator / FIXED_DT;
        system_manager.update(registry, dt);
        render(alpha);
    }

    void World::render(float alpha)
    {
        render_system.render(registry, alpha);
    }
}
