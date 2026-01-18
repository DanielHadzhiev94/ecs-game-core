#include "../render/render_system.hpp"
#include  "../../components/position.hpp"
#include "../../components/camera.hpp"
#include "view/view.hpp"

struct Position;

RenderSystem::RenderSystem(IRenderer &renderer)
    : renderer(renderer) {
}

void RenderSystem::render(Registry &registry, const float alpha) {
    // Take camera
    Camera camera;
    auto cam_view = View<Camera>(registry);

    bool has_camera = false;
    for (auto e: cam_view) {
        camera = *registry.get<Camera>(e);
        has_camera = true;
        break;
    }

    if (!has_camera)
        return;

    Vec2 cam_pos = Vec2::lerp(camera.previous, camera.current, alpha);
    auto view = View<Position>(registry);
    for (auto e: view) {
        const auto &pos = *registry.get<Position>(e);

        Vec2 world_pos = Vec2::lerp(pos.previous, pos.current, alpha);
        Vec2 screen_pos = world_pos - cam_pos;

        renderer.draw({screen_pos});
    }
}
