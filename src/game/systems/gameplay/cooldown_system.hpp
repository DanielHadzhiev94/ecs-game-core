#pragma once
#include "system/interface/i_system_update.hpp"

namespace engine::game::systems::gameplay {
    class CooldownSystem: public core::system::ISystemUpdate {
    public:
        void update(ecs::Registry &registry, float dt) override;
    };
}
