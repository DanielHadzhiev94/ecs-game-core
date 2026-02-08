#pragma once

#include <vector>
#include <memory>
#include "../game/systems/interfaces/i_system_update.hpp"
#include "../game/systems/interfaces/i_system_fixed_update.hpp"

namespace engine::ecs
{
    class Registry;
}

namespace engine::core::manager
{
    class SystemManager
    {
    public:
        SystemManager() = default;
        ~SystemManager();

        SystemManager(const SystemManager &) = delete;
        SystemManager &operator=(const SystemManager &) = delete;

        void register_system(std::unique_ptr<engine::game::systems::ISystemUpdate> system) noexcept;
        void register_system(std::unique_ptr<engine::game::systems::ISystemFixedUpdate> system) noexcept;

        void update(engine::ecs::Registry &registry, float dt) noexcept;
        void fixed_update(engine::ecs::Registry &registry, float fixed_dt) noexcept;

    private:
        std::vector<std::unique_ptr<engine::game::systems::ISystemFixedUpdate>> fixed_update_systems_;
        std::vector<std::unique_ptr<engine::game::systems::ISystemUpdate>> update_systems_;
    };
}
