#pragma once

namespace engine::ecs {
    class Registry;
}

namespace engine::core {
    class EventBus;
}

namespace engine::game::events
{
    struct DeathEvent;
}


namespace engine::game::systems::reactive
{
    class LifetimeSystem
    {
    public:
        explicit LifetimeSystem(ecs::Registry&, core::EventBus&);

    private:
        ecs::Registry& registry_;
        core::EventBus& event_bus_;
        void on_death(const events::DeathEvent&) const;
    };
}
