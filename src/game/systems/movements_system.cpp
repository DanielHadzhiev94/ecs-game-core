#include "movement_system.h"
#include "../components/position.h"
#include "../components/velocity.h"
#include "view/view.h"

void MovementSystem::fixed_update(Registry &registry, const float fixed_dt) {
    auto view = View<Position, Velocity>(registry);

    for (auto entity: view) {
        auto &transform = *registry.get<Position>(entity);
        const auto &velocity = *registry.get<Velocity>(entity);

        transform.x += velocity.value * fixed_dt;
        transform.y += velocity.value * fixed_dt;
    }
}
