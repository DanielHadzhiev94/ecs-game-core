#pragma once
#include "ecs/registry/registry.hpp"

namespace engine::systems {
    class MovementSystem {
    public:
        void fixed_update(engine::ecs::Registry &registry, float fixed_dt);
    };
}
