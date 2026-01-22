#include "../gameplay/lifetime_system.hpp"
#include "../game/components/health.hpp"
#include "ecs/view/view.hpp"

namespace engine::game::systems {
    void LifetimeSystem::fixed_update(ecs::Registry &registry, const float fixed_dt) {
        auto view = ecs::View<components::Health>(registry);

        // Decrease health just for test
        for (auto entity: view) {
            auto health = registry.get<components::Health>(entity);

            health->value -= static_cast<std::int32_t>(fixed_dt);

            if (health->value <= 0) {
                health->value = 0;
                registry.schedule_destruction(entity);
            }
        }
    }
}
