#include "camera_system.hpp"

#include "../../components/camera.hpp"
#include "../../components/velocity.hpp"
#include "ecs/view/view.hpp"

void CameraSystem::fixed_update(engine::ecs::Registry &registry, const float fixed_dt) {
    auto view = engine::ecs::View<Camera, Velocity>(registry);

    for (auto entity: view) {
        auto &camera = *registry.get<Camera>(entity);
        auto &velocity = *registry.get<Velocity>(entity);

        camera.previous = camera.current;
        camera.current += velocity.current * fixed_dt;
    }
}
