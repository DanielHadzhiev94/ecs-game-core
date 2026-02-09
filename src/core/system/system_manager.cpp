#include "system_manager.hpp"
#include "ecs/registry/registry.hpp"

namespace engine::core::system
{
    SystemManager::~SystemManager() = default;

    void SystemManager::register_system(std::unique_ptr<interface::ISystemUpdate> system)
    {
        update_systems_.push_back(std::move(system));
    }

    void SystemManager::register_system(std::unique_ptr<interface::ISystemFixedUpdate> system)
    {
        fixed_update_systems_.push_back(std::move(system));
    }

    void SystemManager::register_system(std::unique_ptr<interface::ISystemRender> system)
    {
        render_systems_.push_back(std::move(system));
    }

    void SystemManager::update(ecs::Registry &registry, float dt)
    {
        for (auto &system : update_systems_)
        {
            system->update(registry, dt);
        }
    }

    void SystemManager::fixed_update(ecs::Registry &registry, float fixed_dt)
    {
        for (auto &system : fixed_update_systems_)
        {
            system->fixed_update(registry, fixed_dt);
        }
    }

    void SystemManager::render(ecs::Registry &registry, float alpha)
    {
        for (auto &system : render_systems_)
        {
            system->render(registry, alpha);
        }
    }
}