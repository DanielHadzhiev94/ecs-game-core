#pragma once
#include "ecs/registry/registry.hpp"

namespace engine::game::spawn
{
    enum class CharacterType
    {
        Player,
        Enemy
    };

    class EntityFactory
    {
    public:
        explicit EntityFactory(ecs::Registry &);

        ecs::EntityId create_player(components::Position);

        ecs::EntityId create_enemy(components::Position);

    private:
        ecs::Registry &registry;

        void init_character(ecs::EntityId, components::Position position, CharacterType character_type);
    };
}
