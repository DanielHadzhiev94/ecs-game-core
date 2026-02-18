#include "health_system.hpp"
#include "core/ecs/registry/registry.hpp"
#include "core/event/event_bus.hpp"
#include "game/events/damage_event.hpp"
#include "game/components/health.hpp"

namespace engine::game::systems
{
    HealthSystem::HealthSystem(ecs::Registry &registry, core::EventBus &eventBus)
        : registry_(registry)
    {
        eventBus.subscribe<events::DamageEvent>(
            [this](const events::DamageEvent &event)
            {
                on_damage(event);
            });
    };

    void HealthSystem::on_damage(const events::DamageEvent &event)
    {
        auto *health = registry_.get<components::Health>(event.target);
        if (health == nullptr)
            return;

        health->value -= event.amount;
    }
};