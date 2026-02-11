#include "collision_system.hpp"
#include "ecs/registry/registry.hpp"
#include "game/components/rigid_body.hpp"
#include "game/components/position.hpp"
#include "game/components/collider.hpp"
#include "ecs/view/view.hpp"

namespace engine::game::systems
{
    using namespace engine::game::components;
    using namespace engine::math;

    void CollisionSystem::fixed_update(ecs::Registry &registry, float /*dt*/)
    {
        auto view = engine::ecs::View<Position, Collider, RigidBody>(registry);

        // TODO: The complexity is (O2) this should be change in the future
        for (auto a : view)
        {
            for (auto b : view)
            {
                if (a == b)
                    continue;

                //  Get components of the first body
                auto &posA = *registry.get<Position>(a);
                auto &colA = *registry.get<Collider>(a);
                auto &rbA = *registry.get<RigidBody>(a);

                // Get components of the second body
                auto &posB = *registry.get<Position>(b);
                auto &colB = *registry.get<Collider>(b);
                auto &rbB = *registry.get<RigidBody>(b);

                // If both bodies are static, no resolution is needed.
                if (rbA.is_static && rbB.is_static)
                    continue;

                // Compute the vector between the centers of the two AABBs.
                // This tells us their relative direction.
                Vec2 delta = posB.current - posA.current;

                // Compute overlap (penetration depth) on both axes.
                //
                // Formula:
                // overlap = (halfA + halfB) - distance_between_centers
                //
                // If overlap > 0 on both axes, they are intersecting.
                Vec2 overlap = {
                    colA.half_extends.x + colB.half_extends.x - std::abs(delta.x),
                    colA.half_extends.y + colB.half_extends.y - std::abs(delta.y)};

                // 7️⃣ Check if we have actual penetration on both axes.
                if (overlap.x > 0 && overlap.y > 0)
                {
                    // If so, resolve the penetration.
                    resolve(posA, rbA, posB, rbB, overlap, delta);
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
        // Determine which axis has the smaller penetration.
        // We resolve along the smallest overlap to ensure minimal correction.
        bool resolveX = overlap.x < overlap.y;

        Vec2 correction{0.f, 0.f};

        // Determine the direction of the correction.
        // delta indicates which side the second body is on.
        if (resolveX)
        {
            correction.x = (delta.x < 0.f ? -overlap.x : overlap.x);
        }
        else
        {
            correction.y = (delta.y < 0.f ? -overlap.y : overlap.y);
        }

        // Apply the correction depending on whether bodies are static or dynamic.
        //
        // - Static bodies do not move.
        // - Dynamic bodies are adjusted.
        if (rbA.is_static)
        {
            // A is static (e.g., ground or wall) → move B
            posB.current += correction;
        }
        else if (rbB.is_static)
        {
            // B is static → move A
            posA.current -= correction;
        }
        else
        {
            // Both are dynamic → split the correction evenly
            posA.current -= correction * 0.5f;
            posB.current += correction * 0.5f;
        }
    }
};
