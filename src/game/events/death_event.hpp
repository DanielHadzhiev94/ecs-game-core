#pragma once

#include "core/ecs/entity/entity_id.hpp"

namespace engine::game::events
{
    struct DeathEvent
    {
        ecs::EntityId target;
    };
}