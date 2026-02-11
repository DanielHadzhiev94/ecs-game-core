#pragma once

#include "ecs/registry/registry.hpp"
#include "system/interface/i_system_fixed_update.hpp"

namespace engine::game::systems::gameplay
{
    class MovementSystem : public engine::core::system::ISystemFixedUpdate
    {
    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt) override;
    };
}
