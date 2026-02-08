#include "system_manager.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::core::manager
{
    SystemManager::~SystemManager() = default;

    void SystemManager::register_system(std::unique_ptr<engine::game::systems::ISystemUpdate> system) noexcept
    {
        update_systems_.push_back(std::move(system));
    }

    void SystemManager::register_system(std::unique_ptr<engine::game::systems::ISystemFixedUpdate> system) noexcept
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