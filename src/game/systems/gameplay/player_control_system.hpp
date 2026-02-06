#pragma once

#include "../input/input_system.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::game::systems {
    class PlayerControlSystem {
    public :
        PlayerControlSystem(input::InputSystem &input_system);

        void update(ecs::Registry& registry, float dt);

    private:
        const input::InputSystem &input_system_;
    };
}
