#include "render_system.hpp"
#include "game/components/position.hpp"
#include "game/components/camera.hpp"
#include "ecs/registry/registry.hpp"
#include "ecs/view/view.hpp"

namespace engine::game::systems::render
{

    RenderSystem::RenderSystem(engine::render::IRenderer &renderer)
        : renderer(renderer)
    {
    }

    void RenderSystem::render(ecs::Registry &registry, const float alpha)
    {
        // Take camera
        components::Camera camera;
        auto cam_view = ecs::View<components::Camera>(registry);

        bool has_camera = false;
        for (auto e : cam_view)
        {
            camera = *registry.get<components::Camera>(e);
            has_camera = true;
            break;
        }

        if (!has_camera)
            return;

        math::Vec2 cam_pos = math::Vec2::lerp(camera.previous, camera.current, alpha);
        auto view = ecs::View<components::Position>(registry);
        for (auto e : view)
        {
            const auto &pos = *registry.get<components::Position>(e);

            math::Vec2 world_pos = math::Vec2::lerp(pos.previous, pos.current, alpha);
            math::Vec2 screen_pos = world_pos - cam_pos;

            renderer.draw({screen_pos});
        }
    }
}
