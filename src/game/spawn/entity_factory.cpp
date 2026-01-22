#include "entity_factory.hpp"

#include "../components/position.hpp"
#include "../components/velocity.hpp"

namespace engine::spawn {
    EntityFactory::EntityFactory(ecs::Registry &registry)
        : registry(registry) {
    }

    ecs::EntityId EntityFactory::create_player(const float x, const float y) {
        ecs::EntityId e = registry.create();
        init_character(e, x, y, CharacterType::Player);
        return e;
    }

    ecs::EntityId EntityFactory::create_enemy(const float x, const float y) {
        ecs::EntityId e = registry.create();
        init_character(e, x, y, CharacterType::Enemy);
        return e;
    }

    void EntityFactory::init_character(ecs::EntityId e, const float x, const float y,
                                       CharacterType character_type) {
        registry.add<components::Position>(e);
        registry.add<components::Velocity>(e);

        auto *p = registry.get<components::Position>(e);
        if (p != nullptr) {
            p->current.x = x;
            p->current.y = y;
        }

        auto *v = registry.get<components::Velocity>(e);
        if (v != nullptr) {
            // TODO: Velocity maybe should not be vector!!!
            auto velocity = character_type == CharacterType::Player ? 1.3F : 1.1F;
            v->current.x = velocity;
            v->current.y = velocity;
        }
    }
}
