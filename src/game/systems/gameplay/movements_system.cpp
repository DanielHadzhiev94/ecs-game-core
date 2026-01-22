#include "movement_system.hpp"
#include "../../components/position.hpp"
#include "../../components/velocity.hpp"
#include "ecs/view/view.hpp"

void MovementSystem::fixed_update(engine::ecs::Registry &registry, const float fixed_dt) {
    auto view = engine::ecs::View<Position, Velocity>(registry);

    for (auto entity: view) {
        auto &transform = *registry.get<Position>(entity);
        const auto &velocity = *registry.get<Velocity>(entity);

        // For interpolation
        transform.previous = transform.current;
        transform.current += velocity.current * fixed_dt;
    }
}
