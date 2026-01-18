#pragma once

#include "DummyRenderer.hpp"
#include "world/world.hpp"
#include "time/Clock.hpp"

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
    EntityManager entity_manager;
    StorageManager storage_manager;
    Registry registry;

    // Rendering backend (ownership)
    DummyRenderer renderer;

    // World (orchestration)
    World world;

    Clock clock;
    GameState state = GameState::Idle;

    void run();
};
