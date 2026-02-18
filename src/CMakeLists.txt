add_library(ecs_core
        core/ecs/entity/entity_id.hpp
        core/ecs/entity/entity_manager.hpp
        core/ecs/entity/entity_manager.cpp
        core/ecs/registry/registry.hpp
        core/ecs/registry/registry.cpp
        core/ecs/storage/component_storage.hpp
        core/ecs/storage/storage_manager.hpp
        core/ecs/storage/storage_manager.cpp
        core/ecs/view/view.hpp
        core/ecs/view/view_iterator.hpp
        core/ecs/entity/entity_id_hash.hpp
        core/event/event_bus.hpp

        core/render/IRenderer.hpp
        core/render/DummyRenderer.hpp
        
        core/time/clock.hpp
        core/time/Clock.cpp
        core/math/vec2.hpp

        core/system/interface/i_system_update.hpp
        core/system/interface/i_system_fixed_update.hpp
        core/system/interface/i_system_render.hpp

        core/system/system_manager.hpp
        core/system/system_manager.cpp
        
        core/event/event_bus.hpp
        
        game/systems/gameplay/lifetime_system.hpp
        game/systems/gameplay/lifetime_system.cpp
        game/systems/gameplay/movement_system.hpp
        game/systems/gameplay/collision_system.hpp
        game/systems/gameplay/collision_system.cpp
        game/systems/gameplay/health_system.hpp
        game/systems/gameplay/health_system.hpp
        game/systems/gameplay/movements_system.cpp

        game/components/health.hpp
        game/components/position.hpp
        game/components/velocity.hpp
        game/components/collider.hpp
        game/components/rigid_body.hpp
        game/components/camera.hpp

        game/spawn/entity_factory.hpp
        game/spawn/entity_factory.cpp
        
        game/systems/render/render_system.hpp
        game/systems/render/render_system.cpp
        game/systems/camera/camera_system.hpp
        game/systems/camera/camera_system.cpp
        game/systems/gameplay/ai_enemy_system.hpp
        game/systems/gameplay/ai_enemy_system.cpp
        game/systems/gameplay/player_control_system.hpp
        game/systems/gameplay/player_control_system.cpp
        game/systems/gameplay/health_system.hpp
        game/systems/gameplay/health_system.cpp
        
        game/commands/render_command.hpp
        
        game/input/input_action.hpp
        game/input/input_state.hpp
        game/input/input_device.hpp
        game/input/input_context.hpp
        game/input/dummy_keyboard.hpp
        game/input/dummy_keyboard.cpp
        game/input/input_system.hpp
        game/input/input_system.cpp

        game/components/player_tag.hpp
        game/components/enemy_tag.hpp

        game/events/damage_event.hpp

        game/world/world.hpp
        game/world/world.cpp

        game/game.hpp
        game/game.cpp
        
)

target_include_directories(ecs_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/core

)

target_compile_options(ecs_core PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
