#include "cooldown_system.hpp"

#include "ecs/view/view.hpp"
#include "game/components/range_attack.hpp"

namespace engine::game::systems::gameplay {
    using namespace components;

    void CooldownSystem::update(ecs::Registry &registry, float dt) {
        auto range_attack_view = ecs::View<RangeAttack>(registry);

        for (auto entity_id: range_attack_view) {
            auto range_attack = registry.get<RangeAttack>(entity_id);
            
            range_attack->tick(dt);
        }
    }
}
