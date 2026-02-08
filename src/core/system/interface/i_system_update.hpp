#pragma once

#include "ecs/registry/registry.hpp"

namespace engine::core::system::interface
{
    struct ISystemUpdate
    {
        virtual ~ISystemUpdate() = default;
        virtual void update(ecs::Registry &registry, float dt) = 0;
    };
}