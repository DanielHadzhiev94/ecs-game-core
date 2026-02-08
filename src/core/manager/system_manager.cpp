#include "system_manager.hpp"
#include "ecs/registry/registry.hpp"
#include "../game/systems/interfaces/i_system_update.hpp"
#include "../game/systems/interfaces/i_system_fixed_update.hpp"

namespace engine::core::manager
{
    void SystemManager::register_system(std::unique_ptr<game::systems::ISystemUpdate> system)
    {
        update_systems_.push_back(std::move(system));
    }

    void SystemManager::register_system(std::unique_ptr<game::systems::ISystemFixedUpdate> system)
    {
        fixed_update_systems_.push_back(std::move(system));
    }

    void SystemManager::update(engine::ecs::Registry &registry, float dt)
    {
        for (auto &system : update_systems_)
        {
            system->update(registry, dt);
        }
    }

    void SystemManager::fixed_update(engine::ecs::Registry &registry, float fixed_dt)
    {
        for (auto &system : fixed_update_systems_)
        {
            system->fixed_update(registry, fixed_dt);
        }
    }
}