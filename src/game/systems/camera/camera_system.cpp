#include "camera_system.hpp"
#include "game/components/camera.hpp"
#include "game/components/velocity.hpp"
#include "ecs/view/view.hpp"

namespace engine::game::systems::camera
{
    void CameraSystem::fixed_update(ecs::Registry &registry, const float fixed_dt)
    {
        auto view = ecs::View<components::Camera, components::Velocity>(registry);

        for (auto entity : view)
        {
            auto &camera = *registry.get<components::Camera>(entity);
            auto &velocity = *registry.get<components::Velocity>(entity);

            camera.previous = camera.current;
            camera.current += velocity.current * fixed_dt;
        }
    }
}
