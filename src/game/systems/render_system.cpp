#include "render_system.h"

#include "../components/position.h"
#include "view/view.h"

void RenderSystem::render(Registry &registry, const float alpha) {
    auto view = View<Position>(registry);

    for (auto entity: view) {
        Position &pos = *registry.get<Position>(entity);

        Vec2 render_pos = Vec2::lerp(
            pos.previous,
            pos.current,
            alpha
        );
    }
}
