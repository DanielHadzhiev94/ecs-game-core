#pragma once

#include "../../core/entity/entity_id.hpp"
#include "../../core/registry/registry.hpp"

enum class CharacterType {
    Player,
    Enemy
};

class EntityFactory {
public:
    explicit EntityFactory(Registry &registry);

    EntityId create_player(float x, float y);

    EntityId create_enemy(float x, float y);

private:
    Registry &registry;

    void init_character(EntityId, float x, float y, CharacterType character_type);
};
