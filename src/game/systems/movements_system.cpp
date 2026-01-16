#include "movement_system.h"
#include "../components/position.h"
#include "../components/velocity.h"
#include "view/view.h"

void MovementSystem::fixed_update(Registry &registry, const float fixed_dt) {
    auto view = View<Position, Velocity>(registry);

    for (auto entity: view) {
        auto &transform = *registry.get<Position>(entity);
        const auto &velocity = *registry.get<Velocity>(entity);

        // For interpolation
        transform.previous_x = transform.x;
        transform.previous_y = transform.y;

        transform.x += velocity.value * fixed_dt;
        transform.y += velocity.value * fixed_dt;
    }
}
