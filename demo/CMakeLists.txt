add_executable(ecs_demo
        main.cpp
)

target_link_libraries(ecs_demo
        PRIVATE ecs_core
)

target_include_directories(ecs_demo
        PRIVATE ${PROJECT_SOURCE_DIR}/src
)