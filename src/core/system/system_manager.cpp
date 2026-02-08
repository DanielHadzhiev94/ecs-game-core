#include "system_manager.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::core::system
{
    SystemManager::~SystemManager() = default;

    void SystemManager::register_system(std::unique_ptr<interface::ISystemUpdate> system) noexcept
    {
        update_systems_.push_back(std::move(system));
    }

    void SystemManager::register_system(std::unique_ptr<interface::ISystemFixedUpdate> system) noexcept
    {
        fixed_update_systems_.push_back(std::move(system));
    }

    void SystemManager::update(ecs::Registry &registry, float dt) noexcept
    {
        for (auto &system : update_systems_)
        {
            system->update(registry, dt);
        }
    }

    void SystemManager::fixed_update(ecs::Registry &registry, float fixed_dt) noexcept
    {
        for (auto &system : fixed_update_systems_)
        {
            system->fixed_update(registry, fixed_dt);
        }
    }
}