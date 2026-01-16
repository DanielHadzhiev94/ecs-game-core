add_library(ecs_core
        core/entity/entity_id.hpp
        core/entity/entity_manager.hpp
        core/entity/entity_manager.cpp
        core/registry/registry.hpp
        core/registry/registry.cpp
        core/storage/component_storage.hpp
        core/storage/storage_manager.hpp
        core/storage/storage_manager.cpp
        core/view/view.hpp
        core/view/view_iterator.hpp
        game/systems/gameplay/movement_system.hpp
        game/components/position.hpp
        game/components/velocity.hpp
        game/systems/gameplay/movements_system.cpp
        game/world/world.hpp
        game/game.hpp
        game/world/world.cpp
        game/game.cpp
        game/spawn/entity_factory.hpp
        game/spawn/entity_factory.cpp
        core/entity/entity_id_hash.hpp
        game/systems/gameplay/lifetime_system.hpp
        game/systems/gameplay/lifetime_system.cpp
        game/components/health.hpp
        core/time/Clock.hpp
        core/time/Clock.cpp
        core/math/vec2.hpp
        game/systems/render_system.hpp
        game/systems/render_system.cpp
        game/systems/camera_system.hpp
        game/systems/camera_system.cpp
        game/components/camera.hpp
)

target_include_directories(ecs_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core

)

target_compile_options(ecs_core PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
