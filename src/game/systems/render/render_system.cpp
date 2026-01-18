#include "../render/render_system.hpp"
#include "../../components/position.hpp"
#include "view/view.hpp"

void RenderSystem::render(Registry &registry, const Camera &camera, const float alpha) {
    Vec2 cam = Vec2::lerp(camera.previous, camera.current, alpha);

    auto view = View<Position>(registry);

    for (auto e: view) {
        Position &pos = *registry.get<Position>(e);

        Vec2 entity_pos = Vec2::lerp(pos.previous, pos.current, alpha);
        Vec2 screen_pos = entity_pos - cam;
    }
}
