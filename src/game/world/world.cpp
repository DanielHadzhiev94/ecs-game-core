#include "world.hpp"

#include "game/components/enemy_tag.hpp"
#include "game/components/health.hpp"
#include "game/components/player_tag.hpp"
#include "game/components/velocity.hpp"
#include "game/systems/gameplay/movement_system.hpp"
#include "game/systems/gameplay/collision_system.hpp"
#include "game/systems/gameplay/ai_enemy_system.hpp"

using namespace engine::game::components;

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

    void World::initialization_demo() {
        // Creating player
        auto player_id = registry_.create();
        registry_.add<Position>(player_id, Position{100.0f, 100.0f});
        registry_.add<Velocity>(player_id, Velocity{5.0f, 5.0f});
        registry_.add<Health>(player_id);
        registry_.add<PlayerTag>(player_id);


        // Creating enemy
        auto enemy_id = registry_.create();
        registry_.add<Position>(enemy_id, Position{60.0f, 60.0f});
        registry_.add<Velocity>(enemy_id, Velocity{3.5f, 3.5f});
        registry_.add<Health>(enemy_id);
        registry_.add<EnemyTag>(enemy_id);
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
