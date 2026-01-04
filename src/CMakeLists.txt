add_library(ecs_core
        core/entity/entity_id.h
        core/entity/entity_manager.h
        core/entity/entity_manager.cpp)

target_include_directories(ecs_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(ecs_core PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
