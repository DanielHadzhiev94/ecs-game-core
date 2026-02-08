#pragma once

#include <vector>
#include <memory>
#include "system/interface/i_system_update.hpp"
#include "system/interface/i_system_fixed_update.hpp"

namespace engine::ecs
{
    class Registry;
}

namespace engine::core::system
{
    class SystemManager
    {
    public:
        SystemManager() = default;
        ~SystemManager();

        SystemManager(const SystemManager &) = delete;
        SystemManager &operator=(const SystemManager &) = delete;

        void register_system(std::unique_ptr<interface::ISystemUpdate> system) noexcept;
        void register_system(std::unique_ptr<interface::ISystemFixedUpdate> system) noexcept;

        void update(ecs::Registry &registry, float dt) noexcept;
        void fixed_update(ecs::Registry &registry, float fixed_dt) noexcept;

    private:
        std::vector<std::unique_ptr<interface::ISystemFixedUpdate>> fixed_update_systems_;
        std::vector<std::unique_ptr<interface::ISystemUpdate>> update_systems_;
    };
}
