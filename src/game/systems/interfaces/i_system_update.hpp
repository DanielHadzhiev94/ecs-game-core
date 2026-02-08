#pragma once

#include "ecs/registry/registry.hpp"

namespace engine::game::systems
{
    struct ISystemUpdate
    {
        virtual ~ISystemUpdate() = default;
        virtual void update(ecs::Registry &registry, float dt) = 0;
    };
}