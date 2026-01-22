#pragma once

#include "../core/render/DummyRenderer.hpp"
#include "world/world.hpp"
#include "time/clock.hpp"

enum class GameState {
    Idle,
    Running,
    Stopped
};

constexpr float MAX_FRAME_TIME = 0.25F;

class Game {
public:
    Game();

    void start();

    void stop();

    bool is_running() const;

private:
    // ECS infrastructure (ownership)
    engine::ecs::EntityManager entity_manager;
    engine::ecs::StorageManager storage_manager;
    engine::ecs::Registry registry;

    // Rendering backend (ownership)
    engine::render::DummyRenderer renderer;

    // World (orchestration)
    World world;

    engine::time::Clock clock;
    GameState state = GameState::Idle;

    void run();
};
