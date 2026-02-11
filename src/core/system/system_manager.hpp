#pragma once

#include <vector>
#include <memory>

#include "system/interface/i_system_update.hpp"
#include "system/interface/i_system_fixed_update.hpp"
#include "system/interface/i_system_render.hpp"

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

        void register_system(std::unique_ptr<ISystemUpdate> system);
        void register_system(std::unique_ptr<ISystemFixedUpdate> system);
        void register_system(std::unique_ptr<ISystemRender> system);

        void update(ecs::Registry &registry, float dt);
        void fixed_update(ecs::Registry &registry, float fixed_dt);
        void render(ecs::Registry &registry, float alpha);

    private:
        std::vector<std::unique_ptr<ISystemFixedUpdate>> fixed_update_systems_;
        std::vector<std::unique_ptr<ISystemUpdate>> update_systems_;
        std::vector<std::unique_ptr<ISystemRender>> render_systems_;
    };
}
