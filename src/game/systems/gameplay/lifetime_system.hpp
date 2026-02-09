#pragma once

#include "system/interface/i_system_fixed_update.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::game::systems::gameplay
{
    class LifetimeSystem : public engine::core::system::interface::ISystemFixedUpdate
    {
    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt) override;
    };
}
