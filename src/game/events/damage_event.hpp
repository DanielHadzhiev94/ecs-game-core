#pragma once

#include "core/ecs/entity/entity_id.hpp"

namespace engine::game::events
{
    struct DamageEvent
    {
        ecs::EntityId attakcer;
        ecs::EntityId target;
        float amount;
    };
}