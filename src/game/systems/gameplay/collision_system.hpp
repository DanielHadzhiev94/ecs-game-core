#pragma once

#include "core/system/interface/i_system_fixed_update.hpp"

namespace engine::math
{
    class Vec2;
}

namespace engine::ecs::registry
{
    class Registry;
}

namespace engine::game::components
{
    class Position;
    class RigidBody;
}

namespace engine::game::systems
{
    class CollisionSystem final : public engine::core::system::ISystemFixedUpdate
    {
        ~CollisionSystem() = default;

    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt) override;

    private:
        static void resolve(engine::game::components::Position &posA, engine::game::components::RigidBody &rbA,
                            engine::game::components::Position &posB, engine::game::components::RigidBody &rbB,
                            const engine::math::Vec2 &overlap, const engine::math::Vec2 &delta);
    };
}
