#include "lifetime_System.h"
#include "../components/health.h"
#include "view/view.h"

struct Health;

void LifetimeSystem::update(Registry &registry, float dt) {
    auto view = View<Health>(registry);

    // Decrease health just for test
    for (auto entity: view) {
        auto health = registry.get<Health>(entity);

        health->value -= dt;

        if (health->value <= 0) {
            health->value = 0;
            registry.schedule_destruction(entity);
        }
    }
}
