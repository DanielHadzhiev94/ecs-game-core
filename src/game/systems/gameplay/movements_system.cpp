#include "movement_system.hpp"
#include "../../components/position.hpp"
#include "../../components/velocity.hpp"
#include "ecs/view/view.hpp"

namespace engine::game::systems {
    void MovementSystem::fixed_update(ecs::Registry &registry, const float fixed_dt) {
        auto view = ecs::View<components::Position, components::Velocity>(registry);

        for (auto entity: view) {
            auto &transform = *registry.get<components::Position>(entity);
            const auto &velocity = *registry.get<components::Velocity>(entity);

            // For interpolation
            transform.previous = transform.current;
            transform.current += velocity.current * fixed_dt;
        }
    }
}
