#include "camera_system.hpp"

#include "../components/position.h"
#include "view/view.h"

void CameraSystem::fixed_update(Registry &registry, Camera &camera) {
    auto view = View<Position>(registry);

    auto entity = *view.begin();
    const Position &target = *registry.get<Position>(entity);

    camera.previous = camera.current;
    camera.current = target.current;
}
