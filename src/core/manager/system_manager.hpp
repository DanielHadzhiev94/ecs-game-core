#pragma once

#include <vector>
#include <memory>

namespace engine::ecs
{
    class Registry;
}
namespace game::systems
{
    class ISystemUpdate;
    class ISystemFixedUpdate;
}

namespace engine::core::manager
{
    class SystemManager
    {
    public:
        SystemManager() = default;
        ~SystemManager() = default;

        SystemManager(const SystemManager &) = delete;
        SystemManager &operator=(const SystemManager &) = delete;

        void register_system(std::unique_ptr<game::systems::ISystemUpdate> system) noexcept;
        void register_system(std::unique_ptr<game::systems::ISystemFixedUpdate> system) noexcept;

        void update(engine::ecs::Registry &registry, float dt) noexcept;
        void fixed_update(engine::ecs::Registry &registry, float fixed_dt) noexcept;

    private:
        std::vector<std::unique_ptr<game::systems::ISystemFixedUpdate>> fixed_update_systems_;
        std::vector<std::unique_ptr<game::systems::ISystemUpdate>> update_systems_;
    };
}
