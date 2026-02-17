#include "ai_enemy_system.hpp"
#include "ecs/registry/registry.hpp"
#include "game/components/enemy_tag.hpp"
#include "game/components/player_tag.hpp"
#include "game/components/velocity.hpp"
#include "game/components/position.hpp"
#include "core/ecs/view/view.hpp"

namespace engine::game::systems
{
    using namespace engine::game::components;

    void AiEnemySystem::fixed_update(ecs::Registry &registry, float)
    {
        auto player_view = ecs::View<
            components::PlayerTag,
            components::Position>(registry);

        if (player_view.begin() == player_view.end())
            return;

        auto player = *player_view.begin();
        const auto &player_pos =
            *registry.get<components::Position>(player);

        auto enemy_view = ecs::View<
            components::EnemyTag,
            components::Position,
            components::Velocity>(registry);

        constexpr float enemy_speed = 60.f;

        for (auto entity : enemy_view)
        {
            auto &pos =
                *registry.get<components::Position>(entity);
            auto &vel =
                *registry.get<components::Velocity>(entity);

            auto direction =
                (player_pos.current - pos.current).normalized();

            vel.current = direction * enemy_speed;
        }
    }
}