#pragma once
#include "ecs/registry/registry.hpp"


namespace engine::spawn {
    enum class CharacterType {
        Player,
        Enemy
    };

    class EntityFactory {
    public:
        explicit EntityFactory(engine::ecs::Registry &registry);

        engine::ecs::EntityId create_player(float x, float y);

        engine::ecs::EntityId create_enemy(float x, float y);

    private:
        engine::ecs::Registry &registry;

        void init_character(engine::ecs::EntityId, float x, float y, CharacterType character_type);
    };
}
