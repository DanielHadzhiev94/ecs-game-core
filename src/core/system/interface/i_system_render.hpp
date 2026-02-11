#pragma once

#include "ecs/registry/registry.hpp"

namespace engine::core::system
{
    struct ISystemRender
    {
        virtual ~ISystemRender() = default;
        virtual void render(engine::ecs::Registry &registry, float alpha) = 0;
    };
}