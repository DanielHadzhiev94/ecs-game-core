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
    class CollisionSystem final : public core::system::ISystemFixedUpdate
    {

    public:
        void fixed_update(ecs::Registry &registry, float fixed_dt) override;

    private:
        static void resolve(components::Position &posA, components::RigidBody &rbA,
                            components::Position &posB, components::RigidBody &rbB,
                            const math::Vec2 &overlap, const math::Vec2 &delta);
    };
}
