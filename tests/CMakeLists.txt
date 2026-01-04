add_executable(ecs_tests
    main.cpp
)

target_link_libraries(ecs_tests
    PRIVATE ecs_core
)
