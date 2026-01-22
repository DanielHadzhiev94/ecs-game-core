#pragma once

#include "ecs/registry/registry.hpp"

namespace engine::game::systems {
    class CameraSystem {
    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt);
    };
}
