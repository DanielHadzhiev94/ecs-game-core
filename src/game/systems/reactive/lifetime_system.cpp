#include "lifetime_system.hpp"

#include "game/events/death_event.hpp"
#include "core/event/event_bus.hpp"
#include "core/ecs/registry/registry.hpp"


namespace engine::game::systems::reactive {
    LifetimeSystem::LifetimeSystem(ecs::Registry &registry, core::EventBus &event_bus)
        : registry_(registry), event_bus_(event_bus) {
        event_bus_.subscribe<events::DeathEvent>([this](const events::DeathEvent &event) {
            on_death(event);
        });
    }

    void LifetimeSystem::on_death(const events::DeathEvent &event) const {
        registry_.schedule_destruction(event.target);
    }
}
