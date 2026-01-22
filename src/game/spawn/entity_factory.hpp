#pragma once
#include "ecs/registry/registry.hpp"


namespace engine::game::spawn {
    enum class CharacterType {
        Player,
        Enemy
    };

    class EntityFactory {
    public:
        explicit EntityFactory(ecs::Registry &registry);

        ecs::EntityId create_player(float x, float y);

        ecs::EntityId create_enemy(float x, float y);

    private:
        ecs::Registry &registry;

        void init_character(ecs::EntityId, float x, float y, CharacterType character_type);
    };
}
