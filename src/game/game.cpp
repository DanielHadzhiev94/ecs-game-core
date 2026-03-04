#include <algorithm>

#include "game.hpp"

Game::Game() {
}

bool Game::is_running() const {
    return state == GameState::Running;
}

void Game::start() {
    if (state == GameState::Idle) {
        state = GameState::Running;
        run();
    }
}

void Game::stop() {
    if (state == GameState::Running)
        state = GameState::Stopped;
}

void Game::run() {
    // Create player and enemy
    world_.initialization_demo();

    // Set the last_frame here, to prevent
    // to large first FrameTime
    clock_.set_initial_frame();

    while (is_running()) {
        auto frameTime = clock_.restart();
        frameTime = std::min(frameTime, MAX_FRAME_TIME);

        world_.tick(frameTime);
    }
}
