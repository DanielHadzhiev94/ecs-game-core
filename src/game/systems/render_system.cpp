#include "render_system.h"

#include "../components/position.h"
#include "view/view.h"

void RenderSystem::render(Registry &registry, const Camera &camera, const float alpha) {
    Vec2 cam = Vec2::lerp(camera.previous, camera.current, alpha);

    auto view = View<Position>(registry);

    for (auto e: view) {
        Position &pos = *registry.get<Position>(e);

        Vec2 entity_pos = Vec2::lerp(pos.previous, pos.current, alpha);
        Vec2 screen_pos = entity_pos - cam;
    }
}
