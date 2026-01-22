#include "../render/render_system.hpp"
#include  "../../components/position.hpp"
#include "../../components/camera.hpp"
#include "ecs/registry/registry.hpp"
#include "ecs/view/view.hpp"

struct Position;

RenderSystem::RenderSystem(engine::render::IRenderer &renderer)
    : renderer(renderer) {
}

void RenderSystem::render(engine::ecs::Registry &registry, const float alpha) {
    // Take camera
    Camera camera;
    auto cam_view = engine::ecs::View<Camera>(registry);

    bool has_camera = false;
    for (auto e: cam_view) {
        camera = *registry.get<Camera>(e);
        has_camera = true;
        break;
    }

    if (!has_camera)
        return;

    engine::math::Vec2 cam_pos = engine::math::Vec2::lerp(camera.previous, camera.current, alpha);
    auto view = engine::ecs::View<Position>(registry);
    for (auto e: view) {
        const auto &pos = *registry.get<Position>(e);

        engine::math::Vec2 world_pos = engine::math::Vec2::lerp(pos.previous, pos.current, alpha);
        engine::math::Vec2 screen_pos = world_pos - cam_pos;

        renderer.draw({screen_pos});
    }
}
