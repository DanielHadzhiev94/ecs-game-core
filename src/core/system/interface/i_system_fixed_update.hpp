#pragma once

#include "ecs/registry/registry.hpp"

namespace engine::core::system::interface
{
    struct ISystemFixedUpdate
    {
        virtual ~ISystemFixedUpdate() = default;
        virtual void fixed_update(ecs::Registry &registry, float fixed_dt) = 0;
    };
}
