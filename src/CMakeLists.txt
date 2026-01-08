add_library(ecs_core
        core/entity/entity_id.h
        core/entity/entity_manager.h
        core/entity/entity_manager.cpp
        core/registry/registry.h
        core/registry/registry.cpp
        core/storage/component_storage.h
        core/storage/storage_manager.h
)

target_include_directories(ecs_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core

)

target_compile_options(ecs_core PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
