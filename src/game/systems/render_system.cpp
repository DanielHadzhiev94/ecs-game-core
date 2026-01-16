#include "render_system.hpp"

#include "../components/position.hpp"
#include "view/view.hpp"

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
