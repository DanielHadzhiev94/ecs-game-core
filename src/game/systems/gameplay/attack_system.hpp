#pragma once
#include "system/interface/i_system_update.hpp"

namespace engine::ecs {
    class Registry;
}

namespace engine::core {
    class EventBus;
}

namespace engine::game::input {
    class InputSystem;
}

namespace engine::game::components {
    class Position;
}

namespace engine::systems::gameplay{
    class AttackSystem : public core::system::ISystemUpdate {
    public:
        explicit AttackSystem(core::EventBus &, game::input::InputSystem &);

        void update(ecs::Registry &registry, float dt) override;

    private:
        core::EventBus &event_bus_;
        game::input::InputSystem& input_system_;

        static float calc_distance(game::components::Position a, game::components::Position b);
    };
}
