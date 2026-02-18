#pragma once

namespace engine::ecs
{
    class Registry;
}

namespace engine::core
{
    class EventBus;
}

namespace engine::events
{
    struct DamageEvent;
}

namespace engine::game::systems
{
    class HealthSystem
    {
    public:
        explicit HealthSystem(ecs::Registry &, core::EventBus &);

    private:
        void on_damage(const events::DamageEvent &);
        ecs::Registry &registry_;
    };
}