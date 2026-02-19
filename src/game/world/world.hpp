#pragma once

#include "core/ecs/entity/entity_manager.hpp"
#include "core/ecs/storage/storage_manager.hpp"
#include "core/ecs/registry/registry.hpp"

#include "core/event/event_bus.hpp"
#include "core/system/system_manager.hpp"
#include "core/render/IRenderer.hpp"

#include "game/systems/reactive/health_system.hpp"
#include "game/systems/gameplay/lifetime_system.hpp"

namespace engine::game
{
    class World
    {
    public:
        explicit World(engine::render::IRenderer &renderer);

        void tick(float dt);

        ecs::Registry &registry();
        core::EventBus &event_bus();

    private:
        static constexpr float FIXED_DT = 1.0f / 60.0f;

        // Core ECS ownership
        ecs::EntityManager entity_manager_;
        ecs::StorageManager storage_manager_;
        ecs::Registry registry_;

        // Messaging
        core::EventBus event_bus_;

        // Execution orchestration
        core::system::SystemManager system_manager_;

        // Reactive systems
        systems::reactive::HealthSystem health_system_;
        systems::gameplay::LifetimeSystem lifetime_system_;

        float accumulator_ = 0.f;
    };
}
