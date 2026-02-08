#pragma once

#include "ecs/registry/registry.hpp"
#include "../game/systems/interfaces/i_system_fixed_update.hpp"

namespace engine::game::systems
{
    class MovementSystem : public ISystemFixedUpdate
    {
    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt) override;
    };
}
