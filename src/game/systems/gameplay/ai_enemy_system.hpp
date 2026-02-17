#pragma once

#include "system/interface/i_system_fixed_update.hpp"

namespace engine::ecs
{
    class Registry;
}

namespace engine::game::systems
{
    class AiEnemySystem : public core::system::ISystemFixedUpdate
    {
    public:
        void fixed_update(ecs::Registry &, float) override;
    };
}