#include "attack_system.hpp"

#include "ecs/view/view.hpp"
#include "event/event_bus.hpp"
#include "game/components/range_attack.hpp"
#include "game/components/enemy_tag.hpp"
#include "game/components/player_tag.hpp"
#include "game/components/position.hpp"
#include "game/input/input_system.hpp"
#include "game/events/damage_event.hpp"

namespace engine::systems::gameplay {
    using namespace game::components;

    AttackSystem::AttackSystem(core::EventBus &event_bus, game::input::InputSystem &input_system)
        : event_bus_(event_bus), input_system_(input_system) {
    }

    void AttackSystem::update(ecs::Registry &registry, float dt) {
        // Check if attack is pressed
        if (!input_system_.state()
            .is_pressed(game::input::InputAction::Attack))
            return;

        // This is not optima because every player will attack every enemy but for the demo is ok!
        auto player_view = ecs::View<PlayerTag>(registry);
        auto enemy_view = ecs::View<EnemyTag>(registry);

        for (auto player_id: player_view) {
            auto player_position = registry.get<Position>(player_id);
            auto player_attack = registry.get<RangeAttack>(player_id);

            // Create cooldown system
            if (player_attack->is_in_cooldown()) {
                std::cout << "[Attack System] Spell is in cooldown: "
                        << std::ceil(player_attack->get_remaining_cd())
                        << "s\n";
                continue;
            }

            for (auto enemy_id: enemy_view) {
                auto enemy_position = registry.get<Position>(enemy_id);
                auto distance = calc_distance(*player_position, *enemy_position);

                if (distance > player_attack->range) {
                    std::cout << "[Attack System] Out of range"
                              << std::endl;

                    continue;
                }

                player_attack->attack();

                event_bus_.publish<game::events::DamageEvent>(game::events::DamageEvent{
                    player_id, enemy_id, player_attack->damage
                });
            }
        }
    }

    float AttackSystem::calc_distance(const Position a, const Position b) {
        float x = b.current.x - a.current.x;
        float y = b.current.y - a.current.y;

        return std::sqrt((x * x) + (y * y));
    }
}
