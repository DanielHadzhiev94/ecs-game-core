#include "collision_system.hpp"
#include "ecs/registry/registry.hpp"
#include "game/components/rigid_body.hpp"
#include "game/components/position.hpp"
#include "game/components/collider.hpp"
#include "ecs/view/view.hpp"
#include "game/components/enemy_tag.hpp"
#include "game/components/player_tag.hpp"
#include "game/events/damage_event.hpp"

namespace engine::game::systems
{
    using namespace engine::game::components;
    using namespace engine::math;

    CollisionSystem::CollisionSystem(core::EventBus &event_bus)
        :  event_bus_(event_bus){
    }

    void CollisionSystem::fixed_update(ecs::Registry &registry, float /*dt*/)
    {
        // View over all entities that have Position, Collider and RigidBody
        auto view = engine::ecs::View<Position, Collider, RigidBody>(registry);

        // NOTE: Current complexity is O(n²). This will be optimized later.
        for (auto a : view)
        {
            // Reset grounded flag every fixed frame.
            // If no valid ground collision occurs this frame,
            // the body will remain ungrounded.
            auto &rbA = *registry.get<RigidBody>(a);
            rbA.grounded = false;

            for (auto b : view)
            {
                // Skip self-collision
                if (a == b)
                    continue;

                // Components for entity A
                auto &posA = *registry.get<Position>(a);
                auto &colA = *registry.get<Collider>(a);

                // Components for entity B
                auto &posB = *registry.get<Position>(b);
                auto &colB = *registry.get<Collider>(b);
                auto &rbB = *registry.get<RigidBody>(b);

                // If both bodies are static, no resolution is required.
                if (rbA.is_static && rbB.is_static)
                    continue;

                // Compute vector between centers (relative position)
                Vec2 delta = posB.current - posA.current;

                // Compute overlap (penetration depth) on both axes.
                // overlap = (halfA + halfB) - |center distance|
                Vec2 overlap = {
                    colA.half_extends.x + colB.half_extends.x - std::abs(delta.x),
                    colA.half_extends.y + colB.half_extends.y - std::abs(delta.y)};

                // If overlapping on both axes → collision detected
                if (overlap.x > 0.f && overlap.y > 0.f)
                {
                    resolve(posA, rbA, posB, rbB, overlap, delta);

                    bool a_is_player = registry.has<PlayerTag>(a);
                    bool b_is_enemy = registry.has<EnemyTag>(b);

                    bool a_is_enemy = registry.has<EnemyTag>(a);
                    bool b_is_player = registry.has<PlayerTag>(b);

                    constexpr int DAMAGE = 10;

                    // Player → Enemy
                    if (a_is_player && b_is_enemy)
                    {
                        event_bus_.publish(events::DamageEvent{ a, b, DAMAGE });
                    }

                    if (b_is_player && a_is_enemy)
                    {
                        event_bus_.publish(events::DamageEvent{ b, a, DAMAGE });
                    }
                }
            }
        }
    }

    void CollisionSystem::resolve(
        Position &posA, RigidBody &rbA,
        Position &posB, RigidBody &rbB,
        const Vec2 &overlap,
        const Vec2 &delta)
    {
        // Determine axis of minimum penetration.
        // We resolve along the smallest overlap to minimize correction.
        bool resolveX = overlap.x < overlap.y;

        Vec2 correction{0.f, 0.f};
        Vec2 normal{0.f, 0.f};

        // Determine correction direction based on relative position.
        if (resolveX)
        {
            correction.x = (delta.x < 0.f ? -overlap.x : overlap.x);
            normal.x = (correction.x > 0.f ? 1.f : -1.f);
        }
        else
        {
            correction.y = (delta.y < 0.f ? -overlap.y : overlap.y);
            normal.y = (correction.y > 0.f ? 1.f : -1.f);
        }

        // ---- Positional correction ----
        // Static bodies do not move.
        // Dynamic bodies are adjusted accordingly.

        if (rbA.is_static)
        {
            posB.current += correction;
        }
        else if (rbB.is_static)
        {
            posA.current -= correction;
        }
        else
        {
            // If both bodies are dynamic, split correction evenly.
            posA.current -= correction * 0.5f;
            posB.current += correction * 0.5f;
        }

        // ---- Velocity resolution ----
        // Remove velocity component along the collision normal.
        // v' = v - dot(v, n) * n

        if (!rbA.is_static)
        {
            float vn = Vec2::dot(rbA.velocity, normal);

            // Only remove velocity if moving toward the surface
            if (vn < 0.f)
            {
                rbA.velocity -= normal * vn;
            }
        }

        if (!rbB.is_static)
        {
            Vec2 invertedNormal = normal * -1.f;

            float vn = Vec2::dot(rbB.velocity, invertedNormal);

            if (vn < 0.f)
            {
                rbB.velocity -= invertedNormal * vn;
            }
        }

        // ---- Grounded detection ----
        // A becomes grounded only if:
        // - A is dynamic
        // - B is static
        // - The collision normal points upward

        if (!rbA.is_static && rbB.is_static && normal.y > 0.5f)
        {
            rbA.grounded = true;
        }

        // B becomes grounded if landing on static A
        if (!rbB.is_static && rbA.is_static && normal.y < -0.5f)
        {
            rbB.grounded = true;
        }
    }
}
