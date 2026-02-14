#include "entity_factory.hpp"

#include "../components/position.hpp"
#include "../components/velocity.hpp"
#include "../components/player_tag.hpp"
#include "../components/enemy_tag.hpp"

namespace engine::game::spawn
{
    EntityFactory::EntityFactory(ecs::Registry &registry)
        : registry(registry)
    {
    }

    ecs::EntityId EntityFactory::create_player(components::Position position)
    {
        ecs::EntityId e = registry.create();
        init_character(e, position, CharacterType::Player);
        return e;
    }

    ecs::EntityId EntityFactory::create_enemy(components::Position position)
    {
        ecs::EntityId e = registry.create();
        init_character(e, position, CharacterType::Enemy);
        return e;
    }

    void EntityFactory::init_character(ecs::EntityId e, components::Position position,
                                       CharacterType character_type)
    {

        if (character_type == CharacterType::Player)
        {
            registry.add<components::PlayerTag>(e);
        }
        else
        {
            registry.add<components::EnemyTag>(e);
        }

        registry.add<components::Position>(e);
        registry.add<components::Velocity>(e);

        auto *p = registry.get<components::Position>(e);
        if (p != nullptr)
        {
            p->current;
        }

        auto *v = registry.get<components::Velocity>(e);
        if (v != nullptr)
        {
            // TODO: Velocity maybe should not be vector!!!
            auto velocity = character_type == CharacterType::Player ? 1.3F : 1.1F;
            v->current.x = velocity;
            v->current.y = velocity;
        }
    }
}
