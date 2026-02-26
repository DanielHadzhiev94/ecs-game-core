#include "world.hpp"

#include "game/systems/gameplay/movement_system.hpp"
#include "game/systems/gameplay/collision_system.hpp"
#include "game/systems/gameplay/ai_enemy_system.hpp"


namespace engine::game {
    World::World()
        : registry_(entity_manager_, storage_manager_),
          health_system_(registry_, event_bus_),
          lifetime_system_(registry_, event_bus_) {
        system_manager_.register_system(
            std::make_unique<systems::gameplay::MovementSystem>());

        system_manager_.register_system(
            std::make_unique<systems::CollisionSystem>());

        system_manager_.register_system(
            std::make_unique<systems::AiEnemySystem>());

        // system_manager_.register_system(
        //     std::make_unique<systems::render::RenderSystem>(renderer));
    }

    void World::tick(float dt) {
        accumulator_ += dt;

        while (accumulator_ >= FIXED_DT) {
            system_manager_.fixed_update(registry_, FIXED_DT);

            registry_.execute_scheduled_destruction();

            accumulator_ -= FIXED_DT;
        }

        const float alpha = accumulator_ / FIXED_DT;

        system_manager_.update(registry_, dt);
        system_manager_.render(registry_, alpha);
    }

    ecs::Registry &World::registry() {
        return registry_;
    }

    core::EventBus &World::event_bus() {
        return event_bus_;
    }
}
