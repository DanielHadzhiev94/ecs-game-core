#include "health_system.hpp"
#include "core/ecs/registry/registry.hpp"
#include "core/event/event_bus.hpp"
#include "game/events/death_event.hpp"
#include "game/events/damage_event.hpp"
#include "game/components/health.hpp"

namespace engine::game::systems::reactive
{
    HealthSystem::HealthSystem(ecs::Registry &registry, core::EventBus &event_bus)
        : registry_(registry), event_bus_(event_bus)
    {
        event_bus.subscribe<events::DamageEvent>(
            [this](const events::DamageEvent &event)
            {
                on_damage(event);
            });
    };

    void HealthSystem::on_damage(const events::DamageEvent &event) const
    {
        auto *health = registry_.get<components::Health>(event.target);
        if (health == nullptr)
            return;

        health->value -= event.amount;

        if (health->value <= 0 && !health->is_dead)
        {
            health->value = 0;

            health->is_dead = true;
            event_bus_.publish<events::DeathEvent>(events::DeathEvent{event.target});
        }
    }
};