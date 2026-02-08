#pragma once

#include "../input/input_system.hpp"
#include "ecs/registry/registry.hpp"
#include "../game/systems/interfaces/i_system_update.hpp"

namespace engine::game::systems
{
    class PlayerControlSystem : public ISystemUpdate
    {
    public:
        PlayerControlSystem(input::InputSystem &input_system);

        void update(ecs::Registry &registry, float dt) override;

    private:
        const input::InputSystem &input_system_;
    };
}
