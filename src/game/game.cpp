#include "game.h"

void Game::update(const float dt) {
    world.update(dt);
}

bool Game::is_running() const {
    return state == GameState::Running;
}

void Game::start() {
    if (state == GameState::Idle)
        state = GameState::Running;
}

void Game::stop() {
    if (state == GameState::Running)
        state = GameState::Stopped;
}

void Game::run() {
    // Set the last_frame here, to prevent
    // to large first FrameTime
    clock.set_initial_frame();

    while (is_running()) {
        auto frameTime = clock.restart();
        frameTime = std::min(frameTime, MAX_FRAME_TIME);

        accumulator += frameTime;

        while (accumulator >= FIXED_DT) {
            world.fixed_update(FIXED_DT);
            accumulator -= FIXED_DT;
        }

        world.update(frameTime);
    }
}
