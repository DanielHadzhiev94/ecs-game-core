#pragma once

namespace engine::ecs
{
    class Registry;
}

namespace engine::core
{
    class EventBus;
}

namespace engine::game::events
{
    struct DamageEvent;
}

namespace engine::game::systems::reactive
{
    class HealthSystem
    {
    public:
        explicit HealthSystem(ecs::Registry &, core::EventBus &);

    private:
        ecs::Registry &registry_;
        core::EventBus &event_bus_;

        void on_damage(const events::DamageEvent &);
    };
}