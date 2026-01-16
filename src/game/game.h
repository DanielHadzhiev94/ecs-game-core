#pragma once

#include "world.h"
#include "time/Clock.h"

enum class GameState {
    Idle,
    Running,
    Stopped
};

constexpr float FIXED_DT = 1.0F / 60.0F;
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
