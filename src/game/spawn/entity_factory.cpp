#include "entity_factory.h"

#include "../components/position.h"
#include "../components/velocity.h"

EntityFactory::EntityFactory(Registry &registry)
    : registry(registry) {
}

EntityId EntityFactory::create_player(const float x, const float y) {
    EntityId e = registry.create();
    init_character(e, x, y, CharacterType::Player);
    return e;
}

EntityId EntityFactory::create_enemy(const float x, const float y) {
    EntityId e = registry.create();
    init_character(e, x, y, CharacterType::Enemy);
    return e;
}

void EntityFactory::init_character(EntityId e, const float x, const float y, CharacterType character_type) {
    registry.add<Position>(e);
    registry.add<Velocity>(e);

    auto *p = registry.get<Position>(e);
    if (p != nullptr) {
        p->x = x;
        p->y = y;
    }

    auto *v = registry.get<Velocity>(e);
    if (v != nullptr)
        v->value = character_type == CharacterType::Player ? 1.3F : 1.1F;
}
