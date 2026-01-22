#include "entity_factory.hpp"

#include "../components/position.hpp"
#include "../components/velocity.hpp"

EntityFactory::EntityFactory(engine::ecs::Registry &registry)
    : registry(registry) {
}

engine::ecs::EntityId EntityFactory::create_player(const float x, const float y) {
    engine::ecs::EntityId e = registry.create();
    init_character(e, x, y, CharacterType::Player);
    return e;
}

engine::ecs::EntityId EntityFactory::create_enemy(const float x, const float y) {
    engine::ecs::EntityId e = registry.create();
    init_character(e, x, y, CharacterType::Enemy);
    return e;
}

void EntityFactory::init_character(engine::ecs::EntityId e, const float x, const float y,
                                   CharacterType character_type) {
    registry.add<Position>(e);
    registry.add<Velocity>(e);

    auto *p = registry.get<Position>(e);
    if (p != nullptr) {
        p->current.x = x;
        p->current.y = y;
    }

    auto *v = registry.get<Velocity>(e);
    if (v != nullptr) {
        // TODO: Velocity maybe should not be vector!!!
        auto velocity = character_type == CharacterType::Player ? 1.3F : 1.1F;
        v->current.x = velocity;
        v->current.y = velocity;
    }
}
