#pragma once

#include "../game/systems/interfaces/i_system_fixed_update.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::game::systems
{
    class LifetimeSystem : public ISystemFixedUpdate
    {
    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt) override;
    };
}
