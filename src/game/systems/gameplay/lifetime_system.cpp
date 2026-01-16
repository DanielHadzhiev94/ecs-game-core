#include "../lifetime_system.hpp"
#include "../../components/health.hpp"
#include "view/view.hpp"

struct Health;

void LifetimeSystem::fixed_update(Registry &registry, const float fixed_dt) {
    auto view = View<Health>(registry);

    // Decrease health just for test
    for (auto entity: view) {
        auto health = registry.get<Health>(entity);

        health->value -= static_cast<std::int32_t>(fixed_dt);

        if (health->value <= 0) {
            health->value = 0;
            registry.schedule_destruction(entity);
        }
    }
}
