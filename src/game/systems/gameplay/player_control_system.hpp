#pragma once

#include "game/input/input_system.hpp"
#include "ecs/registry/registry.hpp"
#include "system/interface/i_system_update.hpp"

namespace engine::game::systems::gameplay
{
    class PlayerControlSystem : public engine::core::system::ISystemUpdate
    {
    public:
        PlayerControlSystem(input::InputSystem &input_system);

        void update(ecs::Registry &registry, float dt) override;

    private:
        input::InputSystem &input_system_;
    };
}
