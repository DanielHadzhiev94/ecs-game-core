#include "movement_system.h"
#include "../components/position.h"
#include "../components/velocity.h"
#include "view/view.h"

void MovementSystem::update(Registry &registry, float dt) {
    auto view = View<Position, Velocity>(registry);

    for (auto entity: view) {
        auto &transform = *registry.get<Position>(entity);
        const auto &velocity = *registry.get<Velocity>(entity);

        transform.x += velocity.value * dt;
        transform.y += velocity.value * dt;
    }
}
