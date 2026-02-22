#pragma once

#include "core/system/interface/i_system_fixed_update.hpp"
#include "core/event/event_bus.hpp"
#include "game/components/position.hpp"
#include "game/components/rigid_body.hpp"

namespace engine::ecs {
    class Registry;
}

namespace engine::game::systems {
    class CollisionSystem : public core::system::ISystemFixedUpdate {
    public:
        explicit CollisionSystem(core::EventBus &event_bus);

        void fixed_update(ecs::Registry &registry, float dt) override;

    private:
        core::EventBus &event_bus_;

        void resolve(
            components::Position &posA, components::RigidBody &rbA,
            components::Position &posB, components::RigidBody &rbB,
            const math::Vec2 &overlap,
            const math::Vec2 &delta);
    };
}
