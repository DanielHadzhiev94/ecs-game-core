#pragma once

#include "core/ecs/entity/entity_id.hpp"

namespace engine::game::events
{
    struct DamageEvent
    {
        ecs::EntityId attacker;
        ecs::EntityId target;
        std::uint32_t amount;
    };
}