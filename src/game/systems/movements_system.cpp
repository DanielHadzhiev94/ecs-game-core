#include "movement_system.hpp"
#include "../components/position.hpp"
#include "../components/velocity.hpp"
#include "view/view.hpp"

void MovementSystem::fixed_update(Registry &registry, const float fixed_dt) {
    auto view = View<Position, Velocity>(registry);

    for (auto entity: view) {
        auto &transform = *registry.get<Position>(entity);
        const auto &velocity = *registry.get<Velocity>(entity);

        // For interpolation
        transform.previous = transform.current;

        transform.current.x += velocity.value * fixed_dt;
        transform.current.y += velocity.value * fixed_dt;
    }
}
