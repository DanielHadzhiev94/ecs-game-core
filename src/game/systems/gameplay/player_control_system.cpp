#include "player_control_system.hpp"

#include "ecs/view/view.hpp"
#include "../game/components/velocity.hpp"
#include "../game/components/player_tag.hpp"

namespace engine::game::systems {
    PlayerControlSystem::PlayerControlSystem(input::InputSystem &input_system)
        : input_system_(input_system) {
    }

    void PlayerControlSystem::update(ecs::Registry &registry, float /*dt*/) {
        const auto &input_state = input_system_.state();

        auto view = ecs::View<components::PlayerTag, components::Velocity>(registry);
        for (auto entity: view) {
            auto &velocity = *registry.get<components::Velocity>(entity);

            if (input_state.is_pressed(input::InputAction::MoveLeft))
                velocity.current.x -= 0.5f;

            if (input_state.is_pressed(input::InputAction::MoveRight))
                velocity.current.x += 0.5f;

            if (input_state.is_pressed(input::InputAction::Jump))
                velocity.current.y += 0.5f;
        }
    }
}
