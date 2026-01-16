add_library(ecs_core
        core/entity/entity_id.h
        core/entity/entity_manager.h
        core/entity/entity_manager.cpp
        core/registry/registry.h
        core/registry/registry.cpp
        core/storage/component_storage.h
        core/storage/storage_manager.h
        core/storage/storage_manager.cpp
        core/view/view.h
        core/view/view_iterator.h
        game/systems/movement_system.h
        game/components/position.h
        game/components/velocity.h
        game/systems/movements_system.cpp
        game/world/world.h
        game/game.h
        game/world/world.cpp
        game/game.cpp
        game/spawn/entity_factory.h
        game/spawn/entity_factory.cpp
        core/entity/entity_id_hash.h
        game/systems/lifetime_system.h
        game/systems/lifetime_system.cpp
        game/components/health.h
        core/time/Clock.h
        core/time/Clock.cpp
        core/math/vec2.h
        game/systems/render_system.h
        game/systems/render_system.cpp
)

target_include_directories(ecs_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core

)

target_compile_options(ecs_core PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
