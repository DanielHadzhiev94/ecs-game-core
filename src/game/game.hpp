#pragma once

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
    Game() = default;

    void update(float dt);

    void start();

    void stop();

    bool is_running() const;

private:
    World world;
    Clock clock;
    GameState state = GameState::Idle;
    float accumulator = 0.0F;

    void run();
};
