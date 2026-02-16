#include "entity_factory.hpp"

#include "../components/collider.hpp"
#include "../components/health.hpp"
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

    void EntityFactory::init_character(
        ecs::EntityId e,
        components::Position position,
        CharacterType character_type)
    {
        if (character_type == CharacterType::Player)
            registry.add<components::PlayerTag>(e);
        else
            registry.add<components::EnemyTag>(e);

        registry.add<components::Position>(e, position);
        registry.add<components::Velocity>(e, components::Velocity{0.f, 0.f});

        // Collider
        components::Collider collider{};

        if (character_type == CharacterType::Player)
            collider.half_extends = {16.f, 16.f};
        else
            collider.half_extends = {14.f, 14.f};

        registry.add<components::Collider>(e, collider);

        // Health
        int health = character_type == CharacterType::Player ? 100 : 50;
        registry.add<components::Health>(e, components::Health{health});
    }
}
